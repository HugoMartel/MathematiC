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

#ifndef YY_YY_GENERATED_PARSER_BISON_HPP_INCLUDED
# define YY_YY_GENERATED_PARSER_BISON_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 100 "language/parser.y"

    typedef struct adr {
        int jmp;  // adresse du jmp
        int jc;  // adrese  du jc
    } type_adresse;
  

#line 57 "generated/parser.bison.hpp"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    var = 258,                     /* var  */
    def = 259,                     /* def  */
    in = 260,                      /* in  */
    arrow = 261,                   /* arrow  */
    RETURN = 262,                  /* RETURN  */
    color = 263,                   /* color  */
    style = 264,                   /* style  */
    label = 265,                   /* label  */
    xmin = 266,                    /* xmin  */
    xmax = 267,                    /* xmax  */
    ymin = 268,                    /* ymin  */
    ymax = 269,                    /* ymax  */
    COLOR_PARAM = 270,             /* COLOR_PARAM  */
    STYLE_PARAM = 271,             /* STYLE_PARAM  */
    STRING = 272,                  /* STRING  */
    NUM = 273,                     /* NUM  */
    SIN = 274,                     /* SIN  */
    COS = 275,                     /* COS  */
    POW = 276,                     /* POW  */
    EXP = 277,                     /* EXP  */
    VAR = 278,                     /* VAR  */
    FOR = 279,                     /* FOR  */
    IF = 280,                      /* IF  */
    ELSE = 281,                    /* ELSE  */
    WHILE = 282,                   /* WHILE  */
    TAN = 283,                     /* TAN  */
    ARCCOS = 284,                  /* ARCCOS  */
    ARCSIN = 285,                  /* ARCSIN  */
    ARCTAN = 286,                  /* ARCTAN  */
    COSH = 287,                    /* COSH  */
    SINH = 288,                    /* SINH  */
    TANH = 289,                    /* TANH  */
    ARCSINH = 290,                 /* ARCSINH  */
    ARCCOSH = 291,                 /* ARCCOSH  */
    ARCTANH = 292,                 /* ARCTANH  */
    SQRT = 293,                    /* SQRT  */
    LOG = 294,                     /* LOG  */
    DRAW = 295,                    /* DRAW  */
    JMP = 296,                     /* JMP  */
    JMPCOND = 297,                 /* JMPCOND  */
    ASSIGN = 298,                  /* ASSIGN  */
    DECLARE = 299,                 /* DECLARE  */
    PLUS = 300,                    /* PLUS  */
    MIN = 301,                     /* MIN  */
    TIMES = 302,                   /* TIMES  */
    DIV = 303,                     /* DIV  */
    PLUS_EQUAL = 304,              /* PLUS_EQUAL  */
    MIN_EQUAL = 305,               /* MIN_EQUAL  */
    TIMES_EQUAL = 306,             /* TIMES_EQUAL  */
    DIV_EQUAL = 307,               /* DIV_EQUAL  */
    EQUAL = 308,                   /* EQUAL  */
    NOT_EQ = 309,                  /* NOT_EQ  */
    INF_STRICT = 310,              /* INF_STRICT  */
    SUP_STRICT = 311,              /* SUP_STRICT  */
    INF = 312,                     /* INF  */
    SUP = 313,                     /* SUP  */
    AND = 314,                     /* AND  */
    OR = 315,                      /* OR  */
    NOT = 316                      /* NOT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 107 "language/parser.y"

    double dvalue;
    char svalue[50];
    bool bvalue;
    type_adresse adresse;

#line 142 "generated/parser.bison.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GENERATED_PARSER_BISON_HPP_INCLUDED  */
