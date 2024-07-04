#include <stdio.h>

// Global variables
int stack[100];  // Array to store the stack elements
int i, j, choice = 0, n, top = -1;  // Variables for iteration, user choice, stack size, and top of the stack

// Function prototypes
void push();  // Function to push an element onto the stack
void pop();   // Function to pop an element from the stack
void show();  // Function to display the elements in the stack

// Main function
void main()
{
    // Input the number of elements in the stack
    printf("Enter the number of elements in the stack ");
    scanf("%d", &n);
    // Loop until the user chooses to exit
    while (choice != 4)
    {
        // Display the menu
        printf("Chose one from the below options...\n");
        printf("\n1.Push\n2.Pop\n3.Show\n4.Exit");
        printf("\nEnter your choice \n");
        scanf("%d", &choice);

        // Switch based on user choice
        switch (choice)
        {
            case 1:
            {
                push();  // Call the push function
                break;
            }
            case 2:
            {
                pop();   // Call the pop function
                break;
            }
            case 3:
            {
                show();  // Call the show function
                break;
            }
            case 4:
            {
                printf("Exiting....");
                break;
            }
            default:
            {
                printf("Please Enter valid choice ");
            }
        };
    }
}

// Function to push an element onto the stack
void push()
{
    int val;

    if (top == (n-1))
        printf("\n Overflow");  // Check if the stack is full
    else
    {
        printf("Enter the value?");
        scanf("%d", &val);
        top = top + 1;   // Increment top
        stack[top] = val;  // Push the value onto the stack
    }
}

// Function to pop an element from the stack
void pop()
{
    if (top == -1)
        printf("Underflow");  // Check if the stack is empty
    else
        top = top - 1;  // Decrement top to remove the top element
}

// Function to display the elements in the stack
void show()
{
    for (i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);  // Print each element in the stack
    }
    if (top == -1)
    {
        printf("Stack is empty");  // If stack is empty, print this message
    }
}
