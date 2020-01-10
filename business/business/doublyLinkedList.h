/* Doubly Linked List implementation */
#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int id;
	int trackNo;
	char artistName[31];
	char albumName[31];
	char trackName[31];
} song;

typedef struct
{
	char userName[16];
	char fullName[16];
	char password[16];
	int level;
} user;

struct Node {
	user data;
	struct Node* next;
	struct Node* prev;
};

//Creates a new Node and returns pointer to it.
struct Node* GetNewNode(user x);

//Inserts a Node at head of doubly linked list
void InsertAtHead(struct Node ** head, user x);

//Inserts a Node at tail of Doubly linked list
void InsertAtTail(struct Node ** head, user x);

//Prints all the elements in linked list in forward traversal order
void Print(struct Node ** head);

//Prints all elements in linked list in reverse traversal order.
void ReversePrint(struct Node ** head);

//Release node
void releaseNode(struct Node **head);

//Delete Node
void deleteNode(struct Node **deletedNode);

// Swap two nodes in dll
void Swap(struct Node* node1, struct Node* node2, struct Node** head);

//Get length of node
int get_length(struct Node *head);
