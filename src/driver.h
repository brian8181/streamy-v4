/**
 * @file driver.hpp
 * @brief Header file for driver.cpp
 * @author Your Name
 * @version 1.0
 * @date 2024-06-01
 */
#ifndef SCANNER_HPP_
#define SCANNER_HPP_


#include "../build/pparser.tab.hh"
#include "singleton.h"

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
 * @return
 */
//int yylex ();

/**
 * @brief
 * @param
 */
//void yyerror (char const *);

//#define lex yylex
//yy::parser parser;

//typedef yy::parser parser;
typedef yy::parser::symbol_type sym_t;
sym_t lex();



#endif // _SCANNER_HPP_
