
//#include "stdafx.h"
#include "string.h"
#include <cstring>
#include <vector>
#include "BstUtility.h"
using namespace std;

#define uint unsigned int

/*https://codereview.stackexchange.com/questions/118949/random-string-generator*/

std::string randomString(uint l, std::string charIndex)
{ 
    // l and charIndex can be customized, but I've also initialized them.

    uint length = rand() % l + 1; 
    // length of the string is a random value that can be up to 'l' characters.

    uint ri[15]; 
    /* array of random values that will be used to iterate through random 
      indexes of 'charIndex' */

    for (uint i = 0; i < length; ++i) 
        ri[i] = rand() % charIndex.length();
    // assigns a random number to each index of "ri"

    std::string rs = ""; 
    // random string that will be returned by this function

    for (uint i = 0; i < length; ++i) 
        rs += charIndex[ri[i]];
    // appends a random amount of random characters to "rs"

    //if (rs.empty()) randomString(l, charIndex); 
    // if the outcome is empty, then redo the generation (this doesn't work, help?)
    //else 
    return rs;
}

char randomColor()
{
    char szColors[] = { 'r', 'g', 'b' };
    uint uiRandIndex;

    uiRandIndex = rand() % 3;
    return szColors[uiRandIndex];
}