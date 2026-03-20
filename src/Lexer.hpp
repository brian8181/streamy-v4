/**
 * @file    Lexer.hpp
 * @version 0.0.1
 * @date    Fri, 26 Sep 2025 17:05:10 +0000
 */
#ifndef Lexer_HPP_
#define Lexer_HPP_

#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <regex>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <boost/regex.hpp>
#include "../streamy-v4/build/pparser.tab.hh"

using std::string;
using std::vector;
using std::list;
using std::map;
using std::pair;
using std::regex;
using std::stringstream;
using yy::parser;

#define INT 1
#define FLOAT 2

typedef struct token_def
{
	string name;
	string stype;
	string rexp;
} token_def;

typedef token_def token;

struct token_match
{
	unsigned long id;
	int pos;
	int line;
	string value;
	token_def* token;
};

typedef struct state_t
{
	unsigned long id;
	string name;
} state_t;

typedef struct context_t
{
	std::string&               scan_file;
	std::string&               search_text;
	boost::regex&              rexp;
	boost::sregex_iterator&    begin;
	boost::sregex_iterator&    end;
	boost::sregex_iterator*    p_iter;
	state_t*                   state;
	string&                    expr;
	vector<token_def*>*        matches;
} context_t;

const string TOKEN_TYPE           = R"([A-Za-z][A-Za-z_]*((::)[A-Za-z_]*)?)";
const string TOKEN_TYPE_          = R"([A-Za-z][A-Za-z_]*)";
const string VALID_SYMBOL_CHARS   = R"([A-Za-z0-9_])"; /** @note_to_self: ~~> \w == [A-Za-z0-9_] **/
const string VALID_CHARS          = R"([[:punct:][:alnum:]])"; // [:punct:] = !"#$%&'()*+,-./:;<=>?@[\]^_{|}~`);
const string CONFIG_STATES        = R"((?<states>^\s*(?<state>[A-Za-z][A-Za-z0-9_]*)\s*=\s*\s*\{(?<tokens>[A-Za-z][A-Za-z0-9_]*(, [A-Za-z][A-Za-z0-9_]*)*)\}\s*\s*$))";
const string CONFIG_SECTIONS      = R"(^\s*\[\s*(?<tokens>tokens)|(?<groups>groups)|(?<states>states)\s*\]\s*$)";
const string CONFIG_PAIR          = R"(\s*(?<type>" + TOKEN_TYPE_ + ")\\s+(?<name>[A-Za-z])" + VALID_SYMBOL_CHARS + R"("*)\\s*=\\s*(?<rexp>)" + VALID_CHARS + R"(*)\s*\"(?<test>.*)\"\s*)";
const string CONFIG_COMMENT       = R"(^\s*#.*$)";
const string CONFIG               = R"((?<pairs>)" + CONFIG_PAIR + R"()|(?<comments>)" + CONFIG_COMMENT + R"())";

/**
  * @brief class Lexer
  */
class Lexer final
{
public:
    /**
 * @name  Lexer
 * @def   Lexer()
 * @brief default ctor
 */
Lexer();

/**
 * @name   load_config
 * @def    void load_config( const string &file )
 * @brief  load_config: load configuration from file
 * @param  const string& file
 * @return void
 */
void load_config( const string& file );

/**
 * @name   dump_config
 * @brief  void dump_config( const string& file ) const
 * @param  const string& file
 * @return void
 */
void dump_config( const string& file ) const;

/**
 * @name   dump_config
 * @def    void dump_config( ) const
 * @brief  dump current config
 * @return void
 */
void dump_config( ) const;

/**
 * @name   init
 * @def    void init(const string &config_file, parser* pparser, const string& input_file, const string& output_file)
 * @brief  initialize state
 * @return bool
 */
void init(const string &config_file, parser* pparser, const string& input_file, const string& output_file);

/**
* @name   get_state
* @brief  state_t *get_state() const
* @return state_t
*/
state_t *get_state() const;

/**
 * @name   set_state
 * @brief  void set_state(state_t* pstate)
 * @param  state_t* pstate
 * @return void
 */
void set_state(state_t* pstate);

/**
 * @name   get_token
 * @def    parser::symbol_type get_token()
 * @return int
 */
parser::symbol_type get_token();

/**
 * @name reset
 * @def  void reset()
 */
void reset();

/**
 * @name   get_expr
 * @def    const string& get_expr() const
 * @brief  get regex expression
 * @return const string&
 */
const string& get_expr() const;

/**
 * @name build_expr
 * @def  void build_expr()
 */
void build_expr();

/**
 * @name  print_token
 * @def   void print_token(int id)
 * @brief print token to stdout
 * @param int id
 */
void print_token(unsigned long id);

/**
 * @name   is_id
 * @def    bool is_id( const token_def& token, const int& id )
 * @param  const token_def& token
 * @param  const unsigned long& id
 * @return bool
 */
bool is_id( const token_def& token, const unsigned long& id );

	/**
	 *
	 */
	void set_context(string& current_input);

/**
 * @name   on_state
 * @param  state_t* pstate
 * @return bool
 */
inline unsigned long on_state(state_t* pstate);

/**
 * @name  on_token
 * @brief override virtual, on_token, for each token ...
 * @param token_def* token
 */
inline parser::symbol_type on_token( token_match* ptoken );

protected:
	parser*                                     m_pparser;
	string                                      m_config_file;
    string                                      m_input_file;
    string                                      m_output_file;
	vector<token_def*>                          m_tokens;
	map<unsigned long, token_def*>              m_idx_tab;  // idx  -> token_def
	map<unsigned long, token_def*>              m_id_tab;   // id   -> token_def
	map<string, token_def*>                     m_name_tab; // name -> token_def
	vector<token_match*>                        m_matches;

	string                                      m_text;
	boost::regex                                m_rexp;
	boost::sregex_iterator                      m_begin;
	boost::sregex_iterator                      m_end;
	boost::sregex_iterator*                     m_piter;
  	int                                         m_pos;
	int                                         m_len;

	string                                      m_expr;
    string                                      m_str;
    string                                      m_prefix;
    string                                      m_suffix;
	stringstream                                m_sout;
	//stack<string>                               filestack;
};

#endif
