/* A Bison parser, made by GNU Bison 3.7.6.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30706

/* Bison version string.  */
#define YYBISON_VERSION "3.7.6"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "calculette.y"

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

#line 118 "calculette.bison.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "calculette.bison.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_var = 3,                        /* var  */
  YYSYMBOL_def = 4,                        /* def  */
  YYSYMBOL_in = 5,                         /* in  */
  YYSYMBOL_color = 6,                      /* color  */
  YYSYMBOL_style = 7,                      /* style  */
  YYSYMBOL_label = 8,                      /* label  */
  YYSYMBOL_xmin = 9,                       /* xmin  */
  YYSYMBOL_xmax = 10,                      /* xmax  */
  YYSYMBOL_ymin = 11,                      /* ymin  */
  YYSYMBOL_ymax = 12,                      /* ymax  */
  YYSYMBOL_PARAM = 13,                     /* PARAM  */
  YYSYMBOL_NUM = 14,                       /* NUM  */
  YYSYMBOL_SIN = 15,                       /* SIN  */
  YYSYMBOL_COS = 16,                       /* COS  */
  YYSYMBOL_POW = 17,                       /* POW  */
  YYSYMBOL_EXP = 18,                       /* EXP  */
  YYSYMBOL_VAR = 19,                       /* VAR  */
  YYSYMBOL_FOR = 20,                       /* FOR  */
  YYSYMBOL_IF = 21,                        /* IF  */
  YYSYMBOL_ELSE = 22,                      /* ELSE  */
  YYSYMBOL_WHILE = 23,                     /* WHILE  */
  YYSYMBOL_TAN = 24,                       /* TAN  */
  YYSYMBOL_ARCCOS = 25,                    /* ARCCOS  */
  YYSYMBOL_ARCSIN = 26,                    /* ARCSIN  */
  YYSYMBOL_ARCTAN = 27,                    /* ARCTAN  */
  YYSYMBOL_COSH = 28,                      /* COSH  */
  YYSYMBOL_SINH = 29,                      /* SINH  */
  YYSYMBOL_TANH = 30,                      /* TANH  */
  YYSYMBOL_ARCSINH = 31,                   /* ARCSINH  */
  YYSYMBOL_ARCCOSH = 32,                   /* ARCCOSH  */
  YYSYMBOL_ARCTANH = 33,                   /* ARCTANH  */
  YYSYMBOL_SQRT = 34,                      /* SQRT  */
  YYSYMBOL_LOG = 35,                       /* LOG  */
  YYSYMBOL_DRAW = 36,                      /* DRAW  */
  YYSYMBOL_JMP = 37,                       /* JMP  */
  YYSYMBOL_JMPCOND = 38,                   /* JMPCOND  */
  YYSYMBOL_PLUS_EQUAL = 39,                /* PLUS_EQUAL  */
  YYSYMBOL_MIN_EQUAL = 40,                 /* MIN_EQUAL  */
  YYSYMBOL_TIMES_EQUAL = 41,               /* TIMES_EQUAL  */
  YYSYMBOL_DIV_EQUAL = 42,                 /* DIV_EQUAL  */
  YYSYMBOL_EQUAL = 43,                     /* EQUAL  */
  YYSYMBOL_NOT_EQ = 44,                    /* NOT_EQ  */
  YYSYMBOL_INF_STRICT = 45,                /* INF_STRICT  */
  YYSYMBOL_SUP_STRICT = 46,                /* SUP_STRICT  */
  YYSYMBOL_INF = 47,                       /* INF  */
  YYSYMBOL_SUP = 48,                       /* SUP  */
  YYSYMBOL_AND = 49,                       /* AND  */
  YYSYMBOL_OR = 50,                        /* OR  */
  YYSYMBOL_NOT = 51,                       /* NOT  */
  YYSYMBOL_52_ = 52,                       /* '+'  */
  YYSYMBOL_53_ = 53,                       /* '-'  */
  YYSYMBOL_54_ = 54,                       /* '*'  */
  YYSYMBOL_55_ = 55,                       /* '/'  */
  YYSYMBOL_56_ = 56,                       /* '^'  */
  YYSYMBOL_57_ = 57,                       /* '='  */
  YYSYMBOL_58_ = 58,                       /* ' '  */
  YYSYMBOL_59_ = 59,                       /* ';'  */
  YYSYMBOL_60_ = 60,                       /* '('  */
  YYSYMBOL_61_ = 61,                       /* ')'  */
  YYSYMBOL_62_ = 62,                       /* ','  */
  YYSYMBOL_63_ = 63,                       /* '['  */
  YYSYMBOL_64_ = 64,                       /* '.'  */
  YYSYMBOL_65_ = 65,                       /* ']'  */
  YYSYMBOL_66_ = 66,                       /* '{'  */
  YYSYMBOL_67_ = 67,                       /* '}'  */
  YYSYMBOL_68_ = 68,                       /* ':'  */
  YYSYMBOL_69_ = 69,                       /* '&'  */
  YYSYMBOL_70_ = 70,                       /* '|'  */
  YYSYMBOL_YYACCEPT = 71,                  /* $accept  */
  YYSYMBOL_code = 72,                      /* code  */
  YYSYMBOL_declarations = 73,              /* declarations  */
  YYSYMBOL_fonctions = 74,                 /* fonctions  */
  YYSYMBOL_args = 75,                      /* args  */
  YYSYMBOL_draw_func = 76,                 /* draw_func  */
  YYSYMBOL_affichage = 77,                 /* affichage  */
  YYSYMBOL_78_1 = 78,                      /* $@1  */
  YYSYMBOL_draw_args = 79,                 /* draw_args  */
  YYSYMBOL_expr = 80                       /* expr  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   299

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  71
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  10
/* YYNRULES -- Number of rules.  */
#define YYNRULES  56
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  163

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   306


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    58,     2,     2,     2,     2,     2,    69,     2,
      60,    61,    54,    52,    62,    53,    64,    55,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    68,    59,
       2,    57,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    63,     2,    65,    56,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    66,    70,    67,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   139,   139,   142,   143,   152,   154,   155,   158,   159,
     160,   163,   163,   166,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   258,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "var", "def", "in",
  "color", "style", "label", "xmin", "xmax", "ymin", "ymax", "PARAM",
  "NUM", "SIN", "COS", "POW", "EXP", "VAR", "FOR", "IF", "ELSE", "WHILE",
  "TAN", "ARCCOS", "ARCSIN", "ARCTAN", "COSH", "SINH", "TANH", "ARCSINH",
  "ARCCOSH", "ARCTANH", "SQRT", "LOG", "DRAW", "JMP", "JMPCOND",
  "PLUS_EQUAL", "MIN_EQUAL", "TIMES_EQUAL", "DIV_EQUAL", "EQUAL", "NOT_EQ",
  "INF_STRICT", "SUP_STRICT", "INF", "SUP", "AND", "OR", "NOT", "'+'",
  "'-'", "'*'", "'/'", "'^'", "'='", "' '", "';'", "'('", "')'", "','",
  "'['", "'.'", "']'", "'{'", "'}'", "':'", "'&'", "'|'", "$accept",
  "code", "declarations", "fonctions", "args", "draw_func", "affichage",
  "$@1", "draw_args", "expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,    43,    45,    42,    47,    94,    61,    32,    59,
      40,    41,    44,    91,    46,    93,   123,   125,    58,    38,
     124
};
#endif

#define YYPACT_NINF (-37)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -37,    29,    42,   -37,   -23,   -20,    33,    51,    57,    28,
     -37,    20,    35,    68,    25,    86,    40,   223,   -37,    46,
      55,    56,    59,   231,    66,    76,    77,    87,    96,    97,
     106,   107,   116,   117,   126,   127,    25,     9,   -37,   -14,
     124,   -37,    68,   -37,    25,    25,    25,    25,    25,    25,
      25,    25,    25,    25,    25,    25,    25,    25,    25,    25,
      25,    25,    25,    25,    25,    19,    25,    25,    25,    25,
      25,   -37,    25,    25,   -37,    86,    88,   134,    -5,    38,
      48,    58,    69,   209,   209,   209,   209,    -3,    79,    89,
      99,   109,   119,   129,   139,   149,   159,   169,   179,   189,
     -37,    27,    27,   211,   211,   211,   209,   209,   135,   143,
     148,   158,   168,   178,   188,   198,   206,   224,   -37,   -37,
      25,   -37,   -37,   -37,   -37,   -37,   -37,   -37,   -37,   -37,
     -37,   -37,   -37,   -37,   193,   204,   214,   234,   273,   276,
     279,   280,    -5,   -37,   199,   173,   -37,   -37,   -37,   -37,
     -37,   -37,   -37,   -37,   -37,   -37,   -37,   195,   -37,   212,
     261,   218,   -37
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     1,     0,     0,     0,     0,     0,     0,
       2,     0,     0,     0,     0,     0,     9,     0,    26,     0,
       0,     0,     0,    51,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     6,     0,
       0,    13,     0,    11,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     4,     0,     0,     5,     0,     0,    10,     0,     0,
       0,     0,     0,    53,    54,    55,    56,    52,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      39,    40,    41,    42,    43,    46,    44,    45,     7,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    27,    28,
       0,    48,    29,    30,    31,    32,    34,    33,    35,    37,
      36,    38,    50,    49,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    12,     0,     0,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    47,     0,
       0,     0,     8
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -37,   -37,   -37,   -37,   202,   242,   -37,   -37,   154,   -36
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,     6,    39,    17,    10,    78,   117,    37
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      65,   110,   111,   112,   113,   114,   115,   116,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,     3,
     101,   102,   103,   104,   105,     7,   106,   107,     8,    18,
      19,    20,    21,    22,    23,     4,     5,    74,    75,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    66,    67,    68,    69,    70,    72,    73,    71,     9,
      11,    66,    67,    68,    69,    70,    12,    14,    72,    73,
     100,    68,    69,    70,   144,    36,    13,    16,    72,    73,
      66,    67,    68,    69,    70,    15,    72,    73,    40,   118,
      66,    67,    68,    69,    70,    38,    44,    72,    73,   119,
      66,    67,    68,    69,    70,    45,    46,    72,    73,    47,
     120,    66,    67,    68,    69,    70,    53,    72,    73,    76,
     121,    66,    67,    68,    69,    70,    54,    55,    72,    73,
     122,    66,    67,    68,    69,    70,   109,    56,    72,    73,
     123,    66,    67,    68,    69,    70,    57,    58,    72,    73,
     124,    66,    67,    68,    69,    70,    59,    60,    72,    73,
     125,    66,    67,    68,    69,    70,    61,    62,    72,    73,
     126,    66,    67,    68,    69,    70,    63,    64,    72,    73,
     127,    66,    67,    68,    69,    70,    42,    75,    72,    73,
     128,    66,    67,    68,    69,    70,   134,   145,    72,    73,
     129,    66,    67,    68,    69,    70,   135,   146,    72,    73,
     130,    66,    67,    68,    69,    70,   136,   147,    72,    73,
     131,    66,    67,    68,    69,    70,   137,   159,    72,    73,
     132,    66,    67,    68,    69,    70,   138,   148,    72,    73,
     133,    66,    67,    68,    69,    70,   139,   142,    72,    73,
     158,    66,    67,    68,    69,    70,   140,    70,    72,    73,
      48,    49,    50,    51,   141,   161,   160,   108,    72,    73,
      72,    73,    41,   162,    77,    42,   142,   149,    52,    43,
     151,   143,   150,   153,   155,   152,   157,     0,   154,   156
};

static const yytype_int16 yycheck[] =
{
      36,     6,     7,     8,     9,    10,    11,    12,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,     0,
      66,    67,    68,    69,    70,    58,    72,    73,    58,    14,
      15,    16,    17,    18,    19,     3,     4,    61,    62,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    52,    53,    54,    55,    56,    69,    70,    59,    36,
      19,    52,    53,    54,    55,    56,    19,    57,    69,    70,
      61,    54,    55,    56,   120,    60,    58,    19,    69,    70,
      52,    53,    54,    55,    56,    60,    69,    70,    58,    61,
      52,    53,    54,    55,    56,    19,    60,    69,    70,    61,
      52,    53,    54,    55,    56,    60,    60,    69,    70,    60,
      62,    52,    53,    54,    55,    56,    60,    69,    70,     5,
      61,    52,    53,    54,    55,    56,    60,    60,    69,    70,
      61,    52,    53,    54,    55,    56,    58,    60,    69,    70,
      61,    52,    53,    54,    55,    56,    60,    60,    69,    70,
      61,    52,    53,    54,    55,    56,    60,    60,    69,    70,
      61,    52,    53,    54,    55,    56,    60,    60,    69,    70,
      61,    52,    53,    54,    55,    56,    60,    60,    69,    70,
      61,    52,    53,    54,    55,    56,    62,    62,    69,    70,
      61,    52,    53,    54,    55,    56,    63,    14,    69,    70,
      61,    52,    53,    54,    55,    56,    68,    13,    69,    70,
      61,    52,    53,    54,    55,    56,    68,    13,    69,    70,
      61,    52,    53,    54,    55,    56,    68,    64,    69,    70,
      61,    52,    53,    54,    55,    56,    68,    13,    69,    70,
      61,    52,    53,    54,    55,    56,    68,    62,    69,    70,
      61,    52,    53,    54,    55,    56,    68,    56,    69,    70,
      39,    40,    41,    42,    68,    14,    64,    75,    69,    70,
      69,    70,    59,    65,    42,    62,    62,    14,    57,    66,
      14,    67,    19,    14,    14,    19,   142,    -1,    19,    19
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    72,    73,     0,     3,     4,    74,    58,    58,    36,
      77,    19,    19,    58,    57,    60,    19,    76,    14,    15,
      16,    17,    18,    19,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    60,    80,    19,    75,
      58,    59,    62,    66,    60,    60,    60,    60,    39,    40,
      41,    42,    57,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    80,    52,    53,    54,    55,
      56,    59,    69,    70,    61,    62,     5,    76,    78,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      61,    80,    80,    80,    80,    80,    80,    80,    75,    58,
       6,     7,     8,     9,    10,    11,    12,    79,    61,    61,
      62,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    63,    68,    68,    68,    68,    68,
      68,    68,    62,    67,    80,    14,    13,    13,    13,    14,
      19,    14,    19,    14,    19,    14,    19,    79,    61,    64,
      64,    14,    65
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    71,    72,    73,    73,    74,    75,    75,    76,    76,
      76,    78,    77,    77,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     0,     7,     6,     1,     3,    10,     1,
       3,     0,     7,     4,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     3,
       3,     3,     3,     3,     3,     3,     3,     6,     4,     4,
       4,     1,     3,     3,     3,     3,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* code: declarations fonctions affichage  */
#line 139 "calculette.y"
                                                        { /* TODO: print start compiling */ }
#line 1320 "calculette.bison.cpp"
    break;

  case 3: /* declarations: %empty  */
#line 142 "calculette.y"
                                                        { /* End of declarations */ }
#line 1326 "calculette.bison.cpp"
    break;

  case 4: /* declarations: declarations var ' ' VAR '=' expr ';'  */
#line 143 "calculette.y"
                                                        { /* Init Vars */
                if (!variables.count((yyvsp[-3].STRING))) {
                    variables[(yyvsp[-3].STRING)] = (yyvsp[-1].DOUBLE);
                } else {
                    yyerror("Variable already declared...");
                }
}
#line 1338 "calculette.bison.cpp"
    break;

  case 5: /* fonctions: def ' ' VAR '(' args ')'  */
#line 152 "calculette.y"
                                                        { /* TODO */ }
#line 1344 "calculette.bison.cpp"
    break;

  case 6: /* args: VAR  */
#line 154 "calculette.y"
                                                        { /* TODO */ }
#line 1350 "calculette.bison.cpp"
    break;

  case 7: /* args: args ',' args  */
#line 155 "calculette.y"
                                                        { /* TODO */ }
#line 1356 "calculette.bison.cpp"
    break;

  case 8: /* draw_func: VAR ' ' in ' ' '[' NUM '.' '.' NUM ']'  */
#line 158 "calculette.y"
                                                        { /* TODO */ }
#line 1362 "calculette.bison.cpp"
    break;

  case 9: /* draw_func: VAR  */
#line 159 "calculette.y"
                                                        { /* TODO */ }
#line 1368 "calculette.bison.cpp"
    break;

  case 10: /* draw_func: draw_func ',' draw_func  */
#line 160 "calculette.y"
                                                        { /* TODO */ }
#line 1374 "calculette.bison.cpp"
    break;

  case 11: /* $@1: %empty  */
#line 163 "calculette.y"
                                    { /*TODO: load funcs*/ }
#line 1380 "calculette.bison.cpp"
    break;

  case 13: /* affichage: DRAW ' ' draw_func ';'  */
#line 166 "calculette.y"
                                    { /* TODO: load default args */}
#line 1386 "calculette.bison.cpp"
    break;

  case 14: /* draw_args: color ':' PARAM  */
#line 169 "calculette.y"
                                         { /*TODO: check PARAM values*/ }
#line 1392 "calculette.bison.cpp"
    break;

  case 15: /* draw_args: style ':' PARAM  */
#line 170 "calculette.y"
                                         { /*TODO: check PARAM values*/ }
#line 1398 "calculette.bison.cpp"
    break;

  case 16: /* draw_args: label ':' PARAM  */
#line 171 "calculette.y"
                                         { /*TODO: check PARAM values*/ }
#line 1404 "calculette.bison.cpp"
    break;

  case 17: /* draw_args: xmin ':' NUM  */
#line 172 "calculette.y"
                                         { /*TODO*/ }
#line 1410 "calculette.bison.cpp"
    break;

  case 18: /* draw_args: xmin ':' VAR  */
#line 173 "calculette.y"
                                         { /*TODO*/ }
#line 1416 "calculette.bison.cpp"
    break;

  case 19: /* draw_args: xmax ':' NUM  */
#line 174 "calculette.y"
                                         { /*TODO*/ }
#line 1422 "calculette.bison.cpp"
    break;

  case 20: /* draw_args: xmax ':' VAR  */
#line 175 "calculette.y"
                                         { /*TODO*/ }
#line 1428 "calculette.bison.cpp"
    break;

  case 21: /* draw_args: ymin ':' NUM  */
#line 176 "calculette.y"
                                         { /*TODO*/ }
#line 1434 "calculette.bison.cpp"
    break;

  case 22: /* draw_args: ymin ':' VAR  */
#line 177 "calculette.y"
                                         { /*TODO*/ }
#line 1440 "calculette.bison.cpp"
    break;

  case 23: /* draw_args: ymax ':' NUM  */
#line 178 "calculette.y"
                                         { /*TODO*/ }
#line 1446 "calculette.bison.cpp"
    break;

  case 24: /* draw_args: ymax ':' VAR  */
#line 179 "calculette.y"
                                         { /*TODO*/ }
#line 1452 "calculette.bison.cpp"
    break;

  case 25: /* draw_args: draw_args ',' draw_args  */
#line 180 "calculette.y"
                                         { /*TODO*/ }
#line 1458 "calculette.bison.cpp"
    break;

  case 26: /* expr: NUM  */
#line 234 "calculette.y"
                            { add_instruction(NUM, (yyvsp[0].DOUBLE)); }
#line 1464 "calculette.bison.cpp"
    break;

  case 27: /* expr: SIN '(' expr ')'  */
#line 235 "calculette.y"
                            { add_instruction(SIN); }
#line 1470 "calculette.bison.cpp"
    break;

  case 28: /* expr: COS '(' expr ')'  */
#line 236 "calculette.y"
                            { add_instruction(COS); }
#line 1476 "calculette.bison.cpp"
    break;

  case 29: /* expr: TAN '(' expr ')'  */
#line 237 "calculette.y"
                            { add_instruction(TAN); }
#line 1482 "calculette.bison.cpp"
    break;

  case 30: /* expr: ARCCOS '(' expr ')'  */
#line 238 "calculette.y"
                            { add_instruction(ARCCOS); }
#line 1488 "calculette.bison.cpp"
    break;

  case 31: /* expr: ARCSIN '(' expr ')'  */
#line 239 "calculette.y"
                            { add_instruction(ARCSIN); }
#line 1494 "calculette.bison.cpp"
    break;

  case 32: /* expr: ARCTAN '(' expr ')'  */
#line 240 "calculette.y"
                            { add_instruction(ARCTAN); }
#line 1500 "calculette.bison.cpp"
    break;

  case 33: /* expr: SINH '(' expr ')'  */
#line 241 "calculette.y"
                            { add_instruction(SINH); }
#line 1506 "calculette.bison.cpp"
    break;

  case 34: /* expr: COSH '(' expr ')'  */
#line 242 "calculette.y"
                            { add_instruction(COSH); }
#line 1512 "calculette.bison.cpp"
    break;

  case 35: /* expr: TANH '(' expr ')'  */
#line 243 "calculette.y"
                            { add_instruction(TANH); }
#line 1518 "calculette.bison.cpp"
    break;

  case 36: /* expr: ARCCOSH '(' expr ')'  */
#line 244 "calculette.y"
                            { add_instruction(ARCCOSH); }
#line 1524 "calculette.bison.cpp"
    break;

  case 37: /* expr: ARCSINH '(' expr ')'  */
#line 245 "calculette.y"
                            { add_instruction(ARCSINH); }
#line 1530 "calculette.bison.cpp"
    break;

  case 38: /* expr: ARCTANH '(' expr ')'  */
#line 246 "calculette.y"
                            { add_instruction(ARCTANH); }
#line 1536 "calculette.bison.cpp"
    break;

  case 39: /* expr: '(' expr ')'  */
#line 247 "calculette.y"
                            { (yyval.DOUBLE) = (yyvsp[-1].DOUBLE); }
#line 1542 "calculette.bison.cpp"
    break;

  case 40: /* expr: expr '+' expr  */
#line 248 "calculette.y"
                            { (yyval.DOUBLE) = (yyvsp[-2].DOUBLE) + (yyvsp[0].DOUBLE); printf("%g + %g = %g\n", (yyvsp[-2].DOUBLE), (yyvsp[0].DOUBLE), (yyval.DOUBLE)); }
#line 1548 "calculette.bison.cpp"
    break;

  case 41: /* expr: expr '-' expr  */
#line 249 "calculette.y"
                            { (yyval.DOUBLE) = (yyvsp[-2].DOUBLE) - (yyvsp[0].DOUBLE); printf("%g - %g = %g\n", (yyvsp[-2].DOUBLE), (yyvsp[0].DOUBLE), (yyval.DOUBLE)); }
#line 1554 "calculette.bison.cpp"
    break;

  case 42: /* expr: expr '*' expr  */
#line 250 "calculette.y"
                            { (yyval.DOUBLE) = (yyvsp[-2].DOUBLE) * (yyvsp[0].DOUBLE); printf("%g * %g = %g\n", (yyvsp[-2].DOUBLE), (yyvsp[0].DOUBLE), (yyval.DOUBLE)); }
#line 1560 "calculette.bison.cpp"
    break;

  case 43: /* expr: expr '/' expr  */
#line 251 "calculette.y"
                            { (yyval.DOUBLE) = (yyvsp[-2].DOUBLE) / (yyvsp[0].DOUBLE); printf("%g / %g = %g\n", (yyvsp[-2].DOUBLE), (yyvsp[0].DOUBLE), (yyval.DOUBLE)); }
#line 1566 "calculette.bison.cpp"
    break;

  case 44: /* expr: expr '&' expr  */
#line 252 "calculette.y"
                            {
        int tmp1 = (int)(yyvsp[-2].DOUBLE);
        int tmp2 = (int)(yyvsp[0].DOUBLE);
        (yyval.DOUBLE) = tmp1 & tmp2;
        printf("%d & %d = %d\n", tmp1, tmp2, (int)(yyval.DOUBLE));
}
#line 1577 "calculette.bison.cpp"
    break;

  case 45: /* expr: expr '|' expr  */
#line 258 "calculette.y"
                            {
        int tmp1 = (int)(yyvsp[-2].DOUBLE);
        int tmp2 = (int)(yyvsp[0].DOUBLE);
        (yyval.DOUBLE) = tmp1 | tmp2;
        printf("%d | %d = %d\n", tmp1, tmp2, (int)(yyval.DOUBLE));
}
#line 1588 "calculette.bison.cpp"
    break;

  case 46: /* expr: expr '^' expr  */
#line 264 "calculette.y"
                                    { (yyval.DOUBLE) = pow((yyvsp[-2].DOUBLE),(yyvsp[0].DOUBLE)); printf("%g^%g = %g\n", (yyvsp[-2].DOUBLE), (yyvsp[0].DOUBLE), (yyval.DOUBLE)); }
#line 1594 "calculette.bison.cpp"
    break;

  case 47: /* expr: POW '(' expr ',' expr ')'  */
#line 265 "calculette.y"
                                    { add_instruction(POW); }
#line 1600 "calculette.bison.cpp"
    break;

  case 48: /* expr: EXP '(' expr ')'  */
#line 266 "calculette.y"
                                    { add_instruction(EXP); }
#line 1606 "calculette.bison.cpp"
    break;

  case 49: /* expr: LOG '(' expr ')'  */
#line 267 "calculette.y"
                                    { add_instruction(LOG); }
#line 1612 "calculette.bison.cpp"
    break;

  case 50: /* expr: SQRT '(' expr ')'  */
#line 268 "calculette.y"
                                    { add_instruction(SQRT); }
#line 1618 "calculette.bison.cpp"
    break;

  case 51: /* expr: VAR  */
#line 269 "calculette.y"
                                    { add_instruction(VAR, 0, (yyvsp[0].STRING)); }
#line 1624 "calculette.bison.cpp"
    break;

  case 52: /* expr: VAR '=' expr  */
#line 270 "calculette.y"
                                    {  }
#line 1630 "calculette.bison.cpp"
    break;

  case 53: /* expr: VAR PLUS_EQUAL expr  */
#line 271 "calculette.y"
                                    {  }
#line 1636 "calculette.bison.cpp"
    break;

  case 54: /* expr: VAR MIN_EQUAL expr  */
#line 272 "calculette.y"
                                    {  }
#line 1642 "calculette.bison.cpp"
    break;

  case 55: /* expr: VAR TIMES_EQUAL expr  */
#line 273 "calculette.y"
                                    {  }
#line 1648 "calculette.bison.cpp"
    break;

  case 56: /* expr: VAR DIV_EQUAL expr  */
#line 274 "calculette.y"
                                    {  }
#line 1654 "calculette.bison.cpp"
    break;


#line 1658 "calculette.bison.cpp"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

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


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 276 "calculette.y"


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

