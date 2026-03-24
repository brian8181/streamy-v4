/*
 * @file Name:  ./driver.cpp
 * @date: Thu, Sep 11, 2025  4:06:25 PM
 * @version:    0.0.1
 */

#include <iostream>
#include <cstring>
#include <unistd.h>         /* for STDIN_FILENO */
#include <sys/select.h>     /* for pselect   */
#include <string>
#include <getopt.h>
#include <set>
#include "driver.h"
#include "Lexer.hpp"
#include "config.hpp"
#include "bash_color.h"
#include "pparser.tab.hh"

using std::cout;
using std::cerr;
using std::endl;
using std::string;

constexpr int SRC_IDX_OFFSET = 0;
constexpr int CONFIG_IDX_OFFSET = 0;

static string g_config_file;
static string g_input_file;
static string g_output_file;
static bool file_flag = false;
static bool output_file_flag = false;
static bool dump_flag = false;
static bool verbose_flag = false;

// create parser & lexer
static yy::parser yyparser;

/**
 * @name lex
 * @return yy::parser::symbol_type
 */
yy::parser::symbol_type lex()
{
    return Lexer::instance().get_token();
}

/**
 * @brief parse command line options
 * @param argc
 * @param argv
 * @return
 */
int parse_options(const int argc, char* argv[])
{
    int option;
    const auto options_string = "hVdf:o:v";
    const struct option long_options[] = {
        {"help",        no_argument, nullptr,   'h'},
        {"version",     no_argument, nullptr,   'V'},
        {"file",        0, nullptr,   'f'},
        {"out",        0, nullptr,   'o'},
        {"dump",        no_argument, nullptr,   'd'},
        {"verbose",        no_argument, nullptr,   'v'},
        {nullptr,          0, nullptr,    0 }
    };

    while ((option = getopt_long(argc, argv, options_string, long_options, nullptr)) != -1)
    {
        switch (option)
        {
            case 'h':
                cout << "Help message" << endl;
                return 0;
            case 'V':
                cout << "Version 0.0.1" << endl;
                return 0;
             case 'f':
                file_flag = true;
                g_config_file = optarg;
                break;
            case 'o':
                output_file_flag = true;
                g_output_file = optarg;
                break;
            case 'd':
                dump_flag = true;
                break;
            case 'v':
                verbose_flag = true;
                break;
            default:
                cerr << "Unknown option: " << option << endl;
                return 1;
        }
    }

    //test
    // symbol_table["x"] = "1";
    // symbol_table["y"] = "2";
    // symbol_table["z"] = "3";

    // configure driver ...
    string config_file = file_flag ? g_config_file : ".config/default.txt";
    if( argc > (optind + CONFIG_IDX_OFFSET) )
        config_file = argv[optind + CONFIG_IDX_OFFSET];
    cout << FMT_FG_BLUE << "load configuration file=\"" << FMT_RESET
         << FMT_FG_GREEN << FMT_ITALIC <<  config_file << "\"" << FMT_RESET << endl;

    // input file ...
    const string input_file = argv[optind + SRC_IDX_OFFSET];
    cout << FMT_FG_BLUE << "input files=\"" << FMT_RESET
         << FMT_FG_GREEN << FMT_ITALIC <<  input_file << "\"" << FMT_RESET << endl;

    g_config_file = config_file;
    g_input_file = input_file;

    Lexer::instance().init(config_file, &yyparser, input_file, "test/a.txt");
    if (dump_flag)
    {
        cout << "dumping configuration ... " << endl;
        Lexer::instance().dump_config();
        cout << Lexer::instance().get_expr() << endl;
        cout << "configuration dumped." << endl;
    }
    cout << "start scan ..." << endl;
    yyparser.parse();
    cout << "finished scanning. " << endl;

    return 0;
}

/**
 * @brief  stdin_ready function
 * @param filedes
 * @param  int filedes : the file handle
 * @return ready or error code
 */
int stdin_ready (int filedes)
{
        fd_set set;
        // declare/initialize zero timeout
#ifndef CYGWIN
        struct timespec timeout = { .tv_sec = 0 };
#else
        timeval timeout = { .tv_sec = 0 };
#endif
        // initialize the file descriptor set
        FD_ZERO(&set);
        FD_SET(filedes, &set);
        // check stdin_ready is ready on filedes
#ifndef CYGWIN
        return pselect(filedes + 1, &set, NULL, NULL, &timeout, NULL);
#else
        return select(filedes + 1, &set, nullptr, nullptr, &timeout);
#endif
}

/**
 * @brief main function
 * @param argc : param count in argv
 * @param argv : command line parameters
 * @return 0 success : or error
 */
int main(int argc, char* argv[])
{
	try
	{
		char* argv_cpy[ sizeof(char*) * argc + 1 ];
		if(stdin_ready(STDIN_FILENO))
		{
			std::string buffer;
			std::cin >> buffer;
			memcpy(argv_cpy, argv, sizeof(char*) * argc);
			argv_cpy[argc] = &buffer[0];
			++argc;
			return parse_options(argc, argv_cpy);
		}
		return parse_options(argc, argv);
	}
	catch(std::runtime_error& ex)
	{
	 	std::cout << ex.what() << std::endl;
		std::exit(-1);
	}
	catch(std::logic_error& ex)
	{
		std::cout << ex.what() << std::endl;
		std::exit(-1);
	}
}

#ifdef BISON_BRIDGE

#include <ctype.h>
#include <stdlib.h>
#define NUM 1
#define YYEOF 0

char* yylval;
int yyparse();

/**
 * @brief
 * @param
 * @return
 */
int yylex (void)
{
    int c = getchar ();
    /* skip white space */
    while (c == ' ' || c == '\t')
        c = getchar ();
    /* Process numbers. */
    if (c == '.' || isdigit (c))
    {
        ungetc (c, stdin);
        if (scanf ("%lf", &yylval) != 1)
            abort ();
        return NUM;
    }
    /* return end-of-input */
    else if (c == EOF)
        return YYEOF;
    /* return a single char */
    else
        return c;
}

/**
 * @brief
 * @param
 */
// void yyerror (char const *s)
// {
//     printf("%s\n", s);
// }


/**
 * @brief main function
 * @param argc : param count in argv
 * @param argv : command line parameters
 * @return 0 success : or error
 */

int __main(int argc, char* argv[])
{
    return yyparse();
}

#endif
