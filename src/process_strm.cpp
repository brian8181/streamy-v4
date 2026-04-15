#include <boost/regex.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "bash_color.hpp"

#ifdef BOOST_MSVC
#pragma warning(disable : 4512 4244)
#endif

#include <boost/program_options.hpp>

using std::string;
using std::stringstream;
using std::vector;

namespace po = boost::program_options;

std::string pattern;
boost::regex_constants::syntax_option_type flags = boost::regex_constants::basic;
boost::regex re;
boost::smatch what;
std::string file;
int file_count;

/**
 * @name process_stream
 */
void process_stream(std::istream &is)
{
    std::string line;
    int match_found = 0;
    int linenum = 1;
    while (std::getline(is, line))
    {
        bool result = boost::regex_search(line, what, re);
        if (result)
        {
            ++linenum;
        }
        std::cout << FMT_FG_MAGENTA << "STREAM @ line -->" << linenum++ << "\t" << line << FMT_RESET << "\n";

        string rexp_str;
        rexp_str.pop_back(); // remove extra '|' i.e. "V-BAR"
        // set context
        auto rexp = boost::regex(rexp_str, boost::regex::extended);
        // auto iter = boost::sregex_iterator(m_buffer.begin(), m_buffer.end(), rexp);
        // auto end = boost::sregex_iterator();

        // is.eof();
    }
}

/**
 * @name process_file
 */
void process_file(const std::string &name)
{
    file = name;
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
