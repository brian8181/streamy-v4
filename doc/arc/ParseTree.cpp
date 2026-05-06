// main.cpp
#include "ParseTree.hpp"

int main() {
    // Root for rule: expr
    auto root = std::make_unique<NonTerminalNode>("expr");

    // expr -> NUMBER + NUMBER
    root->add_child<LeafNode>("NUMBER", "42");
    root->add_child<LeafNode>("PLUS", "+");
    root->add_child<LeafNode>("NUMBER", "7");

    // Print tree
    root->print(std::cout);
    return 0;
}
