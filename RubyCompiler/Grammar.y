%{
#include <stdio.h>
void yyerror(const char* message) {
    fprintf(stderr, message);
}
int yylex();
int yyparse();
extern FILE* yyin;


%}


%%

expr: '=' { puts("Found expr"); }
;

%%

void main(int argc, char **argv ){
	yyin = fopen(argv[1], "r" );

    yyparse();
    return;
}