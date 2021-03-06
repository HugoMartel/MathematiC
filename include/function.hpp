/**
 * @file    function.hpp
 */

#ifndef __FUNCTION__
#define __FUNCTION__

#include <string>
#include <vector>
#include <map>
#include <cfloat>

/*===================*/
/* --    CLASS    -- */
/*===================*/
/**
 * Class containing a single instruction to store on the programm stack
 */
class Instruction
{
public:
    /** Instruction code, auto generated by Bison */
    int code;
    /** Value returned by the instruction, optional */
    double value;
    /** Reference for the data table, optional */
    std::string name;
    /**
     * Constructor to create an instruction object and then store it in the programm stack
     * @param[in]   c   Code of the instruction
     * @param[in]   v   Double value returned by the instruction
     * @param[in]   n   String value returned by the instruction
     */
    Instruction(const int &c, const double &v = 0, const std::string &n = "") : code(c), value(v), name(n) {}
    /**
     * Default constructor
     */
    Instruction() : code(0), value(0), name("") {}
    /**
     * Defaut destructor
     */
    ~Instruction() {}
};

/**
 * Function class storing its attributes and instruction stack
 */
class Function
{
public:
    /** Function code */
    std::vector<Instruction> code;
    /** Internal Instruction counter */
    std::map<std::string, double> parameters;
    /** Internal Instruction Counter */
    long unsigned int iic;
    /** Hex color code */
    std::string color;
    /** Display style */
    std::string style;
    /** Definition interval */
    std::pair<double, double> xInterval;

    /** Default Constructor */
    Function()
    {
        color = "#FF0000";
        style = "solid";
        xInterval.first = -DBL_MAX;/*lol*/
        xInterval.second = DBL_MAX;
        iic = 0;
    }
    /** Default Destructor */
    ~Function() {}
    /**
     * Add instruction method
     * @param[in]   c   Instruction's code
     * @param[in]   v   Instruction value used in some cases
     * @param[in]   n   Instruction string value like a var name
     * @return      Error code
     */
    int add_instruction(const int &c, const double &v = 0, const std::string &n = "")
    {
        code.push_back(Instruction(c, v, n));
        ++iic;
        return 0;
    }
    /**
     * Function to execute a function
     * @param[in]   args             Parameter values (double)
     * @return      Value returned by the function (double)
     */
    double operator()(...);
};

#endif /*__FUNCTION__*/
