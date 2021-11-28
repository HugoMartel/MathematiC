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
    #include <cmath>
    #include <string>
    #include <map>
    #include <stack>
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
        int add_instruction(const int &c, const double &v=0, const std::string &n="") {
            code.push_back(instruction(c,v,n));
            ic++;
            return 0;
        }
        /**
         * Define a parameter used in a function declaration
         * @param[in]   s   Name of the parameter
         * @param[in]   c   Code of the DECLARE instruction (since it is not known by cpp)
         * @return      Error Code
         */
        int add_param(const std::string &s, const int &c) {
            if (!parameters.count(s)) {
                    parameters[s] = 0;
                    /* c is the code number for DECLARE */
                    add_instruction(c, 0, s);
                    return EXIT_SUCCESS;
            } else {
                yyerror("Parameter already declared...");
                return -1;
            }
        }
    };

    // Structure pour accueillir le code généré
    // (sone de code ou code machine ou assembleur)
    vector <instruction> code_genere;

    /**
     * String storing the current code (main or function) to write to.
     * 0 -> main code, otherwise write to the associated function
     */
    std::stack<std::string> current_code;

    // Déclaration de la map qui associe
    // les noms des variables à leur valeur
    // (La table de symboles)
    std::map<std::string,double> variables;

    //  Map storing functions instructions, access them by their name (string)
    std::map<std::string, function *> functions;

    /* Map storing functions to draw */
    std::map</*name*/std::string, std::pair</*xbegin*/double, /*xend*/double>> funcsToDraw;

    /* Main Code Instruction Counter */
    int ic = 0;

    // Remarquez les paramètres par défaut pour faciliter les appels depuis la grammaire
    int add_instruction(const int &c, const double &v=0, const string &n="") {
        code_genere.push_back(instruction(c,v,n));
        ic++;
        return 0;
    }

#line 193 "generated/parser.bison.cpp"

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
  YYSYMBOL_IF = 28,                        /* IF  */
  YYSYMBOL_ELSE = 29,                      /* ELSE  */
  YYSYMBOL_WHILE = 30,                     /* WHILE  */
  YYSYMBOL_TAN = 31,                       /* TAN  */
  YYSYMBOL_ARCCOS = 32,                    /* ARCCOS  */
  YYSYMBOL_ARCSIN = 33,                    /* ARCSIN  */
  YYSYMBOL_ARCTAN = 34,                    /* ARCTAN  */
  YYSYMBOL_COSH = 35,                      /* COSH  */
  YYSYMBOL_SINH = 36,                      /* SINH  */
  YYSYMBOL_TANH = 37,                      /* TANH  */
  YYSYMBOL_ARCSINH = 38,                   /* ARCSINH  */
  YYSYMBOL_ARCCOSH = 39,                   /* ARCCOSH  */
  YYSYMBOL_ARCTANH = 40,                   /* ARCTANH  */
  YYSYMBOL_SQRT = 41,                      /* SQRT  */
  YYSYMBOL_LOG = 42,                       /* LOG  */
  YYSYMBOL_DRAW = 43,                      /* DRAW  */
  YYSYMBOL_JMP = 44,                       /* JMP  */
  YYSYMBOL_JMPCOND = 45,                   /* JMPCOND  */
  YYSYMBOL_ASSIGN = 46,                    /* ASSIGN  */
  YYSYMBOL_DECLARE = 47,                   /* DECLARE  */
  YYSYMBOL_LOAD = 48,                      /* LOAD  */
  YYSYMBOL_PLUS = 49,                      /* PLUS  */
  YYSYMBOL_MIN = 50,                       /* MIN  */
  YYSYMBOL_TIMES = 51,                     /* TIMES  */
  YYSYMBOL_DIV = 52,                       /* DIV  */
  YYSYMBOL_PLUS_EQUAL = 53,                /* PLUS_EQUAL  */
  YYSYMBOL_MIN_EQUAL = 54,                 /* MIN_EQUAL  */
  YYSYMBOL_TIMES_EQUAL = 55,               /* TIMES_EQUAL  */
  YYSYMBOL_DIV_EQUAL = 56,                 /* DIV_EQUAL  */
  YYSYMBOL_EQUAL = 57,                     /* EQUAL  */
  YYSYMBOL_NOT_EQ = 58,                    /* NOT_EQ  */
  YYSYMBOL_INF_STRICT = 59,                /* INF_STRICT  */
  YYSYMBOL_SUP_STRICT = 60,                /* SUP_STRICT  */
  YYSYMBOL_INF = 61,                       /* INF  */
  YYSYMBOL_SUP = 62,                       /* SUP  */
  YYSYMBOL_AND = 63,                       /* AND  */
  YYSYMBOL_OR = 64,                        /* OR  */
  YYSYMBOL_NOT = 65,                       /* NOT  */
  YYSYMBOL_66_ = 66,                       /* '|'  */
  YYSYMBOL_67_ = 67,                       /* '&'  */
  YYSYMBOL_68_ = 68,                       /* '^'  */
  YYSYMBOL_69_ = 69,                       /* '='  */
  YYSYMBOL_70_ = 70,                       /* ';'  */
  YYSYMBOL_71_ = 71,                       /* ':'  */
  YYSYMBOL_72_ = 72,                       /* '('  */
  YYSYMBOL_73_ = 73,                       /* ')'  */
  YYSYMBOL_74_ = 74,                       /* '{'  */
  YYSYMBOL_75_ = 75,                       /* '}'  */
  YYSYMBOL_76_ = 76,                       /* ','  */
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
  YYSYMBOL_87_2 = 87,                      /* $@2  */
  YYSYMBOL_draw_args = 88,                 /* draw_args  */
  YYSYMBOL_style_args = 89,                /* style_args  */
  YYSYMBOL_color_args = 90,                /* color_args  */
  YYSYMBOL_instruction = 91,               /* instruction  */
  YYSYMBOL_92_3 = 92,                      /* $@3  */
  YYSYMBOL_93_4 = 93,                      /* $@4  */
  YYSYMBOL_logic = 94,                     /* logic  */
  YYSYMBOL_expr = 95                       /* expr  */
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
#define YYLAST   570

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  79
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  231

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   320


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
       2,     2,     2,     2,     2,     2,     2,     2,    67,     2,
      72,    73,     2,     2,    76,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    71,    70,
       2,    69,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    77,     2,    78,    68,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    74,    66,    75,     2,     2,     2,     2,
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
      65
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   232,   232,   235,   238,   247,   256,   256,   270,   272,
     286,   289,   302,   303,   306,   306,   309,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   326,
     327,   330,   331,   334,   335,   336,   340,   348,   340,   364,
     367,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   410,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426
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
  "SIN", "COS", "POW", "EXP", "VAR", "FOR", "IF", "ELSE", "WHILE", "TAN",
  "ARCCOS", "ARCSIN", "ARCTAN", "COSH", "SINH", "TANH", "ARCSINH",
  "ARCCOSH", "ARCTANH", "SQRT", "LOG", "DRAW", "JMP", "JMPCOND", "ASSIGN",
  "DECLARE", "LOAD", "PLUS", "MIN", "TIMES", "DIV", "PLUS_EQUAL",
  "MIN_EQUAL", "TIMES_EQUAL", "DIV_EQUAL", "EQUAL", "NOT_EQ", "INF_STRICT",
  "SUP_STRICT", "INF", "SUP", "AND", "OR", "NOT", "'|'", "'&'", "'^'",
  "'='", "';'", "':'", "'('", "')'", "'{'", "'}'", "','", "'['", "']'",
  "$accept", "code", "declarations", "fonctions", "$@1", "parameters",
  "draw_func", "affichage", "$@2", "draw_args", "style_args", "color_args",
  "instruction", "$@3", "$@4", "logic", "expr", YY_NULLPTR
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
     315,   316,   317,   318,   319,   320,   124,    38,    94,    61,
      59,    58,    40,    41,   123,   125,    44,    91,    93
};
#endif

#define YYPACT_NINF (-158)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -158,     1,    72,  -158,   -10,    86,    11,    66,    54,   103,
     125,  -158,   349,  -158,    74,   136,    41,  -158,  -158,  -158,
    -158,    94,   102,   104,   106,   108,   115,   117,   123,   124,
     126,   128,   129,   130,   131,   132,   134,   135,   349,   273,
     171,   155,  -158,  -158,   103,   349,   349,   349,   349,   349,
     349,   349,   349,   349,   349,   349,   349,   349,   349,   349,
     349,   349,   349,   349,   349,   349,   -43,   349,   349,   349,
     349,   349,   349,   349,  -158,  -158,   -59,   187,    60,   160,
     167,   327,    37,   352,   502,   502,   502,   502,   502,   356,
     360,   364,   389,   393,   397,   401,   426,   430,   434,   438,
     463,  -158,    56,    56,     0,     0,   173,   173,   173,   233,
     171,   169,   172,   175,   176,   177,   178,   179,   180,    93,
    -158,  -158,   349,  -158,  -158,  -158,  -158,  -158,  -158,  -158,
    -158,  -158,  -158,  -158,  -158,  -158,   188,   205,   231,   186,
     208,   266,    44,    88,   107,   144,  -158,    60,   467,  -158,
     209,   235,   269,  -158,  -158,  -158,  -158,  -158,  -158,  -158,
    -158,  -158,   213,  -158,   145,  -158,  -158,    40,  -158,    67,
     264,   279,   279,    59,   235,  -158,   269,  -158,   246,   279,
     217,   498,   218,   349,  -158,   471,   221,   222,   216,  -158,
    -158,   349,   349,   349,   349,   349,   349,   349,   349,   145,
     476,  -158,   349,   145,   502,   502,   502,   502,   502,   502,
     502,   502,   116,  -158,   -39,   324,  -158,   349,   232,   228,
     297,   349,   256,   -47,   145,   257,   189,   145,  -158,   234,
    -158
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     1,     0,     0,     0,     0,     0,     0,
       8,     2,     0,     5,     0,    12,     0,    51,    52,    53,
      50,     0,     0,     0,     0,    78,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    16,    14,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     4,     9,     0,     0,     0,    13,
       0,     0,     0,     0,    80,    81,    82,    83,    79,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    66,    67,    68,    69,    70,    72,    71,    73,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      54,    55,     0,    75,    56,    57,    58,    59,    61,    60,
      62,    64,    63,    65,    77,    76,     0,    10,     0,     0,
       0,     0,     0,     0,     0,     0,    15,     0,     0,     6,
       0,     0,     0,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    74,    33,    11,    31,     0,    29,     0,
       0,     0,     0,     0,     0,    17,     0,    18,     0,     0,
       0,     0,     0,     0,     7,     0,    32,    30,     0,    49,
      36,     0,     0,     0,     0,     0,     0,     0,     0,    33,
       0,    34,     0,    33,    45,    46,    44,    43,    42,    41,
      47,    48,     0,    35,     0,    37,    40,     0,     0,     0,
       0,     0,     0,     0,    33,     0,     0,    33,    38,     0,
      39
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -158,  -158,  -158,   306,  -158,   223,   288,  -158,  -158,   190,
     159,   162,   -97,  -158,  -158,  -157,   -12
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    10,   164,    76,    16,    11,    78,   119,
     169,   167,   173,   203,   218,   180,   185
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      39,     3,    67,    68,    69,    70,    67,    68,    69,    70,
      67,    68,    69,    70,   109,   182,     7,   110,     5,    71,
      72,    73,   189,    71,    72,    73,    66,    71,    72,    73,
     101,   225,   217,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,     9,   102,   103,   104,   105,   106,
     107,   108,    17,    18,    19,   154,    71,    72,    73,   183,
     155,   112,   113,   114,   115,   116,   117,   118,     4,     5,
      20,    21,    22,    23,    24,    25,    67,    68,    69,    70,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,   212,    71,    72,    73,   215,    69,    70,   156,
     148,    42,     8,   122,   157,    43,   174,    44,   175,    17,
      18,    19,    71,    72,    73,    14,   183,   226,   158,    15,
     229,    38,     5,   159,   184,    12,    13,    20,    21,    22,
      23,    24,    25,   176,    41,   177,    40,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,   181,
     181,    49,    50,    51,    52,   160,    45,   181,   146,   147,
     161,   200,   170,   171,    46,   172,    47,    53,    48,   204,
     205,   206,   207,   208,   209,   210,   211,    54,    38,    55,
     214,   216,    17,    18,    19,    56,    57,    75,    58,   183,
      59,    60,    61,    62,    63,   219,    64,    65,   111,   223,
      20,    21,    22,    23,    24,    25,    67,    68,    69,    70,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    77,    71,    72,    73,    44,    17,    18,    19,
     120,    73,   136,   139,   183,   138,   140,   141,   142,   143,
     144,   145,   150,   166,   188,    20,    21,    22,    23,    24,
      25,    38,   149,   151,   228,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    67,    68,    69,
      70,   110,    17,    18,    19,   152,   153,   165,   168,   147,
     178,   190,   199,   202,    71,    72,    73,   174,   176,   221,
      20,    21,    22,    23,    24,    25,    38,   220,     6,   230,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    67,    68,    69,    70,   222,    17,    18,    19,
     224,   227,    79,   137,   183,   187,   186,   162,     0,    71,
      72,    73,     0,    74,   179,    20,    21,    22,    23,    24,
      25,    38,    17,    18,    19,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,     0,     0,     0,
      20,    21,    22,    23,    24,    25,    67,    68,    69,    70,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,     0,    71,    72,    73,    38,     0,     0,     0,
     121,    67,    68,    69,    70,    67,    68,    69,    70,    67,
      68,    69,    70,    67,    68,    69,    70,     0,    71,    72,
      73,    38,    71,    72,    73,   123,    71,    72,    73,   124,
      71,    72,    73,   125,     0,     0,     0,   126,    67,    68,
      69,    70,    67,    68,    69,    70,    67,    68,    69,    70,
      67,    68,    69,    70,     0,    71,    72,    73,     0,    71,
      72,    73,   127,    71,    72,    73,   128,    71,    72,    73,
     129,     0,     0,     0,   130,    67,    68,    69,    70,    67,
      68,    69,    70,    67,    68,    69,    70,    67,    68,    69,
      70,     0,    71,    72,    73,     0,    71,    72,    73,   131,
      71,    72,    73,   132,    71,    72,    73,   133,     0,     0,
       0,   134,    67,    68,    69,    70,    67,    68,    69,    70,
      67,    68,    69,    70,     0,    67,    68,    69,    70,    71,
      72,    73,     0,    71,    72,    73,   135,    71,    72,    73,
     163,   201,    71,    72,    73,     0,   213,    67,    68,    69,
      70,    67,    68,    69,    70,   191,   192,   193,   194,   195,
     196,   197,   198,     0,    71,    72,    73,     0,    71,    72,
      73
};

static const yytype_int16 yycheck[] =
{
      12,     0,    49,    50,    51,    52,    49,    50,    51,    52,
      49,    50,    51,    52,    73,   172,    26,    76,     7,    66,
      67,    68,   179,    66,    67,    68,    38,    66,    67,    68,
      73,    78,    71,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    43,    67,    68,    69,    70,    71,
      72,    73,     3,     4,     5,    21,    66,    67,    68,    10,
      26,    11,    12,    13,    14,    15,    16,    17,     6,     7,
      21,    22,    23,    24,    25,    26,    49,    50,    51,    52,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,   199,    66,    67,    68,   203,    51,    52,    21,
     122,    70,    26,    76,    26,    74,    76,    76,    78,     3,
       4,     5,    66,    67,    68,    71,    10,   224,    21,    26,
     227,    72,     7,    26,    75,    69,    70,    21,    22,    23,
      24,    25,    26,    76,     8,    78,    72,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,   171,
     172,    53,    54,    55,    56,    21,    72,   179,    75,    76,
      26,   183,    27,    28,    72,    30,    72,    69,    72,   191,
     192,   193,   194,   195,   196,   197,   198,    72,    72,    72,
     202,    75,     3,     4,     5,    72,    72,    26,    72,    10,
      72,    72,    72,    72,    72,   217,    72,    72,    21,   221,
      21,    22,    23,    24,    25,    26,    49,    50,    51,    52,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    77,    66,    67,    68,    76,     3,     4,     5,
      73,    68,     9,    71,    10,    76,    71,    71,    71,    71,
      71,    71,    21,    18,     8,    21,    22,    23,    24,    25,
      26,    72,    74,    77,    75,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    49,    50,    51,
      52,    76,     3,     4,     5,    77,    20,    78,    19,    76,
      26,    74,    74,    77,    66,    67,    68,    76,    76,    71,
      21,    22,    23,    24,    25,    26,    72,    75,     2,    75,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    49,    50,    51,    52,    29,     3,     4,     5,
      74,    74,    44,   110,    10,   176,   174,   147,    -1,    66,
      67,    68,    -1,    70,    65,    21,    22,    23,    24,    25,
      26,    72,     3,     4,     5,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    -1,    -1,    -1,
      21,    22,    23,    24,    25,    26,    49,    50,    51,    52,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    -1,    66,    67,    68,    72,    -1,    -1,    -1,
      73,    49,    50,    51,    52,    49,    50,    51,    52,    49,
      50,    51,    52,    49,    50,    51,    52,    -1,    66,    67,
      68,    72,    66,    67,    68,    73,    66,    67,    68,    73,
      66,    67,    68,    73,    -1,    -1,    -1,    73,    49,    50,
      51,    52,    49,    50,    51,    52,    49,    50,    51,    52,
      49,    50,    51,    52,    -1,    66,    67,    68,    -1,    66,
      67,    68,    73,    66,    67,    68,    73,    66,    67,    68,
      73,    -1,    -1,    -1,    73,    49,    50,    51,    52,    49,
      50,    51,    52,    49,    50,    51,    52,    49,    50,    51,
      52,    -1,    66,    67,    68,    -1,    66,    67,    68,    73,
      66,    67,    68,    73,    66,    67,    68,    73,    -1,    -1,
      -1,    73,    49,    50,    51,    52,    49,    50,    51,    52,
      49,    50,    51,    52,    -1,    49,    50,    51,    52,    66,
      67,    68,    -1,    66,    67,    68,    73,    66,    67,    68,
      73,    70,    66,    67,    68,    -1,    70,    49,    50,    51,
      52,    49,    50,    51,    52,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    66,    67,    68,    -1,    66,    67,
      68
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    80,    81,     0,     6,     7,    82,    26,    26,    43,
      82,    86,    69,    70,    71,    26,    85,     3,     4,     5,
      21,    22,    23,    24,    25,    26,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    72,    95,
      72,     8,    70,    74,    76,    72,    72,    72,    72,    53,
      54,    55,    56,    69,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    95,    49,    50,    51,
      52,    66,    67,    68,    70,    26,    84,    77,    87,    85,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    73,    95,    95,    95,    95,    95,    95,    95,    73,
      76,    21,    11,    12,    13,    14,    15,    16,    17,    88,
      73,    73,    76,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,     9,    84,    76,    71,
      71,    71,    71,    71,    71,    71,    75,    76,    95,    74,
      21,    77,    77,    20,    21,    26,    21,    26,    21,    26,
      21,    26,    88,    73,    83,    78,    18,    90,    19,    89,
      27,    28,    30,    91,    76,    78,    76,    78,    26,    65,
      94,    95,    94,    10,    75,    95,    90,    89,     8,    94,
      74,    57,    58,    59,    60,    61,    62,    63,    64,    74,
      95,    70,    77,    92,    95,    95,    95,    95,    95,    95,
      95,    95,    91,    70,    95,    91,    75,    71,    93,    95,
      75,    71,    29,    95,    74,    78,    91,    74,    75,    91,
      75
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    79,    80,    81,    81,    81,    83,    82,    82,    84,
      84,    85,    85,    85,    87,    86,    86,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    89,
      89,    90,    90,    91,    91,    91,    92,    93,    91,    91,
      91,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     0,     6,     4,     0,    11,     2,     1,
       3,     7,     1,     3,     0,     6,     3,     5,     5,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       3,     1,     3,     0,     3,     4,     0,     0,    11,    13,
       5,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       1,     1,     1,     1,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     3,     3,     3,     3,
       3,     3,     3,     3,     6,     4,     4,     4,     1,     3,
       3,     3,     3,     3
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
#line 232 "language/parser.y"
                                                        { /* TODO: print start compiling */ }
#line 1502 "generated/parser.bison.cpp"
    break;

  case 3: /* declarations: %empty  */
#line 235 "language/parser.y"
                                                    { /* End of declarations */
                    std::cout << "-- End of declarations --\n";
 }
#line 1510 "generated/parser.bison.cpp"
    break;

  case 4: /* declarations: declarations var VAR '=' expr ';'  */
#line 238 "language/parser.y"
                                                    { /* Init Vars */
                if (!variables.count((yyvsp[-3].STRING))) {
                    variables[(yyvsp[-3].STRING)] = (yyvsp[-1].DOUBLE);
                    add_instruction(DECLARE, 0, (yyvsp[-3].STRING));
                    add_instruction(ASSIGN, 0, (yyvsp[-3].STRING));
                } else {
                    yyerror("Variable already declared...");
                }
}
#line 1524 "generated/parser.bison.cpp"
    break;

  case 5: /* declarations: declarations var VAR ';'  */
#line 247 "language/parser.y"
                                                    {
                if (!variables.count((yyvsp[-1].STRING))) {
                    variables[(yyvsp[-1].STRING)] = 0;
                    add_instruction(DECLARE, 0, (yyvsp[-1].STRING));
                    add_instruction(ASSIGN, 0, (yyvsp[-1].STRING));
                }
            }
#line 1536 "generated/parser.bison.cpp"
    break;

  case 6: /* $@1: %empty  */
#line 256 "language/parser.y"
                                                              {
                    if(!functions.count((yyvsp[-6].STRING))) {
                        functions[(yyvsp[-6].STRING)] = new function();
                        current_code.push((yyvsp[-6].STRING));
                        add_instruction(DEF, 0, (yyvsp[-6].STRING));
                    } else {
                        yyerror("Function already declared...");
                    }
                    
}
#line 1551 "generated/parser.bison.cpp"
    break;

  case 7: /* fonctions: DEF VAR ':' '(' parameters ')' arrow '{' $@1 instruction '}'  */
#line 267 "language/parser.y"
                                                            {
                    current_code.pop();
}
#line 1559 "generated/parser.bison.cpp"
    break;

  case 8: /* fonctions: fonctions fonctions  */
#line 270 "language/parser.y"
                                                            { /* Support multiple functions */ }
#line 1565 "generated/parser.bison.cpp"
    break;

  case 9: /* parameters: VAR  */
#line 272 "language/parser.y"
                                                        {
                    add_instruction(DECLARE, 0, (yyvsp[0].STRING));
                    /*
                    if (function.count(current_code.top())) {
                        if (!functions[current_code.top()].parameters.count($1)) {
                            functions[current_code.top()].parameters[$1] = 0;
                        } else {
                            yyerror("Parameter already declared...");
                        }
                    } else {
                        yyerror("Function not registered...");
                    }
                    */
}
#line 1584 "generated/parser.bison.cpp"
    break;

  case 10: /* parameters: parameters ',' parameters  */
#line 286 "language/parser.y"
                                                        { /* Support multiple parameters */ }
#line 1590 "generated/parser.bison.cpp"
    break;

  case 11: /* draw_func: VAR in '[' NUM ',' NUM ']'  */
#line 289 "language/parser.y"
                                                        {
                    /* Load function names to send to the front-end */
                    add_instruction(LOAD, 0, (yyvsp[-6].STRING));
                    /* Check if the function is already drawn */
                    if (!functions.count((yyvsp[-6].STRING))){
                        funcsToDraw[(yyvsp[-6].STRING)] = std::pair<double,double>((yyvsp[-3].DOUBLE),(yyvsp[-1].DOUBLE));

                    } else {
                        yyerror("Function already drawn...");
                    }
                    

}
#line 1608 "generated/parser.bison.cpp"
    break;

  case 12: /* draw_func: VAR  */
#line 302 "language/parser.y"
                                                        { /* TODO */ }
#line 1614 "generated/parser.bison.cpp"
    break;

  case 13: /* draw_func: draw_func ',' draw_func  */
#line 303 "language/parser.y"
                                                        { /* Support multiple ??? */ }
#line 1620 "generated/parser.bison.cpp"
    break;

  case 14: /* $@2: %empty  */
#line 306 "language/parser.y"
                                { /*TODO: load funcs*/ }
#line 1626 "generated/parser.bison.cpp"
    break;

  case 16: /* affichage: DRAW draw_func ';'  */
#line 309 "language/parser.y"
                                { /* TODO: load default args */}
#line 1632 "generated/parser.bison.cpp"
    break;

  case 17: /* draw_args: color ':' '[' color_args ']'  */
#line 312 "language/parser.y"
                                         { /*TODO: check PARAM values*/ }
#line 1638 "generated/parser.bison.cpp"
    break;

  case 18: /* draw_args: style ':' '[' style_args ']'  */
#line 313 "language/parser.y"
                                         { /*TODO: check PARAM values*/ }
#line 1644 "generated/parser.bison.cpp"
    break;

  case 19: /* draw_args: label ':' STRING  */
#line 314 "language/parser.y"
                                         { /*TODO: check PARAM values*/ }
#line 1650 "generated/parser.bison.cpp"
    break;

  case 20: /* draw_args: xmin ':' NUM  */
#line 315 "language/parser.y"
                                         { /*TODO*/ }
#line 1656 "generated/parser.bison.cpp"
    break;

  case 21: /* draw_args: xmin ':' VAR  */
#line 316 "language/parser.y"
                                         { /*TODO*/ }
#line 1662 "generated/parser.bison.cpp"
    break;

  case 22: /* draw_args: xmax ':' NUM  */
#line 317 "language/parser.y"
                                         { /*TODO*/ }
#line 1668 "generated/parser.bison.cpp"
    break;

  case 23: /* draw_args: xmax ':' VAR  */
#line 318 "language/parser.y"
                                         { /*TODO*/ }
#line 1674 "generated/parser.bison.cpp"
    break;

  case 24: /* draw_args: ymin ':' NUM  */
#line 319 "language/parser.y"
                                         { /*TODO*/ }
#line 1680 "generated/parser.bison.cpp"
    break;

  case 25: /* draw_args: ymin ':' VAR  */
#line 320 "language/parser.y"
                                         { /*TODO*/ }
#line 1686 "generated/parser.bison.cpp"
    break;

  case 26: /* draw_args: ymax ':' NUM  */
#line 321 "language/parser.y"
                                         { /*TODO*/ }
#line 1692 "generated/parser.bison.cpp"
    break;

  case 27: /* draw_args: ymax ':' VAR  */
#line 322 "language/parser.y"
                                         { /*TODO*/ }
#line 1698 "generated/parser.bison.cpp"
    break;

  case 28: /* draw_args: draw_args ',' draw_args  */
#line 323 "language/parser.y"
                                         { /*TODO*/ }
#line 1704 "generated/parser.bison.cpp"
    break;

  case 29: /* style_args: STYLE_PARAM  */
#line 326 "language/parser.y"
                                         { /*TODO*/ }
#line 1710 "generated/parser.bison.cpp"
    break;

  case 30: /* style_args: style_args ',' style_args  */
#line 327 "language/parser.y"
                                         { /*TODO*/ }
#line 1716 "generated/parser.bison.cpp"
    break;

  case 31: /* color_args: COLOR_PARAM  */
#line 330 "language/parser.y"
                                         { /*TODO*/ }
#line 1722 "generated/parser.bison.cpp"
    break;

  case 32: /* color_args: color_args ',' color_args  */
#line 331 "language/parser.y"
                                         { /*TODO*/ }
#line 1728 "generated/parser.bison.cpp"
    break;

  case 33: /* instruction: %empty  */
#line 334 "language/parser.y"
                                         { /* No instructions left */ }
#line 1734 "generated/parser.bison.cpp"
    break;

  case 34: /* instruction: instruction expr ';'  */
#line 335 "language/parser.y"
                                         { /* new line */ }
#line 1740 "generated/parser.bison.cpp"
    break;

  case 35: /* instruction: instruction RETURN expr ';'  */
#line 336 "language/parser.y"
                                         {
               /* The return instruction will jump to the main instruction (out of function) */
               add_instruction(JMP, -1);
            }
#line 1749 "generated/parser.bison.cpp"
    break;

  case 36: /* $@3: %empty  */
#line 340 "language/parser.y"
                                         {

                // Je sauvegarde l'endroit actuel pour revenir mofifier l'adresse
                // lorsqu'elle sera connue (celle du JC)

                (yyvsp[-2].ADDRESS).jc = ic;
                add_instruction(JMPCOND);
}
#line 1762 "generated/parser.bison.cpp"
    break;

  case 37: /* $@4: %empty  */
#line 348 "language/parser.y"
                                        {
                // Je sauvegarde l'endroit actuel pour revenir mofifier l'adresse
                // lorsqu'elle sera connue (celle du JMP)

                (yyvsp[-4].ADDRESS).jmp = ic;
                add_instruction(JMP);

                // Je mets à jour l'adresse du saut conditionnel
                code_genere[(yyvsp[-4].ADDRESS).jc].value = ic;
}
#line 1777 "generated/parser.bison.cpp"
    break;

  case 38: /* instruction: IF logic '{' $@3 instruction $@4 '}' ELSE '{' instruction '}'  */
#line 360 "language/parser.y"
                                        {
                // Je mets à jour l'adresse du saut inconditionnel
                 code_genere[(yyvsp[-10].ADDRESS).jmp].value = ic;
}
#line 1786 "generated/parser.bison.cpp"
    break;

  case 39: /* instruction: FOR VAR in '[' expr ':' expr ':' expr ']' '{' instruction '}'  */
#line 366 "language/parser.y"
                                        { add_instruction(FOR); }
#line 1792 "generated/parser.bison.cpp"
    break;

  case 40: /* instruction: WHILE logic '{' instruction '}'  */
#line 369 "language/parser.y"
                                        { add_instruction(WHILE); }
#line 1798 "generated/parser.bison.cpp"
    break;

  case 41: /* logic: expr SUP expr  */
#line 372 "language/parser.y"
                            { add_instruction(SUP); }
#line 1804 "generated/parser.bison.cpp"
    break;

  case 42: /* logic: expr INF expr  */
#line 373 "language/parser.y"
                            { add_instruction(INF); }
#line 1810 "generated/parser.bison.cpp"
    break;

  case 43: /* logic: expr SUP_STRICT expr  */
#line 374 "language/parser.y"
                            { add_instruction(SUP_STRICT); }
#line 1816 "generated/parser.bison.cpp"
    break;

  case 44: /* logic: expr INF_STRICT expr  */
#line 375 "language/parser.y"
                            { add_instruction(INF_STRICT); }
#line 1822 "generated/parser.bison.cpp"
    break;

  case 45: /* logic: expr EQUAL expr  */
#line 376 "language/parser.y"
                            { add_instruction(EQUAL); }
#line 1828 "generated/parser.bison.cpp"
    break;

  case 46: /* logic: expr NOT_EQ expr  */
#line 377 "language/parser.y"
                            { add_instruction(NOT_EQ); }
#line 1834 "generated/parser.bison.cpp"
    break;

  case 47: /* logic: expr AND expr  */
#line 378 "language/parser.y"
                            { add_instruction(AND); }
#line 1840 "generated/parser.bison.cpp"
    break;

  case 48: /* logic: expr OR expr  */
#line 379 "language/parser.y"
                            { add_instruction(OR); }
#line 1846 "generated/parser.bison.cpp"
    break;

  case 49: /* logic: NOT logic  */
#line 380 "language/parser.y"
                            { add_instruction(NOT); }
#line 1852 "generated/parser.bison.cpp"
    break;

  case 50: /* expr: NUM  */
#line 383 "language/parser.y"
                            { add_instruction(NUM, (yyvsp[0].DOUBLE)); }
#line 1858 "generated/parser.bison.cpp"
    break;

  case 51: /* expr: PI  */
#line 384 "language/parser.y"
                            { add_instruction(NUM, 3.14159265358979323846); }
#line 1864 "generated/parser.bison.cpp"
    break;

  case 52: /* expr: E  */
#line 385 "language/parser.y"
                            { add_instruction(NUM, 2.71828182845904523536); }
#line 1870 "generated/parser.bison.cpp"
    break;

  case 53: /* expr: PHI  */
#line 386 "language/parser.y"
                            { add_instruction(NUM, 1.61803398874989484820); }
#line 1876 "generated/parser.bison.cpp"
    break;

  case 54: /* expr: SIN '(' expr ')'  */
#line 387 "language/parser.y"
                            { add_instruction(SIN); }
#line 1882 "generated/parser.bison.cpp"
    break;

  case 55: /* expr: COS '(' expr ')'  */
#line 388 "language/parser.y"
                            { add_instruction(COS); }
#line 1888 "generated/parser.bison.cpp"
    break;

  case 56: /* expr: TAN '(' expr ')'  */
#line 389 "language/parser.y"
                            { add_instruction(TAN); }
#line 1894 "generated/parser.bison.cpp"
    break;

  case 57: /* expr: ARCCOS '(' expr ')'  */
#line 390 "language/parser.y"
                            { add_instruction(ARCCOS); }
#line 1900 "generated/parser.bison.cpp"
    break;

  case 58: /* expr: ARCSIN '(' expr ')'  */
#line 391 "language/parser.y"
                            { add_instruction(ARCSIN); }
#line 1906 "generated/parser.bison.cpp"
    break;

  case 59: /* expr: ARCTAN '(' expr ')'  */
#line 392 "language/parser.y"
                            { add_instruction(ARCTAN); }
#line 1912 "generated/parser.bison.cpp"
    break;

  case 60: /* expr: SINH '(' expr ')'  */
#line 393 "language/parser.y"
                            { add_instruction(SINH); }
#line 1918 "generated/parser.bison.cpp"
    break;

  case 61: /* expr: COSH '(' expr ')'  */
#line 394 "language/parser.y"
                            { add_instruction(COSH); }
#line 1924 "generated/parser.bison.cpp"
    break;

  case 62: /* expr: TANH '(' expr ')'  */
#line 395 "language/parser.y"
                            { add_instruction(TANH); }
#line 1930 "generated/parser.bison.cpp"
    break;

  case 63: /* expr: ARCCOSH '(' expr ')'  */
#line 396 "language/parser.y"
                            { add_instruction(ARCCOSH); }
#line 1936 "generated/parser.bison.cpp"
    break;

  case 64: /* expr: ARCSINH '(' expr ')'  */
#line 397 "language/parser.y"
                            { add_instruction(ARCSINH); }
#line 1942 "generated/parser.bison.cpp"
    break;

  case 65: /* expr: ARCTANH '(' expr ')'  */
#line 398 "language/parser.y"
                            { add_instruction(ARCTANH); }
#line 1948 "generated/parser.bison.cpp"
    break;

  case 66: /* expr: '(' expr ')'  */
#line 399 "language/parser.y"
                            { (yyval.DOUBLE) = (yyvsp[-1].DOUBLE); }
#line 1954 "generated/parser.bison.cpp"
    break;

  case 67: /* expr: expr PLUS expr  */
#line 400 "language/parser.y"
                            { add_instruction(PLUS); }
#line 1960 "generated/parser.bison.cpp"
    break;

  case 68: /* expr: expr MIN expr  */
#line 401 "language/parser.y"
                            { add_instruction(MIN); }
#line 1966 "generated/parser.bison.cpp"
    break;

  case 69: /* expr: expr TIMES expr  */
#line 402 "language/parser.y"
                            { add_instruction(TIMES); }
#line 1972 "generated/parser.bison.cpp"
    break;

  case 70: /* expr: expr DIV expr  */
#line 403 "language/parser.y"
                            { add_instruction(DIV); }
#line 1978 "generated/parser.bison.cpp"
    break;

  case 71: /* expr: expr '&' expr  */
#line 404 "language/parser.y"
                            {
        int tmp1 = (int)(yyvsp[-2].DOUBLE);
        int tmp2 = (int)(yyvsp[0].DOUBLE);
        (yyval.DOUBLE) = tmp1 & tmp2;
        printf("%d & %d = %d\n", tmp1, tmp2, (int)(yyval.DOUBLE));
}
#line 1989 "generated/parser.bison.cpp"
    break;

  case 72: /* expr: expr '|' expr  */
#line 410 "language/parser.y"
                            {
        int tmp1 = (int)(yyvsp[-2].DOUBLE);
        int tmp2 = (int)(yyvsp[0].DOUBLE);
        (yyval.DOUBLE) = tmp1 | tmp2;
        printf("%d | %d = %d\n", tmp1, tmp2, (int)(yyval.DOUBLE));
}
#line 2000 "generated/parser.bison.cpp"
    break;

  case 73: /* expr: expr '^' expr  */
#line 416 "language/parser.y"
                                    { add_instruction(POW); }
#line 2006 "generated/parser.bison.cpp"
    break;

  case 74: /* expr: POW '(' expr ',' expr ')'  */
#line 417 "language/parser.y"
                                    { add_instruction(POW); }
#line 2012 "generated/parser.bison.cpp"
    break;

  case 75: /* expr: EXP '(' expr ')'  */
#line 418 "language/parser.y"
                                    { add_instruction(EXP); }
#line 2018 "generated/parser.bison.cpp"
    break;

  case 76: /* expr: LOG '(' expr ')'  */
#line 419 "language/parser.y"
                                    { add_instruction(LOG); }
#line 2024 "generated/parser.bison.cpp"
    break;

  case 77: /* expr: SQRT '(' expr ')'  */
#line 420 "language/parser.y"
                                    { add_instruction(SQRT); }
#line 2030 "generated/parser.bison.cpp"
    break;

  case 78: /* expr: VAR  */
#line 421 "language/parser.y"
                                    { add_instruction(VAR, 0, (yyvsp[0].STRING)); }
#line 2036 "generated/parser.bison.cpp"
    break;

  case 79: /* expr: VAR '=' expr  */
#line 422 "language/parser.y"
                                    { add_instruction(ASSIGN,0,(yyvsp[-2].STRING)); }
#line 2042 "generated/parser.bison.cpp"
    break;

  case 80: /* expr: VAR PLUS_EQUAL expr  */
#line 423 "language/parser.y"
                                    { add_instruction(VAR,0,(yyvsp[-2].STRING)); add_instruction(PLUS); add_instruction(ASSIGN,0,(yyvsp[-2].STRING)); }
#line 2048 "generated/parser.bison.cpp"
    break;

  case 81: /* expr: VAR MIN_EQUAL expr  */
#line 424 "language/parser.y"
                                    { add_instruction(VAR,0,(yyvsp[-2].STRING)); add_instruction(MIN); add_instruction(ASSIGN,0,(yyvsp[-2].STRING)); }
#line 2054 "generated/parser.bison.cpp"
    break;

  case 82: /* expr: VAR TIMES_EQUAL expr  */
#line 425 "language/parser.y"
                                    { add_instruction(VAR,0,(yyvsp[-2].STRING)); add_instruction(TIMES); add_instruction(ASSIGN,0,(yyvsp[-2].STRING)); }
#line 2060 "generated/parser.bison.cpp"
    break;

  case 83: /* expr: VAR DIV_EQUAL expr  */
#line 426 "language/parser.y"
                                    { add_instruction(VAR,0,(yyvsp[-2].STRING)); add_instruction(DIV); add_instruction(ASSIGN,0,(yyvsp[-2].STRING)); }
#line 2066 "generated/parser.bison.cpp"
    break;


#line 2070 "generated/parser.bison.cpp"

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

#line 428 "language/parser.y"


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
    for (size_t i = 0; i < code_genere.size(); i++) {
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

    /* Print function map */
    std::cout << "\nFunctions:\n";
    for (auto it = functions.begin(); it != functions.end(); ++it) {
        std::cout << it->first << ": ( ";
        for (auto it2 = it->second->parameters.begin(); it2 != it->second->parameters.end(); ++it) {
            std::cout << it2->first << " ";
        }
        std::cout << ") => {" <<
            "\n\tcolor: " << it->second->color <<
            "\n\tstyle: " << it->second->style <<
            "\n}\n";
    }

    return EXIT_SUCCESS;
}

