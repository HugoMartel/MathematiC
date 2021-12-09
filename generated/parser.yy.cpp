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
#line 1 "language/parser.y"

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

#line 180 "generated/parser.yy.cpp"

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

#include "parser.yy.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_PI = 3,                         /* PI  */
  YYSYMBOL_E = 4,                          /* E  */
  YYSYMBOL_PHI = 5,                        /* PHI  */
  YYSYMBOL_var = 6,                        /* var  */
  YYSYMBOL_DEF = 7,                        /* DEF  */
  YYSYMBOL_in = 8,                         /* in  */
  YYSYMBOL_arrow = 9,                      /* arrow  */
  YYSYMBOL_RETURN = 10,                    /* RETURN  */
  YYSYMBOL_color = 11,                     /* color  */
  YYSYMBOL_style = 12,                     /* style  */
  YYSYMBOL_label = 13,                     /* label  */
  YYSYMBOL_xmin = 14,                      /* xmin  */
  YYSYMBOL_xmax = 15,                      /* xmax  */
  YYSYMBOL_ymin = 16,                      /* ymin  */
  YYSYMBOL_ymax = 17,                      /* ymax  */
  YYSYMBOL_COLOR_PARAM = 18,               /* COLOR_PARAM  */
  YYSYMBOL_STYLE_PARAM = 19,               /* STYLE_PARAM  */
  YYSYMBOL_STRING = 20,                    /* STRING  */
  YYSYMBOL_NUM = 21,                       /* NUM  */
  YYSYMBOL_SIN = 22,                       /* SIN  */
  YYSYMBOL_COS = 23,                       /* COS  */
  YYSYMBOL_POW = 24,                       /* POW  */
  YYSYMBOL_EXP = 25,                       /* EXP  */
  YYSYMBOL_VAR = 26,                       /* VAR  */
  YYSYMBOL_FOR = 27,                       /* FOR  */
  YYSYMBOL_PROCEEDFOR = 28,                /* PROCEEDFOR  */
  YYSYMBOL_IF = 29,                        /* IF  */
  YYSYMBOL_ELSE = 30,                      /* ELSE  */
  YYSYMBOL_THEN = 31,                      /* THEN  */
  YYSYMBOL_WHILE = 32,                     /* WHILE  */
  YYSYMBOL_TAN = 33,                       /* TAN  */
  YYSYMBOL_ARCCOS = 34,                    /* ARCCOS  */
  YYSYMBOL_ARCSIN = 35,                    /* ARCSIN  */
  YYSYMBOL_ARCTAN = 36,                    /* ARCTAN  */
  YYSYMBOL_COSH = 37,                      /* COSH  */
  YYSYMBOL_SINH = 38,                      /* SINH  */
  YYSYMBOL_TANH = 39,                      /* TANH  */
  YYSYMBOL_ARCSINH = 40,                   /* ARCSINH  */
  YYSYMBOL_ARCCOSH = 41,                   /* ARCCOSH  */
  YYSYMBOL_ARCTANH = 42,                   /* ARCTANH  */
  YYSYMBOL_SQRT = 43,                      /* SQRT  */
  YYSYMBOL_LOG = 44,                       /* LOG  */
  YYSYMBOL_DRAW = 45,                      /* DRAW  */
  YYSYMBOL_JMP = 46,                       /* JMP  */
  YYSYMBOL_JMPCOND = 47,                   /* JMPCOND  */
  YYSYMBOL_ASSIGN = 48,                    /* ASSIGN  */
  YYSYMBOL_CALL = 49,                      /* CALL  */
  YYSYMBOL_PLUS = 50,                      /* PLUS  */
  YYSYMBOL_MIN = 51,                       /* MIN  */
  YYSYMBOL_OPP = 52,                       /* OPP  */
  YYSYMBOL_TIMES = 53,                     /* TIMES  */
  YYSYMBOL_DIV = 54,                       /* DIV  */
  YYSYMBOL_PLUS_EQUAL = 55,                /* PLUS_EQUAL  */
  YYSYMBOL_MIN_EQUAL = 56,                 /* MIN_EQUAL  */
  YYSYMBOL_TIMES_EQUAL = 57,               /* TIMES_EQUAL  */
  YYSYMBOL_DIV_EQUAL = 58,                 /* DIV_EQUAL  */
  YYSYMBOL_EQUAL = 59,                     /* EQUAL  */
  YYSYMBOL_NOT_EQ = 60,                    /* NOT_EQ  */
  YYSYMBOL_INF_STRICT = 61,                /* INF_STRICT  */
  YYSYMBOL_SUP_STRICT = 62,                /* SUP_STRICT  */
  YYSYMBOL_INF = 63,                       /* INF  */
  YYSYMBOL_SUP = 64,                       /* SUP  */
  YYSYMBOL_AND = 65,                       /* AND  */
  YYSYMBOL_OR = 66,                        /* OR  */
  YYSYMBOL_NOT = 67,                       /* NOT  */
  YYSYMBOL_68_ = 68,                       /* '='  */
  YYSYMBOL_69_ = 69,                       /* '^'  */
  YYSYMBOL_70_ = 70,                       /* ','  */
  YYSYMBOL_71_ = 71,                       /* ';'  */
  YYSYMBOL_72_ = 72,                       /* ':'  */
  YYSYMBOL_73_ = 73,                       /* '('  */
  YYSYMBOL_74_ = 74,                       /* ')'  */
  YYSYMBOL_75_ = 75,                       /* '{'  */
  YYSYMBOL_76_ = 76,                       /* '}'  */
  YYSYMBOL_77_ = 77,                       /* '['  */
  YYSYMBOL_78_ = 78,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 79,                  /* $accept  */
  YYSYMBOL_code = 80,                      /* code  */
  YYSYMBOL_declarations = 81,              /* declarations  */
  YYSYMBOL_fonctions = 82,                 /* fonctions  */
  YYSYMBOL_83_1 = 83,                      /* $@1  */
  YYSYMBOL_parameters = 84,                /* parameters  */
  YYSYMBOL_draw_func = 85,                 /* draw_func  */
  YYSYMBOL_affichage = 86,                 /* affichage  */
  YYSYMBOL_draw_args = 87,                 /* draw_args  */
  YYSYMBOL_style_args = 88,                /* style_args  */
  YYSYMBOL_color_args = 89,                /* color_args  */
  YYSYMBOL_instruction = 90,               /* instruction  */
  YYSYMBOL_91_2 = 91,                      /* $@2  */
  YYSYMBOL_92_3 = 92,                      /* $@3  */
  YYSYMBOL_93_4 = 93,                      /* $@4  */
  YYSYMBOL_94_5 = 94,                      /* $@5  */
  YYSYMBOL_95_6 = 95,                      /* $@6  */
  YYSYMBOL_96_7 = 96,                      /* $@7  */
  YYSYMBOL_logic = 97,                     /* logic  */
  YYSYMBOL_expr = 98                       /* expr  */
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
#define YYLAST   498

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  79
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  232

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   322


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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      73,    74,     2,     2,    70,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    72,    71,
       2,    68,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    77,     2,    78,    69,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    75,     2,    76,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   258,   258,   266,   271,   285,   299,   299,   335,   339,
     342,   346,   359,   369,   373,   383,   393,   409,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   438,   453,
     457,   482,   486,   487,   488,   492,   498,   492,   512,   521,
     512,   526,   531,   526,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   552,   558,   564,   570,   576,   582,   588,
     594,   600,   606,   612,   618,   624,   630,   636,   642,   648,
     649,   655,   661,   667,   673,   684,   695,   706,   712,   718,
     724,   733,   742,   753,   765,   776
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
  "\"end of file\"", "error", "\"invalid token\"", "PI", "E", "PHI",
  "var", "DEF", "in", "arrow", "RETURN", "color", "style", "label", "xmin",
  "xmax", "ymin", "ymax", "COLOR_PARAM", "STYLE_PARAM", "STRING", "NUM",
  "SIN", "COS", "POW", "EXP", "VAR", "FOR", "PROCEEDFOR", "IF", "ELSE",
  "THEN", "WHILE", "TAN", "ARCCOS", "ARCSIN", "ARCTAN", "COSH", "SINH",
  "TANH", "ARCSINH", "ARCCOSH", "ARCTANH", "SQRT", "LOG", "DRAW", "JMP",
  "JMPCOND", "ASSIGN", "CALL", "PLUS", "MIN", "OPP", "TIMES", "DIV",
  "PLUS_EQUAL", "MIN_EQUAL", "TIMES_EQUAL", "DIV_EQUAL", "EQUAL", "NOT_EQ",
  "INF_STRICT", "SUP_STRICT", "INF", "SUP", "AND", "OR", "NOT", "'='",
  "'^'", "','", "';'", "':'", "'('", "')'", "'{'", "'}'", "'['", "']'",
  "$accept", "code", "declarations", "fonctions", "$@1", "parameters",
  "draw_func", "affichage", "draw_args", "style_args", "color_args",
  "instruction", "$@2", "$@3", "$@4", "$@5", "$@6", "$@7", "logic", "expr", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,    61,    94,
      44,    59,    58,    40,    41,   123,   125,    91,    93
};
#endif

#define YYPACT_NINF (-201)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -201,    13,    25,  -201,    -7,    -5,    31,    38,    15,    87,
    -201,   284,  -201,    44,   118,   215,  -201,  -201,  -201,  -201,
      70,    72,    73,    96,    10,   100,   123,   124,   125,   127,
     133,   134,   135,   144,   146,   164,   165,   284,   284,   192,
     101,    57,    87,  -201,   481,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   -47,    54,   284,   284,
     284,   284,   284,  -201,  -201,     5,   139,  -201,   169,   175,
     176,   177,   178,   179,   186,    91,   121,   226,    20,   262,
     151,   151,   151,   151,   151,   279,   287,   293,   301,   315,
     323,   329,   337,   351,   359,   365,   373,  -201,   -47,   -47,
     190,   190,   190,   101,   251,   208,   204,   206,   264,    51,
     103,   155,   218,   481,  -201,  -201,  -201,   284,  -201,  -201,
    -201,  -201,  -201,  -201,  -201,  -201,  -201,  -201,  -201,  -201,
    -201,  -201,   216,   271,   275,   277,  -201,  -201,  -201,  -201,
    -201,  -201,  -201,  -201,  -201,  -201,   387,  -201,   219,  -201,
     -54,  -201,   -53,  -201,  -201,  -201,   275,  -201,   277,  -201,
      59,  -201,  -201,   284,   268,   231,   231,   292,   395,   400,
     294,   231,   -57,   422,    56,  -201,  -201,  -201,   224,   -10,
     231,   231,  -201,   284,   284,   284,   284,   284,   284,  -201,
     284,  -201,   238,  -201,   151,   151,   151,   151,   151,   151,
    -201,   -39,   189,   189,   284,   235,   258,    61,   309,  -201,
     284,   239,   -49,  -201,   267,   115,  -201,  -201,  -201,   189,
     269,  -201
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     8,     1,     0,     0,     0,     0,     0,     0,
       2,     0,     5,     0,    12,     0,    54,    55,    56,    53,
       0,     0,     0,     0,    80,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    15,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    70,     0,     0,     0,
       0,     0,     0,     4,     9,     0,     0,    13,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      82,    83,    84,    85,    81,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    69,    71,    72,
      73,    74,    75,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    14,    57,    58,     0,    77,    59,
      60,    61,    62,    63,    64,    65,    67,    66,    68,    79,
      78,    10,     0,     0,     0,     0,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,     0,     6,     0,    30,
       0,    28,     0,    76,    32,    11,     0,    16,     0,    17,
       0,    31,    29,     0,     0,     0,     0,     8,     0,     0,
       0,     0,     0,     0,     0,     7,    33,    34,     0,    52,
       0,     0,    35,     0,     0,     0,     0,     0,     0,    41,
       0,    50,    51,    32,    48,    49,    47,    46,    45,    44,
      32,     0,    36,    42,     0,     0,     0,     0,     0,    43,
       0,     0,     0,    32,     0,     0,    38,    37,    32,    39,
       0,    40
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -201,  -201,  -201,   172,  -201,   237,   316,  -201,   236,   195,
     194,  -200,  -201,  -201,  -201,  -201,  -201,  -201,   -13,   -11
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     6,   164,    75,    15,    10,    85,   162,
     160,   170,   203,   215,   228,   230,   210,   216,   182,   178
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      39,    68,    69,   212,    70,    71,    70,    71,   190,   191,
     213,    68,    69,     3,    70,    71,   166,   168,   192,     7,
      72,     8,    72,   225,   167,   169,    66,    67,   229,   224,
      72,     4,     5,   214,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   190,   191,   108,   109,   110,
     111,   112,    16,    17,    18,    49,    50,    51,    52,   173,
      68,    69,   147,    70,    71,   113,     9,   148,    53,   114,
      19,    20,    21,    22,    23,    24,   174,    13,   175,    72,
     127,   176,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    68,    69,    11,    70,    71,    12,
      37,    68,    69,    14,    70,    71,   156,    40,    16,    17,
      18,   190,   191,    72,   149,   173,    41,    74,   107,   150,
      72,   199,    38,   220,    76,   177,    19,    20,    21,    22,
      23,    24,   174,    45,   175,    46,    47,   176,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
     115,   123,   179,   184,   183,   183,    37,   124,   189,    48,
     183,    68,    69,    54,    70,    71,   151,   201,   202,   183,
     183,   152,   204,   205,   206,   207,   208,   209,    38,   211,
      72,   227,    16,    17,    18,   125,    55,    56,    57,   173,
      58,    68,    69,   217,    70,    71,    59,    60,    61,   222,
      19,    20,    21,    22,    23,    24,   174,    62,   175,    63,
      72,   176,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    16,    17,    18,    64,    65,   153,
      37,   116,    68,    69,   154,    70,    71,   117,   118,   119,
     120,   121,    19,    20,    21,    22,    23,    24,   122,    72,
     142,    72,    38,    73,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    68,    69,   143,    70,
      71,   144,    37,   145,   146,    42,    43,    16,    17,    18,
      44,   157,   158,   159,   180,    72,   161,   165,   181,     5,
     126,   200,   188,   190,    38,    19,    20,    21,    22,    23,
      24,   218,    68,    69,   223,    70,    71,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    68,
      69,    72,    70,    71,   219,    37,   128,    68,    69,   221,
      70,    71,   226,    68,    69,   231,    70,    71,    72,   185,
     141,    68,    69,   129,    70,    71,    72,    38,    77,   155,
     171,   130,    72,   172,     0,    68,    69,   131,    70,    71,
      72,     0,     0,    68,    69,   132,    70,    71,     0,    68,
      69,     0,    70,    71,    72,     0,     0,    68,    69,   133,
      70,    71,    72,     0,     0,     0,     0,   134,    72,     0,
       0,    68,    69,   135,    70,    71,    72,     0,     0,    68,
      69,   136,    70,    71,     0,    68,    69,     0,    70,    71,
      72,     0,     0,    68,    69,   137,    70,    71,    72,     0,
       0,     0,     0,   138,    72,     0,     0,    68,    69,   139,
      70,    71,    72,     0,     0,    68,    69,   140,    70,    71,
      68,    69,     0,    70,    71,     0,    72,     0,     0,     0,
       0,   163,     0,     0,    72,     0,   186,     0,     0,    72,
       0,   187,    68,    69,     0,    70,    71,     0,     0,     0,
       0,   193,   194,   195,   196,   197,   198,     0,     0,     0,
       0,    72,    78,    79,    80,    81,    82,    83,    84
};

static const yytype_int16 yycheck[] =
{
      11,    50,    51,   203,    53,    54,    53,    54,    65,    66,
     210,    50,    51,     0,    53,    54,    70,    70,    75,    26,
      69,    26,    69,   223,    78,    78,    37,    38,   228,    78,
      69,     6,     7,    72,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    65,    66,    68,    69,    70,
      71,    72,     3,     4,     5,    55,    56,    57,    58,    10,
      50,    51,    21,    53,    54,    70,    45,    26,    68,    74,
      21,    22,    23,    24,    25,    26,    27,    72,    29,    69,
      70,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    50,    51,    68,    53,    54,    71,
      51,    50,    51,    26,    53,    54,   127,    73,     3,     4,
       5,    65,    66,    69,    21,    10,     8,    26,    74,    26,
      69,    75,    73,    72,    77,    76,    21,    22,    23,    24,
      25,    26,    27,    73,    29,    73,    73,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      21,    70,   173,   176,   175,   176,    51,    76,   181,    73,
     181,    50,    51,    73,    53,    54,    21,   190,   191,   190,
     191,    26,   193,   194,   195,   196,   197,   198,    73,   200,
      69,    76,     3,     4,     5,    74,    73,    73,    73,    10,
      73,    50,    51,   214,    53,    54,    73,    73,    73,   220,
      21,    22,    23,    24,    25,    26,    27,    73,    29,    73,
      69,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,     3,     4,     5,    73,    73,    21,
      51,    72,    50,    51,    26,    53,    54,    72,    72,    72,
      72,    72,    21,    22,    23,    24,    25,    26,    72,    69,
       9,    69,    73,    71,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    50,    51,    70,    53,
      54,    77,    51,    77,    20,    70,    71,     3,     4,     5,
      75,    75,    21,    18,    26,    69,    19,    78,    67,     7,
      74,    77,     8,    65,    73,    21,    22,    23,    24,    25,
      26,    76,    50,    51,    75,    53,    54,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    50,
      51,    69,    53,    54,    76,    51,    74,    50,    51,    30,
      53,    54,    75,    50,    51,    76,    53,    54,    69,   177,
     113,    50,    51,    74,    53,    54,    69,    73,    42,   123,
     166,    74,    69,   168,    -1,    50,    51,    74,    53,    54,
      69,    -1,    -1,    50,    51,    74,    53,    54,    -1,    50,
      51,    -1,    53,    54,    69,    -1,    -1,    50,    51,    74,
      53,    54,    69,    -1,    -1,    -1,    -1,    74,    69,    -1,
      -1,    50,    51,    74,    53,    54,    69,    -1,    -1,    50,
      51,    74,    53,    54,    -1,    50,    51,    -1,    53,    54,
      69,    -1,    -1,    50,    51,    74,    53,    54,    69,    -1,
      -1,    -1,    -1,    74,    69,    -1,    -1,    50,    51,    74,
      53,    54,    69,    -1,    -1,    50,    51,    74,    53,    54,
      50,    51,    -1,    53,    54,    -1,    69,    -1,    -1,    -1,
      -1,    74,    -1,    -1,    69,    -1,    71,    -1,    -1,    69,
      -1,    71,    50,    51,    -1,    53,    54,    -1,    -1,    -1,
      -1,    59,    60,    61,    62,    63,    64,    -1,    -1,    -1,
      -1,    69,    11,    12,    13,    14,    15,    16,    17
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    80,    81,     0,     6,     7,    82,    26,    26,    45,
      86,    68,    71,    72,    26,    85,     3,     4,     5,    21,
      22,    23,    24,    25,    26,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    51,    73,    98,
      73,     8,    70,    71,    75,    73,    73,    73,    73,    55,
      56,    57,    58,    68,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    98,    98,    50,    51,
      53,    54,    69,    71,    26,    84,    77,    85,    11,    12,
      13,    14,    15,    16,    17,    87,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    74,    98,    98,
      98,    98,    98,    70,    74,    21,    72,    72,    72,    72,
      72,    72,    72,    70,    76,    74,    74,    70,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    84,     9,    70,    77,    77,    20,    21,    26,    21,
      26,    21,    26,    21,    26,    87,    98,    75,    21,    18,
      89,    19,    88,    74,    83,    78,    70,    78,    70,    78,
      90,    89,    88,    10,    27,    29,    32,    76,    98,    98,
      26,    67,    97,    98,    97,    82,    71,    71,     8,    97,
      65,    66,    75,    59,    60,    61,    62,    63,    64,    75,
      77,    97,    97,    91,    98,    98,    98,    98,    98,    98,
      95,    98,    90,    90,    72,    92,    96,    98,    76,    76,
      72,    30,    98,    75,    78,    90,    75,    76,    93,    90,
      94,    76
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    79,    80,    81,    81,    81,    83,    82,    82,    84,
      84,    85,    85,    85,    86,    86,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    88,    88,
      89,    89,    90,    90,    90,    91,    92,    90,    93,    94,
      90,    95,    96,    90,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     0,     6,     4,     0,    12,     0,     1,
       3,     7,     1,     3,     5,     3,     5,     5,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     3,
       1,     3,     0,     3,     4,     0,     0,    12,     0,     0,
      16,     0,     0,     8,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     1,     1,     1,     1,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     3,
       2,     3,     3,     3,     3,     3,     6,     4,     4,     4,
       1,     3,     3,     3,     3,     3
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

/* User initialization code.  */
#line 126 "language/parser.y"
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

#line 1297 "generated/parser.yy.cpp"

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
#line 258 "language/parser.y"
                                                    {
#ifdef __DEBUG__
                std::cout << "-- END OF COMPILATION --\n";
#endif
                                                    }
#line 1503 "generated/parser.yy.cpp"
    break;

  case 3: /* declarations: %empty  */
#line 266 "language/parser.y"
                                                    { /* End of declarations */
#ifdef __DEBUG__
                std::cout << "-- End of declarations --\n";
#endif
                                                    }
#line 1513 "generated/parser.yy.cpp"
    break;

  case 4: /* declarations: declarations var VAR '=' expr ';'  */
#line 271 "language/parser.y"
                                                    { /* Init Vars */
                                                        /* Check if already declared */
                                                        if (!variables.count((yyvsp[-3].STRING))) {
                                                            variables[(yyvsp[-3].STRING)] = (yyvsp[-1].DOUBLE);

#ifdef __DEBUG__
                                                            printf("Declared %s = %lf\n", (yyvsp[-3].STRING), (yyvsp[-1].DOUBLE));
#endif

                                                        } else {
                                                            error = "Variable " + std::string((yyvsp[-3].STRING)) + " has already been declared...\n";
                                                            verbose(error);
                                                        }
                                                    }
#line 1532 "generated/parser.yy.cpp"
    break;

  case 5: /* declarations: declarations var VAR ';'  */
#line 285 "language/parser.y"
                                                    {
                                                        if (!variables.count((yyvsp[-1].STRING))) {
                                                            variables[(yyvsp[-1].STRING)] = 0;
#ifdef __DEBUG__
                                                            printf("Declared %s (=0)\n", (yyvsp[-1].STRING));
#endif
                                                        } else {
                                                            error = "Variable " + std::string((yyvsp[-1].STRING)) + " has already been declared...\n";
                                                            verbose(error);
                                                        }
                                                    }
#line 1548 "generated/parser.yy.cpp"
    break;

  case 6: /* $@1: %empty  */
#line 299 "language/parser.y"
                                                        {
                                                                /* Clear the current_scope vector */
                                                                current_scope.clear();

                                                                /* Check if the function wasn't already declared */
                                                                if (!functions.count((yyvsp[-6].STRING))) {
                                                                    functions[(yyvsp[-6].STRING)] = Function();
                                                                    /* Enqueue to keep it in memory */
                                                                    current_scope.push_back((yyvsp[-6].STRING));

                                                                /* Declare parameters */
                                                                while (!argQueue.empty()) {
                                                                    if (!functions[(yyvsp[-6].STRING)].parameters.count(argQueue.front()))
                                                                        functions[(yyvsp[-6].STRING)].parameters[argQueue.front()] = 0;
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
#line 1580 "generated/parser.yy.cpp"
    break;

  case 7: /* fonctions: DEF VAR ':' '(' parameters ')' arrow '{' $@1 instruction '}' fonctions  */
#line 327 "language/parser.y"
                                                        {
                                                             /* Dequeue since we left the function scope */
                                                             if (!current_scope.empty())
                                                                current_scope.pop_back();
                                                             /*Clear the queue in case it is not empty*/
                                                             while (!argQueue.empty())
                                                                 argQueue.pop();
                                                        }
#line 1593 "generated/parser.yy.cpp"
    break;

  case 8: /* fonctions: %empty  */
#line 335 "language/parser.y"
                                                        { /* End of function declarations */ }
#line 1599 "generated/parser.yy.cpp"
    break;

  case 9: /* parameters: VAR  */
#line 339 "language/parser.y"
                                                        {
                    argQueue.push((yyvsp[0].STRING));
                                                        }
#line 1607 "generated/parser.yy.cpp"
    break;

  case 10: /* parameters: parameters ',' parameters  */
#line 342 "language/parser.y"
                                                        { /* Support multiple parameters */ }
#line 1613 "generated/parser.yy.cpp"
    break;

  case 11: /* draw_func: VAR in '[' NUM ',' NUM ']'  */
#line 346 "language/parser.y"
                                                        {
                                                            /* Load function names to send to the front-end */
                                                            current_scope.push_back((yyvsp[-6].STRING));

                                                            /* Check if the function is already drawn */
                                                            if (functions.count((yyvsp[-6].STRING))) {
                                                                functions[(yyvsp[-6].STRING)].xInterval.first = (yyvsp[-3].DOUBLE);
                                                                functions[(yyvsp[-6].STRING)].xInterval.second = (yyvsp[-1].DOUBLE);
                                                            } else {
                                                                error = "Function already declared...\n";
                                                                verbose(error);
                                                            }
                                                        }
#line 1631 "generated/parser.yy.cpp"
    break;

  case 12: /* draw_func: VAR  */
#line 359 "language/parser.y"
                                                        {
                                                            /* Load function names to send to the front-end */
                                                            current_scope.push_back((yyvsp[0].STRING));

                                                            /* Check if the function is already drawn */
                                                            if (!functions.count((yyvsp[0].STRING))) {
                                                                error = "Function already declared...\n";
                                                                verbose(error);
                                                            }
                                                        }
#line 1646 "generated/parser.yy.cpp"
    break;

  case 13: /* draw_func: draw_func ',' draw_func  */
#line 369 "language/parser.y"
                                                        { /* Support multiple functions to draw at the same time */ }
#line 1652 "generated/parser.yy.cpp"
    break;

  case 14: /* affichage: DRAW draw_func '{' draw_args '}'  */
#line 375 "language/parser.y"
                                                        {
#ifdef __DEBUG__
                                                            for (size_t i = 0; i < current_scope.size(); ++i) {
                                                                std::cout << i << ": " << current_scope[i] << "\n";
                                                            }
#endif
                                                        }
#line 1664 "generated/parser.yy.cpp"
    break;

  case 15: /* affichage: DRAW draw_func ';'  */
#line 383 "language/parser.y"
                                                        {
#ifdef __DEBUG__
                                                            for (size_t i = 0; i < current_scope.size(); ++i) {
                                                                std::cout << i << ": " << current_scope[i] << "\n";
                                                            }
#endif
                                                        }
#line 1676 "generated/parser.yy.cpp"
    break;

  case 16: /* draw_args: color ':' '[' color_args ']'  */
#line 393 "language/parser.y"
                                                        { /* getting the multiples color args (or not) */
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
#line 1697 "generated/parser.yy.cpp"
    break;

  case 17: /* draw_args: style ':' '[' style_args ']'  */
#line 409 "language/parser.y"
                                                        { /* getting the multiples style args (or not) */
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
#line 1718 "generated/parser.yy.cpp"
    break;

  case 18: /* draw_args: label ':' STRING  */
#line 425 "language/parser.y"
                                                        { argLabel = (yyvsp[0].STRING); argLabel = argLabel.substr(1, argLabel.size()-2); }
#line 1724 "generated/parser.yy.cpp"
    break;

  case 19: /* draw_args: xmin ':' NUM  */
#line 426 "language/parser.y"
                                                        { argXmin = (yyvsp[0].DOUBLE); }
#line 1730 "generated/parser.yy.cpp"
    break;

  case 20: /* draw_args: xmin ':' VAR  */
#line 427 "language/parser.y"
                                                        { argXmin = variables[(yyvsp[0].STRING)]; }
#line 1736 "generated/parser.yy.cpp"
    break;

  case 21: /* draw_args: xmax ':' NUM  */
#line 428 "language/parser.y"
                                                        { argXmax = (yyvsp[0].DOUBLE); }
#line 1742 "generated/parser.yy.cpp"
    break;

  case 22: /* draw_args: xmax ':' VAR  */
#line 429 "language/parser.y"
                                                        { argXmax = variables[(yyvsp[0].STRING)]; }
#line 1748 "generated/parser.yy.cpp"
    break;

  case 23: /* draw_args: ymin ':' NUM  */
#line 430 "language/parser.y"
                                                        { argYmin = (yyvsp[0].DOUBLE); }
#line 1754 "generated/parser.yy.cpp"
    break;

  case 24: /* draw_args: ymin ':' VAR  */
#line 431 "language/parser.y"
                                                        { argYmin = variables[(yyvsp[0].STRING)]; }
#line 1760 "generated/parser.yy.cpp"
    break;

  case 25: /* draw_args: ymax ':' NUM  */
#line 432 "language/parser.y"
                                                        { argYmax = (yyvsp[0].DOUBLE); }
#line 1766 "generated/parser.yy.cpp"
    break;

  case 26: /* draw_args: ymax ':' VAR  */
#line 433 "language/parser.y"
                                                        { argYmax = variables[(yyvsp[0].STRING)]; }
#line 1772 "generated/parser.yy.cpp"
    break;

  case 27: /* draw_args: draw_args ',' draw_args  */
#line 434 "language/parser.y"
                                                        { /* Support multiple args */ }
#line 1778 "generated/parser.yy.cpp"
    break;

  case 28: /* style_args: STYLE_PARAM  */
#line 438 "language/parser.y"
                                                        {
                                                            /* Check the value */
                                                            if (!strcmp((yyvsp[0].STRING), "\"dotted\"")) {
                                                                argQueue.push("dotted");
                                                            } else if (!strcmp((yyvsp[0].STRING), "\"hist\"")) {
                                                                argQueue.push("hist");
                                                            } else if (!strcmp((yyvsp[0].STRING), "\"solid\"")) {
                                                                argQueue.push("solid");
                                                            } else if (!strcmp((yyvsp[0].STRING), "\"filled\"")) {
                                                                argQueue.push("filled");
                                                            } else {
                                                                error = std::to_string(yylineno) + "Wrong curve style value...\n";
                                                                verbose(error);
                                                            }
                                                        }
#line 1798 "generated/parser.yy.cpp"
    break;

  case 29: /* style_args: style_args ',' style_args  */
#line 453 "language/parser.y"
                                                        { /* Support multiple style_args */ }
#line 1804 "generated/parser.yy.cpp"
    break;

  case 30: /* color_args: COLOR_PARAM  */
#line 457 "language/parser.y"
                                                        {
                                                            if (!strcmp((yyvsp[0].STRING),"\"blue\"")) {
                                                                argQueue.push("#0000FF");
                                                            } else if (!strcmp((yyvsp[0].STRING),"\"red\"")) {
                                                                argQueue.push("#FF0000");
                                                            } else if (!strcmp((yyvsp[0].STRING),"\"green\"")) {
                                                                argQueue.push("#00FF00");
                                                            } else if (!strcmp((yyvsp[0].STRING),"\"black\"")) {
                                                                argQueue.push("#000000");
                                                            } else if (!strcmp((yyvsp[0].STRING),"\"white\"")) {
                                                                argQueue.push("#FFFFFF");
                                                            } else if (!strcmp((yyvsp[0].STRING),"\"magenta\"")) {
                                                                argQueue.push("#FF00FF");
                                                            } else if (!strcmp((yyvsp[0].STRING),"\"cyan\"")) {
                                                                argQueue.push("#00FFFF");
                                                            } else if (!strcmp((yyvsp[0].STRING),"\"yellow\"")) {
                                                                argQueue.push("#FFFF00");
                                                            } else {
                                                                /* Remove the head and tail '"' */
                                                                for (i = 0; i <= 6; ++i)
                                                                    (yyvsp[0].STRING) [i] = (yyvsp[0].STRING) [i+1];
                                                                (yyvsp[0].STRING)[i] = '\0';
                                                                argQueue.push((yyvsp[0].STRING));
                                                            }
                                                        }
#line 1834 "generated/parser.yy.cpp"
    break;

  case 31: /* color_args: color_args ',' color_args  */
#line 482 "language/parser.y"
                                                        { /* Support multiple color_args */ }
#line 1840 "generated/parser.yy.cpp"
    break;

  case 32: /* instruction: %empty  */
#line 486 "language/parser.y"
                                                        { /* No instructions left */ }
#line 1846 "generated/parser.yy.cpp"
    break;

  case 33: /* instruction: instruction expr ';'  */
#line 487 "language/parser.y"
                                                        { /* new line */ }
#line 1852 "generated/parser.yy.cpp"
    break;

  case 34: /* instruction: instruction RETURN expr ';'  */
#line 488 "language/parser.y"
                                                        {
                                                            /* The return instruction will jump to the main instruction (out of function) */
                                                            add_instruction(JMP, -1);
                                                        }
#line 1861 "generated/parser.yy.cpp"
    break;

  case 35: /* $@2: %empty  */
#line 492 "language/parser.y"
                                                        {

                                                            // Save current location to be able to modify it later
                                                            (yyvsp[-2].ADDRESS).jc = functions[current_scope[0]].iic;
                                                            add_instruction(JMPCOND);
                                                        }
#line 1872 "generated/parser.yy.cpp"
    break;

  case 36: /* $@3: %empty  */
#line 498 "language/parser.y"
                                                        {
                                                            // Save current location to be able to modify it later
                                                            (yyvsp[-4].ADDRESS).jmp = functions[current_scope[0]].iic;
                                                            add_instruction(JMP);

                                                            // Update condi jmp now that the instructions passed
                                                            functions[current_scope[0]].code[(yyvsp[-4].ADDRESS).jc].value = functions[current_scope[0]].iic;
                                                        }
#line 1885 "generated/parser.yy.cpp"
    break;

  case 37: /* instruction: instruction IF logic '{' $@2 instruction $@3 '}' ELSE '{' instruction '}'  */
#line 508 "language/parser.y"
                                                        {
                                                            // Update JMP value for when we don't go to the else part, skip it entirely
                                                            functions[current_scope[0]].code[(yyvsp[-10].ADDRESS).jmp].value = functions[current_scope[0]].iic;
                                                        }
#line 1894 "generated/parser.yy.cpp"
    break;

  case 38: /* $@4: %empty  */
#line 512 "language/parser.y"
                                                                        {

                                                                add_instruction(FOR,0,(yyvsp[-9].STRING));
                                                                (yyvsp[-10].ADDRESS).jmp = functions[current_scope[0]].iic;
                                                                add_instruction(PROCEEDFOR,0,(yyvsp[-9].STRING));
                                                                (yyvsp[-10].ADDRESS).jc = functions[current_scope[0]].iic;
                                                                add_instruction(JMPCOND, (yyvsp[-10].ADDRESS).jc);

                                                            }
#line 1908 "generated/parser.yy.cpp"
    break;

  case 39: /* $@5: %empty  */
#line 521 "language/parser.y"
                                                            {   add_instruction(JMP, (yyvsp[-12].ADDRESS).jmp);   }
#line 1914 "generated/parser.yy.cpp"
    break;

  case 40: /* instruction: instruction FOR VAR in '[' expr ':' expr ':' expr ']' '{' $@4 instruction $@5 '}'  */
#line 522 "language/parser.y"
                                                            {
                                                                //! Check stack value
                                                                functions[current_scope[0]].code[(yyvsp[-14].ADDRESS).jc].value = functions[current_scope[0]].iic;
                                                            }
#line 1923 "generated/parser.yy.cpp"
    break;

  case 41: /* $@6: %empty  */
#line 526 "language/parser.y"
                                                            {
                                                                // Store instruction vector index of both jumps
                                                                (yyvsp[-2].ADDRESS).jc = functions[current_scope[0]].iic;
                                                                add_instruction(JMPCOND, (yyvsp[-2].ADDRESS).jc);
                                                            }
#line 1933 "generated/parser.yy.cpp"
    break;

  case 42: /* $@7: %empty  */
#line 531 "language/parser.y"
                                                            {   add_instruction(JMP, 0); }
#line 1939 "generated/parser.yy.cpp"
    break;

  case 43: /* instruction: instruction WHILE logic '{' $@6 instruction $@7 '}'  */
#line 532 "language/parser.y"
                                                            {
                                                                functions[current_scope[0]].code[(yyvsp[-6].ADDRESS).jc].value = functions[current_scope[0]].iic;
                                                            }
#line 1947 "generated/parser.yy.cpp"
    break;

  case 44: /* logic: expr SUP expr  */
#line 540 "language/parser.y"
                            { add_instruction(SUP); }
#line 1953 "generated/parser.yy.cpp"
    break;

  case 45: /* logic: expr INF expr  */
#line 541 "language/parser.y"
                            { add_instruction(INF); }
#line 1959 "generated/parser.yy.cpp"
    break;

  case 46: /* logic: expr SUP_STRICT expr  */
#line 542 "language/parser.y"
                            { add_instruction(SUP_STRICT); }
#line 1965 "generated/parser.yy.cpp"
    break;

  case 47: /* logic: expr INF_STRICT expr  */
#line 543 "language/parser.y"
                            { add_instruction(INF_STRICT); }
#line 1971 "generated/parser.yy.cpp"
    break;

  case 48: /* logic: expr EQUAL expr  */
#line 544 "language/parser.y"
                            { add_instruction(EQUAL); }
#line 1977 "generated/parser.yy.cpp"
    break;

  case 49: /* logic: expr NOT_EQ expr  */
#line 545 "language/parser.y"
                            { add_instruction(NOT_EQ); }
#line 1983 "generated/parser.yy.cpp"
    break;

  case 50: /* logic: logic AND logic  */
#line 546 "language/parser.y"
                            { add_instruction(AND); }
#line 1989 "generated/parser.yy.cpp"
    break;

  case 51: /* logic: logic OR logic  */
#line 547 "language/parser.y"
                            { add_instruction(OR); }
#line 1995 "generated/parser.yy.cpp"
    break;

  case 52: /* logic: NOT logic  */
#line 548 "language/parser.y"
                            { add_instruction(NOT); }
#line 2001 "generated/parser.yy.cpp"
    break;

  case 53: /* expr: NUM  */
#line 552 "language/parser.y"
                            {
                                if (!current_scope.empty())
                                    add_instruction(NUM, (yyvsp[0].DOUBLE));
                                else
                                    (yyval.DOUBLE) = (yyvsp[0].DOUBLE);
                            }
#line 2012 "generated/parser.yy.cpp"
    break;

  case 54: /* expr: PI  */
#line 558 "language/parser.y"
                            {
                                if (!current_scope.empty())
                                    add_instruction(NUM, 3.14159265358979323846);
                                else
                                    (yyval.DOUBLE) = 3.14159265358979323846;
                            }
#line 2023 "generated/parser.yy.cpp"
    break;

  case 55: /* expr: E  */
#line 564 "language/parser.y"
                            {
                                if (!current_scope.empty())
                                    add_instruction(NUM, 2.71828182845904523536);
                                else
                                    (yyval.DOUBLE) = 2.71828182845904523536;
                            }
#line 2034 "generated/parser.yy.cpp"
    break;

  case 56: /* expr: PHI  */
#line 570 "language/parser.y"
                            {
                                if (!current_scope.empty())
                                    add_instruction(NUM, 1.61803398874989484820);
                                else
                                    (yyval.DOUBLE) = 1.61803398874989484820;
                            }
#line 2045 "generated/parser.yy.cpp"
    break;

  case 57: /* expr: SIN '(' expr ')'  */
#line 576 "language/parser.y"
                            {
                                if (!current_scope.empty())
                                    add_instruction(SIN);
                                else
                                    (yyval.DOUBLE) = sin((yyvsp[-1].DOUBLE));
                            }
#line 2056 "generated/parser.yy.cpp"
    break;

  case 58: /* expr: COS '(' expr ')'  */
#line 582 "language/parser.y"
                            {
                                if (!current_scope.empty())
                                    add_instruction(COS);
                                else
                                    (yyval.DOUBLE) = cos((yyvsp[-1].DOUBLE));
                            }
#line 2067 "generated/parser.yy.cpp"
    break;

  case 59: /* expr: TAN '(' expr ')'  */
#line 588 "language/parser.y"
                            {
                                if (!current_scope.empty())
                                    add_instruction(TAN);
                                else
                                    (yyval.DOUBLE) = tan((yyvsp[-1].DOUBLE));
                            }
#line 2078 "generated/parser.yy.cpp"
    break;

  case 60: /* expr: ARCCOS '(' expr ')'  */
#line 594 "language/parser.y"
                            {
                                if (!current_scope.empty())
                                    add_instruction(ARCCOS);
                                else
                                    (yyval.DOUBLE) = acos((yyvsp[-1].DOUBLE));
                            }
#line 2089 "generated/parser.yy.cpp"
    break;

  case 61: /* expr: ARCSIN '(' expr ')'  */
#line 600 "language/parser.y"
                            {
                                if (!current_scope.empty())
                                    add_instruction(ARCSIN);
                                else
                                    (yyval.DOUBLE) = asin((yyvsp[-1].DOUBLE));
                            }
#line 2100 "generated/parser.yy.cpp"
    break;

  case 62: /* expr: ARCTAN '(' expr ')'  */
#line 606 "language/parser.y"
                            {
                                if (!current_scope.empty())
                                    add_instruction(ARCTAN);
                                else
                                    (yyval.DOUBLE) = atan((yyvsp[-1].DOUBLE));
                            }
#line 2111 "generated/parser.yy.cpp"
    break;

  case 63: /* expr: COSH '(' expr ')'  */
#line 612 "language/parser.y"
                            {
                                if (!current_scope.empty())
                                    add_instruction(COSH);
                                else
                                    (yyval.DOUBLE) = cosh((yyvsp[-1].DOUBLE));
                            }
#line 2122 "generated/parser.yy.cpp"
    break;

  case 64: /* expr: SINH '(' expr ')'  */
#line 618 "language/parser.y"
                            {
                                if (!current_scope.empty())
                                    add_instruction(SINH);
                                else
                                    (yyval.DOUBLE) = sinh((yyvsp[-1].DOUBLE));
                            }
#line 2133 "generated/parser.yy.cpp"
    break;

  case 65: /* expr: TANH '(' expr ')'  */
#line 624 "language/parser.y"
                            {
                                if (!current_scope.empty())
                                    add_instruction(TANH);
                                else
                                    (yyval.DOUBLE) = tanh((yyvsp[-1].DOUBLE));
                            }
#line 2144 "generated/parser.yy.cpp"
    break;

  case 66: /* expr: ARCCOSH '(' expr ')'  */
#line 630 "language/parser.y"
                            {
                                if (!current_scope.empty())
                                    add_instruction(ARCCOSH);
                                else
                                    (yyval.DOUBLE) = acosh((yyvsp[-1].DOUBLE));
                            }
#line 2155 "generated/parser.yy.cpp"
    break;

  case 67: /* expr: ARCSINH '(' expr ')'  */
#line 636 "language/parser.y"
                            {
                                if (!current_scope.empty())
                                    add_instruction(ARCSINH);
                                else
                                    (yyval.DOUBLE) = asinh((yyvsp[-1].DOUBLE));
                            }
#line 2166 "generated/parser.yy.cpp"
    break;

  case 68: /* expr: ARCTANH '(' expr ')'  */
#line 642 "language/parser.y"
                            {
                                if (!current_scope.empty())
                                    add_instruction(ARCTANH);
                                else
                                    (yyval.DOUBLE) = atanh((yyvsp[-1].DOUBLE));
                            }
#line 2177 "generated/parser.yy.cpp"
    break;

  case 69: /* expr: '(' expr ')'  */
#line 648 "language/parser.y"
                            { (yyval.DOUBLE) = (yyvsp[-1].DOUBLE); }
#line 2183 "generated/parser.yy.cpp"
    break;

  case 70: /* expr: MIN expr  */
#line 649 "language/parser.y"
                            {
                                if (!current_scope.empty())
                                    add_instruction(OPP);
                                else
                                    (yyval.DOUBLE) = -(yyvsp[0].DOUBLE);
                            }
#line 2194 "generated/parser.yy.cpp"
    break;

  case 71: /* expr: expr PLUS expr  */
#line 655 "language/parser.y"
                            {
                                if (!current_scope.empty())
                                    add_instruction(PLUS);
                                else
                                    (yyval.DOUBLE) = (yyvsp[-2].DOUBLE) + (yyvsp[0].DOUBLE);
                            }
#line 2205 "generated/parser.yy.cpp"
    break;

  case 72: /* expr: expr MIN expr  */
#line 661 "language/parser.y"
                            {
                                if (!current_scope.empty())
                                    add_instruction(MIN);
                                else
                                    (yyval.DOUBLE) = (yyvsp[-2].DOUBLE) - (yyvsp[0].DOUBLE);
                            }
#line 2216 "generated/parser.yy.cpp"
    break;

  case 73: /* expr: expr TIMES expr  */
#line 667 "language/parser.y"
                            {
                                if (!current_scope.empty())
                                    add_instruction(TIMES);
                                else
                                    (yyval.DOUBLE) = (yyvsp[-2].DOUBLE) * (yyvsp[0].DOUBLE);
                            }
#line 2227 "generated/parser.yy.cpp"
    break;

  case 74: /* expr: expr DIV expr  */
#line 673 "language/parser.y"
                            {
                                if (!current_scope.empty())
                                    add_instruction(DIV);
                                else {
                                    if ((yyvsp[0].DOUBLE) == 0.) {
                                        error = "Dividing by 0...\n";
                                        verbose(error);
                                    } else
                                        (yyval.DOUBLE) = (yyvsp[-2].DOUBLE) / (yyvsp[0].DOUBLE);
                                }
                            }
#line 2243 "generated/parser.yy.cpp"
    break;

  case 75: /* expr: expr '^' expr  */
#line 684 "language/parser.y"
                                    {
                                        if (!current_scope.empty())
                                            add_instruction(POW);
                                        else {
                                            if ((yyvsp[-2].DOUBLE) == 0. && (yyvsp[0].DOUBLE) == 0.) {
                                                error = "Can't put 0 to the power 0...\n";
                                                verbose(error);
                                            } else
                                                (yyval.DOUBLE) = pow((yyvsp[-2].DOUBLE),(yyvsp[0].DOUBLE));
                                        }
                                    }
#line 2259 "generated/parser.yy.cpp"
    break;

  case 76: /* expr: POW '(' expr ',' expr ')'  */
#line 695 "language/parser.y"
                                    {
                                        if (!current_scope.empty())
                                            add_instruction(POW);
                                        else {
                                            if ((yyvsp[-3].DOUBLE) == 0. && (yyvsp[-1].DOUBLE) == 0.) {
                                                error = "Can't put 0 to the power 0...\n";
                                                verbose(error);
                                            } else
                                                (yyval.DOUBLE) = pow((yyvsp[-3].DOUBLE),(yyvsp[-1].DOUBLE));
                                        }
                                    }
#line 2275 "generated/parser.yy.cpp"
    break;

  case 77: /* expr: EXP '(' expr ')'  */
#line 706 "language/parser.y"
                                    {
                                        if (!current_scope.empty())
                                            add_instruction(EXP);
                                        else
                                            (yyval.DOUBLE) = exp((yyvsp[-1].DOUBLE));
                                    }
#line 2286 "generated/parser.yy.cpp"
    break;

  case 78: /* expr: LOG '(' expr ')'  */
#line 712 "language/parser.y"
                                    {
                                        if (!current_scope.empty())
                                            add_instruction(LOG);
                                        else
                                            (yyval.DOUBLE) = log((yyvsp[-1].DOUBLE));
                                    }
#line 2297 "generated/parser.yy.cpp"
    break;

  case 79: /* expr: SQRT '(' expr ')'  */
#line 718 "language/parser.y"
                                    {
                                        if (!current_scope.empty())
                                            add_instruction(SQRT);
                                        else
                                            (yyval.DOUBLE) = sqrt((yyvsp[-1].DOUBLE));
                                    }
#line 2308 "generated/parser.yy.cpp"
    break;

  case 80: /* expr: VAR  */
#line 724 "language/parser.y"
                                    {
                                        /* Only add to the ins vector if we are in a function */
                                        if (!current_scope.empty()) {
                                            add_instruction(VAR, 0, (yyvsp[0].STRING));
                                        } else {
                                            if (variables.count((yyvsp[0].STRING)))
                                                (yyval.DOUBLE) = variables.at((yyvsp[0].STRING));
                                        }
                                    }
#line 2322 "generated/parser.yy.cpp"
    break;

  case 81: /* expr: VAR '=' expr  */
#line 733 "language/parser.y"
                                    {
                                        /* Only add to the ins vector if we are in a function */
                                        if (!current_scope.empty()) {
                                            add_instruction(ASSIGN,0,(yyvsp[-2].STRING));
                                        } else {
                                            error = "Can only assign to an already declared variable when in a function...\n";
                                            verbose(error);
                                        }
                                    }
#line 2336 "generated/parser.yy.cpp"
    break;

  case 82: /* expr: VAR PLUS_EQUAL expr  */
#line 742 "language/parser.y"
                                    {
                                        /* Only add to the ins vector if we are in a function */
                                        if (!current_scope.empty()) {
                                            add_instruction(VAR,0,(yyvsp[-2].STRING));
                                            add_instruction(PLUS);
                                            add_instruction(ASSIGN,0,(yyvsp[-2].STRING));
                                        } else {
                                            error ="Can only assign to an already declared variable when in a function...\n";
                                            verbose(error);
                                        }
                                    }
#line 2352 "generated/parser.yy.cpp"
    break;

  case 83: /* expr: VAR MIN_EQUAL expr  */
#line 753 "language/parser.y"
                                    {
                                        /* Only add to the ins vector if we are in a function */
                                        if (!current_scope.empty()) {
                                            add_instruction(VAR,0,(yyvsp[-2].STRING));
                                            add_instruction(MIN);
                                            add_instruction(OPP);
                                            add_instruction(ASSIGN,0,(yyvsp[-2].STRING));
                                        } else {
                                            error = "Can only assign to an already declared variable when in a function...\n";
                                            verbose(error);
                                        }
                                    }
#line 2369 "generated/parser.yy.cpp"
    break;

  case 84: /* expr: VAR TIMES_EQUAL expr  */
#line 765 "language/parser.y"
                                    {
                                        /* Only add to the ins vector if we are in a function */
                                        if (!current_scope.empty()) {
                                            add_instruction(VAR,0,(yyvsp[-2].STRING));
                                            add_instruction(TIMES);
                                            add_instruction(ASSIGN,0,(yyvsp[-2].STRING));
                                        } else {
                                            error = "Can only assign to an already declared variable when in a function...\n";
                                            verbose(error);
                                        }
                                    }
#line 2385 "generated/parser.yy.cpp"
    break;

  case 85: /* expr: VAR DIV_EQUAL expr  */
#line 776 "language/parser.y"
                                    {
                                        /* Only add to the ins vector if we are in a function */
                                        if (!current_scope.empty()) {
                                            add_instruction(VAR,0,(yyvsp[-2].STRING));
                                            add_instruction(DIV);
                                            add_instruction(ASSIGN,0,(yyvsp[-2].STRING));
                                        } else {
                                            error = "Can only assign to an already declared variable when in a function...\n";
                                            verbose(error);
                                        }
                                    }
#line 2401 "generated/parser.yy.cpp"
    break;


#line 2405 "generated/parser.yy.cpp"

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

#line 788 "language/parser.y"



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
