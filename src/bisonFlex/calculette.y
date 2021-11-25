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
%token <DOUBLE> EXP
%token <STRING> VAR
%token <BOOL> FOR
%token <BOOL> IF
%token <BOOL> ELSE
%token <DOUBLE> WHILE
%token <DOUBLE> TAN
%token <DOUBLE> ARCOS
%token <DOUBLE> ARCSIN
%token <DOUBLE> ARCTAN
%token <DOUBLE> COSH
%token <DOUBLE> SINH
%token <DOUBLE> TANH
%token <DOUBLE> ARCSINH
%token <DOUBLE> ARCOSH
%token <DOUBLE> ARCTANH
%token <DOUBLE> SQRT
%token <DOUBLE> LOG
%token DRAWPARAM
%token DRAW

/* Operators */
%token <DOUBLE> PLUS_EQUAL
%token <DOUBLE> MIN_EQUAL
%token <DOUBLE> TIMES_EQUAL
%token <DOUBLE> DIV_EQUAL

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
           | IF logic '{' '\n'
                lignes
             '}' ELSE '{' '\n'
                lignes
             '}'                        { printf("if instruction with else\n"); }
           | IF logic '{' '\n'
                lignes
             '}'                        { printf("if instruction\n"); }
           | FOR expr '[' expr ':' expr ':' expr ']' '{' '\n'
                lignes
             '}'                        { printf("for instruction\n"); }
           | WHILE logic '{' '\n'
                lignes
             '}'                        { printf("while instruction\n"); }
            

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
    | TAN '(' expr ')'      { $$ = tan($3); printf("tan(%g) = %g\n", $3, $$); }
    | ARCOS '(' expr ')'    { $$ = acos($3); printf("acos(%g) = %g\n", $3, $$); }
    | ARCSIN '(' expr ')'   { $$ = asin($3); printf("asin(%g) = %g\n", $3, $$); }
    | ARCTAN '(' expr ')'   { $$ = atan($3); printf("atan(%g) = %g\n", $3, $$); }
    | SINH '(' expr ')'     { $$ = sinh($3); printf("sinh(%g) = %g\n", $3, $$); }
    | COSH '(' expr ')'     { $$ = cosh($3); printf("cosh(%g) = %g\n", $3, $$); }
    | TANH '(' expr ')'     { $$ = tanh($3); printf("tanh(%g) = %g\n", $3, $$); }
    | ARCOSH '(' expr ')'   { $$ = acosh($3); printf("acosh(%g) = %g\n", $3, $$); }
    | ARCSINH '(' expr ')'  { $$ = asinh($3); printf("asinh(%g) = %g\n", $3, $$); }
    | ARCTANH '(' expr ')'  { $$ = atanh($3); printf("atanh(%g) = %g\n", $3, $$); }
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
    | POW '(' expr ',' expr ')'  { $$ = pow($1,$3); printf("%g^%g = %g\n", $1, $3, $$); }
    | EXP '(' expr ')'      { $$ = exp($3); printf("exp(%g) = %g\n", $3, $$);  }
    | LOG '(' expr ')'      { $$ = log($3); printf("log(%g) = %g\n", $3, $$);  }
    | SQRT '(' expr ')'     { $$ = sqrt($3); printf("sqrt(%g) = %g\n", $3, $$);  }
    | VAR                   {
    if (floatVars.count($1)) {
        $$ = floatVars.at($1);
        printf("Retrieved %g from the variable %s\n", $$, $1);
    } else {
        $$ = 0;
        printf("Using uninitialized variable %s...\n", $1);
    }
}
    | VAR '=' expr               {
    $$ = $3;

    floatVars[$1] = float($3);

    printf("%s <- %g\n", $1, $3);
}

    | VAR PLUS_EQUAL expr        {
    float tmp;

    /* Retrieve value from variable */
    if (floatVars.count($1)) {
        tmp = floatVars.at($1) + $3;
        printf("%s += %g (float)\n", $1, $3);
    } else {
        printf("Using uninitialized variable %s...\n", $1);
    }
    
    /* Output */
    $$ = tmp;

    floatVars[$1] = float(tmp);
}

    | VAR MIN_EQUAL expr        {
    float tmp;

    /* Retrieve value from variable */
    if (floatVars.count($1)) {
        tmp = floatVars.at($1) - $3;
        printf("%s -= %g (float)\n", $1, $3);
    } else {
        printf("Using uninitialized variable %s...\n", $1);
    }
     
    /* Output */
    $$ = tmp;

    floatVars[$1] = float(tmp);
}

    | VAR TIMES_EQUAL expr        {
    float tmp;

    /* Retrieve value from variable */
    if (floatVars.count($1)) {
        tmp = floatVars.at($1) * $3;
        printf("%s *= %g (float)\n", $1, $3);
    } else {
        printf("Using uninitialized variable %s...\n", $1);
    }
     
    /* Output */
    $$ = tmp;

    floatVars[$1] = float(tmp);
}

    | VAR DIV_EQUAL expr        {
    float tmp;

    /* Retrieve value from variable */
    if (floatVars.count($1)) {
        tmp = floatVars.at($1) / $3;
        printf("%s /= %g (float)\n", $1, $3);
    } else {
        printf("Using uninitialized variable %s...\n", $1);
    }
     
    /* Output */
    $$ = tmp;

    
    floatVars[$1] = float(tmp);
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
    printf("Courbe créateur\n");
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

