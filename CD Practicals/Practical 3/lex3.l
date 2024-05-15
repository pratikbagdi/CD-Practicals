%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
%}

%option noyywrap

DIGIT [1-9]
HEX_DIGIT [0-9a-fA-F]
%%
0|[+-]?[1-9][0-9]* {
    int decimal = atoi(yytext);
    printf("Decimal: %d\n", decimal);
}

-?0[0-7]+ {
    int octal = strtol(yytext, NULL, 8);
    printf("Decimal: %d\n", octal);
}

-?0[xX]{HEX_DIGIT}+ {
    int hexadecimal = strtol(yytext, NULL, 16);
    printf("Decimal: %d\n", hexadecimal);
}


%%

int main() {
    yylex();
    return 0;
}

int my_wrap() {
    return 1; // Indicate no more input
}
