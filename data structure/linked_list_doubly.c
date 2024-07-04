// #include <stdio.h>
// #include <stdlib.h>

// struct Node {
//     int data;
//     struct Node* prev;
//     struct Node* next;
// };

// void linkedListTraversal(struct Node* ptr) {
//     while (ptr != NULL) {
//         printf("Element: %d\n", ptr->data);
//         ptr = ptr->next;
//     }
// }
// // Case 1: Insert at the beginning of the doubly linked list
// struct Node* insertAtFirst(struct Node* head, int data) {
//     struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
//     ptr->data = data;
//     ptr->prev = NULL;
//     ptr->next = head;
//     if (head != NULL) {
//         head->prev = ptr;
//     }
//     return ptr;
// }
// // Case 2: Insert at a specific index in the doubly linked list
// struct Node* insertAtIndex(struct Node* head, int data, int index) {
//     struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
//     ptr->data = data;
//     struct Node* p = head;
//     int i = 0;

//     while (i != index - 1) {
//         p = p->next;
//         i++;
//     }

//     ptr->prev = p;
//     ptr->next = p->next;
//     if (p->next != NULL) {
//         p->next->prev = ptr;
//     }
//     p->next = ptr;
//     return head;
// }
// // Case 3: Insert at the end of the doubly linked list
// struct Node* insertAtEnd(struct Node* head, int data) {
//     struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
//     ptr->data = data;
//     ptr->next = NULL;

//     if (head == NULL) {
//         ptr->prev = NULL;
//         return ptr;
//     }

//     struct Node* p = head;
//     while (p->next != NULL) {
//         p = p->next;
//     }

//     p->next = ptr;
//     ptr->prev = p;
//     return head;
// }

// // Case 4: Insert after a specific node in the doubly linked list
// struct Node* insertAfterNode(struct Node* head, struct Node* prevNode, int data) {
//     if (prevNode == NULL) {
//         printf("The previous node cannot be NULL.\n");
//         return head;
//     }

//     struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
//     ptr->data = data;
//     ptr->prev = prevNode;
//     ptr->next = prevNode->next;

//     if (prevNode->next != NULL) {
//         prevNode->next->prev = ptr;
//     }
//     prevNode->next = ptr;
//     return head;
// }

// int main() {
//     struct Node* head = NULL;

//     printf("Linked list before insertion\n");
//     linkedListTraversal(head);

//     head = insertAtFirst(head, 56);
//     head = insertAtIndex(head, 1, 1); // Insert at index 1
//     head = insertAtEnd(head, 66);
//     head = insertAfterNode(head, head, 45);

//     printf("\nLinked list after insertion\n");
//     linkedListTraversal(head);

//     return 0;
// }

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
    struct node*prev;
};
void linkedListTraversal(struct node* ptr) {
    while (ptr != NULL) {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct node* insertatfirst(struct node* head,int data){
    struct node * ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->prev=NULL;
    ptr->next=head;
    if(head->prev!= NULL){
        head->prev=ptr;
    }
    return ptr;
}

struct node* insertatlast(struct node* head , int data){
    
    struct node* ptr = (struct node*)malloc(sizeof(struct node));

    struct node *p = head;
    ptr->data = data;
    
    if(head == NULL){
        ptr->prev=NULL;
        return ptr; 
    }
    
    while(p->next != NULL){
        p = p->next ;
    }
    
    p -> next = ptr ;
    ptr -> next = NULL ;
    ptr-> prev = p;
    return head;
}

struct node * insertafternode(struct node * head,struct node * prevnode, int data){
   struct node* ptr =(struct node*)malloc(sizeof(struct node));
   
   ptr -> data = data;
   ptr -> prev = prevnode;
   ptr -> next = prevnode->next;
   
   if(prevnode->next!=NULL){
       prevnode->next->prev = ptr;
   }
   
   prevnode->next= ptr;
   return head;
   
}

int main() {
    struct Node* head = NULL;

    // printf("Linked list before insertion\n");
    // linkedListTraversal(head);

    head = insertatfirst(head, 56);
    // head = insertatfirst(head, 34);
    
    head = insertatlast(head, 66);
    head = insertafternode(head, head, 45);

    // printf("\nLinked list after insertion\n");
    linkedListTraversal(head);

    return 0;
}