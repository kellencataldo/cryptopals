#include <stdio.h>
#include <stdint.h>

#include "ConvertHexToBase64.h"


static const char base64[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                               'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
                               'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
                               'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
                               'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
                               'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                               'w', 'x', 'y', 'z', '0', '1', '2', '3',
                               '4', '5', '6', '7', '8', '9', '+', '/' };

static const size_t remainderMap[] = { 0, 2, 1 };

char asciiToHex(const char ascii) {
    if ('0' <= ascii && '9' >= ascii) {
        return ascii - '0';
    }
    
    return (ascii - 'a') + 10;
}


char* convertHexToBase64(const char* hexString, const size_t hexStringLength) {
	if(hexString == NULL || hexStringLength == 0 || hexStringLength % 2 == 1) {
		// error print here? idk.
		// return NULL;
    }

    const size_t asciiChars = hexStringLength / 2;
    const size_t paddingChars = remainderMap[asciiChars % 3];
    const size_t b64StringLength = ((asciiChars + paddingChars) * 4) / 3;
    char* b64Buffer = (char* ) calloc(b64StringLength + 1, sizeof(char));
    
    size_t hexIndex = 0;
    size_t b64Index = 0;
    while(b64Index <= b64StringLength - paddingChars) {
        uint32_t chunk = 0;
        chunk |= asciiToHex(hexString[hexIndex])     << 20;
        chunk |= asciiToHex(hexString[hexIndex + 1]) << 16;
        chunk |= asciiToHex(hexString[hexIndex + 2]) << 12;
        chunk |= asciiToHex(hexString[hexIndex + 3]) <<  8;
        chunk |= asciiToHex(hexString[hexIndex + 4]) <<  4;
        chunk |= asciiToHex(hexString[hexIndex + 5]);

        char a = base64[ chunk        & 0x3f];
        char b = base64[(chunk >> 6)  & 0x3f];
        char c = base64[(chunk >> 12) & 0x3f];
        char d = base64[(chunk >> 18) & 0x3f];


	    hexIndex += 6;
	    b64Index += 4;
    }

    // SIX hex characters in -> three base64 characters out.
    // the logic is that two hex represents one ascii. 

    return b64Buffer;
}






