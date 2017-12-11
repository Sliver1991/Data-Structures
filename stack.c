/*

Stack data structure is based on the linked list  structure. Supported commands are Push, Pop, Top and isEmpty.

*/

#include <stdio.h>
#include <stdlib.h>

typedef enum { FALSE, TRUE } BOOL;

typedef struct nodes {
	int data;
	struct nodes* next;
} node;

typedef struct stacks {
	node** top;
} stack;

stack initStack() {
	stack newStack;
	newStack.top = NULL;
	return newStack;
}

node* initNode(int data) {
	node* newNode = malloc(sizeof(node));
	newNode->data = data;
	return newNode;
}

void push(stack s, node* newNode) {	//push new node at top of stack
	newNode->next = *(s.top);
	*(s.top) = newNode;
}

int pop(stack s) { //removes top node from stack and returns its data
	node* newNode = *(s.top);
	*(s.top) = (*s.top)->next;
	newNode->next = NULL;
	int data = newNode->data;
	free(newNode);
	return data;
}

int top(stack s) { //returns data value of top node in stack
	return (*(s.top))->data;
}

BOOL isEmpty(stack s) { //returns true (1) if stack is empty
	return (*(s.top) == NULL);
}