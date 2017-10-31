#ifndef CLINKLIST_H
#define CLINKLIST_H
struct CLL_Node;
typedef struct CLL_Node LL_Node;
struct CLinkList
{
	LL_Node *head;
	LL_Node *curr;
};
typedef struct CLinkList CLinkList;
//创建链表 
void cll_Create(CLinkList *linkList);

//在当前指针的后一位插入 
void cll_Insert(CLinkList *linkList, char c1, char c2);

//把指针移动到下一位 
int cll_MoveNext(CLinkList *linkList);

//输出（记得删） 
void cll_Print(CLinkList *linkList);
void cll_PrintAscll(CLinkList *linkList);

//获取数据 
int cll_GetData(CLinkList *linkList, char *pch1, char *pch2);
int cll_GetIndex(CLinkList *linkList);
void cll_SetHead(CLinkList *linkList);
#endif

