#include <stdlib.h>
#include "doubly_list.h"

void initList(listUsers *lst)
{
	lst->head = lst->tail = NULL;	
}

//is listUsers empty
int isEmpty(listUsers *lst)
{
	return lst->head == NULL;
}

//return amount of nodes in the listUsers
int length(listUsers *lst)
{
	int length = 0;
	nodeUser *current;
	
	for(current = lst->head; current != NULL; current = current->next)
		length++;
	
   return length;
}

//allocate a new item
nodeUser* allocItemUser(user data)
{
	nodeUser* item = (nodeUser*)malloc(sizeof(nodeUser));
	item->data = data;
	return item;
}

//nodeUser* allocItemTicket(ticket data)
//{
//	nodeUser* item = (nodeUser*)malloc(sizeof(nodeUser));
//	item->data = data;
//	return item;
//}

////return item located in spesific index
nodeUser* getLinkByIndex(listUsers *lst, int idx)
{
	int i;
	//start from the first link
	nodeUser* link = lst->head;

	//navigate through listUsers
	for (i=0; i<idx && link != NULL ;i++)
		link = link->next;
	
	return link;
}

//insert item at the first location
int insertFirst(listUsers *lst, nodeUser *item)
{
	if (item != NULL)
	{
		//reset item pointers
		item->next = item->prev = NULL;
	
		if(isEmpty(lst))
		{
			//make head & tail pointing to item
			lst->head = lst->tail = item;	
		}
		else 
		{
			//update first prev link
			lst->head->prev = item;
			//point item to old first link
			item->next = lst->head;
			//point head to new first node
			lst->head = item;
		}
		return 1;
	}
	return 0;
}

//insert item at the last location
int insertLast(listUsers *lst, nodeUser *item)
{
	if (item != NULL)
	{
		//reset item pointers
		item->next = item->prev = NULL;
	
		if(isEmpty(lst))
		{
			//make head & tail pointing to item
			lst->head = lst->tail = item;
		}
		else 
		{
			//update last next link
			lst->tail->next = item;     
			//point item to old last link
			item->prev = lst->tail;
			//point last to new last node
			lst->tail = item;
		}
		return 1;
	}
	return 0;
}

//delete first item
int deleteFirst(listUsers *lst)
{	
	//if listUsers is empty there is nothing to delete
	if (!isEmpty(lst))
	{
		//save reference to first link
		nodeUser *temp = lst->head;

		//if only one link
		if(temp->next == NULL)
		{			
			initList(lst);
		}
		else
		{
			lst->head->next->prev = NULL;
			lst->head = lst->head->next;
		}
		free(temp);
		return 1;
	}
	return 0;
}

//delete link at the last location
int deleteLast(listUsers *lst)
{
	//if listUsers is empty there is nothing to delete
	if (!isEmpty(lst))
	{
		//save reference to last link
		nodeUser *temp = lst->tail;

		//if only one link
		if(temp->prev == NULL)
		{
			initList(lst);
		}
		else
		{
			lst->tail->prev->next = NULL;
			lst->tail = lst->tail->prev;
		}
		free(temp);
		return 1;
	}
	return 0;
}

//delete link from listUsers
int deleteLink(listUsers *lst, nodeUser *link)
{
	if (!isEmpty(lst))
	{
		if (link == NULL)
			return 0;
		if (link == lst->head)
			return deleteFirst(lst);
		if (link == lst->tail)
			return deleteLast(lst);

		//bypass the current link
		link->prev->next = link->next;
		link->next->prev = link->prev;
		free(link);
		return 1;
	}
	return 0;
}

//insert a new item after link
int insertAfter(listUsers *lst, nodeUser *item, nodeUser *link)
{
	if (!isEmpty(lst))
	{
		if ((item == NULL) || (link == NULL))
			return 0;
		if (link == lst->tail)
			return insertLast(lst,item);

		//assign new item pointers
		item->prev = link;
		item->next = link->next;
		//chain link and link->next to new item
		link->next->prev = item;
		link->next = item;
		return 1;
	}
	return 0;
}

//insert a new item before link
int insertBefore(listUsers *lst, nodeUser *item, nodeUser *link)
{
	if (!isEmpty(lst))
	{
		if ((item == NULL) || (link == NULL))
			return 0;
		if (link == lst->head)
			return insertFirst(lst,item);

		//assign new item pointers
		item->next = link;
		item->prev = link->prev;
		//chain link and link->prev to new item
		link->prev->next = item;
		link->prev = item;
		return 1;
	}
	return 0;
}
//Prints all the elements in linked listUsers in forward traversal order
void Print(listUsers lst) {
	nodeUser* temp = lst.head;
	printf("\n");
	while (temp != NULL) {
		//printf("%5d %30s %30s %10d %30s\n", temp->data.id, temp->data.artistName, temp->data.albumName, temp->data.trackNo, temp->data.trackName);
		printf("%-15s %-15s %-15s  %-1d\n", temp->data.userName, temp->data.password, temp->data.fullName, temp->data.level);

		temp = temp->next;
	}
	printf("\n");
}