#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;  };

struct node* createNode(int data){
    struct node *n; 
    n = (struct node *) malloc(sizeof(struct node)); 
    n->data = data;
    n->left = NULL; 
    n->right = NULL; 
    return n;       }

void insert(struct node *root, int key){
   struct node *prev = NULL;
   while(root!=NULL){
       prev = root;
       if(key==root->data){
           printf("Cannot insert %d, already in BST", key);
           return;  }
       else if(key<root->data){
           root = root->left;  }
       else{
           root = root->right;} }

   struct node* new = createNode(key);

   if(key<prev->data){
       prev->left = new;  }
   else{
       prev->right = new; } 

}

void inOrder(struct  node* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void input(){

  int data;
  struct node* ptr;
  printf("enter the value:");
  scanf("%d\n",&data);

  insert(ptr,data);

}
// ----------------------------------deleteNode--------------------------------------------

struct node *inOrderPredecessor(struct node* root){
    root = root->left;
    while (root->right!=NULL){
         root = root->right; 
        }   
    return root; 
    }

struct node *deleteNode(struct node *root, int value){
 // 1) node is leaf node 2) node is non-leaf node 3) node is root node
    struct node* iPre;
    
    if (root == NULL){
        return NULL; }
    // when node is leaf node 
    if (root->left == NULL && root->right == NULL){
        free(root);
        return NULL; }
    
    // when node is non-leaf node  
    if (value < root->data){
        root-> left = deleteNode(root->left,value);    }

    else if (value > root->data){
        root-> right = deleteNode(root->right,value);  }
    
    // when node is root
    else{
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deleteNode(root->left, iPre->data); }
    return root;
}

// ----------------------------------------search node----------------------------------------
struct node * search(struct node* root, int key){
    if(root==NULL){
        return NULL;
    }
    if(key==root->data){
        return root;
    }
    else if(key<root->data){
        return search(root->left, key);
    }
    else{
        return search(root->right, key);
    }
}

int main(){ 
    int i=0;
    while(i<5){
        input();
        i++;
    }
    // struct node * p  = createNode(5);
    // struct node * p1 = createNode(3);
    // struct node * p2 = createNode(6);
    // struct node * p3 = createNode(1);
    // struct node * p4 = createNode(4);
    
    // p->left = p1; 
    // p->right = p2; 
    // p1->left = p3;  
    // p1->right = p4;

    // insert(p, 16);
    // printf("%d\n", p->right->right->data);
    inOrder(p);
    printf("\n");
    deleteNode(p, 3);
    inOrder(p);

    struct node* n = search(p, 10);
    if(n!=NULL){
    printf("\nFound: %d", n->data); }
    else{
        printf("\nElement not found"); }
    return 0; }

