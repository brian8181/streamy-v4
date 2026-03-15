%require "3.2"
%language "c++"
%define api.value.type variant
%code
{
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
}

%define api.token.constructor
%code
{
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

}
%token MATCH UNDEFINED WHITESPACE CARROT OPEN_PAREN CLOSE_PAREN DASH PLUS_SIGN BACKSLASH ARRAY OPEN_BRACKET CLOSE_BRACKET OPEN_BRACE CLOSE_BRACE LPAREN RPAREN
%token SKIP_TOKEN CONST_SYMBOL ANYTHING VALID_CHAR DOLLAR_SIGN COMMA VBAR COLON PERCENT_SIGN HASH_MARK
%token IF WHILE BREAK
%token END 0 _("end of input")
%token END_OF_FILES
%type files file block blocks colon_sep_param colon_sep_params modifier
%type<std::pair< std::string, std::string > > attrib
%type<std::string> built_in
%type<std::string> attributes
%type<std::string> expr
%type<std::string> stmt assign_stmt
%type<std::string> number
%token<std::string> CAPTURE CONFIG_LOAD INCLUDE REQUIRE REQUIRE_ONCE INSERT ASSIGN ISSET SECTION LDELIM RDELIM VERSION CYCLE COUNTER
%token<std::string> CAPITALIZE CAT COUNT_CHARACTERS COUNT_SENTENCES COUNT_PARAGRAPHS COUNT_WORDS DATE_FORMAT DEFAULT ESCAPE
%token<std::string> INDENT LOWER UPPER STRIP NL2BR REGEX_REPLACE REPLACE SPACIFY STRING_FORMAT STRIP_TAGS TRUNCATE WORDWRAP REGX_REPLACE
%token SEMI_COLON DOUBLE_QUOTE SINGLE_QUOTE BACK_SLASH
%token AT AMPERSAND AND OR NOT DOT PERIOD
%token<std::string> INDIRECT_MEMBER
%token<std::string> STRING_LITERAL NUMERIC_LITERAL
%token<std::string> IDENTIFIER ID CONST_ID
%token<std::string> VAR_ATTRIB VALUE_ATTRIB FILE_ATTRIB FROM_ATTRIB KEY_ATTRIB NAME_ATTRIB ITEM_ATTRIB FILE_NAME
%token<std::string> UNESCAPED_TEXT
%token COMMENT QUESTION_MARK
%token<int> NUMBER


%nonassoc IFX
%nonassoc ELSE ELSEIF
%left GREATER_THAN_EQUAL LESS_THAN_EQUAL EQUAL_SIGN NOT_EQUAL LESS_THAN GREATER_THAN COMMA
%left PLUS MINUS
%left ASTERISK SLASH PERCENT
%nonassoc UMINUS
%type<std::string> symbol sub_proc array qualafied_id
%start complier

%%

/**
 * @name complier
 */
complier:
    files                                                       {
                                                                    cout <<  FMT_FG_GREEN << "PARSER complier: | files" << FMT_RESET << endl;
                                                                    cout << FMT_FG_YELLOW << "*********************** STOPPING **********************" << FMT_REVERSE << FMT_RESET << endl;
                                                                    cout << FMT_FG_YELLOW << "*                     Terminating.                    *" << FMT_REVERSE << FMT_RESET << endl;
                                                                    cout << FMT_FG_YELLOW << "************************* Done ************************" << FMT_REVERSE << FMT_RESET << endl;
                                                                }
                                                                ;

/**
 * @name files
 */
files:
    file                                                        { cout << FMT_FG_YELLOW << "PARSER files: | file" << FMT_RESET << endl; }
    | files file                                                { cout << FMT_FG_YELLOW << "PARSER files: | files file" << FMT_RESET << endl; }
                                                                ;

/**
 * @name file
 */
file:
    blocks END                                                  {
                                                                    cout << FMT_FG_YELLOW << "PARSER file: | blocks END_OF_FILE" << FMT_RESET << endl;
                                                                    cout << FMT_FG_YELLOW << "*******************************************************" << FMT_REVERSE << FMT_RESET << endl;
                                                                    cout << FMT_FG_YELLOW << "*                      End Of File                    *" << FMT_REVERSE << FMT_RESET << endl;
                                                                    cout << FMT_FG_YELLOW << "*******************************************************" << FMT_REVERSE << FMT_RESET << endl;
                                                                }
                                                                ;

/**
 * @name blocks
 */
blocks:
    block                                                       {
                                                                    cout << FMT_FG_YELLOW << "PARSER blocks: | block" << FMT_RESET << endl;
                                                                }
    | blocks block                                              {
                                                                    cout << FMT_FG_YELLOW << "PARSER blocks: | blocks block" << FMT_RESET << endl;
                                                                }
                                                                ;

/**
 * @name block
 */
block:
    OPEN_BRACE sub_proc CLOSE_BRACE                             {
                                                                    cout << FMT_FG_YELLOW << "PARSER block: | OPEN_BRACE sub_porc CLOSE_BRACE" << FMT_RESET << endl;
                                                                }
    | OPEN_BRACE array CLOSE_BRACE                              {
                                                                    cout << FMT_FG_YELLOW << "PARSER block: | OPEN_BRACE array CLOSE_BRACE" << FMT_RESET << endl;
                                                                }
    | OPEN_BRACE symbol CLOSE_BRACE                             {
                                                                    cout << FMT_FG_YELLOW << "PARSER block: | OPEN_BRACE symbol CLOSE_BRACE" << FMT_RESET << endl;
                                                                }
    | OPEN_BRACE assign_stmt CLOSE_BRACE                        {
                                                                    cout << FMT_FG_YELLOW << "PARSER block: | OPEN_BRACE assign_stmt CLOSE_BRACE" << FMT_RESET << endl;
                                                                }
    | OPEN_BRACE qualafied_id CLOSE_BRACE                       {
                                                                    cout << FMT_FG_YELLOW << "PARSER block: | OPEN_BRACE qualafied_id CLOSE_BRACE" << FMT_RESET << endl;
                                                                }
    | OPEN_BRACE built_in CLOSE_BRACE                           {
                                                                    cout << FMT_FG_YELLOW << "PARSER block: | OPEN_BRACE built_in CLOSE_BRACE" << FMT_RESET << endl;
                                                                    //free_all_nvalues();
                                                                }
                                                                ;

/**
 * @name assign_stmt
 */
assign_stmt:
    symbol EQUAL_SIGN number                                    {
                                                                    cout << FMT_FG_YELLOW << "PARSER assign_stmt: | symbol EQUAL_SIGN NUMERIC_LITERAL" << FMT_RESET << endl;
                                                                    if(auto iter = stab.find($1) != stab.end())
                                                                    {
                                                                        //iter->second = $3;
                                                                    }
                                                                    $$ = $1;
                                                                }
    | symbol EQUAL_SIGN STRING_LITERAL                          {
                                                                    cout << FMT_FG_YELLOW << "PARSER assign_stmt: | symbol EQUAL_SIGN STRING_LITERAL=" << FMT_RESET << $3 << "\n";
                                                                    $$ = $1;
                                                                }
                                                                ;


number:
    NUMERIC_LITERAL                                              {
                                                                    cout << "PARSER number: | NUMERIC_LITERAL\n";
                                                                    $$=$1;
                                                                }
                                                                ;

/**
 * @name stmt
 */
stmt:
     expr CLOSE_BRACE                                           {
                                                                    /*$$ = opr(PRINT, 1, $2);          */
                                                                    cout << FMT_FG_YELLOW "PARSER stmt: | expr CLOSE_BRACE\n" << FMT_RESET;
                                                                }
    | WHILE LPAREN expr RPAREN stmt                             {
                                                                    cout << "PARSER stmt: | WHILE LPAREN expr RPAREN stmt\n";
                                                                }
     | IF LPAREN expr %prec IFX RPAREN                          {
                                                                    cout << "PARSER stmt TEST: | IF LPAREN expr prec IFX RPAREN\n";
                                                                }
    | IF LPAREN expr RPAREN stmt %prec IFX SLASH IF CLOSE_BRACE {
                                                                    cout << "PARSER stmt: | IF LPAREN expr RPAREN stmt prec IFX CLOSE_BRACE\n";
                                                                }
    | SLASH IF CLOSE_BRACE                                      {
                                                                    cout << "PARSER stmt: | IF LPAREN expr RPAREN stmt ELSE stmt CLOSE_BRACE\n";
                                                                }

    | IF LPAREN expr RPAREN stmt ELSE stmt CLOSE_BRACE          {
                                                                    cout << "PARSER stmt: | IF LPAREN expr RPAREN stmt ELSE stmt CLOSE_BRACE\n";
                                                                }
    | sub_proc CLOSE_BRACE                                      {
                                                                    cout << "PARSER stmt: | sub_porc CLOSE_BRACE\n";
                                                                }
    | array CLOSE_BRACE                                         {
                                                                    cout  << "PARSER stmt: | array CLOSE_BRACE\n";
                                                                }
    | expr VBAR modifier CLOSE_BRACE                            {
                                                                    cout << "PARSER stmt: | symbol VBAR CLOSE_BRACE\n";
                                                                }
    | qualafied_id CLOSE_BRACE                                  {
                                                                    cout  << "PARSER stmt: | qualafied_id CLOSE_BRACE\n";
                                                                }
     | built_in CLOSE_BRACE                                     {
                                                                    cout  << "PARSER stmt: | built_in CLOSE_BRACE\n";
                                                                }
                                                                ;

/**
 * @name expr
 * @brief Numerical / logical exprssions
 */
expr:
       STRING_LITERAL                                           {
                                                                    cout << FMT_FG_YELLOW << "PARSER expr: | STRING_LITERAL" << FMT_RESET << endl;
                                                                    $$=$1;
                                                                }
       | MINUS expr %prec UMINUS                                {
                                                                    cout << "PARSER expr: | expr\n";
                                                                }
        | expr PLUS expr                                        {
                                                                    cout << "PARSER expr: | expr\n";
                                                                }
        | expr MINUS expr                                       {
                                                                    cout << "PARSER expr: | expr\n";
                                                                }
        | expr ASTERISK expr                                    {
                                                                    cout << "PARSER expr: | expr\n";
                                                                }
        | expr SLASH expr                                       {
                                                                    cout << "PARSER expr: | expr\n";
                                                                }
        | expr LESS_THAN expr                                   {
                                                                    cout << "PARSER expr: | expr\n";
                                                                }
        | expr GREATER_THAN expr                                {
                                                                    cout << "PARSER expr: | expr\n";
                                                                }
        | expr GREATER_THAN_EQUAL expr                          {
                                                                    cout << "PARSER expr: | expr\n";
                                                                }
        | expr LESS_THAN_EQUAL expr                             {
                                                                    cout << "PARSER expr: | expr\n";
                                                                }
        | expr NOT_EQUAL expr                                   {
                                                                    cout << "PARSER expr: | expr\n";
                                                                }
        | LPAREN expr RPAREN                                    {
                                                                    cout << "PARSER expr: | expr\n";
                                                                }
                                                                ;

/**
 * @name colon_sep_params
 * @brief ( $x:$y:$x ) | 1:2:"three"
 */
colon_sep_params:
        colon_sep_param                                         {
                                                                    cout << "colon_sep_params: | colon_sep_param\n";
                                                                }
        | colon_sep_params colon_sep_param                      {
                                                                    cout << "colon_sep_params: | colon_sep_params colon_sep_param" << endl;
                                                                }
                                                                ;

/**
 * @name colon_sep_param
 * @brief colon seperated param {$x|trim:3:' '}
 */
colon_sep_param:
        COLON NUMERIC_LITERAL                                   {
                                                                    cout << "colon_sep_param: | COLON NUMERIC_LITERAL" << endl;
                                                                }
                                                                ;

/**
 * @name qualafied_id
 */
qualafied_id:
    symbol DOT ID                                               {
                                                                    cout << FMT_FG_YELLOW
                                                                            << "PARSER qualafied_id: | symbol DOT ID"
                                                                         << FMT_RESET << endl;
                                                                }
    | symbol INDIRECT_MEMBER ID                                 { cout << FMT_FG_YELLOW << "PARSER qualafied_id: | symbol INDIRECT_MEMBER ID" << FMT_RESET << endl; }
    | qualafied_id DOT ID                                       { cout << FMT_FG_YELLOW << "PARSER qualafied_id: | qualafied_id DOT ID" << FMT_RESET << endl; }
    | qualafied_id INDIRECT_MEMBER ID                           { cout << FMT_FG_YELLOW << "PARSER qualafied_id: | qualafied_id INDIRECT_MEMBER ID" << FMT_RESET << endl; }
                                                                ;

/**
 * @name sub_proc
 */
sub_proc:
    symbol LPAREN params RPAREN                                 {
                                                                    cout << FMT_FG_YELLOW
                                                                            << "PARSER sub_proc: | symbol LPAREN params RPAREN"
                                                                        << FMT_RESET << endl;
                                                                    $$=$1;
                                                                }
                                                                ;

/**
 * @name array
 */
array:
    symbol OPEN_BRACKET NUMERIC_LITERAL CLOSE_BRACKET                    {
                                                                    cout << FMT_FG_YELLOW
                                                                            << "PARSER array: | symbol=\"" << $1 << "\" OPEN_BRACKET NUMERIC_LITERAL=\"" << $3 << "\" CLOSE_BRACKET"
                                                                        << FMT_RESET << endl;;
                                                                    $$=$1;
                                                                }
                                                                ;

/**
 * @name params
 * @brief params (i.e. $x, $y, $x)
 */
params:
        param                                                   {
                                                                    cout << "PARSER params: | param\n" << endl;
                                                                }
        | params symbol                                         {
                                                                    cout << FMT_FG_YELLOW << "PARSER qualafied_id: | params COMMA symbol" << FMT_RESET << endl;
                                                                }
                                                                ;


/**
 * @name param
 * @brief param (i.e. $x, )
 */
param:
        symbol COMMA                                            {
                                                                    cout << FMT_FG_YELLOW << "PARSER param: | symbol" << FMT_RESET << endl;
                                                                }
                                                                ;

/**
 * @name symbol
 */
symbol:
    DOLLAR_SIGN IDENTIFIER                                     {
                                                                    cout << FMT_FG_YELLOW << "PARSER symbol: | IDENTIFIER=\"" << $2 << "\"" << FMT_RESET << endl;
                                                                    $$=$2;
                                                               }
    | CONST_ID                                                 {
                                                                    cout << FMT_FG_YELLOW << "PARSER symbol: | CONST_ID=\"" << $1 << "\"" << FMT_RESET << endl;;
                                                                    $$=$1;
                                                               }
                                                               ;

/**
 *   @name modifier
 */
modifier:
    CAPITALIZE                                                  {
                                                                    cout << "PARSER modifier: | CAPITALIZE\n";
                                                                }
    | CAT                                                       {
                                                                    cout  << "PARSER modifier: | CAT\n";
                                                                }
    | COUNT_CHARACTERS                                          {
                                                                    cout  << "PARSER modifier: | COUNT_CHARACTERS\n";
                                                                }
    | COUNT_SENTENCES                                           {
                                                                    cout  << "PARSER modifier: | COUNT_SENTENCES\n";
                                                                }
   | COUNT_PARAGRAPHS                                           {
                                                                    cout  << "PARSER modifier: | COUNT_PARAGRAPHS\n";
                                                                }
    | COUNT_WORDS                                               {
                                                                cout  << "PARSER modifier: | COUNT_WORDS\n";
                                                                }
    | DATE_FORMAT                                               {
                                                                    cout  << "PARSER modifier: | DATE_FORMAT\n";
                                                                }
    | DEFAULT                                                   {
                                                                    cout  << "PARSER modifier: | DEFAULT\n";
                                                                }
    | ESCAPE                                                    {
                                                                    cout  << "PARSER modifier: | ESCAPE\n";
                                                                }
    | INDENT                                                    {
                                                                    cout  << "PARSER modifier: | INDENT\n";
                                                                }
    | STRIP                                                     {
                                                                    cout  << "PARSER modifier: | STRIPS\n";
                                                                }
    | NL2BR                                                     {
                                                                    cout  << "PARSER modifier: | NL2BR\n";
                                                                }
    | REPLACE                                                   {
                                                                    cout  << "PARSER modifier: | REPLACE\n";
                                                                }
    | REGEX_REPLACE                                             {
                                                                    cout  << "PARSER modifier: | REGEX_REPLACE\n";
                                                                }
    | SPACIFY                                                   {
                                                                    cout  << "PARSER modifier: | SPACIFY\n";
                                                                }
    | STRING_FORMAT                                             {
                                                                    cout  << "PARSER modifier: | STRING_FORMAT\n";
                                                                }
    | STRIP_TAGS                                                {
                                                                    cout  << "PARSER modifier: | STIP_TAGS\n";
                                                                }
    | TRUNCATE                                                  {
                                                                    cout  << "PARSER modifier: | TRUNCATE\n";
                                                                }
    | UPPER                                                     {
                                                                    cout  << "PARSER modifier: | UPPER\n";
                                                                }
    | LOWER                                                     {
                                                                    cout  << "PARSER modifier: | LOWER\n";
                                                                }
    | WORDWRAP                                                  {
                                                                    cout  << "PARSER modifier: | WORDWRAP\n";
                                                                }
    ;

/**
 * @name built-in
 */
built_in:
    CONFIG_LOAD attributes                                      {
                                                                    cout << FMT_FG_YELLOW << "PARSER built_in: | CONFIG_LOAD FILE_ATTRIB=\""
                                                                          << $1 << "\" EQUAL STRING_LITERAL=\"$2\""
                                                                         << FMT_RESET << endl;
                                                                }
    | INCLUDE attributes                                        {
                                                                    cout << FMT_FG_YELLOW
                                                                         << "PARSER built_in: | INCLUDE FILE_ATTRIB=\"%s\" EQUAL STRING_LITERAL=\"\""
                                                                         << FMT_RESET << endl;
                                                                }
    | REQUIRE attributes                                        {
                                                                    cout << FMT_FG_YELLOW
                                                                         << "PARSER built_in: | REQUIRE FILE_ATTRIB=\"%s\" EQUAL STRING_LITERAL=\"\""
                                                                         << FMT_RESET << endl;

                                                                }
    | INSERT attributes                                         {
                                                                    cout << FMT_FG_YELLOW
                                                                            << "PARSER built_in: | INSERT FILE_ATTRIB=\"\" EQUAL STRING_LITERAL=\"\""
                                                                         << FMT_RESET << endl;

                                                                }
    | ASSIGN attributes                                         {
                                                                    cout << FMT_FG_YELLOW
                                                                            << "PARSER built_in: | INSERT FILE_ATTRIB=\"\" EQUAL STRING_LITERAL=\"\""
                                                                         << FMT_RESET << endl;
                                                                }
                                                                ;

/**
 * @name attributes
 */

attributes:
    attrib                                                     {
                                                                    cout << FMT_FG_YELLOW << "PARSER attribute: | attribute={name=\"\"; value=\"\"\n" << FMT_RESET << endl;
                                                               }
    | attributes attrib                                        {
                                                                    cout << FMT_FG_YELLOW
                                                                            << "PARSER attributes: | attribute={name=\"\"; value=\"\"\n"
                                                                         << FMT_RESET << endl;
                                                               }
                                                               ;

/**
 * @name attrib
 */

attrib:
    VALUE_ATTRIB EQUAL_SIGN STRING_LITERAL                          {
                                                                    cout << FMT_FG_YELLOW << "PARSER name_value: | VALUE_ATTRIB=\""
                                                                        << $1 << "\" EQUAL_SIGN STRING_LITERAL=\""
                                                                        << buf << "\"" << FMT_RESET << endl;

                                                                    std::pair<std::string, std::string>  pair($1, $3);
                                                                    $$ = pair;
                                                               }
    | VAR_ATTRIB EQUAL_SIGN STRING_LITERAL                          {
                                                                    cout << FMT_FG_YELLOW
                                                                            << "PARSER name_value: | VAR_ATTRIB=\"\" EQUAL_SIGN STRING_LITERAL=\"\""
                                                                         << FMT_FG_GREEN << FMT_RESET << endl;

                                                                    std::pair<std::string, std::string>  pair($1, $3);
                                                                    $$ = pair;
                                                                }
    | FILE_ATTRIB EQUAL_SIGN STRING_LITERAL                          {
                                                                    cout << FMT_FG_YELLOW
                                                                            << "PARSER name_value: | FILE_ATTRIB=\""
                                                                            << $1 << "\" EQUAL_SIGN STRING_LITERAL=\""
                                                                            << $3 << "\""
                                                                         << FMT_RESET << endl;

                                                                     std::pair<std::string, std::string>  pair($1, $3);
                                                                    $$ = pair;
                                                               }
                                                               ;

%%


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
