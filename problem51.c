#include <stdio.h>
#include <string.h>
/*
    Get a string and a character from the user and find all the positions
    where the character present and print it.

    E.g.: string : hellosurabee
    character : e
    Answer : 2, 11, 12
*/

#define STRING_LEN 100

void is_match(char const *string, char character);

int main() {
    char string[STRING_LEN];
    char character, count;
    printf("Enter a string: ");
    scanf("%s", string);
    printf("Enter a character to find in the string: ");
    scanf(" %c", &character);
    is_match(string, character);
}

void is_match(char const *string, char character) {
    char const *cPtr;
    char counter = 1; // counter to track each caracter iteration
    for (cPtr = string; *cPtr; cPtr++) { // cPtr = first byte of string array 
        if (*cPtr == character) { // compare cPtr data to the character
            printf("%d\n", counter);
        }
        counter++;  
    }
}