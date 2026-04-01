/*
 * @file Name:  ./driver.cpp
 * @date: Thu, Sep 11, 2025  4:06:25 PM
 * @version:    0.0.1
 */

#include <iostream>
#include <cstring>
#include <unistd.h>         /* for STDIN_FILENO */
#if defined(_WIN32)
    // Windows-specific code (e.g., MSYS2 UCRT64)
    #include <winsock2.h>
#elif defined(__linux__)
    // Linux-specific code (e.g., Fedora, Ubuntu)
    #include <sys/select.h>
#elif defined(__unix__)
    // Other Unix-like systems (e.g., BSD, macOS)
    #include <sys/select.h>
#endif
#include <string>
#include <getopt.h>
#include <set>
#include "bash_color.hpp"
#include "config.hpp"
#include "driver.h"
#include "lexer.hpp"
#include "pparser.tab.hh"

using std::cout;
using std::cerr;
using std::endl;
using std::string;

constexpr int SRC_IDX_OFFSET = 0;
constexpr int CONFIG_IDX_OFFSET = 0;

static string g_config_file = "default.conf";
static string g_output_file = "out.txt";
static string g_input_file = "in.txt";

static bool config_flag = false;
static bool output_file_flag = false;
static bool dump_flag = false;
static bool verbose_flag = false;

// create parser & lexer
static yy::parser yyparser;

#define DEBUGG
#ifdef DEBUGG
#define LOGG // cout << "test" << endl;
#else 
#define LOGG cout << "test" << endl;
#endif


/**
 * @name lex
 * @return yy::parser::symbol_type
 */
yy::parser::symbol_type lex()
{
    TRACE
    return lexer::instance().get_token();
}

/**
 * @brief parse command line options
 * @param argc
 * @param argv
 * @return
 */
int parse_options(const int argc, char* argv[])
{
    TRACE
    
    int option;
    const auto options_string = "hVdc:o:v";
    const struct option long_options[] = {
        {"help",        no_argument, nullptr,   'h'},
        {"version",     no_argument, nullptr,   'V'},
        {"config",        0, nullptr,   'c'},
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
             case 'c':
                config_flag = true;
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

    int offset = optind + SRC_IDX_OFFSET;
    for(int i = offset; i < argc; ++i)
    {
        TRACE
        g_input_file = argv[optind + SRC_IDX_OFFSET];
        LOG("ATTENSION: ", FMT_FG_RED, "scannning file:\"" << g_input_file << "\"");

        stringstream log;
        log << "in:\"" << g_input_file
            << "\" - out:\"" << g_output_file
            << "\" - conf:\"" << g_config_file << "\"" << endl;
        LOG("ATTENSION: ", FMT_FG_RED ,log.str());

        lexer::instance().init(g_config_file, &yyparser, g_input_file, g_output_file);
        if (dump_flag)
        {
            cout << "dumping configuration ... " << endl;
            lexer::instance().dump_config();
            cout << lexer::instance().get_expr() << endl;
            cout << "configuration dumped." << endl;
        }
        yyparser.parse();
        LOG("ATTENSION: ", FMT_FG_RED, "finished file:\"" << g_input_file << "\"");
    }
    TRACE
    INFO("EOFS");
    return 0;
}

#ifndef _WIN32
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
#endif

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
        #ifndef _WIN32
		TRACE
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
        #endif
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
