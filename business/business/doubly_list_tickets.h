/////////////////////////////////////
//		Copyrights (C) to	   /////
//		   January 2020		  /////
//*/ Raviv Nachum ID 311453096  //
//*/ Barak Pahima ID 203484217 //
////////////////////////////////
typedef struct ticket
{
	int carNumber;
	int status;
	int price;
	char color[16];
	char model[16];
	char date[16];
}ticket;

typedef struct nodeTickets 
{
    ticket data;	
   struct nodeTickets *next;
   struct nodeTickets *prev;
}nodeTickets;

typedef struct listTicket
{
	nodeTickets *head;
	nodeTickets *tail;
}listTicket;

void initListTickets(listTicket *lst);

int isEmptyTickets(listTicket *lst);

int lengthTickets(listTicket *lst);

nodeTickets* allocItemTickets(ticket value);

nodeTickets* getLinkByIndexTickets(listTicket *lst, int idx);

int insertFirstTickets(listTicket *lst, nodeTickets *item);

int insertLastTickets(listTicket *lst, nodeTickets *item);

int deleteFirstTickets(listTicket *lst);

int deleteLastTickets(listTicket *lst);

int deleteLinkTickets(listTicket *lst, nodeTickets *link);

int insertAfterTickets(listTicket *lst, nodeTickets *item, nodeTickets *link);

int insertBeforeTickets(listTicket *lst, nodeTickets *item, nodeTickets *link);
