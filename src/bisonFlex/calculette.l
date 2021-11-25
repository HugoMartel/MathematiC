%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "calculette.bison.hpp"
%}

%option noyywrap

%%

[0-9]+(\.[0-9]*)?([Ee][+-]?[0-9]+)?                         { yylval.dvalue = atof(yytext); return NUM; }
\n                                                          { return '\n'; }
\r|" "|\t                                                   {}
Sin|SIN|sin|sinus|Sinus|SINUS                               { return SIN; }
Cos|COS|cos|cosinus|Cosinus|COSINUS                         { return COS; }
Tan|TAN|tan                                                 { return TAN; }
Arcos|ARCOS|arcos                                           { return ARCOS; }
Arcsin|ARCSIN|arcsin                                        { return ARCSIN; }
Arctan|ARCTAN|arctan                                        { return ARCTAN; }
Hcos|HCOS|hcos|Cosh|COSH|cosh                               { return COSH; }
Hsin|HSIN|hsin|Sinh|SINH|sinh                               { return SINH; }
Htan|HTAN|htan|Tanh|TANH|sinh                               { return TANH; }
Archcos|ARCHCOS|archcos|Arccosh|ARCCOSH|arcosh              { return ARCOSH; }
Archsin|ARCHSIN|archsin|Arcsinh|ARCSINH|arcsinh             { return ARCSINH; }
Archtan|ARCHTAN|archtan|Arctanh|ARCTANH|arcsinh             { return ARCTANH; }
Log|LOG|log                                                 { return LOG; }
Sqrt|SQRT|sqrt                                              { return SQRT; }
\^|\*\*                                                     { return '^'; } 
pow|POW|Pow                                                 { return POW; }
exp|Exp|EXP                                                 { return EXP; }
if|IF|If                                                    { return IF; }
else|ELSE|Else                                              { return ELSE; }
for|FOR|For                                                 { return FOR; }
draw|Draw|DRAW                                              { return DRAW; }
while|While|WHILE                                           { return WHILE; }
drawParam|DrawParam|drawparam|DRAWPARAM                     { return DRAWPARAM; }
" "                                     {  }
[a-zA-Z_][a-zA-Z0-9_]*                  { strcpy(yylval.svalue, yytext); return VAR; }
"+="                                    { return PLUS_EQUAL; }
"-="                                    { return MIN_EQUAL; }
"*="                                    { return TIMES_EQUAL; }
"/="                                    { return DIV_EQUAL; }
"=="                                    { return EQUAL; }
"!="                                    { return NOT_EQ; }
"<="                                    { return INF; }
">="                                    { return SUP; }
"<"                                     { return INF_STRICT; }
">"                                     { return SUP_STRICT; }
"&&"                                    { return AND; }
"||"                                    { return OR; }
"="                                     { return '='; }
"+"                                     { return yytext[0]; }
"-"                                     { return yytext[0]; }
"*"                                     { return yytext[0]; }
"/"                                     { return yytext[0]; }
"%"                                     { return yytext[0]; }
\(                                      { return '('; }
\)                                      { return ')'; }
\{                                      { return '{'; }
\}                                      { return '}'; }
","                                     { return ','; }
";"                                     { return ';'; }
<<EOF>>                                 { printf("Test file contains a valid source code\n"); return EOF; }
.                                       { printf("lex error : %s\n", yytext); return 0; }

%%

