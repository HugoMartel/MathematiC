/**
 * @file    interface.cpp
 */

#include "interface.hpp"

#include "lexer.yy.hpp"
#include "parser.yy.hpp"


void callingYYParse(std::string filename)
{
    if (filename != "") {
        compileCode(filename.c_str());
    }
}

bool verbose(std::string &mOutput, bool mIsError, bool read)
{
    /*local variables*/
    static std::string output("");
    static bool isError = false;
    /*we're writing the mOuput and mIsError into the local variables*/
    if (!read) {
        output = mOutput;
        isError = mIsError;
    /*we're reading the output and the isError, copying it into the parameters*/
    } else {
        mOutput = output;
        mIsError = isError;
    }
    return isError;
}
