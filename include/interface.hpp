/**
 * @file    interface.hpp
 */

#ifndef __INTERFACE__
#define __INTERFACE__

#include <fstream>
#include <string>
#include <algorithm>


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
 * @param[in]   filename     the filename containing the buffer
 */

void callingYYParse(std::string);

/**
 * getter & setter for the verbose output when running code
 * @param[in,out]   mOutput     passed by reference, the string containing the output
 * @param[in,out]   mIsError    bool telling if the output is an error message, defaults to true
 * @param[in]       read        bool telling if we're using our param to edit the local var, or if we're reading them, by default on false
 * @return          Retrieving if the code produced an error or note
 */
bool verbose(std::string &, bool = true, bool = false);

#endif
