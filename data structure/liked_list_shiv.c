#include<stdio.h>
#include<stdlib.h>

struct node  {
    int data;
    struct node* next;
};

void linkedListTraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// struct node * newnode (int data){
//     struct node * newnode = (struct node*)malloc(sizeof(struct node));
//     newnode->data=data;
//     newnode->next=NULL;
//     return newnode;
// };

struct node * insertatfirst(struct node *head ,int data){
    struct node* ptr =(struct node*)malloc(sizeof(struct node));
    ptr->next=head;
    ptr->data=data;
    return  ptr;
}  

struct node * insertatlast(struct node * head,int data){
  struct node*ptr=(struct node*)malloc(sizeof(struct node));
  struct node *ptr2=head;
  ptr->data=data;

   while (ptr2!=NULL){
   ptr2=ptr2->next;
  }
  ptr2->data=ptr;
  ptr->next=NULL;
}

struct node * insertatnode(struct node* head,struct node* prevnode,int data){
 struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=prevnode->next;
    prevnode->next=ptr;
    return ptr;
}

int main(){
   struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    // Link first and second nodes
    head->data = 7;
    head->next = second;
    // Link second and third nodes
    second->data = 11;
    second->next = third;
    // Link third and fourth nodes
    third->data = 41;
    third->next = fourth;
    // Terminate the list at the third node
    fourth->data = 66;
    fourth->next = NULL;

    printf("Linked list before insertion\n");
    linkedListTraversal(head);
    // head = insertatfirst(head, 56);
    // head = insertAtIndex(head, 56, 1);
    // head = insertAtEnd(head, 56);
    // head = insertAfterNode(head, third, 45);
    // printf("\nLinked list after insertion\n");
    // linkedListTraversal(head);


//    linkedListTraversal(head);
    head = insertatfirst(head , 56);
    // head = insertAtIndex(head, 56, 1);
    head = insertatlast(head , 36);
    head = insertatnode(head, head->next->next , 45);
    printf("\nLinked list after insertion\n");
    linkedListTraversal(head);
}