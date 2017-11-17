#ifndef STATIS_H
#define STATIS_H
#include "CLinkList.h"
#include "bit.h"
struct FLL_Node	//²»ÒªÓÃ£¡£¡ 
{
	char c1;
	char c2;
	int num;
	Bit *huffCode;
	struct FLL_Node *next;
};
typedef struct FLL_Node FLL_Node;
struct FreLinkList
{
	FLL_Node *head;
	FLL_Node *curr;
};
typedef struct FreLinkList FreLinkList;
FreLinkList *fll_Create();
FreLinkList *sta_statis(CLinkList *fileContent);
void fll_Print(FreLinkList *linkList);
void rank(FreLinkList *linkList);
void fll_Sort(FreLinkList *freLinkList);
int fll_GetData(FreLinkList *freLinkList, char *ch1, char *ch2, long *freq);
int fll_MoveNext(FreLinkList *linkList);
int fll_SetHead(FreLinkList *freLinkList);
void fll_Sortquick(FreLinkList *freLinkList);
void fll_SetHuffCode(FreLinkList *freLinkList, char c1, char c2, Bit *bit);
Bit *fll_GetHuffCode(FreLinkList *freLinkList, char c1, char c2);
#endif
