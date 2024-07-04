#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
};

void traversal(struct node*ptr)
{
    while (ptr!=NULL){
         printf("element:%d\n",ptr->data);
         ptr= ptr->next;   }         }

struct node * deletatbeginnig(struct node *head){
   struct node* ptr = head;
   head=head->next;
   free(ptr);
   return head;
}

struct node * deletatlast(struct node *head){
    struct node*ptr= head;
    struct node *ptr2=head->next;

    while(ptr2->next != NULL){
        ptr=ptr->next;
        ptr2=ptr2->next;
    }
    
    ptr->next=NULL;
    free(ptr2);
    return head;
}

struct node* deleteatindex(struct node* head,int index){
    struct node * ptr=head;
    struct node * ptr2=head->next;

    for (int i = 0; i < index-1; i++)
    {
        ptr = ptr->next;
        ptr2 = ptr2->next;
    }

    ptr->next = ptr2->next;
    free(ptr2);
    return head; 
}

struct node * deleteByValue(struct node * head, int value){
    struct node *ptr = head;
    struct node *ptr2= head->next;
    
    while(ptr2->data!=value && ptr2->next!= NULL)
    {
        ptr = ptr->next;
        ptr2 = ptr2->next;
    }
    
    if(ptr2->data == value){
        ptr->next = ptr2->next;
        free(ptr2);
    }
    return head;
}

int main()
{
    struct node *head;
    struct node *sec;
    struct node *third;
    struct node *fourth;

    head = (struct node *)malloc(sizeof(struct node));
    sec = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    // Link first and second nodes
    head->data = 3;
    head->next = sec;

    // Link second and third nodes
    sec->data = 6;
    sec->next = third;

    // Link third and fourth nodes
    third->data = 8;
    third->next = fourth;

    // Terminate the list at the third node
    fourth->data = 2;
    fourth->next = NULL;

    printf("Linked list before deletion\n");
    traversal(head);

    head = deletatbeginnig(head); // For deleting first element of the linked list
    head = deleteatindex(head, 2);
    // head = deleteByValue(head);
    printf("Linked list after deletion\n");
    traversal(head);

    return 0;
}


