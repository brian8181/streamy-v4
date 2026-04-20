
/**
 * @file    lexer.cpp
 * @version 0.0.1
 * @date    Fri, 26 Sep 2025 17:05:10
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
#include "fileio.hpp"
#include "lexer.hpp"
#include "driver.hpp"
#include "utility.hpp"
#include "bash_color.hpp"
#include "log.hpp"

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
            m_tokens.push_back(*ptoken);
            m_tok_map[ptoken->index] = *ptoken;
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
            unsigned long state_id = 0xFFul | (++i * 6ul); // generate id for new state
            state_t stat{state_id, str_state};             // create new state
            m_states.push_back(stat);

            // copy to term to vector
            vector<token_t> tokens;           // token vector for this state
            std::stringstream ss(str_tokens); // csv of states
            std::string str_token;            // item in csv states

            // use get line to split on commas
            while (std::getline(ss, str_token, ','))
            {
                token_t ptoken;
                m_tokens.push_back(ptoken);
            }
        }
    }
}

/**
 * @name   init
 * @def    void lexer::init(const string &config_file, const string& input_file, string& output_file)
 * @brief  initialize state
 * @return bool
 */
void lexer::init(string in, string out)
{
    read_str(in, m_buffer, std::ios::in);
    // set state
    set_state_flag(&INITIAL);
    m_fstream.open(out, std::ios_base::out | std::ios::trunc);
    m_line = 0;
	cout << FMT_FG_LIGHT_YELLOW << "initialized buffer - [ \"" << esc_nl( m_buffer, "\\n" ).get_val() << "\" ]" << FMT_ITALIC << "line:" << __LINE__ << FMT_RESET << endl;
}

/**
 * @ set_istream
 */
void lexer::set_istream( const string& in )
{
	m_ifile = in;
}

/**
 * @ set_istream
 */
void lexer::set_ostream( const string& out )
{
	m_ofile = out;
}

/**
 * @name   set_state_flag
 * @brief  void lexer::set_state_flag(state_t* pstate)
 * @return void
 */
void lexer::set_state_flag(state_t *pstate)
{
	ATTN("Enter set_state ~ " << p_state->id << ":" << p_state->name << " ~~> " << pstate->id << ":" << pstate->name);
	p_state = pstate;
	// just update for now
	stringstream ss;
	const vector<unsigned long>* STATE_TOKENS = g_state_tokens[p_state->id];
	const unsigned long len = STATE_TOKENS->size();

	for( unsigned long i = 0; i < len; i++ )
	{
		unsigned long id = ( *STATE_TOKENS )[i];
		token_t* ptoken = &g_tokens[id];

		stringstream rstr;
		rstr << "R\"(" << ptoken->rexp << ")\"";
		stringstream info;
		info << std::left << "#" << i << "   "
			<< "id:   " << std::setw( 4 ) << std::right << id
			<< "    ~    " << std::right << "idx: " << std::setw( 3 ) << std::left << ptoken->index
			<< "    ~    " << std::left << "name: " << std::setw( 18 ) << std::left << ptoken->name
			<< "    ~    " << std::left << "type: " << std::setw( 10 ) << ptoken->stype
			<< "    ~    " << std::left << "regex: " << std::left << std::setw( 44 ) << rstr.str() << std::right;

		cout << ( ( i % 2 ) ? FMT_BG_BLACK : FMT_BG_DARK_GREY ) << FMT_FG_LIGHT_YELLOW
			<< info.str() << FMT_ITALIC << FMT_RESET << endl;

	//  ss << "(?<" << ptoken->name << ">)" << ptoken->rexp << ")|";
		ss << "(" << ptoken->rexp << ")|";
	}
	// save expression string ...
	m_regex_str = ss.str();
	m_regex_str.pop_back(); // remove extra '|' i.e. "V-BAR"
	ATTN( "Exit set_state ~ " << p_state->id << ":" << p_state->name );
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
	if( m_buffer.empty() )
	{
		ATTN("END_OF_FILE");
		return parser::make_END_OF_FILE();
	}

	auto rexp = boost::regex( m_regex_str, boost::regex::extended );
	auto iter = boost::sregex_iterator( m_buffer.begin(), m_buffer.end(), rexp );
	auto end = boost::sregex_iterator();
	boost::smatch m(*iter);
	string match = m.str();
	const size_t len = m.size();

	if (iter != end)
    {
        for (int i = 1; i < len; ++i)
        {
			if( m.operator[](i).matched )
            {
                if (m.prefix().matched)
                {
                    if (p_state->id != UL_INITIAL)
                        return parser::make_YYerror();
                    m_fstream << m.prefix(); // stream prefix (unescaped text)
                }
                // get match : by sub_match index (i)
                unsigned long id = (*g_state_tokens[p_state->id])[i - 1];
                token_t token = g_tokens[id];

				INFO("match.pos:" << m.position() << " - match.sz:" << m.str().size() << " - prefix.sz:" << m.prefix().str().size() << " - suffix.sz:" << m.suffix().str().size());
				INFO("match[" << "i=" << i << "] = " << token.name \
													 <<          "[ " << FMT_RESET << FMT_FG_WHITE << "\"" << esc_nl(m.str()).get_val()    << "\"" << FMT_RESET << FMT_ITALIC << FMT_FG_GREEN << "]" \
													 << " - prefix[ " << FMT_RESET << FMT_FG_WHITE << "\"" << esc_nl(m.prefix()).get_val() << "\"" << FMT_RESET << FMT_ITALIC << FMT_FG_GREEN << "]" \
													 << " - suffix[ " << FMT_RESET << FMT_FG_WHITE << "\"" << esc_nl(m.suffix()).get_val() << "\"" << FMT_RESET << FMT_ITALIC << FMT_FG_GREEN << "]");
				// set buffer to suffix
				m_buffer = m.suffix();
				return on_token(id, match);
            }
        }
		return parser::make_YYerror(); // no sub match?, should not happen
    }
    else if(!m_buffer.empty())
    {
		ATTN("ITER == end & buffer not empty");
        m_fstream << m_buffer;
        m_fstream.flush();
        m_fstream.close();
    }
	ATTN( "END_OF_FILE" );
    return parser::make_END_OF_FILE();
}

/**
 * @name  on_token
 * @brief override virtual, on_token, for each token ...
 * @param unsigned long id
 * @param string match: current match
 * @return parser::symbol_type
 */
parser::symbol_type lexer::on_token( unsigned long id, const string& match )
{
    switch (p_state->id)
    {
    case UL_INITIAL:
    {
        switch (id)
        {
        case OPEN_BRACE:
            set_state_flag(&ESCAPED);
            return parser::make_OPEN_BRACE();
        case COMMENT:
            return parser::make_SKIP_TOKEN();
        case NEWLINE:
            m_line++;
            m_fstream << '\n';
            return get_token();
        case SKIP_TOK:
            return get_token();
        default:;
        } // END switch
        break;
    } // END case UL_INITIAL
    case UL_ESCAPED:
    {
        switch (id)
        {
        case CLOSE_BRACE:
            set_state_flag(&INITIAL);
            return parser::make_CLOSE_BRACE();
        case IF:
            set_state_flag(&IF_BLOCK);
            return parser::make_IF();
        case SYMBOL:
            return parser::make_SYMBOL(match);
        case CONST_SYMBOL:
            return parser::make_CONST_SYMBOL(match);
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
            return parser::make_CAPITALIZE(match);
        case TRUNCATE:
            return parser::make_TRUNCATE(match);
        case STRIP:
            return parser::make_STRIP(match);
        case EQUAL_SIGN:
            return parser::make_EQUAL_SIGN();
        case NUMERIC_LITERAL:
            return parser::make_NUMERIC_LITERAL(match);
        case FILE_ATTRIB:
            return parser::make_FILE_ATTRIB(match);
        case INCLUDE:
            return parser::make_INCLUDE(match);
        case ASSIGN:
            return parser::make_ASSIGN(match);
        case DOUBLE_QUOTE:
            set_state_flag(&DOUBLE_QUOTED); // fallthrough
        case WHITESPACE:                    // fallthrough
        case SKIP_TOK:
            return get_token();
        default:;
        } // END switch
        break;
    } // CASE UL_ESCAPED
	case UL_IF_BLOCK:
	{
		INFO( "switch case: IF_BLOCK_STATE" );
		switch( id )
		{
		case SKIP_TOK:
			//return parser::make_OPEN_BRACE();
		default:;
		}
		break;
	} // CASE UL_IF_BLOCK_STATE
	case UL_DOUBLE_QUOTED:
	{
		INFO( "switch case: DOUBLE_QUOTED_STATE" );
		switch( id )
		{
		case ESC_TAB:
			g_stringstream << "\t";
			return get_token();
		case ESC_BACKSLASH:
			g_stringstream << "\\";
			return get_token();
		case ESC_DOUBLE_QUOTE:
			g_stringstream << "\"";
			return get_token();
		case ESC_SINGLE_QUOTE:
			g_stringstream << "'";
			return get_token();
		case VALID_CHAR:
			g_stringstream << match;
			//cout << "char " << g_stringstream.str() << endl;
			return get_token();
		case DOUBLE_QUOTE:
		{
			set_state_flag( &ESCAPED );
			string qstr = g_stringstream.str();
			g_stringstream.str( "" );
			g_stringstream.clear();
			m_fstream << qstr;
			return parser::make_STRING_LITERAL( qstr );
		}
		default:;
		}
		break;
	} // UL_DOUBLE_QUOTED_STATE:
	case UL_INCLUDING:
	{
		INFO( "switch case: INCLUDING_STATE" );
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
	//             m_fstream << "}";
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
	} // UL_INCLUDING_STATE
	} // END switch
	cout << "UNDEFINED symbol found..." << endl;
    return parser::make_UNDEFINED();
}
