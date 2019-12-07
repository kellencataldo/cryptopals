#include "SingleByteXorCipher.h"
#include "Hex.h"
#include <stdio.h>


char* hexStringToAsciiString(const char* hexString, const size_t hexStringLength) {
    if(hexString == NULL || hexStringLength == 0 || hexStringLength % 2 == 1) {
        return NULL;
    }

    char* asciiString = (char*) calloc((hexStringLength / 2)  + 1, sizeof(char));
    if(asciiString == NULL) {
        return NULL;
    }

    for(size_t hexIndex = 0; hexIndex < hexStringLength; hexIndex+=2) {
        asciiString[hexIndex/2] = (char)((asciiToHex(hexString[hexIndex])*0x10) + asciiToHex(hexString[hexIndex+1]));
    }

    return asciiString;
}

char singleByteXorCipher(const char* xoredHexString, const size_t xoredHexStringLength) {

    return 'a';
}
