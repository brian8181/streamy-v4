/**
 * @file    log.hpp
 * @version version 0.0.1
 * @date    Tue Mar 31 13:39:39 CDT 2026
 */

#ifndef LOG_HPP_
#define LOG_HPP_

#include <iostream>
#include <sstream>
#include <vector>
#include <boost/regex.hpp>
#include "bash_color.hpp"

using std::cout;
using std::endl;
using std::stringstream;
using std::vector;

// namespace bkp {

void log(const std::string &msg, int line_number);

#define ITALIC(str) FMT_ITALIC << str << FMT_RESET
#define UNDERLINE(str) FMT_UNDERLINE << str << FMT_RESET
#define BOLD(str) FMT_BOLD << str << FMT_RESET
#define DIM(str) FMT_DIM << str << FMT_RESET
#define HIDDEN(str) << FMT_HIDDEN << str << FMT_RESET
#define GREEN(str) FMT_FG_GREEN << str << FMT_RESET
#define RED(str) FMT_FG_RED << str << FMT_RESET
#define BLUE(str) FMT_FG_BLUE << str << FMT_RESET
#define YELLOW(str) FMT_FG_YELLOW << str << FMT_RESET
#define GREY(str) FMT_FG_DARK_GREY << str << FMT_RESET
#define CYAN(str) FMT_FG_CYAN << str << FMT_RESET
#define MAGENTA(str) FMT_FG_MAGENTA << str << FMT_RESET
#define WHITE(str) FMT_FG_WHITE << str << FMT_RESET

#define LOG(type, color, str) cout << type << FMT_ITALIC << color << str << FMT_RESET << "  ---> "                                                       \
                                   << FMT_FG_DARK_GREY << "func:\"" << __func__ << "\" ~ file:\"" << __FILE__ << "\" ~ " << "line:" << __LINE__ << " ~ " \
                                   << "STD-C++:" << __cplusplus << " ~ " << __DATE__ << ", " << __TIME__ << FMT_RESET << endl

// tracing
#ifdef TRACING
#define TRACE() cout << "TRACE: " << FMT_ITALIC << FMT_BG_DARK_GREY << "func:\"" << __func__ << "\" ~ file:\"" << __FILE__ << "\" ~ " \
    << "line:" << __LINE__ << " ~ " << __DATE__ << ", " << __TIME__ << FMT_RESET << endl
#else
#define TRACE //
#endif

#define INFO_COLOR FMT_FG_GREEN
// #ifdef SET_COLOR
// #undef INFO_COLOR
// #define SET_COLOR(c) c
// #define INFO_COLOR SET_COLOR(c)
// #endif

// debugging
#ifdef DEBUG
#define INFO(str) LOG("INFO:  ", INFO_COLOR, str)
#define WARN(str) LOG("WARN:  ", FMT_FG_YELLOW, str)
#define ERROR(str) LOG("ERROR: ", FMT_FG_RED, str)
#elif WARNINGS
#define INFO(str) // str
#define WARN(str) LOG("WARN:  ", FMT_FG_YELLOW, str)
#define ERROR(str) LOG("ERROR: ", FMT_FG_RED, str)
#else
#define INFO(str) // str
#define WARN(str) // str
#define ERROR(str) LOG("ERROR: ", FMT_FG_RED, str)
#endif

namespace bkp
{
    template <typename T, typename... Args>
    string &print(string &fmt, Args... args)
    {
        vector<T> v;
        (v.push_back(args), ...);

        int len = v.size();
        const auto rexp = boost::regex(R"({.*})", boost::regex::extended);
        const auto beg = boost::sregex_iterator(fmt.begin(), fmt.end(), rexp);
        const auto end = boost::sregex_iterator();
        auto iter = beg;

        stringstream ss;
        for (int i = 0; iter != end; ++iter, ++i)
            ss << iter->prefix() << v[i];

        ss << iter->suffix();
        fmt = ss.str();
        return fmt;
    }

    template<typename... Ts>
    void myFunction(Ts const&... xs) // Ts can be of any number of any type
    {
        // ...
    }
}

//}

#endif
