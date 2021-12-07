/**
 * @file    interface.hpp
 */

#ifndef __INTERFACE__
#define __INTERFACE__
#include <fstream>
#include <string>
#include <algorithm>


#ifndef BUFF_SIZE
#define BUFF_SIZE 2000
#endif


/**
 * Save a given text buffer to a file
 * @param[in]   buff        text to save
 * @param[in]   filename    path of the file to save to
 * @param[in]   window      the SDL_window
 * @param[in]   logo        the sdl logo
 * @param[in]   ctx         the sdl context
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
 * @param[in]   mOutput     passed by reference, the string containing the output
 * @param[in]   mIsError    passed by reference, bool telling if there is a problem
 * @param[in]   read        bool telling if we're using our param to edit the local var,
 *                          or if we're reading them, by default on false
 * @param[out]  isError     Retrieving if the code produced an error or note
 */
bool verbose(std::string &, bool, bool = false);

#endif
