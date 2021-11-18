%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    #include <string>
    #include <map>
    extern int yylex();
    extern FILE *yyin;
    extern char *yytext;
    int yyerror(char *s);
    std::map<std::string,float> floatVars;
    std::map<std::string,int> intVars;

    #define DOUBLE dvalue
    #define STRING svalue
    #define BOOL bvalue
%}


%union {
    double dvalue;
    char svalue[50];
    bool bvalue;
}

%type <DOUBLE> expr
%type <DOUBLE> instruction
%type <BOOL> logic

/* Functions & instructions*/
%token <DOUBLE> NUM
%token <DOUBLE> SIN
%token <DOUBLE> COS
%token <DOUBLE> POW
%token <STRING> VAR
%token <BOOL> FOR
%token <BOOL> IF
%token <BOOL> ELSE
%token TAN
%token ARCOS
%token ARCSIN
%token ARCTAN
%token HCOS
%token HSIN
%token HTAN
%token DRAW
%token WHILE
%token SWITCH
%token CASE
%token BREAK
%token DRAWPARAM

/* Operators */
%token <DOUBLE> PLUS_EQUAL
%token <DOUBLE> MIN_EQUAL
%token <DOUBLE> TIMES_EQUAL
%token <DOUBLE> DIV_EQUAL
%token <DOUBLE> OR_EQUAL
%token <DOUBLE> AND_EQUAL

/* Logic bools */
%token <BOOL> EQUAL
%token <BOOL> NOT_EQ
%token <BOOL> INF_STRICT
%token <BOOL> SUP_STRICT
%token <BOOL> INF
%token <BOOL> SUP
%token <BOOL> AND
%token <BOOL> OR
%token <BOOL> NOT


/* Define operators priority */
%left '+' '-'
%left '*' '/'
%right '^'
%right '='

%%

lignes:  /* \epsilon */                 { /* deletes */ }
      | lignes instruction '\n'         {}


instruction: /* \epsilon */             {}
           | expr                       { printf("= %g\n", $1);}  
           | IF '(' logic ')' '{' '\n'
                lignes
             '}' ELSE '{' '\n'
                lignes
             '}'                        { printf("if instruction with else\n"); }
           | IF '(' logic ')' '{' '\n'
                lignes
             '}'                        { printf("if instruction\n"); }
           | FOR '(' expr ';' logic ';' expr ')' '{' '\n'
                lignes
             '}'                        { printf("for instruction\n"); }



logic: expr SUP expr        { $$ = $1 >= $3; printf("%g >= %g = %i\n", $1, $3, $$); }
     | expr INF expr        { $$ = $1 >= $3; printf("%g <= %g = %i\n", $1, $3, $$); }
     | expr SUP_STRICT expr { $$ = $1 >= $3; printf("%g > %g = %i\n", $1, $3, $$); }
     | expr INF_STRICT expr { $$ = $1 >= $3; printf("%g < %g = %i\n", $1, $3, $$); }
     | expr EQUAL expr      { $$ = $1 >= $3; printf("%g == %g = %i\n", $1, $3, $$); }
     | expr NOT_EQ expr     { $$ = $1 >= $3; printf("%g != %g = %i\n", $1, $3, $$); }
     | expr AND expr        { $$ = $1 >= $3; printf("%g && %g = %i\n", $1, $3, $$); }
     | expr OR expr         { $$ = $1 || $3; printf("%g || %g = %i\n", $1, $3, $$); }


expr: NUM                   { $$ = $1; }
    | SIN '(' expr ')'      { $$ = sin($3); printf("sin(%g) = %g\n", $3, $$); }
    | COS '(' expr ')'      { $$ = cos($3); printf("cos(%g) = %g\n", $3, $$); }
    | '(' expr ')'          { $$ = $2; }
    | expr '+' expr         { $$ = $1 + $3; printf("%g + %g = %g\n", $1, $3, $$); }
    | expr '-' expr         { $$ = $1 - $3; printf("%g - %g = %g\n", $1, $3, $$); }
    | expr '*' expr         { $$ = $1 * $3; printf("%g * %g = %g\n", $1, $3, $$); }
    | expr '/' expr         { $$ = $1 / $3; printf("%g / %g = %g\n", $1, $3, $$); }
    | expr '&' expr         { int tmp1 = (int)$1;
                              int tmp2 = (int)$3;
                              $$ = tmp1 & tmp2; 
                              printf("%d & %d = %d\n", tmp1, tmp2, (int)$$); }
    | expr '|' expr         { int tmp1 = (int)$1; 
                              int tmp2 = (int)$3; 
                              $$ = tmp1 | tmp2; 
                              printf("%d | %d = %d\n", tmp1, tmp2, (int)$$); 
                            }
    | expr '^' expr         { $$ = pow($1,$3); printf("%g^%g = %g\n", $1, $3, $$); }
    | POW '(' expr ',' expr ')'      { $$ = pow($1,$3); printf("%g^%g = %g\n", $1, $3, $$); }
    | VAR                   {
    if (floatVars.count($1)) {
        $$ = floatVars.at($1);
        printf("Retrieved %g from the variable %s\n", $$, $1);
    } else if (intVars.count($1)) {
        $$ = intVars.at($1);
        printf("Retrieved %g from the variable %s\n", $$, $1);
    } else {
        $$ = 0;
        printf("Using uninitialized variable %s...\n", $1);
    }
}
    | VAR '=' expr               {
    $$ = $3;

    if (trunc($3) == $3)
        intVars[$1] = int($3);
    else 
        floatVars[$1] = float($3);

    printf("%s <- %g\n", $1, $3);
}

    | VAR PLUS_EQUAL expr        {
    float tmp;

    /* Retrieve value from variable */
    if (floatVars.count($1)) {
        tmp = floatVars.at($1) + $3;
        printf("%s += %g (float)\n", $1, $3);
    } else if (intVars.count($1)) {
        tmp = intVars.at($1) + $3;
        printf("%s += %g (int)\n", $1, $3);
    } else {
        printf("Using uninitialized variable %s...\n", $1);
    }
     
    /* Output */
    $$ = tmp;

    if (trunc(tmp) == tmp) 
        intVars[$1] = int(tmp);
    else 
        floatVars[$1] = float(tmp);
}

    | VAR MIN_EQUAL expr        {
    float tmp;

    /* Retrieve value from variable */
    if (floatVars.count($1)) {
        tmp = floatVars.at($1) - $3;
        printf("%s -= %g (float)\n", $1, $3);
    } else if (intVars.count($1)) {
        tmp = intVars.at($1) - $3;
        printf("%s -= %g (int)\n", $1, $3);
    } else {
        printf("Using uninitialized variable %s...\n", $1);
    }
     
    /* Output */
    $$ = tmp;

    if (trunc(tmp) == tmp) 
        intVars[$1] = int(tmp);
    else 
        floatVars[$1] = float(tmp);
}

    | VAR TIMES_EQUAL expr        {
    float tmp;

    /* Retrieve value from variable */
    if (floatVars.count($1)) {
        tmp = floatVars.at($1) * $3;
        printf("%s *= %g (float)\n", $1, $3);
    } else if (intVars.count($1)) {
        tmp = intVars.at($1) * $3;
        printf("%s *= %g (int)\n", $1, $3);
    } else {
        printf("Using uninitialized variable %s...\n", $1);
    }
     
    /* Output */
    $$ = tmp;

    if (trunc(tmp) == tmp) 
        intVars[$1] = int(tmp);
    else 
        floatVars[$1] = float(tmp);
}

    | VAR DIV_EQUAL expr        {
    float tmp;

    /* Retrieve value from variable */
    if (floatVars.count($1)) {
        tmp = floatVars.at($1) / $3;
        printf("%s /= %g (float)\n", $1, $3);
    } else if (intVars.count($1)) {
        tmp = intVars.at($1) / $3;
        printf("%s /= %g (int)\n", $1, $3);
    } else {
        printf("Using uninitialized variable %s...\n", $1);
    }
     
    /* Output */
    $$ = tmp;

    if (trunc(tmp) == tmp) 
        intVars[$1] = int(tmp);
    else 
        floatVars[$1] = float(tmp);
}

    | VAR OR_EQUAL expr        {
    if ($3 != trunc($3)) {
        printf("Using binary operator with not binary values...");
    } else {
        int tmp = $3;
    
        /* Retrieve value from variable */
        if (intVars.count($1)) {
            intVars[$1] |= tmp;
            printf("%s |= %g\n", $1, $3);
            /* Output */
            $$ = intVars.at($1);
        } else {
            printf("Using unitialized variable %s",$1);
        }
    }
}
     
%%

int yyerror(char *s)
{
    printf("%s : %s\n", s, yytext);
    return EXIT_SUCCESS;
}


/*
    MAIN
*/
int main(int argc, char* argv[])
{
    printf("Calculatrice V0.0001\n");
    if (argc > 1) {
        yyin = fopen(argv[1], "r");

        if (!yyin) {
            printf("Error opening the provided file... (%s)", argv[1]);
            return 1;
        }
    
        yyparse();

        if (fclose(yyin))
            return 2;
    } else {
        yyin = stdin;
        yyparse();
    }

    yyparse();

    return EXIT_SUCCESS;
}

