%require "3.2"
%language "c++"

%{
    #define YYDEBUG 1
%}

%define api.value.type variant
%code
{
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
}

%define api.token.constructor
%code
{
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

    bool get_value(const string& name, /*out*/ string& val);
    bool set_value(const string& name, const string& val);


    // declare
    typedef map<string, string> symbol_table_t;
    // test
    symbol_table_t symbol_table =  { {"$a", "a_val"}, {"$b", "b_val"}, {"$c", "c_val"}, {"$x", "x"}, {"$y", "y"}, {"$z", "z"}};
    bool is_name(const std::pair<string, string>& p, const string& str);

    //%type<std::vector< modifier_t > > modifiers
    //%type<modifier_t> modifier
}

%token<std::string> CAPTURE CONFIG_LOAD INCLUDE REQUIRE REQUIRE_ONCE INSERT ASSIGN ISSET SECTION LDELIM RDELIM VERSION CYCLE COUNTER
%token<std::string> INDIRECT_MEMBER ARRAY
%token<std::string> STRING_LITERAL NUMERIC_LITERAL
%token<std::string> CONST_SYMBOL SYMBOL
%token<std::string> VAR_ATTRIB VALUE_ATTRIB FILE_ATTRIB FROM_ATTRIB KEY_ATTRIB NAME_ATTRIB ITEM_ATTRIB
%token<std::string> CAPITALIZE CAT COUNT_CHARACTERS COUNT_SENTENCES COUNT_PARAGRAPHS COUNT_WORDS DATE_FORMAT DEFAULT ESCAPE
%token<std::string> INDENT LOWER UPPER STRIP NL2BR REGEX_REPLACE REPLACE SPACIFY STRING_FORMAT STRIP_TAGS TRUNCATE WORDWRAP
%token CARROT OPEN_PAREN CLOSE_PAREN DASH BACKSLASH QUESTION_MARK SEMI_COLON DOUBLE_QUOTE SINGLE_QUOTE BACK_SLASH AT AMPERSAND AND OR NOT
%token DOLLAR_SIGN COMMA COLON VBAR HASH_MARK OPEN_BRACKET CLOSE_BRACKET OPEN_BRACE CLOSE_BRACE LPAREN RPAREN DOT
%token END 0
%token END_OF_FILES MATCH UNDEFINED WHITESPACE ANYTHING VALID_CHAR SKIP_TOKEN


%type files file blocks
%type< std::pair<std::string, std::string> > attrib
%type<std::vector< std::pair<std::string, std::string> > > attributes built_in
%type<std::string> block
%type<std::string> expr
%type<std::string> assign_stmt
%type<std::string> colon_sep_params
%type<std::string> colon_sep_param
%type<std::vector< std::string > > modifiers
%type<std::string> modifier
%type<std::string> attrib_name
%type<std::string> const_indentifier

%nonassoc IFX
%nonassoc ELSE ELSEIF IF WHILE BREAK
%left GREATER_THAN_EQUAL LESS_THAN_EQUAL EQUAL_SIGN NOT_EQUAL LESS_THAN GREATER_THAN COMMA
%left<char> PLUS_SIGN MINUS
%left ASTERISK SLASH PERCENT_SIGN
%nonassoc UMINUS
%type<std::string> symbol sub_proc array qualafied_id
%start complier

%%

/**
 * @name complier
 */
complier:
    files                                                       {
                                                                    LOG("PARSER complier: | files");
                                                                    cout << FMT_FG_DARK_GREY << "*********************** STOPPING **********************" << FMT_RESET << endl;
                                                                    cout << FMT_FG_DARK_GREY << "*                     Terminating.                    *" << FMT_RESET << endl;
                                                                    cout << FMT_FG_DARK_GREY << "************************* Done ************************" << FMT_RESET << endl;
                                                                }
                                                                ;
/**
 * @name files
 */
files:
    file                                                        { LOG("files: file"); }
    | files file                                                { LOG("files: | files file"); }
                                                                ;
/**
 * @name file
 */
file:
    blocks END                                                  {
                                                                    LOG("file: | blocks END_OF_FILE");
                                                                    cout << FMT_FG_DARK_GREY << "*******************************************************" << FMT_RESET << endl;
                                                                    cout << FMT_FG_DARK_GREY << "*                      End Of File                    *" << FMT_RESET << endl;
                                                                    cout << FMT_FG_DARK_GREY << "*******************************************************" << FMT_RESET << endl;
                                                                }
                                                                ;
/**
 * @name blocks
 */
blocks:
    block                                                       { LOG("PARSER blocks: | block"); }
    | blocks block                                              {
                                                                    LOG("blocks: | blocks block");
                                                                    lexer::instance().dump_config();
                                                                }
                                                                ;
/**
 * @name block
 */
block:
   OPEN_BRACE expr CLOSE_BRACE                               {
                                                                    LOG("block: | OPEN_BRACE expr CLOSE_BRACE");
                                                                }
    | OPEN_BRACE sub_proc CLOSE_BRACE                           {
                                                                    LOG("block: | OPEN_BRACE sub_porc CLOSE_BRACE");
                                                                }
    | OPEN_BRACE array CLOSE_BRACE                              {
                                                                    LOG("block: | OPEN_BRACE array CLOSE_BRACE");
                                                                }
    | OPEN_BRACE assign_stmt CLOSE_BRACE                        {
                                                                    LOG("block: | OPEN_BRACE assign_stmt CLOSE_BRACE");
                                                                }
    | OPEN_BRACE qualafied_id CLOSE_BRACE                       {
                                                                    LOG("block: | OPEN_BRACE qualafied_id CLOSE_BRACE");
                                                                    // bkp todo, look up in symbol table & do replace
                                                                    // bkp todo qualified lookup
                                                                    std::string s;
                                                                    get_value($2, s);
                                                                    $$ = s;
                                                                }
    | OPEN_BRACE INCLUDE attributes CLOSE_BRACE                 {
                                                                    LOG("block: OPEN_BRACE INCLUDE attributes CLOSE_BRACE");
                                                                    // LOG("block: | OPEN_BRACE built_in CLOSE_BRACE");
                                                                    // size_t len = $2.size();
                                                                    // int i = 0;
                                                                    // for(; i < len; ++i)
                                                                    // {
                                                                    //     if($2[i].first == "file")
                                                                    //         break;
                                                                    // }
                                                                    // string path = $2[i].second;
                                                                    // // read include path
                                                                    // string sout;
                                                                    // read_str(path, sout);
                                                                    // //  append include path output to buffer
                                                                    // string* p_rstr = lexer::instance().get_remaining();
                                                                    // stringstream* include_buffer = lexer::instance().get_include_buffer();
                                                                    // *include_buffer << sout << *p_rstr;

                                                                    // cout << FMT_FG_RED << include_buffer->str() << FMT_RESET;
                                                                    // // set the suffix a.k.a "current search buffer"
                                                                    // lexer::instance().set_remaining( (*include_buffer).str() );
                                                                    // lexer::instance().set_state(&sINITIAL);
                                                                    // cout << FMT_FG_RED << "file=\"" << FMT_ITALIC << path << "\"" << "");
                                                                }
    | OPEN_BRACE ASSIGN attributes CLOSE_BRACE                  {
                                                                     LOG("block: | OPEN_BRACE ASSIGN attibutes CLOSE_BRACE");
                                                                }
                                                                ;
/**
 * @name assign_stmt
 */
assign_stmt:
    symbol EQUAL_SIGN NUMERIC_LITERAL                           {
                                                                    LOG("assign_stmt: | symbol EQUAL_SIGN NUMERIC_LITERAL");
                                                                    set_value($1, $3);
                                                                    $$ = $3;
                                                                }
    | symbol EQUAL_SIGN STRING_LITERAL                          {
                                                                    LOG("assign_stmt: | symbol EQUAL_SIGN STRING_LITERAL");
                                                                    set_value($1, $3);
                                                                    $$ = $3;
                                                                }
                                                                ;
 /**
 * @name expr
 * @brief Numerical / logical exprssions
 */
expr:
    symbol VBAR modifiers                                       {
                                                                    LOG("expr: | symbol VBAR modifiers ");
                                                                    std::string s;
                                                                    get_value($1, s);
                                                                    $$ = s;
                                                                }
    | MINUS expr %prec UMINUS                                   {
                                                                    LOG("PARSER expr: | expr <<");
                                                                }
    | expr PLUS_SIGN expr                                       {
                                                                    LOG("PARSER expr: | expr PLUS_SIGN expr <<");
                                                                }
    | expr MINUS expr                                           {
                                                                    LOG("PARSER expr: | expr MINUS expr <<");
                                                                }
    | expr ASTERISK expr                                        {
                                                                    LOG("PARSER expr: | expr ASTERISK expr <<");
                                                                }
    | expr SLASH expr                                           {
                                                                    LOG("PARSER expr: | expr SLASH expr <<");
                                                                }
    | expr LESS_THAN expr                                       {
                                                                    LOG("PARSER expr: | expr LESS_THAN expr <<");
                                                                }
    | expr GREATER_THAN expr                                    {
                                                                    LOG("PARSER expr: | | expr GREATER_THAN expr <<");
                                                                }
    | expr GREATER_THAN_EQUAL expr                              {
                                                                    LOG("PARSER expr: | expr GREATER_THAN_EQUAL expr << ");
                                                                }
    | expr LESS_THAN_EQUAL expr                                 {
                                                                    LOG("PARSER expr: | expr LESS_THAN_EQUAL expr <<");
                                                                }
    | expr NOT_EQUAL expr                                       {
                                                                    LOG("PARSER expr: | expr NOT_EQUAL expr <<");
                                                                }
    | LPAREN expr RPAREN                                        {
                                                                    LOG("PARSER expr: | LPAREN expr RPAREN <<");
                                                                }
                                                                ;
/**
 * @name qualafied_id
 */
qualafied_id:
    symbol DOT symbol                                       { LOG("qualafied_id: | symbol DOT symbol"); }
    | symbol INDIRECT_MEMBER symbol                         { LOG("qualafied_id: | symbol INDIRECT_MEMBER symbol"); }
    | qualafied_id DOT symbol                               { LOG("qualafied_id: | qualafied_id DOT symbol"); }
    | qualafied_id INDIRECT_MEMBER symbol                   { LOG("qualafied_id: | qualafied_id INDIRECT_MEMBER symbol"); }
                                                                ;
/**
 * @name sub_proc
 */
sub_proc:
    symbol LPAREN params RPAREN                                 {
                                                                    LOG("sub_proc: | symbol LPAREN params RPAREN" << "");
                                                                    $$=$1;
                                                                }
                                                                ;
/**
 * @name array
 */
array:
    symbol OPEN_BRACKET NUMERIC_LITERAL CLOSE_BRACKET           {
                                                                    LOG("PARSER array: | symbol=\"" << $1 << "\" OPEN_BRACKET NUMERIC_LITERAL=\"" << $3 << "\" CLOSE_BRACKET");
                                                                    $$=$1;
                                                                }
                                                                ;
/**
 * @name params
 * @brief params (i.e. $x, $y, $x)
 */
params:
    param                                                       { LOG("PARSER params: | param"); }
    | params symbol                                             { LOG("qualafied_id: | params COMMA symbol"); }
                                                                ;
/**
 * @name param
 * @brief param (i.e. $x, )
 */
param:
        symbol COMMA                                            { LOG("param: | symbol"); }
                                                                ;
/**
 * @name modifiers
 * @brief create vector of modifiers
 */
modifiers:
    modifier                                                    {
                                                                     std::vector< std::string > v;
                                                                     //v.push_back($1);
                                                                     //$$ = v;
                                                                     $$.push_back($1);
                                                                }
   | modifiers VBAR modifier                                    {
                                                                    $1.push_back($3);
                                                                    $$ = $1;
                                                                }
                                                                ;
/**
 *   @name modifier
 */
modifier:
    modifier colon_sep_params                                   {
                                                                    LOG(" modifier: modifier colon_sep_params");
                                                                    // $1.params.append("|");
                                                                    // $1.params.append($2);
                                                                }
    | CAPITALIZE                                                {
                                                                    LOG("PARSER modifier: | CAPITALIZE");
                                                                    // modifier_t m;
                                                                    // m.name = "capitalize";
                                                                    // m.params = "";
                                                                    // $$ = m;
                                                                    $$ = "capitalize";
                                                                }
    | CAT                                                       { LOG("PARSER modifier: | CAT"); $$="cat"; }
    | COUNT_CHARACTERS                                          { LOG("PARSER modifier: | COUNT_CHARACTERS"); $$="count_characters"; }
    | COUNT_SENTENCES                                           { LOG("PARSER modifier: | COUNT_SENTENCES"); $$="count_sentences"; }
    | COUNT_PARAGRAPHS                                          { LOG("PARSER modifier: | COUNT_PARAGRAPHS"); $$="count_paragraphs"; }
    | COUNT_WORDS                                               { LOG("PARSER modifier: | COUNT_WORDS"); $$="count_words"; }
    | DATE_FORMAT                                               { LOG("PARSER modifier: | DATE_FORMAT"); $$="date_format"; }
    | DEFAULT                                                   { LOG("PARSER modifier: | DEFAULT"); $$="default"; }
    | ESCAPE                                                    { LOG("PARSER modifier: | ESCAPE"); $$="esacpe"; }
    | INDENT                                                    { LOG("PARSER modifier: | INDENT"); $$="indent"; }
    | STRIP                                                     { LOG("PARSER modifier: | STRIPS"); $$="strip"; }
    | NL2BR                                                     { LOG("PARSER modifier: | NL2BR"); $$="nl2br"; }
    | REPLACE                                                   { LOG("PARSER modifier: | REPLACE"); $$="replace"; }
    | REGEX_REPLACE                                             { LOG("PARSER modifier: | REGEX_REPLACE"); $$="regex_replsce"; }
    | SPACIFY                                                   { LOG("PARSER modifier: | SPACIFY"); $$="spacify"; }
    | STRING_FORMAT                                             { LOG("PARSER modifier: | STRING_FORMAT"); $$="string_format"; }
    | STRIP_TAGS                                                { LOG("PARSER modifier: | STIP_TAGS"); $$="strip_tags"; }
    | TRUNCATE                                                  {
                                                                    LOG("TRUNCATE"); $$="truncate";
                                                                    // modifier_t m;
                                                                    // m.name = "truncate";
                                                                    // m.params = "";
                                                                    // $$ = m;
                                                                    $$ = "truncate";
                                                                }
    | UPPER                                                     { LOG("PARSER modifier: | UPPER"); $$="upper"; }
    | LOWER                                                     { LOG("PARSER modifier: | LOWER"); $$="lower"; }
    | WORDWRAP                                                  { LOG("PARSER modifier: | WORDWRAP"); $$="word_wrap"; }
                                                                ;
/**
 * @name colon_sep_params
 * @brief ( $x:$y:$x ) | 1:2:"three"
 */
colon_sep_params:
        /*empty*/
        | colon_sep_params colon_sep_param                      { LOG("colon_sep_params: | colon_sep_params colon_sep_param"); $$=$1.append($2); }
                                                                ;
/**
 * @name colon_sep_param
 * @brief colon seperated param {$x|trim:3:' '}
 */
colon_sep_param:
        COLON NUMERIC_LITERAL                                   { LOG("colon_sep_param: | COLON NUMERIC_LITERAL"); string s(":"); s.append($2); $$=s; }
                                                                ;
/**
 * @name symbol
 */
symbol:
    SYMBOL                                                      {
                                                                    LOG("symbol: | SYMBOL=\"" + $1 + "\"");
                                                                    //LOG("SYMBOL testing");
                                                                    $$=$1;
                                                                }
    | CONST_SYMBOL                                              {
                                                                    cout << FMT_FG_DARK_GREY << "symbol: | CONST_SYMBOL=\"" << $1 << "\" - line#=" << __LINE__  << FMT_RESET << endl;
                                                                    $$=$1;
                                                                }
                                                                ;
/**
 * @name built-in
 */
built_in:
    CONFIG_LOAD attributes                                      {
                                                                    LOG("built_in: | CONFIG_LOAD attributes");
                                                                    $$ = $2;
                                                                }
    | '#' INCLUDE attributes                                        {
                                                                    LOG("built_in: | INCLUDE attributes");
                                                                    $$ = $2;
                                                                }
    | REQUIRE attributes                                        { cout << FMT_FG_DARK_GREY << "built_in: | REQUIRE FILE_ATTRIB=\"%s\" EQUAL STRING_LITERAL=\"\"" << " - line#=" << __LINE__  << FMT_RESET << endl; }
    | REQUIRE_ONCE attributes                                   { cout << FMT_FG_DARK_GREY << "built_in: | REQUIRE_once FILE_ATTRIB=\"%s\" EQUAL STRING_LITERAL=\"\"" << " - line#=" << __LINE__  << FMT_RESET << endl; }
    | INSERT attributes                                         { cout << FMT_FG_DARK_GREY << "built_in: | INSERT FILE_ATTRIB=\"%s\" EQUAL STRING_LITERAL=\"\"" << " - line#=" << __LINE__  << FMT_RESET << endl; }
    | '#' ASSIGN attributes                                     {
                                                                    LOG("built_in: | ASSIGN attributes");
                                                                    $$ = $2;
                                                                }
    | ISSET attributes                                          { cout << FMT_FG_DARK_GREY << "built_in: | ISSET FILE_ATTRIB=\"%s\" EQUAL STRING_LITERAL=\"\"" << " - line#=" << __LINE__  << FMT_RESET << endl; }
    | CAPTURE attributes                                        { cout << FMT_FG_DARK_GREY << "built_in: | CAPTURE FILE_ATTRIB=\"%s\" EQUAL STRING_LITERAL=\"\"" << " - line#=" << __LINE__  << FMT_RESET << endl; }
    | SECTION attributes                                        { cout << FMT_FG_DARK_GREY << "built_in: | SECTION FILE_ATTRIB=\"%s\" EQUAL STRING_LITERAL=\"\"" << " - line#=" << __LINE__  << FMT_RESET << endl; }
    | COUNTER attributes                                        { cout << FMT_FG_DARK_GREY << "built_in: | COUNTER FILE_ATTRIB=\"%s\" EQUAL STRING_LITERAL=\"\"" << " - line#=" << __LINE__  << FMT_RESET << endl; }
    | CYCLE attributes                                          { cout << FMT_FG_DARK_GREY << "built_in: | CYCLE FILE_ATTRIB=\"%s\" EQUAL STRING_LITERAL=\"\"" << " - line#=" << __LINE__  << FMT_RESET << endl; }
    | LDELIM attributes                                         { cout << FMT_FG_DARK_GREY << "built_in: | LDELIM FILE_ATTRIB=\"%s\" EQUAL STRING_LITERAL=\"\"" << " - line#=" << __LINE__  << FMT_RESET << endl; }
    | RDELIM attributes                                         { cout << FMT_FG_DARK_GREY << "built_in: | RDELIM FILE_ATTRIB=\"%s\" EQUAL STRING_LITERAL=\"\"" << " - line#=" << __LINE__  << FMT_RESET << endl; }
    | VERSION attributes                                        { cout << FMT_FG_DARK_GREY << "built_in: | VERSION FILE_ATTRIB=\"%s\" EQUAL STRING_LITERAL=\"\"" << " - line#=" << __LINE__  << FMT_RESET << endl; }
                                                                ;
/**
 * @name attributes
 */
attributes:
    attrib                                                     {
                                                                    cout << FMT_FG_DARK_GREY << "attribute: | push -> attrib={name=\"" << $1.first  << "\"; value=\"" << $1.second << "\"}\n" << " - line#=" << __LINE__  << FMT_RESET << endl;
                                                                    std::pair<std::string, std::string>  p($1);
                                                                    std::vector< std::pair<std::string, std::string> > v;
                                                                    v.push_back( p );
                                                                    $$ = v;
                                                               }
    | attributes attrib                                        {
                                                                    cout << FMT_FG_DARK_GREY << "attribute: | attributes : push-> attrib={name=\"" << $2.first  << "\"; value=\"" << $2.second << "\"}\n" << " - line#=" << __LINE__  << FMT_RESET << endl;
                                                                    $1.push_back( $2 );
                                                                    $$ = $1;
                                                               }
                                                               ;
/**
 * @name attrib
 */
attrib:
    VALUE_ATTRIB EQUAL_SIGN STRING_LITERAL                     {
                                                                    cout << FMT_BG_DARK_GREY << "name_value: | VALUE_ATTRIB=\""
                                                                        << $1 << "\" EQUAL_SIGN STRING_LITERAL=\""
                                                                        << buf << "\"" << " - line#=" << __LINE__  << FMT_RESET << endl;
                                                                    std::pair<std::string, std::string>  pair($1, $3);
                                                                    $$ = pair;
                                                               }
    | VAR_ATTRIB EQUAL_SIGN STRING_LITERAL                     {
                                                                    cout << FMT_FG_YELLOW
                                                                        << "PARSER name_value: | VAR_ATTRIB=\"\" EQUAL_SIGN STRING_LITERAL=\"\""
                                                                        << FMT_FG_GREEN << " - line#=" << __LINE__  << FMT_RESET << endl;
                                                                    std::pair<std::string, std::string>  pair($1, $3);
                                                                    $$ = pair;
                                                               }
    | FILE_ATTRIB EQUAL_SIGN STRING_LITERAL                    {
                                                                    cout << FMT_FG_YELLOW
                                                                        << "PARSER name_value: | FILE_ATTRIB=\""
                                                                        << $1 << "\" EQUAL_SIGN STRING_LITERAL=\""
                                                                        << $3 << "\""
                                                                        << " - line#=" << __LINE__  << FMT_RESET << endl;
                                                                    std::pair<std::string, std::string>  pair($1, $3);
                                                                    $$ = pair;
                                                               }
    | FILE_ATTRIB EQUAL_SIGN symbol                    {
                                                                    cout << FMT_FG_YELLOW
                                                                        << "PARSER name_value: | FILE_ATTRIB=\""
                                                                        << $1 << "\" EQUAL_SIGN STRING_LITERAL=\""
                                                                        << $3 << "\""
                                                                        << " - line#=" << __LINE__  << FMT_RESET << endl;
                                                                    std::pair<std::string, std::string>  pair($1, $3);
                                                                    $$ = pair;
                                                               }
    | attrib_name EQUAL_SIGN STRING_LITERAL                    {
                                                                      cout << FMT_FG_YELLOW
                                                                        << "PARSER name_value: | " << $1 << "=\""
                                                                        << $1 << "\" EQUAL_SIGN STRING_LITERAL=\""
                                                                        << $3 << "\""
                                                                        << " - line#=" << __LINE__  << FMT_RESET << endl;
                                                                    std::pair<std::string, std::string>  pair($1, $3);
                                                                    $$ = pair;
                                                               }
                                                               ;
/**
 * @name attrib_name
 * @brief attribute name
 */
attrib_name:
    FROM_ATTRIB
    | ITEM_ATTRIB
    | KEY_ATTRIB
    | NAME_ATTRIB
    ;

%%

bool get_value(const string& name, /*out*/ string& val)
{
    if(symbol_table.find(name) != symbol_table.end())
    {
        val = symbol_table[name];
        return true;
    }
    cout << FMT_FG_RED << "symbol, (" << name << "), not found!" << " - line#=" << __LINE__  << FMT_RESET << endl;
    return false;
}

bool set_value(const string& name, const string& val)
{
    if(symbol_table.find(name) != symbol_table.end())
    {
        symbol_table[name] = val;
        cout << FMT_FG_GREEN << "symbol updated: " << name << " = " << val << " - line#=" << __LINE__  << FMT_RESET << endl;\
        return true;
    }
    cout << FMT_FG_RED << "symbol, (" << name << "), not found!" << " - line#=" << __LINE__  << FMT_RESET << endl;
    return false;
}

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
