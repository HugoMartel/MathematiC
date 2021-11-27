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
    arrow = 261,                   /* arrow  */
    RETURN = 262,                  /* RETURN  */
    color = 263,                   /* color  */
    style = 264,                   /* style  */
    label = 265,                   /* label  */
    xmin = 266,                    /* xmin  */
    xmax = 267,                    /* xmax  */
    ymin = 268,                    /* ymin  */
    ymax = 269,                    /* ymax  */
    PARAM = 270,                   /* PARAM  */
    STRING = 271,                  /* STRING  */
    NUM = 272,                     /* NUM  */
    SIN = 273,                     /* SIN  */
    COS = 274,                     /* COS  */
    POW = 275,                     /* POW  */
    EXP = 276,                     /* EXP  */
    VAR = 277,                     /* VAR  */
    FOR = 278,                     /* FOR  */
    IF = 279,                      /* IF  */
    ELSE = 280,                    /* ELSE  */
    WHILE = 281,                   /* WHILE  */
    TAN = 282,                     /* TAN  */
    ARCCOS = 283,                  /* ARCCOS  */
    ARCSIN = 284,                  /* ARCSIN  */
    ARCTAN = 285,                  /* ARCTAN  */
    COSH = 286,                    /* COSH  */
    SINH = 287,                    /* SINH  */
    TANH = 288,                    /* TANH  */
    ARCSINH = 289,                 /* ARCSINH  */
    ARCCOSH = 290,                 /* ARCCOSH  */
    ARCTANH = 291,                 /* ARCTANH  */
    SQRT = 292,                    /* SQRT  */
    LOG = 293,                     /* LOG  */
    DRAW = 294,                    /* DRAW  */
    JMP = 295,                     /* JMP  */
    JMPCOND = 296,                 /* JMPCOND  */
    PLUS_EQUAL = 297,              /* PLUS_EQUAL  */
    MIN_EQUAL = 298,               /* MIN_EQUAL  */
    TIMES_EQUAL = 299,             /* TIMES_EQUAL  */
    DIV_EQUAL = 300,               /* DIV_EQUAL  */
    EQUAL = 301,                   /* EQUAL  */
    NOT_EQ = 302,                  /* NOT_EQ  */
    INF_STRICT = 303,              /* INF_STRICT  */
    SUP_STRICT = 304,              /* SUP_STRICT  */
    INF = 305,                     /* INF  */
    SUP = 306,                     /* SUP  */
    AND = 307,                     /* AND  */
    OR = 308,                      /* OR  */
    NOT = 309                      /* NOT  */
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

#line 135 "generated/parser.bison.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GENERATED_PARSER_BISON_HPP_INCLUDED  */
