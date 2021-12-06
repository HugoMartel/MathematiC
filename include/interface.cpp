#include "interface.hpp"

void callingYYParse(std::string filename)
{
    if (filename != "") {
        //TODO: call the lex etc
    }
}

bool verbose(std::string &mOutput, bool mIsError, bool read = false)
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
