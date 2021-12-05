#include "mathGraph.hpp"

#include "imgui.h"
#include "implot.h"

#include <stdlib.h>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <math.h>


/*=======================================================================================*/
//TODO   add the function as parameters
void doGraph(int *width, int *height, double interXmin, double interXmax, const double &displayYmin, const double &displayYmax, const double &displayXmin, const double &displayXmax, ImVec4 testColors[], int testColorsLen, const char * plotMode)
{
    int tmp = 1;
    if (std::strcmp(plotMode, "dotted") == 0 || std::strcmp(plotMode, "hist") == 0) {
        tmp = 4;
    }

    /* Get widget's width */
    const unsigned int sizeN = std::floor((*width - 480)/tmp);
    /* Points to plot coords (x,y) */
    double arrX[sizeN];
    double arrY[sizeN];

    /* step between two points plotted */
    double step1 = (1.0/sizeN) * (interXmax - interXmin) * tmp;
    /* Compute coords on the interval [interXmin, interXmax] */
    for (unsigned int i = 0; i < sizeN; ++i) {
        arrY[i] = 10 * (cos(interXmin)*exp(-0.5 * interXmin));//! will change
        arrX[i] = interXmin;
        interXmin += step1; // Corresponds to 1px on the X axis
    }

    ImPlot::PushColormap(ImPlot::AddColormap("UserColors", testColors, testColorsLen, true));

    if (ImPlot::BeginPlot("MathematiC", ImVec2(*width - 480 - 15,*height - 37))) {
        /* Init Axis */
        ImPlot::SetupAxes("x", "y");
        /*Always prevents movable axis + set the display frame*/
        ImPlot::SetupAxesLimits(displayXmin, displayXmax, displayYmin, displayYmax, ImGuiCond_Always);

        if (std::strcmp(plotMode, "solid") == 0) {
            /* PlotLine(label, x values, y values, arrays length = # of points to draw) */
            //! will change to be able to plot n functions from lexer/parser
            ImPlot::PlotLine("y=10*cos(20*x)*e^(-0.5*x)", arrX, arrY, sizeN);// First func
            //...
            ImPlot::PlotLine("y=x", arrX, arrX, sizeN);// func number N
        } else if (std::strcmp(plotMode, "filled") == 0) {
            //fill
            ImPlot::PushStyleVar(ImPlotStyleVar_FillAlpha, 0.15f);// set alpha
            ImPlot::PlotShaded("y=10*cos(20*x)*e^(-0.5*x)", arrX, arrY, sizeN);// First func
            //...
            ImPlot::PlotShaded("y=x", arrX, arrX, sizeN);// func number N
            ImPlot::PopStyleVar();// reset alpha

            //lines
            ImPlot::PlotLine("y=10*cos(20*x)*e^(-0.5*x)", arrX, arrY, sizeN);// First func
            //...
            ImPlot::PlotLine("y=x", arrX, arrX, sizeN);// func number N
        } else if (std::strcmp(plotMode, "dotted") == 0) {
            ImPlot::PlotScatter("y=10*cos(20*x)*e^(-0.5*x)", arrX, arrY, sizeN);// First func
            //...
            ImPlot::PlotScatter("y=x", arrX, arrX, sizeN);// func number N
        } else if (std::strcmp(plotMode, "hist") == 0) {
            ImPlot::PushStyleVar(ImPlotStyleVar_FillAlpha, 0.15f);// set alpha
            ImPlot::PlotBars("y=10*cos(20*x)*e^(-0.5*x)", arrX, arrY, sizeN, step1);// First func
            //...
            ImPlot::PlotBars("y=x", arrX, arrX, sizeN, step1);// func number N
            ImPlot::PopStyleVar();// reset alpha
        }

        ImPlot::EndPlot();
    }

}
/*=======================================================================================*/
ImVec4 convertHexToRGBA(std::string& inputHex)
{
    int r, g, b;
    const char *cstr = inputHex.c_str();
    sscanf(cstr, "#%02x%02x%02x", &r, &g, &b);
    return(ImVec4((float)r/255, (float)g/255, (float)b/255, 1));
}
