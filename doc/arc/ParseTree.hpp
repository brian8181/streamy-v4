// ParseTree.hpp
#pragma once
#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <functional>

// ---------------- Base Node ----------------
class ParseNode {
public:
    enum class Kind { Leaf, NonTerminal };

    explicit ParseNode(Kind k) : kind(k) {}
    virtual ~ParseNode() = default;

    Kind kind;
    virtual void print(std::ostream& os, int depth = 0) const = 0;
};

// ---------------- Leaf Node ----------------
class LeafNode : public ParseNode {
public:
    LeafNode(std::string tokenType, std::string tokenValue)
        : ParseNode(Kind::Leaf), type(std::move(tokenType)), value(std::move(tokenValue)) {}

    std::string type;
    std::string value;

    void print(std::ostream& os, int depth = 0) const override {
        os << std::string(depth * 2, ' ') << "Leaf(" << type << ": \"" << value << "\")\n";
    }
};


  
// ---------------- Non-terminal Node ----------------
class NonTerminalNode : public ParseNode {
public:
    explicit NonTerminalNode(std::string ruleName)
        : ParseNode(Kind::NonTerminal), rule(std::move(ruleName)) {}

    std::string rule;
    std::vector<std::unique_ptr<ParseNode>> children;

    template<typename NodeType, typename... Args>
    NodeType* add_child(Args&&... args) {
        auto child = std::make_unique<NodeType>(std::forward<Args>(args)...);
        NodeType* raw = child.get();
        children.push_back(std::move(child));
        return raw;
    }

    void print(std::ostream& os, int depth = 0) const override {
        os << std::string(depth * 2, ' ') << "NonTerminal(" << rule << ")\n";
        for (const auto& child : children) {
            child->print(os, depth + 1);
        }
    }
};
