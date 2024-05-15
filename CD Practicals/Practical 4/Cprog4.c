#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 20

int main() {
    char pro[SIZE], alpha[SIZE], beta[SIZE];
    int nonterminal, i, j, index = 5; // index adjusted for ' -> '
    printf("Enter the production as E -> E|a:");
    scanf("%s", pro);
    nonterminal = pro[0];
    if (nonterminal == pro[index]) {
        int alphaIndex = 0, betaIndex = 0;
        int isAlpha = 1; // Flag to differentiate between alpha and beta
        for (i = index + 3; pro[i] != '\0'; i++) {
            if (pro[i] == '+') {
                isAlpha = 0; // Beta part starts after '+'
                continue;
            }
            if (pro[i] == '|') {
                alpha[alphaIndex] = '\0';
                isAlpha = 1; // Reset flag for next term after '|'
                alphaIndex = 0;
                continue;
            }
            if (isAlpha) {
                alpha[alphaIndex++] = pro[i];
            } else {
                beta[betaIndex++] = pro[i];
            }
        }
        alpha[alphaIndex] = '\0';
        beta[betaIndex] = '\0';

        printf("\nGrammar without left recursion:\n\n");
        printf("%c->%s%c'\n", nonterminal, beta, nonterminal);
        printf("%c->%s%c'\n", nonterminal, alpha, nonterminal);
    } else {
        printf("\nThis grammar is not left recursion.\n");
    }
    return 0;
}
