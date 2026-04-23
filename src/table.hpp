#ifndef __THE_TABLE_
#define __THE_TABLE_

	// declare
	typedef map<string, string> symbol_table_t;
	typedef map<string, void*> object_table_t;
	// test
	symbol_table_t symbol_table = {     {"$a", "a_val"}, {"$b", "b_val"}, {"$c", "c_val"},
										{"$x", "x"}, {"$y", "y"}, {"$z", "z"},
										{"$xxx", "XXX_VAL"}, {"$yyy", "YYY_VAL"}, {"$zzz", "ZZZ_VAL"},
										{"$headers", "the headers"}, {"$page_title", "Brian's Home2 Page"}, {"#test#", "config_const"}, {"$e", "51"}, {"$f", "52"}, {"$h", "53"}, {"$i", "54"}, {"$pussy", "wet"} };
#endif
