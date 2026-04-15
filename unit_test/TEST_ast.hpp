#ifndef _TEST_AST_HPP_
#define _TEST_AST_HPP_

#include "ast/scope.hpp"
#include "ast/symbol_base.hpp"
#include "ast/variant.hpp"
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestFixture.h>
#include <map>
#include <string>


class TEST_ast : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE( TEST_ast );
    CPPUNIT_TEST( TEST_string_memory );
    CPPUNIT_TEST( TEST_logger );
    CPPUNIT_TEST( TEST_symbol_create );
    CPPUNIT_TEST( TEST_symbol_create2 );
    CPPUNIT_TEST( TEST_symbol_create_assign );
    CPPUNIT_TEST( TEST_variant_create_unset_set );
    CPPUNIT_TEST( TEST_variant_create_unset_set2 );
    CPPUNIT_TEST( TEST_reallocate_buffer );
    CPPUNIT_TEST( TEST_variant_create_from_array );
    CPPUNIT_TEST( TEST_variant_create_from_array2 );
    CPPUNIT_TEST( TEST_variant_create_from_array3 );
    CPPUNIT_TEST( TEST_variant7 );
    CPPUNIT_TEST( TEST_variant_unsigned_int_to_char );
    CPPUNIT_TEST( TEST_token_create );
    CPPUNIT_TEST( TEST_token_push_tokenized_expr );
    CPPUNIT_TEST( TEST_token_push_tokenized_expr2 );
    CPPUNIT_TEST( TEST_get_buffer );
    CPPUNIT_TEST( TEST_allocate_buffer );
    CPPUNIT_TEST( TEST_allocate_buffer_with_val );
    CPPUNIT_TEST( TEST_create_file_scope );
    CPPUNIT_TEST( TEST_create_file_scope_push_symbols );
    CPPUNIT_TEST( TEST_decl_expr_create );
    CPPUNIT_TEST( TEST_assign_expr_create );
    CPPUNIT_TEST( TEST_add_expr_create );
    CPPUNIT_TEST( TEST_subtract_expr_create );
    CPPUNIT_TEST( TEST_divide_expr_create );
    CPPUNIT_TEST( TEST_multiply_expr_create );
    CPPUNIT_TEST( TEST_mod_expr_create );
    CPPUNIT_TEST( TEST_symbol_expr_create );
    CPPUNIT_TEST( TEST_expr_eval );
    CPPUNIT_TEST( TEST_create_file_scope_push_statement );
    CPPUNIT_TEST( TEST_Typeof );
    CPPUNIT_TEST( TEST_little_to_big_endian );
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp() override;
    void tearDown() override;

 protected:
    void TEST_string_memory();
    void TEST_logger();
    void TEST_symbol_create();
    void TEST_symbol_create2();
    void TEST_symbol_create_assign();
	void TEST_variant_create_unset_set();
    void TEST_variant_create_unset_set2();
    void TEST_reallocate_buffer();
    void TEST_variant_create_from_array();
    void TEST_variant_create_from_array2();
    void TEST_variant_create_from_array3();
    void TEST_variant7();
    void TEST_variant_unsigned_int_to_char();
    void TEST_token_create();
    void TEST_token_push_tokenized_expr();
    void TEST_token_push_tokenized_expr2();
    void TEST_get_buffer();
	void TEST_allocate_buffer();
    void TEST_allocate_buffer_with_val();
	void TEST_create_file_scope();
    void TEST_create_file_scope_push_symbols();
    void TEST_decl_expr_create();
    void TEST_assign_expr_create();
    void TEST_add_expr_create();
    void TEST_subtract_expr_create();
    void TEST_multiply_expr_create();
    void TEST_divide_expr_create();
    void TEST_mod_expr_create();
    void TEST_symbol_expr_create();
    void TEST_expr_eval();
    void TEST_create_file_scope_push_statement();
    void TEST_Typeof();
    void TEST_little_to_big_endian();

private:

};

#endif // _TEST_AST_HPP_
