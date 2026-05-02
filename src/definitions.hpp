/**
 * @file    lexer.hpp
 * @version 0.0.1
 * @date    Fri, 26 Sep 2025 17:05:10
 */
#ifndef _DEFINITIONS_HPP_
#define _DEFINITIONS_HPP_

#ifdef _MSC_VER
#define forceinline __forceinline
#elif defined(__GNUC__)
#define forceinline inline __attribute__((__always_inline__))
#elif defined(__CLANG__)
#if __has_attribute(__always_inline__)
#define forceinline inline __attribute__((__always_inline__))
#else
#define forceinline inline
#endif
#else
#define forceinline inline
#endif

#include <iostream>
#include <iterator>
#include <map>
#include <stack>
#include <fstream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <iomanip>
#include <boost/regex.hpp>
#include "pparser.tab.hpp"

using std::list;
using std::map;
using std::fstream;
using std::pair;
using std::string;
using std::stringstream;
using std::vector;
using yy::parser;

const string VALID_SYMBOL_CHARS = R"([A-Za-z0-9_])";  /** @note_to_self: ~~> \w == [A-Za-z0-9_] **/
const string VALID_CHARS = R"([[:punct:][:alnum:]])"; // [:punct:] = !"#$%&'()*+,-./:;<=>?@[\]^_{|}~`);
const string CONFIG_STATES = R"((?<states>^\s*(?<state>[A-Za-z][A-Za-z0-9_]*)\s*=\s*\s*\{(?<tokens>[A-Za-z][A-Za-z0-9_]*(, [A-Za-z][A-Za-z0-9_]*)*)\}\s*\s*$))";
const string CONFIG_SECTIONS = R"(^\s*\[\s*(?<tokens>tokens)|(?<groups>groups)|(?<states>states)\s*\]\s*$)";
const string CONFIG_PAIR = R"(\s*(?<type>" + TOKEN_TYPE_ + ")\\s+(?<name>[A-Za-z])" + VALID_SYMBOL_CHARS + R"("*)\\s*=\\s*(?<rexp>)" + VALID_CHARS + R"(*)\s*\"(?<test>.*)\"\s*)";
const string CONFIG_COMMENT = R"(^\s*#.*$)";
const string CONFIG = R"((?<pairs>)" + CONFIG_PAIR + R"()|(?<comments>)" + CONFIG_COMMENT + R"())";
const string qwerty = R"(ABCDEFGHIJKLMNOPQRSTUVWXYZabcefghijklmnopqrstuvwxyz1234567890~!@#$%^&*()_+{}|:"<>?`-=[]\;',./')";

// groups
const string BUILTIN_FUNCTION = "(insert)|(include)|(config_load)|(assign)|(fetch)|(capture)";
const string MATH = "(abs)|(ceil)|(cos)|(exp)|(floor)|(log)|(log10)|(max)|(min)|(pi)|(pow)|(rand)|(round)|(sin)|(sqrt)|(srans)|(tan)";
const string KEY_WORDS = "(if)|(else)|(elseif)|(foreach)|(foreachelse)|(literal)|(section)|(strip)|(assign)|(counter)|(cycle)|(debug)|(eval)|(fetch)|(html_checkboxes)";
const string VAR_MODIFIER = "(capitalize)|(indent)|(lower)|(upper)|(spacify)|(string_format)|(truncate)|(date_format)|(escape)";
typedef struct token_t
{
	string name;
	string stype;
	string rexp;
	unsigned long index;
} token_t;
typedef struct state_t
{
	unsigned long id;
	string name;
} state_t;

typedef token_t token;
typedef parser::token_type yytoken;
typedef parser::symbol_type yysymbol;
inline auto SKIP_TOKEN = yysymbol( yytoken::SKIP_TOKEN ).kind();

#define R_TILDE R"(~)"
#define R_EXCLAMATION R"(!)"
#define R_REAL_LITERAL R"(([0-9]+\.[0-9]*|[0-9]*\.[0-9]+)([eE][-+]?[0-9]+)?)"

/**
 * @brief token definitions : unsigned long integers
 */
#define TILDE 4ul
#define TIC_MARK 5ul
#define EXCLAMATION 6ul
#define AT_SYMBOL 7ul
#define HASH_MARK 8ul
#define DOLLAR_SIGN 9ul
#define PERCENT_SIGN 10ul
#define CARROT 11ul
#define AMPERSAND 12ul
#define ASTERISK 13ul
#define OPEN_PAREN 14ul
#define CLOSE_PAREN 15ul
#define DASH 16ul
#define UNDERSCORE 17ul
#define PLUS_SIGN 18ul
#define EQUAL_SIGN 19ul
#define OPEN_BRACE 20ul
#define OPEN_BRACKET 21ul
#define CLOSE_BRACE 22ul
#define CLOSE_BRACKET 23ul
#define VBAR 24ul
#define BACKSLASH 25ul
#define COLON 26ul
#define SEMI_COLON 27ul
#define DOUBLE_QUOTE 28ul
#define SINGLE_QUOTE 29ul
#define ESC_SEQ      307ul
#define ESC_NLINE      308ul
#define ESC_BACKSLASH 301ul
#define ESC_NEWLINE 302ul
#define ESC_DOUBLE_QUOTE 303ul
#define ESC_SINGLE_QUOTE 304ul
#define ESC_TAB 305ul
#define EQUALS 306ul
#define LESS_THAN 30ul
#define COMMA 31ul
#define GREATER_THAN 32ul
#define DOT 33ul
#define QUESTION_MARK 34ul
#define SLASH 35ul
#define NOT 39ul
#define AND 40ul
#define OR 41ul
#define XOR 42ul
#define LEFT_SHIFT 43ul
#define RIGHT_SHIFT 44ul
#define LOGICAL_AND 45ul
#define LOGICAL_OR 46ul
#define LOGICAL_NOT 47ul
#define LOGICAL_EQUAL 48ul
#define GREATER_THAN_EQUAL 49ul
#define LESS_THAN_EQUAL 50ul
#define NUMERIC_LITERAL 51ul
#define REAL_LITERAL   0x0FFFFFFFFFFF0001ul
#define STRING_LITERAL 52ul
#define DECIMAL_LITERAL 53ul
#define HEXADECIMAL_LITERAL 54ul
#define OCTAL_DECIMAL_LITERAL 55ul
#define IF 60ul
#define ELSE 61ul
#define ELSEIF 62ul
#define FOREACH 63ul
#define DO 64ul
#define WHILE 65ul
#define SWITCH 66ul
#define CASE 67ul
#define DEFAULT 68ul
#define BREAK 69ul
#define CONTINUE 70ul
#define TRY 71ul
#define CATCH 72ul
#define REQUIRE 77ul
#define CONFIG_LOAD 78ul
#define INSERT 79ul
#define INCLUDE 579ul
#define FILE_ATTRIB 81ul
#define ASSIGN 82ul
#define VAR_ATTRIB 83ul
#define VALUE_ATTRIB 84ul
#define FROM_ATTRIB 85ul
#define ITEM_ATTRIB 86ul
#define KEY_ATTRIB 87ul
#define NAME_ATTRIB 88ul
#define CAPITALIZE 89ul
#define CAT 90ul
#define COUNT_CHARACTERS 91ul
#define COUNT_PARAGRAPHS 92ul
#define COUNT_SENTENCES 93ul
#define COUNT_WORDS 94ul
#define DATE_FORMAT 95ul
#define ESCAPE 96ul
#define INDENT 97ul
#define LOWER 98ul
#define UPPER 99ul
#define STRIP 100ul
#define NL2BR 101ul
#define REGX_REPLACE 102ul
#define REPLACE 103ul
#define SPACIFY 104ul
#define STRING_FORMAT 105ul
#define STRIP_TAGS 106ul
#define TRUNCATE 107ul
#define WORDWRAP 108ul
#define VALID_CHAR 113ul
#define FIRST_CHAR 114ul
#define ID 115ul
#define IDENTIFIER 116ul
#define SYMBOL 117ul
#define CONST_SYMBOL 118ul
#define ARRAY 119ul
#define COMMENT 120ul
#define WHITESPACE 121ul
#define FILE_NAME 122ul
#define HAS_SIGN 123ul
#define NEWLINE 124ul
#define SKIP_TOK 125
#define UNESCAPED_TEXT 126
#define SCAN_EOF 128
#define ANYTHING 130
#define MATCH 140
#define UNDEFINED 150
#define EMPTY_STRING 160ul
#define INDIRECT_MEMBER 170ul
#define MODIFIER 180ul
#define BLOCK 190ul
#define BLOCKS 200ul
#define BUILT_IN 210ul
#define FILES 220ul
#define FILE 230ul
#define ASSIGN_STMT 240ul
#define EXPR 250ul
#define SUB_PROC 260ul
#define PARAM 270ul
#define PARAMS 280ul
#define COLON_SEP_PARAMS 290ul
#define COLON_SEP_PARAM 300ul
#define ATTRIB 310ul
#define ATTRIBUTES 320ul
#define ATTRIB_NAME 330ul
#define COMPILER 440ul
#define END_OF_FILE 442ul
#define END_OF_FILES 445ul
#define S_TYPE "string"


#define isodigit(x) ((x) >= '0' && (x) <= '7')
#define hextoint(x) (isdigit((x)) ? (x) - '0' : ((x) - 'A') + 10)

// hex (x|X)[0-9a-fA-F]{1,2}
// oct [0-7]{1,3}

/**
 * @name g_tokens
 * @brief global token vector - all tokens
 */
inline map<unsigned long, token> g_tokens =
{
	{UNESCAPED_TEXT,	token{"UNESCAPED_TEXT", S_TYPE, R"([^{]+)", __LINE__}},
	{ESC_SEQ,	        token{"ESC_SEQ", S_TYPE, R"(\\[^\n])", __LINE__}},
	{ESC_NLINE,	        token{"ESC_NINE", S_TYPE, R"([^\\\n])", __LINE__}},
	{WHITESPACE, 		token{"WHITESPACE", S_TYPE, R"([ \t])", __LINE__}},
	{NEWLINE,           token{"NEWLINE", S_TYPE, R"(\n)", __LINE__}},
	{FILE_ATTRIB,       token{"FILE_ATTRIB", S_TYPE, R"(file)", __LINE__}},
	{VALID_CHAR,        token{"VALID_CHAR", S_TYPE, R"([A-Za-z0-9*@_.~+-/ ])", __LINE__}},
	{NUMERIC_LITERAL,   token{"NUMERIC_LITERAL", S_TYPE, R"([1-9]+[0-9]*|0)", __LINE__}},
	{REAL_LITERAL,      token{"REAL_LITERAL", S_TYPE, R"(([0-9]+\.[0-9]*|[0-9]*\.[0-9]+)([eE][-+]?[0-9]+)?)", __LINE__}},
	{CAPITALIZE,        token{"CAPITALIZE", S_TYPE, R"(capitalize)", __LINE__}},
	{STRING_LITERAL,    token{"STRING_LITERAL", S_TYPE, R"("[A-Za-z0-9*@_.~+-/ ]+")", __LINE__}},
	{ARRAY,             token{"ARRAY", S_TYPE, R"([A-Za-z*@_~+-][A-Za-z0-9*@_~+-]*\[[^\]]\])", __LINE__}},
	{SYMBOL,            token{"SYMBOL", S_TYPE, R"(\$[A-Za-z*@_~+-][A-Za-z0-9*@_~+-]*)", __LINE__}},
	{CONST_SYMBOL,      token{"CONST_SYMBOL", S_TYPE, R"(#[A-Za-z*@_.~+-][A-Za-z0-9*@_~+-]*#)", __LINE__}},
	{IDENTIFIER,        token{"IDENTIFIER", S_TYPE, R"([A-Za-z*@_~+-][A-Za-z0-9*@_~+-]*)", __LINE__}},
	{COMMENT,           token{"COMMENT", S_TYPE, R"(\{[ ]*\*[^*}]*\*[ ]*\})", __LINE__}},
	{VAR_ATTRIB,        token{"VAR_ATTRIB", S_TYPE, R"(var='[^']*')", __LINE__}},
	{VALUE_ATTRIB,      token{"VALUE_ATTRIB", S_TYPE, R"(value='[^']*')", __LINE__}},
	{FROM_ATTRIB,       token{"FROM_ATTRIB", S_TYPE, R"(from='[^']*')", __LINE__}},
	{ITEM_ATTRIB,       token{"ITEM_ATTRIB", S_TYPE, R"(item='[^']*')", __LINE__}},
	{KEY_ATTRIB,        token{"KEY_ATTRIB", S_TYPE, R"(key='[^']*')", __LINE__}},
	{NAME_ATTRIB,       token{"NAME_ATTRIB", S_TYPE, R"(name='[^']*")", __LINE__}},
 // {START_ATTRIB,      token{"START_ATTRIB", S_TYPE, R"(key='[^']*')", __LINE__}},
 // {MAX_ATTRIB,        token{"MAX_ATTRIB", S_TYPE, R"(key='[^']*')", __LINE__}},
 // {ONCE_ATTRIB,       token{"ONCE_ATTRIB", S_TYPE, R"(key='[^']*')", __LINE__}},
 // {SCRIPT_ATTRIB,     token{"SCRIPT_ATTRIB", S_TYPE, R"(key='[^']*')", __LINE__}},
 // {LOOP_ATTRIB,       token{"LOOP_ATTRIB", S_TYPE, R"(key='[^']*')", __LINE__}},
 // {STEP_ATTRIB,       token{"STEP_ATTRIB", S_TYPE, R"(key='[^']*')", __LINE__}},
 // {SHOW_ATTRIB,       token{"SHOW_ATTRIB", S_TYPE, R"(key='[^']*')", __LINE__}},
 // {SKIP_ATTRIB,       token{"SKIP_ATTRIB", S_TYPE, R"(key='[^']*')", __LINE__}},
 // {PRINT_ATTRIB,      token{"PRINT_ATTRIB", S_TYPE, R"(key='[^']*')", __LINE__}},
 // {DIRECTION_ATTRIB,  token{"DIRECTION_ATTRIB", S_TYPE, R"(key='[^']*')", __LINE__}},
 // {ADVANCE_ATTRIB,    token{"ADVANCE_ATTRIB", S_TYPE, R"(key='[^']*')", __LINE__}},
 // {RESET_ATTRIB,      token{"RESET_ATTRIB", S_TYPE, R"(key='[^']*')", __LINE__}},
 // {DELIMITER_ATTRIB,  token{"DELIMITER_ATTRIB", S_TYPE, R"(key='[^']*')", __LINE__}},
 // {OUTPUT_ATTRIB,     token{"OUTPUT_ATTRIB", S_TYPE, R"(key='[^']*')", __LINE__}},
 // {HEIGHT_ATTRIB,     token{"HEIGHT_ATTRIB", S_TYPE, R"(key='[^']*')", __LINE__}},
 // {WIDTH_ATTRIB,      token{"WIDTH_ATTRIB", S_TYPE, R"(key='[^']*')", __LINE__}},
 // {ALT_ATTRIB,        token{"ALT_ATTRIB", S_TYPE, R"(key='[^']*')", __LINE__}},
 // {HREF_ATTRIB,       token{"HREF_ATTRIB", S_TYPE, R"(key='[^']*')", __LINE__}},
 // {BASEDIR_ATTRIB,    token{"BASEDIR_ATTRIB", S_TYPE, R"(key='[^']*')", __LINE__}},
 // {PATH_PREFIX_ATTRIB,token{"PATH_PREFIX_ATTRIB", S_TYPE, R"(key='[^']*')", __LINE__}},
 // {SELECTED_ATTRIB,   token{"SELECTED_ATTRIB", S_TYPE, R"(key='[^']*')", __LINE__}},
 // {OPTIONS_ATTRIB,    token{"OPTIONS_ATTRIB", S_TYPE, R"(key='[^']*')", __LINE__}},
 // {VALUES_ATTRIB,     token{"VALUES_ATTRIB", S_TYPE, R"(key='[^']*')", __LINE__}},
 // {SEPERATOR_ATTRIB,  token{"SEPERATOR_ATTRIB", S_TYPE, R"(key='[^']*')", __LINE__}},
 // {FORMAT_ATTRIB,     token{"FORMAT_ATTRIB", S_TYPE, R"(key='[^']*')", __LINE__}},
	{DOUBLE_QUOTE,      token{"DOUBLE_QUOTE", S_TYPE, R"(")", __LINE__}},
	{TILDE,             token{"TILDE", S_TYPE, R"(~)", __LINE__}},
	{EXCLAMATION,       token{"EXCLAMATION", S_TYPE, R"(!)", __LINE__}},
	{AT_SYMBOL,         token{"AT_SYMBOL", S_TYPE, R"(@)", __LINE__}},
	{TIC_MARK,          token{"TIC_MARK", S_TYPE, R"(`)", __LINE__}},
	{CARROT,            token{"CARROT", S_TYPE, R"(\^)", __LINE__}},
	{AMPERSAND,         token{"AMPERSAND", S_TYPE, R"(&)", __LINE__}},
	{ASTERISK,          token{"ASTERISK", S_TYPE, R"(\*)", __LINE__}},
	{OPEN_PAREN,        token{"LPAREN", S_TYPE, R"(\()", __LINE__}},
	{CLOSE_PAREN,       token{"RPAREN", S_TYPE, R"(\))", __LINE__}},
	{DASH,              token{"MINUS", S_TYPE, R"(-)", __LINE__}},
	{PLUS_SIGN,         token{"PLUS", S_TYPE, R"(\+)", __LINE__}},
	{EQUAL_SIGN,        token{"EQUAL_SIGN", S_TYPE, R"(=)", __LINE__}},
	{CLOSE_BRACKET,     token{"RBRACKET", S_TYPE, R"(\])", __LINE__}},
	{OPEN_BRACE,        token{"OPEN_BRACE", S_TYPE, R"(\{)", __LINE__}},
	{CLOSE_BRACE,       token{"CLOSE_BRACE", S_TYPE, R"(\})", __LINE__}},
	{OPEN_BRACKET,      token{"LBRACKET", S_TYPE, R"(\[)", __LINE__}},
	{VBAR,              token{"VBAR", S_TYPE, R"(\|)", __LINE__}},
	{BACKSLASH,         token{"BACKSLASH", S_TYPE, R"(\\)", __LINE__}},
	{COLON,             token{"COLON", S_TYPE, R"(:)", __LINE__}},
	{SEMI_COLON,        token{"SEMI_COLON", S_TYPE, R"(;)", __LINE__}},
	{SINGLE_QUOTE,      token{"SINGLE_QUOTE", S_TYPE, R"(')", __LINE__}},
	{GREATER_THAN,      token{"GREATER_THAN", S_TYPE, R"(>)", __LINE__}},
	{QUESTION_MARK,     token{"QUESTION_MARK", S_TYPE, R"(\?)", __LINE__}},
	{COMMA,             token{"COMMA", S_TYPE, R"(\,)", __LINE__}},
	{DOT,               token{"DOT", S_TYPE, R"(\.)", __LINE__}},
	{SLASH,             token{"SLASH", S_TYPE, R"(/)", __LINE__}},
	{GREATER_THAN_EQUAL,token{"GREATER_THAN_EQUAL", S_TYPE, R"(>=)", __LINE__}},
	{LESS_THAN_EQUAL,   token{"LESS_THAN_EQUAL", S_TYPE, R"(<=)", __LINE__}},
	{IF,                token{"IF", S_TYPE, R"(if)", __LINE__}},
	{ELSE,              token{"ELSE", S_TYPE, R"(else)", __LINE__}},
	{ELSEIF,            token{"ELSEIF", S_TYPE, R"(elseif)", __LINE__}},
	{WHILE,             token{"WHILE", S_TYPE, R"(while)", __LINE__}},
	{ASSIGN,            token{"ASSIGN", S_TYPE, R"(assign)", __LINE__}},
	{BREAK,             token{"BREAK", S_TYPE, R"(break)", __LINE__}},
	{REQUIRE,           token{"REQUIRE", S_TYPE, R"(require)", __LINE__}},
	{INCLUDE,           token{"INCLUDE", S_TYPE, R"(include)", __LINE__}},
	{CONFIG_LOAD,       token{"CONFIG_LOAD", S_TYPE, R"(config_load)", __LINE__}},
	{INSERT,            token{"INSERT", S_TYPE, R"(insert)", __LINE__}},
	{COUNT_PARAGRAPHS,  token{"COUNT_PARAGRAPHS", S_TYPE, R"(count_paragraphs)", __LINE__}},
	{COUNT_SENTENCES,   token{"COUNT_SENTENCES", S_TYPE, R"(count_sentences)", __LINE__}},
	{COUNT_WORDS,       token{"COUNT_WORDS", S_TYPE, R"(count_words)", __LINE__}},
	{DATE_FORMAT,       token{"DATE_FORMAT", S_TYPE, R"(date_format)", __LINE__}},
	{NULL,              token{"DEFAULT", S_TYPE, R"(default)", __LINE__}},
	{ESCAPE,            token{"ESCAPE", S_TYPE, R"(escape)", __LINE__}},
	{INDENT,            token{"INDENT", S_TYPE, R"(indent)", __LINE__}},
	{LOWER,             token{"LOWER", S_TYPE, R"(lower)", __LINE__}},
	{UPPER,             token{"UPPER", S_TYPE, R"(upper)", __LINE__}},
	{STRIP,             token{"STRIP", S_TYPE, R"(strip)", __LINE__}},
	{NL2BR,             token{"NL2BR", S_TYPE, R"(nl2br)", __LINE__}},
	{REGX_REPLACE,      token{"REGX_REPLACE", S_TYPE, R"(regx_replace)", __LINE__}},
	{REPLACE,           token{"REPLACE", S_TYPE, R"(replace)", __LINE__}},
	{SPACIFY,           token{"SPACIFY", S_TYPE, R"(spacify)", __LINE__}},
	{STRING_FORMAT,     token{"STRING_FORMAT", S_TYPE, R"(string_format)", __LINE__}},
	{STRIP_TAGS,        token{"STRIP_TAGS", S_TYPE, R"(strip_tags)", __LINE__}},
	{WORDWRAP,          token{"WORDWRAP", S_TYPE, R"(wordwrap)", __LINE__}},
	{TRUNCATE,          token{"TRUNCATE", S_TYPE, R"(truncate)", __LINE__}},
	{UNDEFINED,         token{"UNDEFINED", S_TYPE, R"(.)", __LINE__}},
};

/**
 * @brief unsigned long states
 */
constexpr unsigned long UL_INITIAL = 0x10;
constexpr unsigned long UL_UNESCAPE = 0x10;
constexpr unsigned long UL_COMMENTING = 0x20;
constexpr unsigned long UL_ESCAPED = 0x40;
constexpr unsigned long UL_DOUBLE_QUOTED = 0x80;
constexpr unsigned long UL_SINGLE_QUOTED = 0x100;
constexpr unsigned long UL_INCLUDING = 0x200;
constexpr unsigned long UL_IF_BLOCK = 0x400;
constexpr unsigned long UL_IF_CONDITION = 0x800;

/**
 * @brief global state IDs
 */
inline vector<unsigned long> state_ids = { UL_INITIAL, UL_COMMENTING, UL_ESCAPED, UL_DOUBLE_QUOTED, UL_SINGLE_QUOTED, UL_INCLUDING, UL_IF_BLOCK, UL_IF_CONDITION };

/**
 * @brief state_t states
 */

inline state_t INITIAL = { UL_INITIAL, "INITIAL" };
inline state_t COMMENTING = { UL_COMMENTING, "COMMENT" };
inline state_t ESCAPED = { UL_ESCAPED, "ESCAPED" };
inline state_t DOUBLE_QUOTED = { UL_DOUBLE_QUOTED, "DOUBLE_QUOTED" };
inline state_t SINGLE_QUOTED = { UL_SINGLE_QUOTED, "SINGLE_QUOTED" };
inline state_t INCLUDING = { UL_INCLUDING, "INCLUDING" };
inline state_t IF_BLOCK = { UL_IF_BLOCK, "IF_BLOCK" };
inline state_t IF_CONDITION = { UL_IF_CONDITION, "IF_CONDITION" };
inline state_t& UNESCAPED = INITIAL;

/**
 * @brief global state vector
 */
inline vector<state_t> states__ = { INITIAL, COMMENTING, ESCAPED, DOUBLE_QUOTED, SINGLE_QUOTED, INCLUDING, IF_BLOCK, IF_CONDITION };

/**
 * @brief token list -> by state
 */
inline vector<unsigned long> INITIAL_TOKENS = { UNESCAPED_TEXT, OPEN_BRACE, NEWLINE, COMMENT };

inline vector<unsigned long> ESCAPED_TOKENS = { CLOSE_BRACE, OPEN_BRACKET, DOUBLE_QUOTE, IF, ELSE, FILE_ATTRIB, INCLUDE, ASSIGN, STRING_LITERAL, NUMERIC_LITERAL, EQUAL_SIGN,
												CAPITALIZE, TRUNCATE, VBAR, COMMA, COLON, DOT, SLASH,  STRIP, SYMBOL, CONST_SYMBOL, WHITESPACE };

inline vector<unsigned long> COMMENTING_TOKENS = { OPEN_BRACE, COMMENT, ANYTHING };
inline vector<unsigned long> DOUBLE_QUOTED_TOKENS = { DOUBLE_QUOTE, VALID_CHAR };
inline vector<unsigned long> SINGLE_QUOTED_TOKENS = { OPEN_BRACE, COMMENT, VALID_CHAR, SINGLE_QUOTE, DOUBLE_QUOTE };
inline vector<unsigned long> INCLUDING_TOKENS = { FILE_ATTRIB };
inline vector<unsigned long> IF_BLOCK_TOKENS = { CLOSE_BRACE, CLOSE_BRACE, OPEN_BRACKET, DOUBLE_QUOTE, IF, ELSE, FILE_ATTRIB, INCLUDE, ASSIGN, STRING_LITERAL, NUMERIC_LITERAL, EQUAL_SIGN,
												CAPITALIZE, TRUNCATE, VBAR, COMMA, COLON, DOT, SLASH, STRIP, SYMBOL, CONST_SYMBOL };

inline vector<unsigned long> IF_CONDITION_TOKENS = { CLOSE_BRACE };

/**
 * @brief global state: state_id -> states
 * @name g_tokens_by_state_id
 */
inline map<unsigned long, vector<unsigned long>*> g_state_tokens { {UL_INITIAL, &INITIAL_TOKENS},
																	{UL_ESCAPED, &ESCAPED_TOKENS},
																	{UL_COMMENTING, &COMMENTING_TOKENS},
																	{UL_SINGLE_QUOTED, &SINGLE_QUOTED_TOKENS},
																	{UL_DOUBLE_QUOTED, &DOUBLE_QUOTED_TOKENS},
																	{UL_INCLUDING, &INCLUDING_TOKENS},
																	{UL_IF_BLOCK, &IF_BLOCK_TOKENS},
																	{UL_IF_CONDITION, &IF_CONDITION_TOKENS} };
/**
 *
 */
typedef unsigned long type_t;
typedef unsigned long terminal_t;
typedef vector<terminal_t> terminals_t;
typedef vector<type_t> types_t;
typedef vector<unsigned long> rules_t;
typedef vector<type_t> rules_t;
typedef vector<type_t> sequence_t;
typedef vector<sequence_t> sequences_t;
typedef map < type_t, sequences_t > maps;

#define PROGRAM 1ul
// #define FILES 2ul
// #define FILE 3ul
// #define BLOCKS 4ul
// #define BLOCK 5ul

//type_t type { PROGRAM, FILES, FILE, BLOCKS, BLOCK }
//maps g_map { type_t{PROGRAM}, sequences_t{ sequence_t{ PROGRAM, FILES } } }

//inline constexpr unsigned long ADD_TYPE, MUL_TYPE, NUM;
// TYPES types{ADD_TYPE, MUL_TYPE, NUM, EXPR};
// inline terminal_t terminals {OPEN_BRACE, SYMBOL, EQUALS, IDENTIFIER, PLUS_SIGN, NUMERIC_LITERAL, CLOSE_BRACE};

// inline rules_t rules_ {	{OPEN_BRACE, SYMBOL, EQUALS, IDENTIFIER, PLUS_SIGN, NUMERIC_LITERAL, CLOSE_BRACE},
// 					{OPEN_BRACE, SYMBOL, EQUALS, IDENTIFIER, CLOSE_BRACE},
// 					{OPEN_BRACE, SYMBOL, EQUALS, NUMERIC_LITERAL, CLOSE_BRACE},
// 					{OPEN_BRACE, SYMBOL, EQUALS, SYMBOL, CLOSE_BRACE},
// 					{SYMBOL}	};

// std::deque<unsigned long> rlz = { OPEN_BRACE, SYMBOL, CLOSE_BRACE};
// inline rules_t rules { { OPEN_BRACE, SYMBOL, EQUALS, IDENTIFIER, PLUS_SIGN, NUMERIC_LITERAL, CLOSE_BRACE},
// 												rule_t{OPEN_BRACE, SYMBOL, EQUALS, IDENTIFIER, CLOSE_BRACE},
// 												rule_t{OPEN_BRACE, SYMBOL, EQUALS, NUMERIC_LITERAL, CLOSE_BRACE},
// 												rule_t{OPEN_BRACE, SYMBOL, EQUALS, SYMBOL, CLOSE_BRACE},
// 										    	rule_t{SYMBOL} };


#endif
