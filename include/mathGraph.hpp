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
    bool gotSomething;
    /** Boolean to check if the function can be drawn or not */
    bool drawable;
    /** Graph widget name */
    const char *graphName;
    /** Functions names */
    std::vector<const char *> names;
    /** Color map */
    std::vector<ImVec4> colors;
    /** Plot type (solid, filled, dotted, hist) */
    std::vector<const char *> plotModes;
    /** Display intervals Y minimun*/
    double setDisplayYmin;
    /** Display intervals Y maximum*/
    double setDisplayYmax;
    /** Display intervals X minimal*/
    double setDisplayXmin;
    /** Display intervals X maximal*/
    double setDisplayXmax;
    /** Definition interval minimums of each curves */
    std::vector<double> interXmins;
    /** Definition interval maximums of each curves */
    std::vector<double> interXmaxs;
    /** Map storing the Functions objects associated with a name (string) used as map key */
    std::map<std::string, Function> curvesFunctions;
    /** Curve points to draw on the widget */
    std::vector<std::vector<double>> curvesCalData;

    /*-----------------*/
    /* --  METHODS  -- */
    /*-----------------*/
    /**
     * Default constructor
     */
    GraphSetup();

    /**
     * Method used to compute the points to draw on the UI
     * @param[in]   width   Width of the graph widget used to evaluate the amount of points to draw
     */
    void updateCurves(int width);
    /**
     * Method used to reset the object
     */
    void clear();
};


/**
 * Function used to draw a Graph
 * @param[in]       width       Window width
 * @param[in]       height      Window height
 * @param[in]       setup       GraphSetup object that contain everthing needed for display
 */
void doGraph(int width, int height, GraphSetup *setup);

/**
* Convert hexadecimal string to RGBA ImVec4
* @param[in]       inputHex    string of the hexadecimal value format #FFFFFF (equal white)
*/
ImVec4 convertHexToRGBA(const std::string inputHex);

#endif/*__MATHGRAPH__*/
