/*

	Binary Search Tree implemented with a linked list where each node has two links.
    In a BST, the left linked node must have a lower data value than its parent,
    while the right linked node must have a higher data value than its parent.
    
    

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodes {
	int data;
	struct nodes *left, *right;
} node;

node* initBST() {
    node* newTop = NULL;
    return newTop;
}

void insert(node* tree, int value) {
    if (tree->data>value) {
        if (tree->left!=NULL) {
            tree->left = malloc(sizeof(node));
            tree->left->data = value;
        }
        else
            insert(tree->left,value);
    }
    else {
        if (tree->right!=NULL) {
            tree->right = malloc(sizeof(node));
            tree->right->data = value;
        }
        else
            insert(tree->right,value);
    }
}

void preorder(node* tree) {
    if (tree==NULL)
        return;
    preorder(tree->left);
    printf("%d ",tree->data);
    preorder(tree->right);
}
