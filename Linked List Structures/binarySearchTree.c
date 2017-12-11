#include <stdio.h>
#include <stdlib.h>

/*

	Binary Search Tree implemented with a linked list where each node has two links.
    In a BST, the left linked node must have a lower data value than its parent,
    while the right linked node must have a higher data value than its parent.
    
    

*/

typedef struct nodes {
	int data;
	struct nodes *left, *right;
} node;

node* initBST() {
	node* newTop = NULL;
	return newTop;
}

void insert(node** tree, int value) {
	if (*tree == NULL) {
		*tree = (node*)malloc(sizeof(node));
		(*tree)->data = value;
		(*tree)->left = NULL;
		(*tree)->right = NULL;
	}
	else if ((*tree)->data>value) {
		if ((*tree)->left == NULL) {
			(*tree)->left = (node*)malloc(sizeof(node));
			(*tree)->left->data = value;
			(*tree)->left->left = NULL;
			(*tree)->left->right = NULL;
		}
		else
			insert(&((*tree)->left), value);
	}
	else {
		if ((*tree)->right == NULL) {
			(*tree)->right = (node*)malloc(sizeof(node));
			(*tree)->right->data = value;
			(*tree)->right->left = NULL;
			(*tree)->right->right = NULL;
		}
		else
			insert(&((*tree)->right), value);
	}
}

void preOrder(node* tree) {
	if (tree == NULL)
		return;
	printf("%d ", tree->data);
	preOrder(tree->left);
	preOrder(tree->right);
	
}

void inOrder(node* tree) {
	if (tree == NULL)
		return;
	inOrder(tree->left);
	printf("%d ", tree->data);
	inOrder(tree->right);
}

void postOrder(node* tree) {
	if (tree == NULL)
		return;
	postOrder(tree->left);
	postOrder(tree->right);
	printf("%d ", tree->data);
}

