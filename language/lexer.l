%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string>

    #include "parser.yy.hpp"
    #include "interface.hpp"
%}


/*-----------------
 -- Definitions --
-----------------*/
%option noyywrap nounput
%option yylineno

variable        [a-zA-Z_][a-zA-Z0-9_]*
/* /!\ color doesn't support [A-Fa-f0-9]{3} format */
color_arg       \"(blue|red|green|black|white|magenta|cyan|yellow|\#([A-Fa-f0-9]{6}))\"
style_arg       \"(dashed|dotted|solid|hist)\"
string          \"[a-zA-Z0-9\-\+\/\*\(\)\[\]\{\}\ \&\~\#\^\@\=\$\%\!\,\.\:\>\<]+\"
number          [+-]?[0-9]+(\.[0-9]*)?([Ee][+-]?[0-9]+)?
toskip          \r|\t|\ |\/\/.*

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
\n                                                          { /* flex rule for yylineno++ */ }
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
<<EOF>>                                                     {
                                                                std::string output("File contains a valid source code\n");
                                                                verbose(output, false);/* false since no error */
                                                                return EOF;
                                                            }
.                                                           {
                                                                /* Char not supported in this language */
                                                                char str[150];
                                                                sprintf(str, "%d - Syntax error: %s\n", yylineno, yytext);
                                                                std::string output(str);
                                                                verbose(output, true);
                                                                return 0;
                                                            }

%%
