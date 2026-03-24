
/**
 * @file    Lexer.cpp
 * @version 0.0.1
 * @date    Fri, 26 Sep 2025 17:05:10 +0000
 */

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <boost/regex.hpp>
#include <fmt/core.h>
#include <fmt/format.h>
#include <iomanip>
#include <iostream>
#include <map>
#include <regex>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include "fileio.hpp"
#include "Lexer.hpp"
#include "tokens.hpp"
#include "driver.h"

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::map;
using std::pair;
using std::setw;
using std::left;
using std::right;
using yy::parser;

/**
 * @name Lexer
 * @def Lexer::Lexer()
 * @brief default ctor
 */
Lexer::Lexer()
{
}

/**
 * @name init
 * @def void Lexer::init(const string &config_file, parser* pparser,
 *      const string& input_file, const string& output_file)
 * @brief  initialize state
 * @return bool
 */
void Lexer::init(const string &config_file, parser* pparser, const string& input_file, const string& output_file)
{
    m_config_file = config_file;
    m_input_file = input_file;
    m_output_file = output_file;
    m_pparser = pparser;

    //load_config( m_config_file );
    read_str( m_input_file, m_text );
    m_suffix = m_text;
    // set state
    set_state(gp_state);

    // todo context
    // context_t c;
    // c.expr = m_expr;
    // c.scan_file = m_input_file;
    // c.search_text = m_text;

    m_stream.open(output_file, std::ios_base::out | std::ios::trunc);
}

/**
 * @name reset
 * @def void Lexer::reset()
 */
void Lexer::reset()
{
    init(m_config_file, m_pparser, m_input_file, m_output_file);
}

/**
 * @name load_config
 * @def void Lexer::load_config( const string &file )
 * @brief  load_config: load configuration from file
 * @param  const string& file
 * @return void
 */
void Lexer::load_config( const string& file )
{
    m_config_file = file;
    string section = "none";
    string s;
    read_str( m_config_file, s);
    auto rgx = boost::regex( CONFIG_SECTIONS );
    boost::smatch terminal_match;
    // begins terminal section
    boost::regex_search( s, terminal_match, rgx, boost::match_not_bol | boost::match_not_eol );
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
        auto config_rgx = boost::regex( CONFIG );
        boost::smatch token_match;
        boost::regex_match( line, token_match, config_rgx );
        if(constexpr unsigned int ID_PAIR = 1; token_match[ID_PAIR].matched)
        {
            string name = token_match["name"].str();
            string expr = token_match["rexp"].str();
            string stype = token_match["type"].str();
            string test_val = token_match["test"].str();

            auto* ptoken = new token_def{string(name), stype, string(expr),  };

            // copy to term to vector
            m_tokens.push_back(ptoken);
            //m_id_tab[ptoken->id] = ptoken;
            m_name_tab[ptoken->name] = ptoken;
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
        auto config_states_rgx = boost::regex( CONFIG_STATES );
        boost::regex_match( line, states_match, config_states_rgx );
        if(states_match["states"].matched)
        {
            string str_state = states_match["state"].str();  // new state to create
            string str_tokens = states_match["tokens"].str(); // csv tokens for that state
            unsigned long i = 0ul;
            unsigned long state_id = 0xFFul | (++i*6ul); // generate id for new state
            auto* pstate = new state_t{ state_id , str_state }; // create new state
            // m_pstates->push_back(pstate);
            // (*m_pstate_tab)[pstate->id] = pstate; // insert new state into table

            // copy to term to vector
            vector<token_def> tokens; // token vector for this state
            std::stringstream ss(str_tokens); // csv of states
            std::string str_token; // item in csv states

            // use get line to split on commas
            while (std::getline(ss, str_token, ','))
            {
                token_def* ptoken = m_name_tab[str_token];
                tokens.push_back(*ptoken);
                //_state_tokens_tab[pstate->id] = tokens;
            }
        }
    }
}

/**
 * @name dump_config
 * @brief void Lexer::dump_config( const string& file ) const
 * @param const string& file
 * @return void
 */
void Lexer::dump_config( const string& file ) const
{
    dump_config( );
}

/**
 * @name dump_config
 * @def void Lexer::dump_config( ) const
 * @brief  dump current config
 * @return void
 */
void Lexer::dump_config( ) const
{
    cout << "config_file: " << m_config_file << endl;
    cout << "input file: " << m_input_file << endl;
    cout << "input text: " << m_text << endl;
    cout << "regexp: " << m_expr << endl;
    cout << "state: " << gp_state->name << endl;

    // stringstream ss;
    // const size_t len = m_tokens.size();
    // for(int i = 0; i < len; ++i)
    // {
    //     const token_def* ptoken = g_tokens[i];
    //     print_token(ptoke->na);
    // }
    // cout << ss.str();
}

/**
* @name get_state
* @brief state_t *Lexer::get_state() const
* @return state_t
*/
state_t *Lexer::get_state() const
{
    return gp_state;
}

/**
 * @name set_state
 * @brief void Lexer::set_state(state_t* pstate)
 * @param state_t* pstate
 * @return void
 */
void Lexer::set_state(state_t* pstate)
{
    m_tokens.clear();
    m_idx_tab.clear();
    m_name_tab.clear();
    gp_state = pstate;

    stringstream ss;
    unsigned long sid = pstate->id;
    const vector<unsigned long>* STATE_TOKENS = g_tokens_by_state_id[sid];
    const unsigned long len = STATE_TOKENS->size();
    // iter this states tokens
    for (unsigned long i = 0; i < len; i++)
    {
        unsigned long id = (*STATE_TOKENS)[i];
        token_def* ptoken = &g_tokens[id];
        //ptoken->index = i+1;
        // ss << R"((?<)" << ptoken->name << R"(>)" << ptoken->rexp << R"()|)";
        ss << "(" << ptoken->rexp << ")|";

        m_tokens.push_back(ptoken);
        m_name_tab[ptoken->name] = ptoken;
    }

    m_expr.clear();
    m_expr = ss.str();
    m_expr.pop_back(); // remove extra '|' i.e. "V-BAR"

    // set context
    set_context(m_suffix);

#ifdef DEBUG
    cout << "EXPR=\"" << m_expr << "\"" << endl;
    cout << "STATE=" << pstate->id << " : " << pstate->name << endl;
#endif
}

/**
 * @name  get_token
 * @def parser::symbol_type Lexer::get_token()
 * @return int
 */
parser::symbol_type Lexer::get_token()
{
    SKIP:
    if((*m_piter) != m_end)
    {
        token_def* ptoken = nullptr;
        boost::smatch m = *(*m_piter);
        const size_t len = m.size();

        m_str.clear();
        m_prefix.clear();
        m_suffix.clear();

        m_str    = m.str();
        m_prefix = m.prefix().matched ? m.prefix() : string("");
        m_suffix = m.suffix().matched ? m.suffix() : string("");

        // find matched
        for(int i = 1; i < len; ++i)
        {
            if(m[i].matched)
            {
#ifdef DEBUG
                cout << "MATCH=\"" << m.prefix() << "\" : \"" << m.str() << "\" : \"" << m.suffix() << "\""<<  endl;
#endif
                if(m.prefix().matched)
                {
                    if (gp_state->id != UL_INITIAL_STATE)
                    {
                        cout << "error: unexpected token ... \"" << m.prefix() << "\"" << endl;
                        return parser::make_YYerror();
                    }
                    // stream prefix (unescaped text)
                    //m_sout << m.prefix();
                    m_stream << m.prefix();
                }

                // get id by index value "i-1" zero based vector
                // i is match index to group ...
                // (g index 0 (g index 1)|(g index 2)|(g index 3))...
                unsigned long id = (*g_tokens_by_state_id[gp_state->id])[i-1];
                ptoken = &g_tokens[id];

                // find match & lookup by sub_match index
                token_match tmatch = {id, 0, 0, m.str(), ptoken};
                string match_str = m[i].str();
                m_matches.push_back(&tmatch);
                ++(*m_piter);

                // get return "value / token" first, then check for skip,
                // call "get_token/on_token" recursively ,(as long as), ... while it skips
                // then return token ... stack unrolls
                yy::parser::symbol_type rtoken = on_token( &tmatch );
                if (rtoken.kind() == yy::parser::symbol_type( parser::token::SKIP_TOKEN).kind())
                {
                    cout << "skipping... " << endl;
                    goto SKIP;
                }
                //m_stream << match_str;
                return rtoken;
            }
        }
    }
    else
    {
        //m_sout << m_suffix;
        //write_str(m_output_file, m_sout.str());
        m_stream << m_suffix;
        m_stream.close();
        m_str.clear();
        m_sout.clear();
        m_suffix.clear();
        return parser::make_END(); // error or eof
    }
    return parser::make_END_OF_FILES(); // error or eof
}

/**
 * @name get_expr
 * @def const string& Lexer::get_expr() const
 * @brief get regex expression
 * @return const string&
 */
const string& Lexer::get_expr() const
{
    return m_expr;
}

/**
 * @name  print_token
 * @def   void Lexer::print_token(int id)
 * @brief print token to stdout
 * @param unsigned long id
 */
void Lexer::print_token(unsigned long id)
{
    const token *ptoken = &g_tokens[id];
    cout << "TOKEN={" << setw(5) << left << "\n\t id: "
            << setw(10) << right << id << setw(5) << left
            << "\n\t name: " << setw(10) << right << ptoken->name << setw(5) << left
            << "\n\t stype: " << setw(10) << right
            << "\n\t rexp: " << setw(10) << right << ptoken->rexp << setw(5) << left << setw(10) << right << "\n}\n";
}

/**
 * @name is_id
 * @def bool Lexer::is_id( const token_def& token, const int& id )
 * @param token
 * @param id
 * @return
 */
bool Lexer::is_id( const token_def& token, const unsigned long& id )
{
       // return (token.id == id);
    return true;
}

/**
 * @name  set_context
 * @def   set_context(string& current_input)
 * @param string& current_input
 * @return void
 */
void Lexer::set_context(string& current_input)
{
    // reinit get_token iterators
    m_rexp = boost::regex( m_expr, boost::regex::extended  );
    m_text = current_input;
    m_begin = boost::sregex_iterator( m_text.begin( ), m_text.end( ), m_rexp );
    m_piter = &m_begin;
    m_end = boost::sregex_iterator();
}
