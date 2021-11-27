%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "calculette.bison.hpp"
%}

%option noyywrap

variable        [a-zA-Z_][a-zA-Z0-9_]*
parameter       \"[a-z][a-z\-]*[a-z]\"
number          [0-9]+(\.[0-9]*)?([Ee][+-]?[0-9]+)?
toskip          \n|\r|\t|\/\/.*

%x    IN_COMMENT

%%
        /* Multiline Comment */
<INITIAL>"/*"                   BEGIN(IN_COMMENT);
<IN_COMMENT>{
"*/"      BEGIN(INITIAL);
[^*\n]+   /* eat comment in chunks */
"*"       /* eat the lone star     */
\n        /* eat newlines */
}

{number}                                                    { 
    char *endptr;
    yylval.dvalue = strtod(yytext, &endptr); return NUM; }
" "                                                         { return ' '; }
{toskip}                                                    {  }
sin                                                         { return SIN; }
cos                                                         { return COS; }
tan                                                         { return TAN; }
arccos                                                      { return ARCCOS; }
arcsin                                                      { return ARCSIN; }
arctan                                                      { return ARCTAN; }
cosh                                                        { return COSH; }
sinh                                                        { return SINH; }
tanh                                                        { return TANH; }
arcosh                                                      { return ARCCOSH; }
arcsinh                                                     { return ARCSINH; }
arctanh                                                     { return ARCTANH; }
log                                                         { return LOG; }
sqrt                                                        { return SQRT; }
\^|\*\*                                                     { return '^'; }
pow                                                         { return POW; }
exp                                                         { return EXP; }
if                                                          { return IF; }
else                                                        { return ELSE; }
for                                                         { return FOR; }
draw                                                        { return DRAW; }
while                                                       { return WHILE; }
in                                                          { return in; }
var                                                         { return var; }
color                                                       { return color; }
label                                                       { return label; }
style                                                       { return style; }
ymin                                                        { return ymin; }
ymax                                                        { return ymax; }
{parameter}                                                 { return PARAM; }
{variable}                                                  { strcpy(yylval.svalue, yytext); return VAR; }
"+="                                                        { return PLUS_EQUAL; }
"-="                                                        { return MIN_EQUAL; }
"*="                                                        { return TIMES_EQUAL; }
"/="                                                        { return DIV_EQUAL; }
"=="                                                        { return EQUAL; }
"!="                                                        { return NOT_EQ; }
"<="                                                        { return INF; }
">="                                                        { return SUP; }
"<"                                                         { return INF_STRICT; }
">"                                                         { return SUP_STRICT; }
"&&"                                                        { return AND; }
"||"                                                        { return OR; }
"="                                                         { return yytext[0]; }
"+"                                                         { return yytext[0]; }
"-"                                                         { return yytext[0]; }
"*"                                                         { return yytext[0]; }
"/"                                                         { return yytext[0]; }
"%"                                                         { return yytext[0]; }
\(                                                          { return '('; }
\)                                                          { return ')'; }
\{                                                          { return '{'; }
\}                                                          { return '}'; }
","                                                         { return ','; }
";"                                                         { return ';'; }
"."                                                         { return '.'; }
<<EOF>>                                                     { printf("Test file contains a valid source code\n"); return EOF; }
.                                                           { printf("lex error : %s\n", yytext); return 0; }

%%

