
// #include <stdio.h>
// #include <malloc.h>

// struct node {
//     int data;
//     struct node* left;
//     struct node* right;
// };

// struct node* createNode(int data) {
//     struct node* n = (struct node*)malloc(sizeof(struct node));
//     n->data = data;
//     n->left = NULL;
//     n->right = NULL;
//     return n;
// }

// void preOrder(struct node* root) {
//     if (root != NULL) {
//         printf("%c ", (char)root->data);
//         preOrder(root->left);
//         preOrder(root->right);
//     }
// }

// void postOrder(struct node* root) {
//     if (root != NULL) {
//         postOrder(root->left);
//         postOrder(root->right);
//         printf("%c ", (char)root->data);
//     }
// }

// void inOrder(struct node* root) {
//     if (root != NULL) {
//         inOrder(root->left);
//         printf("%c ", (char)root->data);
//         inOrder(root->right);
//     }
// }

// int main() {
//     struct node* p = createNode(61);  // ASCII for 'a'
//     struct node* p1 = createNode(62); // ASCII for 'b'
//     struct node* p2 = createNode(63); // ASCII for 'c'
//     struct node* p3 = createNode(64); // ASCII for 'd'
//     struct node* p4 = createNode(65); // ASCII for 'e'
//     struct node* p5 = createNode(66); // ASCII for 'f'
//     struct node* p6 = createNode(67); // ASCII for 'g'
//     struct node* p7 = createNode(68); // ASCII for 'h'
//     struct node* p8 = createNode(69); // ASCII for 'i'

//     p->left = p1;
//     p->right = p2;
//     p1->left = p3;
//     p2->left = p4;
//     p2->right = p5;
//     p4->right = p6;
//     p5->left = p7;
//     p5->right = p8;

//     printf("Inorder Traversal: ");
//     inOrder(p);
//     printf("\n");

//     printf("Preorder Traversal: ");
//     preOrder(p);
//     printf("\n");

//     printf("Postorder Traversal: ");
//     postOrder(p);
//     printf("\n");

//     return 0;
// }

#include <stdio.h>
#include <malloc.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void preOrder(struct node* root) {
    if (root != NULL) {
        printf("%c ", (char)root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%c ", (char)root->data);
    }
}

void inOrder(struct node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%c ", (char)root->data);
        inOrder(root->right);
    }
}

int main() {
    struct node* p = createNode(97);  // ASCII for 'a'
    struct node* p1 = createNode(98); // ASCII for 'b'
    struct node* p2 = createNode(99); // ASCII for 'c'
    struct node* p3 = createNode(100); // ASCII for 'd'
    struct node* p4 = createNode(101); // ASCII for 'e'
    struct node* p5 = createNode(102); // ASCII for 'f'
    struct node* p6 = createNode(103); // ASCII for 'g'
    struct node* p7 = createNode(104); // ASCII for 'h'
    struct node* p8 = createNode(105); // ASCII for 'i'

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p2->left = p4;
    p2->right = p5;
    p4->right = p6;
    p5->left = p7;
    p5->right = p8;

    printf("Inorder Traversal: ");
    inOrder(p);
    printf("\n");

    printf("Preorder Traversal: ");
    preOrder(p);
    printf("\n");

    printf("Postorder Traversal: ");
    postOrder(p);
    printf("\n");

    return 0;
}

