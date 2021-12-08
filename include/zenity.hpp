/**
 * @file    zenity.hpp
 */

#ifndef __ZENITY__
#define __ZENITY__

#include <string>
#include <vector>

/**
 * Function to open a File Dialog using Zenity (Linux) or the Windows API
 * @note    heavily inspired by https://github.com/dalerank/nanogui-sdl open/close implementation
 * @param[in]   filetypes   Files types to get and their full names
 * @param[in]   save        0: Open, 1: Save
 * @return      Absolute path of the selected file
 */
std::string  file_dialog(const std::vector<std::pair<std::string, std::string>> &filetypes, bool save);

#endif/*__ZENITY__*/
