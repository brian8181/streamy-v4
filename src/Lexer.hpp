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
	 * @param unsigned long id
	 * @return parser::symbol_type
	 */
	//inline parser::symbol_type on_token(unsigned long id);

		/**
	 * @name  on_token
	 * @brief override virtual, on_token, for each token ...
	 * @param unsigned long id
	 * @param string match: current match
	 * @return parser::symbol_type
	 */
	parser::symbol_type on_token( unsigned long id, const string& match = {} );

	/**
	 * @name   write_stream
	 * @return int
	 */
	inline void write_ostream(const string &s)
	{
		m_fstream << s;
	}

		/**
	 * @name   dump output stream
	 * @return int
	 */
	inline void dump_ostream(const string& in)
	{
		string buffer;
		read_str( in, buffer, std::ios::in );
		std::cout << buffer;
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

	string m_regex_str;
	string m_buffer;
	string m_match;
	fstream m_fstream;
	int m_line;
	state_t *p_state = &INITIAL;
};

#endif
