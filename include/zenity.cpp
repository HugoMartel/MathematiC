/**
 * @file    zenity.cpp
 */

#if defined(_WIN32)
#include <windows.h>
#endif

#include <algorithm>
#include <thread>
#include <chrono>
#include <iostream>

#if !defined(_WIN32)
    #include <locale.h>
    #include <signal.h>
    #include <sys/dir.h>
#endif

#include "./zenity.hpp"

#if !defined(__APPLE__)
std::string
file_dialog(const std::vector<std::pair<std::string, std::string>> &filetypes, bool save)
{
/** Max buffer size of the path selected with the dialog */
#define FILE_DIALOG_MAX_BUFFER 1024
#if defined(_WIN32)
    OPENFILENAME ofn;
    ZeroMemory(&ofn, sizeof(OPENFILENAME));
    ofn.lStructSize = sizeof(OPENFILENAME);
    char tmp[FILE_DIALOG_MAX_BUFFER];
    ofn.lpstrFile = tmp;
    ZeroMemory(tmp, FILE_DIALOG_MAX_BUFFER);
    ofn.nMaxFile = FILE_DIALOG_MAX_BUFFER;
    ofn.nFilterIndex = 1;

    std::string filter;

    if (!save && filetypes.size() > 1) {
        filter.append("Supported file types (");
        for (size_t i = 0; i < filetypes.size(); ++i) {
            filter.append("*.");
            filter.append(filetypes[i].first);
            if (i + 1 < filetypes.size())
                filter.append(";");
        }
        filter.append(")");
        filter.push_back('\0');
        for (size_t i = 0; i < filetypes.size(); ++i) {
            filter.append("*.");
            filter.append(filetypes[i].first);
            if (i + 1 < filetypes.size())
                filter.append(";");
        }
        filter.push_back('\0');
    }
    for (auto pair: filetypes) {
        filter.append(pair.second);
        filter.append(" (*.");
        filter.append(pair.first);
        filter.append(")");
        filter.push_back('\0');
        filter.append("*.");
        filter.append(pair.first);
        filter.push_back('\0');
    }
    filter.push_back('\0');
    ofn.lpstrFilter = filter.data();

    if (save) {
        ofn.Flags = OFN_EXPLORER | OFN_PATHMUSTEXIST | OFN_OVERWRITEPROMPT;
        if (GetSaveFileNameA(&ofn) == FALSE)
            return "";
    } else {
        ofn.Flags = OFN_EXPLORER | OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
        if (GetOpenFileNameA(&ofn) == FALSE)
            return "";
    }
    return std::string(ofn.lpstrFile);
#else
    char buffer[FILE_DIALOG_MAX_BUFFER];

    /* Use the zenity tool */
    std::string cmd = "/usr/bin/zenity --file-selection ";//! Only supports /usr/bin location
    if (save)
        cmd += "--save ";
    cmd += "--file-filter=\"";
    /* Get file types to open/save */
    for (auto pair: filetypes)
        cmd += "\"*." + pair.first +  "\" ";
    cmd += "\"";

    /* Open the zenity window */
    FILE *output = popen(cmd.c_str(), "r");
    if (output == nullptr)
        throw std::runtime_error("popen() failed -- could not launch zenity! (Only supports /usr/bin location for zenity)");

    /* Wait for the user to select a file */
    while (fgets(buffer, FILE_DIALOG_MAX_BUFFER, output) != NULL);

    /* Close the dialog */
    pclose(output);

    /* Get the selected file path */
    std::string result(buffer);
    result.erase(std::remove(result.begin(), result.end(), '\n'), result.end());//Clean the result

    return result;
#endif/*_WIN32*/
}
#endif/*__APPLE__*/
