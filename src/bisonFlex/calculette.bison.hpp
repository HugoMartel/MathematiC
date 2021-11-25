/* A Bison parser, made by GNU Bison 3.0.5.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

#ifndef YY_YY_CALCULETTE_BISON_HPP_INCLUDED
# define YY_YY_CALCULETTE_BISON_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 49 "calculette.y" /* yacc.c:1910  */

    typedef struct adr {
        int jmp;  // adresse du jmp
        int jc;  // adrese  du jc
    } type_adresse;
  

#line 52 "calculette.bison.hpp" /* yacc.c:1910  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUM = 258,
    SIN = 259,
    COS = 260,
    POW = 261,
    EXP = 262,
    VAR = 263,
    FOR = 264,
    IF = 265,
    ELSE = 266,
    WHILE = 267,
    TAN = 268,
    ARCOS = 269,
    ARCSIN = 270,
    ARCTAN = 271,
    COSH = 272,
    SINH = 273,
    TANH = 274,
    ARCSINH = 275,
    ARCOSH = 276,
    ARCTANH = 277,
    SQRT = 278,
    LOG = 279,
    DRAWPARAM = 280,
    DRAW = 281,
    JMP = 282,
    JMPCOND = 283,
    PLUS_EQUAL = 284,
    MIN_EQUAL = 285,
    TIMES_EQUAL = 286,
    DIV_EQUAL = 287,
    EQUAL = 288,
    NOT_EQ = 289,
    INF_STRICT = 290,
    SUP_STRICT = 291,
    INF = 292,
    SUP = 293,
    AND = 294,
    OR = 295,
    NOT = 296
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 56 "calculette.y" /* yacc.c:1910  */

    double dvalue;
    char svalue[50];
    bool bvalue;
    type_adresse adresse;

#line 113 "calculette.bison.hpp" /* yacc.c:1910  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CALCULETTE_BISON_HPP_INCLUDED  */
