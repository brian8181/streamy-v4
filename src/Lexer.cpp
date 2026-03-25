
/**
 * @file    lexer.cpp
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
#include "lexer.hpp"
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
 * @brief global state_t state
 * @name gp_state
 */
inline state_t* gp_state = &sINITIAL;


/**
 * @name init
 * @def void lexer::init(const string &config_file, parser* pparser,
 *      const string& input_file, const string& output_file)
 * @brief  initialize state
 * @return bool
 */
void lexer::init(const string &config_file, parser* pparser, const string& input_file, const string& output_file)
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
 * @def void lexer::reset()
 */
void lexer::reset()
{
    init(m_config_file, m_pparser, m_input_file, m_output_file);
}

/**
 * @name load_config
 * @def void lexer::load_config( const string &file )
 * @brief  load_config: load configuration from file
 * @param  const string& file
 * @return void
 */
void lexer::load_config( const string& file )
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
 * @brief void lexer::dump_config( const string& file ) const
 * @param const string& file
 * @return void
 */
void lexer::dump_config( const string& file ) const
{
    dump_config( );
}

/**
 * @name dump_config
 * @def void lexer::dump_config( ) const
 * @brief  dump current config
 * @return void
 */
void lexer::dump_config( ) const
{
    // bkp todo, not what I would call a good dump ...
    cout << "config_file: " << m_config_file << endl;
    cout << "input file: " << m_input_file << endl;
    cout << "input text: " << m_text << endl;
    cout << "regexp: " << m_expr << endl;
    cout << "state: " << gp_state->name << endl;
}

/**
* @name get_state
* @brief state_t *lexer::get_state() const
* @return state_t
*/
state_t *lexer::get_state() const
{
    return gp_state;
}

/**
 * @name set_state
 * @brief void lexer::set_state(state_t* pstate)
 * @param state_t* pstate
 * @return void
 */
void lexer::set_state(state_t* pstate)
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

// /**
//  * @name   get_remaining
//  * @brief  get remaining input
//  * @param  string& s
//  * @return void
//  */
// inline string* lexer::get_remaining()
// {
// 	return &m_suffix;
// }


// /**
//  * @name   set_remaining
//  * @brief  set remaining input
//  * @param  const string& s
//  * @return void
//  */
// void lexer::set_remaining(const string& s)
// {
//     m_suffix.clear();
//     m_suffix = s;
// }

// /**
//  * @name   get_include_buffer
//  * @brief  get remaining input
//  * @return stringstream*
//  */
// stringstream* lexer::get_include_buffer()
// {
//     m_include_buffer.clear();
//     return &m_include_buffer;
// }

/**
 * @name  get_token
 * @def parser::symbol_type lexer::get_token()
 * @return int
 */
parser::symbol_type lexer::get_token()
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
 * @def const string& lexer::get_expr() const
 * @brief get regex expression
 * @return const string&
 */
const string& lexer::get_expr() const
{
    return m_expr;
}

/**
 * @name  print_token
 * @def   void lexer::print_token(int id)
 * @brief print token to stdout
 * @param unsigned long id
 */
void lexer::print_token(unsigned long id)
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
 * @def bool lexer::is_id( const token_def& token, const int& id )
 * @param token
 * @param id
 * @return
 */
bool lexer::is_id( const token_def& token, const unsigned long& id )
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
void lexer::set_context(string& current_input)
{
    // reinit get_token iterators
    m_rexp = boost::regex( m_expr, boost::regex::extended  );
    m_text = current_input;
    m_begin = boost::sregex_iterator( m_text.begin( ), m_text.end( ), m_rexp );
    m_piter = &m_begin;
    m_end = boost::sregex_iterator();
}

/**
 * @name g_stringstream
 */
stringstream g_stringstream;

/**
 * @name lexer::on_state
 * @param state_t* pstate
 * @return unsigned long
 */
inline unsigned long lexer::on_state(state_t *pstate)
{
   return -1;
}

/**
 * @name lexer::on_token
 * @brief override virtual, on_token, for each token ...
 * @param token_def* token
 */
inline parser::symbol_type lexer::on_token( token_match* ptoken )
{
    switch (gp_state->id)
    {
        case UL_INITIAL_STATE:
        {
            switch (ptoken->id)
            {
            case UL_OPEN_BRACE:  /** open brace, ESCAPE */
                set_state(&sESCAPED);
                print_token(ptoken->id);
                m_stream << "{";
                //m_stream << " ~"<< ptoken->value << "~ ";
                return parser::make_OPEN_BRACE();
            case UL_SKIP_TOKEN:
                print_token(ptoken->id);
                cout << "default: SKIP_TOKEN" << endl;
                return parser::make_OPEN_BRACE();
            }
            break;
        }
        case UL_ESCAPED_STATE:
        {
            switch (ptoken->id)
            {
            case UL_CLOSE_BRACE: /** close brace, UNESCAPE */
                set_state(&sINITIAL);
                print_token(ptoken->id);
                m_stream << "}";
                //m_stream << " ~" << ptoken->value << "~ ";
                return parser::make_CLOSE_BRACE();
            case UL_IF:
                set_state(&sIF_BLOCK);
                print_token(ptoken->id);
                return parser::make_IF();
            case UL_DOLLAR_SIGN:
                print_token(ptoken->id);
                m_stream << " ~" << ptoken->value << "~ ";
                return parser::make_DOLLAR_SIGN();
            case UL_PERCENT_SIGN:
                print_token(ptoken->id);
                m_stream << " ~" << ptoken->value << "~ ";
                return parser::make_PERCENT_SIGN();
            case UL_DOT:
                print_token(ptoken->id);
                m_stream << " ~" << ptoken->value << "~ ";
                return parser::make_DOT();
            case UL_HASH_MARK:
                print_token(ptoken->id);
                m_stream << " ~" << ptoken->value << "~ ";
                return parser::make_HASH_MARK();
            case UL_COLON:
                print_token(ptoken->id);
                m_stream << " ~" << ptoken->value << "~ ";
                return parser::make_COLON();
            case UL_COMMA:
                print_token(ptoken->id);
                m_stream << " ~" << ptoken->value << "~ ";
                return parser::make_COMMA();
            case UL_VBAR:
                print_token(ptoken->id);
                m_stream << " ~" << ptoken->value << "~ ";
                return parser::make_VBAR();
            case UL_IDENTIFIER:
                print_token(ptoken->id);
                m_stream << " ~" << ptoken->value << "~ ";
                return parser::make_IDENTIFIER(ptoken->value);
            case UL_EQUAL_SIGN:
                print_token(ptoken->id);
                m_stream << " ~" << ptoken->value << "~ ";
                return parser::make_EQUAL_SIGN();
            case UL_NUMERIC_LITERAL:
                print_token(ptoken->id);
                m_stream << " ~" << ptoken->value << "~ ";
                return parser::make_NUMERIC_LITERAL(ptoken->value);
            case UL_FILE_ATTRIB:
                print_token(ptoken->id);
                m_stream << " ~" << ptoken->value << "~ ";
                return parser::make_FILE_ATTRIB(ptoken->value);
            case UL_INCLUDE: /** INCLUDING */
                //set_state(&sINCLUDING);
                print_token(ptoken->id);
                m_stream << " ~" << ptoken->value << "~ ";
                //goto SKIP;
                return parser::make_INCLUDE(ptoken->value);
            case UL_DOUBLE_QUOTE: /** opening quote, DOUBLE_QUOTE */
                set_state(&sDOUBLE_QUOTED);
                m_stream << " ~" << ptoken->value << "~ ";
            case UL_WHITESPACE:
            case UL_SKIP_TOKEN:
                return parser::make_SKIP_TOKEN();
            }
            break;
        }
        break;
        case UL_IF_BLOCK_STATE:
        {
            switch (ptoken->id)
            {
            case UL_SKIP_TOKEN:
                print_token(ptoken->id);
                cout << "default: SKIP_TOKEN" << endl;
                return parser::make_OPEN_BRACE();
            }
            break;
        }
        break;
        case UL_DOUBLE_QUOTED_STATE:
        {
            switch (ptoken->id)
            {
            case UL_ESC_TAB: /** esc sequences in string literals */
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
            case UL_VALID_CHAR: /** double quote, valid chars for string literal */
                g_stringstream << ptoken->value;
                cout << "char " << g_stringstream.str() << endl;
                return parser::make_SKIP_TOKEN();
            case UL_DOUBLE_QUOTE: /** closing quote, DOUBLE_QUOTE -> ESCAPED **/
            {
                set_state(&sESCAPED);
                string qstr = g_stringstream.str();
                g_stringstream.str("");
                g_stringstream.clear();

                m_stream << qstr  << "\"";
                return parser::make_STRING_LITERAL(qstr);
            }
            case UL_SKIP_TOKEN:
                cout << "SKIP_TOKEN" << endl;
                return parser::make_SKIP_TOKEN();
            }
            break;
        }
        break;
        case UL_INCLUDING_STATE:
        {
            switch (ptoken->id)
            {
                case UL_FILE_ATTRIB:
                {
                    const boost::regex re("file=\"([^\"]*)\"");
                    boost::smatch sm;
                    boost::regex_search(ptoken->value, sm, re);

                    //const int len = m_matches.size();
                    g_tokens[ ptoken->id ];

                    m_include_path.clear();
                    m_include_path = sm[1].str();
                    cout << "file=" << m_include_path << endl;
                    string sout;
                    read_str(m_include_path, sout);
                    //  append include file output to buffer
                    m_include_buffer.clear();
                    m_include_buffer << endl << sout << endl;

                    // set_state(&sESCAPED);
                    // m_stream << m_suffix;
                    return parser::make_SKIP_TOKEN();
                }
                case UL_CLOSE_BRACE:
                {
                    // append suffix after include is inserted/streamed
                    m_include_buffer << m_suffix;
                    // set the suffix a.k.a "current search buffer"
                    m_suffix.clear();
                    m_suffix = m_include_buffer.str();

                    set_state(&sINITIAL);
                    m_stream << "}";
                    //return parser::make_CLOSE_BRACE();
                    return parser::make_SKIP_TOKEN();
                }
                case UL_DOUBLE_QUOTE: /** closing quote, DOUBLE_QUOTE -> ESCAPED */
                    set_state(&sESCAPED);
                    return parser::make_STRING_LITERAL(g_stringstream.str());
                case UL_WHITESPACE:
                    cout << "WHITESPACE : SKIP_TOKEN" << endl;
                    return parser::make_SKIP_TOKEN();
            }
            break;
        }
        break;
        default:
        {
            cout << "ERROR:" << ptoken->id << endl;
            break;
        }
    }

    return parser::make_END();
}
