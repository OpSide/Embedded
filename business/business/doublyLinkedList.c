#include "doublyLinkedList.h"
#include "doubly_list.h"
//Creates a new Node and returns pointer to it.
struct Node* GetNewNode(user x) {
	struct Node* newNode
		= (struct Node*)malloc(sizeof(struct Node));
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

//Inserts a Node at head of doubly linked list
void InsertAtHead(struct Node ** head, user x) {
	struct Node* newNode = GetNewNode(x);
	if (*head == NULL) {
		*head = newNode;
		return;
	}
	(*head)->prev = newNode;
	newNode->next = *head;
	*head = newNode;
}

//Inserts a Node at tail of Doubly linked list
void InsertAtTail(struct Node ** head, user x) {
	struct Node* temp = *head;
	struct Node* newNode = GetNewNode(x);
	if (*head == NULL) {
		*head = newNode;
		return;
	}
	while (temp->next != NULL) temp = temp->next; // Go To last Node
	temp->next = newNode;
	newNode->prev = temp;
}

//Prints all the elements in linked list in forward traversal order
void Print(list lst) {
	node* temp = lst.head;
	printf("\n");
	while (temp != NULL) {
		//printf("%5d %30s %30s %10d %30s\n", temp->data.id, temp->data.artistName, temp->data.albumName, temp->data.trackNo, temp->data.trackName);
		printf("%-15s %-15s %-15s  %-1d\n", temp->data.userName, temp->data.password, temp->data.fullName, temp->data.level);

		temp = temp->next;
	}
	printf("\n");
}

////Prints all elements in linked list in reverse traversal order.
//void ReversePrint(struct Node ** head) {
//	struct Node* temp = *head;
//	if (temp == NULL) return; // empty list, exit
//							  // Going to last Node
//	while (temp->next != NULL) {
//		temp = temp->next;
//	}
//	// Traversing backward using prev pointer
//	printf("Reverse: ");
//	while (temp != NULL) {
//		printf("%5d %30s %30s %10d %30s\n", temp->data.id, temp->data.artistName, temp->data.albumName, temp->data.trackNo, temp->data.trackName);
//		temp = temp->prev;
//	}
//	printf("\n");
//}

//Release node
void releaseNode(struct Node **head)
{
	struct Node *temp;
	while (*head != NULL)
	{
		temp = *head;
		(*head) = (*head)->next;
		free(temp);
	}
}

//Delete Node
void deleteNode(struct Node **deletedNode)
{
	struct Node *prev, *next;

	prev = (*deletedNode)->prev;
	next = (*deletedNode)->next;

	(*deletedNode)->prev = NULL;
	(*deletedNode)->next = NULL;
	releaseNode(deletedNode);

	if (prev != NULL) prev->next = next;
	if (next != NULL) next->prev = prev;
}

// Swap two nodes in dll
void Swap(struct Node* node1, struct Node* node2, struct Node** head)
{
	if (node1 == node2) return;

	if (*head == node1)
		*head = node2;
	else if (*head == node2)
		*head = node1;

	if (node1->next == node2)
	{
		// right next to each other
		node1->next = node2->next;
		node2->prev = node1->prev;

		if (node1->next != NULL) node1->next->prev = node1;
		if (node2->prev != NULL) node2->prev->next = node2;

		node2->next = node1;
		node1->prev = node2;
	}

	else if (node2->next == node1)
	{
		// right next to each other
		node2->next = node1->next;
		node1->prev = node2->prev;

		if (node2->next != NULL) node2->next->prev = node2;
		if (node1->prev != NULL) node1->prev->next = node1;

		node1->next = node2;
		node2->prev = node1;
	}

	else
	{
		struct Node* p = node2->prev;
		struct Node* n = node2->next;

		node2->prev = node1->prev;
		node2->next = node1->next;

		node1->prev = p;
		node1->next = n;

		if (node2->next != NULL) node2->next->prev = node2;
		if (node2->prev != NULL) node2->prev->next = node2;
		if (node1->next != NULL) node1->next->prev = node1;
		if (node1->prev != NULL) node1->prev->next = node1;
	}
}

//Get length of node
int get_length(struct Node *head)
{
	int res;

	res = 0;

	while (head != NULL)
	{
		res++;
		head = head->next;
	}

	return res;
}