/**
 * @file    mathGraph.hpp
 */

#ifndef __MATHGRAPH__
#define __MATHGRAPH__

#include "imgui.h"

#include <string>
#include <map>
#include <vector>

#include "function.hpp"


class  GraphSetup
{
public:
    /*------------------*/
    /* -- ATTRIBUTES -- */
    /*------------------*/
    /** Defaults to false, set to true only if the compilation is successful */
    bool gotSomething = false;
    /** Graph widget name */
    const char* graphName = "MathematiC";
    /** Functions names */
    std::vector<const char *> names;
    /** Color map */
    std::vector<ImVec4> colors;
    /** Plot type (solid, filled, dotted, hist) */
    std::vector<const char*> plotModes;
    /** Display intervals */
    double setDisplayYmin = -10.;
    double setDisplayYmax =  10.;
    double setDisplayXmin = -10.;
    double setDisplayXmax =  10.;
    /** Definition interval of each curves */
    std::vector<double> interXmins;
    std::vector<double> interXmaxs;
    //each curve
    std::map<std::string, Function> curvesFunctions;
    //each curves calculated data
    std::vector<std::vector<double>> curvesCalData;

    /*-----------------*/
    /* --  METHODS  -- */
    /*-----------------*/
    /**
     * Default constructor
     */
    GraphSetup();
    /**
     * Constructor used to build a GraphSetup Object, almost ready to be drawn
     * @param[in]   curvesData  TODO
     * ...
     */
    GraphSetup(std::map<std::string, Function> &curvesData, std::vector<std::string> curvesNames, const double &displayYmin, const double &displayYmax, const double &displayXmin, const double &displayXmax, std::string &label);

    /**
     * Method used to compute the points to draw on the UI
     * @param[in]   width   Width of the graph widget used to evaluate the amount of points to draw
     */
    void updateCurves(int width);
};


/**
 * Function used to draw a Graph
 * @param[in]       width       Window width
 * @param[in]       height      Window height
 * @param[in]       setup       GraphSetup object that contain everthing needed for display
 */
void doGraph(int width, int height, GraphSetup setup);

/**
* Convert hexadecimal string to RGBA ImVec4
* @param[in]       inputHex    string of the hexadecimal value format #FFFFFF (equal white)
*/
ImVec4 convertHexToRGBA(std::string& inputHex);

#endif/*__MATHGRAPH__*/
