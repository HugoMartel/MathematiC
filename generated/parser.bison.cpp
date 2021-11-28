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
        int add_instruction(const int &c, const double &v=0, const string &n="") {
            code.push_back(instruction(c,v,n));
            ic++;
        return 0;
        }
    };

    // Structure pour accueillir le code généré
    // (sone de code ou code machine ou assembleur)
    vector <instruction> code_genere;

    /**
     * String storing the current code to write to.
     * 0 -> main code, otherwise write to the associated function
     */
    std::string current_code = "";

    // Déclaration de la map qui associe
    // les noms des variables à leur valeur
    // (La table de symboles)
    std::map<std::string,double> variables;
    //  Map storing functions instructions, access them by their name (string)
    std::map<std::string, function> functions;
    int ic = 0;

    // Remarquez les paramètres par défaut pour faciliter les appels depuis la grammaire
    int add_instruction(const int &c, const double &v=0, const string &n="") {
        code_genere.push_back(instruction(c,v,n));
        ic++;
        return 0;
    }

#line 169 "generated/parser.bison.cpp"

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

#include "parser.bison.hpp"
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
  YYSYMBOL_arrow = 6,                      /* arrow  */
  YYSYMBOL_RETURN = 7,                     /* RETURN  */
  YYSYMBOL_color = 8,                      /* color  */
  YYSYMBOL_style = 9,                      /* style  */
  YYSYMBOL_label = 10,                     /* label  */
  YYSYMBOL_xmin = 11,                      /* xmin  */
  YYSYMBOL_xmax = 12,                      /* xmax  */
  YYSYMBOL_ymin = 13,                      /* ymin  */
  YYSYMBOL_ymax = 14,                      /* ymax  */
  YYSYMBOL_COLOR_PARAM = 15,               /* COLOR_PARAM  */
  YYSYMBOL_STYLE_PARAM = 16,               /* STYLE_PARAM  */
  YYSYMBOL_STRING = 17,                    /* STRING  */
  YYSYMBOL_NUM = 18,                       /* NUM  */
  YYSYMBOL_SIN = 19,                       /* SIN  */
  YYSYMBOL_COS = 20,                       /* COS  */
  YYSYMBOL_POW = 21,                       /* POW  */
  YYSYMBOL_EXP = 22,                       /* EXP  */
  YYSYMBOL_VAR = 23,                       /* VAR  */
  YYSYMBOL_FOR = 24,                       /* FOR  */
  YYSYMBOL_IF = 25,                        /* IF  */
  YYSYMBOL_ELSE = 26,                      /* ELSE  */
  YYSYMBOL_WHILE = 27,                     /* WHILE  */
  YYSYMBOL_TAN = 28,                       /* TAN  */
  YYSYMBOL_ARCCOS = 29,                    /* ARCCOS  */
  YYSYMBOL_ARCSIN = 30,                    /* ARCSIN  */
  YYSYMBOL_ARCTAN = 31,                    /* ARCTAN  */
  YYSYMBOL_COSH = 32,                      /* COSH  */
  YYSYMBOL_SINH = 33,                      /* SINH  */
  YYSYMBOL_TANH = 34,                      /* TANH  */
  YYSYMBOL_ARCSINH = 35,                   /* ARCSINH  */
  YYSYMBOL_ARCCOSH = 36,                   /* ARCCOSH  */
  YYSYMBOL_ARCTANH = 37,                   /* ARCTANH  */
  YYSYMBOL_SQRT = 38,                      /* SQRT  */
  YYSYMBOL_LOG = 39,                       /* LOG  */
  YYSYMBOL_DRAW = 40,                      /* DRAW  */
  YYSYMBOL_JMP = 41,                       /* JMP  */
  YYSYMBOL_JMPCOND = 42,                   /* JMPCOND  */
  YYSYMBOL_ASSIGN = 43,                    /* ASSIGN  */
  YYSYMBOL_DECLARE = 44,                   /* DECLARE  */
  YYSYMBOL_PLUS = 45,                      /* PLUS  */
  YYSYMBOL_MIN = 46,                       /* MIN  */
  YYSYMBOL_TIMES = 47,                     /* TIMES  */
  YYSYMBOL_DIV = 48,                       /* DIV  */
  YYSYMBOL_PLUS_EQUAL = 49,                /* PLUS_EQUAL  */
  YYSYMBOL_MIN_EQUAL = 50,                 /* MIN_EQUAL  */
  YYSYMBOL_TIMES_EQUAL = 51,               /* TIMES_EQUAL  */
  YYSYMBOL_DIV_EQUAL = 52,                 /* DIV_EQUAL  */
  YYSYMBOL_EQUAL = 53,                     /* EQUAL  */
  YYSYMBOL_NOT_EQ = 54,                    /* NOT_EQ  */
  YYSYMBOL_INF_STRICT = 55,                /* INF_STRICT  */
  YYSYMBOL_SUP_STRICT = 56,                /* SUP_STRICT  */
  YYSYMBOL_INF = 57,                       /* INF  */
  YYSYMBOL_SUP = 58,                       /* SUP  */
  YYSYMBOL_AND = 59,                       /* AND  */
  YYSYMBOL_OR = 60,                        /* OR  */
  YYSYMBOL_NOT = 61,                       /* NOT  */
  YYSYMBOL_62_ = 62,                       /* '|'  */
  YYSYMBOL_63_ = 63,                       /* '&'  */
  YYSYMBOL_64_ = 64,                       /* '^'  */
  YYSYMBOL_65_ = 65,                       /* '='  */
  YYSYMBOL_66_ = 66,                       /* ';'  */
  YYSYMBOL_67_ = 67,                       /* ':'  */
  YYSYMBOL_68_ = 68,                       /* '('  */
  YYSYMBOL_69_ = 69,                       /* ')'  */
  YYSYMBOL_70_ = 70,                       /* '{'  */
  YYSYMBOL_71_ = 71,                       /* '}'  */
  YYSYMBOL_72_ = 72,                       /* ','  */
  YYSYMBOL_73_ = 73,                       /* '['  */
  YYSYMBOL_74_ = 74,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 75,                  /* $accept  */
  YYSYMBOL_code = 76,                      /* code  */
  YYSYMBOL_declarations = 77,              /* declarations  */
  YYSYMBOL_fonctions = 78,                 /* fonctions  */
  YYSYMBOL_79_1 = 79,                      /* $@1  */
  YYSYMBOL_args = 80,                      /* args  */
  YYSYMBOL_draw_func = 81,                 /* draw_func  */
  YYSYMBOL_affichage = 82,                 /* affichage  */
  YYSYMBOL_83_2 = 83,                      /* $@2  */
  YYSYMBOL_draw_args = 84,                 /* draw_args  */
  YYSYMBOL_style_args = 85,                /* style_args  */
  YYSYMBOL_color_args = 86,                /* color_args  */
  YYSYMBOL_instruction = 87,               /* instruction  */
  YYSYMBOL_88_3 = 88,                      /* $@3  */
  YYSYMBOL_89_4 = 89,                      /* $@4  */
  YYSYMBOL_logic = 90,                     /* logic  */
  YYSYMBOL_expr = 91                       /* expr  */
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
#define YYLAST   441

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  75
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  228

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   316


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
       2,     2,     2,     2,     2,     2,     2,     2,    63,     2,
      68,    69,     2,     2,    72,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    67,    66,
       2,    65,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    73,     2,    74,    64,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    70,    62,    71,     2,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   204,   204,   207,   210,   219,   228,   228,   231,   233,
     234,   237,   238,   239,   242,   242,   245,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   261,
     262,   265,   266,   269,   270,   271,   272,   280,   272,   296,
     299,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   339,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355
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
  "arrow", "RETURN", "color", "style", "label", "xmin", "xmax", "ymin",
  "ymax", "COLOR_PARAM", "STYLE_PARAM", "STRING", "NUM", "SIN", "COS",
  "POW", "EXP", "VAR", "FOR", "IF", "ELSE", "WHILE", "TAN", "ARCCOS",
  "ARCSIN", "ARCTAN", "COSH", "SINH", "TANH", "ARCSINH", "ARCCOSH",
  "ARCTANH", "SQRT", "LOG", "DRAW", "JMP", "JMPCOND", "ASSIGN", "DECLARE",
  "PLUS", "MIN", "TIMES", "DIV", "PLUS_EQUAL", "MIN_EQUAL", "TIMES_EQUAL",
  "DIV_EQUAL", "EQUAL", "NOT_EQ", "INF_STRICT", "SUP_STRICT", "INF", "SUP",
  "AND", "OR", "NOT", "'|'", "'&'", "'^'", "'='", "';'", "':'", "'('",
  "')'", "'{'", "'}'", "','", "'['", "']'", "$accept", "code",
  "declarations", "fonctions", "$@1", "args", "draw_func", "affichage",
  "$@2", "draw_args", "style_args", "color_args", "instruction", "$@3",
  "$@4", "logic", "expr", YY_NULLPTR
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
     315,   316,   124,    38,    94,    61,    59,    58,    40,    41,
     123,   125,    44,    91,    93
};
#endif

#define YYPACT_NINF (-166)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -166,     6,   201,  -166,    47,    67,    20,   142,    25,    83,
     118,  -166,   110,  -166,    42,   109,    45,  -166,    58,    82,
      88,   119,   351,   144,   169,   173,   206,   210,   223,   224,
     243,   247,   260,   261,   280,   110,   -37,   154,   220,  -166,
    -166,    83,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   147,   110,   110,   110,   110,   110,   110,
     110,  -166,  -166,   131,   238,   396,   293,   151,   176,   -44,
     180,    73,    73,    73,    73,    73,   184,   188,   213,   217,
     221,   225,   250,   254,   258,   262,   287,   291,  -166,    61,
      61,   155,   155,   266,   266,   266,   346,   154,   300,   304,
     310,   315,   316,   320,   321,   326,   183,  -166,  -166,   110,
    -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,
    -166,  -166,  -166,   341,   340,   380,   342,   344,   397,   -11,
      -2,    -1,   153,  -166,   396,   295,  -166,   339,   403,   404,
    -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,   347,
    -166,    44,  -166,  -166,   -59,  -166,   -13,   110,   398,    66,
      66,   352,   328,   403,  -166,   404,  -166,   333,   417,    66,
     354,   106,   355,  -166,  -166,   356,   357,  -166,   353,  -166,
    -166,   110,   110,   110,   110,   110,   110,   110,   110,    44,
     110,    44,    73,    73,    73,    73,    73,    73,    73,    73,
     359,   299,  -166,  -166,   110,   360,   322,   401,   110,   362,
     127,    44,   363,   364,    44,  -166,   365,  -166
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     1,     0,     0,     0,     0,     0,     0,
       8,     2,     0,     5,     0,    12,     0,    50,     0,     0,
       0,     0,    75,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    16,
      14,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     4,     9,     0,     0,     0,    13,     0,     0,     0,
       0,    77,    78,    79,    80,    76,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    63,    64,
      65,    66,    67,    69,    68,    70,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    51,    52,     0,
      72,    53,    54,    55,    56,    58,    57,    59,    61,    60,
      62,    74,    73,     0,    10,     0,     0,     0,     0,     0,
       0,     0,     0,    15,     0,     0,     6,     0,     0,     0,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      71,    33,    11,    31,     0,    29,     0,     0,     0,     0,
       0,     0,     0,     0,    17,     0,    18,     0,     0,     0,
       0,     0,     0,     7,    34,    32,    30,    35,     0,    49,
      36,     0,     0,     0,     0,     0,     0,     0,     0,    33,
       0,    33,    45,    46,    44,    43,    42,    41,    47,    48,
       0,     0,    37,    40,     0,     0,     0,     0,     0,     0,
       0,    33,     0,     0,    33,    38,     0,    39
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -166,  -166,  -166,   432,  -166,   330,   399,  -166,  -166,   294,
     264,   268,  -108,  -166,  -166,  -165,   -12
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    10,   161,    73,    16,    11,    75,   116,
     166,   164,   171,   201,   215,   180,   172
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      36,    64,    65,    66,    67,   182,     3,   151,    64,    65,
      66,    67,   152,   173,   189,   174,   153,   155,    68,    69,
      70,   154,   156,    63,     5,    68,    69,    70,   119,    71,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,   167,    99,   100,   101,   102,   103,   104,   105,   175,
       9,   176,    17,    18,    19,    20,    21,    22,   168,   169,
       7,   170,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    17,    18,    19,    20,    21,    22,
       8,   210,    14,   212,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    15,   145,    66,    67,
      37,    39,    35,   223,    38,    40,   226,    41,    64,    65,
      66,    67,     5,    68,    69,    70,    42,   179,    17,    18,
      19,    20,    21,    22,    35,    68,    69,    70,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      43,    64,    65,    66,    67,   177,    44,   181,   181,   191,
     192,   193,   194,   195,   196,   197,   198,   181,    68,    69,
      70,   157,    64,    65,    66,    67,   158,    72,    35,   202,
     203,   204,   205,   206,   207,   208,   209,    45,   211,    68,
      69,    70,    64,    65,    66,    67,    64,    65,    66,    67,
     106,   222,   216,   107,     4,     5,   220,    12,    13,    68,
      69,    70,    51,    68,    69,    70,    98,    68,    69,    70,
     117,    64,    65,    66,    67,    64,    65,    66,    67,    64,
      65,    66,    67,    64,    65,    66,    67,    52,    68,    69,
      70,    53,    68,    69,    70,   118,    68,    69,    70,   120,
      68,    69,    70,   121,   143,   144,   108,   122,    64,    65,
      66,    67,    64,    65,    66,    67,    64,    65,    66,    67,
      64,    65,    66,    67,    54,    68,    69,    70,    55,    68,
      69,    70,   123,    68,    69,    70,   124,    68,    69,    70,
     125,    56,    57,    74,   126,    64,    65,    66,    67,    64,
      65,    66,    67,    64,    65,    66,    67,    64,    65,    66,
      67,    58,    68,    69,    70,    59,    68,    69,    70,   127,
      68,    69,    70,   128,    68,    69,    70,   129,    60,    61,
      70,   130,    64,    65,    66,    67,    64,    65,    66,    67,
      64,    65,    66,    67,    64,    65,    66,    67,    62,    68,
      69,    70,   133,    68,    69,    70,   131,    68,    69,    70,
     132,    68,    69,    70,   160,    41,   214,    64,    65,    66,
      67,   136,   135,    64,    65,    66,    67,   137,    64,    65,
      66,    67,   138,   139,    68,    69,    70,   140,   141,   218,
      68,    69,    70,   142,   184,    68,    69,    70,   147,   187,
      46,    47,    48,    49,   109,   110,   111,   112,   113,   114,
     115,   146,   107,   162,   150,   148,    50,   149,   163,   144,
     165,   178,   188,   183,   190,   199,   200,   219,   173,   175,
     213,   217,   221,   224,     6,   225,   227,   134,   159,   186,
      76,   185
};

static const yytype_uint8 yycheck[] =
{
      12,    45,    46,    47,    48,   170,     0,    18,    45,    46,
      47,    48,    23,    72,   179,    74,    18,    18,    62,    63,
      64,    23,    23,    35,     4,    62,    63,    64,    72,    66,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,     7,    64,    65,    66,    67,    68,    69,    70,    72,
      40,    74,    18,    19,    20,    21,    22,    23,    24,    25,
      23,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    18,    19,    20,    21,    22,    23,
      23,   199,    67,   201,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    23,   119,    47,    48,
      68,    66,    68,   221,     5,    70,   224,    72,    45,    46,
      47,    48,     4,    62,    63,    64,    68,    61,    18,    19,
      20,    21,    22,    23,    68,    62,    63,    64,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      68,    45,    46,    47,    48,   167,    68,   169,   170,    53,
      54,    55,    56,    57,    58,    59,    60,   179,    62,    63,
      64,    18,    45,    46,    47,    48,    23,    23,    68,   191,
     192,   193,   194,   195,   196,   197,   198,    68,   200,    62,
      63,    64,    45,    46,    47,    48,    45,    46,    47,    48,
      69,    74,   214,    72,     3,     4,   218,    65,    66,    62,
      63,    64,    68,    62,    63,    64,    69,    62,    63,    64,
      69,    45,    46,    47,    48,    45,    46,    47,    48,    45,
      46,    47,    48,    45,    46,    47,    48,    68,    62,    63,
      64,    68,    62,    63,    64,    69,    62,    63,    64,    69,
      62,    63,    64,    69,    71,    72,    18,    69,    45,    46,
      47,    48,    45,    46,    47,    48,    45,    46,    47,    48,
      45,    46,    47,    48,    68,    62,    63,    64,    68,    62,
      63,    64,    69,    62,    63,    64,    69,    62,    63,    64,
      69,    68,    68,    73,    69,    45,    46,    47,    48,    45,
      46,    47,    48,    45,    46,    47,    48,    45,    46,    47,
      48,    68,    62,    63,    64,    68,    62,    63,    64,    69,
      62,    63,    64,    69,    62,    63,    64,    69,    68,    68,
      64,    69,    45,    46,    47,    48,    45,    46,    47,    48,
      45,    46,    47,    48,    45,    46,    47,    48,    68,    62,
      63,    64,     6,    62,    63,    64,    69,    62,    63,    64,
      69,    62,    63,    64,    69,    72,    67,    45,    46,    47,
      48,    67,    72,    45,    46,    47,    48,    67,    45,    46,
      47,    48,    67,    67,    62,    63,    64,    67,    67,    67,
      62,    63,    64,    67,    66,    62,    63,    64,    18,    66,
      49,    50,    51,    52,     8,     9,    10,    11,    12,    13,
      14,    70,    72,    74,    17,    73,    65,    73,    15,    72,
      16,    23,     5,    71,    70,    70,    73,    26,    72,    72,
      71,    71,    70,    70,     2,    71,    71,   107,   144,   175,
      41,   173
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    76,    77,     0,     3,     4,    78,    23,    23,    40,
      78,    82,    65,    66,    67,    23,    81,    18,    19,    20,
      21,    22,    23,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    68,    91,    68,     5,    66,
      70,    72,    68,    68,    68,    68,    49,    50,    51,    52,
      65,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    91,    45,    46,    47,    48,    62,    63,
      64,    66,    23,    80,    73,    83,    81,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    69,    91,
      91,    91,    91,    91,    91,    91,    69,    72,    18,     8,
       9,    10,    11,    12,    13,    14,    84,    69,    69,    72,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,     6,    80,    72,    67,    67,    67,    67,
      67,    67,    67,    71,    72,    91,    70,    18,    73,    73,
      17,    18,    23,    18,    23,    18,    23,    18,    23,    84,
      69,    79,    74,    15,    86,    16,    85,     7,    24,    25,
      27,    87,    91,    72,    74,    72,    74,    91,    23,    61,
      90,    91,    90,    71,    66,    86,    85,    66,     5,    90,
      70,    53,    54,    55,    56,    57,    58,    59,    60,    70,
      73,    88,    91,    91,    91,    91,    91,    91,    91,    91,
      87,    91,    87,    71,    67,    89,    91,    71,    67,    26,
      91,    70,    74,    87,    70,    71,    87,    71
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    75,    76,    77,    77,    77,    79,    78,    78,    80,
      80,    81,    81,    81,    83,    82,    82,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    85,
      85,    86,    86,    87,    87,    87,    88,    89,    87,    87,
      87,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     0,     6,     4,     0,    11,     2,     1,
       3,     7,     1,     3,     0,     6,     3,     5,     5,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       3,     1,     3,     0,     2,     3,     0,     0,    11,    13,
       5,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       1,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     3,     3,     3,     3,     3,     3,     3,
       3,     6,     4,     4,     4,     1,     3,     3,     3,     3,
       3
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
#line 204 "language/parser.y"
                                                        { /* TODO: print start compiling */ }
#line 1444 "generated/parser.bison.cpp"
    break;

  case 3: /* declarations: %empty  */
#line 207 "language/parser.y"
                                                    { /* End of declarations */
                    std::cout << "-- End of declarations --\n";
 }
#line 1452 "generated/parser.bison.cpp"
    break;

  case 4: /* declarations: declarations var VAR '=' expr ';'  */
#line 210 "language/parser.y"
                                                    { /* Init Vars */
                if (!variables.count((yyvsp[-3].STRING))) {
                    variables[(yyvsp[-3].STRING)] = (yyvsp[-1].DOUBLE);
                    add_instruction(DECLARE, 0, (yyvsp[-3].STRING));
                    add_instruction(ASSIGN, 0, (yyvsp[-3].STRING));
                } else {
                    yyerror("Variable already declared...");
                }
}
#line 1466 "generated/parser.bison.cpp"
    break;

  case 5: /* declarations: declarations var VAR ';'  */
#line 219 "language/parser.y"
                                                    {
                if (!variables.count((yyvsp[-1].STRING))) {
                    variables[(yyvsp[-1].STRING)] = 0;
                    add_instruction(DECLARE, 0, (yyvsp[-1].STRING));
                    add_instruction(ASSIGN, 0, (yyvsp[-1].STRING));
                }
            }
#line 1478 "generated/parser.bison.cpp"
    break;

  case 6: /* $@1: %empty  */
#line 228 "language/parser.y"
                                                        { /* TODO */ }
#line 1484 "generated/parser.bison.cpp"
    break;

  case 8: /* fonctions: fonctions fonctions  */
#line 231 "language/parser.y"
                                                        { /* TODO */ }
#line 1490 "generated/parser.bison.cpp"
    break;

  case 9: /* args: VAR  */
#line 233 "language/parser.y"
                                                        { /* TODO */ }
#line 1496 "generated/parser.bison.cpp"
    break;

  case 10: /* args: args ',' args  */
#line 234 "language/parser.y"
                                                        { /* TODO */ }
#line 1502 "generated/parser.bison.cpp"
    break;

  case 11: /* draw_func: VAR in '[' NUM ',' NUM ']'  */
#line 237 "language/parser.y"
                                                        { /* TODO */ }
#line 1508 "generated/parser.bison.cpp"
    break;

  case 12: /* draw_func: VAR  */
#line 238 "language/parser.y"
                                                        { /* TODO */ }
#line 1514 "generated/parser.bison.cpp"
    break;

  case 13: /* draw_func: draw_func ',' draw_func  */
#line 239 "language/parser.y"
                                                        { /* TODO */ }
#line 1520 "generated/parser.bison.cpp"
    break;

  case 14: /* $@2: %empty  */
#line 242 "language/parser.y"
                                { /*TODO: load funcs*/ }
#line 1526 "generated/parser.bison.cpp"
    break;

  case 16: /* affichage: DRAW draw_func ';'  */
#line 245 "language/parser.y"
                                { /* TODO: load default args */}
#line 1532 "generated/parser.bison.cpp"
    break;

  case 17: /* draw_args: color ':' '[' color_args ']'  */
#line 248 "language/parser.y"
                                         { /*TODO: check PARAM values*/ }
#line 1538 "generated/parser.bison.cpp"
    break;

  case 18: /* draw_args: style ':' '[' style_args ']'  */
#line 249 "language/parser.y"
                                         { /*TODO: check PARAM values*/ }
#line 1544 "generated/parser.bison.cpp"
    break;

  case 19: /* draw_args: label ':' STRING  */
#line 250 "language/parser.y"
                                         { /*TODO: check PARAM values*/ }
#line 1550 "generated/parser.bison.cpp"
    break;

  case 20: /* draw_args: xmin ':' NUM  */
#line 251 "language/parser.y"
                                         { /*TODO*/ }
#line 1556 "generated/parser.bison.cpp"
    break;

  case 21: /* draw_args: xmin ':' VAR  */
#line 252 "language/parser.y"
                                         { /*TODO*/ }
#line 1562 "generated/parser.bison.cpp"
    break;

  case 22: /* draw_args: xmax ':' NUM  */
#line 253 "language/parser.y"
                                         { /*TODO*/ }
#line 1568 "generated/parser.bison.cpp"
    break;

  case 23: /* draw_args: xmax ':' VAR  */
#line 254 "language/parser.y"
                                         { /*TODO*/ }
#line 1574 "generated/parser.bison.cpp"
    break;

  case 24: /* draw_args: ymin ':' NUM  */
#line 255 "language/parser.y"
                                         { /*TODO*/ }
#line 1580 "generated/parser.bison.cpp"
    break;

  case 25: /* draw_args: ymin ':' VAR  */
#line 256 "language/parser.y"
                                         { /*TODO*/ }
#line 1586 "generated/parser.bison.cpp"
    break;

  case 26: /* draw_args: ymax ':' NUM  */
#line 257 "language/parser.y"
                                         { /*TODO*/ }
#line 1592 "generated/parser.bison.cpp"
    break;

  case 27: /* draw_args: ymax ':' VAR  */
#line 258 "language/parser.y"
                                         { /*TODO*/ }
#line 1598 "generated/parser.bison.cpp"
    break;

  case 28: /* draw_args: draw_args ',' draw_args  */
#line 259 "language/parser.y"
                                         { /*TODO*/ }
#line 1604 "generated/parser.bison.cpp"
    break;

  case 29: /* style_args: STYLE_PARAM  */
#line 261 "language/parser.y"
                                         { /*TODO*/ }
#line 1610 "generated/parser.bison.cpp"
    break;

  case 30: /* style_args: style_args ',' style_args  */
#line 262 "language/parser.y"
                                         { /*TODO*/ }
#line 1616 "generated/parser.bison.cpp"
    break;

  case 31: /* color_args: COLOR_PARAM  */
#line 265 "language/parser.y"
                                         { /*TODO*/ }
#line 1622 "generated/parser.bison.cpp"
    break;

  case 32: /* color_args: color_args ',' color_args  */
#line 266 "language/parser.y"
                                         { /*TODO*/ }
#line 1628 "generated/parser.bison.cpp"
    break;

  case 33: /* instruction: %empty  */
#line 269 "language/parser.y"
                                        { /* No instructions left */ }
#line 1634 "generated/parser.bison.cpp"
    break;

  case 34: /* instruction: expr ';'  */
#line 270 "language/parser.y"
                                        { /* End of instruction */ }
#line 1640 "generated/parser.bison.cpp"
    break;

  case 35: /* instruction: RETURN expr ';'  */
#line 271 "language/parser.y"
                                        { printf("Returning: %g\n", (yyvsp[-1].DOUBLE)); }
#line 1646 "generated/parser.bison.cpp"
    break;

  case 36: /* $@3: %empty  */
#line 272 "language/parser.y"
                                        {

                // Je sauvegarde l'endroit actuel pour revenir mofifier l'adresse
                // lorsqu'elle sera connue (celle du JC)

                (yyvsp[-2].ADDRESS).jc = ic;
                add_instruction(JMPCOND);
}
#line 1659 "generated/parser.bison.cpp"
    break;

  case 37: /* $@4: %empty  */
#line 280 "language/parser.y"
                                        {
                // Je sauvegarde l'endroit actuel pour revenir mofifier l'adresse
                // lorsqu'elle sera connue (celle du JMP)

                (yyvsp[-4].ADDRESS).jmp = ic;
                add_instruction(JMP);

                // Je mets à jour l'adresse du saut conditionnel
                code_genere[(yyvsp[-4].ADDRESS).jc].value = ic;
}
#line 1674 "generated/parser.bison.cpp"
    break;

  case 38: /* instruction: IF logic '{' $@3 instruction $@4 '}' ELSE '{' instruction '}'  */
#line 292 "language/parser.y"
                                        {
                // Je mets à jour l'adresse du saut inconditionnel
                 code_genere[(yyvsp[-10].ADDRESS).jmp].value = ic;
}
#line 1683 "generated/parser.bison.cpp"
    break;

  case 39: /* instruction: FOR VAR in '[' expr ':' expr ':' expr ']' '{' instruction '}'  */
#line 298 "language/parser.y"
                                        { add_instruction(FOR); }
#line 1689 "generated/parser.bison.cpp"
    break;

  case 40: /* instruction: WHILE logic '{' instruction '}'  */
#line 301 "language/parser.y"
                                        { add_instruction(WHILE); }
#line 1695 "generated/parser.bison.cpp"
    break;

  case 41: /* logic: expr SUP expr  */
#line 304 "language/parser.y"
                            { add_instruction(SUP); }
#line 1701 "generated/parser.bison.cpp"
    break;

  case 42: /* logic: expr INF expr  */
#line 305 "language/parser.y"
                            { add_instruction(INF); }
#line 1707 "generated/parser.bison.cpp"
    break;

  case 43: /* logic: expr SUP_STRICT expr  */
#line 306 "language/parser.y"
                            { add_instruction(SUP_STRICT); }
#line 1713 "generated/parser.bison.cpp"
    break;

  case 44: /* logic: expr INF_STRICT expr  */
#line 307 "language/parser.y"
                            { add_instruction(INF_STRICT); }
#line 1719 "generated/parser.bison.cpp"
    break;

  case 45: /* logic: expr EQUAL expr  */
#line 308 "language/parser.y"
                            { add_instruction(EQUAL); }
#line 1725 "generated/parser.bison.cpp"
    break;

  case 46: /* logic: expr NOT_EQ expr  */
#line 309 "language/parser.y"
                            { add_instruction(NOT_EQ); }
#line 1731 "generated/parser.bison.cpp"
    break;

  case 47: /* logic: expr AND expr  */
#line 310 "language/parser.y"
                            { add_instruction(AND); }
#line 1737 "generated/parser.bison.cpp"
    break;

  case 48: /* logic: expr OR expr  */
#line 311 "language/parser.y"
                            { add_instruction(OR); }
#line 1743 "generated/parser.bison.cpp"
    break;

  case 49: /* logic: NOT logic  */
#line 312 "language/parser.y"
                            { add_instruction(NOT); }
#line 1749 "generated/parser.bison.cpp"
    break;

  case 50: /* expr: NUM  */
#line 315 "language/parser.y"
                            { add_instruction(NUM, (yyvsp[0].DOUBLE)); }
#line 1755 "generated/parser.bison.cpp"
    break;

  case 51: /* expr: SIN '(' expr ')'  */
#line 316 "language/parser.y"
                            { add_instruction(SIN); }
#line 1761 "generated/parser.bison.cpp"
    break;

  case 52: /* expr: COS '(' expr ')'  */
#line 317 "language/parser.y"
                            { add_instruction(COS); }
#line 1767 "generated/parser.bison.cpp"
    break;

  case 53: /* expr: TAN '(' expr ')'  */
#line 318 "language/parser.y"
                            { add_instruction(TAN); }
#line 1773 "generated/parser.bison.cpp"
    break;

  case 54: /* expr: ARCCOS '(' expr ')'  */
#line 319 "language/parser.y"
                            { add_instruction(ARCCOS); }
#line 1779 "generated/parser.bison.cpp"
    break;

  case 55: /* expr: ARCSIN '(' expr ')'  */
#line 320 "language/parser.y"
                            { add_instruction(ARCSIN); }
#line 1785 "generated/parser.bison.cpp"
    break;

  case 56: /* expr: ARCTAN '(' expr ')'  */
#line 321 "language/parser.y"
                            { add_instruction(ARCTAN); }
#line 1791 "generated/parser.bison.cpp"
    break;

  case 57: /* expr: SINH '(' expr ')'  */
#line 322 "language/parser.y"
                            { add_instruction(SINH); }
#line 1797 "generated/parser.bison.cpp"
    break;

  case 58: /* expr: COSH '(' expr ')'  */
#line 323 "language/parser.y"
                            { add_instruction(COSH); }
#line 1803 "generated/parser.bison.cpp"
    break;

  case 59: /* expr: TANH '(' expr ')'  */
#line 324 "language/parser.y"
                            { add_instruction(TANH); }
#line 1809 "generated/parser.bison.cpp"
    break;

  case 60: /* expr: ARCCOSH '(' expr ')'  */
#line 325 "language/parser.y"
                            { add_instruction(ARCCOSH); }
#line 1815 "generated/parser.bison.cpp"
    break;

  case 61: /* expr: ARCSINH '(' expr ')'  */
#line 326 "language/parser.y"
                            { add_instruction(ARCSINH); }
#line 1821 "generated/parser.bison.cpp"
    break;

  case 62: /* expr: ARCTANH '(' expr ')'  */
#line 327 "language/parser.y"
                            { add_instruction(ARCTANH); }
#line 1827 "generated/parser.bison.cpp"
    break;

  case 63: /* expr: '(' expr ')'  */
#line 328 "language/parser.y"
                            { (yyval.DOUBLE) = (yyvsp[-1].DOUBLE); }
#line 1833 "generated/parser.bison.cpp"
    break;

  case 64: /* expr: expr PLUS expr  */
#line 329 "language/parser.y"
                            { add_instruction(PLUS); }
#line 1839 "generated/parser.bison.cpp"
    break;

  case 65: /* expr: expr MIN expr  */
#line 330 "language/parser.y"
                            { add_instruction(MIN); }
#line 1845 "generated/parser.bison.cpp"
    break;

  case 66: /* expr: expr TIMES expr  */
#line 331 "language/parser.y"
                            { add_instruction(TIMES); }
#line 1851 "generated/parser.bison.cpp"
    break;

  case 67: /* expr: expr DIV expr  */
#line 332 "language/parser.y"
                            { add_instruction(DIV); }
#line 1857 "generated/parser.bison.cpp"
    break;

  case 68: /* expr: expr '&' expr  */
#line 333 "language/parser.y"
                            {
        int tmp1 = (int)(yyvsp[-2].DOUBLE);
        int tmp2 = (int)(yyvsp[0].DOUBLE);
        (yyval.DOUBLE) = tmp1 & tmp2;
        printf("%d & %d = %d\n", tmp1, tmp2, (int)(yyval.DOUBLE));
}
#line 1868 "generated/parser.bison.cpp"
    break;

  case 69: /* expr: expr '|' expr  */
#line 339 "language/parser.y"
                            {
        int tmp1 = (int)(yyvsp[-2].DOUBLE);
        int tmp2 = (int)(yyvsp[0].DOUBLE);
        (yyval.DOUBLE) = tmp1 | tmp2;
        printf("%d | %d = %d\n", tmp1, tmp2, (int)(yyval.DOUBLE));
}
#line 1879 "generated/parser.bison.cpp"
    break;

  case 70: /* expr: expr '^' expr  */
#line 345 "language/parser.y"
                                    { add_instruction(POW); }
#line 1885 "generated/parser.bison.cpp"
    break;

  case 71: /* expr: POW '(' expr ',' expr ')'  */
#line 346 "language/parser.y"
                                    { add_instruction(POW); }
#line 1891 "generated/parser.bison.cpp"
    break;

  case 72: /* expr: EXP '(' expr ')'  */
#line 347 "language/parser.y"
                                    { add_instruction(EXP); }
#line 1897 "generated/parser.bison.cpp"
    break;

  case 73: /* expr: LOG '(' expr ')'  */
#line 348 "language/parser.y"
                                    { add_instruction(LOG); }
#line 1903 "generated/parser.bison.cpp"
    break;

  case 74: /* expr: SQRT '(' expr ')'  */
#line 349 "language/parser.y"
                                    { add_instruction(SQRT); }
#line 1909 "generated/parser.bison.cpp"
    break;

  case 75: /* expr: VAR  */
#line 350 "language/parser.y"
                                    { add_instruction(VAR, 0, (yyvsp[0].STRING)); }
#line 1915 "generated/parser.bison.cpp"
    break;

  case 76: /* expr: VAR '=' expr  */
#line 351 "language/parser.y"
                                    { add_instruction(ASSIGN,0,(yyvsp[-2].STRING)); }
#line 1921 "generated/parser.bison.cpp"
    break;

  case 77: /* expr: VAR PLUS_EQUAL expr  */
#line 352 "language/parser.y"
                                    { add_instruction(VAR,0,(yyvsp[-2].STRING)); add_instruction(PLUS); add_instruction(ASSIGN,0,(yyvsp[-2].STRING)); }
#line 1927 "generated/parser.bison.cpp"
    break;

  case 78: /* expr: VAR MIN_EQUAL expr  */
#line 353 "language/parser.y"
                                    { add_instruction(VAR,0,(yyvsp[-2].STRING)); add_instruction(MIN); add_instruction(ASSIGN,0,(yyvsp[-2].STRING)); }
#line 1933 "generated/parser.bison.cpp"
    break;

  case 79: /* expr: VAR TIMES_EQUAL expr  */
#line 354 "language/parser.y"
                                    { add_instruction(VAR,0,(yyvsp[-2].STRING)); add_instruction(TIMES); add_instruction(ASSIGN,0,(yyvsp[-2].STRING)); }
#line 1939 "generated/parser.bison.cpp"
    break;

  case 80: /* expr: VAR DIV_EQUAL expr  */
#line 355 "language/parser.y"
                                    { add_instruction(VAR,0,(yyvsp[-2].STRING)); add_instruction(DIV); add_instruction(ASSIGN,0,(yyvsp[-2].STRING)); }
#line 1945 "generated/parser.bison.cpp"
    break;


#line 1949 "generated/parser.bison.cpp"

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

#line 357 "language/parser.y"


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
    for (size_t i = 0; i < code_genere.size(); i++){
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

    return EXIT_SUCCESS;
}

