/**
 * @file driver.hpp
 * @brief Header file for driver.cpp
 * @author Your Name
 * @version 1.0
 * @date 2024-06-01
 */
#ifndef SCANNER_HPP_
#define SCANNER_HPP_
#define YYDEBUG 1

#include "config.h"
#include "pparser.tab.hh"
#include "log.hpp"
#include "fileio.hpp"

static string g_config_file = "default.conf";
static string g_output_dir = "./test/build";
static string g_output_file = "out.obj";
static string g_input_file = "in.txt";

// bkp todo
// class context
// {
//     context(string& input, string& output, const string& parent);
//     std::string&               conf_path;
// 	std::string&               in_path;
//     std::string&               out_path;
//     std::string&               parent;
//     boost::regex&              rexp;
// 	boost::sregex_iterator&    begin;
// 	boost::sregex_iterator&    end;
// 	boost::sregex_iterator*    p_iter;
// 	//state_t*                   state;
//     string&                    all_text;
//     string&                    remaining_text;
// 	string&                    expr;
//     string&                    prefix;
//     string&                    suffix;
// 	//vector<token_def*>*        matches;
// };


/**
 * @brief parse command line options
 * @param argc
 * @param argv
 * @return
 */
int parse_options(int argc, char* argv[]);

/**
 * @brief check if stdin is ready for reading
 * @param filedes
 * @return
 */
int stdin_ready (int filedes);

/**
 * @brief driver entry point for the application
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char* argv[]);

/**
 * @brief
 * @param
 */
//void yyerror (char const *);
//#define lex yylex

yy::parser::symbol_type lex();

#endif // SCANNER_HPP_
