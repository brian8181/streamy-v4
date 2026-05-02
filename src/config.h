#ifndef _CONFIG_HPP_
#define _CONFIF_HPP_

#include <iostream>
#include <string>
#include <iomanip>
#include <list>
#include <map>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileio.hpp"
#include "log.hpp"
#include "symtab.h"
#include "driver.hpp"
#include "lexer.hpp"
#include "bash_color.hpp"

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::pair;
using std::map;

bool get_value( const string& name, /*out*/ string& val );
bool set_value( const string& name, const string& val );

// declare
// typedef map<string, string> symbol_table_t;
// // test
// symbol_table_t symbol_table = {     {"$a", "a_val"}, {"$b", "b_val"}, {"$c", "c_val"},
// 									{"$x", "x"}, {"$y", "y"}, {"$z", "z"},
// 									{"$xxx", "XXX_VAL"}, {"$yyy", "YYY_VAL"}, {"$zzz", "ZZZ_VAL"},
// 									{"$headers", "the headers"}, {"$page_title", "Brian's Home2 Page"}, {"#test#", "config_const"} 		};

#endif
