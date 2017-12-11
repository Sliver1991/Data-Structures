#include <stdio.h>
#include <stdlib.h>

typedef struct nodes {
	int data;
	struct nodes *left, *right, *parent;
} node;

node* initBST() {
	node* newTop = NULL;
	return newTop;
}

/*

	Binary Search Tree implemented with a linked list where each node has two links.
    In a BST, the left linked node must have a lower data value than its parent,
    while the right linked node must have a higher data value than its parent.
    
*/

void insert(node** tree, int value) {
	if (*tree == NULL) {
		*tree = (node*)malloc(sizeof(node));
		(*tree)->data = value;
		(*tree)->left = NULL;
		(*tree)->right = NULL;
        (*tree)->parent = NULL;
	}
	else if ((*tree)->data>value) {
		if ((*tree)->left == NULL) {
			(*tree)->left = (node*)malloc(sizeof(node));
			(*tree)->left->data = value;
			(*tree)->left->left = NULL;
			(*tree)->left->right = NULL;
            (*tree)->left->parent = (*tree);
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
            (*tree)->right->parent = (*tree);
		}
		else
			insert(&((*tree)->right), value);
	}
}

int treeSize(node* tree) {
    if (tree==NULL)
        return 0;
    return 1+treeSize(tree->left)+treeSize(tree->right);
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

void levelOrder(node* tree) {
    int size=treeSize(tree), i=0, j=1;
    node** nodeArr = (node**)malloc(sizeof(node*)*size);
    nodeArr[0] = tree;
    while (i<size) {
        if (nodeArr[i]->left!=NULL)
            nodeArr[j++]=nodeArr[i]->left;
        if (nodeArr[i]->right!=NULL)
            nodeArr[j++]=nodeArr[i]->right;
        printf("%d ",nodeArr[i++]->data);
    }
    free(nodeArr);
}

int maxBST(node* tree) {
    while (tree->right!=NULL) 
        tree = tree->right;
    return tree->data;
}

int minBST(node* tree) {
    while (tree->left!=NULL) 
        tree = tree->left;
    return tree->data;
}

node* findValue(node* tree, int value) {
    if (tree==NULL)
        return NULL;
    if (tree->data == value)
        return tree;
    else if (tree->data > value)
        return findValue(tree->left,value);
    else
        return findValue(tree->right,value);
}

int findNext(node* tree, int val) {
    node* value = findValue(tree,val);
    if (value==NULL)
        return val;
    if (value->right!=NULL)
        return minBST(value->right);
    else {
        node* parent = value->parent;
		while ((parent != NULL) && (parent->left != value)) {
			value = parent;
			parent = value->parent;
		}
        if (parent==NULL)
            return val;
        return parent->data;
    }
}

