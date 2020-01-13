typedef struct user
{
	char userName[16];
	char fullName[16];
	char password[16];
	int level;
}user;

typedef struct ticket
{
	int carNumber;
	int status;
	char color[16];
	char model[16];
	char date[15];
}ticket;

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

void initList(listUsers *lst);

int isEmpty(listUsers *lst);

int length(listUsers *lst);

nodeUser* allocItemUser(user value);

nodeUser* getLinkByIndex(listUsers *lst, int idx);

int insertFirst(listUsers *lst, nodeUser *item);

int insertLast(listUsers *lst, nodeUser *item);

int deleteFirst(listUsers *lst);

int deleteLast(listUsers *lst);

int deleteLink(listUsers *lst, nodeUser *link);

int insertAfter(listUsers *lst, nodeUser *item, nodeUser *link);

int insertBefore(listUsers *lst, nodeUser *item, nodeUser *link);
