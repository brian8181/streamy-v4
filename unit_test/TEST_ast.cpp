#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <stack>
#include <stdexcept>
#include "ast/add_expr.hpp"
#include "ast/assign_expr.hpp"
#include "ast/decl_expr.hpp"
#include "ast/divide_expr.hpp"
#include "ast/expr.hpp"
#include "ast/file_scope.hpp"
#include "ast/logger.hpp"
#include "ast/mod_expr.hpp"
#include "ast/multiply_expr.hpp"
#include "ast/scope.hpp"
#include "ast/statement.hpp"
#include "ast/subtract_expr.hpp"
#include "ast/symbol.hpp"
#include "ast/symbol_base.hpp"
#include "ast/symbol_expr.hpp"
#include "ast/token.hpp"
#include "ast/variant.hpp"
#include "TEST_ast.hpp"
#include "log.hpp"

using std::stack;
using std::queue;
using std::cout;
using std::endl;
using std::cerr;
using std::hex;
using std::stringstream;

using namespace ast;

CPPUNIT_TEST_SUITE_REGISTRATION( TEST_ast );


void TEST_ast::setUp()
{

}

void TEST_ast::tearDown()
{

}

void TEST_ast::TEST_string_memory()
{
	char cstr[] = "Hello!";
	string str1(cstr);
	int len = strlen( cstr );
	CPPUNIT_ASSERT_EQUAL(6, len);
	CPPUNIT_ASSERT_EQUAL( cstr[6],'\0' );

	char* pcstr = 0;
	pcstr = (char*)malloc( sizeof( char ) * len + 1 );
	CPPUNIT_ASSERT( pcstr != 0 );

	strcpy( pcstr, cstr );
	string str2( pcstr );
	cout << "str2 = \"" << str2 << "\"" << endl;
	cout << "pcstr = \"" << pcstr << "\"" << endl;

	free(pcstr);

	cout << "freed pcstr" << endl;
	cout << "str2 = \"" << str2 << "\"" << endl;
	CPPUNIT_ASSERT( str1 == str2 );
	CPPUNIT_ASSERT( strcmp( str1.c_str(), str2.c_str() ) == 0 );
}
void TEST_ast::TEST_logger()
{
	LOG( "testing line");
}

void TEST_ast::TEST_symbol_create()
{
	symbol sym( "x", "int", INT );
	CPPUNIT_ASSERT( sym.get_name() == "x" );
	CPPUNIT_ASSERT( sym.get_value()->get_type() == INT );
}

void TEST_ast::TEST_symbol_create2()
{
	symbol sym( "x", "float", FLOAT );
	CPPUNIT_ASSERT( sym.get_name() == "x" );
	CPPUNIT_ASSERT( sym.get_value()->get_type() == FLOAT );
}

void TEST_ast::TEST_symbol_create_assign()
{
	symbol sym( "y", "long", LONG);
	string str_type = "long";
	variant var_long( str_type, LONG);
	long* p_int = var_long.allocate_buffer<long>();
	CPPUNIT_ASSERT( var_long.get_type() == LONG );
	*p_int = 123;
	CPPUNIT_ASSERT( (long)var_long == 123 );
}

void TEST_ast::TEST_variant_create_unset_set()
{
	string s("int");
	variant var_int( s, INT );
	int* p_int = var_int.allocate_buffer<int>();
	type_t t = var_int.get_type();
	CPPUNIT_ASSERT( var_int.get_type() == INT );
	*p_int = 123;
	CPPUNIT_ASSERT( (int)var_int == 123 );
}

void TEST_ast::TEST_variant_create_unset_set2()
{
	variant var_int( 21 );
	CPPUNIT_ASSERT( (int)var_int == 21 );
	int* p_int = (int*)var_int;
	*p_int = 42;
	CPPUNIT_ASSERT( (int)var_int == 42 );
}

void TEST_ast::TEST_get_buffer()
{
	variant var( 55 );
	int* pint = (int*)var.get_buffer();
	CPPUNIT_ASSERT(*pint == 55 && (int)var == 55);
	CPPUNIT_ASSERT(*pint == (int)var);
	*pint = *pint * 2;
	CPPUNIT_ASSERT(*pint == 110 && (int)var == 110);
	CPPUNIT_ASSERT(*pint == (int)var);
}

void TEST_ast::TEST_reallocate_buffer()
{
	variant var( 44 );
	// get buffer dereferenced value as int
	int n1 = (int)var;
	CPPUNIT_ASSERT( n1 == 44 && (int)var == 44 );
	// get pointer to buffer
	void** pp_int = (void**)var;
	// free buffer
	free(*pp_int);
	// realloc buffer
	*pp_int = (void*)malloc( sizeof( int ) );
	// set this equal to buffer value
	int* p_int = (int*)(*pp_int);
	// dereference the buffer
	*p_int = 66;
	// test from original
	int n2 = (int)var;
	CPPUNIT_ASSERT( n2 == 66 && (int)var == 66 );

}

void TEST_ast::TEST_variant_create_from_array()
{
	int arr_int[] = { 1, 2, 3, 4, 5 };
	variant var_int_array( arr_int, 5 );
	CPPUNIT_ASSERT( var_int_array.get_type() == PTR_INT );
	double arr_double[] = { 1.1, 2.2, 3.3 };
	variant var_double_array( arr_double, 3 );
	CPPUNIT_ASSERT( var_double_array.get_type() == PTR_DOUBLE );
}

void TEST_ast::TEST_variant_create_from_array2()
{
	int arr_int[] = { 1, 2, 3, 4, 5 };
	variant var_int_array( arr_int, 5 );
	int* p_int_array = (int*)var_int_array;
	CPPUNIT_ASSERT( p_int_array[0] == 1 );
	CPPUNIT_ASSERT( p_int_array[1] == 2 );
	CPPUNIT_ASSERT( p_int_array[2] == 3 );
	CPPUNIT_ASSERT( p_int_array[3] == 4 );
	CPPUNIT_ASSERT( p_int_array[4] == 5 );
	double arr_double[] = { 1.1, 2.2, 3.3 };
	variant var_double_array( arr_double, 3 );
	double* p_double_array = (double*)var_double_array;
	CPPUNIT_ASSERT( p_double_array[0] == 1.1 );
	CPPUNIT_ASSERT( p_double_array[1] == 2.2 );
	CPPUNIT_ASSERT( p_double_array[2] == 3.3 );
}

void TEST_ast::TEST_variant_create_from_array3()
{
	int arr_int[] = { 1, 2, 3, 4, 5 };
	variant var_int_array( arr_int, 5 );
	int* p_int_array = (int*)var_int_array;
	CPPUNIT_ASSERT( p_int_array[0] == 1 );
	CPPUNIT_ASSERT( p_int_array[1] == 2 );
	CPPUNIT_ASSERT( p_int_array[2] == 3 );
	CPPUNIT_ASSERT( p_int_array[3] == 4 );
	CPPUNIT_ASSERT( p_int_array[4] == 5 );
	double arr_double[] = { 1.1, 2.2, 3.3 };
	variant var_double_array( arr_double, 3 );
	double* p_double_array = (double*)var_double_array;
	CPPUNIT_ASSERT( p_double_array[0] == 1.1 );
	CPPUNIT_ASSERT( p_double_array[1] == 2.2 );
	CPPUNIT_ASSERT( p_double_array[2] == 3.3 );
}

void TEST_ast::TEST_variant7()
{
	variant var_int( 42 );
	CPPUNIT_ASSERT( (int)var_int == 42 );
	variant var_double( 3.14 );
	CPPUNIT_ASSERT( (double)var_double == 3.14 );
}

void TEST_ast::TEST_variant_unsigned_int_to_char()
{
	variant var( (char)0xDEADEEFu );
	unsigned char c = (char)var;
	CPPUNIT_ASSERT( (unsigned char)c == 0xEFu );
}

void TEST_ast::TEST_token_create()
{
	token tok_type( "int", TOKEN_TYPE_INT );
	token tok_id( "x", TOKEN_TYPE_IDENTIFIER );

	CPPUNIT_ASSERT( (string&)tok_type == "int" );
	CPPUNIT_ASSERT( (int)tok_type == TOKEN_TYPE_INT );
	CPPUNIT_ASSERT( (string&)tok_id == "x" );
	CPPUNIT_ASSERT( (int)tok_id == TOKEN_TYPE_IDENTIFIER );
}

void TEST_ast::TEST_token_push_tokenized_expr()
{
	string tokenized_expr = "int x = 3 + 5 * 8;";
	stack<token> stack;
	stack.push( token( "int" ) );
	stack.push( token( "x" ) );
	stack.push( token( "=" ) );
	stack.push( token( "2" ) );
	stack.push( token( "+" ) );
	stack.push( token( "5" ) );
	stack.push( token( "*" ) );
	stack.push( token( "8" ) );
	stack.push( token( ";" ) );
	CPPUNIT_ASSERT( (string&)stack.top() == ";" );
	stack.pop();
	CPPUNIT_ASSERT( (string&)stack.top() == "8" );
	stack.pop();
	CPPUNIT_ASSERT( (string&)stack.top() == "*" );
	stack.pop();
	CPPUNIT_ASSERT( (string&)stack.top() == "5" );
	stack.pop();
	stack.push( token( "40" ) );
	CPPUNIT_ASSERT( (string&)stack.top() == "40" );
	stack.pop();
	CPPUNIT_ASSERT( (string&)stack.top() == "+" );
	stack.pop();
	CPPUNIT_ASSERT( (string&)stack.top() == "2" );
	stack.pop();
	stack.push( token( "42" ) );
	CPPUNIT_ASSERT( (string&)stack.top() == "42" );
	stack.pop();
	CPPUNIT_ASSERT( (string&)stack.top() == "=" );
	stack.pop();
	CPPUNIT_ASSERT( (string&)stack.top() == "x" );
	stack.pop();
	CPPUNIT_ASSERT( (string&)stack.top() == "int" );
	stack.pop();
	stack.push( token( "42" ) );
}

void TEST_ast::TEST_token_push_tokenized_expr2()
{
	string tokenized_expr = "int x = 3 + 5 * 8;";
	queue<token> tokens;
	tokens.push( token( "int" ) );
	// ... [TYPE"int"]   <shift>
	// [TYPE"int"] ... <lex>
	tokens.push( token( "x" ) );
	// [TYPE"int"] ... [SYMBOL"x"] <reduce>
	// . [decl"int x"]  <shift>
	// [decl"int x"] ... <lex>
	tokens.push( token( "=" ) );
	// [decl"int x"] ...[EQUALS] <shift>
	// [decl"int x"] [EQUALS] ... <lex>
	tokens.push( token( "3" ) );
	// [decl"int x"] [EQUALS ] ... [NUMERIC_LITERAL"3"] <shift>
	// [decl"int x"] [EQUALS] [NUMERIC_LITERAL"3"] ... <lex>
	tokens.push( token( "+" ) );
	// [decl"int x"] [EQUALS] [NUMERIC_LITERAL"3"] ... [PLUS] <shift>
	// [decl"int x"] [EQUALS] [NUMERIC_LITERAL"3"] [PLUS] ... <lex>
	tokens.push( token( "5" ) );
	// [decl"int x"] [EQUALS] [NUMERIC_LITERAL"3"] [PLUS] ... [NUMERIC_LITERAL"5"] <shift>
	// [decl"int x"] [EQUALS] [NUMERIC_LITERAL"3"] [PLUS] [NUMERIC_LITERAL"5"] ... <lex>
	tokens.push( token( "*" ) );
	// [decl"int x"] [EQUALS] [NUMERIC_LITERAL"3"] [PLUS] [NUMERIC_LITERAL"5"] ... [ASTRIEK] <shift>
	// [decl"int x"] [EQUALS] [NUMERIC_LITERAL"3"] [PLUS] [NUMERIC_LITERAL"5"] [ASTRIEK] ... <lex>
	tokens.push( token( "8" ) );
	// [decl"int x"] [EQUALS] [NUMERIC_LITERAL"3"] [PLUS] [NUMERIC_LITERAL"5"] [ASTRIEK ] ... [NUMERIC_LITERAL"8"] <shift>
	// [decl"int x"] [EQUALS] [NUMERIC_LITERAL"3"] [PLUS] [NUMERIC_LITERAL"5"] [ASTRIEK] [NUMERIC_LITERAL"8"] ... <lex>
	tokens.push( token( ";" ) );
	// [(decl)"int x"] [EQUALS] [NUMERIC_LITERAL"3"] [PLUS] [NUMERIC_LITERAL"5"] [ASTRIEK] [NUMERIC_LITERAL"8"] ... SEMI_COLON <reduce>
	// . [statement]
}


void TEST_ast::TEST_allocate_buffer()
{
	variant var_int;
	int* p_int = var_int.allocate_buffer<int>();
	*p_int = 123;
	CPPUNIT_ASSERT( (int)var_int == 123 );
	variant var_double;
	double* p_double = var_double.allocate_buffer<double>();
	*p_double = 3.14159;
	CPPUNIT_ASSERT( (double)var_double == 3.14159 );
}

void TEST_ast::TEST_allocate_buffer_with_val()
{
	variant var_int;
	int val_int = 456;
	int* p_int = var_int.allocate_buffer<int>( &val_int );
	CPPUNIT_ASSERT( (int)var_int == 456 );
	variant var_double;
	double val_double = 2.71828;
	double* p_double = var_double.allocate_buffer<double>( &val_double );
	CPPUNIT_ASSERT( (double)var_double == 2.71828 );
}

void TEST_ast::TEST_create_file_scope()
{
	// create file scope
	// push symbol int x
	// push symbol int y
	// push statement decl int x
	// push statement decl int y
	// push statement assign x = 10
	// push statement assign y = x + 5

	string file_name = "test_file.cpp";
	file_scope scope( file_name );

	//CPPUNIT_ASSERT( scope.get_symbol("x") == 0);
	//CPPUNIT_ASSERT( scope.get_parent_scope() == 0);

	/*std::map<string, symbol_base*> symbol_table_;

	symbol_<int> s( "x", 42);
	symbol_table_["x"] = &s;
	auto it = symbol_table_.find( "x" );
	if(it != symbol_table_.end())
	{
		cout << std::dec << endl;
		string s2 = it->first;
		cout << "sym=" << s2 << endl;
		symbol_<int>* ps = ( symbol_<int>* )it->second;
		cout << "result=" << *ps->m_pval << endl;
		ps->set( 77 );
		cout << "ps=" << *ps->m_pval << " : " << *ps->get() << endl;
		*ps->m_pval = 88;
		cout << "ps=" << *ps->m_pval << " : " << *ps->get() << endl;
	}*/

}

void TEST_ast::TEST_create_file_scope_push_symbols()
{
	string file_name = "test_file.cpp";
	file_scope scope( file_name );
	cout << endl;
	log( "file_scope scope( file_name );", __LINE__ );
	CPPUNIT_ASSERT( scope.get_symbol( "x" ) == 0 );
	CPPUNIT_ASSERT( scope.get_parent_scope() == 0 );

	scope.push_symbol( symbol( "x", "int", INT ) );
	log( "scope.push_symbol( symbol( \"x\", \"int\", INT ) );", __LINE__ );
	scope.push_symbol( symbol( "y", "int", INT ) );
	log( "scope.push_symbol( symbol( \"y\", \"int\", INT ) );", __LINE__ );
	scope.push_symbol( symbol( "z", "int", INT ) );
	log( "scope.push_symbol( symbol( \"z\", \"int\", INT ) );", __LINE__ );

	variant* vx = scope.get_symbol( "x" )->get_value();
	variant* vy = scope.get_symbol( "y" )->get_value();
	variant* vz = scope.get_symbol( "z" )->get_value();
	CPPUNIT_ASSERT( vx != 0 && vy != 0 && vz != 0 );

	cout << "vx = " << vx << " line: " << __LINE__ << endl;
	log( "allocating buffer ...", __LINE__ );
	int* px = vx->allocate_buffer<int>();
	log( "int* px = vx->allocate_buffer<int>();", __LINE__ );
	*px = 25;
	log("*px = 25;", __LINE__);
	cout << "(int)(*vx) = " << (int)(*vx) << " line: " << __LINE__ << endl;
	int* py = vy->allocate_buffer<int>( px );
	int* pz = vz->allocate_buffer<int>( py );
	CPPUNIT_ASSERT( (int)(*vx) ==  25 && (int)(*vy) == 25 && (int)(*vz) == 25);
}

void TEST_ast::TEST_decl_expr_create()
{
	symbol sym( "x", "int", INT );
	decl_expr<int> expr( sym );
}

void TEST_ast::TEST_assign_expr_create()
{
	symbol sym( "x", "int", INT );
	assign_expr<int> expr(sym, 5);
}

void TEST_ast::TEST_add_expr_create()
{
	add_expr<int> expr0( 2, 3 );
	add_expr<float> expr1( 2, 3 );
	add_expr<char> expr2( 2, 3 );
	add_expr<int> expr3( 2, expr0 );
	add_expr<int> expr4( 15, expr3 );
}

void TEST_ast::TEST_subtract_expr_create()
{
	subtract_expr<int> expr0( 2, 3 );
	subtract_expr<float> expr1( 2, 3 );
	subtract_expr<char> expr2( 2, 3 );
	subtract_expr<int> expr3( 2, expr0 );
	subtract_expr<int> expr4( 15, expr3 );
}
void TEST_ast::TEST_multiply_expr_create()
{
	multiply_expr<int> expr0( 2, 3 );
	multiply_expr<float> expr1( 2, 3 );
	multiply_expr<char> expr2( 2, 3 );
	multiply_expr<int> expr3( 2, expr0 );
	multiply_expr<int> expr4( 15, expr3 );
}

void TEST_ast::TEST_divide_expr_create()
{
	divide_expr<int> expr0( 2, 3 );
	divide_expr<float> expr1( 2, 3 );
	divide_expr<char> expr2( 2, 3 );
	divide_expr<int> expr3( 2, expr0 );
	divide_expr<int> expr4( 15, expr3 );
}

void TEST_ast::TEST_mod_expr_create()
{
	mod_expr<int> expr0( 2, 3 );
	mod_expr<float> expr1( 2, 3 );
	mod_expr<char> expr2( 2, 3 );
	mod_expr<int> expr3( 2, expr0 );
	mod_expr<int> expr4( 2, expr3 );
}

void TEST_ast::TEST_symbol_expr_create()
{
	symbol s( "x", "int", INT );
	symbol_expr<int> expr( s );
}

void TEST_ast::TEST_expr_eval()
{
	stringstream ss;
	multiply_expr<int> e( 2, 3 );
	int* pint = e.eval();
	CPPUNIT_ASSERT( *pint == (2 * 3) );
}

void TEST_ast::TEST_create_file_scope_push_statement()
{
	//// int x = 5; ["declration" & "assignment"]
	string file_name = "test_file.cpp";
	file_scope fscope( file_name );
	symbol sym = symbol( "x", "int", INT );
	fscope.push_symbol(sym);
	// build expession [rule:statement = "^decel assign semicolon$"]
	symbol* psym = fscope.get_symbol( "x" );
	decl_expr<int> decl_expr_( *psym );
	assign_expr<int> assign_expr_( *psym, 5 );
	statement stmt( &assign_expr_ );
	fscope.push( stmt );
	statements_t stmts = fscope.get_statements();
	int len = stmts.size();
	for(int i = 0; i < len; ++i)
	{
		//stmts[i].execute<int>();
	}
}

void TEST_ast::TEST_Typeof()
{
	variant var( (int)42 );
	CPPUNIT_ASSERT( var.TypeOf( INT ) );
}

void TEST_ast::TEST_little_to_big_endian()
{
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
	LOG( "ORDER_LITTLE_ENDIAN" );
#endif
	union myu
	{
		int n;
		unsigned char c[4];
	};

	cout << endl;
	log( "testing endianess ...", __LINE__ );
	myu un;
	un.n = 0x41424344;
	cout << std::hex << un.c[0] << un.c[1] << un.c[2] << un.c[3] << endl;
	CPPUNIT_ASSERT( un.c[0] == 'D' && un.c[1] == 'C' && un.c[2] == 'B' && un.c[3] == 'A' );

	short s = 0x2324; // #$
	unsigned char* pc = (unsigned char*)&s;
	cout << pc[0] << pc[1] << endl;
}
