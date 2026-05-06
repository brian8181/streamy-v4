
// main.cpp
#include "SymbolTable.hpp"
#include <iostream>
#include <variant>

enum class SymbolKind { Var, Func };

struct TypeInfo {
    std::string name; // e.g. "int", "float", "T"
};

struct Symbol {
    SymbolKind kind;
    TypeInfo   type;
    // Extra payload (e.g., parameter types, address, etc.)
    std::variant<std::monostate, int, double, std::string> payload;
};

int main() {
    ScopedSymbolTable<Symbol> st;

    st.define("x", Symbol{SymbolKind::Var, {"int"}, 0});
    st.enter_scope();
    st.define("x", Symbol{SymbolKind::Var, {"float"}, 0.0}); // shadows outer x

    if (auto s = st.resolve("x")) {
        std::cout << "Inner x type: " << s->get().type.name << "\n"; // float
    }

    st.exit_scope();
    if (auto s = st.resolve("x")) {
        std::cout << "Outer x type: " << s->get().type.name << "\n"; // int
    }

    // Assign existing symbol
    st.assign("x", Symbol{SymbolKind::Var, {"int"}, 42});

    if (auto s = st.resolve("x")) {
        if (auto p = std::get_if<int>(&s->get().payload)) {
            std::cout << "Outer x value: " << *p << "\n"; // 42
        }
    }
}
