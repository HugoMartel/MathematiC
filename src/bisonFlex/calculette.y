%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    #include <string>
    #include <map>
    #include <vector>
    #include <iostream>
    using namespace std;
    extern int yylex();
    extern FILE *yyin;
    extern char *yytext;
    int yyerror(char *s);
    map<string,float> floatVars;
    

    #define DOUBLE dvalue
    #define STRING svalue
    #define BOOL bvalue
    #define ADDRESS adresse

class instruction{
    public:
        instruction (const int &c, const double &v=0, const string &n="") {code = c; value = v; name = n;};  
        int code; 
        double value;     // éventuellement une valeur si besoin
        string name;      // ou une référence pour la table des données 
    };

  // Structure pour accueillir le code généré 
  // (sone de code ou code machine ou assembleur)
    vector <instruction> code_genere;

  // Déclaration de la map qui associe
  // les noms des variables à leur valeur
  // (La table de symboles)
  map<string,double> variables;
  int ic = 0;

  // Remarquez les paramètres par défaut pour faciliter les appels depuis la grammaire
  int add_instruction(const int &c, const double &v=0, const string &n="") {
      code_genere.push_back(instruction(c,v,n)); 
      ic++;
      return 0; 
   }; 
%}

%code requires
  {
    typedef struct adr {
        int jmp;  // adresse du jmp
        int jc;  // adrese  du jc
    } type_adresse;
  }

%union {
    double dvalue;
    char svalue[50];
    bool bvalue;
    type_adresse adresse;
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
%token <ADDRESS> FOR
%token <ADDRESS> IF
%token <ADDRESS> ELSE
%token <ADDRESS> WHILE
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
%token <BOOL> JMP
%token <BOOL> JMPCOND

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
           | IF logic '{' '\n'          { // Je sauvegarde l'endroit actuel pour revenir mofifier l'adresse 
                                          // lorsqu'elle sera connue (celle du JC)
                                          $1.jc = ic;
                                          add_instruction(JMPCOND);  }
                lignes                  { // Je sauvegarde l'endroit actuel pour revenir mofifier l'adresse 
                                          // lorsqu'elle sera connue (celle du JMP)
                                          $1.jmp = ic;
                                          add_instruction(JMP);
                                          // Je mets à jour l'adresse du saut conditionnel
                                          code_genere[$1.jc].value = ic;
                                        }
             '}' ELSE '{' '\n'
                lignes              
             '}'                        { // Je mets à jour l'adresse du saut inconditionnel
                                          code_genere[$1.jmp].value = ic; }
           | FOR expr '[' expr ':' expr ':' expr ']' '{' '\n'
                lignes
             '}'                        { add_instruction(FOR); }
           | WHILE logic '{' '\n'
                lignes
             '}'                        { add_instruction(WHILE); }
            

logic: expr SUP expr        { add_instruction(SUP); }
     | expr INF expr        { add_instruction(INF); }
     | expr SUP_STRICT expr { add_instruction(SUP_STRICT); }
     | expr INF_STRICT expr { add_instruction(INF_STRICT); }
     | expr EQUAL expr      { add_instruction(EQUAL); }
     | expr NOT_EQ expr     { add_instruction(NOT_EQ); }
     | expr AND expr        { add_instruction(AND); }
     | expr OR expr         { add_instruction(OR); }


expr: NUM                   { add_instruction(NUM, $1); }
    | SIN '(' expr ')'      { add_instruction(SIN); }
    | COS '(' expr ')'      { add_instruction(COS); }
    | TAN '(' expr ')'      { add_instruction(TAN); }
    | ARCOS '(' expr ')'    { add_instruction(ARCOS); }
    | ARCSIN '(' expr ')'   { add_instruction(ARCSIN); }
    | ARCTAN '(' expr ')'   { add_instruction(ARCTAN); }
    | SINH '(' expr ')'     { add_instruction(SINH); }
    | COSH '(' expr ')'     { add_instruction(COSH); }
    | TANH '(' expr ')'     { add_instruction(TANH); }
    | ARCOSH '(' expr ')'   { add_instruction(ARCOSH); }
    | ARCSINH '(' expr ')'  { add_instruction(ARCSINH); }
    | ARCTANH '(' expr ')'  { add_instruction(ARCTANH); }
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
    | POW '(' expr ',' expr ')'  { add_instruction(POW); }
    | EXP '(' expr ')'      { add_instruction(EXP);  }
    | LOG '(' expr ')'      { add_instruction(LOG);  }
    | SQRT '(' expr ')'     { add_instruction(SQRT);  }
    | VAR                   { add_instruction (VAR, 0, $1); }
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

// Fonction pour mieux voir le code généré 
// (au lieu des nombres associés au tokens)
string print_code(int ins) {
  switch (ins) {
    case IF      : return "IF";
    case ELSE      : return "ELSE";
    case FOR      : return "FOR";
    case WHILE      : return "WHILE";
    case SUP      : return "SUP";
    case INF      : return "INF";
    case SUP_STRICT    : return "SUP_STRICT";
    case INF_STRICT     : return "INF_STRICT";
    case EQUAL      : return "EQUAL";
    case NOT_EQ      : return "NOT_EQ";
    case AND      : return "AND";
    case OR      : return "OR";
    case NUM      : return "NUM";
    case SIN      : return "SIN";
    case COS      : return "COS";
    case TAN      : return "TAN";
    case ARCOS      : return "ARCOS";
    case ARCSIN      : return "ARCSIN";
    case ARCTAN      : return "ARCTAN";
    case SINH      : return "SINH";
    case COSH      : return "COSH";
    case TANH      : return "TANH";
    case ARCOSH      : return "ARCOSH";
    case ARCSINH      : return "ARCSINH";
    case ARCTANH      : return "ARCTANH";
    case POW      : return "POW";
    case EXP      : return "EXP";
    case LOG      : return "LOG";
    case SQRT      : return "SQRT";
    case VAR      : return "VAR";
    case JMP      : return "JMP";
    case JMPCOND  : return "JC ";
    default : return "";
  }
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

    // boucle d'affichage du tableau contenant tout le programme
    for (int i = 0; i < code_genere.size(); i++){
    auto instruction = code_genere [i];
    cout << i 
         << '\t'
         << print_code(instruction.code) 
         << '\t'
         << instruction.value 
         << '\t' 
         << instruction.name 
         << endl;
    }

    

    yyparse();

    return EXIT_SUCCESS;
}

