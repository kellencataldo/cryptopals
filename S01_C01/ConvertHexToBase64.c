#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "ConvertHexToBase64.h"
#include "Hex.h"


static const char base64[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                               'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
                               'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
                               'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
                               'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
                               'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                               'w', 'x', 'y', 'z', '0', '1', '2', '3',
                               '4', '5', '6', '7', '8', '9', '+', '/' };

static const int32_t remainderMap[] = { 0, 2, 1 };


void translateChunk(const char* hexString, char* b64String, const int32_t paddingChars) {
    
    /* 
     * what is happening here: 
     *
     * chunk = 0;
     * chunk |= asciiToHex(hexString[hexIndex    ]) << 20;
     * chunk |= asciiToHex(hexString[hexIndex + 1]) << 16;
     * chunk |= asciiToHex(hexString[hexIndex + 2]) << 12;
     * chunk |= asciiToHex(hexString[hexIndex + 3]) <<  8;
     * chunk |= asciiToHex(hexString[hexIndex + 4]) <<  4;
     * chunk |= asciiToHex(hexString[hexIndex + 5]);
     *
     * b64Buffer[b64Index + 3] = base64[ chunk        & 0x3f];
     * b64Buffer[b64Index + 2] = base64[(chunk >> 6)  & 0x3f];
     * b64Buffer[b64Index + 1] = base64[(chunk >> 12) & 0x3f];
     * b64Buffer[b64Index    ] = base64[(chunk >> 18) & 0x3f];
     * */


    int32_t b64Index = 3;
    for (int32_t padding = paddingChars; 0 < padding; padding--, b64Index--) {
        b64String[b64Index] = '=';
    }

    size_t bitShift = paddingChars * 2;
    uint32_t chunk = 0;
    for (int32_t hexIndex = ((3 - paddingChars) * 2) - 1; 0 <= hexIndex; hexIndex--, bitShift+=4) {
        chunk |= asciiToHex(hexString[hexIndex]) << bitShift; // hex.h
    }

    bitShift = 0;
    while (0 <= b64Index) {
        b64String[b64Index] = base64[(chunk >> bitShift) & 0x3f];
        bitShift += 6;
        b64Index--;
    }
}


char* convertHexToBase64(const char* hexString, const size_t hexStringLength) {
    if(hexString == NULL || hexStringLength == 0 || hexStringLength % 2 == 1) {
		// @todo: error print here? idk.
        return NULL;
    }

    const size_t asciiChars = hexStringLength / 2;
    const int32_t paddingChars = remainderMap[asciiChars % 3];
    const size_t b64StringLength = ((asciiChars + paddingChars) * 4) / 3;
    char* b64String = (char*) calloc(b64StringLength + 1, sizeof(char));
    
    size_t hexIndex = 0;
    size_t b64Index = 0;

    while(b64Index < b64StringLength - 4)  {
        translateChunk(hexString + hexIndex, b64String + b64Index, 0);
        hexIndex += 6;
        b64Index += 4;
    }

    translateChunk(hexString + hexIndex, b64String + b64Index, paddingChars);
    return b64String;
}






