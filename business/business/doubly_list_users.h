/////////////////////////////////////
//		Copyrights (C) to	   /////
//		   January 2020		  /////
//*/ Raviv Nachum ID 311453096  //
//*/ Barak Pahima ID 203484217 //
////////////////////////////////
typedef struct user
{
	char userName[16];
	char fullName[16];
	char password[16];
	int level;
}user;


typedef struct nodeUser 
{
    user data;	
   struct nodeUser *next;
   struct nodeUser *prev;
}nodeUser;

typedef struct listUsers
{
	nodeUser *head;
	nodeUser *tail;
}listUsers;

void initListUsers(listUsers *lst);

int isEmptyUsers(listUsers *lst);

int lengthUsers(listUsers *lst);

nodeUser* allocItemUser(user value);

nodeUser* getLinkByIndexUsers(listUsers *lst, int idx);

int insertFirstUsers(listUsers *lst, nodeUser *item);

int insertLastUsers(listUsers *lst, nodeUser *item);

int deleteFirstUsers(listUsers *lst);

int deleteLastUsers(listUsers *lst);

int deleteLinkUsers(listUsers *lst, nodeUser *link);

int insertAfterUsers(listUsers *lst, nodeUser *item, nodeUser *link);

int insertBeforeUsers(listUsers *lst, nodeUser *item, nodeUser *link);
