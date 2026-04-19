/**
 * @file    lexer.hpp
 * @version 0.0.1
 * @date    Fri, 26 Sep 2025 17:05:10
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
using std::ofstream;
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
const string qwerty = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcefghijklmnopqrstuvwxyz1234567890~!@#$%^&*()_+{}|:\"<>?`-=[]\\;',./'";

// groups
const string BUILTIN_FUNCTION = "(insert)|(include)|(config_load)|(assign)|(fetch)|(capture)";
const string MATH = "(abs)|(ceil)|(cos)|(exp)|(floor)|(log)|(log10)|(max)|(min)|(pi)|(pow)|(rand)|(round)|(sin)|(sqrt)|(srans)|(tan)";
const string KEY_WORDS = "(if)|(else)|(elseif)|(foreach)|(foreachelse)|(literal)|(section)|(strip)|(assign)|(counter)|(cycle)|(debug)|(eval)|(fetch)|(html_checkboxes)";
const string VAR_MODIFIER = "(capitalize)|(indent)|(lower)|(upper)|(spacify)|(string_format)|(truncate)|(date_format)|(escape)";

#ifdef BOOST_CLASSESnamespace
{
    template <class charT, class traits = regex_traits<charT>>
    class basic_regex;
    typedef basic_regex<char>
        regex;
    typedef basic_regex<wchar_t>
        wregex;
}
#endif

#ifdef BOOST_CLASSES
namespace boost
{
    template <class
              charT,
              class traits = regex_traits<charT>>
    class basic_regex
    {
    public:
        // types:
        typedef charT
            value_type;
        typedef implementation - specific
                                     const_iterator;
        typedef const_iterator
            iterator;
        typedef charT &
            reference;
        typedef const charT &
            const_reference;
        typedef std::ptrdiff_t
            difference_type;
        typedef std::size_t
            size_type;
        typedef regex_constants::syntax_option_type
            flag_type;
        typedef typename traits::locale_type
            locale_type;
        // constants:
        // main option selection:
        static const regex_constants::syntax_option_type normal = regex_constants::normal;
        static const regex_constants::syntax_option_type ECMAScript = normal;
        static const regex_constants::syntax_option_type JavaScript = normal;
        static const regex_constants::syntax_option_type JScript = normal;
        static const regex_constants::syntax_option_type basic = regex_constants::basic;
        static const regex_constants::syntax_option_type extended = regex_constants::extended;
        static const regex_constants::syntax_option_type awk = regex_constants::awk;
        static const regex_constants::syntax_option_type grep = regex_constants::grep;
        static const regex_constants::syntax_option_type egrep = regex_constants::egrep;
        static const regex_constants::syntax_option_type sed = basic = regex_constants::sed;
        static const regex_constants::syntax_option_type perl = regex_constants::perl;
        static const regex_constants::syntax_option_type literal = regex_constants::literal;
        // modifiers specific to perl expressions:
        static const regex_constants::syntax_option_type no_mod_m = regex_constants::no_mod_m;
        static const regex_constants::syntax_option_type no_mod_s = regex_constants::no_mod_s;
        static const regex_constants::syntax_option_type mod_s = regex_constants::mod_s;
        static const regex_constants::syntax_option_type mod_x = regex_constants::mod_x;
        // modifiers specific to POSIX basic expressions:
        static const regex_constants::syntax_option_type bk_plus_qm = regex_constants::bk_plus_qm;
        static const regex_constants::syntax_option_type bk_vbar = regex_constants::bk_vbar static const regex_constants::syntax_option_type no_char_classes = regex_constants::no_char_classes static const regex_constants::syntax_option_type no_intervals = regex_constants::no_intervals
            // common modifiers:
            static const regex_constants::syntax_option_type nosubs = regex_constants::nosubs;
        static const regex_constants::syntax_option_type optimize = regex_constants::optimize;
        static const regex_constants::syntax_option_type collate = regex_constants::collate;
        static const regex_constants::syntax_option_type newline_alt = regex_constants::newline_alt;
        static const regex_constants::syntax_option_type no_except = regex_constants::newline_alt;
        // construct/copy/destroy:
        explicit basic_regex();
        explicit basic_regex(const charT *p, flag_type f = regex_constants::normal);
        basic_regex(const charT *p1, const charT *p2,
                    flag_type f = regex_constants::normal);
        basic_regex(const charT *p, size_type len, flag_type f);
        basic_regex(const basic_regex &);
        template <class ST, class SA>
        explicit basic_regex(const basic_string<charT, ST,
                                                SA> &p,
                             flag_type f = regex_constants::normal);
        template <class InputIterator>
        basic_regex(InputIterator first,
                    InputIterator last,
                    flag_type f = regex_constants::normal);
        ~basic_regex();
        basic_regex &operator=(const basic_regex &);
        basic_regex &operator=(const charT *ptr);
        template <class ST, class SA>
        basic_regex &operator=(const basic_string<charT, ST, SA> &p);
        // iterators:
        std::pair<const_iterator, const_iterator> subexpression(size_type n) const;
        const_iterator begin() const;
        const_iterator end() const;
        // capacity:
        size_type size() const;
        size_type max_size() const;
        bool empty() const;
        size_type mark_count() const;
        //
        // modifiers:
        basic_regex &assign(const basic_regex &that);
        basic_regex &assign(const charT *ptr,
                            flag_type f = regex_constants::normal);
        basic_regex &assign(const charT *ptr, unsigned int len, flag_type f);
        template <class string_traits, class A>
        basic_regex &assign(const basic_string<charT, string_traits, A> &s,
                            flag_type f = regex_constants::normal);
        template <class InputIterator>
        basic_regex &assign(InputIterator first, InputIterator last,
                            flag_type f = regex_constants::normal);
        // const operations:
        flag_type flags() const;
        int status() const;
        basic_string<charT> str() const;
        int compare(basic_regex &) const;
        // locale:
        locale_type imbue(locale_type loc);
        locale_type getloc() const;
        // swap
        void swap(basic_regex &) throw();
    };
    template <class charT, class traits>
    bool operator==(const basic_regex<charT, traits> &lhs,
                    const basic_regex<charT, traits> &rhs);
    template <class charT, class traits>
    bool operator!=(const basic_regex<charT, traits> &lhs,
                    const basic_regex<charT, traits> &rhs);
    template <class charT, class traits>
    bool operator<(const basic_regex<charT, traits> &lhs,
                   const basic_regex<charT, traits> &rhs);
    template <class charT, class traits>
    bool operator<=(const basic_regex<charT, traits> &lhs,
                    const basic_regex<charT, traits> &rhs);
    template <class charT, class traits>
    bool operator>=(const basic_regex<charT, traits> &lhs,
                    const basic_regex<charT, traits> &rhs);
    template <class charT, class traits>
    bool operator>(const basic_regex<charT, traits> &lhs,
                   const basic_regex<charT, traits> &rhs);
    template <class charT, class io_traits, class re_traits>
    basic_ostream<charT, io_traits> &
    operator<<(basic_ostream<charT, io_traits> &os,
               const basic_regex<charT, re_traits> &e);
    template <class charT, class traits>
    void swap(basic_regex<charT, traits> &e1,
              basic_regex<charT, traits> &e2);
    typedef basic_regex<char> regex;
    typedef basic_regex<wchar_t> wregex;
#endif

#ifdef BOOST_OPTION
    namespace boost
    {
        namespace regex_constants
        {
            typedef implementation - specific - bitmask - type syntax_option_type;
            // these flags are standardized:
            static const syntax_option_type normal;
            static const syntax_option_type ECMAScript = normal;
            static const syntax_option_type JavaScript = normal;
            static const syntax_option_type JScript = normal;
            static const syntax_option_type perl = normal;
            static const syntax_option_type basic;
            static const syntax_option_type sed = basic;
            static const syntax_option_type extended;
            static const syntax_option_type awk;
            static const syntax_option_type grep;
            static const syntax_option_type egrep;
            static const syntax_option_type icase;
            static const syntax_option_type nosubs;
            static const syntax_option_type optimize;
            static const syntax_option_type collate;
            //
            // The remaining options are specific to Boost.Regex:
            //
            // Options common to both Perl and POSIX regular expressions:
            static const syntax_option_type newline_alt;
            static const syntax_option_type no_except;
            static const syntax_option_type
                save_subexpression_location;
            // Perl specific options:
            static const syntax_option_type no_mod_m;
            static const syntax_option_type no_mod_s;
            static const syntax_option_type mod_s;
            static const syntax_option_type mod_x;
            static const syntax_option_type no_empty_expressions;
            // POSIX extended specific options:
            static const syntax_option_type no_escape_in_lists;
            static const syntax_option_type no_bk_refs;
            // POSIX basic specific options:
            static const syntax_option_type no_escape_in_lists;
            static const syntax_option_type no_char_classes;
            static const syntax_option_type no_intervals;
            static const syntax_option_type bk_plus_qm;
            static const syntax_option_type bk_vbar;

            typedef implemenation - specific - bitmask - type match_flag_type;
            static const match_flag_type match_default = 0;
            static const match_flag_type match_not_bob;
            static const match_flag_type match_not_eob;
            static const match_flag_type match_not_bol;
            static const match_flag_type match_not_eol;
            static const match_flag_type match_not_bow;
            static const match_flag_type match_not_eow;
            static const match_flag_type match_any;
            static const match_flag_type match_not_null;
            static const match_flag_type match_continuous;
            static const match_flag_type match_partial;
            static const match_flag_type match_single_line;
            static const match_flag_type match_prev_avail;
            static const match_flag_type match_not_dot_newline;
            static const match_flag_type match_not_dot_null;
            static const match_flag_type match_posix;
            static const match_flag_type match_perl;
            static const match_flag_type match_nosubs;
            static const match_flag_type match_extra;
            static const match_flag_type format_default = 0;
            static const match_flag_type format_sed;
            static const match_flag_type format_perl;
            static const match_flag_type format_literal;
            static const match_flag_type format_no_copy;
            static const match_flag_type format_first_only;
            static const match_flag_type format_all;
        } // namespace regex_constants
    } // namespace boost
#endif

    typedef struct token_t
    {
        string name;
        string stype;
        string rexp;
        unsigned long index;
    } token_t;

    // typedef struct token_value_t
    // {
    //     unsigned long id;
    //     string match;
    //     string prefix;
    //     string suffix;
    //     string file;
    //     int line;
    //     long pos;
    //     token_t *def;
    // } token_value_t;

    typedef struct state_t
    {
        unsigned long id;
        string name;
    } state_t;

    // class file_context
    // {
    //     string name;
    //     string *parent;
    //     char *text;
    // };

    typedef token_t token;
    typedef parser::token_type yytoken;
    typedef parser::symbol_type yysymbol;
    inline auto SKIP_TOKEN = yysymbol(yytoken::SKIP_TOKEN).kind();

#define R_TILDE R"(~)"
#define R_EXCLAMATION R"(!)"

// static context *g_context;
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

    /**
     * @name g_tokens_all
     * @brief global token vector - all tokens
     */
    inline map<unsigned long, token> g_tokens = {
        {UNESCAPED_TEXT, token{"UNESCAPED_TEXT", S_TYPE, R"([^{]+)", __LINE__}},
        {WHITESPACE, token{"WHITESPACE", S_TYPE, R"([ \t])", __LINE__}},
        {NEWLINE, token{"NEWLINE", S_TYPE, R"(\n)", __LINE__}},
        {FILE_ATTRIB, token{"FILE_ATTRIB", S_TYPE, R"(file)", __LINE__}},
        {VALID_CHAR, token{"VALID_CHAR", S_TYPE, R"([A-Za-z0-9*@_~+-./ ])", __LINE__}},
        {NUMERIC_LITERAL, token{"NUMERIC_LITERAL", S_TYPE, R"([0-9]+)", __LINE__}},
        {CAPITALIZE, token{"CAPITALIZE", S_TYPE, R"(capitalize)", __LINE__}},
        {STRING_LITERAL, token{"STRING_LITERAL", S_TYPE, R"("[A-Za-z0-9*@_.~+-/ ]+")", __LINE__}},
        {ARRAY, token{"ARRAY", S_TYPE, R"([A-Za-z*@_~+-][A-Za-z0-9*@_~+-]*\[[^\]]\])", __LINE__}},
        {SYMBOL, token{"SYMBOL", S_TYPE, R"(\$[A-Za-z*@_.~+-][A-Za-z0-9*@_.~+-]*)", __LINE__}},
        {CONST_SYMBOL, token{"CONST_SYMBOL", S_TYPE, R"(#[A-Za-z*@_.~+-][A-Za-z0-9*@_.~+-]*#)", __LINE__}},
        {IDENTIFIER, token{"IDENTIFIER", S_TYPE, R"([A-Za-z*@_.~+-][A-Za-z0-9*@_.~+-]*)", __LINE__}},
        {COMMENT, token{"COMMENT", S_TYPE, R"(\{[ ]*\*[^*}]*\*[ ]*\})", __LINE__}},
        {VAR_ATTRIB, token{"VAR_ATTRIB", S_TYPE, R"(var='[^']*')", __LINE__}},
        {VALUE_ATTRIB, token{"VALUE_ATTRIB", S_TYPE, R"(value='[^']*')", __LINE__}},
        {FROM_ATTRIB, token{"FROM_ATTRIB", S_TYPE, R"(from='[^']*')", __LINE__}},
        {ITEM_ATTRIB, token{"ITEM_ATTRIB", S_TYPE, R"(item='[^']*')", __LINE__}},
        {KEY_ATTRIB, token{"KEY_ATTRIB", S_TYPE, R"(key='[^']*')", __LINE__}},
        {NAME_ATTRIB, token{"NAME_ATTRIB", S_TYPE, R"(name='[^']*")", __LINE__}},
        {DOUBLE_QUOTE, token{"DOUBLE_QUOTE", S_TYPE, R"(")", __LINE__}},
        {TILDE, token{"TILDE", S_TYPE, R"(~)", __LINE__}},
        {EXCLAMATION, token{"EXCLAMATION", S_TYPE, R"(!)", __LINE__}},
        {AT_SYMBOL, token{"AT_SYMBOL", S_TYPE, R"(@)", __LINE__}},
        {TIC_MARK, token{"TIC_MARK", S_TYPE, R"(`)", __LINE__}},
        {CARROT, token{"CARROT", S_TYPE, R"(\^)", __LINE__}},
        {AMPERSAND, token{"AMPERSAND", S_TYPE, R"(&)", __LINE__}},
        {ASTERISK, token{"ASTERISK", S_TYPE, R"(\*)", __LINE__}},
        {OPEN_PAREN, token{"LPAREN", S_TYPE, R"(\()", __LINE__}},
        {CLOSE_PAREN, token{"RPAREN", S_TYPE, R"(\))", __LINE__}},
        {DASH, token{"MINUS", S_TYPE, R"(-)", __LINE__}},
        {PLUS_SIGN, token{"PLUS", S_TYPE, R"(\+)", __LINE__}},
        {EQUAL_SIGN, token{"EQUAL_SIGN", S_TYPE, R"(=)", __LINE__}},
        {CLOSE_BRACKET, token{"RBRACKET", S_TYPE, R"(\])", __LINE__}},
        {OPEN_BRACE, token{"OPEN_BRACE", S_TYPE, R"(\{)", __LINE__}},
        {CLOSE_BRACE, token{"CLOSE_BRACE", S_TYPE, R"(\})", __LINE__}},
        {OPEN_BRACKET, token{"LBRACKET", S_TYPE, R"(\[)", __LINE__}},
        {VBAR, token{"VBAR", S_TYPE, R"(\|)", __LINE__}},
        {BACKSLASH, token{"BACKSLASH", S_TYPE, R"(\\)", __LINE__}},
        {COLON, token{"COLON", S_TYPE, R"(:)", __LINE__}},
        {SEMI_COLON, token{"SEMI_COLON", S_TYPE, R"(;)", __LINE__}},
        {SINGLE_QUOTE, token{"SINGLE_QUOTE", S_TYPE, R"(')", __LINE__}},
        {GREATER_THAN, token{"GREATER_THAN", S_TYPE, R"(>)", __LINE__}},
        {QUESTION_MARK, token{"QUESTION_MARK", S_TYPE, R"(\?)", __LINE__}},
        {COMMA, token{"COMMA", S_TYPE, R"(\,)", __LINE__}},
        {DOT, token{"DOT", S_TYPE, R"(\.)", __LINE__}},
        {SLASH, token{"SLASH", S_TYPE, R"(/)", __LINE__}},
        {GREATER_THAN_EQUAL, token{"GREATER_THAN_EQUAL", S_TYPE, R"(>=)", __LINE__}},
        {LESS_THAN_EQUAL, token{"LESS_THAN_EQUAL", S_TYPE, R"(<=)", __LINE__}},
        {IF, token{"IF", S_TYPE, R"(if)", __LINE__}},
        {ELSEIF, token{"ELSEIF", S_TYPE, R"(elseif)", __LINE__}},
        {WHILE, token{"WHILE", S_TYPE, R"(while)", __LINE__}},
        {ASSIGN, token{"ASSIGN", S_TYPE, R"(assign)", __LINE__}},
        {BREAK, token{"BREAK", S_TYPE, R"(break)", __LINE__}},
        {REQUIRE, token{"REQUIRE", S_TYPE, R"(require)", __LINE__}},
        {INCLUDE, token{"INCLUDE", S_TYPE, R"(include)", __LINE__}},
        {CONFIG_LOAD, token{"CONFIG_LOAD", S_TYPE, R"(config_load)", __LINE__}},
        {INSERT, token{"INSERT", S_TYPE, R"(insert)", __LINE__}},
        {COUNT_PARAGRAPHS, token{"COUNT_PARAGRAPHS", S_TYPE, R"(count_paragraphs)", __LINE__}},
        {COUNT_SENTENCES, token{"COUNT_SENTENCES", S_TYPE, R"(count_sentences)", __LINE__}},
        {COUNT_WORDS, token{"COUNT_WORDS", S_TYPE, R"(count_words)", __LINE__}},
        {DATE_FORMAT, token{"DATE_FORMAT", S_TYPE, R"(date_format)", __LINE__}},
        {NULL, token{"DEFAULT", S_TYPE, R"(default)", __LINE__}},
        {ESCAPE, token{"ESCAPE", S_TYPE, R"(escape)", __LINE__}},
        {INDENT, token{"INDENT", S_TYPE, R"(indent)", __LINE__}},
        {LOWER, token{"LOWER", S_TYPE, R"(lower)", __LINE__}},
        {UPPER, token{"UPPER", S_TYPE, R"(upper)", __LINE__}},
        {STRIP, token{"STRIP", S_TYPE, R"(strip)", __LINE__}},
        {NL2BR, token{"NL2BR", S_TYPE, R"(nl2br)", __LINE__}},
        {REGX_REPLACE, token{"REGX_REPLACE", S_TYPE, R"(regx_replace)", __LINE__}},
        {REPLACE, token{"REPLACE", S_TYPE, R"(replace)", __LINE__}},
        {SPACIFY, token{"SPACIFY", S_TYPE, R"(spacify)", __LINE__}},
        {STRING_FORMAT, token{"STRING_FORMAT", S_TYPE, R"(string_format)", __LINE__}},
        {STRIP_TAGS, token{"STRIP_TAGS", S_TYPE, R"(strip_tags)", __LINE__}},
        {WORDWRAP, token{"WORDWRAP", S_TYPE, R"(wordwrap)", __LINE__}},
        {TRUNCATE, token{"TRUNCATE", S_TYPE, R"(truncate)", __LINE__}},
		{UNDEFINED, token{"UNDEFINED", S_TYPE, R"(.)", __LINE__}},
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
    inline vector<unsigned long> state_ids = {UL_INITIAL, UL_COMMENTING, UL_ESCAPED, UL_DOUBLE_QUOTED, UL_SINGLE_QUOTED, UL_INCLUDING, UL_IF_BLOCK, UL_IF_CONDITION};

    /**
     * @brief state_t states
     */

    inline state_t INITIAL = {UL_INITIAL, "INITIAL"};
    inline state_t COMMENTING = {UL_COMMENTING, "COMMENT"};
    inline state_t ESCAPED = {UL_ESCAPED, "ESCAPED"};
    inline state_t DOUBLE_QUOTED = {UL_DOUBLE_QUOTED, "DOUBLE_QUOTED"};
    inline state_t SINGLE_QUOTED = {UL_SINGLE_QUOTED, "SINGLE_QUOTED"};
    inline state_t INCLUDING = {UL_INCLUDING, "INCLUDING"};
    inline state_t IF_BLOCK = {UL_IF_BLOCK, "IF_BLOCK"};
    inline state_t IF_CONDITION = {UL_IF_CONDITION, "IF_CONDITION"};
	inline state_t& UNESCAPED = INITIAL;

    /**
     * @brief global state vector
     */
    inline vector<state_t> states__ = {INITIAL, COMMENTING, ESCAPED, DOUBLE_QUOTED, SINGLE_QUOTED, INCLUDING, IF_BLOCK, IF_CONDITION};

    /**
     * @brief token list -> by state
     */
	inline vector<unsigned long> INITIAL_TOKENS = { OPEN_BRACE, NEWLINE };

    inline vector<unsigned long> ESCAPED_TOKENS = { CLOSE_BRACE, DOUBLE_QUOTE, FILE_ATTRIB, INCLUDE, ASSIGN, NUMERIC_LITERAL, EQUAL_SIGN,
                                                   CAPITALIZE, TRUNCATE, VBAR, COLON, STRIP, SYMBOL, CONST_SYMBOL, WHITESPACE, VALID_CHAR };

    inline vector<unsigned long> COMMENTING_TOKENS = {OPEN_BRACE, COMMENT, ANYTHING};
    inline vector<unsigned long> DOUBLE_QUOTED_TOKENS = {DOUBLE_QUOTE, VALID_CHAR};
    inline vector<unsigned long> SINGLE_QUOTED_TOKENS = {OPEN_BRACE, COMMENT, VALID_CHAR, SINGLE_QUOTE, DOUBLE_QUOTE};
    inline vector<unsigned long> INCLUDING_TOKENS = {FILE_ATTRIB};
    inline vector<unsigned long> IF_BLOCK_TOKENS = {CLOSE_BRACE};
    inline vector<unsigned long> IF_CONDITION_TOKENS = {CLOSE_BRACE};

    /**
     * @brief global state: state_id -> states
     * @name g_tokens_by_state_id
     */
    inline map<unsigned long, vector<unsigned long> *> g_state_tokens{{UL_INITIAL, &INITIAL_TOKENS},
                                                                      {UL_ESCAPED, &ESCAPED_TOKENS},
                                                                      {UL_COMMENTING, &COMMENTING_TOKENS},
                                                                      {UL_SINGLE_QUOTED, &SINGLE_QUOTED_TOKENS},
                                                                      {UL_DOUBLE_QUOTED, &DOUBLE_QUOTED_TOKENS},
                                                                      {UL_INCLUDING, &INCLUDING_TOKENS},
                                                                      {UL_IF_BLOCK, &IF_BLOCK_TOKENS},
                                                                      {UL_IF_CONDITION, &IF_CONDITION_TOKENS}};
	/**
	 *
	 */
	typedef unsigned long type_t;
	typedef unsigned long terminal_t;
	typedef vector<terminal_t> terminals_t;
	typedef vector<type_t> types_t;
	typedef vector<unsigned long> rules_t;
	typedef vector<type_t> rules_t;
	typedef vector<type_t> squence_t;
	typedef vector<squence_t> squences_t;
	typedef map < type_t, squences_t > maps;

	#define PROGRAM 1ul
	// #define FILES 2ul
	// #define FILE 3ul
	// #define BLOCKS 4ul
	// #define BLOCK 5ul

	//type_t type { PROGRAM, FILES, FILE, BLOCKS, BLOCK }
	//maps g_map { type_t{PROGRAM}, squences_t{ squence_t{ PROGRAM, FILES } } }

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
        }

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
        void init(string in, string out);

        /**
         * @name   set_state
         * @brief  void set_state(state_t* pstate)
         * @return void
         */
        void set_state_flag(state_t *pstate);

        /**
         * @name include_file
         */
        void include_file(const string &input_file);

        /**
         * @name   load_config
         * @param  const string& file
         * @return void
         */
        void load_config(const string &file);

		/**
		 * @name set_buffer
		 */
		void set_buffer( const string& buffer );

        /**
         * @name   get_token
         * @return int
         */
        parser::symbol_type get_token();

        /**
         * @name  on_token
         * @brief override virtual, on_token, for each token ...
         * @param token_def* token
         */
        inline parser::symbol_type on_token(unsigned long id);

        /**
         * @name   write_stream
         * @return int
         */
        inline void write_stream(const string &s)
        {
            m_stream << s;
        }

        // Declaring friend functions for private member access
        friend std::ostream &operator<<(std::ostream &os, const string &s);
        friend std::istream &operator>>(std::istream &is, string &s);

    private:
        /**
         * @name   update_state
         * @brief  void update_state()
         * @return void
         */
        void update_state();

        /**
         * @name print_line_count
         */
        void print_line_count(const string &s);

        /**
         * @name print_line_number_comment
         */
        void print_line_number_comment();

        // /**
        //  * @name  print_token
        //  * @brief print token to stdout
        //  * @param token_match m
        //  */
        void print_token(const token *tval);

    private:
        vector<token_t> m_tokens;
        map<unsigned long, token> m_tok_map;
        vector<state_t> m_states;

		typedef struct context_t
		{
			string regex_str;
			string search;
			string match;
			string prefix;
			string suffix;
			long pos;

			string buffer;
			boost::regex rexp;
			boost::sregex_iterator iter;
			boost::sregex_iterator end;
			boost::smatch* p_smatch;

		} context_t;

		context_t* p_context;

		string m_regex_str;
        string m_match;
        string m_prefix;
        string m_suffix;
        long m_pos;

        string m_buffer;
        boost::regex m_rexp;
		boost::sregex_iterator m_iter = boost::sregex_iterator();
		boost::sregex_iterator m_end = boost::sregex_iterator();
        boost::smatch *p_smatch;

        /**
         * @biref output stream
         */
        ofstream m_stream;
        int m_line;

        state_t *p_state = &INITIAL;

        /**
         *@ brief stream for quoted strings
         * @name m_sstring
         */
        stringstream m_sstring;
    };

#endif
