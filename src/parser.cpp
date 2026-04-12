/**
 * @file    parser.hpp
 * @version 0.0.1
 * @date    Sat, 04 Apr 2026 12:59:28 +0000
 * @info    ...
 */
#include "parser.hpp"
// #include "tokens.hpp"
//  using namespace bkp;

bkp::parser::parser(context *ct, const string &file) : m_context(ct), m_file(file)
{
    read_str(m_file, m_input, std::ios::in);
}
