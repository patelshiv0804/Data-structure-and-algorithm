// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>


// struct Stack {
//     int top;
//     char items[100];
// };


// void initialize(struct Stack *s) {
//     s->top = -1;
// }


// int isEmpty(struct Stack *s) {
//     return (s->top == -1);
// }

// void push(struct Stack *s, char c) {
//     if (s->top == 99) {
//         printf("Stack overflow\n");
//         return;
//     }
//     s->items[++(s->top)] = c;
// }

// char pop(struct Stack *s) {
//     if (isEmpty(s)) {
//         printf("Stack underflow\n");
//         return '\0'; // Assuming '\0' represents an error value
//     }
//     return s->items[(s->top)--];
// }


// int precedence(char op) {
//     if (op == '^')
//         return 3;
//     else if (op == '*' || op == '/')
//         return 2;
//     else if (op == '+' || op == '-')
//         return 1;
//     else
//         return 0;
// }


// void infixToPostfix(char *infix, char *postfix) {
//     struct Stack stack;
//     initialize(&stack);
//     int i = 0;
//     int j = 0;

//     while (infix[i] != '\0') {
//         char c = infix[i];

//         if (isalnum(c)) {
//             postfix[j++] = c;
//         } else if (c == '(') {
//             push(&stack, c);
//         } else if (c == ')') {
//             while (!isEmpty(&stack) && stack.items[stack.top] != '(') {
//                 postfix[j++] = pop(&stack);
//             }
//             if (!isEmpty(&stack) && stack.items[stack.top] != '(') {
//                 printf("Invalid expression\n");
//                 return;
//             } else {
//                 pop(&stack);
//             }
//         } else {
//             while (!isEmpty(&stack) && precedence(c) <= precedence(stack.items[stack.top])) {
//                 postfix[j++] = pop(&stack);
//             }
//             push(&stack, c);
//         }

//         i++;
//     }

//     while (!isEmpty(&stack)) {
//         postfix[j++] = pop(&stack);
//     }

//     postfix[j] = '\0';
// }

// int main() {
//     char infix[100];
//     char postfix[100];

//     printf("Enter an infix expression: ");
//     scanf("%s", infix);

//     infixToPostfix(infix, postfix);
//     printf("Postfix expression: %s\n", postfix);

//     return 0;
// }


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
struct stack
{
    int size;
    int top;
    char *arr;
};
 
int stackTop(struct stack* sp){
    return sp->arr[sp->top];
}
 
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 
void push(struct stack* ptr, char val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
 
char pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int precedence(char ch){
    if (ch== '^')
        return 3; 
    else if(ch == '*' || ch=='/')
        return 2;
    else if(ch == '+' || ch=='-')
        return 1;
    else 
        return 0;
}
 
int isOperator(char ch){
    if(ch=='+' || ch=='-' ||ch=='*' || ch=='/' || ch=='^') 
        return 1;
    else
        return 0;
}
char* infixToPostfix(char* infix){
    struct stack * sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size = 10; 
    sp->top = -1;
    sp->arr = (char *) malloc(sp->size * sizeof(char));
    char * postfix = (char *) malloc((strlen(infix)+1) * sizeof(char));
    int i=0; // Track infix traversal
    int j = 0; // Track postfix addition 
    while (infix[i]!='\0')
    {
        if(!isOperator(infix[i])){
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else{
            if(precedence(infix[i])> precedence(stackTop(sp))){
                push(sp, infix[i]);
                i++;
            }
            else{
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while (!isEmpty(sp))    
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}
int main()
{
    char * infix = "a+b*(c^d-e)^(f+g*h)";
    printf("postfix is %s", infixToPostfix(infix));
    return 0;
}
