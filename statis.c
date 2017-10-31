#include<stdio.h>
#include<stdlib.h>
#include "statis.h"
#include "CLinkList.h"
//结构体定义 ,存字 

//Create LinkList 
void fll_Create(FreLinkList *linkList)
{
	FLL_Node *head = (FLL_Node*)malloc(sizeof(FLL_Node));
	head->next = NULL;
	head->c1 = 0;
	head->c2 = 0;
	head->num = 0;
	linkList->head = head;
	linkList->curr = linkList->head;
}
 //插入数据 *****************************************************需改，改为插入已知数据 
 void fll_Insert(FreLinkList *linkList, char c1, char c2, long count)
{
	FLL_Node *node = (FLL_Node*)malloc(sizeof(FLL_Node));
	node->c1 = c1;
	node->c2 = c2;
	node->num = count; 
	node->next = linkList->curr->next;
	linkList->curr->next = node;
}
//指针移到下一个结点 
int fll_MoveNext(FreLinkList *linkList)
{
	if(linkList->curr->next == NULL){
		return 0;
	}
	linkList->curr = linkList->curr->next;
	return 1;
}
//打印出链表数据 
void fll_Print(FreLinkList *linkList)
{
	FLL_Node *node=linkList->head;
	while(node!=NULL)
	{
		if(node->c1>=0){
			printf("%c",node->c1);
		}else{
			putchar(node->c1);
			putchar(node->c2);
		}
		printf("||频数：%d",node->num);
		printf("\n");
		node=node->next;
	}
}
//打印出ASCLLm码 
void fll_PrintAscll(FreLinkList *linkList)
{
	FLL_Node *node=linkList->head;
	while(node!=NULL)
	{
		printf("(%d, %d) ",node->c1,node->c2);
		printf("\n");
		node=node->next;
	}
}
long fll_GetSize(FreLinkList *freLinkList)
{
	long count = 0;
	FLL_Node *gsCurr = freLinkList->head;
	while(gsCurr->next!=NULL)
	{
		gsCurr = gsCurr->next;
		count++;
	}
	return count;
}
void fll_exangeContent(FLL_Node *node1, FLL_Node *node2)
{
	FLL_Node *node1next = node1->next;
	FLL_Node *node2next = node2->next;
	FLL_Node temp = *node1;
	*node1 = *node2;
	*node2 = temp;
	node1->next=node1next;
	node2->next=node2next;
}
int fll_GetData(FreLinkList *freLinkList, char *ch1, char *ch2, long *freq)
{
	if(freLinkList->curr == NULL)
	{
		return 0;
	}
	*ch1 = freLinkList->curr->c1;
	*ch2 = freLinkList->curr->c2;
	*freq = freLinkList->curr->num;
	return 1;
}
//**************统计文档内容************************************************************ 
void sta_statis(FreLinkList *freLinkList, CLinkList *fileContent)
{
	char ch1,ch2;
	
	cll_SetHead(fileContent);

	fll_Create(freLinkList);
	int endOfContent = 0; 
	int singleCharFre[128] = {0};	//储存字符为0-127的值的频数 要做初始化，不然初值都不确定 
	endOfContent = !cll_MoveNext(fileContent);
	while(!endOfContent)
	{
		cll_GetData(fileContent, &ch1, &ch2);
		//如果ch1>0 则在singleCharFre中统计频数
		if(ch1 >= 0)
		{
			singleCharFre[ch1]++;
			endOfContent = !cll_MoveNext(fileContent);
			continue;
		}
		//如果ch1<0则说明由ch1和ch2共同决定字符，把这个字符统计在LLC链表里 
		if(ch1 < 0)
		{
			FLL_Node *llcHead = freLinkList->head;
			FLL_Node *currNode = llcHead;
			while(!(currNode->next == NULL))
			{
				FLL_Node *nextNode = currNode->next;
				if(nextNode->c1 < ch1)
				{
					currNode = currNode->next;
					continue;
				}
				else if(nextNode->c1 == ch1)
				{
					if(nextNode->c2 < ch2)
					{
						currNode = currNode->next;
						
						continue;
					}
					else if(nextNode->c2 == ch2)
					{
						nextNode->num++;
						
						break;
					}
					else if(nextNode->c2 > ch2)
					{
						freLinkList->curr = currNode;
						fll_Insert(freLinkList, ch1, ch2, 1);
						break;
					}
				}
				else if(nextNode->c1 > ch1)
				{
					freLinkList->curr = currNode;
					fll_Insert(freLinkList, ch1, ch2, 1);
					break;
				}
			}
			if(currNode->next == NULL)
			{
				freLinkList->curr = currNode;
				fll_Insert(freLinkList, ch1, ch2, 1);
			}
		}
		endOfContent = !cll_MoveNext(fileContent);
	}
	
	//最后还是要把所有统计结果都集中到freLinkList上 
	freLinkList->curr = freLinkList->head;
	for(int i = 0; i < 128; i++)
	{
		if(singleCharFre[i] > 0)
		{
			fll_Insert(freLinkList, i, 0, singleCharFre[i]);
			fll_MoveNext(freLinkList);
		}
	}
	//fll_Print(freLinkList);
}
void fll_Sort(FreLinkList *freLinkList)
{
	if(freLinkList->head==NULL)
	{
		return;
	}
	if(freLinkList->head->next==NULL)
	{
		return;
	}
	long count = fll_GetSize(freLinkList);
	printf("\n%d\n",count);
	int i=0;
	for(int i=0;i<count-1;i++)
	{
		int j=0;
		FLL_Node *jCurr = freLinkList->head;
		for(j=0;j<count-i-1;j++)
		{
			jCurr = jCurr->next;
			FLL_Node *node1 = jCurr;
			FLL_Node *node2 = jCurr->next;
			if(node1->num > node2->num)
			{
				
				fll_exangeContent(node1,node2);
			}
		}
	}
}


