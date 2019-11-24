#include "FixedXOR.h"
#include "Hex.h"


void fixedXOR(char* targetBuffer, const char* xorBuffer, const size_t bufferLength) {
    for (size_t index = 0; index < bufferLength; index++) {
        targetBuffer[index] = hexToAscii(asciiToHex(targetBuffer[index]) ^ asciiToHex(xorBuffer[index]));
    }
}
