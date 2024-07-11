#include <stdio.h>

/*
    Get a main string and sub string. Check the sub string in main string
    an print the position.

    E.g.: string : hellosurabee
    substring : sura
    Answer : 6
*/
#define STRING_LEN 100

char get_substr(char const *string, char const *substring);

int main() {
    char string[STRING_LEN];
    char substring[STRING_LEN];
    char substrPosition = 0;
    printf("Enter a string: ");
    scanf("%s", string);
    printf("Enter a substring to find: ");
    scanf("%s", substring);
    substrPosition = get_substr(string, substring);
    if (substrPosition != -1) {
        printf("Position: %u\n", substrPosition);
    } else {
        printf("Substirng %s not found in %s.\n", substring, string);
    }
}

char get_substr(char const *string, char const *substring) {
    char position = 1;
    const char *strPtr;
    const char *substrPtr;
    for (strPtr = string; *strPtr; strPtr++) {
        substrPtr = substring;
        while(*strPtr && *substrPtr && (*strPtr == *substrPtr)) {
            strPtr++;
            substrPtr++;
        }
        if (!*substrPtr) {
            return position;
        }

        position++;
    }

    return -1;
}