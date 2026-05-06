#include <boost/regex.hpp>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "bash_color.hpp"
#include "lexer.hpp"
#include "log.hpp"


#ifdef BOOST_MSVC
#pragma warning(disable : 4512 4244)
#endif

#include <boost/program_options.hpp>
#include <boost/regex.hpp>

using std::string;
using std::stringstream;
using std::vector;

namespace po = boost::program_options;

//string rexp_str;

/**
 * @name process_stream
 */
void process_stream(std::istream &is)
{
    // std::string line;
    // int match_found = 0;
    // int linenum = 1;

	// stringstream ss;
	// const vector<unsigned long>* STATE_TOKENS = g_state_tokens[p_state->id];
	// const unsigned long len = STATE_TOKENS->size();


    // while (std::getline(is, line))
    // {
	// 	// boost::match_flag_type flags = boost::match_default;
	// 	// boost::regex_constants::syntax_option_type flags = boost::regex_constants::basic;
	// 	boost::smatch what;
	// 	boost::regex re(rexp_str);

	// 	std::string::const_iterator start, end;
	// 	start = line.begin();
	// 	end = line.end();
	// 	boost::match_flag_type flags = boost::match_default;
	// 	boost::match_results<std::string::const_iterator> what;
	// 	while( regex_search( start, end, what, re, boost::match_default ) )
	// 	{
	// 		++linenum;
	// 		std::cout << FMT_FG_MAGENTA << "STREAM @ line -->" << linenum++ << "\t" << line << FMT_RESET << "\n";
	// 		cout << what.prefix << what.str() << what.suffix() <<

	// 		++linenum;
	// 		string prefix = what.prefix();
	// 		string suffix = what.suffix();
	// 		what.str();

	// 		// update search position:
	// 		start = what[0].second;
	// 		// update flags:
	// 		flags |= boost::match_prev_avail;
	// 		flags |= boost::match_not_bob;
	// 	}

        // is.eof();
    //}
}

/**
 * @name process_file
 */
void process_file(const std::string &name)
{
    std::ifstream is(name.c_str());
    if (is.bad())
    {
        std::cerr << "Unable to open file " << name << std::endl;
    }
    process_stream(is);
}

/**
 * @name process_files
 */
int process_files(int argc, char **argv)
{
    if (argc - 1)
    {
        for (size_t i = 1; i < argc; ++i)
        {
            std::string file = argv[i];
            process_file("test/debug.txt");
            std::cout << "file:" << file << std::endl;
        }
    }
    else
    {
        // no input files, scan stdin instead:
        process_stream(std::cin);
    }
    return 0;
}
