/**
 * @file    mathGraph.cpp
 */

#include "mathGraph.hpp"

#include "imgui.h"
#include "implot.h"

#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <math.h>
#include <vector>


/*GraphSetup=============================================================================*/
GraphSetup::GraphSetup() {
    this->graphName = "Affichage";
    this->setDisplayYmin = -10.;
    this->setDisplayYmax =  10.;
    this->setDisplayXmin = -10.;
    this->setDisplayXmax =  10.;
    this->gotSomething = false;
    this->drawable = false;
}


/*=======================================================================================*/
void GraphSetup::updateCurves(int width)
{
    if (this->gotSomething) { //check if there is a curve

        /* Used to store the graph widget size */
        unsigned int sizeN, spread;
        size_t i, j;
        double stepX, currentX;

        this->curvesCalData.resize(this->names.size() * 2);

        //set curves data
        for (i = 0; i < this->names.size(); ++i) {

            //calculate each coordinates
            spread = 1;
            if (std::strcmp(this->plotModes[i], "dotted") == 0 || std::strcmp(this->plotModes[i], "hist") == 0) {
                spread = 4;
            }

            /* # of points to draw */
            sizeN = std::floor((width - 495) / spread);
            /* Reserve Y values */
            this->curvesCalData[2*i].reserve(sizeN);
            /* Reserve X values */
            this->curvesCalData[2*i+1].reserve(sizeN);

            /* step between two points plotted */
            stepX = (1.0 / sizeN) * std::abs((this->setDisplayXmax - this->setDisplayXmin)) * spread;

            /* Compute coords on the interval [setDisplayXmin, setDisplayXmax] */
            currentX = this->setDisplayXmin;

            /* Compute points values */
            for (j = 0; j < sizeN; ++j) {
                /* Check if the function can be drawn on this interval */
                if (interXmins[i] <= currentX && interXmaxs[i] >= currentX) {

                    this->curvesCalData[2*i].push_back(this->curvesFunctions.at(this->names[i])(currentX));
                    this->curvesCalData[2*i+1].push_back(currentX);

                }
                currentX += stepX; // Corresponds to "tmp"px on the X axis
            }

        }

        this->gotSomething = false;
        this->drawable = true;
    }
}
/*=======================================================================================*/
void GraphSetup::clear()
{
    this->drawable = false;
    this->gotSomething = false;

    curvesFunctions.clear();

    this->names.clear();
    this->colors.clear();
    this->plotModes.clear();
    this->interXmins.clear();
    this->interXmaxs.clear();
    this->curvesCalData.clear();
}

/*Implot Interface Related===============================================================*/
void doGraph(int width, int height, GraphSetup *setup)
{
    //get widget size
    int winW = width - 495;
    int winH = height - 37;


    /* Check if the Widget is correctly initialized */
    if (ImPlot::BeginPlot(setup->graphName, ImVec2(winW, winH))) {

        /* Init Axis */
        ImPlot::SetupAxes("x", "y");
        /*Always prevents movable axis + set the display frame*/
        ImPlot::SetupAxesLimits(setup->setDisplayXmin, setup->setDisplayXmax, setup->setDisplayYmin, setup->setDisplayYmax, ImGuiCond_Always);

        /* Check if the function is drawable */
        if (setup->drawable) {

            /* Load ColorMap using ImVec4 */
            ImPlot::PushColormap(ImPlot::AddColormap("UserColors", setup->colors.data(), (int) setup->colors.size(), true));

            for (size_t n = 0; n < setup->names.size(); n++) {

                if (std::strcmp(setup->plotModes[n], "solid") == 0) {

                    /* PlotLine(label, x values, y values, arrays length = # of points to draw) */
                    ImPlot::PlotLine(setup->names[n], setup->curvesCalData[1+n*2].data(), setup->curvesCalData[n*2].data(), (int) setup->curvesCalData[n*2].size());

                } else if (std::strcmp(setup->plotModes[n], "filled") == 0) {

                    //fill
                    ImPlot::PushStyleVar(ImPlotStyleVar_FillAlpha, 0.15f);// set alpha
                    // Name, X[], Y[], size
                    ImPlot::PlotShaded(setup->names[n], setup->curvesCalData[1+n*2].data(), setup->curvesCalData[n*2].data(), (int) setup->curvesCalData[n*2].size());
                    ImPlot::PopStyleVar();// reset alpha
                    //lines
                    // Name, X[], Y[], size
                    ImPlot::PlotLine(setup->names[n], setup->curvesCalData[1+n*2].data(), setup->curvesCalData[n*2].data(), (int) setup->curvesCalData[n*2].size());

                } else if (std::strcmp(setup->plotModes[n], "dotted") == 0) {

                    // Name, X[], Y[], size
                    ImPlot::PlotScatter(setup->names[n], setup->curvesCalData[1+n*2].data(), setup->curvesCalData[n*2].data(), (int) setup->curvesCalData[n*2].size());

                } else if (std::strcmp(setup->plotModes[n], "hist") == 0) {

                    ImPlot::PushStyleVar(ImPlotStyleVar_FillAlpha, 0.15f);// set alpha
                    // Name, X[], Y[], size, bar_width
                    ImPlot::PlotBars(setup->names[n], setup->curvesCalData[1+n*2].data(), setup->curvesCalData[n*2].data(), (int) setup->curvesCalData[n*2].size(), setup->curvesCalData[1+n*2][1]-setup->curvesCalData[1+n*2][0]);

                    ImPlot::PopStyleVar();// reset alpha
                } else {

                    fprintf(stderr, "Wrong print type for the function %s.\n", setup->names[n]);
                }
            }
        }
        ImPlot::EndPlot();
    }
}

/*=======================================================================================*/
ImVec4 convertHexToRGBA(const std::string inputHex)
{
    int r, g, b;
    const char *cstr = inputHex.c_str();
    sscanf(cstr, "#%02x%02x%02x", &r, &g, &b);
    return(ImVec4((float)r/255, (float)g/255, (float)b/255, 1));
}
