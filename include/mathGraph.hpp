#ifndef __MATHGRAPH__
#define __MATHGRAPH__

#include "imgui.h"
#include <string>
#include <map>
#include <vector>

class  GraphSetup
{
public:
    //var

    //in case of empty graph
    bool gotSomething = false;//
    //all names
    const char* graphName = "MathematiC";//
    std::vector<const char*> names;//
    //colors
    std::vector<ImVec4> colors;//
    //plot type (solid, filled, dotted, hist)
    std::vector<const char*> plotModes;//
    //display intervals
    double setDisplayYmin = -10.;//
    double setDisplayYmax =  10.;//
    double setDisplayXmin = -10.;//
    double setDisplayXmax =  10.;//
    //interval of definitions of each curves
    std::vector<double> interXmins;//
    std::vector<double> interXmaxs;//
    //each curves calculated data
    std::vector<std::vector<double>> curvesCalData;//
    //windows vals
    int winW;//
    int winH;//

    //functions

    //init
    /**
     * Function used init a GraphSetup
     * @param[in]       width       Window width
     * @param[in]       height      Window height
     */
    GraphSetup(int width, int height);
    /**
     * Function used init a GraphSetup
     * @param[in]       width       Window width
     * @param[in]       height      Window height
     */
    GraphSetup(int width, int height, std::map<std::string, function::function> &curvesData, std::vector<std::string> curvesNames, double displayYmin, double displayYmax, double displayXmin, double displayXmax, std::string label);
};


/**
 * Function used to draw a Graph
 * @param[in]       width       Window width
 * @param[in]       height      Window height
 * @param[in]       setup       GraphSetup object that contain everthing needed for display
 */
void doGraph(GraphSetup setup);
/**
* Convert hexadecimal string to RGBA ImVec4
* @param[in]       inputHex    string of the hexadecimal value format #FFFFFF (equal white)
*/
ImVec4 convertHexToRGBA(std::string& inputHex);

#endif/*__MATHGRAPH__*/
