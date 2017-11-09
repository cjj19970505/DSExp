#include "TPQueue.h"
#include "statis.h"
#include<stdlib.h>
#include<stdio.h>
int tpq_DeleteNode(TPQ_Node *node);
void tpq_Create(TPQueue *queue)
{
	queue->front = NULL;
	queue->rear = NULL;
}

int tpq_IsEmpty(TPQueue *queue)
{
	if(queue->front == NULL || queue->rear == NULL)
	{
		return 1;
	}
	return 0;
}
//返回true的排前面！！ d
int tpq_Compare(BiTree *dataA, BiTree *dataB)
{
	if(dataB == NULL)
	{
		return 1;
	}
	if(dataA->freq > dataB->freq)
	{
		return 0;
	}
	return 1;
}
void tpq_InQueue(TPQueue *queue, BiTree *data)
{
	TPQ_Node *newNode = (TPQ_Node*)malloc(sizeof(TPQ_Node));
	newNode->data = data;
	newNode->next = NULL;
	if(queue->front == NULL)
	{
		queue->front=queue->rear=newNode;
	}
	else
	{
		
		int shouldBeFront = tpq_Compare(data, queue->front->data);
		if(shouldBeFront)
		{
			newNode->next = queue->front;
			queue->front = newNode;
		}
		else
		{
			TPQ_Node *curr = queue->front;
			while(curr != queue->rear)
			{
				int b = tpq_Compare(newNode->data, curr->next->data);
				if(b)
				{
					newNode->next = curr->next;
					curr->next = newNode;
					break;
				}
				curr = curr->next;
			}
			if(curr == queue->rear)
			{
				queue->rear->next = newNode;
				queue->rear = newNode;
				
			}
		}
	}
}
int tpq_GetSize(TPQueue *queue)
{
	TPQ_Node *node = queue->front;
	int count = 0;
	while(node != NULL)
	{
		count++;
		node = node->next;
	}
}
BiTree *tpq_OutQueue(TPQueue *queue)
{
	if(tpq_IsEmpty(queue))
	{
		return NULL;
	}
	TPQ_Node *node = queue->front;
	queue->front = queue->front->next;
	BiTree *data = node->data;
	if(queue->front == NULL)
	{
		queue->rear = NULL;
	}
	tpq_DeleteNode(node);
	return data;
}

//后期完善！！！ 
int tpq_DeleteNode(TPQ_Node *node)
{
	return 0;
}

void tpq_Print(TPQueue *queue)
{
	TPQ_Node *node=queue->front;
	while(node!=NULL)
	{
		printf("%d ",node->data->freq);
		node=node->next;
	}
	printf("\n");
}
TPQueue *tpq_CreateFromFLL(FreLinkList *freLinkList)
{
	TPQueue *tpqueue = (TPQueue*)malloc(sizeof(TPQueue));
	tpq_Create(tpqueue);
	while(fll_MoveNext(freLinkList))
	{
		char ch1,ch2;
		long freq;
		fll_GetData(freLinkList, &ch1, &ch2, &freq);
		BiTree *newTree = bt_Create(ch1,ch2,freq);
		
		tpq_InQueue(tpqueue, newTree);
	}
	return tpqueue;
}

BiTree *bt_CreateFromFLLNode(FLL_Node *node)		//对链表里节点转化为二叉树 
{
	BiTree *newTree = (BiTree*)malloc(sizeof(BiTree));
	newTree->c1 = node->c1;
	newTree->c2 = node->c2;
	newTree->freq = node->num;
}


