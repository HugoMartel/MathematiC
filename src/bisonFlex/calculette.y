%{
    #include <cstdio>
    #include <math.h>
    #include <string>
    #include <map>
    #include <vector>
    #include <iostream>
    using namespace std;
    extern int yylex();
    extern FILE *yyin;
    extern char *yytext;
    extern size_t yylineno;
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
    double value;     // eventuellement une valeur si besoin
    std::string name; // ou une référence pour la table des données
};

    // Structure pour accueillir le code généré
    // (sone de code ou code machine ou assembleur)
    vector <instruction> code_genere;

    // Déclaration de la map qui associe
    // les noms des variables à leur valeur
    // (La table de symboles)
    map<std::string,double> variables;
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
%type instruction
%type <BOOL> logic

/* Reserved words */
%token var /* Variable definition */
%token def /* Function definition */
%token in  /* param interval for a given function */
/* Parameters for draw */
%token color
%token style
%token label
%token xmin
%token xmax
%token ymin
%token ymax
%token PARAM /* "value" */

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
%token <DOUBLE> ARCCOS
%token <DOUBLE> ARCSIN
%token <DOUBLE> ARCTAN
%token <DOUBLE> COSH
%token <DOUBLE> SINH
%token <DOUBLE> TANH
%token <DOUBLE> ARCSINH
%token <DOUBLE> ARCCOSH
%token <DOUBLE> ARCTANH
%token <DOUBLE> SQRT
%token <DOUBLE> LOG
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

/* Structure globale d'un programme :
    Déclarations
    Fonctions
    Affichage
*/
code: declarations fonctions affichage                  { /* TODO: print start compiling */ }


declarations: /* \epsilon */                            { /* End of declarations */ }
            | declarations var ' ' VAR '=' expr ';'     { /* Init Vars */
                if (!variables.count($4)) {
                    variables[$4] = $6;
                } else {
                    yyerror("Variable already declared...");
                }
}


fonctions: def ' ' VAR '(' args ')'                     { /* TODO */ }

args: VAR                                               { /* TODO */ }
    | args ',' args                                     { /* TODO */ }


draw_func: VAR ' ' in ' ' '[' NUM '.''.' NUM ']'        { /* TODO */ }
         | VAR                                          { /* TODO */ }
         | draw_func ',' draw_func                      { /* TODO */ }


affichage: DRAW ' ' draw_func '{'   { /*TODO: load funcs*/ }
                draw_args
           '}'
         | DRAW ' ' draw_func ';'   { /* TODO: load default args */}


draw_args: color ':' PARAM               { /*TODO: check PARAM values*/ }
         | style ':' PARAM               { /*TODO: check PARAM values*/ }
         | label ':' PARAM               { /*TODO: check PARAM values*/ }
         | xmin ':' NUM                  { /*TODO*/ }
         | xmin ':' VAR                  { /*TODO*/ }
         | xmax ':' NUM                  { /*TODO*/ }
         | xmax ':' VAR                  { /*TODO*/ }
         | ymin ':' NUM                  { /*TODO*/ }
         | ymin ':' VAR                  { /*TODO*/ }
         | ymax ':' NUM                  { /*TODO*/ }
         | ymax ':' VAR                  { /*TODO*/ }
         | draw_args ',' draw_args       { /*TODO*/ }

/* Example
{
    color: "red",
    style: "dashed"
}
*/


instruction: /* \epsilon */             {}
           | expr ';'                   { printf("= %g\n", $1); }
           | IF logic '{'               {

                // Je sauvegarde l'endroit actuel pour revenir mofifier l'adresse
                // lorsqu'elle sera connue (celle du JC)

                $1.jc = ic;
                add_instruction(JMPCOND);
}
            instruction                 {
                // Je sauvegarde l'endroit actuel pour revenir mofifier l'adresse
                // lorsqu'elle sera connue (celle du JMP)

                $1.jmp = ic;
                add_instruction(JMP);

                // Je mets à jour l'adresse du saut conditionnel
                code_genere[$1.jc].value = ic;
}
             '}' ELSE '{'
            instruction
             '}'                        {
                // Je mets à jour l'adresse du saut inconditionnel
                 code_genere[$1.jmp].value = ic;
}
           | FOR VAR ' ' in ' ' '[' expr ':' expr ':' expr ']' '{'
                instruction
             '}'                        { add_instruction(FOR); }
           | WHILE logic '{'
                instruction
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
    | ARCCOS '(' expr ')'   { add_instruction(ARCCOS); }
    | ARCSIN '(' expr ')'   { add_instruction(ARCSIN); }
    | ARCTAN '(' expr ')'   { add_instruction(ARCTAN); }
    | SINH '(' expr ')'     { add_instruction(SINH); }
    | COSH '(' expr ')'     { add_instruction(COSH); }
    | TANH '(' expr ')'     { add_instruction(TANH); }
    | ARCCOSH '(' expr ')'  { add_instruction(ARCCOSH); }
    | ARCSINH '(' expr ')'  { add_instruction(ARCSINH); }
    | ARCTANH '(' expr ')'  { add_instruction(ARCTANH); }
    | '(' expr ')'          { $$ = $2; }
    | expr '+' expr         { $$ = $1 + $3; printf("%g + %g = %g\n", $1, $3, $$); }
    | expr '-' expr         { $$ = $1 - $3; printf("%g - %g = %g\n", $1, $3, $$); }
    | expr '*' expr         { $$ = $1 * $3; printf("%g * %g = %g\n", $1, $3, $$); }
    | expr '/' expr         { $$ = $1 / $3; printf("%g / %g = %g\n", $1, $3, $$); }
    | expr '&' expr         {
        int tmp1 = (int)$1;
        int tmp2 = (int)$3;
        $$ = tmp1 & tmp2;
        printf("%d & %d = %d\n", tmp1, tmp2, (int)$$);
}
    | expr '|' expr         {
        int tmp1 = (int)$1;
        int tmp2 = (int)$3;
        $$ = tmp1 | tmp2;
        printf("%d | %d = %d\n", tmp1, tmp2, (int)$$);
}
    | expr '^' expr                 { $$ = pow($1,$3); printf("%g^%g = %g\n", $1, $3, $$); }
    | POW '(' expr ',' expr ')'     { add_instruction(POW); }
    | EXP '(' expr ')'              { add_instruction(EXP); }
    | LOG '(' expr ')'              { add_instruction(LOG); }
    | SQRT '(' expr ')'             { add_instruction(SQRT); }
    | VAR                           { add_instruction(VAR, 0, $1); }
    | VAR '=' expr                  {  }
    | VAR PLUS_EQUAL expr           {  }
    | VAR MIN_EQUAL expr            {  }
    | VAR TIMES_EQUAL expr          {  }
    | VAR DIV_EQUAL expr            {  }

%%

int yyerror(char *s)
{
    printf("%i - %s : %s\n", yylineno, s, yytext);
    return EXIT_SUCCESS;
}

// Fonction pour mieux voir le code généré
// (au lieu des nombres associés au tokens)
string print_code(int ins) {
    switch (ins) {
        case IF         : return "IF";
        case ELSE       : return "ELSE";
        case FOR        : return "FOR";
        case WHILE      : return "WHILE";
        case SUP        : return "SUP";
        case INF        : return "INF";
        case SUP_STRICT : return "SUP_STRICT";
        case INF_STRICT : return "INF_STRICT";
        case EQUAL      : return "EQUAL";
        case NOT_EQ     : return "NOT_EQ";
        case AND        : return "AND";
        case OR         : return "OR";
        case NUM        : return "NUM";
        case SIN        : return "SIN";
        case COS        : return "COS";
        case TAN        : return "TAN";
        case ARCCOS     : return "ARCCOS";
        case ARCSIN     : return "ARCSIN";
        case ARCTAN     : return "ARCTAN";
        case SINH       : return "SINH";
        case COSH       : return "COSH";
        case TANH       : return "TANH";
        case ARCCOSH    : return "ARCCOSH";
        case ARCSINH    : return "ARCSINH";
        case ARCTANH    : return "ARCTANH";
        case POW        : return "POW";
        case EXP        : return "EXP";
        case LOG        : return "LOG";
        case SQRT       : return "SQRT";
        case VAR        : return "VAR";
        case JMP        : return "JMP";
        case JMPCOND    : return "JC ";
        case DRAW       : return "DRAW";
        default : return "";
    }
}

/*
    MAIN
*/
int main(int argc, char* argv[])
{
    /* Check file input */
    if (argc > 1) {
        yyin = fopen(argv[1], "r");

        if (!yyin) {
            std::cerr << "Error opening the provided file... (" << argv[1] << ")\n";
            return 1;
        }

        yyparse();

        if (fclose(yyin)) {
            std::cerr << "Couldn't close the opened file...\n";
            return 2;
        }
    } else {
        std::cerr << "No input file given...\n";
        return -1;
    }

    // boucle d'affichage du tableau contenant tout le programme
    for (int i = 0; i < code_genere.size(); i++){
    auto instruction = code_genere [i];
    std::cout << i 
         << '\t'
         << print_code(instruction.code) 
         << '\t'
         << instruction.value 
         << '\t' 
         << instruction.name 
         << std::endl;
    }


    yyparse();

    return EXIT_SUCCESS;
}

