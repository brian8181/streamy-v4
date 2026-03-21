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
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "../src/bash_color.h"
    #include "../src/symtab.h"
    #include "../src/scanner.h"

    using std::string;
    using std::cout;
    using std::endl;
    using std::pair;
    typedef std::pair< std::string, std::string > attribute;

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
#line 42 "src/pparser.yy"

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
    typedef std::pair< std::string, std::string > attribute;


#line 110 "build/pparser.tab.cc"


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
#line 187 "build/pparser.tab.cc"

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
      case symbol_kind::S_NUMBER: // NUMBER
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_attrib: // attrib
        value.YY_MOVE_OR_COPY< std::pair< std::string, std::string >  > (YY_MOVE (that.value));
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
      case symbol_kind::S_REGX_REPLACE: // REGX_REPLACE
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
      case symbol_kind::S_number: // number
      case symbol_kind::S_qualafied_id: // qualafied_id
      case symbol_kind::S_sub_proc: // sub_proc
      case symbol_kind::S_array: // array
      case symbol_kind::S_symbol: // symbol
      case symbol_kind::S_built_in: // built_in
      case symbol_kind::S_attributes: // attributes
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
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
      case symbol_kind::S_NUMBER: // NUMBER
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_attrib: // attrib
        value.move< std::pair< std::string, std::string >  > (YY_MOVE (that.value));
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
      case symbol_kind::S_REGX_REPLACE: // REGX_REPLACE
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
      case symbol_kind::S_number: // number
      case symbol_kind::S_qualafied_id: // qualafied_id
      case symbol_kind::S_sub_proc: // sub_proc
      case symbol_kind::S_array: // array
      case symbol_kind::S_symbol: // symbol
      case symbol_kind::S_built_in: // built_in
      case symbol_kind::S_attributes: // attributes
        value.move< std::string > (YY_MOVE (that.value));
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
      case symbol_kind::S_NUMBER: // NUMBER
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_attrib: // attrib
        value.copy< std::pair< std::string, std::string >  > (that.value);
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
      case symbol_kind::S_REGX_REPLACE: // REGX_REPLACE
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
      case symbol_kind::S_number: // number
      case symbol_kind::S_qualafied_id: // qualafied_id
      case symbol_kind::S_sub_proc: // sub_proc
      case symbol_kind::S_array: // array
      case symbol_kind::S_symbol: // symbol
      case symbol_kind::S_built_in: // built_in
      case symbol_kind::S_attributes: // attributes
        value.copy< std::string > (that.value);
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
      case symbol_kind::S_NUMBER: // NUMBER
        value.move< int > (that.value);
        break;

      case symbol_kind::S_attrib: // attrib
        value.move< std::pair< std::string, std::string >  > (that.value);
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
      case symbol_kind::S_REGX_REPLACE: // REGX_REPLACE
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
      case symbol_kind::S_number: // number
      case symbol_kind::S_qualafied_id: // qualafied_id
      case symbol_kind::S_sub_proc: // sub_proc
      case symbol_kind::S_array: // array
      case symbol_kind::S_symbol: // symbol
      case symbol_kind::S_built_in: // built_in
      case symbol_kind::S_attributes: // attributes
        value.move< std::string > (that.value);
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
      case symbol_kind::S_NUMBER: // NUMBER
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_attrib: // attrib
        yylhs.value.emplace< std::pair< std::string, std::string >  > ();
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
      case symbol_kind::S_REGX_REPLACE: // REGX_REPLACE
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
      case symbol_kind::S_number: // number
      case symbol_kind::S_qualafied_id: // qualafied_id
      case symbol_kind::S_sub_proc: // sub_proc
      case symbol_kind::S_array: // array
      case symbol_kind::S_symbol: // symbol
      case symbol_kind::S_built_in: // built_in
      case symbol_kind::S_attributes: // attributes
        yylhs.value.emplace< std::string > ();
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
#line 112 "src/pparser.yy"
                                                                {
                                                                    cout <<  FMT_FG_GREEN << "PARSER complier: | files" << FMT_RESET << endl;
                                                                    cout << FMT_FG_YELLOW << "*********************** STOPPING **********************" << FMT_REVERSE << FMT_RESET << endl;
                                                                    cout << FMT_FG_YELLOW << "*                     Terminating.                    *" << FMT_REVERSE << FMT_RESET << endl;
                                                                    cout << FMT_FG_YELLOW << "************************* Done ************************" << FMT_REVERSE << FMT_RESET << endl;
                                                                }
#line 918 "build/pparser.tab.cc"
    break;

  case 3: // files: file
#line 124 "src/pparser.yy"
                                                                { cout << FMT_FG_YELLOW << "PARSER files: | file" << FMT_RESET << endl; }
#line 924 "build/pparser.tab.cc"
    break;

  case 4: // files: files file
#line 125 "src/pparser.yy"
                                                                { cout << FMT_FG_YELLOW << "PARSER files: | files file" << FMT_RESET << endl; }
#line 930 "build/pparser.tab.cc"
    break;

  case 5: // file: blocks "end of input"
#line 132 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW << "PARSER file: | blocks END_OF_FILE" << FMT_RESET << endl;
                                                                    cout << FMT_FG_YELLOW << "*******************************************************" << FMT_REVERSE << FMT_RESET << endl;
                                                                    cout << FMT_FG_YELLOW << "*                      End Of File                    *" << FMT_REVERSE << FMT_RESET << endl;
                                                                    cout << FMT_FG_YELLOW << "*******************************************************" << FMT_REVERSE << FMT_RESET << endl;
                                                                }
#line 941 "build/pparser.tab.cc"
    break;

  case 6: // blocks: block
#line 144 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW << "PARSER blocks: | block" << FMT_RESET << endl;
                                                                }
#line 949 "build/pparser.tab.cc"
    break;

  case 7: // blocks: blocks block
#line 147 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW << "PARSER blocks: | blocks block" << FMT_RESET << endl;
                                                                }
#line 957 "build/pparser.tab.cc"
    break;

  case 8: // block: OPEN_BRACE sub_proc CLOSE_BRACE
#line 156 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW << "PARSER block: | OPEN_BRACE sub_porc CLOSE_BRACE" << FMT_RESET << endl;
                                                                }
#line 965 "build/pparser.tab.cc"
    break;

  case 9: // block: OPEN_BRACE array CLOSE_BRACE
#line 159 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW << "PARSER block: | OPEN_BRACE array CLOSE_BRACE" << FMT_RESET << endl;
                                                                }
#line 973 "build/pparser.tab.cc"
    break;

  case 10: // block: OPEN_BRACE symbol CLOSE_BRACE
#line 162 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW << "PARSER block: | OPEN_BRACE symbol CLOSE_BRACE" << FMT_RESET << endl;
                                                                }
#line 981 "build/pparser.tab.cc"
    break;

  case 11: // block: OPEN_BRACE assign_stmt CLOSE_BRACE
#line 165 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW << "PARSER block: | OPEN_BRACE assign_stmt CLOSE_BRACE" << FMT_RESET << endl;
                                                                }
#line 989 "build/pparser.tab.cc"
    break;

  case 12: // block: OPEN_BRACE qualafied_id CLOSE_BRACE
#line 168 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW << "PARSER block: | OPEN_BRACE qualafied_id CLOSE_BRACE" << FMT_RESET << endl;
                                                                }
#line 997 "build/pparser.tab.cc"
    break;

  case 13: // block: OPEN_BRACE built_in CLOSE_BRACE
#line 171 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW << "PARSER block: | OPEN_BRACE built_in CLOSE_BRACE" << FMT_RESET << endl;
                                                                    //free_all_nvalues();
                                                                }
#line 1006 "build/pparser.tab.cc"
    break;

  case 14: // assign_stmt: symbol EQUAL_SIGN number
#line 181 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW << "PARSER assign_stmt: | symbol EQUAL_SIGN NUMERIC_LITERAL" << FMT_RESET << endl;
                                                                    if(auto iter = stab.find(yystack_[2].value.as < std::string > ()) != stab.end())
                                                                    {
                                                                        //iter->second = $3;
                                                                    }
                                                                    yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > ();
                                                                }
#line 1019 "build/pparser.tab.cc"
    break;

  case 15: // assign_stmt: symbol EQUAL_SIGN STRING_LITERAL
#line 189 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW << "PARSER assign_stmt: | symbol EQUAL_SIGN STRING_LITERAL=" << FMT_RESET << yystack_[0].value.as < std::string > () << "\n";
                                                                    yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > ();
                                                                }
#line 1028 "build/pparser.tab.cc"
    break;

  case 16: // number: NUMERIC_LITERAL
#line 197 "src/pparser.yy"
                                                                 {
                                                                    cout << "PARSER number: | NUMERIC_LITERAL\n";
                                                                    yylhs.value.as < std::string > ()=yystack_[0].value.as < std::string > ();
                                                                }
#line 1037 "build/pparser.tab.cc"
    break;

  case 17: // qualafied_id: symbol DOT IDENTIFIER
#line 315 "src/pparser.yy"
                                                                        {
                                                                    cout << FMT_FG_YELLOW
                                                                            << "PARSER qualafied_id: | symbol DOT IDENTIFIER"
                                                                         << FMT_RESET << endl;
                                                                }
#line 1047 "build/pparser.tab.cc"
    break;

  case 18: // qualafied_id: symbol INDIRECT_MEMBER IDENTIFIER
#line 320 "src/pparser.yy"
                                                                        { cout << FMT_FG_YELLOW << "PARSER qualafied_id: | symbol INDIRECT_MEMBER IDENTIFIER" << FMT_RESET << endl; }
#line 1053 "build/pparser.tab.cc"
    break;

  case 19: // qualafied_id: qualafied_id DOT IDENTIFIER
#line 321 "src/pparser.yy"
                                                                        { cout << FMT_FG_YELLOW << "PARSER qualafied_id: | qualafied_id DOT IDENTIFIER" << FMT_RESET << endl; }
#line 1059 "build/pparser.tab.cc"
    break;

  case 20: // qualafied_id: qualafied_id INDIRECT_MEMBER IDENTIFIER
#line 322 "src/pparser.yy"
                                                                        { cout << FMT_FG_YELLOW << "PARSER qualafied_id: | qualafied_id INDIRECT_MEMBER IDENTIFIER" << FMT_RESET << endl; }
#line 1065 "build/pparser.tab.cc"
    break;

  case 21: // sub_proc: symbol LPAREN params RPAREN
#line 329 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW
                                                                            << "PARSER sub_proc: | symbol LPAREN params RPAREN"
                                                                        << FMT_RESET << endl;
                                                                    yylhs.value.as < std::string > ()=yystack_[3].value.as < std::string > ();
                                                                }
#line 1076 "build/pparser.tab.cc"
    break;

  case 22: // array: symbol OPEN_BRACKET NUMERIC_LITERAL CLOSE_BRACKET
#line 341 "src/pparser.yy"
                                                                         {
                                                                    cout << FMT_FG_YELLOW
                                                                            << "PARSER array: | symbol=\"" << yystack_[3].value.as < std::string > () << "\" OPEN_BRACKET NUMERIC_LITERAL=\"" << yystack_[1].value.as < std::string > () << "\" CLOSE_BRACKET"
                                                                        << FMT_RESET << endl;;
                                                                    yylhs.value.as < std::string > ()=yystack_[3].value.as < std::string > ();
                                                                }
#line 1087 "build/pparser.tab.cc"
    break;

  case 23: // params: param
#line 354 "src/pparser.yy"
                                                                {
                                                                    cout << "PARSER params: | param\n" << endl;
                                                                }
#line 1095 "build/pparser.tab.cc"
    break;

  case 24: // params: params symbol
#line 357 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW << "PARSER qualafied_id: | params COMMA symbol" << FMT_RESET << endl;
                                                                }
#line 1103 "build/pparser.tab.cc"
    break;

  case 25: // param: symbol COMMA
#line 368 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW << "PARSER param: | symbol" << FMT_RESET << endl;
                                                                }
#line 1111 "build/pparser.tab.cc"
    break;

  case 26: // symbol: DOLLAR_SIGN IDENTIFIER
#line 377 "src/pparser.yy"
                                                               {
                                                                    cout << FMT_FG_YELLOW << "PARSER symbol: | IDENTIFIER=\"" << yystack_[0].value.as < std::string > () << "\"" << FMT_RESET << endl;
                                                                    yylhs.value.as < std::string > ()=yystack_[0].value.as < std::string > ();
                                                               }
#line 1120 "build/pparser.tab.cc"
    break;

  case 27: // symbol: CONST_ID
#line 381 "src/pparser.yy"
                                                               {
                                                                    cout << FMT_FG_YELLOW << "PARSER symbol: | CONST_ID=\"" << yystack_[0].value.as < std::string > () << "\"" << FMT_RESET << endl;;
                                                                    yylhs.value.as < std::string > ()=yystack_[0].value.as < std::string > ();
                                                               }
#line 1129 "build/pparser.tab.cc"
    break;

  case 28: // built_in: CONFIG_LOAD attributes
#line 460 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW << "PARSER built_in: | CONFIG_LOAD FILE_ATTRIB=\""
                                                                          << yystack_[1].value.as < std::string > () << "\" EQUAL STRING_LITERAL=\"$2\""
                                                                         << FMT_RESET << endl;
                                                                }
#line 1139 "build/pparser.tab.cc"
    break;

  case 29: // built_in: INCLUDE attributes
#line 465 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW
                                                                         << "PARSER built_in: | INCLUDE FILE_ATTRIB=\"%s\" EQUAL STRING_LITERAL=\"\""
                                                                         << FMT_RESET << endl;
                                                                }
#line 1149 "build/pparser.tab.cc"
    break;

  case 30: // built_in: REQUIRE attributes
#line 470 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW
                                                                         << "PARSER built_in: | REQUIRE FILE_ATTRIB=\"%s\" EQUAL STRING_LITERAL=\"\""
                                                                         << FMT_RESET << endl;

                                                                }
#line 1160 "build/pparser.tab.cc"
    break;

  case 31: // built_in: INSERT attributes
#line 476 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW
                                                                            << "PARSER built_in: | INSERT FILE_ATTRIB=\"\" EQUAL STRING_LITERAL=\"\""
                                                                         << FMT_RESET << endl;

                                                                }
#line 1171 "build/pparser.tab.cc"
    break;

  case 32: // built_in: ASSIGN attributes
#line 482 "src/pparser.yy"
                                                                {
                                                                    cout << FMT_FG_YELLOW
                                                                            << "PARSER built_in: | INSERT FILE_ATTRIB=\"\" EQUAL STRING_LITERAL=\"\""
                                                                         << FMT_RESET << endl;
                                                                }
#line 1181 "build/pparser.tab.cc"
    break;

  case 33: // attributes: attrib
#line 494 "src/pparser.yy"
                                                               {
                                                                    cout << FMT_FG_YELLOW << "PARSER attribute: | attribute={name=\"\"; value=\"\"\n" << FMT_RESET << endl;
                                                               }
#line 1189 "build/pparser.tab.cc"
    break;

  case 34: // attributes: attributes attrib
#line 497 "src/pparser.yy"
                                                               {
                                                                    cout << FMT_FG_YELLOW
                                                                            << "PARSER attributes: | attribute={name=\"\"; value=\"\"\n"
                                                                         << FMT_RESET << endl;
                                                               }
#line 1199 "build/pparser.tab.cc"
    break;

  case 35: // attrib: VALUE_ATTRIB EQUAL_SIGN STRING_LITERAL
#line 509 "src/pparser.yy"
                                                                    {
                                                                    cout << FMT_FG_YELLOW << "PARSER name_value: | VALUE_ATTRIB=\""
                                                                        << yystack_[2].value.as < std::string > () << "\" EQUAL_SIGN STRING_LITERAL=\""
                                                                        << buf << "\"" << FMT_RESET << endl;

                                                                    std::pair<std::string, std::string>  pair(yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ());
                                                                    yylhs.value.as < std::pair< std::string, std::string >  > () = pair;
                                                               }
#line 1212 "build/pparser.tab.cc"
    break;

  case 36: // attrib: VAR_ATTRIB EQUAL_SIGN STRING_LITERAL
#line 517 "src/pparser.yy"
                                                                    {
                                                                    cout << FMT_FG_YELLOW
                                                                            << "PARSER name_value: | VAR_ATTRIB=\"\" EQUAL_SIGN STRING_LITERAL=\"\""
                                                                         << FMT_FG_GREEN << FMT_RESET << endl;

                                                                    std::pair<std::string, std::string>  pair(yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ());
                                                                    yylhs.value.as < std::pair< std::string, std::string >  > () = pair;
                                                                }
#line 1225 "build/pparser.tab.cc"
    break;

  case 37: // attrib: FILE_ATTRIB EQUAL_SIGN STRING_LITERAL
#line 525 "src/pparser.yy"
                                                                     {
                                                                    cout << FMT_FG_YELLOW
                                                                            << "PARSER name_value: | FILE_ATTRIB=\""
                                                                            << yystack_[2].value.as < std::string > () << "\" EQUAL_SIGN STRING_LITERAL=\""
                                                                            << yystack_[0].value.as < std::string > () << "\""
                                                                         << FMT_RESET << endl;

                                                                     std::pair<std::string, std::string>  pair(yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ());
                                                                    yylhs.value.as < std::pair< std::string, std::string >  > () = pair;
                                                               }
#line 1240 "build/pparser.tab.cc"
    break;


#line 1244 "build/pparser.tab.cc"

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









  const signed char parser::yypact_ninf_ = -69;

  const signed char parser::yytable_ninf_ = -1;

  const signed char
  parser::yypact_[] =
  {
      -6,   -22,    11,    -6,   -69,     6,   -69,   -68,   -67,   -67,
     -67,   -67,   -67,   -69,     8,    -8,    19,    21,   -13,    22,
     -69,   -69,   -69,   -69,   -69,   -66,   -63,   -62,   -67,   -69,
     -67,   -67,   -67,   -67,   -69,   -69,   -42,   -41,   -69,   -69,
     -39,   -69,   -18,   -38,   -37,   -48,   -69,   -34,   -33,   -31,
     -69,   -69,   -69,    30,   -16,   -69,    25,   -69,   -69,   -69,
     -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     2,     3,     0,     6,     0,     0,     0,
       0,     0,     0,    27,     0,     0,     0,     0,     0,     0,
       1,     4,     5,     7,    26,     0,     0,     0,    28,    33,
      29,    30,    31,    32,    11,    12,     0,     0,     8,     9,
       0,    10,     0,     0,     0,     0,    13,     0,     0,     0,
      34,    19,    20,     0,     0,    23,     0,    17,    18,    15,
      16,    14,    36,    35,    37,    22,    21,    24,    25
  };

  const signed char
  parser::yypgoto_[] =
  {
     -69,   -69,   -69,    48,   -69,    47,   -69,   -69,   -69,   -69,
     -69,   -69,   -69,   -32,   -69,    20,    -5
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,     2,     3,     4,     5,     6,    14,    61,    15,    16,
      17,    54,    55,    18,    19,    28,    29
  };

  const signed char
  parser::yytable_[] =
  {
      40,     7,    66,    41,    42,     7,    22,     7,    35,     1,
      56,    20,     8,     9,    10,    24,    11,    12,    25,    26,
      27,     1,    67,    50,    34,    50,    50,    50,    50,    30,
      31,    32,    33,    59,    60,    38,    47,    39,    46,    48,
      49,    51,    52,    53,    65,    57,    58,    62,    63,    68,
      64,    21,    23,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    13,     0,     0,    43,    13,    44,    13,     0,
      36,     0,    37,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    45
  };

  const signed char
  parser::yycheck_[] =
  {
      13,    23,    18,    16,    17,    23,     0,    23,    16,    15,
      42,     0,    34,    35,    36,    83,    38,    39,    85,    86,
      87,    15,    54,    28,    16,    30,    31,    32,    33,     9,
      10,    11,    12,    81,    82,    16,   102,    16,    16,   102,
     102,    83,    83,    82,    14,    83,    83,    81,    81,    24,
      81,     3,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    84,    -1,    -1,    78,    84,    80,    84,    -1,
      78,    -1,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   102
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,    15,   113,   114,   115,   116,   117,    23,    34,    35,
      36,    38,    39,    84,   118,   120,   121,   122,   125,   126,
       0,   115,     0,   117,    83,    85,    86,    87,   127,   128,
     127,   127,   127,   127,    16,    16,    78,    80,    16,    16,
      13,    16,    17,    78,    80,   102,    16,   102,   102,   102,
     128,    83,    83,    82,   123,   124,   125,    83,    83,    81,
      82,   119,    81,    81,    81,    14,    18,   125,    24
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,   112,   113,   114,   114,   115,   116,   116,   117,   117,
     117,   117,   117,   117,   118,   118,   119,   120,   120,   120,
     120,   121,   122,   123,   123,   124,   125,   125,   126,   126,
     126,   126,   126,   127,   127,   128,   128,   128
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     1,     2,     2,     1,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     3,     3,     3,
       3,     4,     4,     1,     2,     2,     2,     1,     2,     2,
       2,     2,     2,     1,     2,     3,     3,     3
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of input\"", "error", "\"invalid token\"", "MATCH", "UNDEFINED",
  "WHITESPACE", "CARROT", "OPEN_PAREN", "CLOSE_PAREN", "DASH", "PLUS_SIGN",
  "BACKSLASH", "ARRAY", "OPEN_BRACKET", "CLOSE_BRACKET", "OPEN_BRACE",
  "CLOSE_BRACE", "LPAREN", "RPAREN", "SKIP_TOKEN", "CONST_SYMBOL",
  "ANYTHING", "VALID_CHAR", "DOLLAR_SIGN", "COMMA", "VBAR", "COLON",
  "PERCENT_SIGN", "HASH_MARK", "IF", "WHILE", "BREAK", "END_OF_FILES",
  "CAPTURE", "CONFIG_LOAD", "INCLUDE", "REQUIRE", "REQUIRE_ONCE", "INSERT",
  "ASSIGN", "ISSET", "SECTION", "LDELIM", "RDELIM", "VERSION", "CYCLE",
  "COUNTER", "CAPITALIZE", "CAT", "COUNT_CHARACTERS", "COUNT_SENTENCES",
  "COUNT_PARAGRAPHS", "COUNT_WORDS", "DATE_FORMAT", "DEFAULT", "ESCAPE",
  "INDENT", "LOWER", "UPPER", "STRIP", "NL2BR", "REGEX_REPLACE", "REPLACE",
  "SPACIFY", "STRING_FORMAT", "STRIP_TAGS", "TRUNCATE", "WORDWRAP",
  "REGX_REPLACE", "SEMI_COLON", "DOUBLE_QUOTE", "SINGLE_QUOTE",
  "BACK_SLASH", "AT", "AMPERSAND", "AND", "OR", "NOT", "DOT", "PERIOD",
  "INDIRECT_MEMBER", "STRING_LITERAL", "NUMERIC_LITERAL", "IDENTIFIER",
  "CONST_ID", "VAR_ATTRIB", "VALUE_ATTRIB", "FILE_ATTRIB", "FROM_ATTRIB",
  "KEY_ATTRIB", "NAME_ATTRIB", "ITEM_ATTRIB", "FILE_NAME",
  "UNESCAPED_TEXT", "COMMENT", "QUESTION_MARK", "NUMBER", "IFX", "ELSE",
  "ELSEIF", "GREATER_THAN_EQUAL", "LESS_THAN_EQUAL", "EQUAL_SIGN",
  "NOT_EQUAL", "LESS_THAN", "GREATER_THAN", "PLUS", "MINUS", "ASTERISK",
  "SLASH", "PERCENT", "UMINUS", "$accept", "complier", "files", "file",
  "blocks", "block", "assign_stmt", "number", "qualafied_id", "sub_proc",
  "array", "params", "param", "symbol", "built_in", "attributes", "attrib", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   112,   112,   124,   125,   132,   144,   147,   156,   159,
     162,   165,   168,   171,   181,   189,   197,   315,   320,   321,
     322,   329,   341,   354,   357,   368,   377,   381,   460,   465,
     470,   476,   482,   494,   497,   509,   517,   525
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
#line 1606 "build/pparser.tab.cc"

#line 537 "src/pparser.yy"



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
    // return the next token
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

     // return the next token
    parser::symbol_type yylex()
    {
        return lex();
    }

    // report an error to the user
    auto parser::error(const std::string& msg) -> void
    {
        std::cerr << msg << '\n';
    }
}
