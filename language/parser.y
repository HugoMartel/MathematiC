%{
    #include <cstdio>
    #include <cstdlib>
    #include <cstdarg>
    #include <cmath>
    #include <cstring>
    #include <string>
    #include <cfloat>
    #include <map>
    #include <queue>
    #include <stack>
    #include <vector>
    #include <iostream>
    #include <tuple>
    #include <algorithm>

    #include "interface.hpp"
    #include "function.hpp"

    /* \/ Uncomment to enable debug output */
    //#define __DEBUG__

    using namespace std;//? useful ?

    extern int yylex();
    extern FILE *yyin;
    extern char *yytext;
    //extern int yy_flush_buffer();
    extern int yylex_destroy(void);
    extern int yylineno;
    int yyerror(const char *s);


    #define DOUBLE dvalue
    #define STRING svalue
    #define BOOL bvalue
    #define ADDRESS address


    /*===================*/
    /* --  VARIABLES  -- */
    /*===================*/

    /* Draw function Variables */
    std::string argLabel;
    double argXmin;
    double argXmax;
    double argYmin;
    double argYmax;

    /** Error message */
    std::string error;

    /** Map with FOR variables */
    std::map<std::string, std::tuple<double, double, double>> forArguments;

    /* Variables only used during parsing */
    /** Function currently modified index */
    unsigned int functionToEdit;
    int i;


    /**
     * String storing the current code (main or function) to write to.
     * 0 -> main code, otherwise write to the associated function
     */
    std::vector<std::string> current_scope;

    /**
     * Temporary queue to store args to add to functions and draw
     */
    std::queue<std::string> argQueue;

    /**
     * Map storing variables declared gloabally
     */
    std::map<std::string,double> variables;

    /**
     * Map storing functions instructions, access them by their name (string)
     */
    std::map<std::string,Function> functions;


    /*===================*/
    /* --  FUNCTIONS  -- */
    /*===================*/
    /**
     * Convert int code to string value
     * @param[in]   ins     Instruction code
     */
    string print_code(const int &ins);

    /**
     * Function to easily add instruction to the appropriate function without having to care about the current function
     */
    int add_instruction(const int &c, const double &v=0, const string &n="") {
        /* Check where this instruction should be put */
        if (current_scope.empty()) {
            error = "Instructions not placed in a function...\n";
            verbose(error);
        } else {
            /* Write to the appropriated function stack */
            functions[current_scope[0]].add_instruction(c, v, n);
        }
        return 0;
    }
%}


%code provides {
    #include "mathGraph.hpp"

    /**
     * Compile the code to generate the functions to then use to draw
     * @param[in]   filename    file to open to read the code from
     * @param[out]  graph       GraphSetup object to set after a successful compilation
     * @return      0: success, 1: open error, 2: close error, 3: display interval error, 4: compilation error
     */
    int compileCode(const char *filename, GraphSetup *graph);
}


/* Reset containers on compilation start */
%initial-action
{
    /* Reset to default values */
    argLabel = "Affichage";
    argXmin = -10;
    argXmax = 10;
    argYmin = -10;
    argYmax = 10;

    /* Empty variables and maps */
    functionToEdit = 0;
    variables.clear();
    current_scope.clear();
    functions.clear();
    while (!argQueue.empty())
        argQueue.pop();

}


%code requires
  {
    typedef struct adr {
        int jmp;  // jmp address
        int jc;   // jc addres
    } Address;
  }

%union {
    double dvalue;
    char svalue[50];
    bool bvalue;
    Address address;
}

%type <DOUBLE> expr
%type <Instruction> instruction
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
%token <STRING> color
%token <STRING> style
%token <STRING> label
%token <DOUBLE> xmin
%token <DOUBLE> xmax
%token <DOUBLE> ymin
%token <DOUBLE> ymax
%token <STRING> COLOR_PARAM /* "#F0F0F0" or simple colors */
%token <STRING> STYLE_PARAM /* "solid", "filled", "dotted", "hist" */
%token <STRING> STRING /* "text" */

/* Functions & instructions*/
%token <DOUBLE> NUM
%token <DOUBLE> SIN
%token <DOUBLE> COS
%token <DOUBLE> POW
%token <DOUBLE> EXP
%token <STRING> VAR
%token <ADDRESS> FOR
%token <BOOL> PROCEEDFOR
%token <ADDRESS> IF
%token <ADDRESS> ELSE
%token THEN
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
%token CALL

/* Operators */
%token <DOUBLE> PLUS
%token <DOUBLE> MIN
%token <DOUBLE> OPP
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


/* Define operators priority and associativity behaviour */
%precedence '=' PLUS_EQUAL MIN_EQUAL TIMES_EQUAL DIV_EQUAL
%precedence NOT
%left PLUS MIN OR
%left TIMES DIV AND
%right '^'
%left ','


%%

/* Structure globale d'un programme :
    Déclarations
    Fonctions
    Affichage
*/
code: declarations fonctions affichage              {
#ifdef __DEBUG__
                std::cout << "-- END OF COMPILATION --\n";
#endif
                                                    }


/*===========================================================================================*/
declarations: %empty /* \epsilon */                 { /* End of declarations */
#ifdef __DEBUG__
                std::cout << "-- End of declarations --\n";
#endif
                                                    }
            | declarations var VAR '=' expr ';'     { /* Init Vars */
                                                        /* Check if already declared */
                                                        if (!variables.count($3)) {
                                                            variables[$3] = $5;

#ifdef __DEBUG__
                                                            printf("Declared %s = %lf\n", $3, $5);
#endif

                                                        } else {
                                                            error = "Variable " + std::string($3) + " has already been declared...\n";
                                                            verbose(error);
                                                        }
                                                    }
            | declarations var VAR ';'              {
                                                        if (!variables.count($3)) {
                                                            variables[$3] = 0;
#ifdef __DEBUG__
                                                            printf("Declared %s (=0)\n", $3);
#endif
                                                        } else {
                                                            error = "Variable " + std::string($3) + " has already been declared...\n";
                                                            verbose(error);
                                                        }
                                                    }


/*===========================================================================================*/
fonctions: DEF VAR ':' '(' parameters ')' arrow '{'     {
                                                                /* Clear the current_scope vector */
                                                                current_scope.clear();

                                                                /* Check if the function wasn't already declared */
                                                                if (!functions.count($2)) {
                                                                    functions[$2] = Function();
                                                                    /* Enqueue to keep it in memory */
                                                                    current_scope.push_back($2);

                                                                /* Declare parameters */
                                                                while (!argQueue.empty()) {
                                                                    if (!functions[$2].parameters.count(argQueue.front()))
                                                                        functions[$2].parameters[argQueue.front()] = 0;
                                                                    else {
                                                                        error = "Parameter already used...\n";
                                                                        verbose(error);
                                                                    }

                                                                    argQueue.pop();
                                                                }
                                                            } else {
                                                                error = "Function already declared...\n";
                                                                verbose(error);
                                                            }

                                                        }
                instruction
          '}' fonctions                                 {
                                                             /* Dequeue since we left the function scope */
                                                             if (!current_scope.empty())
                                                                current_scope.pop_back();
                                                             /*Clear the queue in case it is not empty*/
                                                             while (!argQueue.empty())
                                                                 argQueue.pop();
                                                        }
         | %empty /* \epsilon */                        { /* End of function declarations */ }


/*===========================================================================================*/
parameters: VAR                                         {
                    argQueue.push($1);
                                                        }
          | parameters ',' parameters                   { /* Support multiple parameters */ }


/*===========================================================================================*/
draw_func: VAR in '[' NUM ',' NUM ']'                   {
                                                            /* Load function names to send to the front-end */
                                                            current_scope.push_back($1);

                                                            /* Check if the function is already drawn */
                                                            if (functions.count($1)) {
                                                                functions[$1].xInterval.first = $4;
                                                                functions[$1].xInterval.second = $6;
                                                            } else {
                                                                error = "Function already declared...\n";
                                                                verbose(error);
                                                            }
                                                        }
         | VAR                                          {
                                                            /* Load function names to send to the front-end */
                                                            current_scope.push_back($1);

                                                            /* Check if the function is already drawn */
                                                            if (!functions.count($1)) {
                                                                error = "Function already declared...\n";
                                                                verbose(error);
                                                            }
                                                        }
         | draw_func ',' draw_func                      { /* Support multiple functions to draw at the same time */ }


/*===========================================================================================*/
affichage: DRAW draw_func '{'
                draw_args
          '}'                                           {
#ifdef __DEBUG__
                                                            for (size_t i = 0; i < current_scope.size(); ++i) {
                                                                std::cout << i << ": " << current_scope[i] << "\n";
                                                            }
#endif
                                                        }

         | DRAW draw_func ';'                           {
#ifdef __DEBUG__
                                                            for (size_t i = 0; i < current_scope.size(); ++i) {
                                                                std::cout << i << ": " << current_scope[i] << "\n";
                                                            }
#endif
                                                        }


/*===========================================================================================*/
draw_args: color ':' '[' color_args ']'                 { /* getting the multiples color args (or not) */
                                                            if (current_scope.size() == argQueue.size()) { /* Check if the arg count matches the function count */
                                                                functionToEdit = 0;
                                                                while (!argQueue.empty()) { /* Assign each attribute to its function */
#ifdef __DEBUG__
                                                                    std::cout << "arg : " << argQueue.front() << " in " << current_scope[functionToEdit] << "\n";
#endif
                                                                    functions[current_scope[functionToEdit]].color = argQueue.front();
                                                                    argQueue.pop();
                                                                    ++functionToEdit;
                                                                }
                                                            } else {
                                                                error = "The number of function to draw doesn't match the number of arg\n";
                                                                verbose(error);
                                                            }
                                                        }
         | style ':' '[' style_args ']'                 { /* getting the multiples style args (or not) */
                                                            if (current_scope.size() == argQueue.size()) { /* Check if the arg count matches the function count */
                                                                functionToEdit = 0;
                                                                while (!argQueue.empty()) { /* Assign each attribute to its function */
#ifdef __DEBUG__
                                                                    std::cout << "arg : " << argQueue.front() << " in " << current_scope[functionToEdit] << "\n";
#endif
                                                                    functions[current_scope[functionToEdit]].style = argQueue.front();
                                                                    argQueue.pop();
                                                                    ++functionToEdit;
                                                                }
                                                            } else {
                                                                error = "The number of function to draw doesn't match the number of arg\n";
                                                                verbose(error);
                                                            }
                                                        }
         | label ':' STRING                             { argLabel = $3; argLabel = argLabel.substr(1, argLabel.size()-2); }
         | xmin ':' NUM                                 { argXmin = $3; }
         | xmin ':' VAR                                 { argXmin = variables[$3]; }
         | xmax ':' NUM                                 { argXmax = $3; }
         | xmax ':' VAR                                 { argXmax = variables[$3]; }
         | ymin ':' NUM                                 { argYmin = $3; }
         | ymin ':' VAR                                 { argYmin = variables[$3]; }
         | ymax ':' NUM                                 { argYmax = $3; }
         | ymax ':' VAR                                 { argYmax = variables[$3]; }
         | draw_args ',' draw_args                      { /* Support multiple args */ }


/*===========================================================================================*/
style_args: STYLE_PARAM                                 {
                                                            /* Check the value */
                                                            if (!strcmp($1, "\"dotted\"")) {
                                                                argQueue.push("dotted");
                                                            } else if (!strcmp($1, "\"hist\"")) {
                                                                argQueue.push("hist");
                                                            } else if (!strcmp($1, "\"solid\"")) {
                                                                argQueue.push("solid");
                                                            } else if (!strcmp($1, "\"filled\"")) {
                                                                argQueue.push("filled");
                                                            } else {
                                                                error = std::to_string(yylineno) + "Wrong curve style value...\n";
                                                                verbose(error);
                                                            }
                                                        }
          | style_args ',' style_args                   { /* Support multiple style_args */ }


/*===========================================================================================*/
color_args: COLOR_PARAM                                 {
                                                            if (!strcmp($1,"\"blue\"")) {
                                                                argQueue.push("#0000FF");
                                                            } else if (!strcmp($1,"\"red\"")) {
                                                                argQueue.push("#FF0000");
                                                            } else if (!strcmp($1,"\"green\"")) {
                                                                argQueue.push("#00FF00");
                                                            } else if (!strcmp($1,"\"black\"")) {
                                                                argQueue.push("#000000");
                                                            } else if (!strcmp($1,"\"white\"")) {
                                                                argQueue.push("#FFFFFF");
                                                            } else if (!strcmp($1,"\"magenta\"")) {
                                                                argQueue.push("#FF00FF");
                                                            } else if (!strcmp($1,"\"cyan\"")) {
                                                                argQueue.push("#00FFFF");
                                                            } else if (!strcmp($1,"\"yellow\"")) {
                                                                argQueue.push("#FFFF00");
                                                            } else {
                                                                /* Remove the head and tail '"' */
                                                                for (i = 0; i <= 6; ++i)
                                                                    $1 [i] = $1 [i+1];
                                                                $1[i] = '\0';
                                                                argQueue.push($1);
                                                            }
                                                        }
          | color_args ',' color_args                   { /* Support multiple color_args */ }


/*===========================================================================================*/
instruction: %empty /* \epsilon */                      { /* No instructions left */ }
           | instruction expr ';'                       { /* new line */ }
           | instruction RETURN expr ';'                {
                                                            /* The return instruction will jump to the main instruction (out of function) */
                                                            add_instruction(JMP, -1);
                                                        }
           | instruction IF logic '{'                   {

                                                            // Save current location to be able to modify it later
                                                            $2.jc = functions[current_scope[0]].iic;
                                                            add_instruction(JMPCOND);
                                                        }
                instruction                             {
                                                            // Save current location to be able to modify it later
                                                            $2.jmp = functions[current_scope[0]].iic;
                                                            add_instruction(JMP);

                                                            // Update condi jmp now that the instructions passed
                                                            functions[current_scope[0]].code[$2.jc].value = functions[current_scope[0]].iic;
                                                        }
             '}' ELSE '{'
                instruction
             '}'                                        {
                                                            // Update JMP value for when we don't go to the else part, skip it entirely
                                                            functions[current_scope[0]].code[$2.jmp].value = functions[current_scope[0]].iic;
                                                        }
           | instruction FOR VAR in '[' expr ':' expr ':' expr ']' '{'  {

                                                                add_instruction(FOR,0,$3);
                                                                $2.jmp = functions[current_scope[0]].iic;
                                                                add_instruction(PROCEEDFOR,0,$3);
                                                                $2.jc = functions[current_scope[0]].iic;
                                                                add_instruction(JMPCOND, $2.jc);

                                                            }
                instruction                                 {   add_instruction(JMP, $2.jmp);   }
             '}'                                            {
                                                                //! Check stack value
                                                                functions[current_scope[0]].code[$2.jc].value = functions[current_scope[0]].iic;
                                                            }
           | instruction WHILE logic '{'                    {
                                                                // Store instruction vector index of both jumps
                                                                $2.jc = functions[current_scope[0]].iic;
                                                                add_instruction(JMPCOND, $2.jc);
                                                            }
                instruction                                 {   add_instruction(JMP, 0); }
             '}'                                            {
                                                                functions[current_scope[0]].code[$2.jc].value = functions[current_scope[0]].iic;
                                                            }




/*===========================================================================================*/
logic: expr SUP expr        { add_instruction(SUP); }
     | expr INF expr        { add_instruction(INF); }
     | expr SUP_STRICT expr { add_instruction(SUP_STRICT); }
     | expr INF_STRICT expr { add_instruction(INF_STRICT); }
     | expr EQUAL expr      { add_instruction(EQUAL); }
     | expr NOT_EQ expr     { add_instruction(NOT_EQ); }
     | logic AND logic      { add_instruction(AND); }
     | logic OR logic       { add_instruction(OR); }
     | NOT logic            { add_instruction(NOT); }


/*===========================================================================================*/
expr: NUM                   {
                                if (!current_scope.empty())
                                    add_instruction(NUM, $1);
                                else
                                    $$ = $1;
                            }
    | PI                    {
                                if (!current_scope.empty())
                                    add_instruction(NUM, 3.14159265358979323846);
                                else
                                    $$ = 3.14159265358979323846;
                            }
    | E                     {
                                if (!current_scope.empty())
                                    add_instruction(NUM, 2.71828182845904523536);
                                else
                                    $$ = 2.71828182845904523536;
                            }
    | PHI                   {
                                if (!current_scope.empty())
                                    add_instruction(NUM, 1.61803398874989484820);
                                else
                                    $$ = 1.61803398874989484820;
                            }
    | SIN '(' expr ')'      {
                                if (!current_scope.empty())
                                    add_instruction(SIN);
                                else
                                    $$ = sin($3);
                            }
    | COS '(' expr ')'      {
                                if (!current_scope.empty())
                                    add_instruction(COS);
                                else
                                    $$ = cos($3);
                            }
    | TAN '(' expr ')'      {
                                if (!current_scope.empty())
                                    add_instruction(TAN);
                                else
                                    $$ = tan($3);
                            }
    | ARCCOS '(' expr ')'   {
                                if (!current_scope.empty())
                                    add_instruction(ARCCOS);
                                else
                                    $$ = acos($3);
                            }
    | ARCSIN '(' expr ')'   {
                                if (!current_scope.empty())
                                    add_instruction(ARCSIN);
                                else
                                    $$ = asin($3);
                            }
    | ARCTAN '(' expr ')'   {
                                if (!current_scope.empty())
                                    add_instruction(ARCTAN);
                                else
                                    $$ = atan($3);
                            }
    | COSH '(' expr ')'     {
                                if (!current_scope.empty())
                                    add_instruction(COSH);
                                else
                                    $$ = cosh($3);
                            }
    | SINH '(' expr ')'     {
                                if (!current_scope.empty())
                                    add_instruction(SINH);
                                else
                                    $$ = sinh($3);
                            }
    | TANH '(' expr ')'     {
                                if (!current_scope.empty())
                                    add_instruction(TANH);
                                else
                                    $$ = tanh($3);
                            }
    | ARCCOSH '(' expr ')'  {
                                if (!current_scope.empty())
                                    add_instruction(ARCCOSH);
                                else
                                    $$ = acosh($3);
                            }
    | ARCSINH '(' expr ')'  {
                                if (!current_scope.empty())
                                    add_instruction(ARCSINH);
                                else
                                    $$ = asinh($3);
                            }
    | ARCTANH '(' expr ')'  {
                                if (!current_scope.empty())
                                    add_instruction(ARCTANH);
                                else
                                    $$ = atanh($3);
                            }
    | '(' expr ')'          { $$ = $2; }
    | MIN expr              {
                                if (!current_scope.empty())
                                    add_instruction(OPP);
                                else
                                    $$ = -$2;
                            }
    | expr PLUS expr        {
                                if (!current_scope.empty())
                                    add_instruction(PLUS);
                                else
                                    $$ = $1 + $3;
                            }
    | expr MIN expr         {
                                if (!current_scope.empty())
                                    add_instruction(MIN);
                                else
                                    $$ = $1 - $3;
                            }
    | expr TIMES expr       {
                                if (!current_scope.empty())
                                    add_instruction(TIMES);
                                else
                                    $$ = $1 * $3;
                            }
    | expr DIV expr         {
                                if (!current_scope.empty())
                                    add_instruction(DIV);
                                else {
                                    if ($3 == 0.) {
                                        error = "Dividing by 0...\n";
                                        verbose(error);
                                    } else
                                        $$ = $1 / $3;
                                }
                            }
    | expr '^' expr                 {
                                        if (!current_scope.empty())
                                            add_instruction(POW);
                                        else {
                                            if ($1 == 0. && $3 == 0.) {
                                                error = "Can't put 0 to the power 0...\n";
                                                verbose(error);
                                            } else
                                                $$ = pow($1,$3);
                                        }
                                    }
    | POW '(' expr ',' expr ')'     {
                                        if (!current_scope.empty())
                                            add_instruction(POW);
                                        else {
                                            if ($3 == 0. && $5 == 0.) {
                                                error = "Can't put 0 to the power 0...\n";
                                                verbose(error);
                                            } else
                                                $$ = pow($3,$5);
                                        }
                                    }
    | EXP '(' expr ')'              {
                                        if (!current_scope.empty())
                                            add_instruction(EXP);
                                        else
                                            $$ = exp($3);
                                    }
    | LOG '(' expr ')'              {
                                        if (!current_scope.empty())
                                            add_instruction(LOG);
                                        else
                                            $$ = log($3);
                                    }
    | SQRT '(' expr ')'             {
                                        if (!current_scope.empty())
                                            add_instruction(SQRT);
                                        else
                                            $$ = sqrt($3);
                                    }
    | VAR                           {
                                        /* Only add to the ins vector if we are in a function */
                                        if (!current_scope.empty()) {
                                            add_instruction(VAR, 0, $1);
                                        } else {
                                            if (variables.count($1))
                                                $$ = variables.at($1);
                                        }
                                    }
    | VAR '=' expr                  {
                                        /* Only add to the ins vector if we are in a function */
                                        if (!current_scope.empty()) {
                                            add_instruction(ASSIGN,0,$1);
                                        } else {
                                            error = "Can only assign to an already declared variable when in a function...\n";
                                            verbose(error);
                                        }
                                    }
    | VAR PLUS_EQUAL expr           {
                                        /* Only add to the ins vector if we are in a function */
                                        if (!current_scope.empty()) {
                                            add_instruction(VAR,0,$1);
                                            add_instruction(PLUS);
                                            add_instruction(ASSIGN,0,$1);
                                        } else {
                                            error ="Can only assign to an already declared variable when in a function...\n";
                                            verbose(error);
                                        }
                                    }
    | VAR MIN_EQUAL expr            {
                                        /* Only add to the ins vector if we are in a function */
                                        if (!current_scope.empty()) {
                                            add_instruction(VAR,0,$1);
                                            add_instruction(MIN);
                                            add_instruction(OPP);
                                            add_instruction(ASSIGN,0,$1);
                                        } else {
                                            error = "Can only assign to an already declared variable when in a function...\n";
                                            verbose(error);
                                        }
                                    }
    | VAR TIMES_EQUAL expr          {
                                        /* Only add to the ins vector if we are in a function */
                                        if (!current_scope.empty()) {
                                            add_instruction(VAR,0,$1);
                                            add_instruction(TIMES);
                                            add_instruction(ASSIGN,0,$1);
                                        } else {
                                            error = "Can only assign to an already declared variable when in a function...\n";
                                            verbose(error);
                                        }
                                    }
    | VAR DIV_EQUAL expr            {
                                        /* Only add to the ins vector if we are in a function */
                                        if (!current_scope.empty()) {
                                            add_instruction(VAR,0,$1);
                                            add_instruction(DIV);
                                            add_instruction(ASSIGN,0,$1);
                                        } else {
                                            error = "Can only assign to an already declared variable when in a function...\n";
                                            verbose(error);
                                        }
                                    }

%%


/*================================================================================================*/
int yyerror(const char *s)
{
    /* 150 chars should be enough */
    char str[150];
    sprintf(str, "%d - %s: %s\n", yylineno, s, yytext);
    std::string output(str);
    verbose(output, true);

#ifdef __DEBUG__
    fprintf(stderr, "%d - %s: %s\n", yylineno, s, yytext);
#endif

    return EXIT_SUCCESS;
}


/*================================================================================================*/
string print_code(const int &ins) {
    switch (ins) {
        /* Blocks */
        case IF             : return "IF";
        case ELSE           : return "ELSE";
        case FOR            : return "FOR";
        case PROCEEDFOR     : return "PROCEEDFOR";
        case WHILE          : return "WHILE";
        /* Operators */
        case PLUS           : return "+";
        case MIN            : return "-";
        case OPP            : return "(-)";
        case TIMES          : return "*";
        case DIV            : return "/";
        /* Logic */
        case SUP            : return "SUP";
        case INF            : return "INF";
        case SUP_STRICT     : return "SUP_ST";
        case INF_STRICT     : return "INF_ST";
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
        /* Variable */
        case VAR            : return "VAR";
        /* Adress Instructions */
        case DEF            : return "DEF";
        case JMP            : return "JMP";
        case JMPCOND        : return "JC ";
        case CALL           : return "CALL";
        /* Variables Instructions */
        case ASSIGN         : return "ASSIGN";
        /*---------------------------------*/
        default : return "";
    }
}


/*================================================================================================*/
double Function::operator()(...)
{
    /* INIT */
    stack<double> pile;
    va_list params;
    long unsigned int ic = 0;  /* Instruction Counter */
    double r1, r2, r4;  /* double registers */
    std::string r3; /* string register */
    Instruction ins; /* Current instruction */

    /* Load parameters values */
    va_start(params, NULL);/* init the arg list after variables */

    for (auto &paramValue :this->parameters) {
        paramValue.second = va_arg(params, double);
#ifdef __DEBUG__
        printf("%s: %lf\n", paramValue.first.c_str(), paramValue.second);
#endif
    }

    va_end(params);

#ifdef __DEBUG__
    printf("\n------- FUNCTION START ---------\n");
#endif

    /* Run the Function code */
    while (ic < code.size()) { /* While the ic hasn't reached the end */

        /* Load the next instruction to execute */
        ins = code[ic];

#ifdef __DEBUG__
        printf("%zu\t%s\t%lf\t%s\n", ic, print_code(ins.code).c_str(), ins.value, ins.name.c_str());
#endif

        switch (ins.code) {
        case PLUS:
            r2 = pile.top();    // Récupérer la tête de pile;
            pile.pop();

            r1 = pile.top();    // Récupérer la tête de pile;
            pile.pop();

            pile.push(r1+r2);
            ++ic;
            break;

        case DIV:
            r2 = pile.top();    // Récupérer la tête de pile;
            pile.pop();

            r1 = pile.top();    // Récupérer la tête de pile;
            pile.pop();

            if (r2 != 0)
                pile.push(r1/r2);
            else {
                error = "Division by 0...\n";
                verbose(error);
                return (r1 < 0 ? - DBL_MAX : DBL_MAX);
            }
            ++ic;
            break;

        case MIN:
            r2 = pile.top();    // Récupérer la tête de pile;
            pile.pop();

            r1 = pile.top();    // Récupérer la tête de pile;
            pile.pop();

            pile.push(r1-r2);
            ++ic;
            break;

        case OPP:
            r1 = pile.top();
            pile.pop();

            pile.push(-r1);
            ++ic;
            break;

        case TIMES:
            r2 = pile.top();    // Récupérer la tête de pile;
            pile.pop();

            r1 = pile.top();    // Récupérer la tête de pile;
            pile.pop();

            pile.push(r1*r2);
            ++ic;
            break;

        case SUP:
            r2 = pile.top();    // Récupérer la tête de pile;
            pile.pop();

            r1 = pile.top();    // Récupérer la tête de pile;
            pile.pop();

            pile.push(r1 >= r2);
            ++ic;
            break;

        case INF:
            r2 = pile.top();    // Récupérer la tête de pile;
            pile.pop();

            r1 = pile.top();    // Récupérer la tête de pile;
            pile.pop();

            pile.push(r1 <= r2);
            ++ic;
            break;

        case SUP_STRICT:        // >
            r2 = pile.top();
            pile.pop();

            r1 = pile.top();
            pile.pop();

            pile.push(r1 > r2);
            ++ic;
            break;

        case INF_STRICT:        // <
            r2 = pile.top();
            pile.pop();

            r1 = pile.top();
            pile.pop();

            pile.push(r1 < r2);
            ++ic;
            break;

         case EQUAL:             // ==
            r2 = pile.top();
            pile.pop();

            r1 = pile.top();
            pile.pop();

            pile.push(r1 == r2);
            ++ic;
            break;

        case NOT_EQ:            // !=
            r2 = pile.top();
            pile.pop();

            r1 = pile.top();
            pile.pop();

            pile.push(r1 != r2);
            ++ic;
            break;

        case AND:               // &&
            r1 = pile.top();
            pile.pop();

            r2 = pile.top();
            pile.pop();

            pile.push((double)((bool)r1 && (bool)r2));
            ++ic;
            break;

        case OR:               // ||
            r1 = pile.top();
            pile.pop();

            r2 = pile.top();
            pile.pop();

            pile.push((double)((bool)r1 || (bool)r2));
            ++ic;
            break;

        case NOT:              // !
            r1 = pile.top();
            pile.pop();

            pile.push((double)(!(bool)r1));
            ++ic;
            break;

        case NUM:               // Literal value
            pile.push(ins.value);
            ++ic;
            break;

        case COS:               // cos
            r1 = pile.top();
            pile.pop();
            pile.push(std::cos(r1));
            ++ic;
            break;

        case SIN:               // sin
            r1 = pile.top();
            pile.pop();
            pile.push(std::sin(r1));
            ++ic;
            break;

        case TAN:               // tan
            r1 = pile.top();
            pile.pop();
            pile.push(std::tan(r1));
            ++ic;
            break;

        case COSH:              // cosh
            r1 = pile.top();
            pile.pop();
            pile.push(std::cosh(r1));
            ++ic;
            break;

        case SINH:              // sinh
            r1 = pile.top();
            pile.pop();
            pile.push(std::sinh(r1));
            ++ic;
            break;

        case TANH:              // tanh
            r1 = pile.top();
            pile.pop();
            pile.push(std::tanh(r1));
            ++ic;
            break;

        case ARCCOS:            // arccos
            r1 = pile.top();
            pile.pop();
            pile.push(std::acos(r1));
            ++ic;
            break;

        case ARCSIN:            // arcsin
            r1 = pile.top();
            pile.pop();
            pile.push(std::asin(r1));
            ++ic;
            break;

        case ARCTAN:            // arctan
            r1 = pile.top();
            pile.pop();
            pile.push(std::atan(r1));
            ++ic;
            break;

        case ARCCOSH:           // arccosh
            r1 = pile.top();
            pile.pop();
            pile.push(std::acosh(r1));
            ++ic;
            break;

        case ARCSINH:           // arcsinh
            r1 = pile.top();
            pile.pop();
            pile.push(std::asinh(r1));
            ++ic;
            break;

        case ARCTANH:           // arctanh
            r1 = pile.top();
            pile.pop();
            pile.push(std::atanh(r1));
            ++ic;
            break;

        case POW:               // power
            r2 = pile.top();
            pile.pop();

            r1 = pile.top();
            pile.pop();

            pile.push(std::pow(r1, r2)); // r1^r2
            ++ic;
            break;

        case EXP:               // exponential
            r1 = pile.top();
            pile.pop();
            pile.push(std::exp(r1));
            ++ic;
            break;

        case LOG:               // logarithm (base e)
            r1 = pile.top();
            pile.pop();
            pile.push(std::log(r1));
            ++ic;
            break;

        case SQRT:              // square root function
            r1 = pile.top();
            pile.pop();
            if (r1 < 0.) {
                error = "Square root of negative value...\n";
                verbose(error);
                return -1;
            }
            pile.push(std::sqrt(r1));
            ++ic;
            break;

        case JMP:
            /* Go to the stored address */
            if (ins.value == -1) {
                /* Return case */
                ic = code.size();
            } else {
                ic = ins.value;
            }
            break;

        case JMPCOND:
            r1 = pile.top();     // Get the last logic value

            pile.pop();
            if (r1)              // Logic true => go to next instruction
               ++ic;
            else                 // Otherwise  => go to the given address
               ic = ins.value;
#ifdef __DEBUG__
            // std::cout << "A JMPCOND with logic : " << r1 << " and JMP to : " << (int)ins.value <<" \n";
#endif
            break;

        case CALL:  /* Recursive function */
            pile.push(this->operator()(params));
            ++ic;
            break;

        case ASSIGN:
            r1 = pile.top();    // Récupérer la tête de pile;
            pile.pop();
            if (this->parameters.count(ins.name))
                this->parameters.at(ins.name) = r1;
            else
                variables.at(ins.name) = r1;
            ++ic;
            break;

        case VAR:               // Get the value from a param (local) or a variable (global)
            if (this->parameters.count(ins.name)) {
                pile.push(this->parameters.at(ins.name));
            } else {
                pile.push(variables.at(ins.name));
            }

#ifdef __DEBUG__
            printf("\t%lf\n", pile.top());
#endif
            ++ic;
            break;

        case FOR:
            r1 = pile.top();//Stop
            pile.pop();
            r2 = pile.top();//Step
            pile.pop();
            r4 = pile.top();//Start
            pile.pop();

            // Init
            if (!this->parameters.count(ins.name) && !variables.count(ins.name)) {
                /* If the parameter didn't exist */
                this->parameters[ins.name] = r4 - r2;
            } else if (this->parameters.count(ins.name)) {
                this->parameters.at(ins.name) = r4 - r2;
            } else {
                variables.at(ins.name) = r4;
            }

#ifdef __DEBUG__
            std::cout << "r1: " << r1 << ", r2: " << r2 << ", r4: " << r4 << "\n";
#endif

            forArguments[ins.name] = std::make_tuple (r4,r2,r1);

            ++ic;
            break;

        case PROCEEDFOR:
            r1 = std::get<2>(forArguments[ins.name]);// Stop
            r2 = std::get<1>(forArguments[ins.name]);// Step
            //r4 = std::get<0>(forArguments[ins.name]);// Start

#ifdef __DEBUG__
            std::cout << "r1: " << r1 << ", r2: " << r2 /*<< ", r4: " << r4*/ << "\n";
#endif

            if (this->parameters.count(ins.name)) {
                this->parameters.at(ins.name) += r2;
                if (this->parameters.at(ins.name) > r1)
                    pile.push(0.0);// False, trigger the conditionnal JMP
                else
                    pile.push(1.0);// True ++ic
            } else {
                variables.at(ins.name) += r2;
                if (variables.at(ins.name) > r1)
                    pile.push(0.0);// False, trigger the conditionnal JMP
                else
                    pile.push(1.0);// True, ++ic
            }

            ++ic;
#ifdef __DEBUG__
            // std::cout << "value of FOR var init : " << r4 << " step : " << r2 << " stop : " << r1 << " variable : "<< variables[ins.name] << " logic :" << pile.top() << "\n";
#endif
            break;
        }
    }

#ifdef __DEBUG__
    printf("Stack:\n");
    double elem;
    while (!pile.empty()) {
        elem = pile.top();
        printf("\t%lf\n", elem);
        pile.pop();

    }
    pile.push(elem);
    printf("RETURN %lf;", pile.top());
    printf("\n------- FUNCTION RETURNED OR ENDED ---------\n");
#endif

    /* return the last value contained in the stack */
    return pile.top();
}


/* FUNCTION USAGE EXAMPLE
    functions["g"](3);
    functions["fonction1"](4);
These lines return a signe double value: g(params) = <double>
*/


/*====================================================================================*/
int compileCode(const char *filename, GraphSetup *graph)
{
    int compileSuccess;

    yyin = fopen(filename, "r");

    if (!yyin) {
        fprintf(stderr, "Error opening the provided file... (%s)\n", filename);
        return 1;
    }

    /* Analyse the code */
    compileSuccess = yyparse();

    //yy_flush_buffer();
    yylex_destroy();

/*
    if (fclose(yyin)) {
        fprintf(stderr, "Couldn't close the opened file...\n");
        return 2;
    }
*/
    /* If the compilation was successful, display the graph */
    if (!compileSuccess) {

        /* Check interval values */
        if (argXmin >= argXmax || argYmin >= argYmax) {
            error = "Wrong display window size values...";
            verbose(error);
            return 3;
        } else {

            /* Construct the GraphSetup object */
            if (current_scope.size() > 0) { //check if there is a curve

                //save the curves
                graph->curvesFunctions = functions;

                //set display intervals
                graph->setDisplayYmin = argYmin;
                graph->setDisplayYmax = argYmax;
                graph->setDisplayXmin = argXmin;
                graph->setDisplayXmax = argXmax;

                //set graph label
                graph->graphName = argLabel.c_str();

                //set curves data
                for (size_t i = 0; i < current_scope.size(); ++i) {
                    graph->names.push_back(current_scope[i].c_str());
                    graph->colors.push_back(convertHexToRGBA(functions.at(current_scope[i]).color));
                    graph->plotModes.push_back(functions.at(current_scope[i]).style.c_str());
                    graph->interXmins.push_back(functions.at(current_scope[i]).xInterval.first);
                    graph->interXmaxs.push_back(functions.at(current_scope[i]).xInterval.second);
                }

                /* Add a white color to prevent size 1 colormap */
                graph->colors.push_back(convertHexToRGBA("#FFFFFF"));

                /* Set the boolean, so that the curve points can be computed */
                graph->gotSomething = true;

            } else {
                std::string output("No function to draw...\n");
                verbose(output);
                return 5;
            }

            return EXIT_SUCCESS;
        }

    } else {
        std::string output("Compilation unsuccessful...\n");
        verbose(output);
        return 4;
    }

}
