/**
 * @file    lexer.hpp
 * @version 0.0.1
 * @date    Fri, 26 Sep 2025 17:05:10
 */
#ifndef _LEXER_HPP_
#define _LEXER_HPP_

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
#include "fileio.hpp"
#include "definitions.hpp"
#include "pparser.tab.hpp"

using std::list;
using std::map;
using std::fstream;
using std::pair;
using std::string;
using std::stringstream;
using std::vector;
using std::stack;
using yy::parser;

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
	 * @name   load_config
	 * @param  const string& file
	 * @return void
	 */
	void load_config( const string& file );

	/**
	 * @name  init
	 * @brief initialize input
	 * @param argc, input file count
	 * @param argv, onst char* file names
	 * @return void
	 */
	bool init(const int argc, char* argv[]);

	/**
	 * @name   next_file
	 * @brief  moves lexer to next file
	 * @return bool
	 */
	bool next_file();

	/**
	 * @name   set_state
	 * @brief  void set_state(state_t* pstate)
	 * @return void
	 */
	void set_state(state_t *pstate);

	/**
	 * @name get_current_infile
	 * @param string& in_name
	 * @return void
	 */
	inline void get_current_infile( string& in_name )
	{
		in_name = m_ifile;
	}

	/**
	 * @name get_current_outfile
	 * @param string& out_name
	 * @return void
	 */
	inline void get_current_outfile( string& out_name )
	{
		out_name = m_ofile;
	}

	/**
	 * @name get_stack
	 */
	stack<string>& get_stack();

	/**
	 * @name  push_include
	 * @brief prepends current buffer with include contents
	 */
	void push_include(const string& file);

	/**
	 * @name   get_token
	 * @return int
	 */
	parser::symbol_type get_token();

	/**
	 * @name  on_token
	 * @brief override virtual, on_token, for each token ...
	 * @param unsigned long id
	 * @param string match: current match
	 * @return parser::symbol_type
	 */
	parser::symbol_type on_token( unsigned long id, const string& match = {} );

	/**
	 * @name read_istream
	 * @return int
	 */
	void read_istream( const string& file, string& s );

	/**
	 * @name read_istream
	 * @brief read input file into string object
	 */
	void read_istream(const string& file, char* cstr);

	/**
	 * @name   write_stream
	 * @return int
	 */
	inline void write_ostream( const string &s )
	{
		m_fstream << s;
	}

	/**
	 * @name   dump output stream
	 * @return int
	 */
	inline void dump_ostream( const string& in )
	{

	}

	/**
	 * @name  print_token
	 * @brief print token to stdout
	 * @param token_match m
	 */
	void print_token(const token *tval);

private:

	// typedef struct context_t
	// {
	// 	string regex_str;
	// 	string search;
	// 	string match;
	// 	string prefix;
	// 	string suffix;
	// 	long pos;
	// 	string buffer;
	// 	boost::regex rexp;
	// 	boost::sregex_iterator iter;
	// 	boost::sregex_iterator end;
	// 	boost::smatch* p_smatch;
	// } context_t;
	// context_t* p_context;

	//configuration types
	vector<token_t> m_tokens;
	map<unsigned long, token> m_tok_map;
	vector<state_t> m_states;

	int m_i = 0;
	int m_argc;
	char** m_argv;

	vector<string> m_input_paths;
	bool EOFS;
	string m_ifile;
	string m_ofile = "build/a.out";

	stack<string> include_stack;

	string m_regex_str;
	string m_buffer;
	string m_match;
	fstream m_fstream;
	int m_line;
	int m_file_count;
	state_t *p_state = &INITIAL;
	stringstream g_stringstream;
};

#endif
