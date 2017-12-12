#include <stdio.h>
#include <stdlib.h>

typedef struct nodes {
	int data;
	struct nodes *left, *right, *parent;
} node;


/*

	Binary Search Tree implemented with a linked list where each node has two links.
    In a BST, the left linked node must have a lower data value than its parent,
    while the right linked node must have a higher data value than its parent.
    
*/

node* initBST() { //Function initiates a blank BST
	node* newTop = NULL;
	return newTop;
}

void insert(node** tree, int value) { 
    
    //Function inserts a new node into place according to BST rules
	
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
    //Function returns size of tree
    if (tree==NULL)
        return 0;
    return 1+treeSize(tree->left)+treeSize(tree->right);
}

void preOrder(node* tree) {
    //Function prints tree in pre-order (parent-left-right)
	if (tree == NULL)
		return;
	printf("%d ", tree->data);
	preOrder(tree->left);
	preOrder(tree->right);
	
}

void inOrder(node* tree) {
    //Function prints tree in in-order (left-parent-right)
	if (tree == NULL)
		return;
	inOrder(tree->left);
	printf("%d ", tree->data);
	inOrder(tree->right);
}

void postOrder(node* tree) {
    //Function prints tree in post-order (left-right-parent)
	if (tree == NULL)
		return;
	postOrder(tree->left);
	postOrder(tree->right);
	printf("%d ", tree->data);
}

void levelOrder(node* tree) {
    //Function prints tree in level-order (top-its children-their children-etc.)
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
    //Function returns max value in tree
    while (tree->right!=NULL) 
        tree = tree->right;
    return tree->data;
}

int minBST(node* tree) {
    //Function returns min value in tree
    while (tree->left!=NULL) 
        tree = tree->left;
    return tree->data;
}

node* findValue(node* tree, int value) {
    //Function returns the node with value as data
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
    //Function returns the data of the node with the smallest value above val
    //Function returns the val itself if none is found
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

void deleteVal(node** tree, int val) {
	//Function removes node with val from BST
	node* toDelete = findValue(*tree, val);
	if (toDelete == NULL) {
		printf("%d not found.\n", val);
		return;
	}
	if ((toDelete->left == NULL) && (toDelete->right == NULL)) {
		if (toDelete->parent == NULL)
			*tree = NULL;
		else
			if (toDelete->parent->left == toDelete)
				toDelete->parent->left = NULL;
			else
				toDelete->parent->right = NULL;
		free(toDelete);
	}
	else {
		if ((toDelete->left != NULL) && (toDelete->right == NULL)) {
			if (toDelete->parent == NULL)
				*tree = toDelete->left;
			else
				if (toDelete->parent->left == toDelete) 
					toDelete->parent->left = toDelete->left;
				else
					toDelete->parent->right = toDelete->left;
			toDelete->left->parent = toDelete->parent;
			free(toDelete);
		}
		else if ((toDelete->right != NULL) && (toDelete->left == NULL)) {
			if (toDelete->parent == NULL)
				*tree = toDelete->right;
			else
				if (toDelete->parent->left == toDelete)
					toDelete->parent->left = toDelete->right;
				else
					toDelete->parent->right = toDelete->right;
			toDelete->right->parent = toDelete->parent;
			free(toDelete);
		}
		else {
			int successor = findNext(*tree, toDelete->data);
			deleteVal(tree, successor);
			toDelete->data = successor;
		}
	}
}

void freeTree(node** tree) {
	while (*tree != NULL) {
		if ((*tree)->right != NULL)
			deleteVal(tree, maxBST(*tree));
		else
			deleteVal(tree, minBST(*tree));
	}
}

