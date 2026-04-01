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

#endif // _SCANNER_HPP_
