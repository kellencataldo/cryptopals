#include <stdio.h>

#include "convertHexToBase64.h"


static const char base64[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                               'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
                               'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
                               'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
                               'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
                               'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                               'w', 'x', 'y', 'z', '0', '1', '2', '3',
                               '4', '5', '6', '7', '8', '9', '+', '/' };

static const size_t remainderMap[] = { 0, 2, 1 };


char* convertHexToBase64(const char* hexString, const size_t hexStringLength) {
    if(hexString == NULL || hexStringLength == 0 || hexStringLength % 2 == 1) {
	// error print here? idk.
        return NULL;
    }

    const size_t asciiChars = hexStringLength / 2;
    const size_t paddingChars = remainderMap[asciiChars % 3];
    const size_t base64Length = ((asciiChars + paddingChars) * 4) / 3;
    char* base64Buffer = (char* ) calloc(base64Length, sizeof(char));
    // SIX hex characters in -> three base64 characters out.
    // the logic is that two hex represents one ascii. 

    return base64Buffer;
}






