/*

Queue structure based on linked list. Supports Enqueue, Dequeue and isEmpty functions

*/

typedef enum { FALSE, TRUE } BOOL;

#include <stdio.h>
#include <stdlib.h>

typedef struct nodes {
	int data;
	struct nodes* next;
} node;

typedef struct queues {
	node** top;
} queue;

queue initQueue() {
	queue newQueue;
	newQueue.top = NULL;
	return newQueue;
}

node* initNode(int data) {
	node* newNode = malloc(sizeof(node));
	newNode->data = data;
	return newNode;
}


void enqueue(queue q, node* n) { //Adds new node at end of queue
	node* i = *(q.top);
	if (i!=NULL)
		while (i->next != NULL) 
			i = i->next;
	i->next = n;
}

int dequeue(queue q) { //Removes top node from queue and returns its value
	node* n = *(q.top);
	*(q.top) = (*(q.top))->next;
	n->next = NULL;
	int data = n->data;
	free(n);
	return data;
}

BOOL isEmpty(queue q) { //returns true (1) if queue is empty
	return (*(q.top) == NULL);
}