#ifndef __MATHGRAPH__
#define __MATHGRAPH__

#include "imgui.h"
#include <string>

/**
 * Function used to draw a Graph
 * @param[in]       width       Window width
 * @param[in]       height      Window height
 * @param[in]       interXmin   Min x value of the drawn functions, will become a table of values
 * @param[in]       interXmax   Max x value of the drawn functions
 * @param[in]       displayYmin Min y value of the function display
 * @param[in]       displayYmax Max y value of the function display
 * @param[in]       displayXmin Min x value of the function display
 * @param[in]       displayXmax Max x value of the function display
 */
void doGraph(int *width, int *height, double interXmin, double interXmax, const double &displayYmin, const double &displayYmax, const double &displayXmin, const double &displayXmax, ImVec4 testColors[], int testColorsLen, const char * plotMode);
/**
* Convert hexadecimal string to RGBA ImVec4
* @param[in]       inputHex    string of the hexadecimal value format #FFFFFF (equal white)
*/
ImVec4 convertHexToRGBA(std::string& inputHex);

#endif/*__MATHGRAPH__*/
