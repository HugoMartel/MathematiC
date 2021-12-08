/**
 * @file    mathGraph.cpp
 */

#include "mathGraph.hpp"

#include "imgui.h"
#include "implot.h"

#include <stdlib.h>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <math.h>
#include <vector>


/*GraphSetup=============================================================================*/
GraphSetup::GraphSetup() {}

/*=======================================================================================*/
GraphSetup::GraphSetup(std::map<std::string, Function> &curvesData, std::vector<std::string> curvesNames, const double &displayYmin, const double &displayYmax, const double &displayXmin, const double &displayXmax, std::string &label)
{
    if (curvesNames.size() > 0) { //check if there is a curve

        //save the curves
        curvesFunctions = curvesData;

        //set display intervals
        this->setDisplayYmin = displayYmin;
        this->setDisplayYmax = displayYmax;
        this->setDisplayXmin = displayXmin;
        this->setDisplayXmax = displayXmax;

        //set graph label
        this->graphName = label.c_str();

        //set curves data
        for (size_t i = 0; i < curvesNames.size(); ++i) {
            Function currCurve = curvesData.at(curvesNames[i]);
            this->names.push_back(curvesNames[i].c_str());
            this->colors.push_back(convertHexToRGBA(currCurve.color));
            this->plotModes.push_back(currCurve.style.c_str());
            this->interXmins.push_back(currCurve.xInterval.first);
            this->interXmaxs.push_back(currCurve.xInterval.second);
        }

        this->gotSomething = true;
    }
}
/*=======================================================================================*/
void GraphSetup::updateCurves(int width)
{
    if (this->gotSomething) { //check if there is a curve

        /* Used to store the graph widget size */
        unsigned int sizeN;
        size_t i;

        //set curves data
        for (i = 0; i < this->names.size(); ++i) {
            Function currCurve = this->curvesFunctions.at(this->names[i]);

            //calculate each coordinates
            int tmp = 1;
            if (std::strcmp(this->plotModes[i], "dotted") == 0 || std::strcmp(this->plotModes[i], "hist") == 0) {
                tmp = 4;
            }


            sizeN = std::floor((width - 495)/tmp);
            std::vector<double> currCurveY;
            std::vector<double> currCurveX;
            currCurveY.reserve(sizeN);
            currCurveX.reserve(sizeN);

            /* step between two points plotted */
            double step1 = (1.0/sizeN) * (interXmaxs[i] - interXmins[i]) * tmp;

            /* Compute coords on the interval [interXmin, interXmax] */
            double currentX = interXmins[i];
            for (i = 0; i < sizeN; ++i) {
                currCurveY.push_back(currCurve(currentX));
                currCurveX.push_back(currentX);
                currentX += step1; // Corresponds to "tmp"px on the X axis
            }

            this->curvesCalData.push_back(currCurveY);
            this->curvesCalData.push_back(currCurveX);
        }
    }
}



/*Implot Interface Related===============================================================*/
void doGraph(int width, int height, GraphSetup setup)
{
    //get widget size
    int winW = width - 495;
    int winH = height - 37;

    if (ImPlot::BeginPlot(setup.graphName, ImVec2(winW, winH))) {

        /* Init Axis */
        ImPlot::SetupAxes("x", "y");
        /*Always prevents movable axis + set the display frame*/
        ImPlot::SetupAxesLimits(setup.setDisplayXmin, setup.setDisplayXmax, setup.setDisplayYmin, setup.setDisplayYmax, ImGuiCond_Always);

        if (setup.gotSomething) {

            for (size_t n = 0; n < setup.names.size(); n++) {

                if (std::strcmp(setup.plotModes[n], "solid") == 0) {

                    /* PlotLine(label, x values, y values, arrays length = # of points to draw) */
                    ImPlot::PlotLine(setup.names[n], setup.curvesCalData[1+n*2].data(), setup.curvesCalData[n*2].data(), (int) setup.curvesCalData[n*2].size());

                } else if (std::strcmp(setup.plotModes[n], "filled") == 0) {

                    //fill
                    ImPlot::PushStyleVar(ImPlotStyleVar_FillAlpha, 0.15f);// set alpha
                    // Name, X[], Y[], size
                    ImPlot::PlotShaded(setup.names[n], setup.curvesCalData[1+n*2].data(), setup.curvesCalData[n*2].data(), (int) setup.curvesCalData[n*2].size());
                    ImPlot::PopStyleVar();// reset alpha
                    //lines
                    // Name, X[], Y[], size
                    ImPlot::PlotLine(setup.names[n], setup.curvesCalData[1+n*2].data(), setup.curvesCalData[n*2].data(), (int) setup.curvesCalData[n*2].size());

                } else if (std::strcmp(setup.plotModes[n], "dotted") == 0) {

                    // Name, X[], Y[], size
                    ImPlot::PlotScatter(setup.names[n], setup.curvesCalData[1+n*2].data(), setup.curvesCalData[n*2].data(), (int) setup.curvesCalData[n*2].size());

                } else if (std::strcmp(setup.plotModes[n], "hist") == 0) {

                    ImPlot::PushStyleVar(ImPlotStyleVar_FillAlpha, 0.15f);// set alpha
                    // Name, X[], Y[], size, bar_width
                    ImPlot::PlotBars(setup.names[n], setup.curvesCalData[1+n*2].data(), setup.curvesCalData[n*2].data(), (int) setup.curvesCalData[n*2].size(), setup.curvesCalData[1+n*2][1]-setup.curvesCalData[1+n*2][0]);

                    ImPlot::PopStyleVar();// reset alpha
                }
            }
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
