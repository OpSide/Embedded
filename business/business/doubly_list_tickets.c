/////////////////////////////////////
//		Copyrights (C) to	   /////
//		   January 2020		  /////
//*/ Raviv Nachum ID 311453096  //
//*/ Barak Pahima ID 203484217 //
////////////////////////////////
#include <stdlib.h>
#include "doubly_list_tickets.h"

void initListTickets(listTicket *lst)
{
	lst->head = lst->tail = NULL;	
}

//is listTicket empty
int isEmptyTickets(listTicket *lst)
{
	return lst->head == NULL;
}

//return amount of nodes in the listTicket
int lengthTickets(listTicket *lst)
{
	int length = 0;
	nodeTickets *current;
	
	for(current = lst->head; current != NULL; current = current->next)
		length++;
	
   return length;
}

//allocate a new item
nodeTickets* allocItemTickets(ticket data)
{
	nodeTickets* item = (nodeTickets*)malloc(sizeof(nodeTickets));
	item->data = data;
	return item;
}

//nodeTickets* allocItemTicket(ticket data)
//{
//	nodeTickets* item = (nodeTickets*)malloc(sizeof(nodeTickets));
//	item->data = data;
//	return item;
//}

////return item located in spesific index
nodeTickets* getLinkByIndexTickets(listTicket *lst, int idx)
{
	int i;
	//start from the first link
	nodeTickets* link = lst->head;

	//navigate through listTicket
	for (i=0; i<idx && link != NULL ;i++)
		link = link->next;
	
	return link;
}

//insert item at the first location
int insertFirstTickets(listTicket *lst, nodeTickets *item)
{
	if (item != NULL)
	{
		//reset item pointers
		item->next = item->prev = NULL;
	
		if(isEmptyTickets(lst))
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
int insertLastTickets(listTicket *lst, nodeTickets *item)
{
	if (item != NULL)
	{
		//reset item pointers
		item->next = item->prev = NULL;
	
		if(isEmptyTickets(lst))
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
int deleteFirstTickets(listTicket *lst)
{	
	//if listTicket is empty there is nothing to delete
	if (!isEmptyTickets(lst))
	{
		//save reference to first link
		nodeTickets *temp = lst->head;

		//if only one link
		if(temp->next == NULL)
		{			
			initListTickets(lst);
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
int deleteLastTickets(listTicket *lst)
{
	//if listTicket is empty there is nothing to delete
	if (!isEmptyTickets(lst))
	{
		//save reference to last link
		nodeTickets *temp = lst->tail;

		//if only one link
		if(temp->prev == NULL)
		{
			initListTickets(lst);
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

//delete link from listTicket
int deleteLinkTickets(listTicket *lst, nodeTickets *link)
{
	if (!isEmptyTickets(lst))
	{
		if (link == NULL)
			return 0;
		if (link == lst->head)
			return deleteFirstTickets(lst);
		if (link == lst->tail)
			return deleteLastTickets(lst);

		//bypass the current link
		link->prev->next = link->next;
		link->next->prev = link->prev;
		free(link);
		return 1;
	}
	return 0;
}

//insert a new item after link
int insertAfterTickets(listTicket *lst, nodeTickets *item, nodeTickets *link)
{
	if (!isEmptyTickets(lst))
	{
		if ((item == NULL) || (link == NULL))
			return 0;
		if (link == lst->tail)
			return insertLastTickets(lst,item);

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
int insertBeforeTickets(listTicket *lst, nodeTickets *item, nodeTickets *link)
{
	if (!isEmptyTickets(lst))
	{
		if ((item == NULL) || (link == NULL))
			return 0;
		if (link == lst->head)
			return insertFirstTickets(lst,item);

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

