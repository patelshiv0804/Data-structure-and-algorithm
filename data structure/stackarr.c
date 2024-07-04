#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isempty(struct stack *ptr)
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

int isfull(struct stack *ptr)
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

void push(struct stack *ptr, int val)
{
    if (isfull(ptr))
    {
        printf("Stack overflow\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack *ptr)
{
    if (isempty(ptr))
    {
        printf("Stack underflow\n");
        return -1; // Return a sentinel value to indicate an error.
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

void show(struct stack *ptr)
{
    if (isempty(ptr))
    {
        printf("Stack is empty\n");
    }
    else
    {
        for (int i = ptr->top; i >= 0; i--)
        {
            printf("%d\n", ptr->arr[i]);
        }
    }
}

int main()
{
    struct stack s;
    s.size = 80;
    s.top = -1;
    s.arr = (int *)malloc(s.size * sizeof(int));

    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    push(&s, 4);

    printf("Popped: %d\n", pop(&s));
    printf("Popped: %d\n", pop(&s));
    printf("Popped: %d\n", pop(&s));
    printf("Popped: %d\n", pop(&s));
    printf("Popped: %d\n", pop(&s));

    show(&s);

    free(s.arr);
    return 0;
}


