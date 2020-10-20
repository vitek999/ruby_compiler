%{
	#include <stdio.h>
	#include <malloc.h>
%}

%%

expr: INT
	| expr '+' expr
	| expr '-' expr
	| expr '*' expr
	| expr '/' expr
	| expr '%' expr
	| expr '**' expr
	| expr '==' expr
	| expr '!=' expr
	| expr '>' expr
	| expr '<' expr
	| expr '>=' expr
	| expr '<=' expr
	| expr '<=>' expr
	| expr '===' expr
	| expr 'eql?' expr
	| expr 'equal?' expr
%%

