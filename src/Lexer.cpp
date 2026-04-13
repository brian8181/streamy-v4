
/**
 * @file    lexer.cpp
 * @version 0.0.1
 * @date    Fri, 26 Sep 2025 17:05:10 +0000
 */

#define _GNU_SOURCE
#include <iostream>
#include <iomanip>
#include <map>
#include <regex>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <boost/regex.hpp>
#include <fmt/core.h>
#include <fmt/format.h>
#include "log.hpp"
#include "fileio.hpp"
#include "lexer.hpp"
#include "driver.hpp"
#include "utility.hpp"

using std::cerr;
using std::cout;
using std::endl;
using std::left;
using std::map;
using std::pair;
using std::right;
using std::setw;
using std::string;
using std::vector;
using yy::parser;

/**
 * @name   load_config
 * @def    void lexer::load_config( const string &file )
 * @brief  load_config: load configuration from file
 * @param file
 * @param  const string& file
 * @return void
 */
void lexer::load_config(const string &file)
{
    g_config_file = file;
    string section = "none";
    string s;
    read_str(g_config_file, s);
    auto rgx = boost::regex(CONFIG_SECTIONS);
    boost::smatch terminal_match;
    // begins terminal section
    boost::regex_search(s, terminal_match, rgx, boost::match_not_bol | boost::match_not_eol);
    boost::smatch groups_match;
    // ends terminal section, begin group section
    string terminal_suffix = terminal_match.suffix();
    boost::regex_search(terminal_suffix, groups_match, rgx, boost::match_not_bol | boost::match_not_eol);
    // now get section
    string token_section = groups_match.prefix();

    // stream & parse tokens section
    std::istringstream input1;
    input1.str(token_section);
    unsigned long j = 0;
    for (std::string line; std::getline(input1, line); j++)
    {
        auto config_rgx = boost::regex(CONFIG);
        boost::smatch token_match;
        boost::regex_match(line, token_match, config_rgx);
        if (constexpr unsigned int ID_PAIR = 1; token_match[ID_PAIR].matched)
        {
            string name = token_match["name"].str();
            string expr = token_match["rexp"].str();
            string stype = token_match["type"].str();
            string test_val = token_match["test"].str();

            auto *ptoken = new token_t{
                string(name),
                stype,
                string(expr),
            };
            // copy to term to vector
            // m_tokens.push_back(ptoken);
            // m_id_tab[m_id] = ptoken;
            // m_name_tab[m_name] = ptoken;
        }
    }
    // ends group section, begin states section
    string groups_suffix = groups_match.suffix();
    boost::smatch states_match;
    boost::regex_search(groups_suffix, states_match, rgx, boost::match_not_bol | boost::match_not_eol);
    string groups_section = states_match.prefix();
    string states_section = states_match.suffix();

    // stream & parse tokens section
    std::istringstream input2;
    input2.str(states_section);
    for (std::string line; std::getline(input2, line);)
    {
        auto config_states_rgx = boost::regex(CONFIG_STATES);
        boost::regex_match(line, states_match, config_states_rgx);
        if (states_match["states"].matched)
        {
            string str_state = states_match["state"].str();   // new state to create
            string str_tokens = states_match["tokens"].str(); // csv tokens for that state
            unsigned long i = 0ul;
            unsigned long state_id = 0xFFul | (++i * 6ul);   // generate id for new state
            auto *pstate = new state_t{state_id, str_state}; // create new state
            // m_pstates->push_back(pstate);
            //(*m_pstate_tab)[pstate->id] = pstate; // insert new state into table

            // copy to term to vector
            vector<token_t> tokens;           // token vector for this state
            std::stringstream ss(str_tokens); // csv of states
            std::string str_token;            // item in csv states

            // use get line to split on commas
            while (std::getline(ss, str_token, ','))
            {
                token_t *ptoken;
                // m_def.tokens::push_back(*ptoken);
                //_state_tokens_tab[pstate->id] = tokens;
            }
        }
    }
}

/**
 * @brief global state_t state
 * @name  gp_state
 */
// inline state_t *g_pstate = &INITIAL;

/**
 * @name   init
 * @def    void lexer::init(const string &config_file, const string& input_file, string& output_file)
 * @brief  initialize state
 * @return bool
 */
void lexer::init(string in, string out)
{
    TRACE;
    read_str(in, m_search, std::ios::in);
    m_buffer = m_search;
    // set state
    set_state_flag(&INITIAL);
    update_state();
    m_stream.open(out, std::ios_base::out | std::ios::trunc);
    m_line = 0;

    WARN("remaining[ \"" << *escape_newlines(m_buffer) << "\" ]");
}

/**
 * @name   set_state_flag
 * @brief  void lexer::set_state_flag(state_t* pstate)
 * @return void
 */
void lexer::set_state_flag(state_t *pstate)
{
    ERROR("Enter set_state_flag ~ _pstate->id:" << _pstate->id << " ~ _pstate->name:" << _pstate->name);
    ERROR("set_state_flag ~ new state id:" << pstate->id << " ~ name:" << pstate->name);
    TRACE;
    _pstate = pstate;

    // bkp todo: deferred update of regex until after on_token event, since it will invalidate iterators,
    // and on_token may want to call get_token recursively, which will need the
    // current regex to be valid until after on_token returns
    // update_state();
}

void lexer::update_state()
{
    stringstream ss;
    const vector<unsigned long> *STATE_TOKENS = g_tokens_by_state_id[_pstate->id];
    const unsigned long len = STATE_TOKENS->size();

    for (unsigned long i = 0; i < len; i++)
    {
        unsigned long id = (*STATE_TOKENS)[i];
        token_t *ptoken = &g_tokens[id];
        // ss << "(?<" << ptoken->name << ">)" << ptoken->rexp << ")|";
        ss << "(" << ptoken->rexp << ")|";
    }

    string rexp_str = ss.str();
    rexp_str.pop_back(); // remove extra '|' i.e. "V-BAR"
    // set context
    m_rexp = boost::regex(rexp_str, boost::regex::extended);
    m_iter = boost::sregex_iterator(m_buffer.begin(), m_buffer.end(), m_rexp);
    m_end = boost::sregex_iterator();

    ERROR("Exit set_state ~ _pstate->id:" << _pstate->id << " ~ _pstate->name:" << _pstate->name);
    INFO("EXPR=\"" << rexp_str << "\"");
}

void lexer::include_file(const string &input_file)
{
    // just read new, (include), file and prepend to remaining text
    string s;
    read_str(input_file, s);
    m_buffer = s + m_buffer; // prepend new text to remaining text
    set_state_flag(&INITIAL);
}

/**
 * @name   get_token
 * @def    parser::symbol_type lexer::get_token()
 * @return int
 */
parser::symbol_type lexer::get_token()
{
    if (m_iter != m_end)
    {
        TRACE;
        p_smatch = new boost::smatch(*m_iter);
        boost::smatch m = *p_smatch;
        const size_t len = p_smatch->size();
        m_match = p_smatch->str();
        m_prefix = p_smatch->prefix().str();
        m_suffix = p_smatch->suffix().str();
        m_buffer = m_suffix;
        long m_pos = p_smatch->position();

        for (int i = 1; i < len; ++i)
        {
            if (m[i].matched)
            {
                if (p_smatch->prefix().matched)
                {
                    if (_pstate->id != UL_INITIAL)
                    {
                        INFO("error: unexpected token ... \"" << m_prefix << "\"");
                        return parser::make_YYerror();
                    }
                    m_stream << m_prefix; // stream prefix (unescaped text)
                }

                // get id by index value "i-1" zero based vector
                unsigned long id = (*g_tokens_by_state_id[_pstate->id])[i - 1];
                // create token_t, find match & lookup by sub_match index
                token_t token = g_tokens[id];
                // token_value_t *tval = new token_value_t{id, m_match, m_prefix, m_suffix, "", m_line, pos, &token};

                INFO("match.sz:" << m_match.size() << " - match.pos:" << m_pos << " - prefix.sz:" << m_prefix.size() << " - suffix.sz:" << m_suffix.size());

                ERROR("match[ " << "i=" << i << " ] = " << token.name << "[ \"" << *escape_newlines(m_match) << "\" ]");
                WARN("remaining[ \"" << *escape_newlines(m_buffer) << "\" ]");

                auto yytok = on_token(id);
                // begin state change
                if (yytok.kind() != SKIP_TOKEN)
                {
                    update_state();
                    return yytok;
                }
                // skipping
                ++m_iter;
                return get_token();
            }
        }
    }
    else
    {
        TRACE;
        m_stream << m_buffer;
        m_stream.flush();
        m_stream.close();
        return parser::make_END(); // error or eof
    }
    return parser::make_END_OF_FILES(); // error or eofs
}

void lexer::replace_newlines_with_line_directives(string &s)
{
    // replace newlines with line directives
    boost::regex newline_rgx(R"(\n)");
    s = boost::regex_replace(s, newline_rgx, R"(\\n)");
}

// void lexer::escape_newlines(const string &s, string &sout)
// {
//     stringstream ss;
//     size_t index = string::npos;
//     string suffix = s;
//     // replace newlines with escapes
//     while ((index = suffix.find('\n')) != string::npos)
//     {
//         string prefix = suffix.substr(0, index - 1);
//         suffix = suffix.substr(index + 1);
//         ss << prefix << "\\\\n";
//     }
//     ss << suffix;
//     sout = ss.str();
// }

void lexer::print_line_count(const string &s)
{
    size_t line_count = 0;
    line_count = std::count(s.begin(), s.end(), '\n');
    INFO("line count: " << line_count);
}

void lexer::print_line_number_comment()
{
    m_stream << "/* line " << m_line << " */\n";
}

/**
 * @name  print_token
 * @def   void lexer::print_token(token_match p_smatch)
 * @brief print token to stdout
 * @param p_smatch
 * @param token_match p_smatch
 */
void lexer::print_token(const token_value_t *tval)
{
    // const token *ptoken = &g_tokens[p_smatch->id];
    //  cout << "token"
    //       << "\n{"
    //       << "\n    id   : " << left << FMT_FG_DARK_GREY << FMT_ITALIC << p_smatch->id << FMT_RESET
    //       << "\n    name : " << left << FMT_FG_DARK_GREY << FMT_ITALIC << ptoken->name << FMT_RESET
    //       << "\n    stype: " << left << FMT_FG_DARK_GREY << FMT_ITALIC << ptoken->stype << FMT_RESET
    //       << "\n    rexp : " << left << FMT_FG_DARK_GREY << FMT_ITALIC << ptoken->rexp << FMT_RESET
    //       << "\n    value: " << left << FMT_FG_DARK_GREY << FMT_ITALIC << "\"" << p_smatch->match << "\"" << FMT_RESET
    //       << "\n    line#: " << left << FMT_FG_DARK_GREY << FMT_ITALIC << ptoken->_line_ << FMT_RESET
    //      << "\n}" << " #" << __LINE__ << endl;
}

//
// /// "External" symbols: returned by the scanner.
// struct symbol_type : basic_symbol<by_kind>
// {
//     /// Superclass.
//     typedef basic_symbol<by_kind> super_type;
//
//     /// Empty symbol.
//     symbol_type () YY_NOEXCEPT { }
//
//     /// Constructor for valueless symbols, and symbols from each type.
//     symbol_type (int tok) : super_type (token_kind_type (tok)) { }
//
//     symbol_type (int tok, char v) : super_type (token_kind_type (tok), std::move (v)) { }
//
//     symbol_type (int tok, std::string v) : super_type (token_kind_type (tok), std::move (v)) { }
//
//     int operator int()
//     {
//
//     }
// };

/**
 * @name  lexer::on_token
 * @brief override virtual, on_token, for each token ...
 * @param ptoken
 * @param token_def* token
 */
inline parser::symbol_type lexer::on_token(unsigned long id)
{
    // INFO("ptoken->token->name=" << ptoken->token->name << ", g_pstate->name=" << _state->name);
    ERROR("_state.id=" << _pstate->id);
    ERROR("_state.name=" << _pstate->name);
    switch (_pstate->id)
    {
    case UL_INITIAL:
    {
        INFO("switch case: INITIAL_STATE");
        switch (id)
        {
        case OPEN_BRACE:
            set_state_flag(&ESCAPED);
            // update_state();
            return parser::make_OPEN_BRACE();
        case COMMENT:
            return parser::make_SKIP_TOKEN();
        case NEWLINE:
            m_line++;
            m_stream << '\n';
            return parser::make_SKIP_TOKEN();
        case SKIP_TOK:
            return parser::make_SKIP_TOKEN();
        default:;
        }
        break;
    }
    case UL_ESCAPED:
    {
        INFO("switch case: ESCAPED_STATE");
        switch (id)
        {
        case CLOSE_BRACE:
            set_state_flag(&INITIAL);
            // update_state();
            return parser::make_CLOSE_BRACE();
        case IF:
            set_state_flag(&IF_BLOCK);
            return parser::make_IF();
        case SYMBOL:
            return parser::make_SYMBOL(m_match);
        case CONST_SYMBOL:
            return parser::make_CONST_SYMBOL(m_match);
        case PERCENT_SIGN:
            return parser::make_PERCENT_SIGN();
        case PLUS_SIGN:
            return parser::make_PLUS_SIGN('+');
        case DOT:
            return parser::make_DOT();
        case HASH_MARK:
            return parser::make_HASH_MARK();
        case COLON:
            return parser::make_COLON();
        case COMMA:
            return parser::make_COMMA();
        case VBAR:
            return parser::make_VBAR();
        case CAPITALIZE:
            return parser::make_CAPITALIZE(m_match);
        case TRUNCATE:
            return parser::make_TRUNCATE(m_match);
        case STRIP:
            return parser::make_STRIP(m_match);
        case EQUAL_SIGN:
            return parser::make_EQUAL_SIGN();
        case NUMERIC_LITERAL:
            return parser::make_NUMERIC_LITERAL(m_match);
        case FILE_ATTRIB:
            return parser::make_FILE_ATTRIB(m_match);
        case INCLUDE:
            return parser::make_INCLUDE(m_match);
        case ASSIGN:
            return parser::make_ASSIGN(m_match);
        case DOUBLE_QUOTE:
            set_state_flag(&DOUBLE_QUOTED); // fallthrough
        case WHITESPACE:                    // fallthrough
        case SKIP_TOK:
            return parser::make_SKIP_TOKEN();
        default:;
        }
        break;
    }
    case UL_IF_BLOCK:
    {
        INFO("switch case: IF_BLOCK_STATE");
        switch (id)
        {
        case SKIP_TOK:
            return parser::make_OPEN_BRACE();
        default:;
        }
        break;
    }
    case UL_DOUBLE_QUOTED:
    {
        INFO("switch case: DOUBLE_QUOTED_STATE");
        switch (id)
        {
        case ESC_TAB:
            m_sstring << "\t";
            return parser::make_SKIP_TOKEN();
        case ESC_BACKSLASH:
            m_sstring << "\\";
            return parser::make_SKIP_TOKEN();
        case ESC_DOUBLE_QUOTE:
            m_sstring << "\"";
            return parser::make_SKIP_TOKEN();
        case ESC_SINGLE_QUOTE:
            m_sstring << "'";
            return parser::make_SKIP_TOKEN();
        case VALID_CHAR:
            m_sstring << m_match;
            cout << "char " << m_sstring.str() << endl;
            return parser::make_SKIP_TOKEN();
        case DOUBLE_QUOTE:
        {
            set_state_flag(&ESCAPED);
            // update_state();
            string qstr = m_sstring.str();
            m_sstring.str("");
            m_sstring.clear();
            return parser::make_STRING_LITERAL(qstr);
        }
        case SKIP_TOK:
            return parser::make_SKIP_TOKEN();
        default:;
        }
        break;
    }
    case UL_INCLUDING:
        INFO("switch case: INCLUDING_STATE");
        break;
    default:;
    }
    return parser::make_END();
}
