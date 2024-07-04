#include <stdio.h>
int stack[100];                     // Array to store the stack elements
int i, j, choice = 0, n, top = -1;  // Variables for iteration, user choice, stack size, and top of the stack

void push(); 
void pop();  
void show();
void top_element();

void push(){
    int val;  
  if(top==(n-1)) {                 // n is number of element in stack
    printf("overflow\n");  
  }
  else{
    printf("enter the value:");
    scanf("%d",&val);
    top=top+1;
    stack[top]=val;
  };
}

void pop(){
    if(top==-1){
        printf("the empty stack");
    }
    else{
        top = top - 1;
    };
}

void show(){
    for(i=top;i>=0;i--){
        printf("%d\n", stack[i]); }
    
    if (top == -1){
        printf("Stack is empty"); };
}

void top_element() {
    if (top == -1) {
        printf("Stack is empty\n");}
         else {
        printf("Top element: %d\n", stack[top]);}
}

int main()
{
    printf("enter the no of element in the stack:");
    scanf("%d", &n);

    while (choice != 4)
    {
        printf("1: push \n");
        printf("2: pop \n");
        printf("3: show \n");
        printf("4: top element \n");
        printf("5: exit \n");
        printf("enter the choice for stack:\n");
        scanf("\n%d", &choice);

        switch (choice)
        {
        case 1:
        {
            push();
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            show();
            break;
        }
        case 4:
        {
            top_element();
            break; }
        case 5:
        {
            printf("your are exiting....");
            break; }

        default:
        {
            printf("enter the number from 1 to 4"); }
      };
    }
    return 0;
}

