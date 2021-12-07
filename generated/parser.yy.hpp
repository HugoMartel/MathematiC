/* A Bison parser, made by GNU Bison 3.7.6.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_GENERATED_PARSER_YY_HPP_INCLUDED
# define YY_YY_GENERATED_PARSER_YY_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 122 "language/parser.y"

    typedef struct adr {
        int jmp;  // adresse du jmp
        int jc;  // adrese  du jc
    } type_adresse;
  

#line 57 "generated/parser.yy.hpp"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    PI = 258,                      /* PI  */
    E = 259,                       /* E  */
    PHI = 260,                     /* PHI  */
    var = 261,                     /* var  */
    DEF = 262,                     /* DEF  */
    in = 263,                      /* in  */
    arrow = 264,                   /* arrow  */
    RETURN = 265,                  /* RETURN  */
    color = 266,                   /* color  */
    style = 267,                   /* style  */
    label = 268,                   /* label  */
    xmin = 269,                    /* xmin  */
    xmax = 270,                    /* xmax  */
    ymin = 271,                    /* ymin  */
    ymax = 272,                    /* ymax  */
    COLOR_PARAM = 273,             /* COLOR_PARAM  */
    STYLE_PARAM = 274,             /* STYLE_PARAM  */
    STRING = 275,                  /* STRING  */
    NUM = 276,                     /* NUM  */
    SIN = 277,                     /* SIN  */
    COS = 278,                     /* COS  */
    POW = 279,                     /* POW  */
    EXP = 280,                     /* EXP  */
    VAR = 281,                     /* VAR  */
    FOR = 282,                     /* FOR  */
    IF = 283,                      /* IF  */
    ELSE = 284,                    /* ELSE  */
    WHILE = 285,                   /* WHILE  */
    TAN = 286,                     /* TAN  */
    ARCCOS = 287,                  /* ARCCOS  */
    ARCSIN = 288,                  /* ARCSIN  */
    ARCTAN = 289,                  /* ARCTAN  */
    COSH = 290,                    /* COSH  */
    SINH = 291,                    /* SINH  */
    TANH = 292,                    /* TANH  */
    ARCSINH = 293,                 /* ARCSINH  */
    ARCCOSH = 294,                 /* ARCCOSH  */
    ARCTANH = 295,                 /* ARCTANH  */
    SQRT = 296,                    /* SQRT  */
    LOG = 297,                     /* LOG  */
    DRAW = 298,                    /* DRAW  */
    JMP = 299,                     /* JMP  */
    JMPCOND = 300,                 /* JMPCOND  */
    ASSIGN = 301,                  /* ASSIGN  */
    CALL = 302,                    /* CALL  */
    PLUS = 303,                    /* PLUS  */
    MIN = 304,                     /* MIN  */
    TIMES = 305,                   /* TIMES  */
    DIV = 306,                     /* DIV  */
    PLUS_EQUAL = 307,              /* PLUS_EQUAL  */
    MIN_EQUAL = 308,               /* MIN_EQUAL  */
    TIMES_EQUAL = 309,             /* TIMES_EQUAL  */
    DIV_EQUAL = 310,               /* DIV_EQUAL  */
    EQUAL = 311,                   /* EQUAL  */
    NOT_EQ = 312,                  /* NOT_EQ  */
    INF_STRICT = 313,              /* INF_STRICT  */
    SUP_STRICT = 314,              /* SUP_STRICT  */
    INF = 315,                     /* INF  */
    SUP = 316,                     /* SUP  */
    AND = 317,                     /* AND  */
    OR = 318,                      /* OR  */
    NOT = 319                      /* NOT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 129 "language/parser.y"

    double dvalue;
    char svalue[50];
    bool bvalue;
    type_adresse adresse;

#line 145 "generated/parser.yy.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);
/* "%code provides" blocks.  */
#line 111 "language/parser.y"

    /**
     * Compile the code to generate the functions to then use to draw
     * @param[in]   filename    file to open to read the code from
     * @param[out]  func        Function map storing generated functions in the use written code
     * @return      0: success, 1: open error, 2: close error, 3: display interval error, 4: compilation error
     */
    int compileCode(const char *filename);

#line 168 "generated/parser.yy.hpp"

#endif /* !YY_YY_GENERATED_PARSER_YY_HPP_INCLUDED  */
