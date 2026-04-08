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

namespace bkp
{
	/**
	 * @brief class parser
	 */
	class parser
	{
	public:
		/**
		 * @brief : default ctor
		 */
		parser(context *ct);

		/**
		 * @brief : copy ctor
		 */
		parser(const parser &src) = default;

		/**
		 * @brief : destructor
		 */
		~parser() = default;

		static match *parse();

	private:
		string m_input;
		context *m_context;
	};
}
#endif
