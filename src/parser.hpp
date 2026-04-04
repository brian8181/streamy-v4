/**
 * @file    parser.hpp
 * @version 0.0.1
 * @date    Sat, 04 Apr 2026 12:59:28 +0000
 * @info    ...
 */
#ifndef _parser_HPP_
#define _parser_HPP_
#include <iostream>

typedef vector<unsigned long> RULE;
RULES rules{{UL_OPEN_BRACE, UL_SYMBOL, UL_EQUALS, UL_IDENTIFIER, UL_PLUS_SIGN, UL_NUMERIC_LITERAL, UL_CLOSE_BRACE} {UL_OPEN_BRACE, UL_SYMBOL, UL_EQUALS, UL_IDENTIFIER, UL_CLOSE_BRACE} {UL_OPEN_BRACE, UL_SYMBOL, UL_EQUALS, UL_NUMERIC_LITERAL, UL_CLOSE_BRACE} {UL_OPEN_BRACE, UL_SYMBOL, UL_EQUALS, UL_SYMBOL, UL_CLOSE_BRACE} {UL_SYMBOL}};

/**
 * @brief class parser
 */
class parser
{
public:
	/**
	 * @brief : default ctor
	 */
	parser() = default;

	/**
	 * @brief : copy ctor
	 */
	parser(const parser &src) = default;

	/**
	 * @brief : destructor
	 */
	~parser() = default;

TEST
	/**
	 * @brief
	 * @brief c++ comment ...
	 * @brief place future addtions here ...
	 *
	 */

	private:
};

#endif
