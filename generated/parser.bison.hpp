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
#line 49 "language/parser.y"

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
    color = 261,                   /* color  */
    style = 262,                   /* style  */
    label = 263,                   /* label  */
    xmin = 264,                    /* xmin  */
    xmax = 265,                    /* xmax  */
    ymin = 266,                    /* ymin  */
    ymax = 267,                    /* ymax  */
    PARAM = 268,                   /* PARAM  */
    NUM = 269,                     /* NUM  */
    SIN = 270,                     /* SIN  */
    COS = 271,                     /* COS  */
    POW = 272,                     /* POW  */
    EXP = 273,                     /* EXP  */
    VAR = 274,                     /* VAR  */
    FOR = 275,                     /* FOR  */
    IF = 276,                      /* IF  */
    ELSE = 277,                    /* ELSE  */
    WHILE = 278,                   /* WHILE  */
    TAN = 279,                     /* TAN  */
    ARCCOS = 280,                  /* ARCCOS  */
    ARCSIN = 281,                  /* ARCSIN  */
    ARCTAN = 282,                  /* ARCTAN  */
    COSH = 283,                    /* COSH  */
    SINH = 284,                    /* SINH  */
    TANH = 285,                    /* TANH  */
    ARCSINH = 286,                 /* ARCSINH  */
    ARCCOSH = 287,                 /* ARCCOSH  */
    ARCTANH = 288,                 /* ARCTANH  */
    SQRT = 289,                    /* SQRT  */
    LOG = 290,                     /* LOG  */
    DRAW = 291,                    /* DRAW  */
    JMP = 292,                     /* JMP  */
    JMPCOND = 293,                 /* JMPCOND  */
    PLUS_EQUAL = 294,              /* PLUS_EQUAL  */
    MIN_EQUAL = 295,               /* MIN_EQUAL  */
    TIMES_EQUAL = 296,             /* TIMES_EQUAL  */
    DIV_EQUAL = 297,               /* DIV_EQUAL  */
    EQUAL = 298,                   /* EQUAL  */
    NOT_EQ = 299,                  /* NOT_EQ  */
    INF_STRICT = 300,              /* INF_STRICT  */
    SUP_STRICT = 301,              /* SUP_STRICT  */
    INF = 302,                     /* INF  */
    SUP = 303,                     /* SUP  */
    AND = 304,                     /* AND  */
    OR = 305,                      /* OR  */
    NOT = 306                      /* NOT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 56 "language/parser.y"

    double dvalue;
    char svalue[50];
    bool bvalue;
    type_adresse adresse;

#line 132 "generated/parser.bison.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GENERATED_PARSER_BISON_HPP_INCLUDED  */
