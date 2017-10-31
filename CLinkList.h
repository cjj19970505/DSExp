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
//�������� 
void cll_Create(CLinkList *linkList);

//�ڵ�ǰָ��ĺ�һλ���� 
void cll_Insert(CLinkList *linkList, char c1, char c2);

//��ָ���ƶ�����һλ 
int cll_MoveNext(CLinkList *linkList);

//������ǵ�ɾ�� 
void cll_Print(CLinkList *linkList);
void cll_PrintAscll(CLinkList *linkList);

//��ȡ���� 
int cll_GetData(CLinkList *linkList, char *pch1, char *pch2);
int cll_GetIndex(CLinkList *linkList);
void cll_SetHead(CLinkList *linkList);
#endif

