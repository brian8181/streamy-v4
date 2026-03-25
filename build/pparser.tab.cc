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
        parser::symbol_type yylex();
    }

    //int yylex(void);
    //int yyerror(char * s);

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
    //typedef std::pair< std::string, std::string > attribute;

    // declare
    typedef map<string, string> symbol_table_t;
    // test
    symbol_table_t symbol_table =  { {"a", "a_val"}, {"b", "b_val"}, {"c", "c_val"} };
    bool is_name(const std::pair<string, string>& p, const string& str);


#line 123 "build/pparser.tab.cc"


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

#ifndef N_
# define N_(Msgid) Msgid
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
#line 200 "build/pparser.tab.cc"

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
      case symbol_kind::S_INDIRECT_MEMBER: // INDIRECT_MEMBER
      case symbol_kind::S_STRING_LITERAL: // STRING_LITERAL
      case symbol_kind::S_NUMERIC_LITERAL: // NUMERIC_LITERAL
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_CONST_ID: // CONST_ID
      case symbol_kind::S_VAR_ATTRIB: // VAR_ATTRIB
      case symbol_kind::S_VALUE_ATTRIB: // VALUE_ATTRIB
      case symbol_kind::S_FILE_ATTRIB: // FILE_ATTRIB
      case symbol_kind::S_FROM_ATTRIB: // FROM_ATTRIB
      case symbol_kind::S_KEY_ATTRIB: // KEY_ATTRIB
      case symbol_kind::S_NAME_ATTRIB: // NAME_ATTRIB
      case symbol_kind::S_ITEM_ATTRIB: // ITEM_ATTRIB
      case symbol_kind::S_FILE_NAME: // FILE_NAME
      case symbol_kind::S_UNESCAPED_TEXT: // UNESCAPED_TEXT
      case symbol_kind::S_assign_stmt: // assign_stmt
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_qualafied_id: // qualafied_id
      case symbol_kind::S_sub_proc: // sub_proc
      case symbol_kind::S_array: // array
      case symbol_kind::S_symbol: // symbol
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
      case symbol_kind::S_INDIRECT_MEMBER: // INDIRECT_MEMBER
      case symbol_kind::S_STRING_LITERAL: // STRING_LITERAL
      case symbol_kind::S_NUMERIC_LITERAL: // NUMERIC_LITERAL
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_CONST_ID: // CONST_ID
      case symbol_kind::S_VAR_ATTRIB: // VAR_ATTRIB
      case symbol_kind::S_VALUE_ATTRIB: // VALUE_ATTRIB
      case symbol_kind::S_FILE_ATTRIB: // FILE_ATTRIB
      case symbol_kind::S_FROM_ATTRIB: // FROM_ATTRIB
      case symbol_kind::S_KEY_ATTRIB: // KEY_ATTRIB
      case symbol_kind::S_NAME_ATTRIB: // NAME_ATTRIB
      case symbol_kind::S_ITEM_ATTRIB: // ITEM_ATTRIB
      case symbol_kind::S_FILE_NAME: // FILE_NAME
      case symbol_kind::S_UNESCAPED_TEXT: // UNESCAPED_TEXT
      case symbol_kind::S_assign_stmt: // assign_stmt
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_qualafied_id: // qualafied_id
      case symbol_kind::S_sub_proc: // sub_proc
      case symbol_kind::S_array: // array
      case symbol_kind::S_symbol: // symbol
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
      case symbol_kind::S_INDIRECT_MEMBER: // INDIRECT_MEMBER
      case symbol_kind::S_STRING_LITERAL: // STRING_LITERAL
      case symbol_kind::S_NUMERIC_LITERAL: // NUMERIC_LITERAL
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_CONST_ID: // CONST_ID
      case symbol_kind::S_VAR_ATTRIB: // VAR_ATTRIB
      case symbol_kind::S_VALUE_ATTRIB: // VALUE_ATTRIB
      case symbol_kind::S_FILE_ATTRIB: // FILE_ATTRIB
      case symbol_kind::S_FROM_ATTRIB: // FROM_ATTRIB
      case symbol_kind::S_KEY_ATTRIB: // KEY_ATTRIB
      case symbol_kind::S_NAME_ATTRIB: // NAME_ATTRIB
      case symbol_kind::S_ITEM_ATTRIB: // ITEM_ATTRIB
      case symbol_kind::S_FILE_NAME: // FILE_NAME
      case symbol_kind::S_UNESCAPED_TEXT: // UNESCAPED_TEXT
      case symbol_kind::S_assign_stmt: // assign_stmt
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_qualafied_id: // qualafied_id
      case symbol_kind::S_sub_proc: // sub_proc
      case symbol_kind::S_array: // array
      case symbol_kind::S_symbol: // symbol
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
      case symbol_kind::S_INDIRECT_MEMBER: // INDIRECT_MEMBER
      case symbol_kind::S_STRING_LITERAL: // STRING_LITERAL
      case symbol_kind::S_NUMERIC_LITERAL: // NUMERIC_LITERAL
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_CONST_ID: // CONST_ID
      case symbol_kind::S_VAR_ATTRIB: // VAR_ATTRIB
      case symbol_kind::S_VALUE_ATTRIB: // VALUE_ATTRIB
      case symbol_kind::S_FILE_ATTRIB: // FILE_ATTRIB
      case symbol_kind::S_FROM_ATTRIB: // FROM_ATTRIB
      case symbol_kind::S_KEY_ATTRIB: // KEY_ATTRIB
      case symbol_kind::S_NAME_ATTRIB: // NAME_ATTRIB
      case symbol_kind::S_ITEM_ATTRIB: // ITEM_ATTRIB
      case symbol_kind::S_FILE_NAME: // FILE_NAME
      case symbol_kind::S_UNESCAPED_TEXT: // UNESCAPED_TEXT
      case symbol_kind::S_assign_stmt: // assign_stmt
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_qualafied_id: // qualafied_id
      case symbol_kind::S_sub_proc: // sub_proc
      case symbol_kind::S_array: // array
      case symbol_kind::S_symbol: // symbol
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
      case symbol_kind::S_INDIRECT_MEMBER: // INDIRECT_MEMBER
      case symbol_kind::S_STRING_LITERAL: // STRING_LITERAL
      case symbol_kind::S_NUMERIC_LITERAL: // NUMERIC_LITERAL
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_CONST_ID: // CONST_ID
      case symbol_kind::S_VAR_ATTRIB: // VAR_ATTRIB
      case symbol_kind::S_VALUE_ATTRIB: // VALUE_ATTRIB
      case symbol_kind::S_FILE_ATTRIB: // FILE_ATTRIB
      case symbol_kind::S_FROM_ATTRIB: // FROM_ATTRIB
      case symbol_kind::S_KEY_ATTRIB: // KEY_ATTRIB
      case symbol_kind::S_NAME_ATTRIB: // NAME_ATTRIB
      case symbol_kind::S_ITEM_ATTRIB: // ITEM_ATTRIB
      case symbol_kind::S_FILE_NAME: // FILE_NAME
      case symbol_kind::S_UNESCAPED_TEXT: // UNESCAPED_TEXT
      case symbol_kind::S_assign_stmt: // assign_stmt
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_qualafied_id: // qualafied_id
      case symbol_kind::S_sub_proc: // sub_proc
      case symbol_kind::S_array: // array
      case symbol_kind::S_symbol: // symbol
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
#line 119 "src/pparser.yy"
                                                                {
                                                                    cout <<  FMT_FG_GREEN << "PARSER complier: | files" << FMT_RESET << endl;
                                                                    cout << FMT_FG_YELLOW << "*********************** STOPPING **********************" << FMT_REVERSE << FMT_RESET << endl;
                                                                    cout << FMT_FG_YELLOW << "*                     Terminating.                    *" << FMT_REVERSE << FMT_RESET << endl;
                                                                    cout << FMT_FG_YELLOW << "************************* Done ************************" << FMT_REVERSE << FMT_RESET << endl;
                                                                }
#line 926 "build/pparser.tab.cc"
    break;

  case 3: // files: file
#line 130 "src/pparser.yy"
                                                                { cout << FMT_FG_YELLOW << "PARSER files: | file" << FMT_RESET << endl; }
#line 932 "build/pparser.tab.cc"
    break;

  case 4: // files: files file
#line 131 "src/pparser.yy"
                                                                { cout << FMT_FG_YELLOW << "PARSER files: | files file" << FMT_RESET << endl; }
#line 938 "build/pparser.tab.cc"
    break;

  case 5: // file: blocks "end of input"
#line 137 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW << "PARSER file: | blocks END_OF_FILE" << FMT_RESET << endl;
                                                                    cout << FMT_FG_YELLOW << "*******************************************************" << FMT_REVERSE << FMT_RESET << endl;
                                                                    cout << FMT_FG_YELLOW << "*                      End Of File                    *" << FMT_REVERSE << FMT_RESET << endl;
                                                                    cout << FMT_FG_YELLOW << "*******************************************************" << FMT_REVERSE << FMT_RESET << endl;
                                                                }
#line 949 "build/pparser.tab.cc"
    break;

  case 6: // blocks: block
#line 148 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW << "PARSER blocks: | block" << FMT_RESET << endl;
                                                                }
#line 957 "build/pparser.tab.cc"
    break;

  case 7: // blocks: blocks block
#line 151 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW << "PARSER blocks: | blocks block" << FMT_RESET << endl;
                                                                    lexer::instance().dump_config();
                                                                }
#line 966 "build/pparser.tab.cc"
    break;

  case 8: // block: OPEN_BRACE sub_proc CLOSE_BRACE
#line 160 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW << "PARSER block: | OPEN_BRACE sub_porc CLOSE_BRACE" << FMT_RESET << endl;
                                                                }
#line 974 "build/pparser.tab.cc"
    break;

  case 9: // block: OPEN_BRACE array CLOSE_BRACE
#line 163 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW << "PARSER block: | OPEN_BRACE array CLOSE_BRACE" << FMT_RESET << endl;
                                                                }
#line 982 "build/pparser.tab.cc"
    break;

  case 10: // block: OPEN_BRACE symbol CLOSE_BRACE
#line 166 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW << "PARSER block: | OPEN_BRACE symbol CLOSE_BRACE" << FMT_RESET << endl;
                                                                    // bkp todo, look up in symbol table & do replace
                                                                    if(symbol_table.find(yystack_[1].value.as < std::string > ()) != symbol_table.end())
                                                                    {
                                                                        string val = symbol_table[yystack_[1].value.as < std::string > ()];
                                                                        cout << FMT_FG_RED << yystack_[1].value.as < std::string > () << " = " << val << FMT_RESET << endl;
                                                                    }
                                                                }
#line 996 "build/pparser.tab.cc"
    break;

  case 11: // block: OPEN_BRACE assign_stmt CLOSE_BRACE
#line 175 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW << "PARSER block: | OPEN_BRACE assign_stmt CLOSE_BRACE" << FMT_RESET << endl;
                                                                }
#line 1004 "build/pparser.tab.cc"
    break;

  case 12: // block: OPEN_BRACE qualafied_id CLOSE_BRACE
#line 178 "src/pparser.yy"
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
#line 1019 "build/pparser.tab.cc"
    break;

  case 13: // block: OPEN_BRACE built_in CLOSE_BRACE
#line 188 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW << "PARSER block: | OPEN_BRACE built_in CLOSE_BRACE" << FMT_RESET << endl;
                                                                    //free_all_nvalues();
                                                                    size_t len = yystack_[1].value.as < std::vector< std::pair<std::string, std::string> >  > ().size();
                                                                    int i = 0;
                                                                    for(; i < len; ++i)
                                                                    {
                                                                        if(yystack_[1].value.as < std::vector< std::pair<std::string, std::string> >  > ()[i].first == "file")
                                                                            break;
                                                                    }
                                                                    string include_file_path = yystack_[1].value.as < std::vector< std::pair<std::string, std::string> >  > ()[i].second;
                                                                    // read incllude file
                                                                    string sout;
                                                                    read_str(include_file_path, sout);
                                                                    //  append include file output to buffer
                                                                    string* p_rstr = lexer::instance().get_remaining();
                                                                    stringstream* include_buffer = lexer::instance().get_include_buffer();
                                                                    *include_buffer << endl << sout << endl << *p_rstr;
                                                                    // set the suffix a.k.a "current search buffer"
                                                                    lexer::instance().set_remaining( *p_rstr );
                                                                    lexer::instance().set_state(&sINITIAL);
                                                                    cout << FMT_FG_RED << "file = \"" << FMT_ITALIC << include_file_path << "\"" << FMT_RESET << endl;
                                                                }
#line 1047 "build/pparser.tab.cc"
    break;

  case 14: // block: OPEN_BRACE stmt CLOSE_BRACE
#line 211 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW << "PARSER block: | OPEN_BRACE stmt CLOSE_BRACE" << FMT_RESET << endl;
                                                                }
#line 1055 "build/pparser.tab.cc"
    break;

  case 15: // assign_stmt: symbol EQUAL_SIGN NUMERIC_LITERAL
#line 219 "src/pparser.yy"
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
#line 1075 "build/pparser.tab.cc"
    break;

  case 16: // assign_stmt: symbol EQUAL_SIGN STRING_LITERAL
#line 234 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW << "PARSER assign_stmt: | symbol EQUAL_SIGN STRING_LITERAL=" << FMT_RESET << yystack_[0].value.as < std::string > () << "\n";
                                                                    yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > ();
                                                                }
#line 1084 "build/pparser.tab.cc"
    break;

  case 17: // stmt: expr CLOSE_BRACE
#line 243 "src/pparser.yy"
                                                                {
                                                                    /*$$ = opr(PRINT, 1, $2);          */
                                                                    cout << FMT_FG_YELLOW << "PARSER stmt: | expr CLOSE_BRACE\n" << FMT_RESET;
                                                                }
#line 1093 "build/pparser.tab.cc"
    break;

  case 18: // stmt: WHILE LPAREN expr RPAREN stmt
#line 247 "src/pparser.yy"
                                                                {
                                                                    cout << "PARSER stmt: | WHILE LPAREN expr RPAREN stmt\n";
                                                                }
#line 1101 "build/pparser.tab.cc"
    break;

  case 19: // stmt: IF LPAREN expr RPAREN
#line 250 "src/pparser.yy"
                                                                {
                                                                    cout << "PARSER stmt TEST: | IF LPAREN expr prec IFX RPAREN\n";
                                                                }
#line 1109 "build/pparser.tab.cc"
    break;

  case 20: // stmt: IF LPAREN expr RPAREN stmt SLASH IF CLOSE_BRACE
#line 253 "src/pparser.yy"
                                                                {
                                                                    cout << "PARSER stmt: | IF LPAREN expr RPAREN stmt prec IFX CLOSE_BRACE\n";
                                                                }
#line 1117 "build/pparser.tab.cc"
    break;

  case 21: // stmt: SLASH IF CLOSE_BRACE
#line 256 "src/pparser.yy"
                                                                {
                                                                    cout << "PARSER stmt: | IF LPAREN expr RPAREN stmt ELSE stmt CLOSE_BRACE\n";
                                                                }
#line 1125 "build/pparser.tab.cc"
    break;

  case 22: // stmt: IF LPAREN expr RPAREN stmt ELSE stmt CLOSE_BRACE
#line 260 "src/pparser.yy"
                                                                {
                                                                    cout << "PARSER stmt: | IF LPAREN expr RPAREN stmt ELSE stmt CLOSE_BRACE\n";
                                                                }
#line 1133 "build/pparser.tab.cc"
    break;

  case 23: // stmt: sub_proc CLOSE_BRACE
#line 263 "src/pparser.yy"
                                                                {
                                                                    cout << "PARSER stmt: | sub_porc CLOSE_BRACE\n";
                                                                }
#line 1141 "build/pparser.tab.cc"
    break;

  case 24: // stmt: array CLOSE_BRACE
#line 266 "src/pparser.yy"
                                                                {
                                                                    cout  << "PARSER stmt: | array CLOSE_BRACE\n";
                                                                }
#line 1149 "build/pparser.tab.cc"
    break;

  case 25: // stmt: expr VBAR modifier CLOSE_BRACE
#line 269 "src/pparser.yy"
                                                                {
                                                                    cout << "PARSER stmt: | symbol VBAR CLOSE_BRACE\n";
                                                                }
#line 1157 "build/pparser.tab.cc"
    break;

  case 26: // stmt: qualafied_id CLOSE_BRACE
#line 272 "src/pparser.yy"
                                                                {
                                                                    cout  << "PARSER stmt: | qualafied_id CLOSE_BRACE\n";
                                                                }
#line 1165 "build/pparser.tab.cc"
    break;

  case 27: // expr: STRING_LITERAL
#line 280 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW << "PARSER expr: | STRING_LITERAL" << FMT_RESET << endl;
                                                                    yylhs.value.as < std::string > ()=yystack_[0].value.as < std::string > ();
                                                                }
#line 1174 "build/pparser.tab.cc"
    break;

  case 28: // expr: MINUS expr
#line 284 "src/pparser.yy"
                                                                {
                                                                    cout << "PARSER expr: | expr\n";
                                                                }
#line 1182 "build/pparser.tab.cc"
    break;

  case 29: // expr: expr PLUS expr
#line 287 "src/pparser.yy"
                                                                {
                                                                    cout << "PARSER expr: | expr\n";
                                                                }
#line 1190 "build/pparser.tab.cc"
    break;

  case 30: // expr: expr MINUS expr
#line 290 "src/pparser.yy"
                                                                {
                                                                    cout << "PARSER expr: | expr\n";
                                                                }
#line 1198 "build/pparser.tab.cc"
    break;

  case 31: // expr: expr ASTERISK expr
#line 293 "src/pparser.yy"
                                                                {
                                                                    cout << "PARSER expr: | expr\n";
                                                                }
#line 1206 "build/pparser.tab.cc"
    break;

  case 32: // expr: expr SLASH expr
#line 296 "src/pparser.yy"
                                                                {
                                                                    cout << "PARSER expr: | expr\n";
                                                                }
#line 1214 "build/pparser.tab.cc"
    break;

  case 33: // expr: expr LESS_THAN expr
#line 299 "src/pparser.yy"
                                                                {
                                                                    cout << "PARSER expr: | expr\n";
                                                                }
#line 1222 "build/pparser.tab.cc"
    break;

  case 34: // expr: expr GREATER_THAN expr
#line 302 "src/pparser.yy"
                                                                {
                                                                    cout << "PARSER expr: | expr\n";
                                                                }
#line 1230 "build/pparser.tab.cc"
    break;

  case 35: // expr: expr GREATER_THAN_EQUAL expr
#line 305 "src/pparser.yy"
                                                                {
                                                                    cout << "PARSER expr: | expr\n";
                                                                }
#line 1238 "build/pparser.tab.cc"
    break;

  case 36: // expr: expr LESS_THAN_EQUAL expr
#line 308 "src/pparser.yy"
                                                                {
                                                                    cout << "PARSER expr: | expr\n";
                                                                }
#line 1246 "build/pparser.tab.cc"
    break;

  case 37: // expr: expr NOT_EQUAL expr
#line 311 "src/pparser.yy"
                                                                {
                                                                    cout << "PARSER expr: | expr\n";
                                                                }
#line 1254 "build/pparser.tab.cc"
    break;

  case 38: // expr: LPAREN expr RPAREN
#line 314 "src/pparser.yy"
                                                                {
                                                                    cout << "PARSER expr: | expr\n";
                                                                }
#line 1262 "build/pparser.tab.cc"
    break;

  case 39: // qualafied_id: symbol DOT IDENTIFIER
#line 343 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW
                                                                        << "PARSER qualafied_id: | symbol DOT IDENTIFIER"
                                                                        << FMT_RESET << endl;
                                                                }
#line 1272 "build/pparser.tab.cc"
    break;

  case 40: // qualafied_id: symbol INDIRECT_MEMBER IDENTIFIER
#line 348 "src/pparser.yy"
                                                                { cout << FMT_FG_YELLOW << "PARSER qualafied_id: | symbol INDIRECT_MEMBER IDENTIFIER" << FMT_RESET << endl; }
#line 1278 "build/pparser.tab.cc"
    break;

  case 41: // qualafied_id: qualafied_id DOT IDENTIFIER
#line 349 "src/pparser.yy"
                                                                { cout << FMT_FG_YELLOW << "PARSER qualafied_id: | qualafied_id DOT IDENTIFIER" << FMT_RESET << endl; }
#line 1284 "build/pparser.tab.cc"
    break;

  case 42: // qualafied_id: qualafied_id INDIRECT_MEMBER IDENTIFIER
#line 350 "src/pparser.yy"
                                                                { cout << FMT_FG_YELLOW << "PARSER qualafied_id: | qualafied_id INDIRECT_MEMBER IDENTIFIER" << FMT_RESET << endl; }
#line 1290 "build/pparser.tab.cc"
    break;

  case 43: // sub_proc: symbol LPAREN params RPAREN
#line 356 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW
                                                                        << "PARSER sub_proc: | symbol LPAREN params RPAREN"
                                                                        << FMT_RESET << endl;
                                                                    yylhs.value.as < std::string > ()=yystack_[3].value.as < std::string > ();
                                                                }
#line 1301 "build/pparser.tab.cc"
    break;

  case 44: // array: symbol OPEN_BRACKET NUMERIC_LITERAL CLOSE_BRACKET
#line 367 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW
                                                                        << "PARSER array: | symbol=\"" << yystack_[3].value.as < std::string > () << "\" OPEN_BRACKET NUMERIC_LITERAL=\"" << yystack_[1].value.as < std::string > () << "\" CLOSE_BRACKET"
                                                                        << FMT_RESET << endl;
                                                                    yylhs.value.as < std::string > ()=yystack_[3].value.as < std::string > ();
                                                                }
#line 1312 "build/pparser.tab.cc"
    break;

  case 45: // params: param
#line 379 "src/pparser.yy"
                                                                {
                                                                    cout << "PARSER params: | param\n" << endl;
                                                                }
#line 1320 "build/pparser.tab.cc"
    break;

  case 46: // params: params symbol
#line 382 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW << "PARSER qualafied_id: | params COMMA symbol" << FMT_RESET << endl;
                                                                }
#line 1328 "build/pparser.tab.cc"
    break;

  case 47: // param: symbol COMMA
#line 391 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW << "PARSER param: | symbol" << FMT_RESET << endl;
                                                                }
#line 1336 "build/pparser.tab.cc"
    break;

  case 48: // symbol: DOLLAR_SIGN IDENTIFIER
#line 399 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW << "PARSER symbol: | IDENTIFIER=\"" << yystack_[0].value.as < std::string > () << "\"" << FMT_RESET << endl;
                                                                    yylhs.value.as < std::string > ()=yystack_[0].value.as < std::string > ();
                                                                }
#line 1345 "build/pparser.tab.cc"
    break;

  case 49: // symbol: CONST_ID
#line 403 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW << "PARSER symbol: | CONST_ID=\"" << yystack_[0].value.as < std::string > () << "\"" << FMT_RESET << endl;;
                                                                    yylhs.value.as < std::string > ()=yystack_[0].value.as < std::string > ();
                                                                }
#line 1354 "build/pparser.tab.cc"
    break;

  case 50: // modifier: CAPITALIZE
#line 412 "src/pparser.yy"
                                                                {
                                                                    cout << "PARSER modifier: | CAPITALIZE\n";
                                                                }
#line 1362 "build/pparser.tab.cc"
    break;

  case 51: // modifier: CAT
#line 415 "src/pparser.yy"
                                                                {
                                                                    cout  << "PARSER modifier: | CAT\n";
                                                                }
#line 1370 "build/pparser.tab.cc"
    break;

  case 52: // modifier: COUNT_CHARACTERS
#line 418 "src/pparser.yy"
                                                                {
                                                                    cout  << "PARSER modifier: | COUNT_CHARACTERS\n";
                                                                }
#line 1378 "build/pparser.tab.cc"
    break;

  case 53: // modifier: COUNT_SENTENCES
#line 421 "src/pparser.yy"
                                                                {
                                                                    cout  << "PARSER modifier: | COUNT_SENTENCES\n";
                                                                }
#line 1386 "build/pparser.tab.cc"
    break;

  case 54: // modifier: COUNT_PARAGRAPHS
#line 424 "src/pparser.yy"
                                                                {
                                                                    cout  << "PARSER modifier: | COUNT_PARAGRAPHS\n";
                                                                }
#line 1394 "build/pparser.tab.cc"
    break;

  case 55: // modifier: COUNT_WORDS
#line 427 "src/pparser.yy"
                                                                {
                                                                    cout  << "PARSER modifier: | COUNT_WORDS\n";
                                                                }
#line 1402 "build/pparser.tab.cc"
    break;

  case 56: // modifier: DATE_FORMAT
#line 430 "src/pparser.yy"
                                                                {
                                                                    cout  << "PARSER modifier: | DATE_FORMAT\n";
                                                                }
#line 1410 "build/pparser.tab.cc"
    break;

  case 57: // modifier: DEFAULT
#line 433 "src/pparser.yy"
                                                                {
                                                                    cout  << "PARSER modifier: | DEFAULT\n";
                                                                }
#line 1418 "build/pparser.tab.cc"
    break;

  case 58: // modifier: ESCAPE
#line 436 "src/pparser.yy"
                                                                {
                                                                    cout  << "PARSER modifier: | ESCAPE\n";
                                                                }
#line 1426 "build/pparser.tab.cc"
    break;

  case 59: // modifier: INDENT
#line 439 "src/pparser.yy"
                                                                {
                                                                    cout  << "PARSER modifier: | INDENT\n";
                                                                }
#line 1434 "build/pparser.tab.cc"
    break;

  case 60: // modifier: STRIP
#line 442 "src/pparser.yy"
                                                                {
                                                                    cout  << "PARSER modifier: | STRIPS\n";
                                                                }
#line 1442 "build/pparser.tab.cc"
    break;

  case 61: // modifier: NL2BR
#line 445 "src/pparser.yy"
                                                                {
                                                                    cout  << "PARSER modifier: | NL2BR\n";
                                                                }
#line 1450 "build/pparser.tab.cc"
    break;

  case 62: // modifier: REPLACE
#line 448 "src/pparser.yy"
                                                                {
                                                                    cout  << "PARSER modifier: | REPLACE\n";
                                                                }
#line 1458 "build/pparser.tab.cc"
    break;

  case 63: // modifier: REGEX_REPLACE
#line 451 "src/pparser.yy"
                                                                {
                                                                    cout  << "PARSER modifier: | REGEX_REPLACE\n";
                                                                }
#line 1466 "build/pparser.tab.cc"
    break;

  case 64: // modifier: SPACIFY
#line 454 "src/pparser.yy"
                                                                {
                                                                    cout  << "PARSER modifier: | SPACIFY\n";
                                                                }
#line 1474 "build/pparser.tab.cc"
    break;

  case 65: // modifier: STRING_FORMAT
#line 457 "src/pparser.yy"
                                                                {
                                                                    cout  << "PARSER modifier: | STRING_FORMAT\n";
                                                                }
#line 1482 "build/pparser.tab.cc"
    break;

  case 66: // modifier: STRIP_TAGS
#line 460 "src/pparser.yy"
                                                                {
                                                                    cout  << "PARSER modifier: | STIP_TAGS\n";
                                                                }
#line 1490 "build/pparser.tab.cc"
    break;

  case 67: // modifier: TRUNCATE
#line 463 "src/pparser.yy"
                                                                {
                                                                    cout  << "PARSER modifier: | TRUNCATE\n";
                                                                }
#line 1498 "build/pparser.tab.cc"
    break;

  case 68: // modifier: UPPER
#line 466 "src/pparser.yy"
                                                                {
                                                                    cout  << "PARSER modifier: | UPPER\n";
                                                                }
#line 1506 "build/pparser.tab.cc"
    break;

  case 69: // modifier: LOWER
#line 469 "src/pparser.yy"
                                                                {
                                                                    cout  << "PARSER modifier: | LOWER\n";
                                                                }
#line 1514 "build/pparser.tab.cc"
    break;

  case 70: // modifier: WORDWRAP
#line 472 "src/pparser.yy"
                                                                {
                                                                    cout  << "PARSER modifier: | WORDWRAP\n";
                                                                }
#line 1522 "build/pparser.tab.cc"
    break;

  case 71: // built_in: CONFIG_LOAD attributes
#line 480 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW << "PARSER built_in: | CONFIG_LOAD FILE_ATTRIB=\""
                                                                        << yystack_[1].value.as < std::string > () << "\" EQUAL STRING_LITERAL=\"" << "TEST" << "\""
                                                                        << FMT_RESET << endl;
                                                                }
#line 1532 "build/pparser.tab.cc"
    break;

  case 72: // built_in: INCLUDE attributes
#line 485 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW
                                                                        << "PARSER built_in: | INCLUDE FILE_ATTRIB=\"" << "INCLUDE_FILE_TEST" << "\" EQUAL STRING_LITERAL=\"\""
                                                                        << FMT_RESET << endl;
                                                                    yylhs.value.as < std::vector< std::pair<std::string, std::string> >  > () = yystack_[0].value.as < std::vector< std::pair<std::string, std::string> >  > ();
                                                                }
#line 1543 "build/pparser.tab.cc"
    break;

  case 73: // built_in: REQUIRE attributes
#line 491 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW
                                                                        << "PARSER built_in: | REQUIRE FILE_ATTRIB=\"%s\" EQUAL STRING_LITERAL=\"\""
                                                                        << FMT_RESET << endl;

                                                                }
#line 1554 "build/pparser.tab.cc"
    break;

  case 74: // built_in: REQUIRE_ONCE attributes
#line 497 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW
                                                                        << "PARSER built_in: | REQUIRE_ONCE FILE_ATTRIB=\"%s\" EQUAL STRING_LITERAL=\"\""
                                                                        << FMT_RESET << endl;

                                                                }
#line 1565 "build/pparser.tab.cc"
    break;

  case 75: // built_in: INSERT attributes
#line 503 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW
                                                                        << "PARSER built_in: | INSERT FILE_ATTRIB=\"\" EQUAL STRING_LITERAL=\"\""
                                                                        << FMT_RESET << endl;

                                                                }
#line 1576 "build/pparser.tab.cc"
    break;

  case 76: // built_in: ASSIGN attributes
#line 509 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW
                                                                        << "PARSER built_in: | ASSIGN FILE_ATTRIB=\"\" EQUAL STRING_LITERAL=\"\""
                                                                        << FMT_RESET << endl;
                                                                }
#line 1586 "build/pparser.tab.cc"
    break;

  case 77: // built_in: ISSET attributes
#line 514 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW
                                                                        << "PARSER built_in: | ISSET FILE_ATTRIB=\"\" EQUAL STRING_LITERAL=\"\""
                                                                        << FMT_RESET << endl;
                                                                }
#line 1596 "build/pparser.tab.cc"
    break;

  case 78: // built_in: VERSION attributes
#line 519 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW
                                                                        << "PARSER built_in: | VERSION FILE_ATTRIB=\"\" EQUAL STRING_LITERAL=\"\""
                                                                        << FMT_RESET << endl;
                                                                }
#line 1606 "build/pparser.tab.cc"
    break;

  case 79: // attributes: attrib
#line 530 "src/pparser.yy"
                                                               {
                                                                    cout << FMT_FG_YELLOW << "PARSER attribute: | push -> attrib={name=\"" << yystack_[0].value.as <  std::pair<std::string, std::string>  > ().first  << "\"; value=\"" << yystack_[0].value.as <  std::pair<std::string, std::string>  > ().second << "\"}\n" << FMT_RESET << endl;
                                                                    std::pair<std::string, std::string>  p(yystack_[0].value.as <  std::pair<std::string, std::string>  > ());
                                                                    std::vector< std::pair<std::string, std::string> > v;
                                                                    v.push_back( p );
                                                                    yylhs.value.as < std::vector< std::pair<std::string, std::string> >  > () = v;
                                                               }
#line 1618 "build/pparser.tab.cc"
    break;

  case 80: // attributes: attributes attrib
#line 537 "src/pparser.yy"
                                                               {
                                                                    cout << FMT_FG_YELLOW << "PARSER attribute: | attributes : push-> attrib={name=\"" << yystack_[0].value.as <  std::pair<std::string, std::string>  > ().first  << "\"; value=\"" << yystack_[0].value.as <  std::pair<std::string, std::string>  > ().second << "\"}\n" << FMT_RESET << endl;
                                                                    yystack_[1].value.as < std::vector< std::pair<std::string, std::string> >  > ().push_back( yystack_[0].value.as <  std::pair<std::string, std::string>  > () );
                                                                    yylhs.value.as < std::vector< std::pair<std::string, std::string> >  > () = yystack_[1].value.as < std::vector< std::pair<std::string, std::string> >  > ();
                                                               }
#line 1628 "build/pparser.tab.cc"
    break;

  case 81: // attrib: VALUE_ATTRIB EQUAL_SIGN STRING_LITERAL
#line 548 "src/pparser.yy"
                                                               {
                                                                    cout << FMT_FG_YELLOW << "PARSER name_value: | VALUE_ATTRIB=\""
                                                                        << yystack_[2].value.as < std::string > () << "\" EQUAL_SIGN STRING_LITERAL=\""
                                                                        << buf << "\"" << FMT_RESET << endl;

                                                                    std::pair<std::string, std::string>  pair(yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ());
                                                                    yylhs.value.as <  std::pair<std::string, std::string>  > () = pair;
                                                               }
#line 1641 "build/pparser.tab.cc"
    break;

  case 82: // attrib: VAR_ATTRIB EQUAL_SIGN STRING_LITERAL
#line 556 "src/pparser.yy"
                                                               {
                                                                    cout << FMT_FG_YELLOW
                                                                        << "PARSER name_value: | VAR_ATTRIB=\"\" EQUAL_SIGN STRING_LITERAL=\"\""
                                                                        << FMT_FG_GREEN << FMT_RESET << endl;

                                                                    std::pair<std::string, std::string>  pair(yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ());
                                                                    yylhs.value.as <  std::pair<std::string, std::string>  > () = pair;
                                                               }
#line 1654 "build/pparser.tab.cc"
    break;

  case 83: // attrib: FILE_ATTRIB EQUAL_SIGN STRING_LITERAL
#line 564 "src/pparser.yy"
                                                               {
                                                                    cout << FMT_FG_YELLOW
                                                                        << "PARSER name_value: | FILE_ATTRIB=\""
                                                                        << yystack_[2].value.as < std::string > () << "\" EQUAL_SIGN STRING_LITERAL=\""
                                                                        << yystack_[0].value.as < std::string > () << "\""
                                                                        << FMT_RESET << endl;

                                                                    std::pair<std::string, std::string>  pair(yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ());
                                                                    yylhs.value.as <  std::pair<std::string, std::string>  > () = pair;
                                                               }
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









  const signed char parser::yypact_ninf_ = -102;

  const signed char parser::yytable_ninf_ = -27;

  const short
  parser::yypact_[] =
  {
     -14,    -6,    16,   -14,  -102,     9,  -102,   -13,   -58,   -48,
     -48,   -48,   -48,   -48,   -48,   -48,   -48,  -102,  -102,     3,
      22,   -13,   -66,    44,    46,   -19,   -17,    49,    51,    -7,
      55,  -102,  -102,  -102,  -102,     5,  -102,    -9,    -2,     0,
     -48,  -102,   -48,   -48,   -48,   -48,   -48,   -48,   -48,   -13,
     -13,  -102,    58,  -102,  -102,  -102,   115,   -13,   -13,   -13,
     -13,   -13,   -13,   -13,   -13,   -13,    91,    34,    35,    94,
      97,    41,  -102,   -12,    42,    45,   -20,  -102,  -102,    50,
      54,    64,  -102,    33,    43,  -102,  -102,  -102,  -102,  -102,
    -102,  -102,  -102,  -102,  -102,  -102,  -102,  -102,  -102,  -102,
    -102,  -102,  -102,  -102,  -102,  -102,  -102,   101,   -10,   -10,
     -10,   -10,   -10,   -42,   -42,  -102,  -102,  -102,  -102,   104,
      -5,  -102,   123,  -102,  -102,  -102,  -102,  -102,  -102,  -102,
      23,    23,  -102,  -102,  -102,  -102,  -102,   -79,   -16,   129,
     130,   -15,  -102,    23,    59,  -102,  -102,  -102,   134,   135,
    -102,  -102
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     2,     3,     0,     6,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    27,    49,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     4,     5,     7,     0,    48,     0,     0,     0,
      71,    79,    72,    73,    74,    75,    76,    77,    78,     0,
       0,    28,     0,    11,    14,    17,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    12,     0,     0,     8,
       9,     0,    10,     0,     0,     0,     0,    13,    38,     0,
       0,     0,    80,     0,     0,    21,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    69,    68,    60,    61,
      63,    62,    64,    65,    66,    67,    70,     0,    35,    36,
      37,    33,    34,    29,    30,    31,    32,    41,    42,     0,
       0,    45,     0,    39,    40,    16,    15,    82,    81,    83,
      19,     0,    25,    44,    43,    46,    47,     0,     0,     0,
       0,     0,    18,     0,     0,    26,    23,    24,     0,     0,
      22,    20
  };

  const short
  parser::yypgoto_[] =
  {
    -102,  -102,  -102,   153,  -102,   152,  -102,  -101,   103,   157,
     158,   196,  -102,  -102,    -1,  -102,  -102,   180,     6
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,     2,     3,     4,     5,     6,    23,    24,    25,   138,
     139,   140,   120,   121,   141,   107,    30,    40,    41
  };

  const short
  parser::yytable_[] =
  {
      29,    55,    71,    66,   145,     1,    73,    56,     7,    33,
      71,   143,     8,    72,    73,     7,    31,   134,     8,     8,
      36,    67,    67,    74,    49,   144,    52,    78,     1,   137,
     142,    74,    37,    38,    39,     9,    10,    11,    12,    13,
      14,    15,   148,    50,     7,    16,    82,     8,    82,    82,
      82,    82,    82,    82,    82,   130,   125,   126,    68,    68,
      75,    64,    65,    17,    53,   131,    54,    18,    75,    69,
      17,    70,   122,    18,    18,    77,    57,    58,    85,    59,
      60,    61,    62,    63,    64,    65,    19,    20,    79,    21,
      76,    62,    63,    64,    65,    80,    21,    81,    22,    17,
      57,    58,    18,    59,    60,    61,    62,    63,    64,    65,
      35,   -26,   117,   118,   -23,    19,    20,   -24,   119,   135,
     123,   132,   133,   124,    51,    21,   127,    22,    57,    58,
     128,    59,    60,    61,    62,    63,    64,    65,    57,    58,
     129,    59,    60,    61,    62,    63,    64,    65,   136,   146,
     147,   149,    83,    84,   150,   151,    32,    34,    26,    27,
     108,   109,   110,   111,   112,   113,   114,   115,   116,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
      42,    43,    44,    45,    46,    47,    48,    28
  };

  const unsigned char
  parser::yycheck_[] =
  {
       1,    20,    17,    20,    20,    19,    21,    26,    21,     0,
      17,    90,    24,    20,    21,    21,     0,    22,    24,    24,
      78,    38,    38,    38,    21,   104,    92,    22,    19,   130,
     131,    38,    80,    81,    82,    41,    42,    43,    44,    45,
      46,    47,   143,    21,    21,    51,    40,    24,    42,    43,
      44,    45,    46,    47,    48,    22,    76,    77,    75,    75,
      75,   103,   104,    76,    20,    22,    20,    79,    75,    20,
      76,    20,    73,    79,    79,    20,    95,    96,    20,    98,
      99,   100,   101,   102,   103,   104,    92,    93,    97,   102,
      97,   101,   102,   103,   104,    97,   102,    97,   104,    76,
      95,    96,    79,    98,    99,   100,   101,   102,   103,   104,
       7,    20,    78,    78,    20,    92,    93,    20,    77,   120,
      78,    20,    18,    78,    21,   102,    76,   104,    95,    96,
      76,    98,    99,   100,   101,   102,   103,   104,    95,    96,
      76,    98,    99,   100,   101,   102,   103,   104,    25,    20,
      20,    92,    49,    50,    20,    20,     3,     5,     1,     1,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      10,    11,    12,    13,    14,    15,    16,     1
  };

  const signed char
  parser::yystos_[] =
  {
       0,    19,   108,   109,   110,   111,   112,    21,    24,    41,
      42,    43,    44,    45,    46,    47,    51,    76,    79,    92,
      93,   102,   104,   113,   114,   115,   116,   117,   118,   121,
     123,     0,   110,     0,   112,   115,    78,    80,    81,    82,
     124,   125,   124,   124,   124,   124,   124,   124,   124,    21,
      21,   115,    92,    20,    20,    20,    26,    95,    96,    98,
      99,   100,   101,   102,   103,   104,    20,    38,    75,    20,
      20,    17,    20,    21,    38,    75,    97,    20,    22,    97,
      97,    97,   125,   115,   115,    20,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,   122,   115,   115,
     115,   115,   115,   115,   115,   115,   115,    78,    78,    77,
     119,   120,   121,    78,    78,    76,    77,    76,    76,    76,
      22,    22,    20,    18,    22,   121,    25,   114,   116,   117,
     118,   121,   114,    90,   104,    20,    20,    20,   114,    92,
      20,    20
  };

  const signed char
  parser::yyr1_[] =
  {
       0,   107,   108,   109,   109,   110,   111,   111,   112,   112,
     112,   112,   112,   112,   112,   113,   113,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   116,
     116,   116,   116,   117,   118,   119,   119,   120,   121,   121,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   123,   123,   123,   123,   123,   123,   123,   123,   124,
     124,   125,   125,   125
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     1,     2,     2,     1,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     5,     4,
       8,     3,     8,     2,     2,     4,     2,     1,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     4,     4,     1,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       2,     3,     3,     3
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of input\"", "error", "\"invalid token\"", "MATCH", "UNDEFINED",
  "WHITESPACE", "ANYTHING", "VALID_CHAR", "SKIP_TOKEN", "CONST_SYMBOL",
  "CARROT", "OPEN_PAREN", "CLOSE_PAREN", "DASH", "PLUS_SIGN", "BACKSLASH",
  "ARRAY", "OPEN_BRACKET", "CLOSE_BRACKET", "OPEN_BRACE", "CLOSE_BRACE",
  "LPAREN", "RPAREN", "QUESTION_MARK", "DOLLAR_SIGN", "COMMA", "VBAR",
  "COLON", "HASH_MARK", "SEMI_COLON", "DOUBLE_QUOTE", "SINGLE_QUOTE",
  "BACK_SLASH", "AT", "AMPERSAND", "AND", "OR", "NOT", "DOT",
  "END_OF_FILES", "CAPTURE", "CONFIG_LOAD", "INCLUDE", "REQUIRE",
  "REQUIRE_ONCE", "INSERT", "ASSIGN", "ISSET", "SECTION", "LDELIM",
  "RDELIM", "VERSION", "CYCLE", "COUNTER", "CAPITALIZE", "CAT",
  "COUNT_CHARACTERS", "COUNT_SENTENCES", "COUNT_PARAGRAPHS", "COUNT_WORDS",
  "DATE_FORMAT", "DEFAULT", "ESCAPE", "INDENT", "LOWER", "UPPER", "STRIP",
  "NL2BR", "REGEX_REPLACE", "REPLACE", "SPACIFY", "STRING_FORMAT",
  "STRIP_TAGS", "TRUNCATE", "WORDWRAP", "INDIRECT_MEMBER",
  "STRING_LITERAL", "NUMERIC_LITERAL", "IDENTIFIER", "CONST_ID",
  "VAR_ATTRIB", "VALUE_ATTRIB", "FILE_ATTRIB", "FROM_ATTRIB", "KEY_ATTRIB",
  "NAME_ATTRIB", "ITEM_ATTRIB", "FILE_NAME", "UNESCAPED_TEXT", "IFX",
  "ELSE", "ELSEIF", "IF", "WHILE", "BREAK", "GREATER_THAN_EQUAL",
  "LESS_THAN_EQUAL", "EQUAL_SIGN", "NOT_EQUAL", "LESS_THAN",
  "GREATER_THAN", "PLUS", "MINUS", "ASTERISK", "SLASH", "PERCENT_SIGN",
  "UMINUS", "$accept", "complier", "files", "file", "blocks", "block",
  "assign_stmt", "stmt", "expr", "qualafied_id", "sub_proc", "array",
  "params", "param", "symbol", "modifier", "built_in", "attributes",
  "attrib", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   119,   119,   130,   131,   137,   148,   151,   160,   163,
     166,   175,   178,   188,   211,   219,   234,   243,   247,   250,
     253,   256,   260,   263,   266,   269,   272,   280,   284,   287,
     290,   293,   296,   299,   302,   305,   308,   311,   314,   343,
     348,   349,   350,   356,   367,   379,   382,   391,   399,   403,
     412,   415,   418,   421,   424,   427,   430,   433,   436,   439,
     442,   445,   448,   451,   454,   457,   460,   463,   466,   469,
     472,   480,   485,   491,   497,   503,   509,   514,   519,   530,
     537,   548,   556,   564
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
#line 2100 "build/pparser.tab.cc"

#line 576 "src/pparser.yy"


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
    /* auto parser::yylex() -> yy::parser::symbol_type
    {
        static int i = 0;
        static int count = 0;
        switch(int stage = count++)
        {
            case 0:
                return parser::make_NUMBER(666);
            case 1:
                return parser::make_END();
        }
        return 0;
    } */

    parser::symbol_type yylex()
    {
        return lex();
    }

    auto parser::error(const std::string& msg) -> void
    {
        std::cerr << msg << '\n';
    }
}
