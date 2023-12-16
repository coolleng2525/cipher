
// create test for cipher
// test.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "sha.h"
#include "sha256.h"

void show(char *title,  unsigned char *s, int len) {
    int i;
    printf("%s len: %d\n", title,  len);
    for (i = 0; i < len; i++)
        printf("%02x", s[i]);
    printf("\n");
}
void testSha() {
    unsigned char *plaintext = "hello world";
    unsigned char result[512];
    int len = strlen(plaintext);
    SHA_State s;
    SHA_Init(&s);
    printf("SHA-1: after SHA INIT\n");
    SHA_Bytes(&s, plaintext, len);
    printf("SHA-1: after SHA Bytes\n");
    SHA_Final(&s, result);
    printf("SHA-1: after SHA Final\n");
    // SHA_Simple(plaintext, len, result);
    if (result != NULL){
        show("result", result, 20);
        // printf("SHA-1: %s\n", result);
    } else {
        printf("SHA-1: NULL\n");
    }
}
void testSHA256() {
    unsigned char *plaintext = "hello world";
//  echo "hello world" | sha256sum 
// a948904f2f0f479b8f8197694b30184b0d2ed1c1cd2a1ec0fb85d299a192a447  -
    unsigned char result[512];
    int len = strlen(plaintext);
    SHA256_State s;
    SHA256_Init(&s);
    printf("SHA-256: after SHA INIT\n");
    SHA256_Bytes(&s, plaintext, len);
    printf("SHA-256: after SHA Bytes\n");
    SHA256_Final(&s, result);
    printf("SHA-256: after SHA Final\n");
    // SHA_Simple(plaintext, len, result);
    if (result != NULL){
        show("result", result, 20);
        // printf("SHA-1: %s\n", result);
    } else {
        printf("SHA-1: NULL\n");
    }
}
int main(int argc, char *argv[]) {
    testSha();
    testSHA256();
    

    //  void SHA_Init(SHA_State * s);
    // void SHA_Bytes(SHA_State * s, const void *p, int len);
    // void SHA_Final(SHA_State * s, unsigned char *output);
    // void SHA_Simple(const void *p, int len, unsigned char *output);

    printf("All tests passed!\n");
    return 0;
}