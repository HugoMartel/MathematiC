/* A Bison parser, made by GNU Bison 3.0.5.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "calculette.y" /* yacc.c:339  */

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

#line 113 "calculette.bison.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "calculette.bison.hpp".  */
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
#line 49 "calculette.y" /* yacc.c:355  */

    typedef struct adr {
        int jmp;  // adresse du jmp
        int jc;  // adrese  du jc
    } type_adresse;
  

#line 151 "calculette.bison.cpp" /* yacc.c:355  */

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
#line 56 "calculette.y" /* yacc.c:355  */

    double dvalue;
    char svalue[50];
    bool bvalue;
    type_adresse adresse;

#line 212 "calculette.bison.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CALCULETTE_BISON_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 229 "calculette.bison.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   523

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  7
/* YYNRULES -- Number of rules.  */
#define YYNRULES  49
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  150

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      48,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    56,     2,
      54,    55,    44,    42,    58,    43,     2,    45,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    52,     2,
       2,    47,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    51,     2,    53,    46,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    49,    57,    50,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   121,   121,   122,   125,   126,   127,   131,   127,   142,
     145,   150,   151,   152,   153,   154,   155,   156,   157,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   182,   187,
     188,   189,   190,   191,   192,   193,   201,   218,   235,   252
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "SIN", "COS", "POW", "EXP", "VAR",
  "FOR", "IF", "ELSE", "WHILE", "TAN", "ARCOS", "ARCSIN", "ARCTAN", "COSH",
  "SINH", "TANH", "ARCSINH", "ARCOSH", "ARCTANH", "SQRT", "LOG",
  "DRAWPARAM", "DRAW", "JMP", "JMPCOND", "PLUS_EQUAL", "MIN_EQUAL",
  "TIMES_EQUAL", "DIV_EQUAL", "EQUAL", "NOT_EQ", "INF_STRICT",
  "SUP_STRICT", "INF", "SUP", "AND", "OR", "NOT", "'+'", "'-'", "'*'",
  "'/'", "'^'", "'='", "'\\n'", "'{'", "'}'", "'['", "':'", "']'", "'('",
  "')'", "'&'", "'|'", "','", "$accept", "lignes", "instruction", "$@1",
  "$@2", "logic", "expr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,    43,    45,    42,    47,    94,    61,    10,   123,
     125,    91,    58,    93,    40,    41,    38,   124,    44
};
# endif

#define YYPACT_NINF -102

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-102)))

#define YYTABLE_NINF -8

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -102,    83,  -102,  -102,   -51,   -41,   -26,   -24,   -20,   274,
     274,   274,    -2,    -1,     0,     1,     2,     3,     4,     5,
       6,    17,    20,    21,   274,    28,   466,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   139,    29,   266,    30,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   213,  -102,   274,   274,   274,   274,   274,   274,
     274,   218,   275,    66,   291,   466,   466,   466,   466,   -49,
     274,    32,   274,   274,   274,   274,   274,   274,   274,   274,
      33,   296,   312,   317,   333,   338,   354,   359,   375,   380,
     396,   401,   417,  -102,   -40,   -40,    16,    16,    16,   466,
     466,  -102,  -102,   274,  -102,   423,  -102,   466,   466,   466,
     466,   466,   466,   466,   466,  -102,  -102,  -102,  -102,  -102,
    -102,  -102,  -102,  -102,  -102,  -102,  -102,  -102,   439,   274,
    -102,   126,  -102,   445,   148,  -102,   274,    27,   461,    71,
      35,    36,    65,    67,  -102,  -102,   200,   222,  -102,  -102
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     4,     1,    19,     0,     0,     0,     0,    44,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     5,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     3,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    46,    47,    48,    49,    45,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    32,    33,    34,    35,    36,    39,    37,
      38,    20,    21,     0,    41,     0,     6,    15,    16,    14,
      13,    12,    11,    17,    18,     2,    22,    23,    24,    25,
      27,    26,    28,    30,    29,    31,    43,    42,     0,     0,
       2,     4,    40,     0,     4,    10,     0,     0,     0,     0,
       0,     0,     0,     0,     2,     2,     4,     4,     9,     8
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -102,  -101,  -102,  -102,  -102,   103,    -9
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    25,   130,   137,    37,    26
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      36,    38,    38,    27,    56,    57,    58,    59,    60,    31,
      32,    33,    34,    28,   131,    52,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    35,    29,   134,
      30,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,   146,   147,    94,    95,    96,    97,    98,
      99,   100,    40,    41,    42,    43,    44,    45,    46,    47,
      48,   105,    58,   107,   108,   109,   110,   111,   112,   113,
     114,    49,    59,    60,    50,    51,    53,   139,    71,    80,
     106,   115,   141,     2,   142,   143,     3,     4,     5,     6,
       7,     8,     9,    10,   128,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    54,    55,
      56,    57,    58,   144,    39,   145,     0,     0,     0,     0,
     133,     0,    59,    60,   103,     0,     0,   138,     0,     3,
       4,     5,     6,     7,     8,     9,    10,    24,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,     3,     4,     5,     6,     7,     8,     9,    10,     0,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,     0,     0,     0,   135,     0,     0,     0,
      24,    54,    55,    56,    57,    58,     0,     0,     0,     0,
      70,     0,     0,     0,     0,    59,    60,     0,    -7,     0,
       0,     0,    24,     3,     4,     5,     6,     7,     8,     9,
      10,     0,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,     3,     4,     5,     6,     7,
       8,     9,    10,     0,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,     0,     0,     0,
     148,     0,     0,     0,    24,    54,    55,    56,    57,    58,
      54,    55,    56,    57,    58,     0,     0,     0,    93,    59,
      60,     0,   149,   101,    59,    60,    24,     3,     4,     5,
       6,     7,     8,     0,     0,     0,     0,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    72,
      73,    74,    75,    76,    77,    78,    79,     0,    54,    55,
      56,    57,    58,     0,     0,     0,     0,    54,    55,    56,
      57,    58,    59,    60,     0,     0,     0,     0,    24,     0,
     102,    59,    60,    54,    55,    56,    57,    58,    54,    55,
      56,    57,    58,     0,     0,     0,   104,    59,    60,     0,
       0,   116,    59,    60,    54,    55,    56,    57,    58,    54,
      55,    56,    57,    58,     0,     0,     0,   117,    59,    60,
       0,     0,   118,    59,    60,    54,    55,    56,    57,    58,
      54,    55,    56,    57,    58,     0,     0,     0,   119,    59,
      60,     0,     0,   120,    59,    60,    54,    55,    56,    57,
      58,    54,    55,    56,    57,    58,     0,     0,     0,   121,
      59,    60,     0,     0,   122,    59,    60,    54,    55,    56,
      57,    58,    54,    55,    56,    57,    58,     0,     0,     0,
     123,    59,    60,     0,     0,   124,    59,    60,    54,    55,
      56,    57,    58,    54,    55,    56,    57,    58,     0,     0,
       0,   125,    59,    60,     0,     0,   126,    59,    60,    54,
      55,    56,    57,    58,     0,    54,    55,    56,    57,    58,
       0,     0,   127,    59,    60,   129,     0,     0,     0,    59,
      60,    54,    55,    56,    57,    58,     0,    54,    55,    56,
      57,    58,     0,     0,   132,    59,    60,   136,     0,     0,
       0,    59,    60,    54,    55,    56,    57,    58,    54,    55,
      56,    57,    58,     0,   140,     0,     0,    59,    60,     0,
       0,     0,    59,    60
};

static const yytype_int16 yycheck[] =
{
       9,    10,    11,    54,    44,    45,    46,    56,    57,    29,
      30,    31,    32,    54,   115,    24,    56,    57,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    47,    54,   130,
      54,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,   144,   145,    54,    55,    56,    57,    58,
      59,    60,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    70,    46,    72,    73,    74,    75,    76,    77,    78,
      79,    54,    56,    57,    54,    54,    48,    50,    49,    49,
      48,    48,    11,     0,    49,    49,     3,     4,     5,     6,
       7,     8,     9,    10,   103,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    42,    43,
      44,    45,    46,    48,    11,    48,    -1,    -1,    -1,    -1,
     129,    -1,    56,    57,    58,    -1,    -1,   136,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    54,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    50,    -1,    -1,    -1,
      54,    42,    43,    44,    45,    46,    -1,    -1,    -1,    -1,
      51,    -1,    -1,    -1,    -1,    56,    57,    -1,    50,    -1,
      -1,    -1,    54,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    -1,    -1,    -1,
      50,    -1,    -1,    -1,    54,    42,    43,    44,    45,    46,
      42,    43,    44,    45,    46,    -1,    -1,    -1,    55,    56,
      57,    -1,    50,    55,    56,    57,    54,     3,     4,     5,
       6,     7,     8,    -1,    -1,    -1,    -1,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    42,    43,
      44,    45,    46,    -1,    -1,    -1,    -1,    42,    43,    44,
      45,    46,    56,    57,    -1,    -1,    -1,    -1,    54,    -1,
      55,    56,    57,    42,    43,    44,    45,    46,    42,    43,
      44,    45,    46,    -1,    -1,    -1,    55,    56,    57,    -1,
      -1,    55,    56,    57,    42,    43,    44,    45,    46,    42,
      43,    44,    45,    46,    -1,    -1,    -1,    55,    56,    57,
      -1,    -1,    55,    56,    57,    42,    43,    44,    45,    46,
      42,    43,    44,    45,    46,    -1,    -1,    -1,    55,    56,
      57,    -1,    -1,    55,    56,    57,    42,    43,    44,    45,
      46,    42,    43,    44,    45,    46,    -1,    -1,    -1,    55,
      56,    57,    -1,    -1,    55,    56,    57,    42,    43,    44,
      45,    46,    42,    43,    44,    45,    46,    -1,    -1,    -1,
      55,    56,    57,    -1,    -1,    55,    56,    57,    42,    43,
      44,    45,    46,    42,    43,    44,    45,    46,    -1,    -1,
      -1,    55,    56,    57,    -1,    -1,    55,    56,    57,    42,
      43,    44,    45,    46,    -1,    42,    43,    44,    45,    46,
      -1,    -1,    55,    56,    57,    52,    -1,    -1,    -1,    56,
      57,    42,    43,    44,    45,    46,    -1,    42,    43,    44,
      45,    46,    -1,    -1,    55,    56,    57,    52,    -1,    -1,
      -1,    56,    57,    42,    43,    44,    45,    46,    42,    43,
      44,    45,    46,    -1,    53,    -1,    -1,    56,    57,    -1,
      -1,    -1,    56,    57
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    60,     0,     3,     4,     5,     6,     7,     8,     9,
      10,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    54,    61,    65,    54,    54,    54,
      54,    29,    30,    31,    32,    47,    65,    64,    65,    64,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    65,    48,    42,    43,    44,    45,    46,    56,
      57,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      51,    49,    33,    34,    35,    36,    37,    38,    39,    40,
      49,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    55,    65,    65,    65,    65,    65,    65,
      65,    55,    55,    58,    55,    65,    48,    65,    65,    65,
      65,    65,    65,    65,    65,    48,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    65,    52,
      62,    60,    55,    65,    60,    50,    52,    63,    65,    50,
      53,    11,    49,    49,    48,    48,    60,    60,    50,    50
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    59,    60,    60,    61,    61,    62,    63,    61,    61,
      61,    64,    64,    64,    64,    64,    64,    64,    64,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     3,     0,     1,     0,     0,    13,    13,
       6,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     3,     3,     3,     3,     3,     3,     3,     3,
       6,     4,     4,     4,     1,     3,     3,     3,     3,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 121 "calculette.y" /* yacc.c:1648  */
    { /* deletes */ }
#line 1469 "calculette.bison.cpp" /* yacc.c:1648  */
    break;

  case 3:
#line 122 "calculette.y" /* yacc.c:1648  */
    {}
#line 1475 "calculette.bison.cpp" /* yacc.c:1648  */
    break;

  case 4:
#line 125 "calculette.y" /* yacc.c:1648  */
    {}
#line 1481 "calculette.bison.cpp" /* yacc.c:1648  */
    break;

  case 5:
#line 126 "calculette.y" /* yacc.c:1648  */
    { printf("= %g\n", (yyvsp[0].DOUBLE));}
#line 1487 "calculette.bison.cpp" /* yacc.c:1648  */
    break;

  case 6:
#line 127 "calculette.y" /* yacc.c:1648  */
    { // Je sauvegarde l'endroit actuel pour revenir mofifier l'adresse 
                                          // lorsqu'elle sera connue (celle du JC)
                                          (yyvsp[-3].ADDRESS).jc = ic;
                                          add_instruction(JMPCOND);  }
#line 1496 "calculette.bison.cpp" /* yacc.c:1648  */
    break;

  case 7:
#line 131 "calculette.y" /* yacc.c:1648  */
    { // Je sauvegarde l'endroit actuel pour revenir mofifier l'adresse 
                                          // lorsqu'elle sera connue (celle du JMP)
                                          (yyvsp[-5].ADDRESS).jmp = ic;
                                          add_instruction(JMP);
                                          // Je mets à jour l'adresse du saut conditionnel
                                          code_genere[(yyvsp[-5].ADDRESS).jc].value = ic;
                                        }
#line 1508 "calculette.bison.cpp" /* yacc.c:1648  */
    break;

  case 8:
#line 140 "calculette.y" /* yacc.c:1648  */
    { // Je mets à jour l'adresse du saut inconditionnel
                                          code_genere[(yyvsp[-12].ADDRESS).jmp].value = ic; }
#line 1515 "calculette.bison.cpp" /* yacc.c:1648  */
    break;

  case 9:
#line 144 "calculette.y" /* yacc.c:1648  */
    { add_instruction(FOR); }
#line 1521 "calculette.bison.cpp" /* yacc.c:1648  */
    break;

  case 10:
#line 147 "calculette.y" /* yacc.c:1648  */
    { add_instruction(WHILE); }
#line 1527 "calculette.bison.cpp" /* yacc.c:1648  */
    break;

  case 11:
#line 150 "calculette.y" /* yacc.c:1648  */
    { add_instruction(SUP); }
#line 1533 "calculette.bison.cpp" /* yacc.c:1648  */
    break;

  case 12:
#line 151 "calculette.y" /* yacc.c:1648  */
    { add_instruction(INF); }
#line 1539 "calculette.bison.cpp" /* yacc.c:1648  */
    break;

  case 13:
#line 152 "calculette.y" /* yacc.c:1648  */
    { add_instruction(SUP_STRICT); }
#line 1545 "calculette.bison.cpp" /* yacc.c:1648  */
    break;

  case 14:
#line 153 "calculette.y" /* yacc.c:1648  */
    { add_instruction(INF_STRICT); }
#line 1551 "calculette.bison.cpp" /* yacc.c:1648  */
    break;

  case 15:
#line 154 "calculette.y" /* yacc.c:1648  */
    { add_instruction(EQUAL); }
#line 1557 "calculette.bison.cpp" /* yacc.c:1648  */
    break;

  case 16:
#line 155 "calculette.y" /* yacc.c:1648  */
    { add_instruction(NOT_EQ); }
#line 1563 "calculette.bison.cpp" /* yacc.c:1648  */
    break;

  case 17:
#line 156 "calculette.y" /* yacc.c:1648  */
    { add_instruction(AND); }
#line 1569 "calculette.bison.cpp" /* yacc.c:1648  */
    break;

  case 18:
#line 157 "calculette.y" /* yacc.c:1648  */
    { add_instruction(OR); }
#line 1575 "calculette.bison.cpp" /* yacc.c:1648  */
    break;

  case 19:
#line 160 "calculette.y" /* yacc.c:1648  */
    { add_instruction(NUM, (yyvsp[0].DOUBLE)); }
#line 1581 "calculette.bison.cpp" /* yacc.c:1648  */
    break;

  case 20:
#line 161 "calculette.y" /* yacc.c:1648  */
    { add_instruction(SIN); }
#line 1587 "calculette.bison.cpp" /* yacc.c:1648  */
    break;

  case 21:
#line 162 "calculette.y" /* yacc.c:1648  */
    { add_instruction(COS); }
#line 1593 "calculette.bison.cpp" /* yacc.c:1648  */
    break;

  case 22:
#line 163 "calculette.y" /* yacc.c:1648  */
    { add_instruction(TAN); }
#line 1599 "calculette.bison.cpp" /* yacc.c:1648  */
    break;

  case 23:
#line 164 "calculette.y" /* yacc.c:1648  */
    { add_instruction(ARCOS); }
#line 1605 "calculette.bison.cpp" /* yacc.c:1648  */
    break;

  case 24:
#line 165 "calculette.y" /* yacc.c:1648  */
    { add_instruction(ARCSIN); }
#line 1611 "calculette.bison.cpp" /* yacc.c:1648  */
    break;

  case 25:
#line 166 "calculette.y" /* yacc.c:1648  */
    { add_instruction(ARCTAN); }
#line 1617 "calculette.bison.cpp" /* yacc.c:1648  */
    break;

  case 26:
#line 167 "calculette.y" /* yacc.c:1648  */
    { add_instruction(SINH); }
#line 1623 "calculette.bison.cpp" /* yacc.c:1648  */
    break;

  case 27:
#line 168 "calculette.y" /* yacc.c:1648  */
    { add_instruction(COSH); }
#line 1629 "calculette.bison.cpp" /* yacc.c:1648  */
    break;

  case 28:
#line 169 "calculette.y" /* yacc.c:1648  */
    { add_instruction(TANH); }
#line 1635 "calculette.bison.cpp" /* yacc.c:1648  */
    break;

  case 29:
#line 170 "calculette.y" /* yacc.c:1648  */
    { add_instruction(ARCOSH); }
#line 1641 "calculette.bison.cpp" /* yacc.c:1648  */
    break;

  case 30:
#line 171 "calculette.y" /* yacc.c:1648  */
    { add_instruction(ARCSINH); }
#line 1647 "calculette.bison.cpp" /* yacc.c:1648  */
    break;

  case 31:
#line 172 "calculette.y" /* yacc.c:1648  */
    { add_instruction(ARCTANH); }
#line 1653 "calculette.bison.cpp" /* yacc.c:1648  */
    break;

  case 32:
#line 173 "calculette.y" /* yacc.c:1648  */
    { (yyval.DOUBLE) = (yyvsp[-1].DOUBLE); }
#line 1659 "calculette.bison.cpp" /* yacc.c:1648  */
    break;

  case 33:
#line 174 "calculette.y" /* yacc.c:1648  */
    { (yyval.DOUBLE) = (yyvsp[-2].DOUBLE) + (yyvsp[0].DOUBLE); printf("%g + %g = %g\n", (yyvsp[-2].DOUBLE), (yyvsp[0].DOUBLE), (yyval.DOUBLE)); }
#line 1665 "calculette.bison.cpp" /* yacc.c:1648  */
    break;

  case 34:
#line 175 "calculette.y" /* yacc.c:1648  */
    { (yyval.DOUBLE) = (yyvsp[-2].DOUBLE) - (yyvsp[0].DOUBLE); printf("%g - %g = %g\n", (yyvsp[-2].DOUBLE), (yyvsp[0].DOUBLE), (yyval.DOUBLE)); }
#line 1671 "calculette.bison.cpp" /* yacc.c:1648  */
    break;

  case 35:
#line 176 "calculette.y" /* yacc.c:1648  */
    { (yyval.DOUBLE) = (yyvsp[-2].DOUBLE) * (yyvsp[0].DOUBLE); printf("%g * %g = %g\n", (yyvsp[-2].DOUBLE), (yyvsp[0].DOUBLE), (yyval.DOUBLE)); }
#line 1677 "calculette.bison.cpp" /* yacc.c:1648  */
    break;

  case 36:
#line 177 "calculette.y" /* yacc.c:1648  */
    { (yyval.DOUBLE) = (yyvsp[-2].DOUBLE) / (yyvsp[0].DOUBLE); printf("%g / %g = %g\n", (yyvsp[-2].DOUBLE), (yyvsp[0].DOUBLE), (yyval.DOUBLE)); }
#line 1683 "calculette.bison.cpp" /* yacc.c:1648  */
    break;

  case 37:
#line 178 "calculette.y" /* yacc.c:1648  */
    { int tmp1 = (int)(yyvsp[-2].DOUBLE);
                              int tmp2 = (int)(yyvsp[0].DOUBLE);
                              (yyval.DOUBLE) = tmp1 & tmp2; 
                              printf("%d & %d = %d\n", tmp1, tmp2, (int)(yyval.DOUBLE)); }
#line 1692 "calculette.bison.cpp" /* yacc.c:1648  */
    break;

  case 38:
#line 182 "calculette.y" /* yacc.c:1648  */
    { int tmp1 = (int)(yyvsp[-2].DOUBLE); 
                              int tmp2 = (int)(yyvsp[0].DOUBLE); 
                              (yyval.DOUBLE) = tmp1 | tmp2; 
                              printf("%d | %d = %d\n", tmp1, tmp2, (int)(yyval.DOUBLE)); 
                            }
#line 1702 "calculette.bison.cpp" /* yacc.c:1648  */
    break;

  case 39:
#line 187 "calculette.y" /* yacc.c:1648  */
    { (yyval.DOUBLE) = pow((yyvsp[-2].DOUBLE),(yyvsp[0].DOUBLE)); printf("%g^%g = %g\n", (yyvsp[-2].DOUBLE), (yyvsp[0].DOUBLE), (yyval.DOUBLE)); }
#line 1708 "calculette.bison.cpp" /* yacc.c:1648  */
    break;

  case 40:
#line 188 "calculette.y" /* yacc.c:1648  */
    { add_instruction(POW); }
#line 1714 "calculette.bison.cpp" /* yacc.c:1648  */
    break;

  case 41:
#line 189 "calculette.y" /* yacc.c:1648  */
    { add_instruction(EXP);  }
#line 1720 "calculette.bison.cpp" /* yacc.c:1648  */
    break;

  case 42:
#line 190 "calculette.y" /* yacc.c:1648  */
    { add_instruction(LOG);  }
#line 1726 "calculette.bison.cpp" /* yacc.c:1648  */
    break;

  case 43:
#line 191 "calculette.y" /* yacc.c:1648  */
    { add_instruction(SQRT);  }
#line 1732 "calculette.bison.cpp" /* yacc.c:1648  */
    break;

  case 44:
#line 192 "calculette.y" /* yacc.c:1648  */
    { add_instruction (VAR, 0, (yyvsp[0].STRING)); }
#line 1738 "calculette.bison.cpp" /* yacc.c:1648  */
    break;

  case 45:
#line 193 "calculette.y" /* yacc.c:1648  */
    {
    (yyval.DOUBLE) = (yyvsp[0].DOUBLE);

    floatVars[(yyvsp[-2].STRING)] = float((yyvsp[0].DOUBLE));

    printf("%s <- %g\n", (yyvsp[-2].STRING), (yyvsp[0].DOUBLE));
}
#line 1750 "calculette.bison.cpp" /* yacc.c:1648  */
    break;

  case 46:
#line 201 "calculette.y" /* yacc.c:1648  */
    {
    float tmp;

    /* Retrieve value from variable */
    if (floatVars.count((yyvsp[-2].STRING))) {
        tmp = floatVars.at((yyvsp[-2].STRING)) + (yyvsp[0].DOUBLE);
        printf("%s += %g (float)\n", (yyvsp[-2].STRING), (yyvsp[0].DOUBLE));
    } else {
        printf("Using uninitialized variable %s...\n", (yyvsp[-2].STRING));
    }
    
    /* Output */
    (yyval.DOUBLE) = tmp;

    floatVars[(yyvsp[-2].STRING)] = float(tmp);
}
#line 1771 "calculette.bison.cpp" /* yacc.c:1648  */
    break;

  case 47:
#line 218 "calculette.y" /* yacc.c:1648  */
    {
    float tmp;

    /* Retrieve value from variable */
    if (floatVars.count((yyvsp[-2].STRING))) {
        tmp = floatVars.at((yyvsp[-2].STRING)) - (yyvsp[0].DOUBLE);
        printf("%s -= %g (float)\n", (yyvsp[-2].STRING), (yyvsp[0].DOUBLE));
    } else {
        printf("Using uninitialized variable %s...\n", (yyvsp[-2].STRING));
    }
     
    /* Output */
    (yyval.DOUBLE) = tmp;

    floatVars[(yyvsp[-2].STRING)] = float(tmp);
}
#line 1792 "calculette.bison.cpp" /* yacc.c:1648  */
    break;

  case 48:
#line 235 "calculette.y" /* yacc.c:1648  */
    {
    float tmp;

    /* Retrieve value from variable */
    if (floatVars.count((yyvsp[-2].STRING))) {
        tmp = floatVars.at((yyvsp[-2].STRING)) * (yyvsp[0].DOUBLE);
        printf("%s *= %g (float)\n", (yyvsp[-2].STRING), (yyvsp[0].DOUBLE));
    } else {
        printf("Using uninitialized variable %s...\n", (yyvsp[-2].STRING));
    }
     
    /* Output */
    (yyval.DOUBLE) = tmp;

    floatVars[(yyvsp[-2].STRING)] = float(tmp);
}
#line 1813 "calculette.bison.cpp" /* yacc.c:1648  */
    break;

  case 49:
#line 252 "calculette.y" /* yacc.c:1648  */
    {
    float tmp;

    /* Retrieve value from variable */
    if (floatVars.count((yyvsp[-2].STRING))) {
        tmp = floatVars.at((yyvsp[-2].STRING)) / (yyvsp[0].DOUBLE);
        printf("%s /= %g (float)\n", (yyvsp[-2].STRING), (yyvsp[0].DOUBLE));
    } else {
        printf("Using uninitialized variable %s...\n", (yyvsp[-2].STRING));
    }
     
    /* Output */
    (yyval.DOUBLE) = tmp;

    
    floatVars[(yyvsp[-2].STRING)] = float(tmp);
}
#line 1835 "calculette.bison.cpp" /* yacc.c:1648  */
    break;


#line 1839 "calculette.bison.cpp" /* yacc.c:1648  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 270 "calculette.y" /* yacc.c:1907  */


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

