#ifndef STATIS_H
#define STATIS_H
#include "CLinkList.h"
struct FLL_Node
{
	char c1;
	char c2;
	int num;
	struct FLL_Node *next;
};
typedef struct FLL_Node FLL_Node;
struct FreLinkList
{
	FLL_Node *head;
	FLL_Node *curr;
};
typedef struct FreLinkList FreLinkList;
void sta_statis(FreLinkList *linkList, CLinkList *fileContent);
void fll_Print(FreLinkList *linkList);
void rank(FreLinkList *linkList);
void fll_Sort(FreLinkList *freLinkList);
#endif
