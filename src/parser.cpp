/**
 * @file    parser.hpp
 * @version 0.0.1
 * @date    Sat, 04 Apr 2026 12:59:28 +0000
 */
#include <iostream>
#include "parser.hpp"
#include "lexer.hpp"
// #include "tokens.hpp"
//  using namespace bkp;

using std::string;
using std::cout;
using std::endl;

bkp::parser::parser(context *ct, const string &file) : m_context(ct), m_file(file)
{
    read_str(m_file, m_input, std::ios::in);
}

/**
 * @name parse
 * @return void
 */
void bkp::parser::parse()
{
	// string n = g_tokens[TILDE].name;
	// cout << "TESTING123 ....   " << g_tokens[WHITESPACE].name << endl;
	// constexpr std::string_view data { "ABCDEF" };
}
