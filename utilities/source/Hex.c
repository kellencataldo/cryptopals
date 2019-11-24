char asciiToHex(const char ascii) {
    if ('0' <= ascii && '9' >= ascii) {
        return ascii - '0';
    }
    
    return (ascii - 'a') + 10;
}


char hexToAscii(const char hex) {
    if (10 > hex) {
        return hex + '0';
    }

    return (hex - 10) + 'a';
}

