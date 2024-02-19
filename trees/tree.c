#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int id;
    struct node *left;
    struct node *right;
} node; 

node *createTree(int id){
    node *newNode = (node *)malloc(sizeof(node));
    newNode->id = id;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertNode(node *root, int id){
    if ( id < root->id) {
        if ( root->left == NULL) {
            root->left = createTree(id);
        } else {
            insertNode(root->left, id);
        }
    }
    else {
        if ( root->right == NULL) {
            root->right = createTree(id);
        } else {
            insertNode(root->right, id);
        }
    }
}

void printTree(node *root, int space) {
    int i;

    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += 10;

    // Process right child first
    printTree(root->right, space);

    // Print current node after space count
    printf("\n");
    for (i = 10; i < space; i++)
        printf(" ");
    printf("%d\n", root->id);

    // Process left child
    printTree(root->left, space);
}

int main(void){

    node *root = createTree(10);
    insertNode(root, 5);
    insertNode(root, 15);
    insertNode(root, 8);
    insertNode(root, 3);
    insertNode(root, 20);
    insertNode(root, 12);
    insertNode(root, 18);
    insertNode(root, 25);
    printTree(root, 0);
    return 0;
}