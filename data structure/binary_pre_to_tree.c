#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to construct BST from pre-order traversal sequence
struct TreeNode* constructBST(int preOrder[], int *index, int minValue, int maxValue, int size) {
    if (*index >= size) {
        return NULL;
    }

    int value = preOrder[*index];
    
    if (value < minValue || value > maxValue) {
        return NULL;
    }

    struct TreeNode* root = createNode(value);
    (*index)++;

    root->left = constructBST(preOrder, index, minValue, value - 1, size);
    root->right = constructBST(preOrder, index, value + 1, maxValue, size);

    return root;
}

// In-order traversal to verify the constructed BST
void inOrderTraversal(struct TreeNode* root) {
    if (root) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

int main() {
    int preOrder[] = {8, 5, 1, 7, 10, 12};
    int size = sizeof(preOrder) / sizeof(preOrder[0]);
    int index = 0;
    
    struct TreeNode* bstRoot = constructBST(preOrder, &index, INT_MIN, INT_MAX, size);

    printf("In-order Traversal of Constructed BST: ");
    inOrderTraversal(bstRoot);
    printf("\n");

    return 0;
}