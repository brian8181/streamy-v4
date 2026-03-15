/**
 * @file    tokens.hpp
 * @version 0.0.1
 * @date    Wed Feb 11 17:23:05 CST 2026
 */
#ifndef TOKENS_HPP_
#define TOKENS_HPP_

#include "Lexer.hpp"
#include "pparser.tab.hh"
#include <iostream>
#include <sstream>
#include <stack>
#include <boost/regex.hpp>

using std::cerr;
using std::cout;
using std::endl;
using yy::parser;

/**
 * @brief token definitions : unsigned long integers
 */
#define UL_TILDE 4ul
#define UL_TIC_MARK 5ul
#define UL_EXCLAMATION 6ul
#define UL_AT_SYMBOL 7ul
#define UL_HASH_MARK 8ul
#define UL_DOLLAR_SIGN 9ul
#define UL_PERCENT_SIGN 10ul
#define UL_CARROT 11ul
#define UL_AMPERSAND 12ul
#define UL_ASTERISK 13ul
#define UL_OPEN_PAREN 14ul
#define UL_CLOSE_PAREN 15ul
#define UL_DASH 16ul
#define UL_UNDERSCORE 17ul
#define UL_PLUS_SIGN 18ul
#define UL_EQUAL_SIGN 19ul
#define UL_OPEN_BRACE 20ul
#define UL_OPEN_BRACKET 21ul
#define UL_CLOSE_BRACE 22ul
#define UL_CLOSE_BRACKET 23ul
#define UL_VBAR 24ul
#define UL_BACKSLASH 25ul
#define UL_COLON 26ul
#define UL_SEMI_COLON 27ul
#define UL_DOUBLE_QUOTE 28ul
#define UL_SINGLE_QUOTE 29ul
#define UL_ESC_BACKSLASH 301ul
#define UL_ESC_NEWLINE 302ul
#define UL_ESC_DOUBLE_QUOTE 303ul
#define UL_ESC_SINGLE_QUOTE 304ul
#define UL_ESC_TAB 305ul
#define UL_EQUALS 306ul
#define UL_LESS_THAN 30ul
#define UL_COMMA 31ul
#define UL_GREATER_THAN 32ul
#define UL_DOT 33ul
#define UL_QUESTION_MARK 34ul
#define UL_SLASH 35ul
#define UL_NOT 39ul
#define UL_AND 40ul
#define UL_OR 41ul
#define UL_XOR 42ul
#define UL_LEFT_SHIFT 43ul
#define UL_RIGHT_SHIFT 44ul
#define UL_LOGICAL_AND 45ul
#define UL_LOGICAL_OR 46ul
#define UL_LOGICAL_NOT 47ul
#define UL_LOGICAL_EQUAL 48ul
#define UL_GREATER_THAN_EQUAL 49ul
#define UL_LESS_THAN_EQUAL 50ul
#define UL_NUMERIC_LITERAL 51ul
#define UL_STRING_LITERAL 52ul
#define UL_DECIMAL_LITERAL 53ul
#define UL_HEXADECIMAL_LITERAL 54ul
#define UL_OCTAL_DECIMAL_LITERAL 55ul
#define UL_IF 60ul
#define UL_ELSE 61ul
#define UL_ELSEIF 62ul
#define UL_FOREACH 63ul
#define UL_DO 64ul
#define UL_WHILE 65ul
#define UL_SWITCH 66ul
#define UL_CASE 67ul
#define UL_DEFAULT 68ul
#define UL_BREAK 69ul
#define UL_CONTINUE 70ul
#define UL_TRY 71ul
#define UL_CATCH 72ul
#define UL_REQUIRE 77ul
#define UL_CONFIG_LOAD 78ul
#define UL_INSERT 79ul
#define UL_INCLUDE 80ul
#define UL_FILE_ATTRIB 81ul
#define UL_ASSIGN 82ul
#define UL_VAR_ATTRIB 83ul
#define UL_VALUE_ATTRIB 84ul
#define UL_FROM_ATTRIB 85ul
#define UL_ITEM_ATTRIB 86ul
#define UL_KEY_ATTRIB 87ul
#define UL_NAME_ATTRIB 88ul
#define UL_CAPITALIZE 89ul
#define UL_CAT 90ul
#define UL_COUNT_CHARACTERS 91ul
#define UL_COUNT_PARAGRAPHS 92ul
#define UL_COUNT_SENTENCES 93ul
#define UL_COUNT_WORDS 94ul
#define UL_DATE_FORMAT 95ul
#define UL_ESCAPE 96ul
#define UL_INDENT 97ul
#define UL_LOWER 98ul
#define UL_UPPER 99ul
#define UL_STRIP 100ul
#define UL_NL2BR 101ul
#define UL_REGX_REPLACE 102ul
#define UL_REPLACE 103ul
#define UL_SPACIFY 104ul
#define UL_STRING_FORMAT 105ul
#define UL_STRIP_TAGS 106ul
#define UL_TRUNCATE 107ul
#define UL_WORDWRAP 108ul
#define UL_VALID_CHAR 113ul
#define UL_FIRST_CHAR 114ul
#define UL_ID 115ul
#define UL_IDENTIFIER 116ul
#define UL_SYMBOL 117ul
#define UL_CONST_SYMBOL 118ul
#define UL_ARRAY 119ul
#define UL_COMMENT 120ul
#define UL_WHITESPACE 121ul
#define UL_FILE_NAME 122ul
#define UL_HAS_SIGN 127ul
#define UL_SKIP_TOKEN 0xFF0000ul
#define UL_UNESCAPED_TEXT 0x00FF00ul
#define UL_ERROR 0x0000FFul
#define UL_SCAN_EOF 0x0ul
#define UL_ANYTHING 0xFFFFFFul
#define UL_MATCH 128ul
#define UL_UNDEFINED 0xDEADBEEFul
#define UL_NULL 0x0ul
#define EMPTY_STRING string("")
#define S_TYPE "string"

/**
 * @name g_tokens_all
 * @brief global token vector - all tokens
 */
inline map<unsigned long, token_def> g_tokens = {
    {UL_UNDEFINED,          token{UL_UNDEFINED,          "UNDEFINED",          S_TYPE, R"(.)", UL_NULL, EMPTY_STRING}},
    {UL_MATCH,              token{UL_MATCH,              "MATCH",              S_TYPE, R"(match)", UL_NULL, EMPTY_STRING}},
    {UL_UNESCAPED_TEXT,     token{UL_UNESCAPED_TEXT,     "UNESCAPED_TEXT",     S_TYPE, R"([^{]+)", UL_NULL, EMPTY_STRING}},
    {UL_WHITESPACE,         token{UL_WHITESPACE,         "WHITESPACE",         S_TYPE, R"([ \t\n]*)", UL_NULL, EMPTY_STRING}},
    {UL_DOLLAR_SIGN,        token{UL_DOLLAR_SIGN,        "DOLLAR_SIGN",        S_TYPE, R"(\$)", UL_NULL, EMPTY_STRING}},
    {UL_VALID_CHAR,         token{UL_VALID_CHAR,         "VALID_CHAR",         S_TYPE, R"([A-Za-z0-9*@_~+-])", UL_NULL, EMPTY_STRING}},
    {UL_NUMERIC_LITERAL,    token{UL_NUMERIC_LITERAL,    "NUMERIC_LITERAL",    S_TYPE, R"([0-9]+)", UL_NULL, EMPTY_STRING}},
    {UL_DOUBLE_QUOTE,       token{UL_DOUBLE_QUOTE,       "DOUBLE_QUOTE",       S_TYPE, R"(")", UL_NULL, EMPTY_STRING}},
    {UL_CARROT,             token{UL_CARROT,             "CARROT",             S_TYPE, R"(\^)", UL_NULL, EMPTY_STRING}},
    {UL_AMPERSAND,          token{UL_AMPERSAND,          "AMPERSAND",          S_TYPE, R"(\*)", UL_NULL, EMPTY_STRING}},
    {UL_ASTERISK,           token{UL_ASTERISK,           "ASTERISK",           S_TYPE, R"(\*)", UL_NULL, EMPTY_STRING}},
    {UL_OPEN_PAREN,         token{UL_OPEN_PAREN,         "LPAREN",             S_TYPE, R"(\()", UL_NULL, EMPTY_STRING}},
    {UL_CLOSE_PAREN,        token{UL_CLOSE_PAREN,        "RPAREN",             S_TYPE, R"(\))", UL_NULL, EMPTY_STRING}},
    {UL_DASH,               token{UL_DASH,               "MINUS",              S_TYPE, "-", UL_NULL, EMPTY_STRING}},
    {UL_PLUS_SIGN,          token{UL_PLUS_SIGN,          "PLUS",               S_TYPE, R"(\+)", UL_NULL, EMPTY_STRING}},
    {UL_EQUAL_SIGN,         token{UL_EQUAL_SIGN,         "EQUAL_SIGN",         S_TYPE, R"(=)", UL_NULL, EMPTY_STRING}},
    {UL_CLOSE_BRACKET,      token{UL_CLOSE_BRACKET,      "RBRACKET",           S_TYPE, R"(\])", UL_NULL, EMPTY_STRING}},
    {UL_OPEN_BRACE,         token{UL_OPEN_BRACE,         "OPEN_BRACE",         S_TYPE, R"(\{)", UL_NULL, EMPTY_STRING}},
    {UL_CLOSE_BRACE,        token{UL_CLOSE_BRACE,        "CLOSE_BRACE",        S_TYPE, R"(\})", UL_NULL, EMPTY_STRING}},
    {UL_OPEN_BRACKET,       token{UL_OPEN_BRACKET,       "LBRACKET",           S_TYPE, R"(\[)", UL_NULL, EMPTY_STRING}},
    {UL_VBAR,               token{UL_VBAR,               "VBAR",               S_TYPE, R"(\|)", UL_NULL, EMPTY_STRING}},
    {UL_BACKSLASH,          token{UL_BACKSLASH,          "BACKSLASH",          S_TYPE, R"(\\)", UL_NULL, EMPTY_STRING}},
    {UL_COLON,              token{UL_COLON,              "COLON",              S_TYPE, ":", UL_NULL, EMPTY_STRING}},
    {UL_HASH_MARK,          token{UL_HASH_MARK,          "HASH_MARK",          S_TYPE, R"(#)", UL_NULL, EMPTY_STRING}},
    {UL_SEMI_COLON,         token{UL_SEMI_COLON,         "SEMI_COLON",         S_TYPE, R"(;)", UL_NULL, EMPTY_STRING}},
    {UL_SINGLE_QUOTE,       token{UL_SINGLE_QUOTE,       "SINGLE_QUOTE",       S_TYPE, R"(')", UL_NULL, EMPTY_STRING}},
    {UL_GREATER_THAN,       token{UL_GREATER_THAN,       "GREATER_THAN",       S_TYPE, R"(>)", UL_NULL, EMPTY_STRING}},
    {UL_QUESTION_MARK,      token{UL_QUESTION_MARK,      "QUESTION_MARK",      S_TYPE, R"(\?)", UL_NULL, EMPTY_STRING}},
    {UL_COMMA,              token{UL_COMMA,              "COMMA",              S_TYPE, R"(\,)", UL_NULL, EMPTY_STRING}},
    {UL_DOT,                token{UL_DOT,                "DOT",                S_TYPE, R"(\.)", UL_NULL, EMPTY_STRING}},
    {UL_SLASH,              token{UL_SLASH,              "SLASH",              S_TYPE, R"(/)", UL_NULL, EMPTY_STRING}},
    {UL_GREATER_THAN_EQUAL, token{UL_GREATER_THAN_EQUAL, "GREATER_THAN_EQUAL", S_TYPE, R"(>=)", UL_NULL, EMPTY_STRING}},
    {UL_LESS_THAN_EQUAL,    token{UL_LESS_THAN_EQUAL,    "LESS_THAN_EQUAL",    S_TYPE, R"(<=)", UL_NULL, EMPTY_STRING}},
    {UL_STRING_LITERAL,     token{UL_STRING_LITERAL,     "STRING_LITERAL",     S_TYPE, R"("[A-Za-z0-9*@_.~+-]+")", UL_NULL, EMPTY_STRING}},
    {UL_ARRAY,              token{UL_ARRAY,              "ARRAY",              S_TYPE, R"([A-Za-z*@_~+-][A-Za-z0-9*@_~+-]*\[[^\]]\])", UL_NULL, EMPTY_STRING}},
    {UL_IDENTIFIER,         token{UL_IDENTIFIER,         "IDENTIFIER",         S_TYPE, R"([A-Za-z*@_~+-][A-Za-z0-9*@_~+-]*)", UL_NULL, EMPTY_STRING}},
    {UL_COMMENT,            token{UL_COMMENT,            "COMMENT",            S_TYPE, R"(\{[ ]*\*[^*}]*\*[ ]*\})", UL_NULL, EMPTY_STRING}},
    {UL_CONST_SYMBOL,       token{UL_CONST_SYMBOL,       "CONST_SYMBOL",       S_TYPE, R"(#[A-Za-z*@_.~+-][A-Za-z0-9*@_.~+-]*#)", UL_NULL, EMPTY_STRING}},
    {UL_ANYTHING,           token{UL_ANYTHING,           "ANYTHING",           S_TYPE, ".", UL_NULL, EMPTY_STRING}},
    {UL_IF,                 token{UL_IF,                 "IF",                 S_TYPE, "if", UL_NULL, EMPTY_STRING}},
    {UL_ELSEIF,             token{UL_ELSEIF,             "ELSEIF",             S_TYPE, "elseif", UL_NULL, EMPTY_STRING}},
    {UL_WHILE,              token{UL_WHILE,              "WHILE",              S_TYPE, "while", UL_NULL, EMPTY_STRING}},
    {UL_ASSIGN,             token{UL_ASSIGN,             "ASSIGN",             S_TYPE, "assign", UL_NULL, EMPTY_STRING}},
    {UL_BREAK,              token{UL_BREAK,              "BREAK",              S_TYPE, "break", UL_NULL, EMPTY_STRING}},
    {UL_REQUIRE,            token{UL_REQUIRE,            "REQUIRE",            S_TYPE, "require", UL_NULL, EMPTY_STRING}},
    {UL_INCLUDE,            token{UL_INCLUDE,            "INCLUDE",            S_TYPE, "include", UL_NULL, EMPTY_STRING}},
    {UL_CONFIG_LOAD,        token{UL_CONFIG_LOAD,        "CONFIG_LOAD",        S_TYPE, "config_load", UL_NULL, EMPTY_STRING}},
    {UL_INSERT,             token{UL_INSERT,             "INSERT",             S_TYPE, "insert", UL_NULL, EMPTY_STRING}},
    {UL_VAR_ATTRIB,         token{UL_VAR_ATTRIB,         "VAR_ATTRIB",         S_TYPE, R"(var='[^']*')", UL_NULL, EMPTY_STRING}},
    {UL_VALUE_ATTRIB,       token{UL_VALUE_ATTRIB,       "VALUE_ATTRIB",       S_TYPE, R"(value='[^']*')", UL_NULL, EMPTY_STRING}},
    {UL_FROM_ATTRIB,        token{UL_FROM_ATTRIB,        "FROM_ATTRIB",        S_TYPE, R"(from='[^']*')", UL_NULL, EMPTY_STRING}},
    {UL_ITEM_ATTRIB,        token{UL_ITEM_ATTRIB,        "ITEM_ATTRIB",        S_TYPE, R"(item='[^']*')", UL_NULL, EMPTY_STRING}},
    {UL_KEY_ATTRIB,         token{UL_KEY_ATTRIB,         "KEY_ATTRIB",         S_TYPE, R"(key='[^']*')", UL_NULL, EMPTY_STRING}},
    {UL_NAME_ATTRIB,        token{UL_NAME_ATTRIB,        "NAME_ATTRIB",        S_TYPE, R"(name='[^']*')", UL_NULL, EMPTY_STRING}},
    {UL_FILE_ATTRIB,        token{UL_FILE_ATTRIB,        "FILE_ATTRIB",        S_TYPE, R"(file='[^']*')", UL_NULL, EMPTY_STRING}},
    {UL_CAPITALIZE,         token{UL_CAPITALIZE,         "CAPITALIZE",         S_TYPE, "capitalize", UL_NULL, EMPTY_STRING}},
    {UL_COUNT_PARAGRAPHS,   token{UL_COUNT_PARAGRAPHS,   "COUNT_PARAGRAPHS",   S_TYPE, "count_paragraphs", UL_NULL, EMPTY_STRING}},
    {UL_COUNT_SENTENCES,    token{UL_COUNT_SENTENCES,    "COUNT_SENTENCES",    S_TYPE, "count_sentences", UL_NULL, EMPTY_STRING}},
    {UL_COUNT_WORDS,        token{UL_COUNT_WORDS,        "COUNT_WORDS",        S_TYPE, "count_words", UL_NULL, EMPTY_STRING}},
    {UL_DATE_FORMAT,        token{UL_DATE_FORMAT,        "DATE_FORMAT",        S_TYPE, "date_format", UL_NULL, EMPTY_STRING}},
    {UL_NULL,               token{UL_NULL,               "DEFAULT",            S_TYPE, R"(default)", UL_NULL, EMPTY_STRING}},
    {UL_ESCAPE,             token{UL_ESCAPE,             "ESCAPE",             S_TYPE, R"(escape)", UL_NULL, EMPTY_STRING}},
    {UL_INDENT,             token{UL_INDENT,             "INDENT",             S_TYPE, R"(indent)", UL_NULL, EMPTY_STRING}},
    {UL_LOWER,              token{UL_LOWER,              "LOWER",              S_TYPE, R"(lower)", UL_NULL, EMPTY_STRING}},
    {UL_UPPER,              token{UL_UPPER,              "UPPER",              S_TYPE, R"(upper)", UL_NULL, EMPTY_STRING}},
    {UL_STRIP,              token{UL_STRIP,              "STRIP",              S_TYPE, R"(strip)", UL_NULL, EMPTY_STRING}},
    {UL_NL2BR,              token{UL_NL2BR,              "NL2BR",              S_TYPE, R"(nl2br)", UL_NULL, EMPTY_STRING}},
    {UL_REGX_REPLACE,       token{UL_REGX_REPLACE,       "REGX_REPLACE",        S_TYPE, R"(regx_replace)", UL_NULL, EMPTY_STRING}},
    {UL_REPLACE,            token{UL_REPLACE,            "REPLACE",             S_TYPE, R"(replace)", UL_NULL, EMPTY_STRING}},
    {UL_SPACIFY,            token{UL_SPACIFY,            "SPACIFY",             S_TYPE, R"(spacify)", UL_NULL, EMPTY_STRING}},
    {UL_STRING_FORMAT,      token{UL_STRING_FORMAT,      "STRING_FORMAT",       S_TYPE, R"(string_format)", UL_NULL, EMPTY_STRING}},
    {UL_STRIP_TAGS,         token{UL_STRIP_TAGS,         "STRIP_TAGS",          S_TYPE, R"(strip_tags)", UL_NULL, EMPTY_STRING}},
    {UL_TRUNCATE,           token{UL_TRUNCATE,           "TRUNCATE",            S_TYPE, R"(truncate)", UL_NULL, EMPTY_STRING}},
    {UL_WORDWRAP,           token{UL_WORDWRAP,           "WORDWRAP",            S_TYPE, R"(wordwrap)", UL_NULL, EMPTY_STRING}}
};

/**
 * @brief unsigned long states
 */
constexpr unsigned long UL_INITIAL_STATE = 0x10;
constexpr unsigned long UL_COMMENT_STATE = 0x20;
constexpr unsigned long UL_ESCAPED_STATE = 0x40;
constexpr unsigned long UL_DOUBLE_QUOTED_STATE = 0x80;
constexpr unsigned long UL_SINGLE_QUOTED_STATE = 0x100;
constexpr unsigned long UL_INCLUDING_STATE = 0x200;
constexpr unsigned long UL_IF_BLOCK_STATE = 0x400;
constexpr unsigned long UL_IF_CONDITION_STATE = 0x800;

/**
 * @brief state_t states
 */
inline state_t sINITIAL = {UL_INITIAL_STATE, "INITIAL"};
inline state_t sCOMMENT = {UL_COMMENT_STATE, "COMMENT"};
inline state_t sESCAPED = {UL_ESCAPED_STATE, "ESCAPED"};
inline state_t sDOUBLE_QUOTED = {UL_DOUBLE_QUOTED_STATE, "DOUBLE_QUOTED"};
inline state_t sSINGLE_QUOTED = {UL_SINGLE_QUOTED_STATE, "SINGLE_QUOTED"};
inline state_t sINCLUDING = {UL_INCLUDING_STATE, "INCLUDING"};
inline state_t sIF_BLOCK = {UL_IF_BLOCK_STATE, "IF_BLOCK"};
inline state_t sIF_CONDITION = {UL_IF_CONDITION_STATE, "IF_CONDITION"};

/**
 * @brief token list -> by state
 */
inline vector<unsigned long> INITIAL_STATE_TOKENS = {UL_OPEN_BRACE};
inline vector<unsigned long> COMMENT_STATE_TOKENS = {UL_OPEN_BRACE, UL_COMMENT, UL_ANYTHING};
inline vector<unsigned long> ESCAPED_STATE_TOKENS = {UL_DOLLAR_SIGN, UL_HASH_MARK, UL_VBAR, UL_IDENTIFIER, UL_COLON, UL_COMMA, UL_DOT, UL_PERCENT_SIGN, UL_NUMERIC_LITERAL, UL_CLOSE_BRACE, UL_EQUAL_SIGN};
inline vector<unsigned long> DOUBLE_QUOTED_STATE_TOKENS = {UL_DOUBLE_QUOTE, UL_VALID_CHAR};
inline vector<unsigned long> SINGLE_QUOTED_STATE_TOKENS = {UL_OPEN_BRACE, UL_COMMENT, UL_VALID_CHAR, UL_SINGLE_QUOTE, UL_DOUBLE_QUOTE};
inline vector<unsigned long> INCLUDING_STATE_TOKENS = {UL_OPEN_BRACE, UL_COMMENT, UL_ANYTHING};
inline vector<unsigned long> IF_BLOCK_STATE_TOKENS = {UL_OPEN_BRACE, UL_COMMENT, UL_ANYTHING};
inline vector<unsigned long> IF_CONDITION_STATE_TOKENS = {UL_OPEN_BRACE, UL_COMMENT, UL_ANYTHING};

/**
 * @brief state_t states vector
 * @name g_states
 */
inline vector<state_t *> g_states{&sINITIAL,       &sCOMMENT,   &sESCAPED,  &sDOUBLE_QUOTED,
                                  &sSINGLE_QUOTED, &sINCLUDING, &sIF_BLOCK, &sIF_CONDITION};

/**
 * @brief state table : unsigned long -> state_t
 * @name g_state_tab
 */
inline map<unsigned long, state_t *> g_state_by_id = {{UL_INITIAL_STATE, &sINITIAL},
                                                    {UL_ESCAPED_STATE, &sESCAPED},
                                                    {UL_COMMENT_STATE, &sCOMMENT},
                                                    {UL_SINGLE_QUOTED_STATE, &sSINGLE_QUOTED},
                                                    {UL_DOUBLE_QUOTED_STATE, &sDOUBLE_QUOTED},
                                                    {UL_INCLUDING_STATE, &sINCLUDING},
                                                    {UL_IF_BLOCK_STATE, &sIF_BLOCK},
                                                    {UL_IF_CONDITION_STATE, &sIF_CONDITION} };

/**
 * @brief global state -> token table
 * @name g_state_tokens_tab
 */
inline map<unsigned long, vector<unsigned long>> g_tokens_by_state_id {{UL_INITIAL_STATE, INITIAL_STATE_TOKENS},
                                                                     {UL_ESCAPED_STATE, ESCAPED_STATE_TOKENS},
                                                                     {UL_COMMENT_STATE, COMMENT_STATE_TOKENS},
                                                                     {UL_SINGLE_QUOTED_STATE, SINGLE_QUOTED_STATE_TOKENS},
                                                                     {UL_DOUBLE_QUOTED_STATE, DOUBLE_QUOTED_STATE_TOKENS},
                                                                     {UL_INCLUDING_STATE, INCLUDING_STATE_TOKENS},
                                                                     {UL_IF_BLOCK_STATE, IF_BLOCK_STATE_TOKENS},
                                                                     {UL_IF_CONDITION_STATE, IF_CONDITION_STATE_TOKENS} };

/**
 * @brief global state_t state
 * @name gp_state
 */
inline state_t *gp_state = &sINITIAL;

/**
 * @name Lexer::on_state
 * @param state_t* pstate
 * @return unsigned long
 */
inline unsigned long Lexer::on_state(state_t *pstate)
{
   return -1;
}

/**
 * @name g_stringstream
 */
stringstream g_stringstream;

/**
 * @name Lexer::on_token
 * @brief override virtual, on_token, for each token ...
 * @param token_def* token
 */
inline parser::symbol_type Lexer::on_token(token_def *ptoken)
{
    switch (gp_state->id)
    {
        case UL_INITIAL_STATE:
        {
            switch (ptoken->id)
            {
            case UL_OPEN_BRACE:
                set_state(&sESCAPED);
                print_token(ptoken->id);
                m_sout << " ~" << ptoken->value << "~ ";
                return parser::make_OPEN_BRACE();
            case UL_SKIP_TOKEN:
                print_token(ptoken->id);
                cout << "default: SKIP_TOKEN" << endl;
                return parser::make_OPEN_BRACE();
            default:
                cout << "error: id=" << ptoken->id << ", name=" << ptoken->name << endl;
                return parser::make_UNDEFINED();
            }
            break;
        }
        case UL_ESCAPED_STATE:
        {
            switch (ptoken->id)
            {
            case UL_CLOSE_BRACE:
                set_state(&sINITIAL);
                print_token(ptoken->id);
                m_sout << " ~" << ptoken->value << "~ ";
                return parser::make_CLOSE_BRACE();
            case UL_INCLUDE:
                set_state(&sINCLUDING);
                print_token(ptoken->id);
                m_sout << " ~" << ptoken->value << "~ ";
                return parser::make_SKIP_TOKEN();
            case UL_DOLLAR_SIGN:
                print_token(ptoken->id);
                m_sout << " ~" << ptoken->value << "~ ";
                return parser::make_DOLLAR_SIGN();
            case UL_PERCENT_SIGN:
                print_token(ptoken->id);
                m_sout << " ~" << ptoken->value << "~ ";
                return parser::make_PERCENT_SIGN();
            case UL_HASH_MARK:
                print_token(ptoken->id);
                m_sout << " ~" << ptoken->value << "~ ";
                return parser::make_HASH_MARK();
            case UL_COLON:
                print_token(ptoken->id);
                m_sout << " ~" << ptoken->value << "~ ";
                return parser::make_COLON();
            case UL_COMMA:
                print_token(ptoken->id);
                m_sout << " ~" << ptoken->value << "~ ";
                return parser::make_COMMA();
            case UL_VBAR:
                print_token(ptoken->id);
                m_sout << " ~" << ptoken->value << "~ ";
                return parser::make_VBAR();
            case UL_IDENTIFIER:
                print_token(ptoken->id);
                m_sout << " ~" << ptoken->value << "~ ";
                return parser::make_IDENTIFIER(ptoken->value);
            case UL_EQUAL_SIGN:
                print_token(ptoken->id);
                m_sout << " ~" << ptoken->value << "~ ";
                return parser::make_EQUAL_SIGN();
            case UL_NUMERIC_LITERAL:
                print_token(ptoken->id);
                m_sout << " ~" << ptoken->value << "~ ";
                return parser::make_NUMERIC_LITERAL(ptoken->value);
            case UL_DOUBLE_QUOTE:
                set_state(&sDOUBLE_QUOTED);
                m_sout << " ~" << ptoken->value << "~ ";
            case UL_WHITESPACE:
            case UL_SKIP_TOKEN:
                return parser::make_SKIP_TOKEN();
            default:
                cout << "error: id=" << ptoken->id << ", name=" << ptoken->name << endl;
                return parser::make_UNDEFINED();
            }
            break;
        }
        case UL_DOUBLE_QUOTED_STATE:
        {
            switch (ptoken->id)
            {
            // case UL_ESC_TAB:
            //     g_stringstream << "\t";
            //     return parser::make_SKIP_TOKEN();
            // case UL_ESC_BACKSLASH:
            //     g_stringstream << "\\";
            //     return parser::make_SKIP_TOKEN();
            // case UL_ESC_DOUBLE_QUOTE:
            //     g_stringstream << "\"";
            //     return parser::make_SKIP_TOKEN();
            // case UL_ESC_SINGLE_QUOTE:
            //     g_stringstream << "'";
            //     return parser::make_SKIP_TOKEN();
            case UL_VALID_CHAR:
                g_stringstream << ptoken->value;
                cout << "char " << g_stringstream.str() << endl;
                return parser::make_SKIP_TOKEN();
            case UL_SKIP_TOKEN:
                cout << "SKIP_TOKEN" << endl;
                return parser::make_SKIP_TOKEN();
            case UL_DOUBLE_QUOTE:
                set_state(&sESCAPED);
                return parser::make_STRING_LITERAL(g_stringstream.str());
            default:
                return parser::make_SKIP_TOKEN();
            }
            break;
        }
        case UL_INCLUDING_STATE:
        {
            switch (ptoken->id)
            {
                case UL_FILE_ATTRIB:
                {
                    const int len = m_matches.size();
                    const string val = m_matches[ len-1 ]->value;

                    const boost::regex re(R"(file='(?<file_name>[^']*)')");
                    boost::smatch match;
                    boost::regex_match(val, match, re);
                    string file = match[1].str();

                    cout << file << endl;

                    // get include text & append remaining text from current file to it
                    // set m_current_search_text, continue lexing ...
                    pair<string, string> p(file, m_suffix);
                    //filestack.push(m_suffix);

                    string sout;
                    read_str(file, sout);

                    // bkp todo !!
                    // parse /compile include

                    m_current_search_text = sout + m_current_search_text;
                    return parser::make_SKIP_TOKEN();
                }
                case UL_CLOSE_BRACE:
                    set_state(&sINITIAL);
                    return parser::make_CLOSE_BRACE();
                case UL_SINGLE_QUOTE:
                    set_state(&sESCAPED);
                    return parser::make_STRING_LITERAL(g_stringstream.str());
                default:
                    cout << "error: id=" << ptoken->id << ", name=" << ptoken->name << endl;
                    return parser::make_UNDEFINED();
            }
            break;
        }
        default:
        {
            cout << "ERROR:" << ptoken->id << endl;
            break;
        }
    }

    return parser::make_END();
}
#endif
