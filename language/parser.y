%{
    #include <cstdio>
    #include <cmath>
    #include <string>
    #include <map>
    #include <stack>
    #include <vector>
    #include <iostream>
    using namespace std;
    extern int yylex();
    extern FILE *yyin;
    extern char *yytext;
    extern size_t yylineno;
    int yyerror(const char *s);


    #define DOUBLE dvalue
    #define STRING svalue
    #define BOOL bvalue
    #define ADDRESS adresse

    /**
     * 
     */
    class instruction {
    public:
        instruction (const int &c, const double &v=0, const string &n="") { code = c; value = v; name = n; };
        int code;
        double value;     // eventuellement une valeur si besoin
        std::string name; // ou une référence pour la table des données
    };

    /**
     * 
     */
    class function {
    public:
        /** Function code */
        std::vector<instruction> code;
        /** Instruction counter */
        int ic;
        /** Function params */
        std::map<std::string,double> parameters;
        /** Hex color code */
        std::string color;
        /** Display style */
        std::string style;
        /** Default Constructor */
        function() { color = "#FF0000"; style = "solid"; ic = 0; }
        /**
         * Color setter
         * @param[in]   c   new color
         */
        void setColor(const std::string& c) { color = c; }
        /**
         * Style setter
         * @param[in]   s   new style
         */
        void setStyle(const std::string& s) { style = s; }
        /**
         * Add instruction method
         * @param[in]   c   Instruction's code
         * @param[in]   v   Instruction value used in some cases
         * @param[in]   n   Instruction string value like a var name
         * @return      Error code
         */
        int add_instruction(const int &c, const double &v=0, const std::string &n="") {
            code.push_back(instruction(c,v,n));
            ic++;
            return 0;
        }
        /**
         * Define a parameter used in a function declaration
         * @param[in]   s   Name of the parameter
         * @param[in]   c   Code of the DECLARE instruction (since it is not known by cpp)
         * @return      Error Code
         */
        int add_param(const std::string &s, const int &c) {
            if (!parameters.count(s)) {
                    parameters[s] = 0;
                    /* c is the code number for DECLARE */
                    add_instruction(c, 0, s);
                    return EXIT_SUCCESS;
            } else {
                yyerror("Parameter already declared...");
                return -1;
            }
        }
    };

    // Structure pour accueillir le code généré
    // (sone de code ou code machine ou assembleur)
    vector <instruction> code_genere;

    /**
     * String storing the current code (main or function) to write to.
     * 0 -> main code, otherwise write to the associated function
     */
    std::stack<std::string> current_code;

    // Déclaration de la map qui associe
    // les noms des variables à leur valeur
    // (La table de symboles)
    std::map<std::string,double> variables;

    //  Map storing functions instructions, access them by their name (string)
    std::map<std::string, function *> functions;

    /* Map storing functions to draw */
    std::map</*name*/std::string, std::pair</*xbegin*/double, /*xend*/double>> funcsToDraw;

    /* Main Code Instruction Counter */
    int ic = 0;

    // Remarquez les paramètres par défaut pour faciliter les appels depuis la grammaire
    int add_instruction(const int &c, const double &v=0, const string &n="") {
        code_genere.push_back(instruction(c,v,n));
        ic++;
        return 0;
    }
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
%token <DOUBLE> PI
%token <DOUBLE> E
%token <DOUBLE> PHI
%token var /* Variable definition */
%token DEF /* Function definition */
%token in  /* param interval for a given function */
%token arrow /* => */
%token RETURN /* return function keyword */

/* Parameters for draw */
%token color
%token style
%token label
%token xmin
%token xmax
%token ymin
%token ymax
%token COLOR_PARAM /* "#F0F0F0" or "blue" */
%token STYLE_PARAM /* "solid", "dashed", "dotted" */
%token STRING /* "text" */

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

/* Instruction vector defines */
%token JMP
%token JMPCOND
%token ASSIGN
%token DECLARE
%token LOAD

/* Operators */
%token <DOUBLE> PLUS
%token <DOUBLE> MIN
%token <DOUBLE> TIMES
%token <DOUBLE> DIV
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
%left PLUS MIN
%left TIMES DIV
%left '|' '&'
%right '^'


%%

/* Structure globale d'un programme :
    Déclarations
    Fonctions
    Affichage
*/
code: declarations fonctions affichage                  { /* TODO: print start compiling */ }


declarations: %empty /* \epsilon */                 { /* End of declarations */
                    std::cout << "-- End of declarations --\n";
 }
            | declarations var VAR '=' expr ';'     { /* Init Vars */
                if (!variables.count($3)) {
                    variables[$3] = $5;
                    add_instruction(DECLARE, 0, $3);
                    add_instruction(ASSIGN, 0, $3);
                } else {
                    yyerror("Variable already declared...");
                }
}
            | declarations var VAR ';'              {
                if (!variables.count($3)) {
                    variables[$3] = 0;
                    add_instruction(DECLARE, 0, $3);
                    add_instruction(ASSIGN, 0, $3);
                }
            }


fonctions: DEF VAR ':' '(' parameters ')' arrow '{'           {
                    if(!functions.count($2)) {
                        functions[$2] = new function();
                        current_code.push($2);
                        add_instruction(DEF, 0, $2);
                    } else {
                        yyerror("Function already declared...");
                    }
                    
}
                instruction
          '}'                                               {
                    current_code.pop();
}
         | fonctions fonctions                              { /* Support multiple functions */ }

parameters: VAR                                         {
                    add_instruction(DECLARE, 0, $1);
                    /*
                    if (function.count(current_code.top())) {
                        if (!functions[current_code.top()].parameters.count($1)) {
                            functions[current_code.top()].parameters[$1] = 0;
                        } else {
                            yyerror("Parameter already declared...");
                        }
                    } else {
                        yyerror("Function not registered...");
                    }
                    */
}
          | parameters ',' parameters                   { /* Support multiple parameters */ }


draw_func: VAR in '[' NUM ',' NUM ']'                   {
                    /* Load function names to send to the front-end */
                    add_instruction(LOAD, 0, $1);
                    /* Check if the function is already drawn */
                    if (!functions.count($1)){
                        funcsToDraw[$1] = std::pair<double,double>($4,$6);

                    } else {
                        yyerror("Function already drawn...");
                    }
                    

}
         | VAR                                          { /* TODO */ }
         | draw_func ',' draw_func                      { /* Support multiple ??? */ }


affichage: DRAW draw_func '{'   { /*TODO: load funcs*/ }
                draw_args
           '}'
         | DRAW draw_func ';'   { /* TODO: load default args */}


draw_args: color ':' '[' color_args ']'  { /*TODO: check PARAM values*/ }
         | style ':' '[' style_args ']'  { /*TODO: check PARAM values*/ }
         | label ':' STRING              { /*TODO: check PARAM values*/ }
         | xmin ':' NUM                  { /*TODO*/ }
         | xmin ':' VAR                  { /*TODO*/ }
         | xmax ':' NUM                  { /*TODO*/ }
         | xmax ':' VAR                  { /*TODO*/ }
         | ymin ':' NUM                  { /*TODO*/ }
         | ymin ':' VAR                  { /*TODO*/ }
         | ymax ':' NUM                  { /*TODO*/ }
         | ymax ':' VAR                  { /*TODO*/ }
         | draw_args ',' draw_args       { /*TODO*/ }


style_args: STYLE_PARAM                  { /*TODO*/ }
          | style_args ',' style_args    { /*TODO*/ }


color_args: COLOR_PARAM                  { /*TODO*/ }
          | color_args ',' color_args    { /*TODO*/ }


instruction: %empty /* \epsilon */       { /* No instructions left */ }
           | instruction expr ';'        { /* new line */ }
           | instruction RETURN expr ';' {
               /* The return instruction will jump to the main instruction (out of function) */
               add_instruction(JMP, -1);
            }
           | IF logic '{'                {

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
           | FOR VAR in '[' expr ':' expr ':' expr ']' '{'
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
     | NOT logic            { add_instruction(NOT); }


expr: NUM                   { add_instruction(NUM, $1); }
    | PI                    { add_instruction(NUM, 3.14159265358979323846); }
    | E                     { add_instruction(NUM, 2.71828182845904523536); }
    | PHI                   { add_instruction(NUM, 1.61803398874989484820); }
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
    | expr PLUS expr        { add_instruction(PLUS); }
    | expr MIN expr         { add_instruction(MIN); }
    | expr TIMES expr       { add_instruction(TIMES); }
    | expr DIV expr         { add_instruction(DIV); }
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
    | expr '^' expr                 { add_instruction(POW); }
    | POW '(' expr ',' expr ')'     { add_instruction(POW); }
    | EXP '(' expr ')'              { add_instruction(EXP); }
    | LOG '(' expr ')'              { add_instruction(LOG); }
    | SQRT '(' expr ')'             { add_instruction(SQRT); }
    | VAR                           { add_instruction(VAR, 0, $1); }
    | VAR '=' expr                  { add_instruction(ASSIGN,0,$1); }
    | VAR PLUS_EQUAL expr           { add_instruction(VAR,0,$1); add_instruction(PLUS); add_instruction(ASSIGN,0,$1); }
    | VAR MIN_EQUAL expr            { add_instruction(VAR,0,$1); add_instruction(MIN); add_instruction(ASSIGN,0,$1); }
    | VAR TIMES_EQUAL expr          { add_instruction(VAR,0,$1); add_instruction(TIMES); add_instruction(ASSIGN,0,$1); }
    | VAR DIV_EQUAL expr            { add_instruction(VAR,0,$1); add_instruction(DIV); add_instruction(ASSIGN,0,$1); }

%%

int yyerror(const char *s)
{
    printf("%zu - %s : %s\n", yylineno, s, yytext);
    return EXIT_SUCCESS;
}

/**
 * Convert int code to string value
 * @param[in]   ins     Instruction code
 */
string print_code(const int &ins) {
    switch (ins) {
        /* Blocks */
        case IF             : return "IF";
        case ELSE           : return "ELSE";
        case FOR            : return "FOR";
        case WHILE          : return "WHILE";
        /* Operators */
        case PLUS           : return "+";
        case MIN            : return "-";
        case TIMES          : return "*";
        case DIV            : return "/";
        /* Logic */
        case SUP            : return "SUP";
        case INF            : return "INF";
        case SUP_STRICT     : return "SUP_STRICT";
        case INF_STRICT     : return "INF_STRICT";
        case EQUAL          : return "EQUAL";
        case NOT_EQ         : return "NOT_EQ";
        case AND            : return "AND";
        case OR             : return "OR";
        case NOT            : return "NOT";
        /* Literal */
        case NUM            : return "NUM";
        /* Functions */
        case SIN            : return "SIN";
        case COS            : return "COS";
        case TAN            : return "TAN";
        case ARCCOS         : return "ARCCOS";
        case ARCSIN         : return "ARCSIN";
        case ARCTAN         : return "ARCTAN";
        case SINH           : return "SINH";
        case COSH           : return "COSH";
        case TANH           : return "TANH";
        case ARCCOSH        : return "ARCCOSH";
        case ARCSINH        : return "ARCSINH";
        case ARCTANH        : return "ARCTANH";
        case POW            : return "POW";
        case EXP            : return "EXP";
        case LOG            : return "LOG";
        case SQRT           : return "SQRT";
        case VAR            : return "VAR";
        /* Adress Instructions */
        case JMP            : return "JMP";
        case JMPCOND        : return "JC ";
        /* Variables Instructions */
        case ASSIGN         : return "ASSIGN";
        case DECLARE        : return "DECLARE";
        /* Draw Instructions */
        case DRAW           : return "DRAW";
        /*---------------------------------*/
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

        /* Analyse the code */
        yyparse();

        if (fclose(yyin)) {
            std::cerr << "Couldn't close the opened file...\n";
            return 2;
        }
    } else {
        std::cerr << "No input file given...\n";
        return -1;
    }

    /* Print the generated code */
    std::cout << "i\tCode\tValue\tName\n";
    for (size_t i = 0; i < code_genere.size(); i++) {
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

    /* Print function map */
    std::cout << "\nFunctions:\n";
    for (auto it = functions.begin(); it != functions.end(); ++it) {
        std::cout << it->first << ": ( ";
        for (auto it2 = it->second->parameters.begin(); it2 != it->second->parameters.end(); ++it) {
            std::cout << it2->first << " ";
        }
        std::cout << ") => {" <<
            "\n\tcolor: " << it->second->color <<
            "\n\tstyle: " << it->second->style <<
            "\n}\n";
    }

    return EXIT_SUCCESS;
}

