/**
 * @file    interface.hpp
 */

#ifndef __INTERFACE__
#define __INTERFACE__

#include <fstream>
#include <string>
#include <algorithm>

#include "mathGraph.hpp"


#ifndef BUFF_SIZE
/**
 * Max size of the TextInput buffer (char *)
 * @note    maybe change to std::string if available
 */
#define BUFF_SIZE 2000
#endif


/**
 * Save a given text buffer to a file
 * @param[in]   buff        text to save
 * @param[in]   filename    path of the file to save to
 */
void save(char *, std::string &);


/**
 * Open a given file to a text buffer
 * @param[in]   buff        buffer to write the text to
 * @param[in]   filename    path of the file to open
 */
void open(char *, std::string &);


/**
 * Calls YYParse with the filename
 * @param[in]   filename    the filename containing the buffer
 * @param[out]  graph       Pointer to the main GraphSetup object to change after a successful compilation
 * @param[in]   width       Graph widget width, used to compute the right amount of points
 */
void callingYYParse(std::string, GraphSetup *, int width);


/**
 * Getter & Setter for the verbose output when running code
 * @param[in,out]   mOutput     passed by reference, the string containing the output
 * @param[in,out]   mIsError    bool telling if the output is an error message, defaults to true
 * @param[in]       read        bool telling if we're using our param to edit the local var, or if we're reading them, by default on false
 * @param[in]       reset       bool telling if we're reseting the output
 * @return          Retrieving if the code produced an error or note
 */
bool verbose(std::string &, bool = true, bool = false, bool = false);

#endif
