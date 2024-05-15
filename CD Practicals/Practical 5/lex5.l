%{
#include <stdio.h>
#include <stdlib.h>
%}

%%
"+"     { return '+'; }
"-"     { return '-'; }
"a"     { return 'a'; }
"b"     { return 'b'; }
"|"     { return '|'; }
\n      { return '\n'; }
.       { fprintf(stderr, "Invalid character: %c\n", yytext[0]); exit(1); }
%%

int lookahead;

void match(int token) {
    if (lookahead == token)
        lookahead = yylex();
    else {
        fprintf(stderr, "Parsing unsuccessful\n");
        exit(1);
    }
}

void E();
void E1();

void E() {
    if (lookahead == 'a' || lookahead == 'b') {
        printf("E -> %c\n", lookahead);
        match(lookahead);
    }
    else if (lookahead == '+' || lookahead == '-') {
        printf("E -> %c\n", lookahead);
        match(lookahead);
        E();
        E1();
    }
    else {
        fprintf(stderr, "Syntax error\n");
        exit(1);
    }
}

void E1() {
    if (lookahead == 'a' || lookahead == 'b' || lookahead == '+' || lookahead == '-') {
        E();
        E1();
    }
}

int yywrap() {
    return 1; // Indicate that there are no more files to scan
}

int main() {
    lookahead = yylex();
    E();
    if (lookahead != '\n') {
        fprintf(stderr, "Parsing unsuccessful\n");
        exit(1);
    }
    printf("Parsing successful\n");
    return 0;
}
