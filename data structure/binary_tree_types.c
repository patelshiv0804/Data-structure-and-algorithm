#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node * right;
};

struct node* createnode(int data){
    struct node* n=(struct node *)malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;  };

void preOrder(struct node* root){
    if(root!=NULL){
        printf(" %d",root->data);
        preOrder(root->left);
        preOrder(root->right);} }

void postOrder(struct node* root){
    if(root!=NULL){
        // printf(" %d",root->data);
        postOrder(root->left);
        postOrder(root->right);
        printf(" %d",root->data);} }

void InOrder(struct node* root){
    if(root!=NULL){
        // printf(" %d",root->data);
        InOrder(root->left);
        printf(" %d",root->data);
        InOrder(root->right);} }

int main(){
    struct node *p = createnode(2);
    struct node *p1 = createnode(3);
    struct node *p2 = createnode(4);
    struct node *p3 = createnode(5);
    struct node *p4 = createnode(6); 

    p->left=p1;
    p->right=p2;
    
    p1->left=p3;
    p1->right=p4;
    
    printf("preorder:");
    preOrder(p); 
    printf("\npostorder:");
    postOrder(p);
    printf("\nInorder:");
    InOrder(p);
    
    return 0;
}
