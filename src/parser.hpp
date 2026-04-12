/**
 * @file    parser.hpp
 * @version 0.0.1
 * @date    Sat, 04 Apr 2026 12:59:28 +0000
 * @info    ...
 */
#ifndef parser_HPP_
#define parser_HPP_
#include <iostream>
#include "lexer.hpp"
#include "context.hpp"
// #include "tokens.hpp"

typedef vector<unsigned long> TYPE;
typedef vector<unsigned long> TERMINAL;
typedef vector<unsigned long> RULE;
typedef vector<TYPE> TYPES;
typedef vector<TERMINAL> TERMINALS;
typedef vector<RULE> RULES;
typedef vector<TYPE> SEQUENCE;
typedef vector<SEQUENCE> SEQUENCES;
typedef TYPE START;

// TYPES types{ADD_TYPE, MUL_TYPE, NUM, EXPR};
// TERMINALS terminals{OPEN_BRACE, SYMBOL, EQUALS, IDENTIFIER, PLUS_SIGN, NUMERIC_LITERAL, CLOSE_BRACE};

// RULES rules{
// 	{OPEN_BRACE, SYMBOL, EQUALS, IDENTIFIER, PLUS_SIGN, NUMERIC_LITERAL, CLOSE_BRACE},
// 	{OPEN_BRACE, SYMBOL, EQUALS, IDENTIFIER, CLOSE_BRACE},
// 	{OPEN_BRACE, SYMBOL, EQUALS, NUMERIC_LITERAL, CLOSE_BRACE},
// 	{OPEN_BRACE, SYMBOL, EQUALS, SYMBOL, CLOSE_BRACE},
// 	{SYMBOL}};

namespace bkp
{

	/**
	 * @brief class parser
	 */
	class parser
	{
	public:
		/**
		 * @brief : ctor
		 */
		parser(context *ct, const string &file);

		/**
		 * @brief : copy ctor
		 */
		parser(const parser &src) = default;

		/**
		 * @brief : destructor
		 */
		~parser() = default;

		static token_value_t *parse();

	private:
		string m_file;
		string m_input;
		context *m_context;
	};
}
#endif
