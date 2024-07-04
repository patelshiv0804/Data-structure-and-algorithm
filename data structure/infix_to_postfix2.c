#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
    int top;
    int items[100];
};

void initialize(struct Stack *s) {
    s->top = -1;
}

int isEmpty(struct Stack *s) {
    return (s->top == -1);
}

int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        return -1; // Assuming -1 represents an error value
    }
    return s->items[s->top--];
}

void push(struct Stack *s, int value) {
    if (s->top == 99) {
        printf("Stack overflow\n");
        return;
    }
    s->items[++(s->top)] = value;
}

int evaluatePostfix(char *expression) {
    struct Stack stack;
    initialize(&stack);

    int length = strlen(expression);
    for (int i = 0; i < length; i++) {
        char token = expression[i];
        if (token >= '0' && token <= '9') {
            push(&stack, token - '0'); // Convert char to int
        } else if (token == '+' || token == '-' || token == '*' || token == '/') {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            int result;
            switch (token) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
            }
            push(&stack, result);
        }
    }

    return pop(&stack);
}

int main() {
    char expression[] = "22 + 2 / 5 * 7 +";
    int result = evaluatePostfix(expression);
    printf("Result: %d\n", result);

    return 0;
}