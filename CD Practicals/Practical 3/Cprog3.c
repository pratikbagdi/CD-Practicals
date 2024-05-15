#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char num[20];
    double decimal;
    
    printf("Enter an integer constant (in decimal, octal, hexadecimal, or floating-point format): ");
    scanf("%s", num);

    int is_negative = 0;
    if (num[0] == '-') {
        is_negative = 1;
        memmove(num, num + 1, strlen(num));
    }

    int base = 10;
    if (num[0] == '0') {
        if (num[1] == 'x' || num[1] == 'X') {
            base = 16;
            memmove(num, num + 2, strlen(num));
        }
        else if (strchr(num, '.') != NULL) {
            base = 10;
        }
        else {
            base = 8;
        }
    }

    decimal = 0;
    int i = 0;
    while (num[i] != '\0') {
        double digit;
        if (isdigit(num[i])) {
            digit = num[i] - '0';
        }
        else if (isalpha(num[i])) {
            digit = toupper(num[i]) - 'A' + 10;
        }
        else if (num[i] == '.') {
            i++;
            double factor = 0.1;
            while (num[i] != '\0') {
                digit += (num[i] - '0') * factor;
                factor *= 0.1;
                i++;
            }
            break;  // Exit the loop after processing the fractional part
        }
        else {
            printf("Invalid character: %c\n", num[i]);
            return 1;
        }

        if (digit >= base) {
            printf("Invalid digit for base %d: %c\n", base, num[i]);
            return 1;
        }
        decimal = decimal * base + digit;
        i++;
    }
    if (is_negative) {
        decimal = -decimal;
    }
    printf("The decimal equivalent of %s is %f\n", num, decimal);

    return 0;
}
