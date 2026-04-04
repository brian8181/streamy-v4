
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
#include <stdlib.h>
#include <string.h>
#include <boost/regex.hpp>
#include <fmt/core.h>
#include <fmt/format.h>
#include "log.hpp"
#include "fileio.hpp"
#include "lexer.hpp"
#include "driver.h"

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
 * @name g_stringstream
 */
stringstream g_stringstream;
/**
 * @brief global state_t state
 * @name  gp_state
 */
inline state_t *gp_state = &sINITIAL;

/**
 * @name   init
 * @def    void lexer::init(const string &config_file, const string& input_file, const string& output_file)
 * @brief  initialize state
 * @return bool
 */
void lexer::init(const string &config_file, string &input_file, const string &output_file)
{
    TRACE();
    read_str(input_file, m_text);
    g_input = new file_ptr(input_file);
    m_suffix = m_text;
    // set state
    set_state(gp_state);
    m_stream.open(output_file, std::ios_base::out | std::ios::trunc);
    m_debug1_stream.open("debug1.txt", std::ios_base::out | std::ios::trunc);
    m_debug2_stream.open("debug2.txt", std::ios_base::out | std::ios::trunc);
}

/**
 * @name reset
 * @def  void lexer::reset()
 */
void lexer::push(string &input_file)
{
    file_ptrs.push(g_input);
    g_input = new file_ptr(input_file);

    filestack.push(g_input_file);
    g_input_file = input_file;

    fs::path p = g_input_file;
    g_output_file = "build/" + p.filename().string() + ".obj";
    read_str(input_file, m_text);
    m_suffix = m_text;
    // set state
    set_state(gp_state);
}

/**
 * @name pop
 * @def  void lexer::reset()
 */
void lexer::pop()
{
    if (file_ptrs.empty())
        parser::make_END_OF_FILES();
    g_input = file_ptrs.top();
    file_ptrs.pop();

    if (filestack.empty())
        parser::make_END_OF_FILES();
    g_input_file = filestack.top();
    filestack.pop();

    fs::path p = g_input_file;
    g_output_file = "build/" + p.filename().string() + ".obj";
    read_str(g_input->path, m_text);
    m_suffix = m_text;
    // set state
    set_state(gp_state);
}

/**
 * @name   load_config
 * @def    void lexer::load_config( const string &file )
 * @brief  load_config: load configuration from file
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

            auto *ptoken = new token_def{
                string(name),
                stype,
                string(expr),
            };
            // copy to term to vector
            // m_tokens.push_back(ptoken);
            // m_id_tab[ptoken->id] = ptoken;
            // m_name_tab[ptoken->name] = ptoken;
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
            // (*m_pstate_tab)[pstate->id] = pstate; // insert new state into table

            // copy to term to vector
            vector<token_def> tokens;         // token vector for this state
            std::stringstream ss(str_tokens); // csv of states
            std::string str_token;            // item in csv states

            // use get line to split on commas
            while (std::getline(ss, str_token, ','))
            {
                // token_def* ptoken = m_name_tab[str_token];
                // tokens.push_back(*ptoken);
                //_state_tokens_tab[pstate->id] = tokens;
            }
        }
    }
}

/**
 * @name   dump_config
 * @brief  void lexer::dump_config( const string& file ) const
 * @param  const string& file
 * @return void
 */
void lexer::dump_config(const string &file) const
{
    dump_config();
}

/**
 * @name   dump_config
 * @def    void lexer::dump_config( ) const
 * @brief  dump current config
 * @return void
 */
void lexer::dump_config() const
{
    // bkp todo, not what I would call a good dump ...
    INFO("config_file: " << g_config_file);
    INFO("input file: " << g_input_file);
    INFO("input text: " << m_text);
    INFO("regexp: " << m_expr);
    INFO("state: " << gp_state->name);
}

/**
 * @name   get_state
 * @brief  state_t *lexer::get_state() const
 * @return state_t
 */
state_t *lexer::get_state() const
{
    return gp_state;
}

/**
 * @name   set_state
 * @brief  void lexer::set_state(state_t* pstate)
 * @param  state_t* pstate
 * @return void
 */
void lexer::set_state(state_t *pstate)
{
    TRACE();
    gp_state = pstate;

    stringstream ss;
    unsigned long sid = pstate->id;
    const vector<unsigned long> *STATE_TOKENS = g_tokens_by_state_id[sid];
    const unsigned long len = STATE_TOKENS->size();
    // iter this states tokens
    for (unsigned long i = 0; i < len; i++)
    {
        unsigned long id = (*STATE_TOKENS)[i];
        token_def *ptoken = &g_tokens[id];
        // ptoken->index = i+1;
        //  ss << R"((?<)" << ptoken->name << R"(>)" << ptoken->rexp << R"()|)";
        ss << "(" << ptoken->rexp << ")|";
        // m_tokens.push_back(ptoken);
        // m_name_tab[ptoken->name] = ptoken;
    }

    m_expr = ss.str();
    m_expr.pop_back(); // remove extra '|' i.e. "V-BAR"

    // set context
    set_context(m_suffix);

#ifdef DEBUG
    INFO("STATE=" << pstate->id << " : " << pstate->name);
    INFO("EXPR=\"" << m_expr << "\"");
#endif
}

/**
 * @name   get_token
 * @def    parser::symbol_type lexer::get_token()
 * @return int
 */
parser::symbol_type lexer::get_token()
{
    TRACE();
SKIP:
    if ((*m_piter) != m_end)
    {
        token_def *ptok_def = nullptr;
        boost::smatch m = *(*m_piter);
        const size_t len = m.size();

        m_match = m.str();
        m_prefix = m.prefix().matched ? m.prefix() : string("");
        m_suffix = m.suffix().matched ? m.suffix() : string("");
        m_debug1_stream << m_prefix << m_match;
        m_debug2_stream << "match.sz:" << m_match.size() << " - prefix.sz:" << m_prefix.size() << " - suffix.sz:" << m_suffix.size() << endl;
        m_debug2_stream << FMT_FG_BLUE << m_prefix << FMT_FG_GREEN << m_match << FMT_FG_DARK_GREY << m_suffix << FMT_RESET << endl
                        << endl;

        int pos = g_input->size - m_suffix.size();
        g_input->set_pos(pos);
        g_input->log();

        // find matched
        for (int i = 1; i < len; ++i)
        {
            if (m[i].matched)
            {
                if (m.prefix().matched)
                {
                    if (gp_state->id != UL_INITIAL_STATE)
                    {
                        INFO("error: unexpected token ... \"" << m_prefix << "\"");
                        return parser::make_YYerror();
                    }
                    // stream prefix (unescaped text)
                    m_stream << m.prefix();
                }

                // get id by index value "i-1" zero based vector
                unsigned long id = (*g_tokens_by_state_id[gp_state->id])[i - 1];
                ptok_def = &g_tokens[id];

                // find match & lookup by sub_match index
                token_match tok = {id, ptok_def, g_input->path, m_line, i, &m};
                string match_str = m[i].str();
                ++(*m_piter);

                // get return val, goto skip, otherwise return
                yy::parser::symbol_type rtoken = on_token(&tok);
                if (rtoken.kind() == yy::parser::symbol_type(parser::token::SKIP_TOKEN).kind())
                {
                    INFO("Skipping - token:" << tok.token->name << " = " << tok.pmatch->str());
                    goto SKIP;
                }

                INFO("match.sz:" << m_match.size() << " - prefix.sz:" << m_prefix.size() << " - suffix.sz:" << m_suffix.size());
                INFO("match[ " << "i=" << i << " ] = " << ptok_def->name << "[ \"" << m[i].str() << "\" ]");
                return rtoken;
            }
        }
    }
    else
    {
        m_stream << m_suffix;
        m_stream.close();
        return parser::make_END(); // error or eof
    }
    return parser::make_END_OF_FILES(); // error or eof
}

/**
 * @name   get_expr
 * @def    const string& lexer::get_expr() const
 * @brief  get regex expression
 * @return const string&
 */
const string &lexer::get_expr() const
{
    return m_expr;
}

/**
 * @name  print_token
 * @def   void lexer::print_token(token_match m)
 * @brief print token to stdout
 * @param token_match m
 */
void lexer::print_token(token_match *m)
{
    const token *ptoken = &g_tokens[m->id];
    cout << "token"
         << "\n{"
         << "\n    id   : " << left << FMT_FG_DARK_GREY << FMT_ITALIC << m->id << FMT_RESET
         << "\n    name : " << left << FMT_FG_DARK_GREY << FMT_ITALIC << ptoken->name << FMT_RESET
         << "\n    stype: " << left << FMT_FG_DARK_GREY << FMT_ITALIC << ptoken->stype << FMT_RESET
         << "\n    rexp : " << left << FMT_FG_DARK_GREY << FMT_ITALIC << ptoken->rexp << FMT_RESET
         << "\n    value: " << left << FMT_FG_DARK_GREY << FMT_ITALIC << "\"" << m->pmatch->str() << "\"" << FMT_RESET
         << "\n    line#: " << left << FMT_FG_DARK_GREY << FMT_ITALIC << ptoken->_line_ << FMT_RESET
         << "\n}" << " #" << __LINE__ << endl;
}

/**
 * @name   is_id
 * @def    bool lexer::is_id( const token_def& token, const int& id )
 * @param  token
 * @param  id
 * @return bool
 */
bool lexer::is_id(const token_def &token, const unsigned long &id)
{
    // return (token.id == id);
    return true;
}

/**
 * @name   set_context
 * @def    set_context(string& current_input)
 * @param  string& current_input
 * @return void
 */
void lexer::set_context(string &current_input)
{
    TRACE();
    // reinit get_token iterators
    m_rexp = boost::regex(m_expr, boost::regex::extended);
    m_text = current_input;
    m_begin = boost::sregex_iterator(m_text.begin(), m_text.end(), m_rexp);
    m_piter = &m_begin;
    m_end = boost::sregex_iterator();
}

/**
 * @name   lexer::on_state
 * @param  state_t* pstate
 * @return unsigned long
 */
inline unsigned long lexer::on_state(state_t *pstate)
{
    return -1;
}

/**
 * @name  lexer::on_token
 * @brief override virtual, on_token, for each token ...
 * @param token_def* token
 */
inline parser::symbol_type lexer::on_token(token_match *ptoken)
{
    TRACE();
    switch (gp_state->id)
    {
    case UL_INITIAL_STATE:
    {
        INFO("switch case: INITIAL_STATE");
        switch (ptoken->id)
        {
        case UL_OPEN_BRACE:
            TRACE();
            set_state(&sESCAPED);
            return parser::make_OPEN_BRACE();
        case UL_COMMENT:
            return parser::make_SKIP_TOKEN();
        case UL_NEWLINE:
            TRACE();
            m_line++;
            m_stream << ptoken->pmatch->str();
            return parser::make_SKIP_TOKEN();
        case UL_SKIP_TOKEN:
            return parser::make_OPEN_BRACE();
        }
        break;
    }
    case UL_ESCAPED_STATE:
    {
        INFO("switch case: ESCAPED_STATE");
        switch (ptoken->id)
        {
        case UL_CLOSE_BRACE:
            set_state(&sINITIAL);
            return parser::make_CLOSE_BRACE();
        case UL_IF:
            set_state(&sIF_BLOCK);
            return parser::make_IF();
        case UL_SYMBOL:
            return parser::make_SYMBOL(ptoken->pmatch->str());
        case UL_CONST_SYMBOL:
            return parser::make_CONST_SYMBOL(ptoken->pmatch->str());
        case UL_PERCENT_SIGN:
            return parser::make_PERCENT_SIGN();
        case UL_PLUS_SIGN:
            return parser::make_PLUS_SIGN('+');
        case UL_DOT:
            return parser::make_DOT();
        case UL_HASH_MARK:
            return parser::make_HASH_MARK();
        case UL_COLON:
            return parser::make_COLON();
        case UL_COMMA:
            return parser::make_COMMA();
        case UL_VBAR:
            return parser::make_VBAR();
        case UL_CAPITALIZE:
            return parser::make_CAPITALIZE(ptoken->pmatch->str());
        case UL_TRUNCATE:
            return parser::make_TRUNCATE(ptoken->pmatch->str());
        case UL_STRIP:
            return parser::make_STRIP(ptoken->pmatch->str());
        case UL_EQUAL_SIGN:
            return parser::make_EQUAL_SIGN();
        case UL_NUMERIC_LITERAL:
            return parser::make_NUMERIC_LITERAL(ptoken->pmatch->str());
        case UL_FILE_ATTRIB:
            return parser::make_FILE_ATTRIB(ptoken->pmatch->str());
        case UL_INCLUDE:
            return parser::make_INCLUDE(ptoken->pmatch->str());
        case UL_ASSIGN:
            return parser::make_ASSIGN(ptoken->pmatch->str());
        case UL_DOUBLE_QUOTE:
            set_state(&sDOUBLE_QUOTED);
        case UL_WHITESPACE:
        case UL_SKIP_TOKEN:
            return parser::make_SKIP_TOKEN();
        }
        break;
    }
    break;
    case UL_IF_BLOCK_STATE:
    {
        INFO("switch case: IF_BLOCK_STATE");
        switch (ptoken->id)
        {
        case UL_SKIP_TOKEN:

            return parser::make_OPEN_BRACE();
        }
        break;
    }
    break;
    case UL_DOUBLE_QUOTED_STATE:
    {
        INFO("switch case: DOUBLE_QUOTED_STATE");
        switch (ptoken->id)
        {
        case UL_ESC_TAB:
            g_stringstream << "\t";
            return parser::make_SKIP_TOKEN();
        case UL_ESC_BACKSLASH:
            g_stringstream << "\\";
            return parser::make_SKIP_TOKEN();
        case UL_ESC_DOUBLE_QUOTE:
            g_stringstream << "\"";
            return parser::make_SKIP_TOKEN();
        case UL_ESC_SINGLE_QUOTE:
            g_stringstream << "'";
            return parser::make_SKIP_TOKEN();
        case UL_VALID_CHAR:
            g_stringstream << ptoken->pmatch->str();
            cout << "char " << g_stringstream.str() << endl;
            return parser::make_SKIP_TOKEN();
        case UL_DOUBLE_QUOTE:
        {
            set_state(&sESCAPED);
            string qstr = g_stringstream.str();
            g_stringstream.str("");
            g_stringstream.clear();
            m_stream << qstr;
            return parser::make_STRING_LITERAL(qstr);
        }
        case UL_SKIP_TOKEN:

            return parser::make_SKIP_TOKEN();
        }
        break;
    }
    break;
    case UL_INCLUDING_STATE:
    {
        INFO("switch case: INCLUDING_STATE");
        //     switch (ptoken->id)
        //     {
        //         case UL_FILE_ATTRIB:
        //         {
        //             const boost::regex re("file=\"([^\"]*)\"");
        //             boost::smatch sm;
        //             boost::regex_search(ptoken->pmatch->str(), sm, re);
        //             // const int len = m_matches.size();
        //             g_tokens[ ptoken->id ];
        //             //m_include_path.clear();
        //             m_include_path = sm[1].str();
        //             cout << "file=" << m_include_path << endl;
        //             string sout;
        //             read_str(m_include_path, sout);
        //             // append include file output to buffer
        //             //m_include_buffer.clear();
        //             //m_include_buffer << endl << sout << endl;
        //             return parser::make_SKIP_TOKEN();
        //         }
        //         case UL_CLOSE_BRACE:
        //         {
        //             // append suffix after include is inserted/streamed
        //            // m_include_buffer << m_suffix;
        //             // set the suffix a.k.a "current search buffer"
        //             m_suffix.clear();
        //             m_suffix = m_include_buffer.str();
        //             set_state(&sINITIAL);
        //             m_stream << "}";
        //             return parser::make_SKIP_TOKEN();
        //         }
        //         case UL_DOUBLE_QUOTE:
        //             set_state(&sESCAPED);
        //             return parser::make_STRING_LITERAL(g_stringstream.str());
        //         case UL_WHITESPACE:
        //             cout << "WHITESPACE : SKIP_TOKEN" << endl;
        //             return parser::make_SKIP_TOKEN();
        //     }
        //     break;
    }
    break;
    default:
    {
        ERROR("ERROR:" << ptoken->id);
        break;
    }
    }

    // pop stack
    if(file_ptrs.empty(), "file_ptrs is empty, cannot pop input file path");
        return parser::make_END_OF_FILES();

    g_input = file_ptrs.top();
    file_ptrs.pop();

    if(filestack.empty(), "filestack is empty, cannot pop input file path");
        return parser::make_END_OF_FILES();

    g_input_file = filestack.top();
    filestack.pop();

    return parser::make_END();
}
