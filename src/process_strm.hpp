/**
 * @file    process_strm.hpp
 * @version 0.0.1
 * @date    Fri, 26 Sep 2025 17:05:10 +0000
 */
#ifndef PROCESS_STRM_HPP_
#define PROCESS_STRM_HPP_

#include <boost/regex.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>

#ifdef BOOST_MSVC
#pragma warning(disable : 4512 4244)
#endif

#include <boost/program_options.hpp>

namespace po = boost::program_options;

// typedef lexstrm
// {

// 	deque<string> deq;
// }

/**
 * @name process_stream
 */
void process_stream(std::istream &is);

/**
 * @name process_file
 */
void process_file(const std::string &name);

/**
 * @name process_files
 */
int process_files(int argc, char *argv[]);

#endif
