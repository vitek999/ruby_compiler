%option noyywrap
%option never-interactive
%option yylineno

%{
	#include <stdio.h>

    void remove_char_from_str(const char * str, char * dest, char deleted_char);
    int binstr_to_dec(const char * str);
%}

DIGIT [0-9]
HEX_DIGIT [0-9A-Fa-f]
OCT_DIGIT [0-7]
BIN_DIGIT [01]
EXPONENT [eE][+-]?[1-9]{DIGIT}*(_{DIGIT}+)*
NUMBER_ALPHA_UNDERSCOPE [a-zA-Z0-9_]

%x ML_COMMENT
%x STRING

%% 

%{
    int num;
    float real_num;
    char temp1[100];
    char temp2[100];
    char comment[1000];
%}

alias		{ printf("Found ALIAS_KEYWORD\n"); }
and			{ printf("Found AND_KEYWORD\n"); }
begin		{ printf("Found BEGIN_KEYWORD\n"); }
break		{ printf("Found BREAK_KEYWORD\n"); }
case		{ printf("Found CASE_KEYWORD\n"); }
class		{ printf("Found CLASS_KEYWORD\n"); }
def			{ printf("Found DEF_KEYWORD\n"); }
"defined?"	{ printf("Found DEFINED_KEYWORD\n"); }
do			{ printf("Found DO_KEYWORD\n"); }
if			{ printf("Found IF_KEYWORD\n"); }
else		{ printf("Found ELSE_KEYWORD\n"); }
elsif		{ printf("Found ELSIF_KEYWORD\n"); }
end			{ printf("Found END_KEYWORD\n"); }
ensure		{ printf("Found ENSURE_KEYWORD\n"); }
false		{ printf("Found FALSE_KEYWORD\n"); }
for			{ printf("Found FOR_KEYWORD\n"); }
in			{ printf("Found IN_KEYWORD\n"); }
module		{ printf("Found MODULE_KEYWORD\n"); }
next		{ printf("Found NEXT_KEYWORD\n"); }
nil			{ printf("Found NIL_KEYWORD\n"); }
not			{ printf("Found NOT_KEYWORD\n"); }
or			{ printf("Found OR_KEYWORD\n"); }
redo		{ printf("Found REDO_KEYWORD\n"); }
rescue		{ printf("Found RESCUE_KEYWORD\n"); }
retry		{ printf("Found RETRY_KEYWORD\n"); }
return		{ printf("Found RETURN_KEYWORD\n"); }
self		{ printf("Found SELF_KEYWORD\n"); }
super		{ printf("Found SUPER_KEYWORD\n"); }
then		{ printf("Found THEN_KEYWORD\n"); }
true		{ printf("Found TRUE_KEYWORD\n"); }
undef		{ printf("Found UNDEF_KEYWORD\n"); }
unless		{ printf("Found UNLESS_KEYWORD\n"); }
until		{ printf("Found UNTIL_KEYWORD\n"); }
when		{ printf("Found WHEN_KEYWORD\n"); }
while		{ printf("Found WHILE_KEYWORD\n"); }
yield		{ printf("Found YIELD_KEYWORD\n"); }

"+"         { printf("Found ARITHMETIC_PLUS_OP\n"); }   
"-"         { printf("Found ARITHMETIC_MINUS_OP\n"); }
"*"         { printf("Found ARITHMETIC_MUL_OP\n"); }
"/"         { printf("Found ARITHMETIC_DIV_OP\n"); }
"%"         { printf("Found ARITHMETIC_MOD_OP\n"); }
"**"        { printf("Found ARITHMETIC_POW_OP\n"); }

"=="        { printf("Found EQL_OP\n"); }
"!="        { printf("Found NOT_EQL_OP\n"); }
">"         { printf("Found GREATER_OP\n"); }
"<"         { printf("Found LESS_OP\n"); }
">="        { printf("Found GREATER_OR_EQL_OP\n"); }
"<="        { printf("Found LESS_OR_EQL_OP\n"); }
"<=>"       { printf("Found COMB_COMPRASION_OP\n"); }
"==="       { printf("Found CASE_EQL_OP\n"); }
"eql?"      { printf("Found RECEIVER_EQL_OP\n"); }
"equal?"    { printf("Found OBJ_ID_EQL_OP\n"); }

"="         { printf("Found ASSIGN_OP\n"); }
"+="        { printf("Found ADD_ASSIGN_OP\n"); }
"-="        { printf("Found SUB_ASSIGN_OP\n"); }
"*="        { printf("Found MUL_ASSIGN_OP\n"); }
"/="        { printf("Found DIV_ASSIGN_OP\n"); }
"%="        { printf("Found MOD_ASSIGN_OP\n"); }
"**="       { printf("Found POW_ASSIGN_OP\n"); }

"&"         { printf("Found BIN_AND_OP\n"); }
"|"         { printf("Found BIN_OR_OP\n"); }
"^"         { printf("Found BIN_XOR_OP\n"); }
"~"         { printf("Found BIN_ONES_COMPLEMENT_OP\n"); }
"<<"        { printf("Found BIN_LEFT_SHIFT_OP\n"); }
">>"        { printf("Found BIN_RIGHT_SHIFT_OP\n"); }

"&&"        { printf("Found LOGICAL_AND_OP\n"); }
"||"        { printf("Found LOGICAL_OR_OP\n"); }
"!"         { printf("Found LOGICAL_NOT_OP\n"); }

".."        { printf("Found INCLUSIVE_RANGE_OP\n"); }
"..."       { printf("Found EXCLUSIVE_RANGE_OP\n"); }

"("         { printf("Found OPEN_ROUND_BRACKET\n"); }
")"         { printf("Found CLOSE_ROUND_BRACKET\n"); }
"{"         { printf("Found OPEN_CURLY_BRACKET\n"); }
"}"         { printf("Found CLOSE_CURLY_BRACKET\n"); }
"["         { printf("Found OPEN_SQUARE_BRACKET\n"); }
"]"         { printf("Found CLOSE_SQUARE_BRACKET\n"); }
"<"         { printf("Found OPEN_ANGLE_BRACKET\n"); }
">"         { printf("Found CLOSE_ANGLE_BRACKET\n"); }
"@"         { printf("Found COMMERCIAL_AT\n"); }

"."         { printf("Found DOT SYMBOL\n"); }
","         { printf("Found COMMA SYMBOOL\n"); }
":"         { printf("Found COLON SYMBOL\n"); }
";"         { printf("Found SEMICOLON SYMBOL\n"); }

0|[1-9]{DIGIT}*(_{DIGIT}+)*          { 
                                remove_char_from_str(yytext,temp1,'_');
                                num = atoi(temp1);
                                printf("Found decimal number %d\n", num);
                             }
0[dD][1-9]{DIGIT}*(_{DIGIT}+)*        {
                                remove_char_from_str(yytext+2,temp1,'_');
                                num = atoi(temp1);
                                printf("Found decimal number %d\n", num);              
                             }

0[oO]?{OCT_DIGIT}+(_{OCT_DIGIT}+)*    {
                                        remove_char_from_str(yytext,temp1,'_');
                                        remove_char_from_str(temp1,temp2,'o');
                                        remove_char_from_str(temp2,temp1,'O');
                                        sscanf(temp1,"%o",&num);
                                        printf("Found octal number %d\n", num);
                                     }
0[xX]{HEX_DIGIT}+(_{HEX_DIGIT}+)*    {
                                        remove_char_from_str(yytext + 2,temp1,'_');
                                        sscanf(temp1,"%x",&num);
                                        printf("Found hex number %d\n", num);
                                    }
0[bB]{BIN_DIGIT}+(_{BIN_DIGIT}+)*   {
                                        remove_char_from_str(yytext + 2,temp1,'_');
                                        num = binstr_to_dec(temp1);
                                        printf("Found binary number %d\n", num); 
                                    }

(0|[1-9](_?{DIGIT})*)(\.{DIGIT}+(_{DIGIT}+)*)?({EXPONENT})?  {
                                                                 remove_char_from_str(yytext,temp1,'_');
                                                                 real_num = atof(temp1);
                                                                 printf("Found float number %f\n", real_num); 
                                                            }

#.*             { printf("Found single-line comment: %s\n", yytext + 1); }

^=begin                         { 
                                    // printf("Foun start ml-comment");
                                    comment[0] = 0; 
                                    BEGIN(ML_COMMENT);
                                }

<ML_COMMENT>^=end.*             {
                                    strcat(comment, yytext + 5);
                                    printf("Found multi-line comment: %s\n", comment);
                                    BEGIN(INITIAL);
                                }

<ML_COMMENT>.*                  { 
                                    strcat(comment, yytext); 
                                }

[a-z_]{NUMBER_ALPHA_UNDERSCOPE}*             {
                                                printf("Found local variable or method name %s\n", yytext);
                                             }
\@[a-z_]{NUMBER_ALPHA_UNDERSCOPE}*                      {
                                                             printf("Found instance variable %s\n", yytext);
                                                        }
\@\@[a-z_]{NUMBER_ALPHA_UNDERSCOPE}*         {
                                                 printf("Found class variable %s\n", yytext);
                                             }

[A-Z]{NUMBER_ALPHA_UNDERSCOPE}*            {
                                                printf("Found class name %s\n", yytext);
                                           }

\n      { //printf("Found new line\n"); 
        }
%% 

void remove_char_from_str(const char * str, char * dest, char deleted_char) {
	int j = 0;
	
    for(int i = 0; str[i] != 0; i++) {
        if(str[i] != deleted_char) {
            dest[j++] = str[i];
        }
    }

    dest[j] = 0;
}

int binstr_to_dec(const char * str) {
    unsigned char *p = str;
    unsigned int   r = 0;

    while (p && *p ) {
        r <<= 1;
        r += (unsigned int)((*p++) & 0x01);
    }

    return (int) r;
}

void main(int argc, char **argv ){
	yyin = fopen(argv[1], "r" );

    yylex();
    return;
}
