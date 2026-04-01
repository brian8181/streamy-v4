/**
 * @file    streamy3.hpp
 * @version version 0.0.1
 * @date    Sun, 08 Mar 2026 16:09:45 +0000
  */
#ifndef BASH_COLOR_HPP_
#define BASH_COLOR_HPP_

#include <iostream>
#include <string>

using std::string;

// shell color constants
const string FMT_RESET             = "\033[0m";
const string FMT_RESET_BOLD        = "\033[21m";
const string FMT_RESET_DIM         = "\033[22m";
const string FMT_RESET_UNDERLINE   = "\033[24m";
const string FMT_RESET_BLINK       = "\033[25m";
const string FMT_RESET_REVERSE     = "\033[27m";
const string FMT_RESET_HIDDEN      = "\033[28m";
const string FMT_BOLD              = "\033[1m";
const string FMT_DIM               = "\033[2m";
const string FMT_ITALIC            = "\033[3m";
const string FMT_UNDERLINE         = "\033[4m";
const string FMT_BLINK             = "\033[5m";
const string FMT_REVERSE           = "\033[7m";
const string FMT_HIDDEN            = "\033[8m";
const string FMT_FG_DEFUALT        = "\033[39m";
const string FMT_FG_RED            = "\033[31m";
const string FMT_FG_GREEN          = "\033[32m";
const string FMT_FG_YELLOW         = "\033[33m";
const string FMT_FG_BLUE           = "\033[34m";
const string FMT_FG_MAGENTA        = "\033[35m";
const string FMT_FG_CYAN           = "\033[36m";
const string FMT_FG_LIGHT_GREY     = "\033[37m";
const string FMT_FG_DARK_GREY      = "\033[90m";
const string FMT_FG_LIGHT_RED      = "\033[91m";
const string FMT_FG_LIGHT_GREEN    = "\033[92m";
const string FMT_FG_LIGHT_YELLOW   = "\033[93m";
const string FMT_FG_LIGHT_BLUE     = "\033[94m";
const string FMT_FG_LIGHT_MAGENTA  = "\033[95m";
const string FMT_FG_LIGHT_CYAN     = "\033[96m";
const string FMT_FG_WHITE          = "\033[97m";
const string FMT_BG_DEFUALT        = "\033[49m";
const string FMT_BG_BLACK          = "\033[40m";
const string FMT_BG_RED            = "\033[41m";
const string FMT_BG_GREEN          = "\033[42m";
const string FMT_BG_YELLOW         = "\033[43m";
const string FMT_BG_BLUE           = "\033[44m";
const string FMT_BG_MAGENTA        = "\033[45m";
const string FMT_BG_CYAN           = "\033[46m";
const string FMT_BG_DARK_GREY      = "\033[100m";
const string FMT_BG_LIGHT_RED      = "\033[101m";
const string FMT_BG_LIGHT_GREEN    = "\033[102m";
const string FMT_BG_LIGHT_YELLOW   = "\033[103m";
const string FMT_BG_LIGHT_BLUE     = "\033[104m";
const string FMT_BG_LIGHT_MAGENTA  = "\033[105m";
const string FMT_BG_LIGHT_CYAN     = "\033[106m";
const string FMT_BG_WHITE          = "\033[107m";

#define ITALIC(str) FMT_ITALIC << str << FMT_RESET
#define UNDERLINE(str) FMT_UNDERLINE << str << FMT_RESET_UNDERLINE
#define BOLD(str) FMT_BOLD << str << FMT_RESET_BOLD
#define DIM(str) FMT_DIM << str << FMT_RESET_DIM
#define HIDDEN(str) << FMT_HIDDEN << str << FMT_RESET_HIDDEN
#define GREEN(str) FMT_FG_GREEN << str << FMT_RESET
#define RED(str) FMT_FG_RED << str << FMT_RESET
#define BLUE(str) FMT_FG_BLUE << str << FMT_RESET
#define YELLOW(str) FMT_FG_YELLOW << str << FMT_RESET
#define GREY(str) FMT_FG_DARK_GREY << str << FMT_RESET
#define CYAN(str) FMT_FG_CYAN << str << FMT_RESET
#define MAGENTA(str) FMT_FG_MAGENTA << str << FMT_RESET
#define WHITE(str) FMT_FG_WHITE << str << FMT_RESET

#define TRACE cout << "TRACE: " << FMT_ITALIC << FMT_BG_DARK_GREY << "func:\"" << __func__ << "\" ~ file:\"" << __FILE__ << \
"\" ~ " <<  "line:" << __LINE__ << " ~ " << " ~ " << __DATE__ << ", " << __TIME__ << FMT_RESET << endl;

#define LOG(type, color, str) cout << type << FMT_ITALIC << color << str << FMT_RESET << "  ---> " \
<< FMT_FG_DARK_GREY << "func:\"" << __func__ << "\" ~ file:\"" << __FILE__ << "\" ~ " <<  "line:" << __LINE__ << " ~ " \
<< "STD-C++:" << __cplusplus << " ~ " << __DATE__ << ", " << __TIME__ << FMT_RESET << endl;

#define INFO(str) LOG("INFO: ", FMT_FG_GREEN, str)
#define WARN(str) LOG("WARN: ", FMT_FG_YELLOW, str)
#define ERROR(str) LOG("ERROR: ", FMT_FG_RED, str)

//FMT_ITALIC << FMT_FG_GREEN << str << FMT_RESET << FMT_RESET

// string& FMT_STRING(string& s, const string& format)
// {
//     s = format + s + FMT_RESET;
//     return s;
// }

// string& COLOR_RED(string& s)
// {
//     return FMT_STRING(s, FMT_FG_RED);
// }

// string& COLOR_BLUE(string& s)
// {
//      return FMT_STRING(s, FMT_FG_BLUE);
// }

// string& COLOR_YELLOW(string& s)
// {
//     return FMT_STRING(s, FMT_FG_YELLOW);
// }

// string& COLOR_GREEN(string& s)
// {
//     return FMT_STRING(s, FMT_FG_GREEN);
// }

#endif
