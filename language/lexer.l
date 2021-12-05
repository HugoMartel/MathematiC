%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "parser.bison.hpp"
%}


/*-----------------
 -- Definitions --
-----------------*/
%option noyywrap

variable        [a-zA-Z_][a-zA-Z0-9_]*
/* /!\ color doesn't support [A-Fa-f0-9]{3} format */
color_arg       \"(blue|red|green|black|white|magenta|cyan|yellow|\#([A-Fa-f0-9]{6}))\"
style_arg       \"(dashed|dotted|solid|hist)\"
string          \"[a-zA-Z0-9\-\+\/\*\(\)\[\]\{\}\ \&\~\#\^\@\=\$\%\!\,\.\:\>\<]+\"
number          [+-]?[0-9]+(\.[0-9]*)?([Ee][+-]?[0-9]+)?
toskip          \n|\r|\t|\ |\/\/.*

/* Used to track line information */
%x    IN_COMMENT


/*---------------
 --   Rules   --
---------------*/
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
    yylval.dvalue = std::strtod(yytext, &endptr); return NUM;
}
{toskip}                                                    {  }
and                                                         { return AND; }
or                                                          { return OR; }
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
\^                                                          { return '^'; }
pow                                                         { return POW; }
exp                                                         { return EXP; }
if                                                          { return IF; }
else                                                        { return ELSE; }
for                                                         { return FOR; }
draw                                                        { return DRAW; }
while                                                       { return WHILE; }
    /* Reserved Words */
pi                                                          { return PI; }
e                                                           { return E; }
phi                                                         { return PHI; }
in                                                          { return in; }
var                                                         { return var; }
def                                                         { return DEF; }
"=>"                                                        { return arrow; }
return                                                      { return RETURN; }
    /* Draw args */
color                                                       { return color; }
label                                                       { return label; }
style                                                       { return style; }
xmin                                                        { return xmin; }
xmax                                                        { return xmax; }
ymin                                                        { return ymin; }
ymax                                                        { return ymax; }
    /* /!\ copy char * */
{color_arg}                                                 { strcpy(yylval.svalue, yytext); return COLOR_PARAM; }
{style_arg}                                                 { strcpy(yylval.svalue, yytext); return STYLE_PARAM; }
{string}                                                    { strcpy(yylval.svalue, yytext); return STRING; }
{variable}                                                  { strcpy(yylval.svalue, yytext); return VAR; }
    /* Operators */
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
"!"                                                         { return NOT; }
"="                                                         { return '='; }
"+"                                                         { return PLUS; }
"-"                                                         { return MIN; }
"*"                                                         { return TIMES; }
"/"                                                         { return DIV; }
"%"                                                         { return '%'; }
\(                                                          { return '('; }
\)                                                          { return ')'; }
\{                                                          { return '{'; }
\}                                                          { return '}'; }
\[                                                          { return '['; }
\]                                                          { return ']'; }
","                                                         { return ','; }
";"                                                         { return ';'; }
":"                                                         { return ':'; }
<<EOF>>                                                     { printf("File contains a valid source code\n"); return EOF; }
.                                                           { fprintf(stderr, "lex error : %s\n", yytext); return 0; }

%%
