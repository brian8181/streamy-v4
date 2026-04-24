%token IF THEN ELSE expr
%%
stmt       : matched_stmt
           | unmatched_stmt
           ;

matched_stmt : IF expr THEN matched_stmt ELSE matched_stmt
             | expr
             ;

unmatched_stmt : IF expr THEN stmt
               ;
%%
