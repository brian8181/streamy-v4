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
#line 49 "src/pparser.yy"

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


#line 120 "build/pparser.tab.cc"


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
#line 193 "build/pparser.tab.cc"

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
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_qualafied_id: // qualafied_id
      case symbol_kind::S_sub_proc: // sub_proc
      case symbol_kind::S_array: // array
      case symbol_kind::S_symbol: // symbol
      case symbol_kind::S_modifier: // modifier
      case symbol_kind::S_attrib_name: // attrib_name
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_built_in: // built_in
      case symbol_kind::S_attributes: // attributes
        value.YY_MOVE_OR_COPY< std::vector< std::pair<std::string, std::string> >  > (YY_MOVE (that.value));
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
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_qualafied_id: // qualafied_id
      case symbol_kind::S_sub_proc: // sub_proc
      case symbol_kind::S_array: // array
      case symbol_kind::S_symbol: // symbol
      case symbol_kind::S_modifier: // modifier
      case symbol_kind::S_attrib_name: // attrib_name
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_built_in: // built_in
      case symbol_kind::S_attributes: // attributes
        value.move< std::vector< std::pair<std::string, std::string> >  > (YY_MOVE (that.value));
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
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_qualafied_id: // qualafied_id
      case symbol_kind::S_sub_proc: // sub_proc
      case symbol_kind::S_array: // array
      case symbol_kind::S_symbol: // symbol
      case symbol_kind::S_modifier: // modifier
      case symbol_kind::S_attrib_name: // attrib_name
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_built_in: // built_in
      case symbol_kind::S_attributes: // attributes
        value.copy< std::vector< std::pair<std::string, std::string> >  > (that.value);
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
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_qualafied_id: // qualafied_id
      case symbol_kind::S_sub_proc: // sub_proc
      case symbol_kind::S_array: // array
      case symbol_kind::S_symbol: // symbol
      case symbol_kind::S_modifier: // modifier
      case symbol_kind::S_attrib_name: // attrib_name
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_built_in: // built_in
      case symbol_kind::S_attributes: // attributes
        value.move< std::vector< std::pair<std::string, std::string> >  > (that.value);
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
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_qualafied_id: // qualafied_id
      case symbol_kind::S_sub_proc: // sub_proc
      case symbol_kind::S_array: // array
      case symbol_kind::S_symbol: // symbol
      case symbol_kind::S_modifier: // modifier
      case symbol_kind::S_attrib_name: // attrib_name
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_built_in: // built_in
      case symbol_kind::S_attributes: // attributes
        yylhs.value.emplace< std::vector< std::pair<std::string, std::string> >  > ();
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
#line 116 "src/pparser.yy"
                                                                {
                                                                    cout <<  FMT_FG_GREEN << "PARSER complier: | files" << FMT_RESET << endl;
                                                                    cout << FMT_FG_YELLOW << "*********************** STOPPING **********************" << FMT_REVERSE << FMT_RESET << endl;
                                                                    cout << FMT_FG_YELLOW << "*                     Terminating.                    *" << FMT_REVERSE << FMT_RESET << endl;
                                                                    cout << FMT_FG_YELLOW << "************************* Done ************************" << FMT_REVERSE << FMT_RESET << endl;
                                                                }
#line 959 "build/pparser.tab.cc"
    break;

  case 3: // files: file
#line 127 "src/pparser.yy"
                                                                { cout << FMT_FG_YELLOW << "PARSER files: | file" << FMT_RESET << endl; }
#line 965 "build/pparser.tab.cc"
    break;

  case 4: // files: files file
#line 128 "src/pparser.yy"
                                                                { cout << FMT_FG_YELLOW << "PARSER files: | files file" << FMT_RESET << endl; }
#line 971 "build/pparser.tab.cc"
    break;

  case 5: // file: blocks END
#line 134 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW << "PARSER file: | blocks END_OF_FILE" << FMT_RESET << endl;
                                                                    cout << FMT_FG_YELLOW << "*******************************************************" << FMT_REVERSE << FMT_RESET << endl;
                                                                    cout << FMT_FG_YELLOW << "*                      End Of File                    *" << FMT_REVERSE << FMT_RESET << endl;
                                                                    cout << FMT_FG_YELLOW << "*******************************************************" << FMT_REVERSE << FMT_RESET << endl;
                                                                }
#line 982 "build/pparser.tab.cc"
    break;

  case 6: // blocks: block
#line 145 "src/pparser.yy"
                                                                { cout << FMT_FG_YELLOW << "PARSER blocks: | block" << FMT_RESET << endl; }
#line 988 "build/pparser.tab.cc"
    break;

  case 7: // blocks: blocks block
#line 146 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW << "PARSER blocks: | blocks block" << FMT_RESET << endl;
                                                                    lexer::instance().dump_config();
                                                                }
#line 997 "build/pparser.tab.cc"
    break;

  case 8: // block: OPEN_BRACE sub_proc CLOSE_BRACE
#line 155 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW << "PARSER block: | OPEN_BRACE sub_porc CLOSE_BRACE" << FMT_RESET << endl;
                                                                }
#line 1005 "build/pparser.tab.cc"
    break;

  case 9: // block: OPEN_BRACE array CLOSE_BRACE
#line 158 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW << "PARSER block: | OPEN_BRACE array CLOSE_BRACE" << FMT_RESET << endl;
                                                                }
#line 1013 "build/pparser.tab.cc"
    break;

  case 10: // block: OPEN_BRACE symbol CLOSE_BRACE
#line 161 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW << "PARSER block: | OPEN_BRACE symbol CLOSE_BRACE" << FMT_RESET << endl;
                                                                    // bkp todo, look up in symbol table & do replace
                                                                    if(symbol_table.find(yystack_[1].value.as < std::string > ()) != symbol_table.end())
                                                                    {
                                                                        string val = symbol_table[yystack_[1].value.as < std::string > ()];
                                                                        cout << FMT_FG_RED << yystack_[1].value.as < std::string > () << " = " << val << FMT_RESET << endl;
                                                                    }
                                                                }
#line 1027 "build/pparser.tab.cc"
    break;

  case 11: // block: OPEN_BRACE symbol CLOSE_BRACE
#line 170 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW << "PARSER block: | OPEN_BRACE symbol CLOSE_BRACE" << FMT_RESET << endl;
                                                                    // bkp todo, look up in symbol table & do replace
                                                                    if(symbol_table.find(yystack_[1].value.as < std::string > ()) != symbol_table.end())
                                                                    {
                                                                        string val = symbol_table[yystack_[1].value.as < std::string > ()];
                                                                        cout << FMT_FG_RED << yystack_[1].value.as < std::string > () << " = " << val << FMT_RESET << endl;
                                                                    }
                                                                }
#line 1041 "build/pparser.tab.cc"
    break;

  case 12: // block: OPEN_BRACE symbol VBAR modifier CLOSE_BRACE
#line 179 "src/pparser.yy"
                                                               {
                                                                    cout << FMT_FG_YELLOW << "PARSER block: | OPEN_BRACE symbol=" << yystack_[3].value.as < std::string > () << " VBAR modifier=" << yystack_[1].value.as < std::string > () <<" CLOSE_BRACE" << FMT_RESET << endl;
                                                                    // bkp todo, look up in symbol table & do replace
                                                                    // if(symbol_table.find($2) != symbol_table.end())
                                                                    // {
                                                                    //     string val = symbol_table[$2];
                                                                    //     for (char &c : val)
                                                                    //     {
                                                                    //         c = std::toupper(static_cast<unsigned char>(c));
                                                                    //     }

                                                                    //     cout << FMT_FG_RED << $2 << " = " << val << FMT_RESET << endl;
                                                                    // }
                                                                }
#line 1060 "build/pparser.tab.cc"
    break;

  case 13: // block: OPEN_BRACE assign_stmt CLOSE_BRACE
#line 208 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW << "PARSER block: | OPEN_BRACE assign_stmt CLOSE_BRACE" << FMT_RESET << endl;
                                                                }
#line 1068 "build/pparser.tab.cc"
    break;

  case 14: // block: OPEN_BRACE qualafied_id CLOSE_BRACE
#line 211 "src/pparser.yy"
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
#line 1083 "build/pparser.tab.cc"
    break;

  case 15: // block: OPEN_BRACE built_in CLOSE_BRACE
#line 221 "src/pparser.yy"
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
                                                                    // read incllude path
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
#line 1112 "build/pparser.tab.cc"
    break;

  case 16: // block: OPEN_BRACE stmt CLOSE_BRACE
#line 245 "src/pparser.yy"
                                                                { cout << FMT_FG_YELLOW << "PARSER block: | OPEN_BRACE stmt CLOSE_BRACE" << FMT_RESET << endl; }
#line 1118 "build/pparser.tab.cc"
    break;

  case 17: // assign_stmt: symbol EQUAL_SIGN NUMERIC_LITERAL
#line 251 "src/pparser.yy"
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
#line 1138 "build/pparser.tab.cc"
    break;

  case 18: // assign_stmt: symbol EQUAL_SIGN STRING_LITERAL
#line 266 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW << "PARSER assign_stmt: | symbol EQUAL_SIGN STRING_LITERAL=" << FMT_RESET << yystack_[0].value.as < std::string > () << "\n";
                                                                    yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > ();
                                                                }
#line 1147 "build/pparser.tab.cc"
    break;

  case 19: // stmt: expr CLOSE_BRACE
#line 275 "src/pparser.yy"
                                                                { cout << FMT_FG_YELLOW << "PARSER stmt: | expr CLOSE_BRACE\n" << FMT_RESET; }
#line 1153 "build/pparser.tab.cc"
    break;

  case 20: // stmt: WHILE LPAREN expr RPAREN stmt
#line 276 "src/pparser.yy"
                                                                { cout << "PARSER stmt: | WHILE LPAREN expr RPAREN stmt\n";}
#line 1159 "build/pparser.tab.cc"
    break;

  case 21: // stmt: IF LPAREN expr RPAREN
#line 277 "src/pparser.yy"
                                                                { cout << "PARSER stmt TEST: | IF LPAREN expr prec IFX RPAREN\n"; }
#line 1165 "build/pparser.tab.cc"
    break;

  case 22: // stmt: IF LPAREN expr RPAREN stmt SLASH IF CLOSE_BRACE
#line 278 "src/pparser.yy"
                                                                { cout << "PARSER stmt: | IF LPAREN expr RPAREN stmt prec IFX CLOSE_BRACE\n"; }
#line 1171 "build/pparser.tab.cc"
    break;

  case 23: // stmt: SLASH IF CLOSE_BRACE
#line 279 "src/pparser.yy"
                                                                { cout << "PARSER stmt: | IF LPAREN expr RPAREN stmt ELSE stmt CLOSE_BRACE\n"; }
#line 1177 "build/pparser.tab.cc"
    break;

  case 24: // stmt: IF LPAREN expr RPAREN stmt ELSE stmt CLOSE_BRACE
#line 280 "src/pparser.yy"
                                                                { cout << "PARSER stmt: | IF LPAREN expr RPAREN stmt ELSE stmt CLOSE_BRACE\n"; }
#line 1183 "build/pparser.tab.cc"
    break;

  case 25: // stmt: sub_proc CLOSE_BRACE
#line 281 "src/pparser.yy"
                                                                { cout << "PARSER stmt: | sub_porc CLOSE_BRACE\n"; }
#line 1189 "build/pparser.tab.cc"
    break;

  case 26: // stmt: array CLOSE_BRACE
#line 282 "src/pparser.yy"
                                                                { cout  << "PARSER stmt: | array CLOSE_BRACE\n"; }
#line 1195 "build/pparser.tab.cc"
    break;

  case 27: // stmt: expr VBAR modifier CLOSE_BRACE
#line 283 "src/pparser.yy"
                                                                { cout << "PARSER stmt: | symbol VBAR CLOSE_BRACE\n"; }
#line 1201 "build/pparser.tab.cc"
    break;

  case 28: // stmt: qualafied_id CLOSE_BRACE
#line 284 "src/pparser.yy"
                                                                { cout  << "PARSER stmt: | qualafied_id CLOSE_BRACE\n"; }
#line 1207 "build/pparser.tab.cc"
    break;

  case 29: // expr: STRING_LITERAL
#line 290 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW << "PARSER expr: | STRING_LITERAL" << FMT_RESET << endl;
                                                                    yylhs.value.as < std::string > ()=yystack_[0].value.as < std::string > ();
                                                                }
#line 1216 "build/pparser.tab.cc"
    break;

  case 30: // expr: MINUS expr
#line 294 "src/pparser.yy"
                                                                {
                                                                    cout << "PARSER expr: | expr\n";
                                                                }
#line 1224 "build/pparser.tab.cc"
    break;

  case 31: // expr: expr '+' expr
#line 297 "src/pparser.yy"
                                                                {
                                                                    cout << "PARSER expr: | expr '+' expr\n";
                                                                }
#line 1232 "build/pparser.tab.cc"
    break;

  case 32: // expr: expr MINUS expr
#line 300 "src/pparser.yy"
                                                                {
                                                                    cout << "PARSER expr: | expr\n";
                                                                }
#line 1240 "build/pparser.tab.cc"
    break;

  case 33: // expr: expr ASTERISK expr
#line 303 "src/pparser.yy"
                                                                {
                                                                    cout << "PARSER expr: | expr\n";
                                                                }
#line 1248 "build/pparser.tab.cc"
    break;

  case 34: // expr: expr SLASH expr
#line 306 "src/pparser.yy"
                                                                {
                                                                    cout << "PARSER expr: | expr\n";
                                                                }
#line 1256 "build/pparser.tab.cc"
    break;

  case 35: // expr: expr LESS_THAN expr
#line 309 "src/pparser.yy"
                                                                {
                                                                    cout << "PARSER expr: | expr\n";
                                                                }
#line 1264 "build/pparser.tab.cc"
    break;

  case 36: // expr: expr GREATER_THAN expr
#line 312 "src/pparser.yy"
                                                                {
                                                                    cout << "PARSER expr: | expr\n";
                                                                }
#line 1272 "build/pparser.tab.cc"
    break;

  case 37: // expr: expr GREATER_THAN_EQUAL expr
#line 315 "src/pparser.yy"
                                                                {
                                                                    cout << "PARSER expr: | expr\n";
                                                                }
#line 1280 "build/pparser.tab.cc"
    break;

  case 38: // expr: expr LESS_THAN_EQUAL expr
#line 318 "src/pparser.yy"
                                                                {
                                                                    cout << "PARSER expr: | expr\n";
                                                                }
#line 1288 "build/pparser.tab.cc"
    break;

  case 39: // expr: expr NOT_EQUAL expr
#line 321 "src/pparser.yy"
                                                                {
                                                                    cout << "PARSER expr: | expr\n";
                                                                }
#line 1296 "build/pparser.tab.cc"
    break;

  case 40: // expr: LPAREN expr RPAREN
#line 324 "src/pparser.yy"
                                                                {
                                                                    cout << "PARSER expr: | expr\n";
                                                                }
#line 1304 "build/pparser.tab.cc"
    break;

  case 41: // qualafied_id: symbol DOT IDENTIFIER
#line 347 "src/pparser.yy"
                                                                { cout << FMT_FG_YELLOW << "PARSER qualafied_id: | symbol DOT IDENTIFIER" << FMT_RESET << endl; }
#line 1310 "build/pparser.tab.cc"
    break;

  case 42: // qualafied_id: symbol INDIRECT_MEMBER IDENTIFIER
#line 348 "src/pparser.yy"
                                                                { cout << FMT_FG_YELLOW << "PARSER qualafied_id: | symbol INDIRECT_MEMBER IDENTIFIER" << FMT_RESET << endl; }
#line 1316 "build/pparser.tab.cc"
    break;

  case 43: // qualafied_id: qualafied_id DOT IDENTIFIER
#line 349 "src/pparser.yy"
                                                                { cout << FMT_FG_YELLOW << "PARSER qualafied_id: | qualafied_id DOT IDENTIFIER" << FMT_RESET << endl; }
#line 1322 "build/pparser.tab.cc"
    break;

  case 44: // qualafied_id: qualafied_id INDIRECT_MEMBER IDENTIFIER
#line 350 "src/pparser.yy"
                                                                { cout << FMT_FG_YELLOW << "PARSER qualafied_id: | qualafied_id INDIRECT_MEMBER IDENTIFIER" << FMT_RESET << endl; }
#line 1328 "build/pparser.tab.cc"
    break;

  case 45: // sub_proc: symbol LPAREN params RPAREN
#line 356 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW << "PARSER sub_proc: | symbol LPAREN params RPAREN" << FMT_RESET << endl;
                                                                    yylhs.value.as < std::string > ()=yystack_[3].value.as < std::string > ();
                                                                }
#line 1337 "build/pparser.tab.cc"
    break;

  case 46: // array: symbol OPEN_BRACKET NUMERIC_LITERAL CLOSE_BRACKET
#line 365 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW
                                                                        << "PARSER array: | symbol=\"" << yystack_[3].value.as < std::string > () << "\" OPEN_BRACKET NUMERIC_LITERAL=\"" << yystack_[1].value.as < std::string > () << "\" CLOSE_BRACKET"
                                                                        << FMT_RESET << endl;
                                                                    yylhs.value.as < std::string > ()=yystack_[3].value.as < std::string > ();
                                                                }
#line 1348 "build/pparser.tab.cc"
    break;

  case 47: // params: param
#line 377 "src/pparser.yy"
                                                                { cout << "PARSER params: | param\n" << endl; }
#line 1354 "build/pparser.tab.cc"
    break;

  case 48: // params: params symbol
#line 378 "src/pparser.yy"
                                                                { cout << FMT_FG_YELLOW << "PARSER qualafied_id: | params COMMA symbol" << FMT_RESET << endl; }
#line 1360 "build/pparser.tab.cc"
    break;

  case 49: // param: symbol COMMA
#line 385 "src/pparser.yy"
                                                                { cout << FMT_FG_YELLOW << "PARSER param: | symbol" << FMT_RESET << endl; }
#line 1366 "build/pparser.tab.cc"
    break;

  case 50: // symbol: DOLLAR_SIGN IDENTIFIER
#line 391 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW << "PARSER symbol: | IDENTIFIER=\"" << yystack_[0].value.as < std::string > () << "\"" << FMT_RESET << endl;
                                                                    yylhs.value.as < std::string > ()=yystack_[0].value.as < std::string > ();
                                                                }
#line 1375 "build/pparser.tab.cc"
    break;

  case 51: // symbol: HASH_MARK CONST_ID HASH_MARK
#line 395 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW << "PARSER symbol: | HASH_MARK CONST_ID=\"" << yystack_[1].value.as < std::string > () << "\"" << FMT_RESET << endl;
                                                                    yylhs.value.as < std::string > ()=yystack_[1].value.as < std::string > ();
                                                                }
#line 1384 "build/pparser.tab.cc"
    break;

  case 52: // modifier: CAPITALIZE
#line 404 "src/pparser.yy"
                                                                { cout << "PARSER modifier: | CAPITALIZE\n"; }
#line 1390 "build/pparser.tab.cc"
    break;

  case 53: // modifier: CAT
#line 405 "src/pparser.yy"
                                                                { cout  << "PARSER modifier: | CAT\n"; }
#line 1396 "build/pparser.tab.cc"
    break;

  case 54: // modifier: COUNT_CHARACTERS
#line 406 "src/pparser.yy"
                                                                { cout  << "PARSER modifier: | COUNT_CHARACTERS\n"; }
#line 1402 "build/pparser.tab.cc"
    break;

  case 55: // modifier: COUNT_SENTENCES
#line 407 "src/pparser.yy"
                                                                { cout  << "PARSER modifier: | COUNT_SENTENCES\n"; }
#line 1408 "build/pparser.tab.cc"
    break;

  case 56: // modifier: COUNT_PARAGRAPHS
#line 408 "src/pparser.yy"
                                                                { cout  << "PARSER modifier: | COUNT_PARAGRAPHS\n"; }
#line 1414 "build/pparser.tab.cc"
    break;

  case 57: // modifier: COUNT_WORDS
#line 409 "src/pparser.yy"
                                                                { cout  << "PARSER modifier: | COUNT_WORDS\n";}
#line 1420 "build/pparser.tab.cc"
    break;

  case 58: // modifier: DATE_FORMAT
#line 410 "src/pparser.yy"
                                                                { cout  << "PARSER modifier: | DATE_FORMAT\n"; }
#line 1426 "build/pparser.tab.cc"
    break;

  case 59: // modifier: DEFAULT
#line 411 "src/pparser.yy"
                                                                { cout  << "PARSER modifier: | DEFAULT\n"; }
#line 1432 "build/pparser.tab.cc"
    break;

  case 60: // modifier: ESCAPE
#line 412 "src/pparser.yy"
                                                                { cout  << "PARSER modifier: | ESCAPE\n"; }
#line 1438 "build/pparser.tab.cc"
    break;

  case 61: // modifier: INDENT
#line 413 "src/pparser.yy"
                                                                { cout  << "PARSER modifier: | INDENT\n"; }
#line 1444 "build/pparser.tab.cc"
    break;

  case 62: // modifier: STRIP
#line 414 "src/pparser.yy"
                                                                { cout  << "PARSER modifier: | STRIPS\n"; }
#line 1450 "build/pparser.tab.cc"
    break;

  case 63: // modifier: NL2BR
#line 415 "src/pparser.yy"
                                                                { cout  << "PARSER modifier: | NL2BR\n";  }
#line 1456 "build/pparser.tab.cc"
    break;

  case 64: // modifier: REPLACE
#line 416 "src/pparser.yy"
                                                                { cout  << "PARSER modifier: | REPLACE\n"; }
#line 1462 "build/pparser.tab.cc"
    break;

  case 65: // modifier: REGEX_REPLACE
#line 417 "src/pparser.yy"
                                                                { cout  << "PARSER modifier: | REGEX_REPLACE\n"; }
#line 1468 "build/pparser.tab.cc"
    break;

  case 66: // modifier: SPACIFY
#line 418 "src/pparser.yy"
                                                                { cout  << "PARSER modifier: | SPACIFY\n"; }
#line 1474 "build/pparser.tab.cc"
    break;

  case 67: // modifier: STRING_FORMAT
#line 419 "src/pparser.yy"
                                                                { cout  << "PARSER modifier: | STRING_FORMAT\n"; }
#line 1480 "build/pparser.tab.cc"
    break;

  case 68: // modifier: STRIP_TAGS
#line 420 "src/pparser.yy"
                                                                { cout  << "PARSER modifier: | STIP_TAGS\n"; }
#line 1486 "build/pparser.tab.cc"
    break;

  case 69: // modifier: TRUNCATE
#line 421 "src/pparser.yy"
                                                                { cout  << "PARSER modifier: | TRUNCATE\n"; }
#line 1492 "build/pparser.tab.cc"
    break;

  case 70: // modifier: UPPER
#line 422 "src/pparser.yy"
                                                                { cout  << "PARSER modifier: | UPPER\n"; }
#line 1498 "build/pparser.tab.cc"
    break;

  case 71: // modifier: LOWER
#line 423 "src/pparser.yy"
                                                                { cout  << "PARSER modifier: | LOWER\n"; }
#line 1504 "build/pparser.tab.cc"
    break;

  case 72: // modifier: WORDWRAP
#line 424 "src/pparser.yy"
                                                                { cout  << "PARSER modifier: | WORDWRAP\n"; }
#line 1510 "build/pparser.tab.cc"
    break;

  case 73: // built_in: CONFIG_LOAD attributes
#line 430 "src/pparser.yy"
                                                                {   cout << FMT_FG_YELLOW << "PARSER built_in: | CONFIG_LOAD FILE_ATTRIB=\"" << yystack_[1].value.as < std::string > () << "\" EQUAL STRING_LITERAL=\"" << "TEST" << "\"" << FMT_RESET << endl;  }
#line 1516 "build/pparser.tab.cc"
    break;

  case 74: // built_in: INCLUDE attributes
#line 431 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW << "PARSER built_in: | INCLUDE attributes" << FMT_RESET << endl;
                                                                    yylhs.value.as < std::vector< std::pair<std::string, std::string> >  > () = yystack_[0].value.as < std::vector< std::pair<std::string, std::string> >  > ();
                                                                }
#line 1525 "build/pparser.tab.cc"
    break;

  case 75: // built_in: REQUIRE attributes
#line 435 "src/pparser.yy"
                                                                { cout << FMT_FG_YELLOW << "PARSER built_in: | REQUIRE FILE_ATTRIB=\"%s\" EQUAL STRING_LITERAL=\"\"" << FMT_RESET << endl; }
#line 1531 "build/pparser.tab.cc"
    break;

  case 76: // built_in: REQUIRE_ONCE attributes
#line 436 "src/pparser.yy"
                                                                { cout << FMT_FG_YELLOW << "PARSER built_in: | REQUIRE_once FILE_ATTRIB=\"%s\" EQUAL STRING_LITERAL=\"\"" << FMT_RESET << endl; }
#line 1537 "build/pparser.tab.cc"
    break;

  case 77: // built_in: INSERT attributes
#line 437 "src/pparser.yy"
                                                                { cout << FMT_FG_YELLOW << "PARSER built_in: | INSERT FILE_ATTRIB=\"%s\" EQUAL STRING_LITERAL=\"\"" << FMT_RESET << endl; }
#line 1543 "build/pparser.tab.cc"
    break;

  case 78: // built_in: ASSIGN attributes
#line 438 "src/pparser.yy"
                                                                { cout << FMT_FG_YELLOW << "PARSER built_in: | ASSIGN FILE_ATTRIB=\"%s\" EQUAL STRING_LITERAL=\"\"" << FMT_RESET << endl; }
#line 1549 "build/pparser.tab.cc"
    break;

  case 79: // built_in: ISSET attributes
#line 439 "src/pparser.yy"
                                                                { cout << FMT_FG_YELLOW << "PARSER built_in: | ISSET FILE_ATTRIB=\"%s\" EQUAL STRING_LITERAL=\"\"" << FMT_RESET << endl; }
#line 1555 "build/pparser.tab.cc"
    break;

  case 80: // built_in: VERSION attributes
#line 440 "src/pparser.yy"
                                                                { cout << FMT_FG_YELLOW << "PARSER built_in: | VERSION FILE_ATTRIB=\"%s\" EQUAL STRING_LITERAL=\"\"" << FMT_RESET << endl; }
#line 1561 "build/pparser.tab.cc"
    break;

  case 81: // attributes: attrib
#line 446 "src/pparser.yy"
                                                               {
                                                                    cout << FMT_FG_YELLOW << "PARSER attribute: | push -> attrib={name=\"" << yystack_[0].value.as <  std::pair<std::string, std::string>  > ().first  << "\"; value=\"" << yystack_[0].value.as <  std::pair<std::string, std::string>  > ().second << "\"}\n" << FMT_RESET << endl;
                                                                    std::pair<std::string, std::string>  p(yystack_[0].value.as <  std::pair<std::string, std::string>  > ());
                                                                    std::vector< std::pair<std::string, std::string> > v;
                                                                    v.push_back( p );
                                                                    yylhs.value.as < std::vector< std::pair<std::string, std::string> >  > () = v;
                                                               }
#line 1573 "build/pparser.tab.cc"
    break;

  case 82: // attributes: attributes attrib
#line 453 "src/pparser.yy"
                                                               {
                                                                    cout << FMT_FG_YELLOW << "PARSER attribute: | attributes : push-> attrib={name=\"" << yystack_[0].value.as <  std::pair<std::string, std::string>  > ().first  << "\"; value=\"" << yystack_[0].value.as <  std::pair<std::string, std::string>  > ().second << "\"}\n" << FMT_RESET << endl;
                                                                    yystack_[1].value.as < std::vector< std::pair<std::string, std::string> >  > ().push_back( yystack_[0].value.as <  std::pair<std::string, std::string>  > () );
                                                                    yylhs.value.as < std::vector< std::pair<std::string, std::string> >  > () = yystack_[1].value.as < std::vector< std::pair<std::string, std::string> >  > ();
                                                               }
#line 1583 "build/pparser.tab.cc"
    break;

  case 83: // attrib: VALUE_ATTRIB EQUAL_SIGN STRING_LITERAL
#line 463 "src/pparser.yy"
                                                               {
                                                                    cout << FMT_FG_YELLOW << "PARSER name_value: | VALUE_ATTRIB=\""
                                                                        << yystack_[2].value.as < std::string > () << "\" EQUAL_SIGN STRING_LITERAL=\""
                                                                        << buf << "\"" << FMT_RESET << endl;

                                                                    std::pair<std::string, std::string>  pair(yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ());
                                                                    yylhs.value.as <  std::pair<std::string, std::string>  > () = pair;
                                                               }
#line 1596 "build/pparser.tab.cc"
    break;

  case 84: // attrib: VAR_ATTRIB EQUAL_SIGN STRING_LITERAL
#line 471 "src/pparser.yy"
                                                               {
                                                                    cout << FMT_FG_YELLOW
                                                                        << "PARSER name_value: | VAR_ATTRIB=\"\" EQUAL_SIGN STRING_LITERAL=\"\""
                                                                        << FMT_FG_GREEN << FMT_RESET << endl;

                                                                    std::pair<std::string, std::string>  pair(yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ());
                                                                    yylhs.value.as <  std::pair<std::string, std::string>  > () = pair;
                                                               }
#line 1609 "build/pparser.tab.cc"
    break;

  case 85: // attrib: FILE_ATTRIB EQUAL_SIGN STRING_LITERAL
#line 479 "src/pparser.yy"
                                                               {
                                                                    cout << FMT_FG_YELLOW
                                                                        << "PARSER name_value: | FILE_ATTRIB=\""
                                                                        << yystack_[2].value.as < std::string > () << "\" EQUAL_SIGN STRING_LITERAL=\""
                                                                        << yystack_[0].value.as < std::string > () << "\""
                                                                        << FMT_RESET << endl;

                                                                    std::pair<std::string, std::string>  pair(yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ());
                                                                    yylhs.value.as <  std::pair<std::string, std::string>  > () = pair;
                                                               }
#line 1624 "build/pparser.tab.cc"
    break;

  case 86: // attrib: attrib_name EQUAL_SIGN STRING_LITERAL
#line 489 "src/pparser.yy"
                                                               {
                                                                      cout << FMT_FG_YELLOW
                                                                        << "PARSER name_value: | " << yystack_[2].value.as < std::string > () << "=\""
                                                                        << yystack_[2].value.as < std::string > () << "\" EQUAL_SIGN STRING_LITERAL=\""
                                                                        << yystack_[0].value.as < std::string > () << "\""
                                                                        << FMT_RESET << endl;

                                                                    std::pair<std::string, std::string>  pair(yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ());
                                                                    yylhs.value.as <  std::pair<std::string, std::string>  > () = pair;
                                                               }
#line 1639 "build/pparser.tab.cc"
    break;

  case 88: // attrib_name: VALUE_ATTRIB
#line 505 "src/pparser.yy"
      { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1645 "build/pparser.tab.cc"
    break;

  case 89: // attrib_name: FROM_ATTRIB
#line 506 "src/pparser.yy"
      { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1651 "build/pparser.tab.cc"
    break;

  case 90: // attrib_name: ITEM_ATTRIB
#line 507 "src/pparser.yy"
      { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1657 "build/pparser.tab.cc"
    break;

  case 91: // attrib_name: KEY_ATTRIB
#line 508 "src/pparser.yy"
      { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1663 "build/pparser.tab.cc"
    break;

  case 92: // attrib_name: NAME_ATTRIB
#line 509 "src/pparser.yy"
      { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1669 "build/pparser.tab.cc"
    break;


#line 1673 "build/pparser.tab.cc"

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









  const signed char parser::yypact_ninf_ = -96;

  const signed char parser::yytable_ninf_ = -88;

  const short
  parser::yypact_[] =
  {
     -48,    -3,    12,   -48,   -96,     9,   -96,   163,   163,   163,
     163,   163,   163,   163,   163,   -96,     8,    18,   -11,   -59,
     -15,   -11,   -19,     2,     7,   -44,    -4,    29,    30,     0,
      31,   -96,   -96,   -96,   -96,    13,    37,    44,   -96,   -96,
     -96,   -96,    -5,   -96,    48,    -5,    -5,    -5,    -5,    -5,
      -5,    -5,   -96,    22,   -63,   -11,   -11,    16,    68,   -96,
     -96,   114,   -96,   -11,   -11,   -11,   -11,   -11,   -11,   -11,
     -11,   -11,   148,    97,   157,   127,   128,   185,   114,   187,
     -96,   -17,   188,    66,   -96,   189,   191,   192,   -96,   193,
     -96,   -96,    26,    40,   -96,   -96,   -96,   -96,   -96,   -96,
     -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,
     -96,   -96,   -96,   -96,   -96,   -96,   137,   -57,   -57,   -57,
     -57,   -57,   100,    16,    16,    74,   -96,   -96,   -96,   138,
     141,    57,   -96,   147,   -96,   -96,   -96,   -96,   -96,   -96,
     -96,    -9,    -9,   -96,   -96,   -96,   -96,   -96,   -96,   -74,
      24,   142,   143,    19,   -96,    -9,   130,   -96,   -96,   -96,
     145,   146,   -96,   -96
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     2,     3,     0,     6,    87,    87,    87,
      87,    87,    87,    87,    87,    29,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     4,     5,     7,     0,     0,     0,    89,    91,
      92,    90,    73,    81,     0,    74,    75,    76,    77,    78,
      79,    80,    50,     0,     0,     0,     0,    30,     0,    13,
      16,     0,    19,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    14,     0,     8,     9,     0,     0,     0,
      10,     0,     0,     0,    15,     0,     0,     0,    82,     0,
      51,    40,     0,     0,    23,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    71,    70,    62,    63,    65,
      64,    66,    67,    68,    69,    72,     0,    37,    38,    39,
      35,    36,    32,    33,    34,    31,    44,    43,    42,     0,
       0,     0,    47,     0,    41,    18,    17,    84,    83,    85,
      86,    21,     0,    27,    12,    46,    45,    48,    49,     0,
       0,     0,     0,     0,    20,     0,     0,    28,    25,    26,
       0,     0,    24,    22
  };

  const short
  parser::yypgoto_[] =
  {
     -96,   -96,   -96,   214,   -96,   218,   -96,   -95,    46,   223,
     224,   225,   -96,   -96,    -1,   149,   -96,   186,   135,   -96
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,     2,     3,     4,     5,     6,    23,    24,    25,   150,
     151,   152,   131,   132,   153,   116,    30,    42,    43,    44
  };

  const short
  parser::yytable_[] =
  {
      29,     7,     8,     9,    10,    11,    12,    13,    15,    33,
      15,    14,    31,    72,   155,    91,    15,    77,    55,    35,
      36,    37,    38,    39,    40,    41,    61,     1,   156,    52,
      63,    64,    62,    65,    66,    67,    77,    68,    69,    70,
      53,    72,    71,    68,    69,    70,   149,   154,    71,    63,
      64,    16,    65,    66,    67,    17,    68,    69,    70,    16,
     160,    71,    56,    17,    54,    16,    18,    57,    18,    17,
      78,    58,    73,    79,    18,    74,    80,    81,    59,    82,
     133,    19,    20,    60,     1,   135,   136,    19,    20,    21,
     -87,    21,    79,    22,    90,    83,    81,    21,    82,    22,
     157,    92,    93,    74,   141,    75,    76,    84,    85,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   142,    63,
      64,    71,    65,    66,    67,    16,    68,    69,    70,    17,
     147,    71,    86,    63,    64,   146,    65,    66,    67,    87,
      68,    69,    70,    89,    94,    71,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,    63,    64,   126,
      65,    66,    67,   -28,    68,    69,    70,    88,   127,    71,
      88,    88,    88,    88,    88,    88,    88,    35,    36,    37,
      38,    39,    40,    41,    45,    46,    47,    48,    49,    50,
      51,    69,    70,   -25,   -26,    71,   128,   130,   137,   134,
     138,   139,   140,   143,   144,   145,   148,    32,   158,   159,
     161,   162,   163,    34,    26,    27,    28,   129
  };

  const unsigned char
  parser::yycheck_[] =
  {
       1,     4,     5,     6,     7,     8,     9,    10,    19,     0,
      19,    14,     0,    17,    88,    78,    19,    17,    77,    24,
      25,    26,    27,    28,    29,    30,    70,    75,   102,    21,
      93,    94,    76,    96,    97,    98,    17,   100,   101,   102,
      22,    17,   105,   100,   101,   102,   141,   142,   105,    93,
      94,    68,    96,    97,    98,    72,   100,   101,   102,    68,
     155,   105,    77,    72,    18,    68,    77,    21,    77,    72,
      70,    90,    76,    73,    77,    79,    76,    77,    76,    79,
      81,    90,    91,    76,    75,    19,    20,    90,    91,   100,
      95,   100,    73,   102,    72,    95,    77,   100,    79,   102,
      76,    55,    56,    79,    78,    76,    76,    76,    95,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    78,    93,
      94,   105,    96,    97,    98,    68,   100,   101,   102,    72,
     131,   105,    95,    93,    94,    78,    96,    97,    98,    95,
     100,   101,   102,    95,    76,   105,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    93,    94,    21,
      96,    97,    98,    76,   100,   101,   102,    42,    21,   105,
      45,    46,    47,    48,    49,    50,    51,    24,    25,    26,
      27,    28,    29,    30,     8,     9,    10,    11,    12,    13,
      14,   101,   102,    76,    76,   105,    21,    20,    19,    21,
      19,    19,    19,    76,    76,    74,    69,     3,    76,    76,
      90,    76,    76,     5,     1,     1,     1,    78
  };

  const signed char
  parser::yystos_[] =
  {
       0,    75,   107,   108,   109,   110,   111,     4,     5,     6,
       7,     8,     9,    10,    14,    19,    68,    72,    77,    90,
      91,   100,   102,   112,   113,   114,   115,   116,   117,   120,
     122,     0,   109,     0,   111,    24,    25,    26,    27,    28,
      29,    30,   123,   124,   125,   123,   123,   123,   123,   123,
     123,   123,    21,    22,   114,    77,    77,   114,    90,    76,
      76,    70,    76,    93,    94,    96,    97,    98,   100,   101,
     102,   105,    17,    76,    79,    76,    76,    17,    70,    73,
      76,    77,    79,    95,    76,    95,    95,    95,   124,    95,
      72,    78,   114,   114,    76,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,   121,   114,   114,   114,
     114,   114,   114,   114,   114,   114,    21,    21,    21,   121,
      20,   118,   119,   120,    21,    19,    20,    19,    19,    19,
      19,    78,    78,    76,    76,    74,    78,   120,    69,   113,
     115,   116,   117,   120,   113,    88,   102,    76,    76,    76,
     113,    90,    76,    76
  };

  const signed char
  parser::yyr1_[] =
  {
       0,   106,   107,   108,   108,   109,   110,   110,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   112,   112,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   115,   115,   115,   115,   116,   117,   118,   118,   119,
     120,   120,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   122,   122,   122,   122,   122,   122,   122,
     122,   123,   123,   124,   124,   124,   124,   125,   125,   125,
     125,   125,   125
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     1,     2,     2,     1,     2,     3,     3,
       3,     3,     5,     3,     3,     3,     3,     3,     3,     2,
       5,     4,     8,     3,     8,     2,     2,     4,     2,     1,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     4,     4,     1,     2,     2,
       2,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     1,     2,     3,     3,     3,     3,     0,     1,     1,
       1,     1,     1
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
  "PERCENT_SIGN", "UMINUS", "'+'", "$accept", "complier", "files", "file",
  "blocks", "block", "assign_stmt", "stmt", "expr", "qualafied_id",
  "sub_proc", "array", "params", "param", "symbol", "modifier", "built_in",
  "attributes", "attrib", "attrib_name", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   116,   116,   127,   128,   134,   145,   146,   155,   158,
     161,   170,   179,   208,   211,   221,   245,   251,   266,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   290,
     294,   297,   300,   303,   306,   309,   312,   315,   318,   321,
     324,   347,   348,   349,   350,   356,   365,   377,   378,   385,
     391,   395,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   430,   431,   435,   436,   437,   438,   439,
     440,   446,   453,   463,   471,   479,   489,   504,   505,   506,
     507,   508,   509
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
#line 2111 "build/pparser.tab.cc"

#line 512 "src/pparser.yy"


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

#ifdef YYERROR_FUNC
int yyerror(char * s)
{
    fprintf(stderr, "%s\n", s);
    return 0;
};
#endif

#ifdef MAIN_FUNC
#endif

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
