#include <string.h>

#include "external/Unity/src/unity.h"
#include "S01_C01/ConvertHexToBase64.h"


void setUp(void) { }

void tearDown(void) { }

void test_convertHexToBase64(void) {
    const char* hexString_1 =
        "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
    const char* expectedB64String_1 = "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t";
    const char* b64String_1 = convertHexToBase64(hexString_1, strlen(hexString_1));
    TEST_ASSERT_EQUAL_STRING(expectedB64String_1, b64String_1);

    const char* hexString_2 = "0123456789abcdef";
    const char* expectedB64String_2 = "ASNFZ4mrze8=";
    const char* b64String_2 = convertHexToBase64(hexString_2, strlen(hexString_2));
    TEST_ASSERT_EQUAL_STRING(expectedB64String_2, b64String_2);

    const char* hexString_3 = "69b71d79f80720928b30";
    const char* expectedB64String_3 = "abcdefgHIJKLMA==";
    const char* b64String_3 = convertHexToBase64(hexString_3, strlen(hexString_3));
    TEST_ASSERT_EQUAL_STRING(expectedB64String_3, b64String_3);
}

int main(const int nargc, const char* args[]) {
    UNITY_BEGIN();
    RUN_TEST(test_convertHexToBase64);
    return UNITY_END();
}
