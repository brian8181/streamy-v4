/**
 * @file    lexer.hpp
 * @version 0.0.1
 * @date    Fri, 26 Sep 2025 17:05:10 +0000
 */
#ifndef LEXER_HPP_
#define LEXER_HPP_

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
#include <list>
#include <map>
#include <stack>
#include <fstream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <iomanip>
#include <boost/regex.hpp>
#include "pparser.tab.hh"

using std::list;
using std::map;
using std::ofstream;
using std::pair;
using std::string;
using std::stringstream;
using std::vector;
using yy::parser;

#define INT 1
#define FLOAT 2

typedef struct token_def
{
    string name;
    string stype;
    string rexp;
    int _line_;
} token_def;

typedef token_def token;

struct token_match // : public token_def
{
    unsigned long id;
    token_def *token;
    string file;
    int line;
    int sub_index;
    boost::smatch *pmatch;
};

typedef struct state_t
{
    unsigned long id;
    string name;
} state_t;

class file_context
{
    string name;
    string *parent;
    char* text;
};

//static context* g_context;

// bkp todo cleanup!
const string VALID_SYMBOL_CHARS = R"([A-Za-z0-9_])";  /** @note_to_self: ~~> \w == [A-Za-z0-9_] **/
const string VALID_CHARS = R"([[:punct:][:alnum:]])"; // [:punct:] = !"#$%&'()*+,-./:;<=>?@[\]^_{|}~`);
const string CONFIG_STATES = R"((?<states>^\s*(?<state>[A-Za-z][A-Za-z0-9_]*)\s*=\s*\s*\{(?<tokens>[A-Za-z][A-Za-z0-9_]*(, [A-Za-z][A-Za-z0-9_]*)*)\}\s*\s*$))";
const string CONFIG_SECTIONS = R"(^\s*\[\s*(?<tokens>tokens)|(?<groups>groups)|(?<states>states)\s*\]\s*$)";
const string CONFIG_PAIR = R"(\s*(?<type>" + TOKEN_TYPE_ + ")\\s+(?<name>[A-Za-z])" + VALID_SYMBOL_CHARS + R"("*)\\s*=\\s*(?<rexp>)" + VALID_CHARS + R"(*)\s*\"(?<test>.*)\"\s*)";
const string CONFIG_COMMENT = R"(^\s*#.*$)";
const string CONFIG = R"((?<pairs>)" + CONFIG_PAIR + R"()|(?<comments>)" + CONFIG_COMMENT + R"())";
const string qwerty = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcefghijklmnopqrstuvwxyz1234567890~!@#$%^&*()_+{}|:\"<>?`-=[]\\;',./'";
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
#define UL_HAS_SIGN 123ul
#define UL_NEWLINE 124ul
#define UL_SKIP_TOKEN 0xFF0000ul
#define UL_UNESCAPED_TEXT 0x00FF00ul
#define UL_ERROR __LINE
#define UL_SCAN_EOF __LINE__
#define UL_ANYTHING __LINE__
#define UL_MATCH __LINE__
#define UL_UNDEFINED __LINE__
#define UL_NULL __LINE__
#define EMPTY_STRING __LINE__
#define S_TYPE "string"
#define UL_INDIRECT_MEMBER __LINE__
#define UL_MODIFIER __LINE__
#define UL_BLOCK __LINE__
#define UL_BLOCKS __LINE__
#define UL_BUILT_IN __LINE__
#define UL_FILES __LINE__
#define UL_FILE __LINE__
#define UL_ASSIGN_STMT __LINE__
#define UL_EXPR __LINE__
#define UL_SUB_PROC __LINE__
#define UL_PARAM __LINE__
#define UL_PARAMS __LINE__
#define UL_COLON_SEP_PARAMS __LINE__
#define UL_COLON_SEP_PARAM __LINE__
#define UL_ATTRIB
#define UL_ATTRIBUTES __LINE__
#define UL_ATTRIB_NAME __LINE__
#define UL_COMPILER __LINE__
#define UL_END_OF_FILE __LINE__
#define UL_END_OF_FILES __LINE__
/**
 * @name g_tokens_all
 * @brief global token vector - all tokens
 */
inline map<unsigned long, token_def> g_tokens = {
    {UL_MATCH, token{"MATCH", S_TYPE, R"(match)", __LINE__}},
    {UL_UNESCAPED_TEXT, token{"UNESCAPED_TEXT", S_TYPE, R"([^{]+)", __LINE__}},
    {UL_WHITESPACE, token{"WHITESPACE", S_TYPE, R"([ \t]*)", __LINE__}},
    {UL_NEWLINE, token{"NEWLINE", S_TYPE, R"(\n)", __LINE__}},
    {UL_FILE_ATTRIB, token{"FILE_ATTRIB", S_TYPE, R"(file)", __LINE__}},
    {UL_VALID_CHAR, token{"VALID_CHAR", S_TYPE, R"([A-Za-z0-9*@_~+-./ ])", __LINE__}},
    {UL_NUMERIC_LITERAL, token{"NUMERIC_LITERAL", S_TYPE, R"([0-9]+)", __LINE__}},
    {UL_CAPITALIZE, token{"UL_CAPITALIZE", S_TYPE, R"(capitalize)", __LINE__}},
    {UL_STRING_LITERAL, token{"STRING_LITERAL", S_TYPE, R"("[A-Za-z0-9*@_.~+-/ ]+")", __LINE__}},
    {UL_ARRAY, token{"ARRAY", S_TYPE, R"([A-Za-z*@_~+-][A-Za-z0-9*@_~+-]*\[[^\]]\])", __LINE__}},
    {UL_SYMBOL, token{"SYMBOL", S_TYPE, R"(\$[A-Za-z*@_.~+-][A-Za-z0-9*@_.~+-]*)", __LINE__}},
    {UL_CONST_SYMBOL, token{"CONST_SYMBOL", S_TYPE, R"(#[A-Za-z*@_.~+-][A-Za-z0-9*@_.~+-]*#)", __LINE__}},
    {UL_IDENTIFIER, token{"IDENTIFIER", S_TYPE, R"(1234567890)", __LINE__}},
    {UL_COMMENT, token{"COMMENT", S_TYPE, R"(\{[ ]*\*[^*}]*\*[ ]*\})", __LINE__}},
    {UL_VAR_ATTRIB, token{"VAR_ATTRIB", S_TYPE, R"(var='[^']*')", __LINE__}},
    {UL_VALUE_ATTRIB, token{"VALUE_ATTRIB", S_TYPE, R"(value='[^']*')", __LINE__}},
    {UL_FROM_ATTRIB, token{"FROM_ATTRIB", S_TYPE, R"(from='[^']*')", __LINE__}},
    {UL_ITEM_ATTRIB, token{"ITEM_ATTRIB", S_TYPE, R"(item='[^']*')", __LINE__}},
    {UL_KEY_ATTRIB, token{"KEY_ATTRIB", S_TYPE, R"(key='[^']*')", __LINE__}},
    {UL_NAME_ATTRIB, token{"NAME_ATTRIB", S_TYPE, R"(name='[^']*")", __LINE__}},
    {UL_DOUBLE_QUOTE, token{"DOUBLE_QUOTE", S_TYPE, R"(")", __LINE__}},
    {UL_TILDE, token{"TILDE", S_TYPE, R"(~)", __LINE__}},
    {UL_EXCLAMATION, token{"EXCLAMATION", S_TYPE, R"(!)", __LINE__}},
    {UL_AT_SYMBOL, token{"AT_SYMBOL", S_TYPE, R"(@)", __LINE__}},
    {UL_TIC_MARK, token{"TIC_MARK", S_TYPE, R"(`)", __LINE__}},
    {UL_CARROT, token{"CARROT", S_TYPE, R"(\^)", __LINE__}},
    {UL_AMPERSAND, token{"AMPERSAND", S_TYPE, R"(&)", __LINE__}},
    {UL_ASTERISK, token{"ASTERISK", S_TYPE, R"(\*)", __LINE__}},
    {UL_OPEN_PAREN, token{"LPAREN", S_TYPE, R"(\()", __LINE__}},
    {UL_CLOSE_PAREN, token{"RPAREN", S_TYPE, R"(\))", __LINE__}},
    {UL_DASH, token{"MINUS", S_TYPE, R"(-)", __LINE__}},
    {UL_PLUS_SIGN, token{"PLUS", S_TYPE, R"(\+)", __LINE__}},
    {UL_EQUAL_SIGN, token{"EQUAL_SIGN", S_TYPE, R"(=)", __LINE__}},
    {UL_CLOSE_BRACKET, token{"RBRACKET", S_TYPE, R"(\])", __LINE__}},
    {UL_OPEN_BRACE, token{"OPEN_BRACE", S_TYPE, R"(\{)", __LINE__}},
    {UL_CLOSE_BRACE, token{"CLOSE_BRACE", S_TYPE, R"(\})", __LINE__}},
    {UL_OPEN_BRACKET, token{"LBRACKET", S_TYPE, R"(\[)", __LINE__}},
    {UL_VBAR, token{"VBAR", S_TYPE, R"(\|)", __LINE__}},
    {UL_BACKSLASH, token{"BACKSLASH", S_TYPE, R"(\\)", __LINE__}},
    {UL_COLON, token{"COLON", S_TYPE, R"(:)", __LINE__}},
    {UL_SEMI_COLON, token{"SEMI_COLON", S_TYPE, R"(;)", __LINE__}},
    {UL_SINGLE_QUOTE, token{"SINGLE_QUOTE", S_TYPE, R"(')", __LINE__}},
    {UL_GREATER_THAN, token{"GREATER_THAN", S_TYPE, R"(>)", __LINE__}},
    {UL_QUESTION_MARK, token{"QUESTION_MARK", S_TYPE, R"(\?)", __LINE__}},
    {UL_COMMA, token{"COMMA", S_TYPE, R"(\,)", __LINE__}},
    {UL_DOT, token{"DOT", S_TYPE, R"(\.)", __LINE__}},
    {UL_SLASH, token{"SLASH", S_TYPE, R"(/)", __LINE__}},
    {UL_GREATER_THAN_EQUAL, token{"GREATER_THAN_EQUAL", S_TYPE, R"(>=)", __LINE__}},
    {UL_LESS_THAN_EQUAL, token{"LESS_THAN_EQUAL", S_TYPE, R"(<=)", __LINE__}},
    {UL_IF, token{"IF", S_TYPE, R"(if)", __LINE__}},
    {UL_ELSEIF, token{"ELSEIF", S_TYPE, R"(elseif)", __LINE__}},
    {UL_WHILE, token{"WHILE", S_TYPE, R"(while)", __LINE__}},
    {UL_ASSIGN, token{"ASSIGN", S_TYPE, R"(assign)", __LINE__}},
    {UL_BREAK, token{"BREAK", S_TYPE, R"(break)", __LINE__}},
    {UL_REQUIRE, token{"REQUIRE", S_TYPE, R"(require)", __LINE__}},
    {UL_INCLUDE, token{"INCLUDE", S_TYPE, R"(include)", __LINE__}},
    {UL_CONFIG_LOAD, token{"CONFIG_LOAD", S_TYPE, R"(config_load)", __LINE__}},
    {UL_INSERT, token{"INSERT", S_TYPE, R"(insert)", __LINE__}},
    {UL_COUNT_PARAGRAPHS, token{"COUNT_PARAGRAPHS", S_TYPE, R"(count_paragraphs)", __LINE__}},
    {UL_COUNT_SENTENCES, token{"COUNT_SENTENCES", S_TYPE, R"(count_sentences)", __LINE__}},
    {UL_COUNT_WORDS, token{"COUNT_WORDS", S_TYPE, R"(count_words)", __LINE__}},
    {UL_DATE_FORMAT, token{"DATE_FORMAT", S_TYPE, R"(date_format)", __LINE__}},
    {UL_NULL, token{"DEFAULT", S_TYPE, R"(default)", __LINE__}},
    {UL_ESCAPE, token{"ESCAPE", S_TYPE, R"(escape)", __LINE__}},
    {UL_INDENT, token{"INDENT", S_TYPE, R"(indent)", __LINE__}},
    {UL_LOWER, token{"LOWER", S_TYPE, R"(lower)", __LINE__}},
    {UL_UPPER, token{"UPPER", S_TYPE, R"(upper)", __LINE__}},
    {UL_STRIP, token{"STRIP", S_TYPE, R"(strip)", __LINE__}},
    {UL_NL2BR, token{"NL2BR", S_TYPE, R"(nl2br)", __LINE__}},
    {UL_REGX_REPLACE, token{"REGX_REPLACE", S_TYPE, R"(regx_replace)", __LINE__}},
    {UL_REPLACE, token{"REPLACE", S_TYPE, R"(replace)", __LINE__}},
    {UL_SPACIFY, token{"SPACIFY", S_TYPE, R"(spacify)", __LINE__}},
    {UL_STRING_FORMAT, token{"STRING_FORMAT", S_TYPE, R"(string_format)", __LINE__}},
    {UL_STRIP_TAGS, token{"STRIP_TAGS", S_TYPE, R"(strip_tags)", __LINE__}},
    {UL_WORDWRAP, token{"WORDWRAP", S_TYPE, R"(wordwrap)", __LINE__}},
    {UL_TRUNCATE, token{"TRUNCATE", S_TYPE, R"(truncate)", __LINE__}},

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
constexpr unsigned long UL_IF_CONDITION_STATE_AND_ESC = UL_IF_CONDITION_STATE | UL_ESCAPED_STATE;
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
inline vector<unsigned long> INITIAL_STATE_TOKENS = {UL_NEWLINE, UL_OPEN_BRACE, UL_COMMENT};

inline vector<unsigned long> ESCAPED_STATE_TOKENS = {UL_NEWLINE, UL_CLOSE_BRACE, UL_DOUBLE_QUOTE, UL_FILE_ATTRIB, UL_INCLUDE, UL_ASSIGN, UL_NUMERIC_LITERAL, UL_EQUAL_SIGN,
                                                     UL_CAPITALIZE, UL_TRUNCATE, UL_VBAR, UL_COLON, UL_STRIP, UL_SYMBOL, UL_CONST_SYMBOL, UL_WHITESPACE, UL_VALID_CHAR};

inline vector<unsigned long> COMMENT_STATE_TOKENS = {UL_OPEN_BRACE, UL_COMMENT, UL_ANYTHING};
inline vector<unsigned long> DOUBLE_QUOTED_STATE_TOKENS = {UL_DOUBLE_QUOTE, UL_VALID_CHAR};
inline vector<unsigned long> SINGLE_QUOTED_STATE_TOKENS = {UL_OPEN_BRACE, UL_COMMENT, UL_VALID_CHAR, UL_SINGLE_QUOTE, UL_DOUBLE_QUOTE};
inline vector<unsigned long> INCLUDING_STATE_TOKENS = {UL_FILE_ATTRIB};
inline vector<unsigned long> IF_BLOCK_STATE_TOKENS = {UL_CLOSE_BRACE};
inline vector<unsigned long> IF_CONDITION_STATE_TOKENS = {UL_CLOSE_BRACE};
/**
 * @brief state_t states vector
 * @name g_states
 */
inline vector<state_t *> g_states{&sINITIAL, &sCOMMENT, &sESCAPED, &sDOUBLE_QUOTED,
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
                                                      {UL_IF_CONDITION_STATE, &sIF_CONDITION}};
/**
 * @brief global state: state_id -> states
 * @name g_state_tokens_tab
 */
inline map<unsigned long, vector<unsigned long> *> g_tokens_by_state_id{{UL_INITIAL_STATE, &INITIAL_STATE_TOKENS},
                                                                        {UL_ESCAPED_STATE, &ESCAPED_STATE_TOKENS},
                                                                        {UL_COMMENT_STATE, &COMMENT_STATE_TOKENS},
                                                                        {UL_SINGLE_QUOTED_STATE, &SINGLE_QUOTED_STATE_TOKENS},
                                                                        {UL_DOUBLE_QUOTED_STATE, &DOUBLE_QUOTED_STATE_TOKENS},
                                                                        {UL_INCLUDING_STATE, &INCLUDING_STATE_TOKENS},
                                                                        {UL_IF_BLOCK_STATE, &IF_BLOCK_STATE_TOKENS},
                                                                        {UL_IF_CONDITION_STATE, &IF_CONDITION_STATE_TOKENS}};

/**
 * @brief class lexer (singleton)
 */
class lexer final
{
public:
    // singleton implementation
    static lexer &instance()
    {
        static lexer s;
        return s;
    } // instance

    lexer(const lexer &) = delete;
    lexer &operator=(const lexer &) = delete;

private:
    lexer() {}
    ~lexer() {}

    // singleton public interface
public:
    /**
     * @name   init
     * @brief  initialize state
     * @return bool
     */
    void init(const string &config_file, const string &input_file, const string &output_file);

    /**
     * @name push
     * @brief  push dir on stack
     */
    void push(const string &input_file);

    /**
     * @name pop
     * @brief pop dir off stack
     */
    void pop();

    /**
     * @name   load_config
     * @def    void load_config( const string &file )
     * @brief  load_config: load configuration from file
     * @param  const string& file
     * @return void
     */
    static void load_config(const string &file);

    /**
     * @name   dump_config
     * @brief  void dump_config( const string& file ) const
     * @param  const string& file
     * @return void
     */
    void dump_config(const string &file) const;

    /**
     * @name   dump_config
     * @def    void dump_config( ) const
     * @brief  dump current config
     * @return void
     */
    void dump_config() const;

    /**
     * @name   get_state
     * @brief  state_t *get_state() const
     * @return state_t
     */
    static state_t *get_state();

    /**
     * @name   set_state
     * @brief  void set_state(state_t* pstate)
     * @return void
     */
    void set_state(const state_t &state);

    /**
     * @name   get_remaining
     * @brief  get remaining input
     * @param  string& s
     * @return void
     */
    inline string *get_remaining()
    {
        return &m_suffix;
    }

    /**
     * @name   set_remaining
     * @brief  set remaining input
     * @param  const string& s
     * @return void
     */
    inline void set_remaining(const string &s)
    {
        m_suffix.clear();
        m_suffix = s;
    }

    /**
     * @name   get_include_buffer
     * @brief  get remaining input
     * @return stringstream*
     */
    inline stringstream *get_include_buffer()
    {
        m_include_buffer.clear();
        return &m_include_buffer;
    }

    /**
     * @name   get_token
     * @def    parser::symbol_type get_token()
     * @return int
     */
    parser::symbol_type get_token();

    /**
     *
     * @return
     */
    static token_match* get_match();

    /**
     * @name   get_expr
     * @def    const string& get_expr() const
     * @brief  get regex expression
     * @return const string&
     */
    const string &get_expr() const;

    /**
     * @name build_expr
     * @def  void build_expr()
     */
    void build_expr();

    /**
     * @name  print_token
     * @def   void lexer::print_token(token_match m)
     * @brief print token to stdout
     * @param token_match m
     */
    static void print_token(const token_match *ptoken);

    /**
     * @name   is_id
     * @def    bool is_id( const token_def& token, const int& id )
     * @param  const token_def& token
     * @param  const unsigned long& id
     * @return bool
     */
    static bool is_id(const token_def &token, const unsigned long &id);

    /**
     * @name  set_context
     * @def   set_context(string& current_input)
     * @param string& current_input
     * @return void
     */
    void set_context(const string &current_input);

    /**
     * @name   on_state
     * @param  state_t* pstate
     * @return bool
     */
    static inline unsigned long on_state(state_t *pstate);

    /**
     * @name  on_token
     * @brief override virtual, on_token, for each token ...
     * @param token_def* token
     */
    inline parser::symbol_type on_token(const token_match *ptoken);

    /**
     * @name   write_stream
     * @def    parser::symbol_type get_token()
     * @return int
     */
    inline void write_stream(const string &s)
    {
        m_stream << s;
    }

    inline ofstream &operator<<(string &s)
    {
        m_stream << s;
        return m_stream;
    }

protected:
    // current context
    string m_text;
    boost::regex m_rexp;
    boost::sregex_iterator m_begin;
    boost::sregex_iterator m_end;
    boost::sregex_iterator *m_piter;
    // int                                         m_pos;
    // int                                         m_len;
    string m_expr;
    string m_match;
    string m_prefix;
    string m_suffix;

    stringstream m_sout;
    ofstream m_stream;
    ofstream m_debug1_stream;
    ofstream m_debug2_stream;

    string m_include_path;
    string m_buffer;
    stringstream m_include_buffer;
    // context_t                                 m_context;
    std::stack<string> filestack;
    //std::stack<file_ptr *> file_ptrs;
    int m_line;

    vector<token_match> g_matches;
};

#endif
