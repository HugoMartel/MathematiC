#ifndef __INTERFACE__
#define __INTERFACE__
#include <string>


/*
* Calls YYParse with the filename
* @param[in]   filename     the filename containing the buffer
*/

void callingYYParse(std::string); 

/*
* Calls YYParse with the filename
* @param[out]  isError   the bool used for text coloration, true if there is an error
* @param[out]  output    the string that will be shown, verbosing the operation of the code
*/
void getVerbose(bool &, std::string &);

#endif
