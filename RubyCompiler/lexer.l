%option noyywrap
%option never-interactive
%option yylineno

%{
	#include <stdio.h>
    #include "Grammar.tab.h"

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
    char string[1000];
    int nestingCount = 0;
%}

alias		{ return ALIAS_KEYWORD; }
and			{ return AND_KEYWORD; }
begin		{ return BEGIN_KEYWORD; }
break		{ return BREAK_KEYWORD; }
case		{ return CASE_KEYWORD; }
class		{ return CLASS_KEYWORD; }
def			{ return DEF_KEYWORD; }
"defined?"	{ return DEFINED_KEYWORD; }
do			{ return DO_KEYWORD; }
if			{ return IF_KEYWORD; }
else		{ return ELSE_KEYWORD; }
elsif		{ return ELSIF_KEYWORD; }
end			{ return END_KEYWORD; }
ensure		{ return ENSURE_KEYWORD; }
false		{ return FALSE_KEYWORD; }
for			{ return FOR_KEYWORD; }
in			{ return IN_KEYWORD; }
module		{ return MODULE_KEYWORD; }
next		{ return NEXT_KEYWORD; }
nil			{ return NIL_KEYWORD; }
not			{ return NOT_KEYWORD; }
or			{ return OR_KEYWORD; }
redo		{ return REDO_KEYWORD; }
rescue		{ return RESCUE_KEYWORD; }
retry		{ return RETRY_KEYWORD; }
return		{ return RETURN_KEYWORD; }
self		{ return SELF_KEYWORD; }
super		{ return SUPER_KEYWORD; }
then		{ return THEN_KEYWORD; }
true		{ return TRUE_KEYWORD; }
undef		{ return UNDEF_KEYWORD; }
unless		{ return UNLESS_KEYWORD; }
until		{ return UNTIL_KEYWORD; }
when		{ return WHEN_KEYWORD; }
while		{ return WHILE_KEYWORD; }
yield		{ return YIELD_KEYWORD; }

"+"         { return ARITHMETIC_PLUS_OP; }   
"-"         { return ARITHMETIC_MINUS_OP; }
"*"         { return ARITHMETIC_MUL_OP; }
"/"         { return ARITHMETIC_DIV_OP; }
"%"         { return ARITHMETIC_MOD_OP; }
"**"        { return ARITHMETIC_POW_OP; }

"=="        { return EQL_OP; }
"!="        { return NOT_EQL_OP; }
">"         { return GREATER_OP; }
"<"         { return LESS_OP; }
">="        { return GREATER_OR_EQL_OP; }
"<="        { return LESS_OR_EQL_OP; }
"<=>"       { return COMB_COMPRASION_OP; }
"==="       { return CASE_EQL_OP; }
"eql?"      { return RECEIVER_EQL_OP; }
"equal?"    { return OBJ_ID_EQL_OP; }

"="         { return ASSIGN_OP; }
"+="        { return ADD_ASSIGN_OP; }
"-="        { return SUB_ASSIGN_OP; }
"*="        { return MUL_ASSIGN_OP; }
"/="        { return DIV_ASSIGN_OP; }
"%="        { return MOD_ASSIGN_OP; }
"**="       { return POW_ASSIGN_OP; }

"&"         { return BIN_AND_OP; }
"|"         { return BIN_OR_OP; }
"^"         { return BIN_XOR_OP; }
"~"         { return BIN_ONES_COMPLEMENT_OP; }
"<<"        { return BIN_LEFT_SHIFT_OP; }
">>"        { return BIN_RIGHT_SHIFT_OP; }

"&&"        { return LOGICAL_AND_OP; }
"||"        { return LOGICAL_OR_OP; }
"!"         { return LOGICAL_NOT_OP; }

".."        { return INCLUSIVE_RANGE_OP; }
"..."       { return EXCLUSIVE_RANGE_OP; }

"("         { return OPEN_ROUND_BRACKET; }
")"         { return CLOSE_ROUND_BRACKET; }
"{"         { return OPEN_CURLY_BRACKET; }
"}"         {
                if(nestingCount == 0) {
                    return CLOSE_CURLY_BRACKET;
                } else {
                    nestingCount--;
                    BEGIN(STRING);
                    string[0] = 0;
                    return ARITHMETIC_PLUS_OP;
                }
            }
"["         { return OPEN_SQUARE_BRACKET; }
"]"         { return CLOSE_SQUARE_BRACKET; }
"@"         { return COMMERCIAL_AT; }

"?"         { return QUESTION_SYMBOL; }

"."         { return DOT_SYMBOL; }
","         { return COMMA_SYMBOL; }
":"         { return COLON_SYMBOL; }
"::"        { return DOUBLE_COLON_SYMBOL;}
";"         { return SEMICOLON_SYMBOL; }

\"          { 
                string[0] = 0; 
                BEGIN(STRING);    
            }

<STRING>"#{"        { 
                        printf("Found string %s\n", string);
                        printf("Found ARITHMETIC_PLUS_OP\n");
                        nestingCount++;
                        BEGIN(INITIAL);
                    }
<STRING>[^\\\"\n#{}]+ { strcat(string, yytext); }
<STRING>[#{}]      { strcat(string, yytext); }
<STRING>\\n        { strcat(string, "\n"); }
<STRING>\\a        { strcat(string, "\a"); }
<STRING>\\b        { strcat(string, "\b"); }
<STRING>\\t        { strcat(string, "\t"); }
<STRING>\\v        { strcat(string, "\v"); }
<STRING>\\f        { strcat(string, "\f"); }
<STRING>\\r        { strcat(string, "\r"); }
<STRING>\\e        { strcat(string, "\e"); }
<STRING>\\s        { strcat(string, " "); }
<STRING>\\\\       { strcat(string, "\\"); }
<STRING>\\\"       { strcat(string, "\""); }
<STRING>\\{OCT_DIGIT}{1,3} { 
                                sscanf(yytext + 1, "%o", &num);
                                temp1[0] = (char) num;
                                temp1[1] = 0;
                                strcat(string, temp1);
                            }

<STRING>\\x{HEX_DIGIT}{1,2} { 
                                sscanf(yytext + 2, "%x", &num);
                                temp1[0] = (char) num;
                                temp1[1] = 0;
                                strcat(string, temp1);
                            }
<STRING>\\x[^0-9A-Fa-f\n"}]*       { printf("ERROR: Invalid hex escape \n"); }

<STRING>\" { 
                /* printf("Found string %s \n", string); */
                yylval.string_un=(char *)malloc(strlen(string)+1);
                strcpy(yylval.string_un, string);
                BEGIN(INITIAL);
                return STR;
            }
<STRING><<EOF>> { printf("ERROR: expected\" \n"); }

0|[1-9]{DIGIT}*(_{DIGIT}+)*          { 
                                remove_char_from_str(yytext,temp1,'_');
                                yylval.int_un = atoi(temp1);
                                return INTEGER_NUMBER;
                             }

[1-9](_*{DIGIT}+)*_*   { printf("Found decimal number error1 %s\n", yytext); }

0[dD][1-9]{DIGIT}*(_{DIGIT}+)*        {
                                remove_char_from_str(yytext+2,temp1,'_');
                                yylval.int_un = atoi(temp1);
                                return INTEGER_NUMBER;              
                             }

0_*[dD]_*[1-9](_*{DIGIT}+)*_* { printf("Found decimal number error2 %s\n", yytext); }

0[oO]?{OCT_DIGIT}+(_{OCT_DIGIT}+)*    {
                                        remove_char_from_str(yytext,temp1,'_');
                                        remove_char_from_str(temp1,temp2,'o');
                                        remove_char_from_str(temp2,temp1,'O');
                                        sscanf(temp1,"%o",&num);
                                        yylval.int_un = num;
                                        return INTEGER_NUMBER;
                                     }

0_*[oO]?_*{OCT_DIGIT}(_*{OCT_DIGIT}+)*_* { printf("Found oct number error %s\n", yytext); }

0[xX]{HEX_DIGIT}+(_{HEX_DIGIT}+)*    {
                                        remove_char_from_str(yytext + 2,temp1,'_');
                                        sscanf(temp1,"%x",&num);
                                        yylval.int_un = num;
                                        return INTEGER_NUMBER;
                                    }

0_*[xX]_*{HEX_DIGIT}(_*{HEX_DIGIT}+)*_* { printf("Found hex number error %s\n", yytext); }

0[bB]{BIN_DIGIT}+(_{BIN_DIGIT}+)*   {
                                        remove_char_from_str(yytext + 2,temp1,'_');
                                        num = binstr_to_dec(temp1);
                                        yylval.int_un = num;
                                        return INTEGER_NUMBER; 
                                    }

0_*[bB]_*{BIN_DIGIT}(_*{BIN_DIGIT}+)*_* { printf("Found bin number error %s\n", yytext); }



(0|[1-9](_?{DIGIT})*)(\.{DIGIT}+(_{DIGIT}+)*)?({EXPONENT})?  {
                                                                 remove_char_from_str(yytext,temp1,'_');
                                                                 real_num = atof(temp1);
                                                                 return FLOAT_NUMBER; 
                                                            }

([1-9]*_*(\.|\.{4,})_*{DIGIT}+)+(_*{DIGIT}*)*     { printf("Found float number error1 %s\n", yytext); }

([1-9]+((_|\.)*{DIGIT}*)*[Ee]+((_|\.)*{DIGIT}*)*)+     { printf("Found float number error2 %s\n", yytext); }



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
                                                yylval.string_un=(char *)malloc(strlen(yytext)+1);
                                                strcpy(yylval.string_un, yytext); 
                                                return VAR_METHOD_NAME;
                                             }
\@[a-z_]{NUMBER_ALPHA_UNDERSCOPE}*                      {
                                                             yylval.string_un=(char *)malloc(strlen(yytext)+1);
                                                             strcpy(yylval.string_un, yytext); 
                                                             return INSTANCE_VAR_NAME;
                                                        }
\@\@[a-z_]{NUMBER_ALPHA_UNDERSCOPE}*         {
                                                 return CLASS_VAR_NAME;
                                             }

[A-Z]{NUMBER_ALPHA_UNDERSCOPE}*            {
                                                return CLASS_NAME;
                                           }

\n      { return NEW_LINE_SYMBOL;
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

