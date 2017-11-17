#include<stdio.h>
#include<stdlib.h>
#include "CLinkList.h"

//Create LinkList 
struct CLL_Node
{
	char c1;
	char c2;
	struct CLL_Node *next;
};
typedef struct CLL_Node CLL_Node;
CLinkList *cll_Create()
{
	CLinkList *linkList = (CLinkList*)malloc(sizeof(CLinkList));
	CLL_Node *head = (CLL_Node*)malloc(sizeof(CLL_Node));
	head->next = NULL;
	head->c1 = -7;
	head->c2 = -83;
	linkList->head = head;
	linkList->curr=linkList->head;
	return linkList;
}
 
void cll_Insert(CLinkList *linkList, char c1, char c2)
{
	CLL_Node *node = (CLL_Node*)malloc(sizeof(CLL_Node));
	node->c1 = c1;
	node->c2 = c2;
	node->next = linkList->curr->next;
	linkList->curr->next = node;
}
int cll_MoveNext(CLinkList *linkList)
{
	if(linkList==NULL || linkList->curr->next == NULL){
		return 0;
	}
	linkList->curr = linkList->curr->next;
	return 1;
}
void cll_Print(CLinkList *linkList)
{
	CLL_Node *node=linkList->head;
	while(node!=NULL)
	{
		if(node->c1>=0){
			printf("%c",node->c1);
		}else{
			putchar(node->c1);
			putchar(node->c2);
		}
		printf("-->");
		node=node->next;
	}
}
void cll_PrintAscll(CLinkList *linkList)
{
	CLL_Node *node=linkList->head;
	while(node!=NULL)
	{
		printf("(%d, %d) ",node->c1,node->c2);
		printf("-->");
		node=node->next;
	}
}
int cll_GetData(CLinkList *linkList, char *pch1, char *pch2)
{
	if(linkList == NULL && linkList->curr == linkList->head && linkList->curr == NULL)
	{
		return 0;
	}
	*pch1 = linkList->curr->c1;
	*pch2 = linkList->curr->c2;
	return 1;
}
int cll_GetIndex(CLinkList *linkList)
{
	int i = 0;
	CLL_Node *node = linkList->head;
	while(node != NULL)
	{
		node = node->next;
		i++;
	}
}
void cll_SetHead(CLinkList *linkList)
{
	linkList->curr = linkList->head;
}




