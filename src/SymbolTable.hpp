// SymbolTable.hpp
#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include <optional>
#include <stdexcept>
#include <utility>
#include <functional>

// -------------------- Interface --------------------
template <class Value>
struct ISymbolTable {
    virtual ~ISymbolTable() = default;

    // Create/destroy a scope (e.g., on '{' and '}')
    virtual void enter_scope() = 0;
    virtual void exit_scope() = 0;

    // Insert into current scope; returns false if name already defined in THIS scope
    virtual bool define(const std::string& name, Value value) = 0;

    // Assign (rebind) an existing symbol in nearest defining scope; returns false if not found
    virtual bool assign(const std::string& name, Value value) = 0;

    // Lookup: nearest scope wins
    virtual std::optional<std::reference_wrapper<const Value>>
    resolve(const std::string& name) const = 0;

    // Lookup mutable (use sparingly)
    virtual std::optional<std::reference_wrapper<Value>>
    resolve_mut(const std::string& name) = 0;

    // Introspection
    virtual std::size_t depth() const = 0; // number of active scopes
};

// -------------------- Concrete implementation --------------------
template <class Value>
class ScopedSymbolTable : public ISymbolTable<Value> {
public:
    ScopedSymbolTable() { enter_scope(); } // always have a global scope

    void enter_scope() override {
        _scopes.emplace_back();
    }

    void exit_scope() override {
        if (_scopes.empty()) throw std::runtime_error("No scope to exit");
        _scopes.pop_back();
    }

    bool define(const std::string& name, Value value) override {
        auto& cur = _current();
        auto [it, inserted] = cur.emplace(name, std::move(value));
        return inserted;
    }

    bool assign(const std::string& name, Value value) override {
        for (auto it = _scopes.rbegin(); it != _scopes.rend(); ++it) {
            auto found = it->find(name);
            if (found != it->end()) {
                found->second = std::move(value);
                return true;
            }
        }
        return false;
    }

    std::optional<std::reference_wrapper<const Value>>
    resolve(const std::string& name) const override {
        for (auto it = _scopes.rbegin(); it != _scopes.rend(); ++it) {
            auto found = it->find(name);
            if (found != it->end()) return std::cref(found->second);
        }
        return std::nullopt;
    }

    std::optional<std::reference_wrapper<Value>>
    resolve_mut(const std::string& name) override {
        for (auto it = _scopes.rbegin(); it != _scopes.rend(); ++it) {
            auto found = it->find(name);
            if (found != it->end()) return std::ref(found->second);
        }
        return std::nullopt;
    }

    std::size_t depth() const override { return _scopes.size(); }

private:
    using Map = std::unordered_map<std::string, Value>;
    std::vector<Map> _scopes;

    Map& _current() {
        if (_scopes.empty()) throw std::runtime_error("No active scope");
        return _scopes.back();
    }
};

// -------------------- RAII scope guard --------------------
class ScopeGuard {
public:
    template <class Value>
    explicit ScopeGuard(ISymbolTable<Value>& table) : _enter([&table](){ table.enter_scope(); }),
                                                       _exit([&table](){ table.exit_scope(); }) {
        _enter();
    }
    ScopeGuard(const ScopeGuard&) = delete;
    ScopeGuard& operator=(const ScopeGuard&) = delete;
    ~ScopeGuard() { _exit(); }
private:
    std::function<void()> _enter, _exit;
};
