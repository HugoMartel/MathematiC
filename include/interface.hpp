/**
 * @file    interface.hpp
 */

#ifndef __INTERFACE__
#define __INTERFACE__
#include <string>


/**
 * Calls YYParse with the filename
 * @param[in]   filename     the filename containing the buffer
 */

void callingYYParse(std::string);

/**
 * getter & setter for the verbose output when running code
 * @param[in]   mOutput     passed by reference, the string containing the output
 * @param[in]   mIsError    passed by reference, bool telling if there is a problem
 * @param[in]   read        bool telling if we're using our param to edit the local var,
 *                          or if we're reading them, by default on false
 * @param[out]  isError     Retrieving if the code produced an error or note
 */
bool verbose(std::string &, bool, bool = false);

#endif
