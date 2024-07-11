#include <stdio.h>
/*
    Get a string using gets function and count all the words in it.

    E.g.: string : Welcome to ECEN Academy
    Answer : 4
*/
int word_counter(char const *string);
char str_len(char const *string);

#define STRING_LEN 100

int main() {
    char string[STRING_LEN];

    printf("Enter a string to count the words: ");
    fgets(string,STRING_LEN, stdin);
    int wordCount = word_counter(string);
    printf("The string %s has %u words\n", string, wordCount);
    
}

int word_counter(char const *string) {
    char spaceChar = ' ';
    char const *character = string;
    int wordCount = 1;
    while (*character != '\0') {

        if (*character == spaceChar) {
            wordCount++;
        }
        character++;
    }

    return wordCount;
}
