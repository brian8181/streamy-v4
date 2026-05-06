#ifndef TOKENS_HPP
#define TOKENS_HPP

#include <string>

#define OFFSET __LINE__ + 1
#define TILDE __LINE__ - OFFSET
#define TIC_MARK __LINE__ - OFFSET
#define EXCLAMATION __LINE__ - OFFSET
#define AT_SYMBOL __LINE__ - OFFSET
#define HASH_MARK __LINE__ - OFFSET
#define DOLLAR_SIGN __LINE__ - OFFSET
#define PERCENT_SIGN __LINE__ - OFFSET
#define CARROT __LINE__ - OFFSET
#define AMPERSAND __LINE__ - OFFSET
#define ASTERISK __LINE__ - OFFSET
#define OPEN_PAREN __LINE__ - OFFSET
#define CLOSE_PAREN __LINE__ - OFFSET
#define DASH __LINE__ - OFFSET
#define UNDERSCORE __LINE__ - OFFSET
#define PLUS_SIGN __LINE__ - OFFSET
#define EQUAL_SIGN __LINE__ - OFFSET
#define OPEN_BRACE __LINE__ - OFFSET
#define OPEN_BRACKET __LINE__ - OFFSET
#define CLOSE_BRACE __LINE__ - OFFSET
#define CLOSE_BRACKET __LINE__ - OFFSET
#define VBAR __LINE__ - OFFSET
#define BACKSLASH __LINE__ - OFFSET
#define COLON __LINE__ - OFFSET
#define SEMI_COLON __LINE__ - OFFSET
#define DOUBLE_QUOTE __LINE__ - OFFSET
#define SINGLE_QUOTE __LINE__ - OFFSET
#define ESC_BACKSLASH __LINE__ - OFFSET
#define ESC_NEWLINE __LINE__ - OFFSET
#define ESC_DOUBLE_QUOTE __LINE__ - OFFSET
#define ESC_SINGLE_QUOTE __LINE__ - OFFSET
#define ESC_TAB __LINE__ - OFFSET
#define EQUALS __LINE__ - OFFSET
#define LESS_THAN __LINE__ - OFFSET
#define COMMA __LINE__ - OFFSET
#define GREATER_THAN __LINE__ - OFFSET
#define DOT __LINE__ - OFFSET
#define QUESTION_MARK __LINE__ - OFFSET
#define SLASH __LINE__ - OFFSET
#define NOT __LINE__ - OFFSET
#define AND __LINE__ - OFFSET
#define OR __LINE__ - OFFSET
#define XOR __LINE__ - OFFSET
#define LEFT_SHIFT __LINE__ - OFFSET
#define RIGHT_SHIFT __LINE__ - OFFSET
#define LOGICAL_AND __LINE__ - OFFSET
#define LOGICAL_OR __LINE__ - OFFSET
#define LOGICAL_NOT __LINE__ - OFFSET
#define LOGICAL_EQUAL __LINE__ - OFFSET
#define GREATER_THAN_EQUAL __LINE__ - OFFSET
#define LESS_THAN_EQUAL __LINE__ - OFFSET
#define NUMERIC_LITERAL __LINE__ - OFFSET
#define STRING_LITERAL __LINE__ - OFFSET
#define DECIMAL_LITERAL __LINE__ - OFFSET
#define HEXADECIMAL_LITERAL __LINE__ - OFFSET
#define OCTAL_DECIMAL_LITERAL __LINE__ - OFFSET
#define IF __LINE__ - OFFSET
#define ELSE __LINE__ - OFFSET
#define ELSEIF __LINE__ - OFFSET
#define FOREACH __LINE__ - OFFSET
#define DO __LINE__ - OFFSET
#define WHILE __LINE__ - OFFSET
#define SWITCH __LINE__ - OFFSET
#define CASE __LINE__ - OFFSET
#define DEFAULT __LINE__ - OFFSET
#define BREAK __LINE__ - OFFSET
#define CONTINUE __LINE__ - OFFSET
#define TRY __LINE__ - OFFSET
#define CATCH __LINE__ - OFFSET
#define REQUIRE __LINE__ - OFFSET
#define CONFIG_LOAD __LINE__ - OFFSET
#define INSERT __LINE__ - OFFSET
#define INCLUDE __LINE__ - OFFSET
#define FILE_ATTRIB __LINE__ - OFFSET
#define ASSIGN __LINE__ - OFFSET
#define VAR_ATTRIB __LINE__ - OFFSET
#define VALUE_ATTRIB __LINE__ - OFFSET
#define FROM_ATTRIB __LINE__ - OFFSET
#define ITEM_ATTRIB __LINE__ - OFFSET
#define KEY_ATTRIB __LINE__ - OFFSET
#define NAME_ATTRIB __LINE__ - OFFSET
#define CAPITALIZE __LINE__ - OFFSET
#define CAT __LINE__ - OFFSET
#define COUNT_CHARACTERS __LINE__ - OFFSET
#define COUNT_PARAGRAPHS __LINE__ - OFFSET
#define COUNT_SENTENCES __LINE__ - OFFSET
#define COUNT_WORDS __LINE__ - OFFSET
#define DATE_FORMAT __LINE__ - OFFSET
#define ESCAPE __LINE__ - OFFSET
#define INDENT __LINE__ - OFFSET
#define LOWER __LINE__ - OFFSET
#define UPPER __LINE__ - OFFSET
#define STRIP __LINE__ - OFFSET
#define NL2BR __LINE__ - OFFSET
#define REGX_REPLACE __LINE__ - OFFSET
#define REPLACE __LINE__ - OFFSET
#define SPACIFY __LINE__ - OFFSET
#define STRING_FORMAT __LINE__ - OFFSET
#define STRIP_TAGS __LINE__ - OFFSET
#define TRUNCATE __LINE__ - OFFSET
#define WORDWRAP __LINE__ - OFFSET
#define VALID_CHAR __LINE__ - OFFSET
#define FIRST_CHAR __LINE__ - OFFSET
#define ID __LINE__ - OFFSET
#define IDENTIFIER __LINE__ - OFFSET
#define SYMBOL __LINE__ - OFFSET
#define CONST_SYMBOL __LINE__ - OFFSET
#define ARRAY __LINE__ - OFFSET
#define COMMENT __LINE__ - OFFSET
#define WHITESPACE __LINE__ - OFFSET
#define FILE_NAME __LINE__ - OFFSET
#define HAS_SIGN __LINE__ - OFFSET
#define SKIP_TOKEN __LINE__ - OFFSET
#define UNESCAPED_TEXT __LINE__ - OFFSET
#define ERROR __LINE__ - OFFSET
#define SCAN_EOF __LINE__ - OFFSET
#define ANYTHING __LINE__ - OFFSET
#define MATCH __LINE__ - OFFSET
#define UNDEFINED __LINE__ - OFFSET
#define NULL __LINE__ - OFFSET
#define ADD_TYPE __LINE__ - OFFSET
#define MUL_TYPE __LINE__ - OFFSET
#define NUM __LINE__ - OFFSET
#define EXPR __LINE__ - OFFSET
#define NEWLINE __LINE__ - OFFSET
#define COUNT __LINE__ - OFFSET // for testing

#define S_TYPE "string"

/**
 * @brief token definitions : unsigned long integers
 * @brief toke_id[TILDE] = 4ul, toke_ids[TIC_MARK] = 5ul, ...
 * @brief token_t::token_def tokens[TILDE] = {"TILDE", S_TYPE, R"(~)", __LINE__}, token_t::token_def tokens[TIC_MARK
 */
unsigned long tok_id[] = {
    TILDE,
    TIC_MARK,
    EXCLAMATION,
    AT_SYMBOL,
    HASH_MARK,
    CONTINUE,
    TRY,
    CATCH,
    REQUIRE,
    CONFIG_LOAD,
    INSERT,
    INCLUDE,
    FILE_ATTRIB,
    ASSIGN,
    VAR_ATTRIB,
    VALUE_ATTRIB,
    FROM_ATTRIB,
    ITEM_ATTRIB,
    KEY_ATTRIB,
    NAME_ATTRIB,
    CAPITALIZE,
    CAT,
    COUNT_CHARACTERS,
    COUNT_PARAGRAPHS,
    COUNT_SENTENCES,
    COUNT_WORDS,
    DATE_FORMAT,
    ESCAPE,
    INDENT,
    LOWER,
    UPPER,
    STRIP,
    NL2BR,
    REGX_REPLACE,
    REPLACE,
    SPACIFY,
    STRING_FORMAT,
    STRIP_TAGS,
    TRUNCATE,
    WORDWRAP,
    VALID_CHAR,
    FIRST_CHAR,
    ID,
    IDENTIFIER,
    SYMBOL,
    CONST_SYMBOL,
    ARRAY,
    COMMENT,
    WHITESPACE,
    FILE_NAME,
    HAS_SIGN,
    SKIP_TOKEN,
    UNESCAPED_TEXT,
    ERROR,
    SCAN_EOF,
    ANYTHING,
    MATCH,
    UNDEFINED,
    NULL,
    ADD_TYPE,
    MUL_TYPE,
    NUM,
    EXPR};

#endif // TOKENS_HPP