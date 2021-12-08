/**
 * @file    interface.cpp
 */

#include "interface.hpp"

#include "lexer.yy.hpp"
#include "parser.yy.hpp"


void callingYYParse(std::string filename, GraphSetup *graph, int width)
{
    if (filename != "") {
        compileCode(filename.c_str(), graph);

        graph->updateCurves(width);
    }
}


bool verbose(std::string &mOutput, bool mIsError, bool read, bool reset)
{
    /*local variables*/
    static std::string output("");
    static bool isError = false;
    /* reseting the output */
    if (reset) {
        output = "";
    } else {
        /*we're writing the mOuput and mIsError into the local variables*/
        if (!read) {
            output += mOutput;
            isError = mIsError;
        /*we're reading the output and the isError, copying it into the parameters*/
        } else {
            mOutput = output;
            mIsError = isError;
        }
    }
    return isError;
}


void open(char *buff, std::string &filename)
{
    std::string input("");
    std::fstream file;
    file.open(filename);
    if (!file) {
        fprintf(stderr, "error, cannot open the file");
        return;
    } else {
        std::string line;
        while (getline(file, line)) {
            input += line;
            input += '\n';
        }
        if(input.size() < BUFF_SIZE){
            for(unsigned long int i = 0; i < input.size(); ++i){
                buff[i] = input[i];
            }
            buff[input.size()] = '\0';
        } else {
            buff[0] = '\0';
            fprintf(stderr, "cannot open this file, it's too large");
        }
    }
}


void save(char *buff, std::string &filename)
{
    /*removing all the '.' in the filename*/
    filename.erase(std::remove(filename.begin(), filename.end(), '.'), filename.end());
    /*if the last 4 chars are matc*/
    if (std::string("matc") !=  filename.substr(filename.size() - 4)) {
        /*then we insert the . in the filename*/
        filename += ".matc";
    } else {
        /*else we're adding the file extension*/
        filename.insert(filename.size() - 4, ".");
    }
    /*creating the file*/
    std::ofstream file(filename);
    /*Writing the file*/
    int i = 0;
    while (i < BUFF_SIZE && buff[i] != '\0') {
        file << buff[i];
        ++i;
    }
    /*closing the file*/
    file.close();
}
