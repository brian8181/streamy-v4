
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
inline state_t *g_pstate = &sINITIAL;

/**
 * @name   init
 * @def    void lexer::init(const string &config_file, const string& input_file, string& output_file)
 * @brief  initialize state
 * @return bool
 */
void lexer::init()
{
    TRACE();
    read_str(g_input_file, m_search);
    // set state
    set_state(sINITIAL);
    m_stream.open(g_output_file, std::ios_base::out | std::ios::trunc);
    m_line = 0;
}

/**
 * @name   set_state
 * @brief  void lexer::set_state(state_t* pstate)
 * @return void
 */
void lexer::set_state(const state_t &state)
{
    TRACE();
    *g_pstate = state;

    stringstream ss;
    const unsigned long sid = g_pstate->id;
    const vector<unsigned long> *STATE_TOKENS = g_tokens_by_state_id[sid];
    const unsigned long len = STATE_TOKENS->size();

    for (unsigned long i = 0; i < len; i++)
    {
        unsigned long id = (*STATE_TOKENS)[i];
        token_def *ptoken = &g_tokens[id];
        // ss << "(?<" << ptoken->name << ">)" << ptoken->rexp << ")|";
        ss << "(" << ptoken->rexp << ")|";
    }

    string rexp_str = ss.str();
    rexp_str.pop_back(); // remove extra '|' i.e. "V-BAR"
    // set context
    m_rexp = boost::regex(rexp_str, boost::regex::extended);
    m_iter = boost::sregex_iterator(m_search.begin(), m_search.end(), m_rexp);

    INFO("STATE=" << g_pstate->id << " : " << g_pstate->name);
    INFO("EXPR=\"" << rexp_str << "\"");
}

void lexer::include_file(const string &input_file)
{
    // just read new, (include), file and prepend to remaining text
    string s;
    read_str(input_file, s);
    m_search = s + m_search; // prepend new text to remaining text
    set_state(sINITIAL);
}

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
    const string VALID_SYMBOL_CHARS = R"([A-Za-z0-9_])";  /** @note_to_self: ~~> \w == [A-Za-z0-9_] **/
    const string VALID_CHARS = R"([[:punct:][:alnum:]])"; // [:punct:] = !"#$%&'()*+,-./:;<=>?@[\]^_{|}~`);
    const string CONFIG_STATES = R"((?<states>^\s*(?<state>[A-Za-z][A-Za-z0-9_]*)\s*=\s*\s*\{(?<tokens>[A-Za-z][A-Za-z0-9_]*(, [A-Za-z][A-Za-z0-9_]*)*)\}\s*\s*$))";
    const string CONFIG_SECTIONS = R"(^\s*\[\s*(?<tokens>tokens)|(?<groups>groups)|(?<states>states)\s*\]\s*$)";
    const string CONFIG_PAIR = R"(\s*(?<type>" + TOKEN_TYPE_ + ")\\s+(?<name>[A-Za-z])" + VALID_SYMBOL_CHARS + R"("*)\\s*=\\s*(?<rexp>)" + VALID_CHARS + R"(*)\s*\"(?<test>.*)\"\s*)";
    const string CONFIG_COMMENT = R"(^\s*#.*$)";
    const string CONFIG = R"((?<pairs>)" + CONFIG_PAIR + R"()|(?<comments>)" + CONFIG_COMMENT + R"())";
    const string qwerty = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcefghijklmnopqrstuvwxyz1234567890~!@#$%^&*()_+{}|:\"<>?`-=[]\\;',./'";

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
 * @name   get_token
 * @def    parser::symbol_type lexer::get_token()
 * @return int
 */
parser::symbol_type lexer::get_token()
{
    TRACE();
SKIP:
    if (m_iter != boost::sregex_iterator())
    {
        token_def *ptok_def = nullptr;
        boost::smatch m = *m_iter;
        const size_t len = m.size();
        m_search = m.suffix();

        // find matched
        for (int i = 1; i < len; ++i)
        {
            if (m[i].matched)
            {
                if (m.prefix().matched)
                {
                    if (g_pstate->id != UL_INITIAL_STATE)
                    {
                        INFO("error: unexpected token ... \"" << m.prefix() << "\"");
                        return parser::make_YYerror();
                    }
                    // stream prefix (unescaped text)
                    m_stream << m.prefix();
                }

                // get id by index value "i-1" zero based vector
                unsigned long id = (*g_tokens_by_state_id[g_pstate->id])[i - 1];
                ptok_def = &g_tokens[id];

                // find match & lookup by sub_match index
                token_match tok = {id, ptok_def, g_input_file, m_line, i, &m};
                string match_str = m[i].str();
                ++m_iter;

                // get return val, goto skip, otherwise return
                yy::parser::symbol_type rtoken = on_token(&tok);
                if (rtoken.kind() == yy::parser::symbol_type(parser::token::SKIP_TOKEN).kind())
                {
                    INFO("Skipping - token:" << tok.token->name << " = " << tok.pmatch->str());
                    goto SKIP;
                }

                INFO("match.sz:" << m.str().size() << " - prefix.sz:" << m.prefix().str().size() << " - suffix.sz:" << m.suffix().str().size());
                INFO("match[ " << "i=" << i << " ] = " << ptok_def->name << "[ \"" << m[i].str() << "\" ]");
                return rtoken;
            }
        }
    }
    else
    {
        m_stream << m_search;
        m_stream.close();
        return parser::make_END(); // error or eof
    }
    return parser::make_END_OF_FILES(); // error or eof
}

/**
 * @name  print_token
 * @def   void lexer::print_token(token_match m)
 * @brief print token to stdout
 * @param m
 * @param token_match m
 */
void lexer::print_token(const token_match *m)
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
 * @name  lexer::on_token
 * @brief override virtual, on_token, for each token ...
 * @param ptoken
 * @param token_def* token
 */
inline parser::symbol_type lexer::on_token(const token_match *ptoken)
{
    TRACE();
    switch (g_pstate->id)
    {
    case UL_INITIAL_STATE:
    {
        INFO("switch case: INITIAL_STATE");
        switch (ptoken->id)
        {
        case UL_OPEN_BRACE:
            TRACE();
            set_state(sESCAPED);
            return parser::make_OPEN_BRACE();
        case UL_COMMENT:
            return parser::make_SKIP_TOKEN();
        case UL_NEWLINE:
            TRACE();
            m_line++;
            write_stream(ptoken->pmatch->str());
            return parser::make_SKIP_TOKEN();
        case UL_SKIP_TOKEN:
            return parser::make_OPEN_BRACE();
        default:;
        }
        break;
    }
    case UL_ESCAPED_STATE:
    {
        INFO("switch case: ESCAPED_STATE");
        switch (ptoken->id)
        {
        case UL_CLOSE_BRACE:
            set_state(sINITIAL);
            return parser::make_CLOSE_BRACE();
        case UL_IF:
            set_state(sIF_BLOCK);
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
            set_state(sDOUBLE_QUOTED); // fallthrough
        case UL_WHITESPACE:            // fallthrough
        case UL_SKIP_TOKEN:
            return parser::make_SKIP_TOKEN();
        default:;
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
        default:;
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
            set_state(sESCAPED);
            string qstr = g_stringstream.str();
            g_stringstream.str("");
            g_stringstream.clear();
            m_stream << qstr;
            return parser::make_STRING_LITERAL(qstr);
        }
        case UL_SKIP_TOKEN:
            return parser::make_SKIP_TOKEN();
        default:;
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

    // todo
    // pop stack
    // if(file_ptrs.empty());
    //     return parser::make_END_OF_FILES();

    // g_input = file_ptrs.top();
    // file_ptrs.pop();

    //if (filestack.empty())
        ;
    //return parser::make_END_OF_FILES();

   // g_input_file = filestack.top();
    //filestack.pop();

    return parser::make_END();
}
