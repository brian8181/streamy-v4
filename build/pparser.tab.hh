// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file build/pparser.tab.hh
 ** Define the yy::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_YY_BUILD_PPARSER_TAB_HH_INCLUDED
# define YY_YY_BUILD_PPARSER_TAB_HH_INCLUDED


# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif



#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

namespace yy {
#line 182 "build/pparser.tab.hh"




  /// A Bison parser.
  class parser
  {
  public:
#ifdef YYSTYPE
# ifdef __GNUC__
#  pragma GCC message "bison: do not #define YYSTYPE in C++, use %define api.value.type"
# endif
    typedef YYSTYPE value_type;
#else
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class value_type
  {
  public:
    /// Type of *this.
    typedef value_type self_type;

    /// Empty construction.
    value_type () YY_NOEXCEPT
      : yyraw_ ()
    {}

    /// Construct and fill.
    template <typename T>
    value_type (YY_RVREF (T) t)
    {
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    value_type (const self_type&) = delete;
    /// Non copyable.
    self_type& operator= (const self_type&) = delete;
#endif

    /// Destruction, allowed only if empty.
    ~value_type () YY_NOEXCEPT
    {}

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
    }

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    value_type (const self_type&);
    /// Non copyable.
    self_type& operator= (const self_type&);
#endif

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yyraw_;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yyraw_;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // attrib
      char dummy1[sizeof (std::pair< std::string, std::string > )];

      // CAPTURE
      // CONFIG_LOAD
      // INCLUDE
      // REQUIRE
      // REQUIRE_ONCE
      // INSERT
      // ASSIGN
      // ISSET
      // SECTION
      // LDELIM
      // RDELIM
      // VERSION
      // CYCLE
      // COUNTER
      // CAPITALIZE
      // CAT
      // COUNT_CHARACTERS
      // COUNT_SENTENCES
      // COUNT_PARAGRAPHS
      // COUNT_WORDS
      // DATE_FORMAT
      // DEFAULT
      // ESCAPE
      // INDENT
      // LOWER
      // UPPER
      // STRIP
      // NL2BR
      // REGEX_REPLACE
      // REPLACE
      // SPACIFY
      // STRING_FORMAT
      // STRIP_TAGS
      // TRUNCATE
      // WORDWRAP
      // INDIRECT_MEMBER
      // STRING_LITERAL
      // NUMERIC_LITERAL
      // IDENTIFIER
      // CONST_ID
      // VAR_ATTRIB
      // VALUE_ATTRIB
      // FILE_ATTRIB
      // FROM_ATTRIB
      // KEY_ATTRIB
      // NAME_ATTRIB
      // ITEM_ATTRIB
      // FILE_NAME
      // UNESCAPED_TEXT
      // assign_stmt
      // qualafied_id
      // sub_proc
      // array
      // symbol
      // built_in
      // attributes
      char dummy2[sizeof (std::string)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me_;
      /// A buffer large enough to store any of the semantic values.
      char yyraw_[size];
    };
  };

#endif
    /// Backward compatibility (Bison 3.8).
    typedef value_type semantic_type;


    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const std::string& m)
        : std::runtime_error (m)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        YYEMPTY = -2,
    END = 0,                       // "end of input"
    YYerror = 256,                 // error
    YYUNDEF = 257,                 // "invalid token"
    MATCH = 258,                   // MATCH
    UNDEFINED = 259,               // UNDEFINED
    WHITESPACE = 260,              // WHITESPACE
    ANYTHING = 261,                // ANYTHING
    VALID_CHAR = 262,              // VALID_CHAR
    SKIP_TOKEN = 263,              // SKIP_TOKEN
    CONST_SYMBOL = 264,            // CONST_SYMBOL
    CARROT = 265,                  // CARROT
    OPEN_PAREN = 266,              // OPEN_PAREN
    CLOSE_PAREN = 267,             // CLOSE_PAREN
    DASH = 268,                    // DASH
    PLUS_SIGN = 269,               // PLUS_SIGN
    BACKSLASH = 270,               // BACKSLASH
    ARRAY = 271,                   // ARRAY
    OPEN_BRACKET = 272,            // OPEN_BRACKET
    CLOSE_BRACKET = 273,           // CLOSE_BRACKET
    OPEN_BRACE = 274,              // OPEN_BRACE
    CLOSE_BRACE = 275,             // CLOSE_BRACE
    LPAREN = 276,                  // LPAREN
    RPAREN = 277,                  // RPAREN
    QUESTION_MARK = 278,           // QUESTION_MARK
    DOLLAR_SIGN = 279,             // DOLLAR_SIGN
    COMMA = 280,                   // COMMA
    VBAR = 281,                    // VBAR
    COLON = 282,                   // COLON
    HASH_MARK = 283,               // HASH_MARK
    SEMI_COLON = 284,              // SEMI_COLON
    DOUBLE_QUOTE = 285,            // DOUBLE_QUOTE
    SINGLE_QUOTE = 286,            // SINGLE_QUOTE
    BACK_SLASH = 287,              // BACK_SLASH
    AT = 288,                      // AT
    AMPERSAND = 289,               // AMPERSAND
    AND = 290,                     // AND
    OR = 291,                      // OR
    NOT = 292,                     // NOT
    DOT = 293,                     // DOT
    END_OF_FILES = 294,            // END_OF_FILES
    CAPTURE = 295,                 // CAPTURE
    CONFIG_LOAD = 296,             // CONFIG_LOAD
    INCLUDE = 297,                 // INCLUDE
    REQUIRE = 298,                 // REQUIRE
    REQUIRE_ONCE = 299,            // REQUIRE_ONCE
    INSERT = 300,                  // INSERT
    ASSIGN = 301,                  // ASSIGN
    ISSET = 302,                   // ISSET
    SECTION = 303,                 // SECTION
    LDELIM = 304,                  // LDELIM
    RDELIM = 305,                  // RDELIM
    VERSION = 306,                 // VERSION
    CYCLE = 307,                   // CYCLE
    COUNTER = 308,                 // COUNTER
    CAPITALIZE = 309,              // CAPITALIZE
    CAT = 310,                     // CAT
    COUNT_CHARACTERS = 311,        // COUNT_CHARACTERS
    COUNT_SENTENCES = 312,         // COUNT_SENTENCES
    COUNT_PARAGRAPHS = 313,        // COUNT_PARAGRAPHS
    COUNT_WORDS = 314,             // COUNT_WORDS
    DATE_FORMAT = 315,             // DATE_FORMAT
    DEFAULT = 316,                 // DEFAULT
    ESCAPE = 317,                  // ESCAPE
    INDENT = 318,                  // INDENT
    LOWER = 319,                   // LOWER
    UPPER = 320,                   // UPPER
    STRIP = 321,                   // STRIP
    NL2BR = 322,                   // NL2BR
    REGEX_REPLACE = 323,           // REGEX_REPLACE
    REPLACE = 324,                 // REPLACE
    SPACIFY = 325,                 // SPACIFY
    STRING_FORMAT = 326,           // STRING_FORMAT
    STRIP_TAGS = 327,              // STRIP_TAGS
    TRUNCATE = 328,                // TRUNCATE
    WORDWRAP = 329,                // WORDWRAP
    INDIRECT_MEMBER = 330,         // INDIRECT_MEMBER
    STRING_LITERAL = 331,          // STRING_LITERAL
    NUMERIC_LITERAL = 332,         // NUMERIC_LITERAL
    IDENTIFIER = 333,              // IDENTIFIER
    CONST_ID = 334,                // CONST_ID
    VAR_ATTRIB = 335,              // VAR_ATTRIB
    VALUE_ATTRIB = 336,            // VALUE_ATTRIB
    FILE_ATTRIB = 337,             // FILE_ATTRIB
    FROM_ATTRIB = 338,             // FROM_ATTRIB
    KEY_ATTRIB = 339,              // KEY_ATTRIB
    NAME_ATTRIB = 340,             // NAME_ATTRIB
    ITEM_ATTRIB = 341,             // ITEM_ATTRIB
    FILE_NAME = 342,               // FILE_NAME
    UNESCAPED_TEXT = 343,          // UNESCAPED_TEXT
    IFX = 344,                     // IFX
    ELSE = 345,                    // ELSE
    ELSEIF = 346,                  // ELSEIF
    IF = 347,                      // IF
    WHILE = 348,                   // WHILE
    BREAK = 349,                   // BREAK
    GREATER_THAN_EQUAL = 350,      // GREATER_THAN_EQUAL
    LESS_THAN_EQUAL = 351,         // LESS_THAN_EQUAL
    EQUAL_SIGN = 352,              // EQUAL_SIGN
    NOT_EQUAL = 353,               // NOT_EQUAL
    LESS_THAN = 354,               // LESS_THAN
    GREATER_THAN = 355,            // GREATER_THAN
    PLUS = 356,                    // PLUS
    MINUS = 357,                   // MINUS
    ASTERISK = 358,                // ASTERISK
    SLASH = 359,                   // SLASH
    PERCENT_SIGN = 360,            // PERCENT_SIGN
    UMINUS = 361                   // UMINUS
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::token_kind_type token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 107, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // "end of input"
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_MATCH = 3,                             // MATCH
        S_UNDEFINED = 4,                         // UNDEFINED
        S_WHITESPACE = 5,                        // WHITESPACE
        S_ANYTHING = 6,                          // ANYTHING
        S_VALID_CHAR = 7,                        // VALID_CHAR
        S_SKIP_TOKEN = 8,                        // SKIP_TOKEN
        S_CONST_SYMBOL = 9,                      // CONST_SYMBOL
        S_CARROT = 10,                           // CARROT
        S_OPEN_PAREN = 11,                       // OPEN_PAREN
        S_CLOSE_PAREN = 12,                      // CLOSE_PAREN
        S_DASH = 13,                             // DASH
        S_PLUS_SIGN = 14,                        // PLUS_SIGN
        S_BACKSLASH = 15,                        // BACKSLASH
        S_ARRAY = 16,                            // ARRAY
        S_OPEN_BRACKET = 17,                     // OPEN_BRACKET
        S_CLOSE_BRACKET = 18,                    // CLOSE_BRACKET
        S_OPEN_BRACE = 19,                       // OPEN_BRACE
        S_CLOSE_BRACE = 20,                      // CLOSE_BRACE
        S_LPAREN = 21,                           // LPAREN
        S_RPAREN = 22,                           // RPAREN
        S_QUESTION_MARK = 23,                    // QUESTION_MARK
        S_DOLLAR_SIGN = 24,                      // DOLLAR_SIGN
        S_COMMA = 25,                            // COMMA
        S_VBAR = 26,                             // VBAR
        S_COLON = 27,                            // COLON
        S_HASH_MARK = 28,                        // HASH_MARK
        S_SEMI_COLON = 29,                       // SEMI_COLON
        S_DOUBLE_QUOTE = 30,                     // DOUBLE_QUOTE
        S_SINGLE_QUOTE = 31,                     // SINGLE_QUOTE
        S_BACK_SLASH = 32,                       // BACK_SLASH
        S_AT = 33,                               // AT
        S_AMPERSAND = 34,                        // AMPERSAND
        S_AND = 35,                              // AND
        S_OR = 36,                               // OR
        S_NOT = 37,                              // NOT
        S_DOT = 38,                              // DOT
        S_END_OF_FILES = 39,                     // END_OF_FILES
        S_CAPTURE = 40,                          // CAPTURE
        S_CONFIG_LOAD = 41,                      // CONFIG_LOAD
        S_INCLUDE = 42,                          // INCLUDE
        S_REQUIRE = 43,                          // REQUIRE
        S_REQUIRE_ONCE = 44,                     // REQUIRE_ONCE
        S_INSERT = 45,                           // INSERT
        S_ASSIGN = 46,                           // ASSIGN
        S_ISSET = 47,                            // ISSET
        S_SECTION = 48,                          // SECTION
        S_LDELIM = 49,                           // LDELIM
        S_RDELIM = 50,                           // RDELIM
        S_VERSION = 51,                          // VERSION
        S_CYCLE = 52,                            // CYCLE
        S_COUNTER = 53,                          // COUNTER
        S_CAPITALIZE = 54,                       // CAPITALIZE
        S_CAT = 55,                              // CAT
        S_COUNT_CHARACTERS = 56,                 // COUNT_CHARACTERS
        S_COUNT_SENTENCES = 57,                  // COUNT_SENTENCES
        S_COUNT_PARAGRAPHS = 58,                 // COUNT_PARAGRAPHS
        S_COUNT_WORDS = 59,                      // COUNT_WORDS
        S_DATE_FORMAT = 60,                      // DATE_FORMAT
        S_DEFAULT = 61,                          // DEFAULT
        S_ESCAPE = 62,                           // ESCAPE
        S_INDENT = 63,                           // INDENT
        S_LOWER = 64,                            // LOWER
        S_UPPER = 65,                            // UPPER
        S_STRIP = 66,                            // STRIP
        S_NL2BR = 67,                            // NL2BR
        S_REGEX_REPLACE = 68,                    // REGEX_REPLACE
        S_REPLACE = 69,                          // REPLACE
        S_SPACIFY = 70,                          // SPACIFY
        S_STRING_FORMAT = 71,                    // STRING_FORMAT
        S_STRIP_TAGS = 72,                       // STRIP_TAGS
        S_TRUNCATE = 73,                         // TRUNCATE
        S_WORDWRAP = 74,                         // WORDWRAP
        S_INDIRECT_MEMBER = 75,                  // INDIRECT_MEMBER
        S_STRING_LITERAL = 76,                   // STRING_LITERAL
        S_NUMERIC_LITERAL = 77,                  // NUMERIC_LITERAL
        S_IDENTIFIER = 78,                       // IDENTIFIER
        S_CONST_ID = 79,                         // CONST_ID
        S_VAR_ATTRIB = 80,                       // VAR_ATTRIB
        S_VALUE_ATTRIB = 81,                     // VALUE_ATTRIB
        S_FILE_ATTRIB = 82,                      // FILE_ATTRIB
        S_FROM_ATTRIB = 83,                      // FROM_ATTRIB
        S_KEY_ATTRIB = 84,                       // KEY_ATTRIB
        S_NAME_ATTRIB = 85,                      // NAME_ATTRIB
        S_ITEM_ATTRIB = 86,                      // ITEM_ATTRIB
        S_FILE_NAME = 87,                        // FILE_NAME
        S_UNESCAPED_TEXT = 88,                   // UNESCAPED_TEXT
        S_IFX = 89,                              // IFX
        S_ELSE = 90,                             // ELSE
        S_ELSEIF = 91,                           // ELSEIF
        S_IF = 92,                               // IF
        S_WHILE = 93,                            // WHILE
        S_BREAK = 94,                            // BREAK
        S_GREATER_THAN_EQUAL = 95,               // GREATER_THAN_EQUAL
        S_LESS_THAN_EQUAL = 96,                  // LESS_THAN_EQUAL
        S_EQUAL_SIGN = 97,                       // EQUAL_SIGN
        S_NOT_EQUAL = 98,                        // NOT_EQUAL
        S_LESS_THAN = 99,                        // LESS_THAN
        S_GREATER_THAN = 100,                    // GREATER_THAN
        S_PLUS = 101,                            // PLUS
        S_MINUS = 102,                           // MINUS
        S_ASTERISK = 103,                        // ASTERISK
        S_SLASH = 104,                           // SLASH
        S_PERCENT_SIGN = 105,                    // PERCENT_SIGN
        S_UMINUS = 106,                          // UMINUS
        S_YYACCEPT = 107,                        // $accept
        S_complier = 108,                        // complier
        S_files = 109,                           // files
        S_file = 110,                            // file
        S_blocks = 111,                          // blocks
        S_block = 112,                           // block
        S_assign_stmt = 113,                     // assign_stmt
        S_qualafied_id = 114,                    // qualafied_id
        S_sub_proc = 115,                        // sub_proc
        S_array = 116,                           // array
        S_params = 117,                          // params
        S_param = 118,                           // param
        S_symbol = 119,                          // symbol
        S_built_in = 120,                        // built_in
        S_attributes = 121,                      // attributes
        S_attrib = 122                           // attrib
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol () YY_NOEXCEPT
        : value ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value ()
      {
        switch (this->kind ())
    {
      case symbol_kind::S_attrib: // attrib
        value.move< std::pair< std::string, std::string >  > (std::move (that.value));
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
      case symbol_kind::S_qualafied_id: // qualafied_id
      case symbol_kind::S_sub_proc: // sub_proc
      case symbol_kind::S_array: // array
      case symbol_kind::S_symbol: // symbol
      case symbol_kind::S_built_in: // built_in
      case symbol_kind::S_attributes: // attributes
        value.move< std::string > (std::move (that.value));
        break;

      default:
        break;
    }

      }
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructors for typed symbols.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t)
        : Base (t)
      {}
#else
      basic_symbol (typename Base::kind_type t)
        : Base (t)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::pair< std::string, std::string > && v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::pair< std::string, std::string > & v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v)
        : Base (t)
        , value (v)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }



      /// Destroy contents, and record that is empty.
      void clear () YY_NOEXCEPT
      {
        // User destructor.
        symbol_kind_type yykind = this->kind ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yykind)
        {
       default:
          break;
        }

        // Value type destructor.
switch (yykind)
    {
      case symbol_kind::S_attrib: // attrib
        value.template destroy< std::pair< std::string, std::string >  > ();
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
      case symbol_kind::S_qualafied_id: // qualafied_id
      case symbol_kind::S_sub_proc: // sub_proc
      case symbol_kind::S_array: // array
      case symbol_kind::S_symbol: // symbol
      case symbol_kind::S_built_in: // built_in
      case symbol_kind::S_attributes: // attributes
        value.template destroy< std::string > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

#if YYDEBUG || 0
      /// The user-facing name of this symbol.
      const char *name () const YY_NOEXCEPT
      {
        return parser::symbol_name (this->kind ());
      }
#endif // #if YYDEBUG || 0


      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      value_type value;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Default constructor.
      by_kind () YY_NOEXCEPT;

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that) YY_NOEXCEPT;
#endif

      /// Copy constructor.
      by_kind (const by_kind& that) YY_NOEXCEPT;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t) YY_NOEXCEPT;



      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {
      /// Superclass.
      typedef basic_symbol<by_kind> super_type;

      /// Empty symbol.
      symbol_type () YY_NOEXCEPT {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok)
        : super_type (token_kind_type (tok))
#else
      symbol_type (int tok)
        : super_type (token_kind_type (tok))
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v)
        : super_type (token_kind_type (tok), std::move (v))
#else
      symbol_type (int tok, const std::string& v)
        : super_type (token_kind_type (tok), v)
#endif
      {}
    };

    /// Build a parser object.
    parser ();
    virtual ~parser ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    parser (const parser&) = delete;
    /// Non copyable.
    parser& operator= (const parser&) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param msg    a description of the syntax error.
    virtual void error (const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

#if YYDEBUG || 0
    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static const char *symbol_name (symbol_kind_type yysymbol);
#endif // #if YYDEBUG || 0


    // Implementation of make_symbol for each token kind.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_END ()
      {
        return symbol_type (token::END);
      }
#else
      static
      symbol_type
      make_END ()
      {
        return symbol_type (token::END);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYerror ()
      {
        return symbol_type (token::YYerror);
      }
#else
      static
      symbol_type
      make_YYerror ()
      {
        return symbol_type (token::YYerror);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYUNDEF ()
      {
        return symbol_type (token::YYUNDEF);
      }
#else
      static
      symbol_type
      make_YYUNDEF ()
      {
        return symbol_type (token::YYUNDEF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MATCH ()
      {
        return symbol_type (token::MATCH);
      }
#else
      static
      symbol_type
      make_MATCH ()
      {
        return symbol_type (token::MATCH);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UNDEFINED ()
      {
        return symbol_type (token::UNDEFINED);
      }
#else
      static
      symbol_type
      make_UNDEFINED ()
      {
        return symbol_type (token::UNDEFINED);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_WHITESPACE ()
      {
        return symbol_type (token::WHITESPACE);
      }
#else
      static
      symbol_type
      make_WHITESPACE ()
      {
        return symbol_type (token::WHITESPACE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ANYTHING ()
      {
        return symbol_type (token::ANYTHING);
      }
#else
      static
      symbol_type
      make_ANYTHING ()
      {
        return symbol_type (token::ANYTHING);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VALID_CHAR ()
      {
        return symbol_type (token::VALID_CHAR);
      }
#else
      static
      symbol_type
      make_VALID_CHAR ()
      {
        return symbol_type (token::VALID_CHAR);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SKIP_TOKEN ()
      {
        return symbol_type (token::SKIP_TOKEN);
      }
#else
      static
      symbol_type
      make_SKIP_TOKEN ()
      {
        return symbol_type (token::SKIP_TOKEN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CONST_SYMBOL ()
      {
        return symbol_type (token::CONST_SYMBOL);
      }
#else
      static
      symbol_type
      make_CONST_SYMBOL ()
      {
        return symbol_type (token::CONST_SYMBOL);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CARROT ()
      {
        return symbol_type (token::CARROT);
      }
#else
      static
      symbol_type
      make_CARROT ()
      {
        return symbol_type (token::CARROT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OPEN_PAREN ()
      {
        return symbol_type (token::OPEN_PAREN);
      }
#else
      static
      symbol_type
      make_OPEN_PAREN ()
      {
        return symbol_type (token::OPEN_PAREN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CLOSE_PAREN ()
      {
        return symbol_type (token::CLOSE_PAREN);
      }
#else
      static
      symbol_type
      make_CLOSE_PAREN ()
      {
        return symbol_type (token::CLOSE_PAREN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DASH ()
      {
        return symbol_type (token::DASH);
      }
#else
      static
      symbol_type
      make_DASH ()
      {
        return symbol_type (token::DASH);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PLUS_SIGN ()
      {
        return symbol_type (token::PLUS_SIGN);
      }
#else
      static
      symbol_type
      make_PLUS_SIGN ()
      {
        return symbol_type (token::PLUS_SIGN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BACKSLASH ()
      {
        return symbol_type (token::BACKSLASH);
      }
#else
      static
      symbol_type
      make_BACKSLASH ()
      {
        return symbol_type (token::BACKSLASH);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ARRAY ()
      {
        return symbol_type (token::ARRAY);
      }
#else
      static
      symbol_type
      make_ARRAY ()
      {
        return symbol_type (token::ARRAY);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OPEN_BRACKET ()
      {
        return symbol_type (token::OPEN_BRACKET);
      }
#else
      static
      symbol_type
      make_OPEN_BRACKET ()
      {
        return symbol_type (token::OPEN_BRACKET);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CLOSE_BRACKET ()
      {
        return symbol_type (token::CLOSE_BRACKET);
      }
#else
      static
      symbol_type
      make_CLOSE_BRACKET ()
      {
        return symbol_type (token::CLOSE_BRACKET);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OPEN_BRACE ()
      {
        return symbol_type (token::OPEN_BRACE);
      }
#else
      static
      symbol_type
      make_OPEN_BRACE ()
      {
        return symbol_type (token::OPEN_BRACE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CLOSE_BRACE ()
      {
        return symbol_type (token::CLOSE_BRACE);
      }
#else
      static
      symbol_type
      make_CLOSE_BRACE ()
      {
        return symbol_type (token::CLOSE_BRACE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LPAREN ()
      {
        return symbol_type (token::LPAREN);
      }
#else
      static
      symbol_type
      make_LPAREN ()
      {
        return symbol_type (token::LPAREN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RPAREN ()
      {
        return symbol_type (token::RPAREN);
      }
#else
      static
      symbol_type
      make_RPAREN ()
      {
        return symbol_type (token::RPAREN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_QUESTION_MARK ()
      {
        return symbol_type (token::QUESTION_MARK);
      }
#else
      static
      symbol_type
      make_QUESTION_MARK ()
      {
        return symbol_type (token::QUESTION_MARK);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOLLAR_SIGN ()
      {
        return symbol_type (token::DOLLAR_SIGN);
      }
#else
      static
      symbol_type
      make_DOLLAR_SIGN ()
      {
        return symbol_type (token::DOLLAR_SIGN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMMA ()
      {
        return symbol_type (token::COMMA);
      }
#else
      static
      symbol_type
      make_COMMA ()
      {
        return symbol_type (token::COMMA);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VBAR ()
      {
        return symbol_type (token::VBAR);
      }
#else
      static
      symbol_type
      make_VBAR ()
      {
        return symbol_type (token::VBAR);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COLON ()
      {
        return symbol_type (token::COLON);
      }
#else
      static
      symbol_type
      make_COLON ()
      {
        return symbol_type (token::COLON);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_HASH_MARK ()
      {
        return symbol_type (token::HASH_MARK);
      }
#else
      static
      symbol_type
      make_HASH_MARK ()
      {
        return symbol_type (token::HASH_MARK);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SEMI_COLON ()
      {
        return symbol_type (token::SEMI_COLON);
      }
#else
      static
      symbol_type
      make_SEMI_COLON ()
      {
        return symbol_type (token::SEMI_COLON);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOUBLE_QUOTE ()
      {
        return symbol_type (token::DOUBLE_QUOTE);
      }
#else
      static
      symbol_type
      make_DOUBLE_QUOTE ()
      {
        return symbol_type (token::DOUBLE_QUOTE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SINGLE_QUOTE ()
      {
        return symbol_type (token::SINGLE_QUOTE);
      }
#else
      static
      symbol_type
      make_SINGLE_QUOTE ()
      {
        return symbol_type (token::SINGLE_QUOTE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BACK_SLASH ()
      {
        return symbol_type (token::BACK_SLASH);
      }
#else
      static
      symbol_type
      make_BACK_SLASH ()
      {
        return symbol_type (token::BACK_SLASH);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AT ()
      {
        return symbol_type (token::AT);
      }
#else
      static
      symbol_type
      make_AT ()
      {
        return symbol_type (token::AT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AMPERSAND ()
      {
        return symbol_type (token::AMPERSAND);
      }
#else
      static
      symbol_type
      make_AMPERSAND ()
      {
        return symbol_type (token::AMPERSAND);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AND ()
      {
        return symbol_type (token::AND);
      }
#else
      static
      symbol_type
      make_AND ()
      {
        return symbol_type (token::AND);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OR ()
      {
        return symbol_type (token::OR);
      }
#else
      static
      symbol_type
      make_OR ()
      {
        return symbol_type (token::OR);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NOT ()
      {
        return symbol_type (token::NOT);
      }
#else
      static
      symbol_type
      make_NOT ()
      {
        return symbol_type (token::NOT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOT ()
      {
        return symbol_type (token::DOT);
      }
#else
      static
      symbol_type
      make_DOT ()
      {
        return symbol_type (token::DOT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_END_OF_FILES ()
      {
        return symbol_type (token::END_OF_FILES);
      }
#else
      static
      symbol_type
      make_END_OF_FILES ()
      {
        return symbol_type (token::END_OF_FILES);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CAPTURE (std::string v)
      {
        return symbol_type (token::CAPTURE, std::move (v));
      }
#else
      static
      symbol_type
      make_CAPTURE (const std::string& v)
      {
        return symbol_type (token::CAPTURE, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CONFIG_LOAD (std::string v)
      {
        return symbol_type (token::CONFIG_LOAD, std::move (v));
      }
#else
      static
      symbol_type
      make_CONFIG_LOAD (const std::string& v)
      {
        return symbol_type (token::CONFIG_LOAD, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INCLUDE (std::string v)
      {
        return symbol_type (token::INCLUDE, std::move (v));
      }
#else
      static
      symbol_type
      make_INCLUDE (const std::string& v)
      {
        return symbol_type (token::INCLUDE, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_REQUIRE (std::string v)
      {
        return symbol_type (token::REQUIRE, std::move (v));
      }
#else
      static
      symbol_type
      make_REQUIRE (const std::string& v)
      {
        return symbol_type (token::REQUIRE, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_REQUIRE_ONCE (std::string v)
      {
        return symbol_type (token::REQUIRE_ONCE, std::move (v));
      }
#else
      static
      symbol_type
      make_REQUIRE_ONCE (const std::string& v)
      {
        return symbol_type (token::REQUIRE_ONCE, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INSERT (std::string v)
      {
        return symbol_type (token::INSERT, std::move (v));
      }
#else
      static
      symbol_type
      make_INSERT (const std::string& v)
      {
        return symbol_type (token::INSERT, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASSIGN (std::string v)
      {
        return symbol_type (token::ASSIGN, std::move (v));
      }
#else
      static
      symbol_type
      make_ASSIGN (const std::string& v)
      {
        return symbol_type (token::ASSIGN, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ISSET (std::string v)
      {
        return symbol_type (token::ISSET, std::move (v));
      }
#else
      static
      symbol_type
      make_ISSET (const std::string& v)
      {
        return symbol_type (token::ISSET, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SECTION (std::string v)
      {
        return symbol_type (token::SECTION, std::move (v));
      }
#else
      static
      symbol_type
      make_SECTION (const std::string& v)
      {
        return symbol_type (token::SECTION, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LDELIM (std::string v)
      {
        return symbol_type (token::LDELIM, std::move (v));
      }
#else
      static
      symbol_type
      make_LDELIM (const std::string& v)
      {
        return symbol_type (token::LDELIM, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RDELIM (std::string v)
      {
        return symbol_type (token::RDELIM, std::move (v));
      }
#else
      static
      symbol_type
      make_RDELIM (const std::string& v)
      {
        return symbol_type (token::RDELIM, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VERSION (std::string v)
      {
        return symbol_type (token::VERSION, std::move (v));
      }
#else
      static
      symbol_type
      make_VERSION (const std::string& v)
      {
        return symbol_type (token::VERSION, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CYCLE (std::string v)
      {
        return symbol_type (token::CYCLE, std::move (v));
      }
#else
      static
      symbol_type
      make_CYCLE (const std::string& v)
      {
        return symbol_type (token::CYCLE, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COUNTER (std::string v)
      {
        return symbol_type (token::COUNTER, std::move (v));
      }
#else
      static
      symbol_type
      make_COUNTER (const std::string& v)
      {
        return symbol_type (token::COUNTER, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CAPITALIZE (std::string v)
      {
        return symbol_type (token::CAPITALIZE, std::move (v));
      }
#else
      static
      symbol_type
      make_CAPITALIZE (const std::string& v)
      {
        return symbol_type (token::CAPITALIZE, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CAT (std::string v)
      {
        return symbol_type (token::CAT, std::move (v));
      }
#else
      static
      symbol_type
      make_CAT (const std::string& v)
      {
        return symbol_type (token::CAT, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COUNT_CHARACTERS (std::string v)
      {
        return symbol_type (token::COUNT_CHARACTERS, std::move (v));
      }
#else
      static
      symbol_type
      make_COUNT_CHARACTERS (const std::string& v)
      {
        return symbol_type (token::COUNT_CHARACTERS, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COUNT_SENTENCES (std::string v)
      {
        return symbol_type (token::COUNT_SENTENCES, std::move (v));
      }
#else
      static
      symbol_type
      make_COUNT_SENTENCES (const std::string& v)
      {
        return symbol_type (token::COUNT_SENTENCES, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COUNT_PARAGRAPHS (std::string v)
      {
        return symbol_type (token::COUNT_PARAGRAPHS, std::move (v));
      }
#else
      static
      symbol_type
      make_COUNT_PARAGRAPHS (const std::string& v)
      {
        return symbol_type (token::COUNT_PARAGRAPHS, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COUNT_WORDS (std::string v)
      {
        return symbol_type (token::COUNT_WORDS, std::move (v));
      }
#else
      static
      symbol_type
      make_COUNT_WORDS (const std::string& v)
      {
        return symbol_type (token::COUNT_WORDS, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DATE_FORMAT (std::string v)
      {
        return symbol_type (token::DATE_FORMAT, std::move (v));
      }
#else
      static
      symbol_type
      make_DATE_FORMAT (const std::string& v)
      {
        return symbol_type (token::DATE_FORMAT, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DEFAULT (std::string v)
      {
        return symbol_type (token::DEFAULT, std::move (v));
      }
#else
      static
      symbol_type
      make_DEFAULT (const std::string& v)
      {
        return symbol_type (token::DEFAULT, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ESCAPE (std::string v)
      {
        return symbol_type (token::ESCAPE, std::move (v));
      }
#else
      static
      symbol_type
      make_ESCAPE (const std::string& v)
      {
        return symbol_type (token::ESCAPE, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INDENT (std::string v)
      {
        return symbol_type (token::INDENT, std::move (v));
      }
#else
      static
      symbol_type
      make_INDENT (const std::string& v)
      {
        return symbol_type (token::INDENT, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LOWER (std::string v)
      {
        return symbol_type (token::LOWER, std::move (v));
      }
#else
      static
      symbol_type
      make_LOWER (const std::string& v)
      {
        return symbol_type (token::LOWER, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UPPER (std::string v)
      {
        return symbol_type (token::UPPER, std::move (v));
      }
#else
      static
      symbol_type
      make_UPPER (const std::string& v)
      {
        return symbol_type (token::UPPER, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRIP (std::string v)
      {
        return symbol_type (token::STRIP, std::move (v));
      }
#else
      static
      symbol_type
      make_STRIP (const std::string& v)
      {
        return symbol_type (token::STRIP, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NL2BR (std::string v)
      {
        return symbol_type (token::NL2BR, std::move (v));
      }
#else
      static
      symbol_type
      make_NL2BR (const std::string& v)
      {
        return symbol_type (token::NL2BR, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_REGEX_REPLACE (std::string v)
      {
        return symbol_type (token::REGEX_REPLACE, std::move (v));
      }
#else
      static
      symbol_type
      make_REGEX_REPLACE (const std::string& v)
      {
        return symbol_type (token::REGEX_REPLACE, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_REPLACE (std::string v)
      {
        return symbol_type (token::REPLACE, std::move (v));
      }
#else
      static
      symbol_type
      make_REPLACE (const std::string& v)
      {
        return symbol_type (token::REPLACE, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SPACIFY (std::string v)
      {
        return symbol_type (token::SPACIFY, std::move (v));
      }
#else
      static
      symbol_type
      make_SPACIFY (const std::string& v)
      {
        return symbol_type (token::SPACIFY, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRING_FORMAT (std::string v)
      {
        return symbol_type (token::STRING_FORMAT, std::move (v));
      }
#else
      static
      symbol_type
      make_STRING_FORMAT (const std::string& v)
      {
        return symbol_type (token::STRING_FORMAT, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRIP_TAGS (std::string v)
      {
        return symbol_type (token::STRIP_TAGS, std::move (v));
      }
#else
      static
      symbol_type
      make_STRIP_TAGS (const std::string& v)
      {
        return symbol_type (token::STRIP_TAGS, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TRUNCATE (std::string v)
      {
        return symbol_type (token::TRUNCATE, std::move (v));
      }
#else
      static
      symbol_type
      make_TRUNCATE (const std::string& v)
      {
        return symbol_type (token::TRUNCATE, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_WORDWRAP (std::string v)
      {
        return symbol_type (token::WORDWRAP, std::move (v));
      }
#else
      static
      symbol_type
      make_WORDWRAP (const std::string& v)
      {
        return symbol_type (token::WORDWRAP, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INDIRECT_MEMBER (std::string v)
      {
        return symbol_type (token::INDIRECT_MEMBER, std::move (v));
      }
#else
      static
      symbol_type
      make_INDIRECT_MEMBER (const std::string& v)
      {
        return symbol_type (token::INDIRECT_MEMBER, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRING_LITERAL (std::string v)
      {
        return symbol_type (token::STRING_LITERAL, std::move (v));
      }
#else
      static
      symbol_type
      make_STRING_LITERAL (const std::string& v)
      {
        return symbol_type (token::STRING_LITERAL, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NUMERIC_LITERAL (std::string v)
      {
        return symbol_type (token::NUMERIC_LITERAL, std::move (v));
      }
#else
      static
      symbol_type
      make_NUMERIC_LITERAL (const std::string& v)
      {
        return symbol_type (token::NUMERIC_LITERAL, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IDENTIFIER (std::string v)
      {
        return symbol_type (token::IDENTIFIER, std::move (v));
      }
#else
      static
      symbol_type
      make_IDENTIFIER (const std::string& v)
      {
        return symbol_type (token::IDENTIFIER, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CONST_ID (std::string v)
      {
        return symbol_type (token::CONST_ID, std::move (v));
      }
#else
      static
      symbol_type
      make_CONST_ID (const std::string& v)
      {
        return symbol_type (token::CONST_ID, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VAR_ATTRIB (std::string v)
      {
        return symbol_type (token::VAR_ATTRIB, std::move (v));
      }
#else
      static
      symbol_type
      make_VAR_ATTRIB (const std::string& v)
      {
        return symbol_type (token::VAR_ATTRIB, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VALUE_ATTRIB (std::string v)
      {
        return symbol_type (token::VALUE_ATTRIB, std::move (v));
      }
#else
      static
      symbol_type
      make_VALUE_ATTRIB (const std::string& v)
      {
        return symbol_type (token::VALUE_ATTRIB, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FILE_ATTRIB (std::string v)
      {
        return symbol_type (token::FILE_ATTRIB, std::move (v));
      }
#else
      static
      symbol_type
      make_FILE_ATTRIB (const std::string& v)
      {
        return symbol_type (token::FILE_ATTRIB, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FROM_ATTRIB (std::string v)
      {
        return symbol_type (token::FROM_ATTRIB, std::move (v));
      }
#else
      static
      symbol_type
      make_FROM_ATTRIB (const std::string& v)
      {
        return symbol_type (token::FROM_ATTRIB, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_KEY_ATTRIB (std::string v)
      {
        return symbol_type (token::KEY_ATTRIB, std::move (v));
      }
#else
      static
      symbol_type
      make_KEY_ATTRIB (const std::string& v)
      {
        return symbol_type (token::KEY_ATTRIB, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NAME_ATTRIB (std::string v)
      {
        return symbol_type (token::NAME_ATTRIB, std::move (v));
      }
#else
      static
      symbol_type
      make_NAME_ATTRIB (const std::string& v)
      {
        return symbol_type (token::NAME_ATTRIB, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ITEM_ATTRIB (std::string v)
      {
        return symbol_type (token::ITEM_ATTRIB, std::move (v));
      }
#else
      static
      symbol_type
      make_ITEM_ATTRIB (const std::string& v)
      {
        return symbol_type (token::ITEM_ATTRIB, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FILE_NAME (std::string v)
      {
        return symbol_type (token::FILE_NAME, std::move (v));
      }
#else
      static
      symbol_type
      make_FILE_NAME (const std::string& v)
      {
        return symbol_type (token::FILE_NAME, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UNESCAPED_TEXT (std::string v)
      {
        return symbol_type (token::UNESCAPED_TEXT, std::move (v));
      }
#else
      static
      symbol_type
      make_UNESCAPED_TEXT (const std::string& v)
      {
        return symbol_type (token::UNESCAPED_TEXT, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IFX ()
      {
        return symbol_type (token::IFX);
      }
#else
      static
      symbol_type
      make_IFX ()
      {
        return symbol_type (token::IFX);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ELSE ()
      {
        return symbol_type (token::ELSE);
      }
#else
      static
      symbol_type
      make_ELSE ()
      {
        return symbol_type (token::ELSE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ELSEIF ()
      {
        return symbol_type (token::ELSEIF);
      }
#else
      static
      symbol_type
      make_ELSEIF ()
      {
        return symbol_type (token::ELSEIF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IF ()
      {
        return symbol_type (token::IF);
      }
#else
      static
      symbol_type
      make_IF ()
      {
        return symbol_type (token::IF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_WHILE ()
      {
        return symbol_type (token::WHILE);
      }
#else
      static
      symbol_type
      make_WHILE ()
      {
        return symbol_type (token::WHILE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BREAK ()
      {
        return symbol_type (token::BREAK);
      }
#else
      static
      symbol_type
      make_BREAK ()
      {
        return symbol_type (token::BREAK);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GREATER_THAN_EQUAL ()
      {
        return symbol_type (token::GREATER_THAN_EQUAL);
      }
#else
      static
      symbol_type
      make_GREATER_THAN_EQUAL ()
      {
        return symbol_type (token::GREATER_THAN_EQUAL);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LESS_THAN_EQUAL ()
      {
        return symbol_type (token::LESS_THAN_EQUAL);
      }
#else
      static
      symbol_type
      make_LESS_THAN_EQUAL ()
      {
        return symbol_type (token::LESS_THAN_EQUAL);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EQUAL_SIGN ()
      {
        return symbol_type (token::EQUAL_SIGN);
      }
#else
      static
      symbol_type
      make_EQUAL_SIGN ()
      {
        return symbol_type (token::EQUAL_SIGN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NOT_EQUAL ()
      {
        return symbol_type (token::NOT_EQUAL);
      }
#else
      static
      symbol_type
      make_NOT_EQUAL ()
      {
        return symbol_type (token::NOT_EQUAL);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LESS_THAN ()
      {
        return symbol_type (token::LESS_THAN);
      }
#else
      static
      symbol_type
      make_LESS_THAN ()
      {
        return symbol_type (token::LESS_THAN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GREATER_THAN ()
      {
        return symbol_type (token::GREATER_THAN);
      }
#else
      static
      symbol_type
      make_GREATER_THAN ()
      {
        return symbol_type (token::GREATER_THAN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PLUS ()
      {
        return symbol_type (token::PLUS);
      }
#else
      static
      symbol_type
      make_PLUS ()
      {
        return symbol_type (token::PLUS);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MINUS ()
      {
        return symbol_type (token::MINUS);
      }
#else
      static
      symbol_type
      make_MINUS ()
      {
        return symbol_type (token::MINUS);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASTERISK ()
      {
        return symbol_type (token::ASTERISK);
      }
#else
      static
      symbol_type
      make_ASTERISK ()
      {
        return symbol_type (token::ASTERISK);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SLASH ()
      {
        return symbol_type (token::SLASH);
      }
#else
      static
      symbol_type
      make_SLASH ()
      {
        return symbol_type (token::SLASH);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PERCENT_SIGN ()
      {
        return symbol_type (token::PERCENT_SIGN);
      }
#else
      static
      symbol_type
      make_PERCENT_SIGN ()
      {
        return symbol_type (token::PERCENT_SIGN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UMINUS ()
      {
        return symbol_type (token::UMINUS);
      }
#else
      static
      symbol_type
      make_UMINUS ()
      {
        return symbol_type (token::UMINUS);
      }
#endif


  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    parser (const parser&);
    /// Non copyable.
    parser& operator= (const parser&);
#endif


    /// Stored state numbers (used for stacks).
    typedef signed char state_type;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT;

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT;

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_kind_type enum.
    static symbol_kind_type yytranslate_ (int t) YY_NOEXCEPT;

#if YYDEBUG || 0
    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#endif // #if YYDEBUG || 0


    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const signed char yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const signed char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const signed char yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const signed char yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const signed char yytable_[];

    static const signed char yycheck_[];

    // YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
    // state STATE-NUM.
    static const signed char yystos_[];

    // YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.
    static const signed char yyr1_[];

    // YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.
    static const signed char yyr2_[];


#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a symbol_kind::S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200) YY_NOEXCEPT
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range) YY_NOEXCEPT
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1) YY_NOEXCEPT;

    /// Constants.
    enum
    {
      yylast_ = 80,     ///< Last index in yytable_.
      yynnts_ = 16,  ///< Number of nonterminal symbols.
      yyfinal_ = 23 ///< Termination state number.
    };



  };

  inline
  parser::symbol_kind_type
  parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106
    };
    // Last valid token kind.
    const int code_max = 361;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

  // basic_symbol.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
  {
    switch (this->kind ())
    {
      case symbol_kind::S_attrib: // attrib
        value.copy< std::pair< std::string, std::string >  > (YY_MOVE (that.value));
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
      case symbol_kind::S_qualafied_id: // qualafied_id
      case symbol_kind::S_sub_proc: // sub_proc
      case symbol_kind::S_array: // array
      case symbol_kind::S_symbol: // symbol
      case symbol_kind::S_built_in: // built_in
      case symbol_kind::S_attributes: // attributes
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
  parser::symbol_kind_type
  parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_attrib: // attrib
        value.move< std::pair< std::string, std::string >  > (YY_MOVE (s.value));
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
      case symbol_kind::S_qualafied_id: // qualafied_id
      case symbol_kind::S_sub_proc: // sub_proc
      case symbol_kind::S_array: // array
      case symbol_kind::S_symbol: // symbol
      case symbol_kind::S_built_in: // built_in
      case symbol_kind::S_attributes: // attributes
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

  }

  // by_kind.
  inline
  parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  inline
  parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  inline
  parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  inline
  parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  inline
  void
  parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  inline
  void
  parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  inline
  parser::symbol_kind_type
  parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  inline
  parser::symbol_kind_type
  parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


} // yy
#line 3316 "build/pparser.tab.hh"




#endif // !YY_YY_BUILD_PPARSER_TAB_HH_INCLUDED
