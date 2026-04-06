/**
 * @file    parser.hpp
 * @version 0.0.1
 * @date    Sat, 04 Apr 2026 12:59:28 +0000
 * @info    ...
 */
#include "parser.hpp"
#include "lexer.hpp"

typedef vector<unsigned long> RULE;
typedef vector<RULE> RULES;
typedef unsigned int RULEZ[][];

unsigned int rules[][] =
{
    /**
    * @name compiler
    */
    {
            {UL_FILES, UL_END_OF_FILES}
    },

    /**
    * @name files
    */
    {
        {UL_FILE},
        {UL_FILES}, {UL_FILE}
    },

    /**
    * @name file
    */
    {
        {UL_BLOCKS, UL_END_OF_FILE}
    },

    /**
     * @name blocks
     */
    {
        {UL_BLOCK},
        {UL_BLOCKS, UL_BLOCK}
    },

    /**
     * @name block
     */
    {
        {UL_OPEN_BRACKET, UL_SYMBOL, UL_CLOSE_BRACE},
        {UL_OPEN_BRACKET, UL_EXPR, UL_CLOSE_BRACE},
        {UL_OPEN_BRACKET, UL_SUB_PROC, UL_CLOSE_BRACE},
        {UL_OPEN_BRACKET, UL_ARRAY, UL_CLOSE_BRACE},
        {UL_OPEN_BRACE, UL_BUILT_IN, UL_ATTRIBUTES, UL_CLOSE_BRACE}
    },

    /**
    * @name assign_stmt
    */
    {
        {UL_SYMBOL, UL_EQUAL_SIGN, UL_NUMERIC_LITERAL},
        {UL_SYMBOL, UL_EQUAL_SIGN, UL_STRING_LITERAL}
    },

    /**
    * @name sub_pro
    */
    {
        {UL_SYMBOL, UL_OPEN_PAREN, UL_PARAMS, UL_CLOSE_PAREN}
    },

    /**
    * @name array
    */
    {
          {UL_SYMBOL, UL_OPEN_BRACKET, UL_NUMERIC_LITERAL, UL_CLOSE_BRACKET}
    },

    /**
    * @name params
    * @brief params (i.e. $x, $y, $x)
    */
    {
        {UL_PARAM},
        {UL_PARAMS, UL_PARAM}
    },

    /**
    * @name param
    * @brief param (i.e. $x, )
    */
    {
        {UL_COMMA, UL_PARAM}
    },

    /**
    * @name modifier
    */
    {
        {UL_CAPITALIZE},
        {UL_CAT},
        {UL_COUNT_CHARACTERS},
        {UL_COUNT_PARAGRAPHS},
        {UL_COUNT_SENTENCES },
        {UL_COUNT_WORDS     },
        {UL_DATE_FORMAT     },
        {UL_ESCAPE          },
        {UL_INDENT          },
        {UL_STRIP           },
        {UL_NL2BR        },
        {UL_REGX_REPLACE },
        {UL_REPLACE      },
        {UL_SPACIFY      },
        {UL_STRING_FORMAT},
        {UL_STRIP_TAGS   },
        {UL_TRUNCATE     },
        {UL_LOWER           },
        {UL_UPPER           },
        {UL_WORDWRAP     }
    },

    /**
    * @name colon_sep_params
    * @brief ( $x:$y:$x ) | 1:2:"three"
    */
    {
        {UL_COLON_SEP_PARAMS, UL_COLON_SEP_PARAM}
    },

    /**
    * @name colon_sep_param
    * @brief colon seperated param {$x|trim:3:' '}
    */
    {
        {UL_COLON, UL_NUMERIC_LITERAL},
        {UL_COLON, UL_STRING_LITERAL},
        {UL_COLON, UL_SYMBOL},
    },

    /**
    * @name qualafied_identifier
    */
    {
        {UL_SYMBOL},
        //{UL_DOLLAR_SIGN, UL_IDENTIFIER},
        {UL_CONST_SYMBOL},
        //{UL_HASH_MARK, UL_IDENTIFIER, UL_HASH_MARK},
        {UL_SYMBOL, UL_DOT, UL_SYMBOL},
        {UL_SYMBOL, UL_INDIRECT_MEMBER, UL_SYMBOL}
    },

    /**
    * @name built_in
    */
    {
        {UL_REQUIRE},
        {UL_CONFIG_LOAD},
        {UL_INSERT},
        {UL_INCLUDE},
        {UL_FILE_ATTRIB},
        {UL_ASSIGN}
    },

    /**
    * @name attributes
    */
    {
        {UL_ATTRIB},
        {UL_ATTRIBUTES, UL_ATTRIB}
    },

    /**
    * @name attrib
    */
    {
        { UL_VALUE_ATTRIB, UL_LOGICAL_EQUAL, UL_STRING_FORMAT   },
        { UL_VAR_ATTRIB, UL_LOGICAL_EQUAL, UL_STRING_FORMAT   },
        { UL_FILE_ATTRIB, UL_LOGICAL_EQUAL, UL_STRING_FORMAT   },
        { UL_FILE_ATTRIB, UL_LOGICAL_EQUAL, UL_SYMBOL   },
        { UL_ATTRIB_NAME, UL_LOGICAL_EQUAL, UL_STRING_FORMAT   }
    },

    /**
    * @name attrib_name
    */
    {
        {UL_FROM_ATTRIB},
        {UL_ITEM_ATTRIB},
        {UL_KEY_ATTRIB},
        {UL_NAME_ATTRIB}
    }
};

bkp::parser::parser(context* ct) : m_context(ct)
{
}

token_match* bkp::parser::parse()
{
    token_match* t = lexer::get_match();
    return t;
}



