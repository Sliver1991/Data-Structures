/*

	Base linked list structure is used across several other data type structures

*/

typedef struct nodes {
	int data;
	struct nodes* next;
} node;

typedef struct linkedLists {
	node** top;
} linkedList;

