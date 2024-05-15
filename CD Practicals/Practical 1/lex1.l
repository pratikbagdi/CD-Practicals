%{
#include <stdio.h>
int yywrap(void); // consistent declaration
%}

%%
^[ab]*abb$   { printf("Valid string: %s\n", yytext); }
.            { printf("Invalid string: %s\n", yytext); }
%%

int yywrap(void) {
    return 1; // Indicate no more input files
}

int main(int argc, char **argv) {
    yylex();
    return 0;
}
