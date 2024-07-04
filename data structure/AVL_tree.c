#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node*left;
    struct node*right;
    int height;
};

struct node* createnode(int data){
    struct node *n= (struct node*)malloc(sizeof(struct node));
    n->data=data;
    n->left= NULL;
    n->right=NULL;
    n->height=1;
    return n;
}

int max (int a, int b){
    return (a>b)?a:b;
}

int getheight(struct node * n){
    if (n== NULL){
        return 0;
    }
    return n->height;
}

int getbalancefactor(struct node* n){
    if(n== NULL) {
        return 0;
    }
    return getheight(n->left)-getheight(n->right);
}

struct node *rightrotate(struct node* y){
 struct node* x = y->left;
 struct node* T2= x->right;

 x->right=y;
 y->left=T2;

 y->height=max(getheight(y->left),getheight(y->right))+1;
 x->height=max(getheight(x->left),getheight(x->right))+1;

 return x;   //because after left rotation our root node is x
}

struct node *leftrotate(struct node* x){
 struct node* y = x->right;
 struct node* T2= y->left;

 x->right=T2;
 y->left=x;

 y->height=max(getheight(y->left),getheight(y->right))+1;
 x->height=max(getheight(x->left),getheight(x->right))+1;

 return y;  //because after right rotation our root node is y
}

struct node*insert(struct node* node,int key){
 if(node == NULL){
    return 0;
 }
 if(key > node->data){
    node->left = insert(node->left, key);
 }
 else{
    node->right=insert(node->right,key);
 }

 int bf=getbalancefactor(node);

 //left left
 if(bf>1 && key < node->left->data){ 
    rightrotate(node);
 }
 //right right
 if(bf<-1 && key > node->right->data){ 
    leftrotate(node);
 }
 //left right
 if(bf>1 && key > node->left->data){
    node->left = leftrotate(node->left);
    rightrotate(node);
 }
 //right left
 if(bf<1 && key < node->right->data){
    node->right = rightrotate(node->right);
    leftrotate(node); }

 return node;  
}

void preOrder(struct node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main(){

    struct node* root = NULL;
 
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);
    preOrder(root);
    return 0;
}


// #include <stdio.h>
// #include <stdlib.h>
 
// struct Node
// {
//     int key;
//     struct Node *left;
//     struct Node *right;
//     int height;
// };
 
// int getHeight(struct Node *n){
//     if(n==NULL)
//         return 0;
//     return n->height;
// }
 
// struct Node *createNode(int key){
//     struct Node* node = (struct Node *) malloc(sizeof(struct Node));
//     node->key = key;
//     node->left = NULL;
//     node->right = NULL;
//     node->height = 1;
//     return node;
// }
 
// int max (int a, int b){
//     return (a>b)?a:b;
// }
 
// int getBalanceFactor(struct Node * n){
//     if(n==NULL){
//         return 0;
//     }
//     return getHeight(n->left) - getHeight(n->right);
// }
 
// struct Node* rightRotate(struct Node* y){
//     struct Node* x = y->left;
//     struct Node* T2 = x->right;
 
//     x->right = y;
//     y->left = T2;
 
//     x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
//     y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
 
//     return x;
// }
 
// struct Node* leftRotate(struct Node* x){
//     struct Node* y = x->right;
//     struct Node* T2 = y->left;
 
//     y->left = x;
//     x->right = T2;
 
//     x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
//     y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
 
//     return y;
// }
 
// struct Node *insert(struct Node* node, int key){
//     if (node == NULL)
//         return  createNode(key);
 
//     if (key < node->key)
//         node->left  = insert(node->left, key);
//     else if (key > node->key)
//         node->right = insert(node->right, key);
 
//     node->height = 1 + max(getHeight(node->left), getHeight(node->right));
//     int bf = getBalanceFactor(node);
 
//     // Left Left Case
//         if(bf>1 && key < node->left->key){
//             return rightRotate(node);
//         }
//     // Right Right Case
//         if(bf<-1 && key > node->right->key){
//             return leftRotate(node);
//         }
//     // Left Right Case
//     if(bf>1 && key > node->left->key){
//             node->left = leftRotate(node->left);
//             return rightRotate(node);
//         }
//     // Right Left Case
//     if(bf<-1 && key < node->right->key){
//             node->right = rightRotate(node->right);
//             return leftRotate(node);
//         }
//     return node;
// }
 
// void preOrder(struct Node *root)
// {
//     if(root != NULL)
//     {
//         printf("%d ", root->key);
//         preOrder(root->left);
//         preOrder(root->right);
//     }
// }
 
// int main(){
//     struct Node * root = NULL;
 
 
//     root = insert(root, 1);
//     root = insert(root, 2);
//     root = insert(root, 4);
//     root = insert(root, 5);
//     root = insert(root, 6);
//     root = insert(root, 3);
//     preOrder(root);
//     return 0;
// }
