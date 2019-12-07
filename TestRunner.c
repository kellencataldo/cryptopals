#include <string.h>

#include "external/Unity/src/unity.h"
#include "S01_C01/ConvertHexToBase64.h"
#include "S01_C02/FixedXOR.h"
#include "S01_C03/SingleByteXorCipher.h"


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

void test_fixedXOR(void) {

    char* copyString_1 = "1c0111001f010100061a024b53535009181c";
    char* targetString_1 = (char*) calloc(strlen(copyString_1), sizeof(char));
    strcpy(targetString_1, copyString_1);

    const char* xorString_1 = "686974207468652062756c6c277320657965";
    const char* expectedString_1 = "746865206b696420646f6e277420706c6179";
    fixedXOR(targetString_1, xorString_1, strlen(targetString_1));
    TEST_ASSERT_EQUAL_STRING(expectedString_1, targetString_1 );

    char* copyString_2 = "aa";
    char* targetString_2 = (char*) calloc(strlen(copyString_2), sizeof(char));
    strcpy(targetString_2, copyString_2);

    const char* xorString_2 = "bb";
    const char* expectedString_2 = "11";
    fixedXOR(targetString_2, xorString_2, strlen(targetString_2));
    TEST_ASSERT_EQUAL_STRING(expectedString_2, targetString_2 );

    char* copyString_3 = "123456789abcdef";
    char* targetString_3 = (char*) calloc(strlen(copyString_3), sizeof(char));
    strcpy(targetString_3, copyString_3);

    const char* xorString_3 = "fffffffffffffff";
    const char* expectedString_3 = "edcba9876543210";
    fixedXOR(targetString_3, xorString_3, strlen(targetString_3));
    TEST_ASSERT_EQUAL_STRING(expectedString_3, targetString_3 );

}

void test_singleByteXorCipher(void) {
    singleByteXorCipher("aa", 2);
    TEST_ASSERT_EQUAL(1,1);
}

int main(const int nargc, const char* args[]) {
    UNITY_BEGIN();
    RUN_TEST(test_convertHexToBase64);
    RUN_TEST(test_fixedXOR);
    RUN_TEST(test_singleByteXorCipher);
    return UNITY_END();
}
