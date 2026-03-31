/**
 * @file    log.hpp
 * @version version 0.0.1
 * @date    Tue Mar 31 13:39:39 CDT 2026
  */

#ifndef BASH_COLOR_HPP_
#define BASH_COLOR_HPP_

#include <iostream>
#include <string>
#include "bash_color.hpp"

using std::string;

#define LOG(type, color, str) cout << type << FMT_ITALIC << color << str << FMT_RESET << "  ---> " \
<< FMT_FG_DARK_GREY <<  " line:" << __LINE__ << FMT_FG_WHITE << " ~ " << FMT_FG_DARK_GREY \
<< "file:\"" << __FILE__ << "\" - " << __cplusplus << " - " << __TIME__ << FMT_RESET << endl;

#define INFO(str) LOG("INFO", FMT_FG_GREEN, str)
#define WARN(str) LOG("WARN", FMT_FG_YELLOW, str)
#define WARN(str) LOG("ERROR", FMT_FG_RED, str)
