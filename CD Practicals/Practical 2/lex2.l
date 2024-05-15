%{
#include <stdio.h>
%}

%option noyywrap

DIGIT [0-9]
HEX_DIGIT [0-9a-fA-F]
FLOAT_SUFFIX [fF]|[lL]

%%
[a-zA-Z_][a-zA-Z0-9_]*                    printf("Valid Identifier: %s\n", yytext);
0|[+-]?[1-9][0-9]*                        printf("Decimal Integer Constant: %s\n", yytext);			
0[0-7]+                                   printf("Octal Integer Constant: %s\n", yytext);
0[xX]{HEX_DIGIT}+                         printf("Hexadecimal Integer Constant: %s\n", yytext);
[+-]?{DIGIT}+"."{DIGIT}+{FLOAT_SUFFIX}?   printf("Floating Point Constant: %s\n", yytext);
"."{DIGIT}+{FLOAT_SUFFIX}?                printf("Floating Point Constant: %s\n", yytext);
[+-]?{DIGIT}+"."{DIGIT}+[eE][+-]?{DIGIT}+ printf("Exponential Format Constant: %s\n", yytext);
.|.[a-zA-Z0-9_]*|{DIGIT}[a-zA-Z0-9_]*     printf("Invalid Identifier: %s\n", yytext);
%%

int main() {
    yylex();
    return 0;
}
