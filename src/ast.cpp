#include <iostream>
#include <vector>
#include "ast.hpp"

using std::cout;
using std::endl;

#define AST_MAIN
#define AST_MAIN
#ifdef AST_MAIN
int main(int argc, char** argv)
{
    ast::add_expr<int,int> e11(2,3);
    int* v11 = e11.eval();
    cout << "e12=" << *v11 << endl;

	ast::add_expr2<int> e12(10,7);
    int* v12 = e12.eval();
    cout << "e12=" << *v12 << endl;

	// ast::add_expr<int> e1(e11,  e12);
    // int* v = e1.eval();
    // cout << "e1=" << *v << endl;

    ast::subtract_expr<int> e2(5,3);
    int* v2 = e2.eval();
    cout << "e2=" << *v2 << endl;

    ast::multiply_expr<int> e3(2,3);
    int* v3 = e3.eval();
    cout << "e3=" << *v3 << endl;

    ast::divide_expr<int> e4(10,2);
    int* v4 = e4.eval();
    cout << "e4=" << *v4 << endl;

    ast::modlus_expr<int> e5(10,3);
    int* v5 = e5.eval();
    cout << "e5=" << *v5 << endl;


	//std::vector<ast::expr> vec = { e1, e2, e3, e4, e5 };

    return 0;
}
#endif
