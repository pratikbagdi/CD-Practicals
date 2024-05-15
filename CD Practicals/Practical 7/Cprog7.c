#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

// Define a stack structure
typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

// Function to initialize the stack
void initialize(Stack *s) {
    s->top = -1;
}

// Function to push an item onto the stack
void push(Stack *s, int value) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    s->items[++(s->top)] = value;
}

// Function to pop an item from the stack
int pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->items[(s->top)--];
}

// Function to evaluate the postfix expression
int evaluatePostfix(char *expression) {
    Stack stack;
    initialize(&stack);

    for (int i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];

        if (isdigit(ch)) {
            push(&stack, ch - '0');
        } else {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);

            switch (ch) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
                default:
                    printf("Invalid postfix expression\n");
                    exit(EXIT_FAILURE);
            }
        }
    }

    if (stack.top != 0) {
        printf("Invalid postfix expression\n");
        exit(EXIT_FAILURE);
    }

    return pop(&stack);
}

int main() {
    char postfix[MAX_SIZE];
    
    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);

    return 0;
}
