/**
 * @file    parser.hpp
 * @version 0.0.1
 * @date    Sat, 04 Apr 2026 12:59:28 +0000
 * @info    ...
 */
#include "parser.hpp"

#include "lexer.hpp"
#include "tokens.hpp"

typedef vector<unsigned long> RULE;
typedef vector<string RULES;

RULES rules{{UL_OPEN_BRACE, UL_SYMBOL, UL_EQUALS, UL_IDENTIFIER, UL_PLUS_SIGN, UL_NUMERIC_LITERAL, UL_CLOSE_BRACE}
    {UL_OPEN_BRACE, UL_SYMBOL, UL_EQUALS, UL_IDENTIFIER, UL_CLOSE_BRACE}
    {UL_OPEN_BRACE, UL_SYMBOL, UL_EQUALS, UL_NUMERIC_LITERAL, UL_CLOSE_BRACE}
    {UL_OPEN_BRACE, UL_SYMBOL, UL_EQUALS, UL_SYMBOL, UL_CLOSE_BRACE},{UL_SYMBOL}
    { UL_SYMBOL, UL_VBAR, UL_UNESCAPED_TEXT },
    UL_VAR_ATTRIB, UL_LOGICAL_EQUAL, UL_STRING_FORMAT   };


