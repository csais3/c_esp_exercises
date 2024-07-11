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

char count_char(char const *string, char character); // count selected character
char str_len(char const *string); // get length of the string

int main() {
    char string[STRING_LEN];
    char character, count;
    printf("Enter a string: ");
    scanf("%s", string);
    printf("Enter a character to find in the string: ");
    scanf(" %c", &character);

    printf("Sting: %s\tCharacter: %c\n", string, character);
    count = count_char(string, character);
    printf("The character %c is found %d times in the string %s\n", character, count, string);
}

char count_char(char const *string, char character) {
    char i = 0, count = 0; 

    //for (i = 0; i < strlen(string); i++) {
     for (i = 0; i < str_len(string); i++) {
        if (string[i] == character) // compadre if 
        count++;
    }

    return count;
}

char str_len(char const *string) {
    // get the length of string
    char len = 0;
    const char *stringPtr; // pointer get the first char of the array (string)
    for (stringPtr = string; *stringPtr; stringPtr++) { // stringPtr = first character
        len++; // jumps to next byte (next character)
    }
    return len;
}