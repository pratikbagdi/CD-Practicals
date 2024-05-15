#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

// Function prototypes
void E();
void match(char expected);

// Global variables
char input[MAX_LEN];
int current = 0;

// Function to parse the non-terminal E
void E() {
    if (input[current] == '+') {
        match('+');
        E();
        E();
    } else if (input[current] == '-') {
        match('-');
        E();
        E();
    } else if (input[current] == 'a') {
        match('a');
    } else if (input[current] == 'b') {
        match('b');
    } else {
        printf("The input string is not valid according to the grammar.\n");
        exit(1);
    }
}

// Function to match the current input character with the expected character
void match(char expected) {
    if (input[current] == expected) {
        current++;
    } else {
        printf("The input string is not valid according to the grammar.\n");
        exit(1);
    }
}

int main() {
    printf("Enter an expression: ");
    scanf("%s", input);

    E(); // Start parsing from the start symbol E

    if (input[current] == '\0') {
        printf("The input string is valid according to the grammar.\n");
    } else {
        printf("The input string is not valid according to the grammar.\n");
    }

    return 0;
}
