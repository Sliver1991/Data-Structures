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

typedef struct binarySearchTree {
	node** top;
} BST;

BST initBST() {
    BST newTree;
    newTree->top = NULL;
}

node* initNode(int data) {
	node* newNode = malloc(sizeof(node));
	newNode->data = data;
	return newNode;
}
