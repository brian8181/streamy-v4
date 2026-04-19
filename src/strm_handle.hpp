/**
 * @file    strm_handle.hpp
 * @version 0.0.1
 * @date    Sat, 18 Apr 2026 08:03:45 +0000
 * @info    ...
 */
#ifndef _strm_handle_HPP_
#define _strm_handle_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <boost/regex.hpp>
#include <boost/program_options.hpp>

#ifdef BOOST_MSVC
#pragma warning(disable : 4512 4244)
#endif



namespace po = boost::program_options;

/**
  * @brief class strm_handle
  */
class strm_handle
{
public:
	/**
	* @brief : default ctor
	*/
	strm_handle() = default;

		/**
	* @brief : copy ctor
	*/
	strm_handle( const strm_handle& src ) = default;

		/**
	* @brief : destructor
	*/
	~strm_handle() = default;

	/**
	 * @name process_stream
	 */
	void process_stream( std::istream& is );

	/**
	 * @name process_file
	 */
	void process_file( const std::string& name );

	/**
	 * @name process_files
	 */
	int process_files( int argc, char* argv[] );
private:
	string m_rexp_str;
};

#endif
