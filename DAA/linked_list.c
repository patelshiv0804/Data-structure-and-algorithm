#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

// Function to create a new node with given data
struct node *createnode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

// Function to insert a node at the end of a linked list
void insertend(struct node **headRef, int data)
{
    struct node *newnode = createnode(data);
    if (*headRef == NULL)
    {
        *headRef = newnode;
        return;
    }
    struct node *temp = *headRef;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}

// Function to add two linked lists representing numbers

struct node *addlinkedlists(struct node *head1, struct node *head2)
{
    struct node *result = NULL;
    struct node *tail = NULL;
    int carry = 0, sum;

    while (head1 != NULL || head2 != NULL || carry != 0)
    {
        sum = carry;
        if (head1 != NULL)
        {
            sum += head1->data;
            head1 = head1->next;
        }
        if (head2 != NULL)
        {
            sum += head2->data;
            head2 = head2->next;
        }

        carry = sum / 10; // Calculate carry for next addition
        sum = sum % 10;   // Get the remainder as the current digit

        // Create a new node with the current digit
        struct node *newnode = createnode(sum);

        // Append the new node to the result
        if (result == NULL)
        {
            result = newnode; // result node points to first element of the answer
            tail = result;    // tail points to last element of the linked list
        }
        else
        {
            tail->next = newnode;
            tail = tail->next;
        }
    }

    return result;
}

// Function to subtract two linked lists representing numbers
struct node *subtractlinkedlists(struct node *head1, struct node *head2)
{

    struct node *result = NULL;
    struct node *tail = NULL;
    int borrow = 0, diff;

    while (head1 != NULL || head2 != NULL)
    {
        int num1 = (head1 != NULL) ? head1->data : 0;
        int num2 = (head2 != NULL) ? head2->data : 0;

        diff = num1 - num2 - borrow;

        if (diff < 0)
        {
            diff = diff + 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        struct node *newnode = createnode(diff);

        if (result == NULL)
        {
            result = newnode;
            tail = result;
        }
        else
        {
            tail->next = newnode;
            tail = tail->next;
        }

        if (head1 != NULL)
            head1 = head1->next;
        if (head2 != NULL)
            head2 = head2->next;
    }

    return result;
}

struct node *multiplylinkedlists(struct node *head1, struct node *head2)
{
    struct node *result = NULL;

    if (head1 == NULL || head2 == NULL)
        return result;

    int position = 0;

    while (head2 != NULL)
    {

        struct node *tempresult = NULL;
        struct node *temptail = NULL;

        int carry = 0;

        struct node *temphead1 = head1;
        while (temphead1 != NULL)
        {

            int product = (temphead1->data) * (head2->data) + carry;

            carry = product / 10;
            product %= 10;

            struct node *newnode = createnode(product);

            if (tempresult == NULL)
            {
                tempresult = newnode;
                temptail = tempresult;
            }
            else
            {
                temptail->next = newnode;
                temptail = temptail->next;
            }

            temphead1 = temphead1->next;
        }

        if (carry > 0)
        {
            temptail->next = createnode(carry);
        }

        for (int i = 0; i < position; i++)
        {
            struct node *zeronode = createnode(0);
            zeronode->next = tempresult;
            tempresult = zeronode;
        }

        result = addlinkedlists(result, tempresult);

        head2 = head2->next;

        position++;
    }

    return result;
}

// Function to print a linked list
void printlist(struct node *head)
{
    while (head != NULL)
    {
        printf("%d", head->data);
        head = head->next;
    }
    printf("\n");
}

void printreverse(struct node *head)
{
    if (head == NULL)
        return;

    // Recursively call printreverse for the next node
    printreverse(head->next);

    // Print the data of the current node after recursive call returns
    printf("%d", head->data);
}
int main()
{
    int num1, num2;

    printf("name: Shiv Patel\n");
    printf("Roll No: 22BCP317\n");

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    struct node *head1 = NULL;
    struct node *head2 = NULL;

    // Creating linked lists from numbers
    while (num1 > 0)
    {
        insertend(&head1, num1 % 10);
        num1 = num1 / 10;
    }

    while (num2 > 0)
    {
        insertend(&head2, num2 % 10);
        num2 = num2 / 10;
    }

    // Printing linked lists
    printf("Reversed Linked list 1: ");
    printlist(head1);
    // printf("\n");
    printf("Reversed Linked list 2: ");
    printlist(head2);
    // printf("\n");

    // Adding two linked lists
    struct node *sum = addlinkedlists(head1, head2);
    printf("Sum of the two linked lists: ");
    printreverse(sum);
    printf("\n");

    // Subtracting two linked lists
    struct node *diff = subtractlinkedlists(head1, head2);
    printf("Difference of the two linked lists: ");
    printreverse(diff);
    printf("\n");

    // Multiplying two linked lists
    struct node *mul = multiplylinkedlists(head1, head2);
    printf("Multiplication of the two linked lists: ");
    printreverse(mul);
    printf("\n");

    // Freeing allocated memory
    // Code for freeing memory...

    return 0;
}
