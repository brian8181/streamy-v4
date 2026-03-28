// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "pparser.tab.hh"


// Unqualified %code blocks.
#line 5 "src/pparser.yy"

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
    #include "bash_color.hpp"
    #include "symtab.h"
    #include "driver.h"
    #include "lexer.hpp"

    using std::vector;
    using std::string;
    using std::cout;
    using std::endl;
    using std::pair;
    using std::map;

    //typedef std::pair< std::string, std::string > > attrib_t;
    //typedef std::vector< attrib_t > attributes_t;

    // print a list of strings
    auto operator<<(std::ostream& o, const std::vector<std::string>& ss) -> std::ostream&
    {
        o << '{';
        const char *sep = "";
        for(const auto& s: ss)
        {
            o << sep << s;
            sep = ", ";
        }
        return o << '}';
    }

    std::map<string, string> stab;

    typedef struct modifier_t
    {
        std::string name;
        std::string params;
    } modifier_t;
#line 55 "src/pparser.yy"

    // declare yylex
    namespace yy
    {
        auto yylex() -> parser::symbol_type;
    }

    char* STRDUP(char* s);
    /* string literal buffer */
    char buf[100];
    char *s;

    typedef struct nvalue
    {
        char* name;
        char* value;
        struct nvalue* next;
    } nvalue;

    static nvalue* pnv_head = 0;
    nvalue* alloc_nvalue(char* name, char* value);
    void free_nvalue(nvalue* nv);
    void free_all_nvalues();
    typedef std::pair< std::string, std::string > attribute;

    // declare
    typedef map<string, string> symbol_table_t;
    // test
    symbol_table_t symbol_table =  { {"a", "a_val"}, {"b", "b_val"}, {"c", "c_val"} };
    bool is_name(const std::pair<string, string>& p, const string& str);

    //%type<std::vector< modifier_t > > modifiers
    //%type<modifier_t> modifier



#line 130 "build/pparser.tab.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 203 "build/pparser.tab.cc"

  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr)
#else

#endif
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_attrib: // attrib
        value.YY_MOVE_OR_COPY<  std::pair<std::string, std::string>  > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_PLUS_SIGN: // PLUS_SIGN
      case symbol_kind::S_MINUS: // MINUS
        value.YY_MOVE_OR_COPY< char > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CAPTURE: // CAPTURE
      case symbol_kind::S_CONFIG_LOAD: // CONFIG_LOAD
      case symbol_kind::S_INCLUDE: // INCLUDE
      case symbol_kind::S_REQUIRE: // REQUIRE
      case symbol_kind::S_REQUIRE_ONCE: // REQUIRE_ONCE
      case symbol_kind::S_INSERT: // INSERT
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_ISSET: // ISSET
      case symbol_kind::S_SECTION: // SECTION
      case symbol_kind::S_LDELIM: // LDELIM
      case symbol_kind::S_RDELIM: // RDELIM
      case symbol_kind::S_VERSION: // VERSION
      case symbol_kind::S_CYCLE: // CYCLE
      case symbol_kind::S_COUNTER: // COUNTER
      case symbol_kind::S_INDIRECT_MEMBER: // INDIRECT_MEMBER
      case symbol_kind::S_ARRAY: // ARRAY
      case symbol_kind::S_STRING_LITERAL: // STRING_LITERAL
      case symbol_kind::S_NUMERIC_LITERAL: // NUMERIC_LITERAL
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_CONST_ID: // CONST_ID
      case symbol_kind::S_CONST_SYMBOL: // CONST_SYMBOL
      case symbol_kind::S_VAR_ATTRIB: // VAR_ATTRIB
      case symbol_kind::S_VALUE_ATTRIB: // VALUE_ATTRIB
      case symbol_kind::S_FILE_ATTRIB: // FILE_ATTRIB
      case symbol_kind::S_FROM_ATTRIB: // FROM_ATTRIB
      case symbol_kind::S_KEY_ATTRIB: // KEY_ATTRIB
      case symbol_kind::S_NAME_ATTRIB: // NAME_ATTRIB
      case symbol_kind::S_ITEM_ATTRIB: // ITEM_ATTRIB
      case symbol_kind::S_FILE_NAME: // FILE_NAME
      case symbol_kind::S_CAPITALIZE: // CAPITALIZE
      case symbol_kind::S_CAT: // CAT
      case symbol_kind::S_COUNT_CHARACTERS: // COUNT_CHARACTERS
      case symbol_kind::S_COUNT_SENTENCES: // COUNT_SENTENCES
      case symbol_kind::S_COUNT_PARAGRAPHS: // COUNT_PARAGRAPHS
      case symbol_kind::S_COUNT_WORDS: // COUNT_WORDS
      case symbol_kind::S_DATE_FORMAT: // DATE_FORMAT
      case symbol_kind::S_DEFAULT: // DEFAULT
      case symbol_kind::S_ESCAPE: // ESCAPE
      case symbol_kind::S_INDENT: // INDENT
      case symbol_kind::S_LOWER: // LOWER
      case symbol_kind::S_UPPER: // UPPER
      case symbol_kind::S_STRIP: // STRIP
      case symbol_kind::S_NL2BR: // NL2BR
      case symbol_kind::S_REGEX_REPLACE: // REGEX_REPLACE
      case symbol_kind::S_REPLACE: // REPLACE
      case symbol_kind::S_SPACIFY: // SPACIFY
      case symbol_kind::S_STRING_FORMAT: // STRING_FORMAT
      case symbol_kind::S_STRIP_TAGS: // STRIP_TAGS
      case symbol_kind::S_TRUNCATE: // TRUNCATE
      case symbol_kind::S_WORDWRAP: // WORDWRAP
      case symbol_kind::S_assign_stmt: // assign_stmt
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_qualafied_id: // qualafied_id
      case symbol_kind::S_sub_proc: // sub_proc
      case symbol_kind::S_array: // array
      case symbol_kind::S_modifier: // modifier
      case symbol_kind::S_colon_sep_params: // colon_sep_params
      case symbol_kind::S_colon_sep_param: // colon_sep_param
      case symbol_kind::S_symbol: // symbol
      case symbol_kind::S_attrib_name: // attrib_name
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_built_in: // built_in
      case symbol_kind::S_attributes: // attributes
        value.YY_MOVE_OR_COPY< std::vector< std::pair<std::string, std::string> >  > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_modifiers: // modifiers
        value.YY_MOVE_OR_COPY< std::vector< std::string >  > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.kind ())
    {
      case symbol_kind::S_attrib: // attrib
        value.move<  std::pair<std::string, std::string>  > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_PLUS_SIGN: // PLUS_SIGN
      case symbol_kind::S_MINUS: // MINUS
        value.move< char > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CAPTURE: // CAPTURE
      case symbol_kind::S_CONFIG_LOAD: // CONFIG_LOAD
      case symbol_kind::S_INCLUDE: // INCLUDE
      case symbol_kind::S_REQUIRE: // REQUIRE
      case symbol_kind::S_REQUIRE_ONCE: // REQUIRE_ONCE
      case symbol_kind::S_INSERT: // INSERT
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_ISSET: // ISSET
      case symbol_kind::S_SECTION: // SECTION
      case symbol_kind::S_LDELIM: // LDELIM
      case symbol_kind::S_RDELIM: // RDELIM
      case symbol_kind::S_VERSION: // VERSION
      case symbol_kind::S_CYCLE: // CYCLE
      case symbol_kind::S_COUNTER: // COUNTER
      case symbol_kind::S_INDIRECT_MEMBER: // INDIRECT_MEMBER
      case symbol_kind::S_ARRAY: // ARRAY
      case symbol_kind::S_STRING_LITERAL: // STRING_LITERAL
      case symbol_kind::S_NUMERIC_LITERAL: // NUMERIC_LITERAL
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_CONST_ID: // CONST_ID
      case symbol_kind::S_CONST_SYMBOL: // CONST_SYMBOL
      case symbol_kind::S_VAR_ATTRIB: // VAR_ATTRIB
      case symbol_kind::S_VALUE_ATTRIB: // VALUE_ATTRIB
      case symbol_kind::S_FILE_ATTRIB: // FILE_ATTRIB
      case symbol_kind::S_FROM_ATTRIB: // FROM_ATTRIB
      case symbol_kind::S_KEY_ATTRIB: // KEY_ATTRIB
      case symbol_kind::S_NAME_ATTRIB: // NAME_ATTRIB
      case symbol_kind::S_ITEM_ATTRIB: // ITEM_ATTRIB
      case symbol_kind::S_FILE_NAME: // FILE_NAME
      case symbol_kind::S_CAPITALIZE: // CAPITALIZE
      case symbol_kind::S_CAT: // CAT
      case symbol_kind::S_COUNT_CHARACTERS: // COUNT_CHARACTERS
      case symbol_kind::S_COUNT_SENTENCES: // COUNT_SENTENCES
      case symbol_kind::S_COUNT_PARAGRAPHS: // COUNT_PARAGRAPHS
      case symbol_kind::S_COUNT_WORDS: // COUNT_WORDS
      case symbol_kind::S_DATE_FORMAT: // DATE_FORMAT
      case symbol_kind::S_DEFAULT: // DEFAULT
      case symbol_kind::S_ESCAPE: // ESCAPE
      case symbol_kind::S_INDENT: // INDENT
      case symbol_kind::S_LOWER: // LOWER
      case symbol_kind::S_UPPER: // UPPER
      case symbol_kind::S_STRIP: // STRIP
      case symbol_kind::S_NL2BR: // NL2BR
      case symbol_kind::S_REGEX_REPLACE: // REGEX_REPLACE
      case symbol_kind::S_REPLACE: // REPLACE
      case symbol_kind::S_SPACIFY: // SPACIFY
      case symbol_kind::S_STRING_FORMAT: // STRING_FORMAT
      case symbol_kind::S_STRIP_TAGS: // STRIP_TAGS
      case symbol_kind::S_TRUNCATE: // TRUNCATE
      case symbol_kind::S_WORDWRAP: // WORDWRAP
      case symbol_kind::S_assign_stmt: // assign_stmt
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_qualafied_id: // qualafied_id
      case symbol_kind::S_sub_proc: // sub_proc
      case symbol_kind::S_array: // array
      case symbol_kind::S_modifier: // modifier
      case symbol_kind::S_colon_sep_params: // colon_sep_params
      case symbol_kind::S_colon_sep_param: // colon_sep_param
      case symbol_kind::S_symbol: // symbol
      case symbol_kind::S_attrib_name: // attrib_name
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_built_in: // built_in
      case symbol_kind::S_attributes: // attributes
        value.move< std::vector< std::pair<std::string, std::string> >  > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_modifiers: // modifiers
        value.move< std::vector< std::string >  > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_attrib: // attrib
        value.copy<  std::pair<std::string, std::string>  > (that.value);
        break;

      case symbol_kind::S_PLUS_SIGN: // PLUS_SIGN
      case symbol_kind::S_MINUS: // MINUS
        value.copy< char > (that.value);
        break;

      case symbol_kind::S_CAPTURE: // CAPTURE
      case symbol_kind::S_CONFIG_LOAD: // CONFIG_LOAD
      case symbol_kind::S_INCLUDE: // INCLUDE
      case symbol_kind::S_REQUIRE: // REQUIRE
      case symbol_kind::S_REQUIRE_ONCE: // REQUIRE_ONCE
      case symbol_kind::S_INSERT: // INSERT
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_ISSET: // ISSET
      case symbol_kind::S_SECTION: // SECTION
      case symbol_kind::S_LDELIM: // LDELIM
      case symbol_kind::S_RDELIM: // RDELIM
      case symbol_kind::S_VERSION: // VERSION
      case symbol_kind::S_CYCLE: // CYCLE
      case symbol_kind::S_COUNTER: // COUNTER
      case symbol_kind::S_INDIRECT_MEMBER: // INDIRECT_MEMBER
      case symbol_kind::S_ARRAY: // ARRAY
      case symbol_kind::S_STRING_LITERAL: // STRING_LITERAL
      case symbol_kind::S_NUMERIC_LITERAL: // NUMERIC_LITERAL
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_CONST_ID: // CONST_ID
      case symbol_kind::S_CONST_SYMBOL: // CONST_SYMBOL
      case symbol_kind::S_VAR_ATTRIB: // VAR_ATTRIB
      case symbol_kind::S_VALUE_ATTRIB: // VALUE_ATTRIB
      case symbol_kind::S_FILE_ATTRIB: // FILE_ATTRIB
      case symbol_kind::S_FROM_ATTRIB: // FROM_ATTRIB
      case symbol_kind::S_KEY_ATTRIB: // KEY_ATTRIB
      case symbol_kind::S_NAME_ATTRIB: // NAME_ATTRIB
      case symbol_kind::S_ITEM_ATTRIB: // ITEM_ATTRIB
      case symbol_kind::S_FILE_NAME: // FILE_NAME
      case symbol_kind::S_CAPITALIZE: // CAPITALIZE
      case symbol_kind::S_CAT: // CAT
      case symbol_kind::S_COUNT_CHARACTERS: // COUNT_CHARACTERS
      case symbol_kind::S_COUNT_SENTENCES: // COUNT_SENTENCES
      case symbol_kind::S_COUNT_PARAGRAPHS: // COUNT_PARAGRAPHS
      case symbol_kind::S_COUNT_WORDS: // COUNT_WORDS
      case symbol_kind::S_DATE_FORMAT: // DATE_FORMAT
      case symbol_kind::S_DEFAULT: // DEFAULT
      case symbol_kind::S_ESCAPE: // ESCAPE
      case symbol_kind::S_INDENT: // INDENT
      case symbol_kind::S_LOWER: // LOWER
      case symbol_kind::S_UPPER: // UPPER
      case symbol_kind::S_STRIP: // STRIP
      case symbol_kind::S_NL2BR: // NL2BR
      case symbol_kind::S_REGEX_REPLACE: // REGEX_REPLACE
      case symbol_kind::S_REPLACE: // REPLACE
      case symbol_kind::S_SPACIFY: // SPACIFY
      case symbol_kind::S_STRING_FORMAT: // STRING_FORMAT
      case symbol_kind::S_STRIP_TAGS: // STRIP_TAGS
      case symbol_kind::S_TRUNCATE: // TRUNCATE
      case symbol_kind::S_WORDWRAP: // WORDWRAP
      case symbol_kind::S_assign_stmt: // assign_stmt
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_qualafied_id: // qualafied_id
      case symbol_kind::S_sub_proc: // sub_proc
      case symbol_kind::S_array: // array
      case symbol_kind::S_modifier: // modifier
      case symbol_kind::S_colon_sep_params: // colon_sep_params
      case symbol_kind::S_colon_sep_param: // colon_sep_param
      case symbol_kind::S_symbol: // symbol
      case symbol_kind::S_attrib_name: // attrib_name
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_built_in: // built_in
      case symbol_kind::S_attributes: // attributes
        value.copy< std::vector< std::pair<std::string, std::string> >  > (that.value);
        break;

      case symbol_kind::S_modifiers: // modifiers
        value.copy< std::vector< std::string >  > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_attrib: // attrib
        value.move<  std::pair<std::string, std::string>  > (that.value);
        break;

      case symbol_kind::S_PLUS_SIGN: // PLUS_SIGN
      case symbol_kind::S_MINUS: // MINUS
        value.move< char > (that.value);
        break;

      case symbol_kind::S_CAPTURE: // CAPTURE
      case symbol_kind::S_CONFIG_LOAD: // CONFIG_LOAD
      case symbol_kind::S_INCLUDE: // INCLUDE
      case symbol_kind::S_REQUIRE: // REQUIRE
      case symbol_kind::S_REQUIRE_ONCE: // REQUIRE_ONCE
      case symbol_kind::S_INSERT: // INSERT
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_ISSET: // ISSET
      case symbol_kind::S_SECTION: // SECTION
      case symbol_kind::S_LDELIM: // LDELIM
      case symbol_kind::S_RDELIM: // RDELIM
      case symbol_kind::S_VERSION: // VERSION
      case symbol_kind::S_CYCLE: // CYCLE
      case symbol_kind::S_COUNTER: // COUNTER
      case symbol_kind::S_INDIRECT_MEMBER: // INDIRECT_MEMBER
      case symbol_kind::S_ARRAY: // ARRAY
      case symbol_kind::S_STRING_LITERAL: // STRING_LITERAL
      case symbol_kind::S_NUMERIC_LITERAL: // NUMERIC_LITERAL
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_CONST_ID: // CONST_ID
      case symbol_kind::S_CONST_SYMBOL: // CONST_SYMBOL
      case symbol_kind::S_VAR_ATTRIB: // VAR_ATTRIB
      case symbol_kind::S_VALUE_ATTRIB: // VALUE_ATTRIB
      case symbol_kind::S_FILE_ATTRIB: // FILE_ATTRIB
      case symbol_kind::S_FROM_ATTRIB: // FROM_ATTRIB
      case symbol_kind::S_KEY_ATTRIB: // KEY_ATTRIB
      case symbol_kind::S_NAME_ATTRIB: // NAME_ATTRIB
      case symbol_kind::S_ITEM_ATTRIB: // ITEM_ATTRIB
      case symbol_kind::S_FILE_NAME: // FILE_NAME
      case symbol_kind::S_CAPITALIZE: // CAPITALIZE
      case symbol_kind::S_CAT: // CAT
      case symbol_kind::S_COUNT_CHARACTERS: // COUNT_CHARACTERS
      case symbol_kind::S_COUNT_SENTENCES: // COUNT_SENTENCES
      case symbol_kind::S_COUNT_PARAGRAPHS: // COUNT_PARAGRAPHS
      case symbol_kind::S_COUNT_WORDS: // COUNT_WORDS
      case symbol_kind::S_DATE_FORMAT: // DATE_FORMAT
      case symbol_kind::S_DEFAULT: // DEFAULT
      case symbol_kind::S_ESCAPE: // ESCAPE
      case symbol_kind::S_INDENT: // INDENT
      case symbol_kind::S_LOWER: // LOWER
      case symbol_kind::S_UPPER: // UPPER
      case symbol_kind::S_STRIP: // STRIP
      case symbol_kind::S_NL2BR: // NL2BR
      case symbol_kind::S_REGEX_REPLACE: // REGEX_REPLACE
      case symbol_kind::S_REPLACE: // REPLACE
      case symbol_kind::S_SPACIFY: // SPACIFY
      case symbol_kind::S_STRING_FORMAT: // STRING_FORMAT
      case symbol_kind::S_STRIP_TAGS: // STRIP_TAGS
      case symbol_kind::S_TRUNCATE: // TRUNCATE
      case symbol_kind::S_WORDWRAP: // WORDWRAP
      case symbol_kind::S_assign_stmt: // assign_stmt
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_qualafied_id: // qualafied_id
      case symbol_kind::S_sub_proc: // sub_proc
      case symbol_kind::S_array: // array
      case symbol_kind::S_modifier: // modifier
      case symbol_kind::S_colon_sep_params: // colon_sep_params
      case symbol_kind::S_colon_sep_param: // colon_sep_param
      case symbol_kind::S_symbol: // symbol
      case symbol_kind::S_attrib_name: // attrib_name
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_built_in: // built_in
      case symbol_kind::S_attributes: // attributes
        value.move< std::vector< std::pair<std::string, std::string> >  > (that.value);
        break;

      case symbol_kind::S_modifiers: // modifiers
        value.move< std::vector< std::string >  > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " (";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex ());
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_attrib: // attrib
        yylhs.value.emplace<  std::pair<std::string, std::string>  > ();
        break;

      case symbol_kind::S_PLUS_SIGN: // PLUS_SIGN
      case symbol_kind::S_MINUS: // MINUS
        yylhs.value.emplace< char > ();
        break;

      case symbol_kind::S_CAPTURE: // CAPTURE
      case symbol_kind::S_CONFIG_LOAD: // CONFIG_LOAD
      case symbol_kind::S_INCLUDE: // INCLUDE
      case symbol_kind::S_REQUIRE: // REQUIRE
      case symbol_kind::S_REQUIRE_ONCE: // REQUIRE_ONCE
      case symbol_kind::S_INSERT: // INSERT
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_ISSET: // ISSET
      case symbol_kind::S_SECTION: // SECTION
      case symbol_kind::S_LDELIM: // LDELIM
      case symbol_kind::S_RDELIM: // RDELIM
      case symbol_kind::S_VERSION: // VERSION
      case symbol_kind::S_CYCLE: // CYCLE
      case symbol_kind::S_COUNTER: // COUNTER
      case symbol_kind::S_INDIRECT_MEMBER: // INDIRECT_MEMBER
      case symbol_kind::S_ARRAY: // ARRAY
      case symbol_kind::S_STRING_LITERAL: // STRING_LITERAL
      case symbol_kind::S_NUMERIC_LITERAL: // NUMERIC_LITERAL
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_CONST_ID: // CONST_ID
      case symbol_kind::S_CONST_SYMBOL: // CONST_SYMBOL
      case symbol_kind::S_VAR_ATTRIB: // VAR_ATTRIB
      case symbol_kind::S_VALUE_ATTRIB: // VALUE_ATTRIB
      case symbol_kind::S_FILE_ATTRIB: // FILE_ATTRIB
      case symbol_kind::S_FROM_ATTRIB: // FROM_ATTRIB
      case symbol_kind::S_KEY_ATTRIB: // KEY_ATTRIB
      case symbol_kind::S_NAME_ATTRIB: // NAME_ATTRIB
      case symbol_kind::S_ITEM_ATTRIB: // ITEM_ATTRIB
      case symbol_kind::S_FILE_NAME: // FILE_NAME
      case symbol_kind::S_CAPITALIZE: // CAPITALIZE
      case symbol_kind::S_CAT: // CAT
      case symbol_kind::S_COUNT_CHARACTERS: // COUNT_CHARACTERS
      case symbol_kind::S_COUNT_SENTENCES: // COUNT_SENTENCES
      case symbol_kind::S_COUNT_PARAGRAPHS: // COUNT_PARAGRAPHS
      case symbol_kind::S_COUNT_WORDS: // COUNT_WORDS
      case symbol_kind::S_DATE_FORMAT: // DATE_FORMAT
      case symbol_kind::S_DEFAULT: // DEFAULT
      case symbol_kind::S_ESCAPE: // ESCAPE
      case symbol_kind::S_INDENT: // INDENT
      case symbol_kind::S_LOWER: // LOWER
      case symbol_kind::S_UPPER: // UPPER
      case symbol_kind::S_STRIP: // STRIP
      case symbol_kind::S_NL2BR: // NL2BR
      case symbol_kind::S_REGEX_REPLACE: // REGEX_REPLACE
      case symbol_kind::S_REPLACE: // REPLACE
      case symbol_kind::S_SPACIFY: // SPACIFY
      case symbol_kind::S_STRING_FORMAT: // STRING_FORMAT
      case symbol_kind::S_STRIP_TAGS: // STRIP_TAGS
      case symbol_kind::S_TRUNCATE: // TRUNCATE
      case symbol_kind::S_WORDWRAP: // WORDWRAP
      case symbol_kind::S_assign_stmt: // assign_stmt
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_qualafied_id: // qualafied_id
      case symbol_kind::S_sub_proc: // sub_proc
      case symbol_kind::S_array: // array
      case symbol_kind::S_modifier: // modifier
      case symbol_kind::S_colon_sep_params: // colon_sep_params
      case symbol_kind::S_colon_sep_param: // colon_sep_param
      case symbol_kind::S_symbol: // symbol
      case symbol_kind::S_attrib_name: // attrib_name
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_built_in: // built_in
      case symbol_kind::S_attributes: // attributes
        yylhs.value.emplace< std::vector< std::pair<std::string, std::string> >  > ();
        break;

      case symbol_kind::S_modifiers: // modifiers
        yylhs.value.emplace< std::vector< std::string >  > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // complier: files
#line 130 "src/pparser.yy"
                                                                {
                                                                    cout <<  FMT_FG_GREEN << "PARSER complier: | files" << FMT_RESET << endl;
                                                                    cout << FMT_FG_YELLOW << "*********************** STOPPING **********************" << FMT_REVERSE << FMT_RESET << endl;
                                                                    cout << FMT_FG_YELLOW << "*                     Terminating.                    *" << FMT_REVERSE << FMT_RESET << endl;
                                                                    cout << FMT_FG_YELLOW << "************************* Done ************************" << FMT_REVERSE << FMT_RESET << endl;
                                                                }
#line 994 "build/pparser.tab.cc"
    break;

  case 3: // files: file
#line 141 "src/pparser.yy"
                                                                { cout << FMT_FG_YELLOW << "PARSER files: | file" << FMT_RESET << endl; }
#line 1000 "build/pparser.tab.cc"
    break;

  case 4: // files: files file
#line 142 "src/pparser.yy"
                                                                { cout << FMT_FG_YELLOW << "PARSER files: | files file" << FMT_RESET << endl; }
#line 1006 "build/pparser.tab.cc"
    break;

  case 5: // file: blocks END
#line 148 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW << "PARSER file: | blocks END_OF_FILE" << FMT_RESET << endl;
                                                                    cout << FMT_FG_YELLOW << "*******************************************************" << FMT_REVERSE << FMT_RESET << endl;
                                                                    cout << FMT_FG_YELLOW << "*                      End Of File                    *" << FMT_REVERSE << FMT_RESET << endl;
                                                                    cout << FMT_FG_YELLOW << "*******************************************************" << FMT_REVERSE << FMT_RESET << endl;
                                                                }
#line 1017 "build/pparser.tab.cc"
    break;

  case 6: // blocks: block
#line 159 "src/pparser.yy"
                                                                { cout << FMT_FG_YELLOW << "PARSER blocks: | block" << FMT_RESET << endl; }
#line 1023 "build/pparser.tab.cc"
    break;

  case 7: // blocks: blocks block
#line 160 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW << "PARSER blocks: | blocks block" << FMT_RESET << endl;
                                                                    lexer::instance().dump_config();
                                                                }
#line 1032 "build/pparser.tab.cc"
    break;

  case 8: // block: OPEN_BRACE expr CLOSE_BRACE
#line 169 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW << "PARSER block: | OPEN_BRACE expr CLOSE_BRACE" << FMT_RESET << endl;
                                                                }
#line 1040 "build/pparser.tab.cc"
    break;

  case 9: // block: OPEN_BRACE sub_proc CLOSE_BRACE
#line 172 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW << "PARSER block: | OPEN_BRACE sub_porc CLOSE_BRACE" << FMT_RESET << endl;
                                                                }
#line 1048 "build/pparser.tab.cc"
    break;

  case 10: // block: OPEN_BRACE array CLOSE_BRACE
#line 175 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW << "PARSER block: | OPEN_BRACE array CLOSE_BRACE" << FMT_RESET << endl;
                                                                }
#line 1056 "build/pparser.tab.cc"
    break;

  case 11: // block: OPEN_BRACE assign_stmt CLOSE_BRACE
#line 178 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW << "PARSER block: | OPEN_BRACE assign_stmt CLOSE_BRACE" << FMT_RESET << endl;
                                                                }
#line 1064 "build/pparser.tab.cc"
    break;

  case 12: // block: OPEN_BRACE qualafied_id CLOSE_BRACE
#line 181 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW << "PARSER block: | OPEN_BRACE qualafied_id CLOSE_BRACE" << FMT_RESET << endl;
                                                                    // bkp todo, look up in symbol table & do replace
                                                                    // bkp todo qualified lookup
                                                                    if(symbol_table.find(yystack_[1].value.as < std::string > ()) != symbol_table.end())
                                                                    {
                                                                        string val = symbol_table[yystack_[1].value.as < std::string > ()];
                                                                        cout << FMT_FG_RED << yystack_[1].value.as < std::string > () << " = " << val << FMT_RESET << endl;
                                                                    }
                                                                }
#line 1079 "build/pparser.tab.cc"
    break;

  case 13: // block: OPEN_BRACE built_in CLOSE_BRACE
#line 191 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW << "PARSER block: | OPEN_BRACE built_in CLOSE_BRACE" << FMT_RESET << endl;
                                                                    size_t len = yystack_[1].value.as < std::vector< std::pair<std::string, std::string> >  > ().size();
                                                                    int i = 0;
                                                                    for(; i < len; ++i)
                                                                    {
                                                                        if(yystack_[1].value.as < std::vector< std::pair<std::string, std::string> >  > ()[i].first == "file")
                                                                            break;
                                                                    }
                                                                    string path = yystack_[1].value.as < std::vector< std::pair<std::string, std::string> >  > ()[i].second;
                                                                    // read include path
                                                                    string sout;
                                                                    read_str(path, sout);
                                                                    //  append include path output to buffer
                                                                    string* p_rstr = lexer::instance().get_remaining();
                                                                    stringstream* include_buffer = lexer::instance().get_include_buffer();
                                                                    *include_buffer << sout << *p_rstr;

                                                                    cout << FMT_FG_RED << include_buffer->str() << FMT_RESET;
                                                                    // set the suffix a.k.a "current search buffer"
                                                                    lexer::instance().set_remaining( (*include_buffer).str() );
                                                                    lexer::instance().set_state(&sINITIAL);
                                                                    cout << FMT_FG_RED << "file=\"" << FMT_ITALIC << path << "\"" << FMT_RESET << endl;
                                                                }
#line 1108 "build/pparser.tab.cc"
    break;

  case 14: // assign_stmt: symbol EQUAL_SIGN NUMERIC_LITERAL
#line 220 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW << "PARSER assign_stmt: | symbol EQUAL_SIGN NUMERIC_LITERAL" << FMT_RESET << endl;
                                                                    // bkp todo, look up in symbol table & do replace
                                                                    // if(symbol_table.find($2) != symbol_table.end())
                                                                    // {
                                                                    //     symbol_table[$1] = $3;
                                                                    //     cout << $1 << " = " << $3 << endl;
                                                                    // }

                                                                    // if(auto iter = stab.find($1) != stab.end())
                                                                    // {
                                                                    //     //iter->second = $3;
                                                                    // }
                                                                    yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();
                                                                }
#line 1128 "build/pparser.tab.cc"
    break;

  case 15: // assign_stmt: symbol EQUAL_SIGN STRING_LITERAL
#line 235 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW << "PARSER assign_stmt: | symbol EQUAL_SIGN STRING_LITERAL=" << FMT_RESET << yystack_[0].value.as < std::string > () << "\n";
                                                                    yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > ();
                                                                }
#line 1137 "build/pparser.tab.cc"
    break;

  case 16: // expr: STRING_LITERAL
#line 245 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW << "PARSER expr: | STRING_LITERAL" << FMT_RESET << endl;
                                                                    yylhs.value.as < std::string > ()=yystack_[0].value.as < std::string > ();
                                                                }
#line 1146 "build/pparser.tab.cc"
    break;

  case 17: // expr: symbol
#line 249 "src/pparser.yy"
                                                                {
                                                                    cout << "PARSER expr: | symbol\n"
                                                                        << FMT_FG_DARK_GREY << FMT_ITALIC
                                                                        << "file: \"" << __FILE__ << "\" - " << "line: \"" << __LINE__ << "\""
                                                                        << FMT_RESET << endl;
                                                                }
#line 1157 "build/pparser.tab.cc"
    break;

  case 18: // expr: expr VBAR modifiers
#line 255 "src/pparser.yy"
                                                                {
                                                                     cout << "PARSER expr: | symbol VBAR modifiers\n";
                                                                }
#line 1165 "build/pparser.tab.cc"
    break;

  case 19: // expr: MINUS expr
#line 258 "src/pparser.yy"
                                                                {
                                                                    cout << "PARSER expr: | expr\n";
                                                                }
#line 1173 "build/pparser.tab.cc"
    break;

  case 20: // expr: expr PLUS_SIGN expr
#line 261 "src/pparser.yy"
                                                                {
                                                                    cout << "PARSER expr: | expr PLUS_SIGN expr\n";
                                                                }
#line 1181 "build/pparser.tab.cc"
    break;

  case 21: // expr: expr MINUS expr
#line 264 "src/pparser.yy"
                                                                {
                                                                    cout << "PARSER expr: | expr MINUS expr\n";
                                                                }
#line 1189 "build/pparser.tab.cc"
    break;

  case 22: // expr: expr ASTERISK expr
#line 267 "src/pparser.yy"
                                                                {
                                                                    cout << "PARSER expr: | expr ASTERISK expr\n";
                                                                }
#line 1197 "build/pparser.tab.cc"
    break;

  case 23: // expr: expr SLASH expr
#line 270 "src/pparser.yy"
                                                                {
                                                                    cout << "PARSER expr: | expr SLASH expr\n";
                                                                }
#line 1205 "build/pparser.tab.cc"
    break;

  case 24: // expr: expr LESS_THAN expr
#line 273 "src/pparser.yy"
                                                                {
                                                                    cout << "PARSER expr: | expr LESS_THAN expr\n";
                                                                }
#line 1213 "build/pparser.tab.cc"
    break;

  case 25: // expr: expr GREATER_THAN expr
#line 276 "src/pparser.yy"
                                                                {
                                                                    cout << "PARSER expr: | | expr GREATER_THAN expr\n";
                                                                }
#line 1221 "build/pparser.tab.cc"
    break;

  case 26: // expr: expr GREATER_THAN_EQUAL expr
#line 279 "src/pparser.yy"
                                                                {
                                                                    cout << "PARSER expr: | expr GREATER_THAN_EQUAL expr\n";
                                                                }
#line 1229 "build/pparser.tab.cc"
    break;

  case 27: // expr: expr LESS_THAN_EQUAL expr
#line 282 "src/pparser.yy"
                                                                {
                                                                    cout << "PARSER expr: | expr LESS_THAN_EQUAL expr\n";
                                                                }
#line 1237 "build/pparser.tab.cc"
    break;

  case 28: // expr: expr NOT_EQUAL expr
#line 285 "src/pparser.yy"
                                                                {
                                                                    cout << "PARSER expr: | expr NOT_EQUAL expr\n";
                                                                }
#line 1245 "build/pparser.tab.cc"
    break;

  case 29: // expr: LPAREN expr RPAREN
#line 288 "src/pparser.yy"
                                                                {
                                                                    cout << "PARSER expr: | LPAREN expr RPAREN\n";
                                                                }
#line 1253 "build/pparser.tab.cc"
    break;

  case 30: // qualafied_id: symbol DOT IDENTIFIER
#line 296 "src/pparser.yy"
                                                                { cout << FMT_FG_YELLOW << "PARSER qualafied_id: | symbol DOT IDENTIFIER" << FMT_RESET << endl; }
#line 1259 "build/pparser.tab.cc"
    break;

  case 31: // qualafied_id: symbol INDIRECT_MEMBER IDENTIFIER
#line 297 "src/pparser.yy"
                                                                { cout << FMT_FG_YELLOW << "PARSER qualafied_id: | symbol INDIRECT_MEMBER IDENTIFIER" << FMT_RESET << endl; }
#line 1265 "build/pparser.tab.cc"
    break;

  case 32: // qualafied_id: qualafied_id DOT IDENTIFIER
#line 298 "src/pparser.yy"
                                                                { cout << FMT_FG_YELLOW << "PARSER qualafied_id: | qualafied_id DOT IDENTIFIER" << FMT_RESET << endl; }
#line 1271 "build/pparser.tab.cc"
    break;

  case 33: // qualafied_id: qualafied_id INDIRECT_MEMBER IDENTIFIER
#line 299 "src/pparser.yy"
                                                                { cout << FMT_FG_YELLOW << "PARSER qualafied_id: | qualafied_id INDIRECT_MEMBER IDENTIFIER" << FMT_RESET << endl; }
#line 1277 "build/pparser.tab.cc"
    break;

  case 34: // sub_proc: symbol LPAREN params RPAREN
#line 305 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW << "PARSER sub_proc: | symbol LPAREN params RPAREN" << FMT_RESET << endl;
                                                                    yylhs.value.as < std::string > ()=yystack_[3].value.as < std::string > ();
                                                                }
#line 1286 "build/pparser.tab.cc"
    break;

  case 35: // array: symbol OPEN_BRACKET NUMERIC_LITERAL CLOSE_BRACKET
#line 314 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW
                                                                        << "PARSER array: | symbol=\"" << yystack_[3].value.as < std::string > () << "\" OPEN_BRACKET NUMERIC_LITERAL=\"" << yystack_[1].value.as < std::string > () << "\" CLOSE_BRACKET"
                                                                        << FMT_RESET << endl;
                                                                    yylhs.value.as < std::string > ()=yystack_[3].value.as < std::string > ();
                                                                }
#line 1297 "build/pparser.tab.cc"
    break;

  case 36: // params: param
#line 326 "src/pparser.yy"
                                                                { cout << "PARSER params: | param\n" << endl; }
#line 1303 "build/pparser.tab.cc"
    break;

  case 37: // params: params symbol
#line 327 "src/pparser.yy"
                                                                { cout << FMT_FG_YELLOW << "PARSER qualafied_id: | params COMMA symbol" << FMT_RESET << endl; }
#line 1309 "build/pparser.tab.cc"
    break;

  case 38: // param: symbol COMMA
#line 334 "src/pparser.yy"
                                                                { cout << FMT_FG_YELLOW << "PARSER param: | symbol" << FMT_RESET << endl; }
#line 1315 "build/pparser.tab.cc"
    break;

  case 39: // modifiers: modifier
#line 341 "src/pparser.yy"
                                                                {
                                                                     std::vector< std::string > v;
                                                                     v.push_back(yystack_[0].value.as < std::string > ());
                                                                     yylhs.value.as < std::vector< std::string >  > () = v;
                                                                }
#line 1325 "build/pparser.tab.cc"
    break;

  case 40: // modifiers: modifiers VBAR modifier
#line 346 "src/pparser.yy"
                                                                {
                                                                    yystack_[2].value.as < std::vector< std::string >  > ().push_back(yystack_[0].value.as < std::string > ());
                                                                    yylhs.value.as < std::vector< std::string >  > () = yystack_[2].value.as < std::vector< std::string >  > ();
                                                                }
#line 1334 "build/pparser.tab.cc"
    break;

  case 41: // modifier: modifier colon_sep_params
#line 355 "src/pparser.yy"
                                                                {
                                                                    cout << "PARSER modifier : | " << FMT_FG_MAGENTA << " modifier=" << yystack_[1].value.as < std::string > () << " COLON NUMERIC_LITERAL=" << yystack_[0].value.as < std::string > () << FMT_RESET << "\n";
                                                                    // $1.params.append("|");
                                                                    // $1.params.append($2);
                                                                }
#line 1344 "build/pparser.tab.cc"
    break;

  case 42: // modifier: CAPITALIZE
#line 360 "src/pparser.yy"
                                                                {
                                                                    cout << "PARSER modifier: | CAPITALIZE\n";
                                                                    // modifier_t m;
                                                                    // m.name = "capitalize";
                                                                    // m.params = "";
                                                                    // $$ = m;
                                                                    yylhs.value.as < std::string > () = "capitalize";
                                                                }
#line 1357 "build/pparser.tab.cc"
    break;

  case 43: // modifier: CAT
#line 368 "src/pparser.yy"
                                                                { cout  << "PARSER modifier: | CAT\n"; yylhs.value.as < std::string > ()="cat"; }
#line 1363 "build/pparser.tab.cc"
    break;

  case 44: // modifier: COUNT_CHARACTERS
#line 369 "src/pparser.yy"
                                                                { cout  << "PARSER modifier: | COUNT_CHARACTERS\n"; yylhs.value.as < std::string > ()="count_characters"; }
#line 1369 "build/pparser.tab.cc"
    break;

  case 45: // modifier: COUNT_SENTENCES
#line 370 "src/pparser.yy"
                                                                { cout  << "PARSER modifier: | COUNT_SENTENCES\n"; yylhs.value.as < std::string > ()="count_sentences"; }
#line 1375 "build/pparser.tab.cc"
    break;

  case 46: // modifier: COUNT_PARAGRAPHS
#line 371 "src/pparser.yy"
                                                                { cout  << "PARSER modifier: | COUNT_PARAGRAPHS\n"; yylhs.value.as < std::string > ()="count_paragraphs"; }
#line 1381 "build/pparser.tab.cc"
    break;

  case 47: // modifier: COUNT_WORDS
#line 372 "src/pparser.yy"
                                                                { cout  << "PARSER modifier: | COUNT_WORDS\n"; yylhs.value.as < std::string > ()="count_words"; }
#line 1387 "build/pparser.tab.cc"
    break;

  case 48: // modifier: DATE_FORMAT
#line 373 "src/pparser.yy"
                                                                { cout  << "PARSER modifier: | DATE_FORMAT\n"; yylhs.value.as < std::string > ()="date_format"; }
#line 1393 "build/pparser.tab.cc"
    break;

  case 49: // modifier: DEFAULT
#line 374 "src/pparser.yy"
                                                                { cout  << "PARSER modifier: | DEFAULT\n"; yylhs.value.as < std::string > ()="default"; }
#line 1399 "build/pparser.tab.cc"
    break;

  case 50: // modifier: ESCAPE
#line 375 "src/pparser.yy"
                                                                { cout  << "PARSER modifier: | ESCAPE\n"; yylhs.value.as < std::string > ()="esacpe"; }
#line 1405 "build/pparser.tab.cc"
    break;

  case 51: // modifier: INDENT
#line 376 "src/pparser.yy"
                                                                { cout  << "PARSER modifier: | INDENT\n"; yylhs.value.as < std::string > ()="indent"; }
#line 1411 "build/pparser.tab.cc"
    break;

  case 52: // modifier: STRIP
#line 377 "src/pparser.yy"
                                                                { cout  << "PARSER modifier: | STRIPS\n"; yylhs.value.as < std::string > ()="strip"; }
#line 1417 "build/pparser.tab.cc"
    break;

  case 53: // modifier: NL2BR
#line 378 "src/pparser.yy"
                                                                { cout  << "PARSER modifier: | NL2BR\n"; yylhs.value.as < std::string > ()="nl2br"; }
#line 1423 "build/pparser.tab.cc"
    break;

  case 54: // modifier: REPLACE
#line 379 "src/pparser.yy"
                                                                { cout  << "PARSER modifier: | REPLACE\n"; yylhs.value.as < std::string > ()="replace"; }
#line 1429 "build/pparser.tab.cc"
    break;

  case 55: // modifier: REGEX_REPLACE
#line 380 "src/pparser.yy"
                                                                { cout  << "PARSER modifier: | REGEX_REPLACE\n"; yylhs.value.as < std::string > ()="regex_replsce"; }
#line 1435 "build/pparser.tab.cc"
    break;

  case 56: // modifier: SPACIFY
#line 381 "src/pparser.yy"
                                                                { cout  << "PARSER modifier: | SPACIFY\n"; yylhs.value.as < std::string > ()="spacify"; }
#line 1441 "build/pparser.tab.cc"
    break;

  case 57: // modifier: STRING_FORMAT
#line 382 "src/pparser.yy"
                                                                { cout  << "PARSER modifier: | STRING_FORMAT\n"; yylhs.value.as < std::string > ()="string_format"; }
#line 1447 "build/pparser.tab.cc"
    break;

  case 58: // modifier: STRIP_TAGS
#line 383 "src/pparser.yy"
                                                                { cout  << "PARSER modifier: | STIP_TAGS\n"; yylhs.value.as < std::string > ()="strip_tags"; }
#line 1453 "build/pparser.tab.cc"
    break;

  case 59: // modifier: TRUNCATE
#line 384 "src/pparser.yy"
                                                                {
                                                                    cout  << "PARSER modifier: | " << FMT_FG_MAGENTA << " TRUNCATE" << FMT_RESET << endl; yylhs.value.as < std::string > ()="truncate";
                                                                    // modifier_t m;
                                                                    // m.name = "truncate";
                                                                    // m.params = "";
                                                                    // $$ = m;
                                                                    yylhs.value.as < std::string > () = "truncate";
                                                                }
#line 1466 "build/pparser.tab.cc"
    break;

  case 60: // modifier: UPPER
#line 392 "src/pparser.yy"
                                                                { cout  << "PARSER modifier: | UPPER\n"; yylhs.value.as < std::string > ()="upper"; }
#line 1472 "build/pparser.tab.cc"
    break;

  case 61: // modifier: LOWER
#line 393 "src/pparser.yy"
                                                                { cout  << "PARSER modifier: | LOWER\n"; yylhs.value.as < std::string > ()="lower"; }
#line 1478 "build/pparser.tab.cc"
    break;

  case 62: // modifier: WORDWRAP
#line 394 "src/pparser.yy"
                                                                { cout  << "PARSER modifier: | WORDWRAP\n"; yylhs.value.as < std::string > ()="word_wrap"; }
#line 1484 "build/pparser.tab.cc"
    break;

  case 63: // colon_sep_params: colon_sep_param
#line 401 "src/pparser.yy"
                                                                { cout << "colon_sep_params: | colon_sep_param\n"; yylhs.value.as < std::string > ()=yystack_[0].value.as < std::string > (); }
#line 1490 "build/pparser.tab.cc"
    break;

  case 64: // colon_sep_params: colon_sep_params colon_sep_param
#line 402 "src/pparser.yy"
                                                                { cout << "colon_sep_params: | colon_sep_params colon_sep_param" << endl; yylhs.value.as < std::string > ()=yystack_[1].value.as < std::string > ().append(yystack_[0].value.as < std::string > ()); }
#line 1496 "build/pparser.tab.cc"
    break;

  case 65: // colon_sep_param: COLON NUMERIC_LITERAL
#line 409 "src/pparser.yy"
                                                                { cout << "colon_sep_param: | COLON NUMERIC_LITERAL" << endl; yylhs.value.as < std::string > ()=":" + yystack_[0].value.as < std::string > (); }
#line 1502 "build/pparser.tab.cc"
    break;

  case 66: // symbol: DOLLAR_SIGN IDENTIFIER
#line 415 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW << "PARSER symbol: | IDENTIFIER=\"" << yystack_[0].value.as < std::string > () << "\"" << FMT_RESET << endl;
                                                                    yylhs.value.as < std::string > ()=yystack_[0].value.as < std::string > ();
                                                                }
#line 1511 "build/pparser.tab.cc"
    break;

  case 67: // symbol: HASH_MARK CONST_ID HASH_MARK
#line 419 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW << "PARSER symbol: | HASH_MARK CONST_ID=\"" << yystack_[1].value.as < std::string > () << "\"" << FMT_RESET << endl;
                                                                    yylhs.value.as < std::string > ()=yystack_[1].value.as < std::string > ();
                                                                }
#line 1520 "build/pparser.tab.cc"
    break;

  case 68: // built_in: CONFIG_LOAD attributes
#line 428 "src/pparser.yy"
                                                                {   cout << FMT_FG_YELLOW << "PARSER built_in: | CONFIG_LOAD FILE_ATTRIB=\"" << yystack_[1].value.as < std::string > () << "\" EQUAL STRING_LITERAL=\"" << "TEST" << "\"" << FMT_RESET << endl;  }
#line 1526 "build/pparser.tab.cc"
    break;

  case 69: // built_in: INCLUDE attributes
#line 429 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW << "PARSER built_in: | INCLUDE attributes" << FMT_RESET << endl;
                                                                    yylhs.value.as < std::vector< std::pair<std::string, std::string> >  > () = yystack_[0].value.as < std::vector< std::pair<std::string, std::string> >  > ();
                                                                }
#line 1535 "build/pparser.tab.cc"
    break;

  case 70: // built_in: REQUIRE attributes
#line 433 "src/pparser.yy"
                                                                { cout << FMT_FG_YELLOW << "PARSER built_in: | REQUIRE FILE_ATTRIB=\"%s\" EQUAL STRING_LITERAL=\"\"" << FMT_RESET << endl; }
#line 1541 "build/pparser.tab.cc"
    break;

  case 71: // built_in: REQUIRE_ONCE attributes
#line 434 "src/pparser.yy"
                                                                { cout << FMT_FG_YELLOW << "PARSER built_in: | REQUIRE_once FILE_ATTRIB=\"%s\" EQUAL STRING_LITERAL=\"\"" << FMT_RESET << endl; }
#line 1547 "build/pparser.tab.cc"
    break;

  case 72: // built_in: INSERT attributes
#line 435 "src/pparser.yy"
                                                                { cout << FMT_FG_YELLOW << "PARSER built_in: | INSERT FILE_ATTRIB=\"%s\" EQUAL STRING_LITERAL=\"\"" << FMT_RESET << endl; }
#line 1553 "build/pparser.tab.cc"
    break;

  case 73: // built_in: ASSIGN attributes
#line 436 "src/pparser.yy"
                                                                { cout << FMT_FG_YELLOW << "PARSER built_in: | ASSIGN FILE_ATTRIB=\"%s\" EQUAL STRING_LITERAL=\"\"" << FMT_RESET << endl; }
#line 1559 "build/pparser.tab.cc"
    break;

  case 74: // built_in: ISSET attributes
#line 437 "src/pparser.yy"
                                                                { cout << FMT_FG_YELLOW << "PARSER built_in: | ISSET FILE_ATTRIB=\"%s\" EQUAL STRING_LITERAL=\"\"" << FMT_RESET << endl; }
#line 1565 "build/pparser.tab.cc"
    break;

  case 75: // built_in: VERSION attributes
#line 438 "src/pparser.yy"
                                                                { cout << FMT_FG_YELLOW << "PARSER built_in: | VERSION FILE_ATTRIB=\"%s\" EQUAL STRING_LITERAL=\"\"" << FMT_RESET << endl; }
#line 1571 "build/pparser.tab.cc"
    break;

  case 76: // attributes: attrib
#line 444 "src/pparser.yy"
                                                               {
                                                                    cout << FMT_FG_YELLOW << "PARSER attribute: | push -> attrib={name=\"" << yystack_[0].value.as <  std::pair<std::string, std::string>  > ().first  << "\"; value=\"" << yystack_[0].value.as <  std::pair<std::string, std::string>  > ().second << "\"}\n" << FMT_RESET << endl;
                                                                    std::pair<std::string, std::string>  p(yystack_[0].value.as <  std::pair<std::string, std::string>  > ());
                                                                    std::vector< std::pair<std::string, std::string> > v;
                                                                    v.push_back( p );
                                                                    yylhs.value.as < std::vector< std::pair<std::string, std::string> >  > () = v;
                                                               }
#line 1583 "build/pparser.tab.cc"
    break;

  case 77: // attributes: attributes attrib
#line 451 "src/pparser.yy"
                                                               {
                                                                    cout << FMT_FG_YELLOW << "PARSER attribute: | attributes : push-> attrib={name=\"" << yystack_[0].value.as <  std::pair<std::string, std::string>  > ().first  << "\"; value=\"" << yystack_[0].value.as <  std::pair<std::string, std::string>  > ().second << "\"}\n" << FMT_RESET << endl;
                                                                    yystack_[1].value.as < std::vector< std::pair<std::string, std::string> >  > ().push_back( yystack_[0].value.as <  std::pair<std::string, std::string>  > () );
                                                                    yylhs.value.as < std::vector< std::pair<std::string, std::string> >  > () = yystack_[1].value.as < std::vector< std::pair<std::string, std::string> >  > ();
                                                               }
#line 1593 "build/pparser.tab.cc"
    break;

  case 78: // attrib: VALUE_ATTRIB EQUAL_SIGN STRING_LITERAL
#line 461 "src/pparser.yy"
                                                               {
                                                                    cout << FMT_FG_YELLOW << "PARSER name_value: | VALUE_ATTRIB=\""
                                                                        << yystack_[2].value.as < std::string > () << "\" EQUAL_SIGN STRING_LITERAL=\""
                                                                        << buf << "\"" << FMT_RESET << endl;

                                                                    std::pair<std::string, std::string>  pair(yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ());
                                                                    yylhs.value.as <  std::pair<std::string, std::string>  > () = pair;
                                                               }
#line 1606 "build/pparser.tab.cc"
    break;

  case 79: // attrib: VAR_ATTRIB EQUAL_SIGN STRING_LITERAL
#line 469 "src/pparser.yy"
                                                               {
                                                                    cout << FMT_FG_YELLOW
                                                                        << "PARSER name_value: | VAR_ATTRIB=\"\" EQUAL_SIGN STRING_LITERAL=\"\""
                                                                        << FMT_FG_GREEN << FMT_RESET << endl;

                                                                    std::pair<std::string, std::string>  pair(yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ());
                                                                    yylhs.value.as <  std::pair<std::string, std::string>  > () = pair;
                                                               }
#line 1619 "build/pparser.tab.cc"
    break;

  case 80: // attrib: FILE_ATTRIB EQUAL_SIGN STRING_LITERAL
#line 477 "src/pparser.yy"
                                                               {
                                                                    cout << FMT_FG_YELLOW
                                                                        << "PARSER name_value: | FILE_ATTRIB=\""
                                                                        << yystack_[2].value.as < std::string > () << "\" EQUAL_SIGN STRING_LITERAL=\""
                                                                        << yystack_[0].value.as < std::string > () << "\""
                                                                        << FMT_RESET << endl;

                                                                    std::pair<std::string, std::string>  pair(yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ());
                                                                    yylhs.value.as <  std::pair<std::string, std::string>  > () = pair;
                                                               }
#line 1634 "build/pparser.tab.cc"
    break;

  case 81: // attrib: attrib_name EQUAL_SIGN STRING_LITERAL
#line 487 "src/pparser.yy"
                                                               {
                                                                      cout << FMT_FG_YELLOW
                                                                        << "PARSER name_value: | " << yystack_[2].value.as < std::string > () << "=\""
                                                                        << yystack_[2].value.as < std::string > () << "\" EQUAL_SIGN STRING_LITERAL=\""
                                                                        << yystack_[0].value.as < std::string > () << "\""
                                                                        << FMT_RESET << endl;

                                                                    std::pair<std::string, std::string>  pair(yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ());
                                                                    yylhs.value.as <  std::pair<std::string, std::string>  > () = pair;
                                                               }
#line 1649 "build/pparser.tab.cc"
    break;

  case 82: // attrib_name: VALUE_ATTRIB
#line 503 "src/pparser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1655 "build/pparser.tab.cc"
    break;

  case 83: // attrib_name: FROM_ATTRIB
#line 504 "src/pparser.yy"
      { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1661 "build/pparser.tab.cc"
    break;

  case 84: // attrib_name: ITEM_ATTRIB
#line 505 "src/pparser.yy"
      { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1667 "build/pparser.tab.cc"
    break;

  case 85: // attrib_name: KEY_ATTRIB
#line 506 "src/pparser.yy"
      { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1673 "build/pparser.tab.cc"
    break;

  case 86: // attrib_name: NAME_ATTRIB
#line 507 "src/pparser.yy"
      { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1679 "build/pparser.tab.cc"
    break;


#line 1683 "build/pparser.tab.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        std::string msg = YY_("syntax error");
        error (YY_MOVE (msg));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

#if YYDEBUG || 0
  const char *
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0









  const signed char parser::yypact_ninf_ = -66;

  const signed char parser::yytable_ninf_ = -1;

  const signed char
  parser::yypact_[] =
  {
     -65,    -3,    14,   -65,   -66,     9,   -66,    85,    85,    85,
      85,    85,    85,    85,    85,   -66,     2,     4,   -11,   -11,
     -47,   -58,    -4,   -45,   -42,     0,   -39,   -66,   -66,   -66,
     -66,   -63,   -62,   -40,   -66,   -66,   -66,   -66,    85,   -66,
     -35,    85,    85,    85,    85,    85,    85,    85,   -66,   -25,
     -48,   -66,    -6,   -66,    87,   -66,   -11,   -11,   -11,   -11,
     -11,   -11,   -11,   -11,   -11,    46,   -66,    47,   -66,   -66,
      49,    56,   -44,    57,     1,   -66,    61,    62,    63,   -66,
      64,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,
     -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,
     -66,   -66,   -66,   -66,    20,    21,   -14,   -14,   -14,   -14,
     -14,   -43,   -43,    -6,    -6,   -66,   -66,   -66,    17,   -53,
     -66,    24,   -66,   -66,   -66,   -66,   -66,   -66,   -66,    87,
      74,    21,   -66,   -66,   -66,   -66,   -66,    21,   -66,   -66
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     2,     3,     0,     6,     0,     0,     0,
       0,     0,     0,     0,     0,    16,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    17,     0,     1,     4,     5,
       7,     0,     0,     0,    83,    85,    86,    84,    68,    76,
       0,    69,    70,    71,    72,    73,    74,    75,    66,     0,
       0,    17,    19,    11,     0,     8,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    12,     0,     9,    10,
       0,     0,     0,     0,     0,    13,     0,     0,     0,    77,
       0,    67,    29,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    61,    60,    52,    53,    55,    54,    56,
      57,    58,    59,    62,    18,    39,    26,    27,    28,    24,
      25,    20,    21,    22,    23,    33,    32,    31,     0,     0,
      36,     0,    30,    15,    14,    79,    78,    80,    81,     0,
       0,    41,    63,    35,    34,    37,    38,    40,    65,    64
  };

  const short
  parser::yypgoto_[] =
  {
     -66,   -66,   -66,    93,   -66,    94,   -66,    44,   -66,   -66,
     -66,   -66,   -66,   -66,   -31,   -66,   -15,    -1,   -66,   142,
     102,   -66
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,     2,     3,     4,     5,     6,    20,    21,    22,    23,
      24,   119,   120,   104,   105,   131,   132,    51,    26,    38,
      39,    40
  };

  const unsigned char
  parser::yytable_[] =
  {
      25,     7,     8,     9,    10,    11,    12,    13,    15,    29,
       1,    14,    54,    65,    27,    16,    15,    70,    55,    17,
     123,   124,    54,    48,    16,   134,    49,    54,    17,    53,
      82,    68,    76,    77,    69,    56,    57,    75,    58,    59,
      60,    61,    62,    63,    64,    56,    57,    81,    58,    59,
      60,    61,    62,    63,    64,    78,    54,    16,    63,    64,
      80,    17,    50,    52,    54,    16,    18,   115,   116,    17,
     117,   121,    66,    71,    18,    67,   118,    72,   122,    73,
     125,   126,   127,   128,     1,    61,    62,    63,    64,    19,
     129,   133,   130,   136,   138,    74,    28,    19,   137,    30,
     106,   107,   108,   109,   110,   111,   112,   113,   114,    31,
      32,    33,    34,    35,    36,    37,   139,     0,   135,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
      79,     0,     0,    79,    79,    79,    79,    79,    79,    79,
      41,    42,    43,    44,    45,    46,    47
  };

  const short
  parser::yycheck_[] =
  {
       1,     4,     5,     6,     7,     8,     9,    10,    19,     0,
      75,    14,    70,    17,     0,    68,    19,    17,    76,    72,
      19,    20,    70,    21,    68,    78,    22,    70,    72,    76,
      78,    76,    95,    95,    76,    93,    94,    76,    96,    97,
      98,    99,   100,   101,   102,    93,    94,    72,    96,    97,
      98,    99,   100,   101,   102,    95,    70,    68,   101,   102,
      95,    72,    18,    19,    70,    68,    77,    21,    21,    72,
      21,    72,    76,    73,    77,    79,    20,    77,    21,    79,
      19,    19,    19,    19,    75,    99,   100,   101,   102,   100,
      70,    74,    71,    69,    20,    95,     3,   100,   129,     5,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    24,
      25,    26,    27,    28,    29,    30,   131,    -1,   119,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      38,    -1,    -1,    41,    42,    43,    44,    45,    46,    47,
       8,     9,    10,    11,    12,    13,    14
  };

  const signed char
  parser::yystos_[] =
  {
       0,    75,   106,   107,   108,   109,   110,     4,     5,     6,
       7,     8,     9,    10,    14,    19,    68,    72,    77,   100,
     111,   112,   113,   114,   115,   122,   123,     0,   108,     0,
     110,    24,    25,    26,    27,    28,    29,    30,   124,   125,
     126,   124,   124,   124,   124,   124,   124,   124,    21,    22,
     112,   122,   112,    76,    70,    76,    93,    94,    96,    97,
      98,    99,   100,   101,   102,    17,    76,    79,    76,    76,
      17,    73,    77,    79,    95,    76,    95,    95,    95,   125,
      95,    72,    78,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,   118,   119,   112,   112,   112,   112,
     112,   112,   112,   112,   112,    21,    21,    21,    20,   116,
     117,   122,    21,    19,    20,    19,    19,    19,    19,    70,
      71,   120,   121,    74,    78,   122,    69,   119,    20,   121
  };

  const signed char
  parser::yyr1_[] =
  {
       0,   105,   106,   107,   107,   108,   109,   109,   110,   110,
     110,   110,   110,   110,   111,   111,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     113,   113,   113,   113,   114,   115,   116,   116,   117,   118,
     118,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   120,   120,   121,   122,   122,   123,   123,
     123,   123,   123,   123,   123,   123,   124,   124,   125,   125,
     125,   125,   126,   126,   126,   126,   126
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     1,     2,     2,     1,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     3,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     4,     4,     1,     2,     2,     1,
       3,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     2,     3,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     3,
       3,     3,     1,     1,     1,     1,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "END", "error", "\"invalid token\"", "CAPTURE", "CONFIG_LOAD",
  "INCLUDE", "REQUIRE", "REQUIRE_ONCE", "INSERT", "ASSIGN", "ISSET",
  "SECTION", "LDELIM", "RDELIM", "VERSION", "CYCLE", "COUNTER",
  "INDIRECT_MEMBER", "ARRAY", "STRING_LITERAL", "NUMERIC_LITERAL",
  "IDENTIFIER", "CONST_ID", "CONST_SYMBOL", "VAR_ATTRIB", "VALUE_ATTRIB",
  "FILE_ATTRIB", "FROM_ATTRIB", "KEY_ATTRIB", "NAME_ATTRIB", "ITEM_ATTRIB",
  "FILE_NAME", "CAPITALIZE", "CAT", "COUNT_CHARACTERS", "COUNT_SENTENCES",
  "COUNT_PARAGRAPHS", "COUNT_WORDS", "DATE_FORMAT", "DEFAULT", "ESCAPE",
  "INDENT", "LOWER", "UPPER", "STRIP", "NL2BR", "REGEX_REPLACE", "REPLACE",
  "SPACIFY", "STRING_FORMAT", "STRIP_TAGS", "TRUNCATE", "WORDWRAP",
  "CARROT", "OPEN_PAREN", "CLOSE_PAREN", "DASH", "BACKSLASH",
  "QUESTION_MARK", "SEMI_COLON", "DOUBLE_QUOTE", "SINGLE_QUOTE",
  "BACK_SLASH", "AT", "AMPERSAND", "AND", "OR", "NOT", "DOLLAR_SIGN",
  "COMMA", "VBAR", "COLON", "HASH_MARK", "OPEN_BRACKET", "CLOSE_BRACKET",
  "OPEN_BRACE", "CLOSE_BRACE", "LPAREN", "RPAREN", "DOT", "END_OF_FILES",
  "MATCH", "UNDEFINED", "WHITESPACE", "ANYTHING", "VALID_CHAR",
  "SKIP_TOKEN", "IFX", "ELSE", "ELSEIF", "IF", "WHILE", "BREAK",
  "GREATER_THAN_EQUAL", "LESS_THAN_EQUAL", "EQUAL_SIGN", "NOT_EQUAL",
  "LESS_THAN", "GREATER_THAN", "PLUS_SIGN", "MINUS", "ASTERISK", "SLASH",
  "PERCENT_SIGN", "UMINUS", "$accept", "complier", "files", "file",
  "blocks", "block", "assign_stmt", "expr", "qualafied_id", "sub_proc",
  "array", "params", "param", "modifiers", "modifier", "colon_sep_params",
  "colon_sep_param", "symbol", "built_in", "attributes", "attrib",
  "attrib_name", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   130,   130,   141,   142,   148,   159,   160,   169,   172,
     175,   178,   181,   191,   220,   235,   245,   249,   255,   258,
     261,   264,   267,   270,   273,   276,   279,   282,   285,   288,
     296,   297,   298,   299,   305,   314,   326,   327,   334,   341,
     346,   355,   360,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     392,   393,   394,   401,   402,   409,   415,   419,   428,   429,
     433,   434,   435,   436,   437,   438,   444,   451,   461,   469,
     477,   487,   503,   504,   505,   506,   507
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 2098 "build/pparser.tab.cc"

#line 510 "src/pparser.yy"


bool is_name(const std::pair<string, string>& p, const string& str)
{
    return (p.first == str);
}

char* STRDUP(char* s)
{
    char* dup = (char*)malloc(strlen(s) + 1);
    strcpy(dup, s);
    return dup;
}

nvalue* alloc_nvalue(char* name, char* value)
{
    nvalue* nval = (nvalue*)malloc( sizeof( nvalue ) );
    nval->name = STRDUP(name);
    nval->value = STRDUP(value);
    nval->next = 0;
    return nval;
}

void free_nvalue(nvalue* nv)
{
    free(nv->name);
    free(nv->value);
    free(nv);
}

void free_all_nvalues()
{
    if(!pnv_head)
        return;

    nvalue* cur = pnv_head;
    nvalue* next = pnv_head->next;
    while(cur != 0)
    {
        free_nvalue(cur);
        cur = next;
        next = cur->next;
    }
}

namespace yy
{
    auto yylex() -> parser::symbol_type
    {
        return lex();
    }

    auto parser::error(const std::string& msg) -> void
    {
        std::cerr << msg << '\n';
    }
}
