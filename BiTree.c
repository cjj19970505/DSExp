#include "BiTree.h"
#include "statis.h"
#include "TPQueue.h"
#include <stdlib.h>
#include <stdio.h>


int bt_Create(BiTree *biTree, char c1, char c2, long freq)   // ����һ�������� 
{
	//biTree = (BiTree*)malloc(sizeof(BiTree));		//����ռ� 
	if (biTree == NULL)			//�ж��Ƿ�����ɹ� 
	{
		return 0;
	}
	biTree->leftTree = NULL;
	biTree->rightTree = NULL;
	biTree->parent = NULL;
	biTree->c1 = c1;
	biTree->c2 = c2;
	biTree->freq = freq;
	return 1;
}

BiTree *bt_GetParent(BiTree *biTree)     //���ص�ǰ�ڵ��˫�׽ڵ� 
{
	if (biTree == NULL)			//�ж�����������Ƿ�Ϊ�� 
	{
		return NULL;
	}
	return biTree->parent;
}

BiTree *bt_GetLeftTree(BiTree *biTree)     //���ص�ǰ�ڵ���ڵ� 
{
	if (biTree == NULL)			//�ж�����������Ƿ�Ϊ��
	{
		return NULL;		
	}
	return biTree->leftTree;
}

BiTree *bt_GetRightTree(BiTree *biTree)     //���ص�ǰ�ڵ���ҽڵ� 
{
	if (biTree == NULL)			//�ж�����������Ƿ�Ϊ��
	{
		return NULL;
	}
	return biTree->rightTree;
}

void bt_PreOrderLeft(BiTree *biTree)
{
	if (biTree == NULL)		
	{
		return;
	}
	printf("%d ",0);
	if (biTree->leftTree == NULL);
	{
		printf("%c ");
	}
	bt_PreOrderLeft(biTree->leftTree);
	bt_PreOrderRight(biTree->rightTree); 
}

void bt_PreOrderRight(BiTree *biTree)
{
	if (biTree == NULL)		
	{
		return;
	}
	printf("%d ",1);
	bt_PreOrderLeft(biTree->leftTree);
	bt_PreOrderRight(biTree->rightTree); 
}



void bt_PreOrder(BiTree *biTree)    //������� 
{
	if (biTree == NULL)			//�ж�����������Ƿ�Ϊ��
	{
		return;
	}
	bt_PreOrderLeft(biTree->leftTree);
	bt_PreOrderRight(biTree->rightTree); 
}

int bt_SetLeft(BiTree *biTree, BiTree *value)    //������ڵ� 
{
	if(biTree == NULL)
	{
		return 0;
	}
	biTree->leftTree = value;
	value->parent = biTree;
	return 1;
}
int bt_SetRight(BiTree *biTree, BiTree *value)    //�����ҽڵ� 
{
	if(biTree == NULL)
	{
		return 0;
	}
	biTree->rightTree = value;
	value->parent = biTree;
	return 1;
}

int bt_SetParent( BiTree *target,BiTree *dad)   //����˫�׽ڵ� 
{
	if(target == NULL)
	{
		return 0;
	}
	target->parent = dad;
	return 1;
}
//===============================������======================================= 

BiTree *bt_NewRight(BiTree *biTree, char c1, char c2, long freq)
{
	BiTree *newTree = (BiTree*)malloc(sizeof(BiTree));
	newTree->c1 = c1;
	newTree->c2 = c2;
	newTree->freq = freq;
	bt_SetRight(biTree, newTree);
	return newTree;
}
BiTree *bt_NewLeft(BiTree *biTree, char c1, char c2, long freq)
{
	BiTree *newTree = (BiTree*)malloc(sizeof(BiTree));
	newTree->c1 = c1;
	newTree->c2 = c2;
	newTree->freq = freq;
	bt_SetLeft(biTree, newTree);
	return newTree;
}

//==========================================������===================================== 


void bt_CreHuff(FreLinkList *linkList)    //������������ 	   *************************�������ö���ǰ������
{
	TPQueue *tpqueue = tpq_CreateFromFLL(linkList);
	BiTree *tree1;
	BiTree *tree2;
	tree1 = tpq_OutQueue(&tpqueue);
	tree2 = tpq_OutQueue(&tpqueue);
	while (tree2 != NULL)
	{
		BiTree *parentT = (BiTree*)malloc(sizeof(BiTree));
		bt_SetParent(tree1,parentT);    //��ǰ�������ϳ�����
		bt_SetParent(tree2,parentT);
		parentT->freq = tree1->freq + tree2->freq;
		tpq_InQueue(&tpqueue, parentT);                 //������������� 
		tree1 = tpq_OutQueue(&tpqueue);
		tree2 = tpq_OutQueue(&tpqueue);
	}
}
/*
int bt_HuffCode(BiTree *biTree)			//����������
{
	if(biTree == NULL)
	{
		return NULL;
	}
	bt_PreOrder(BiTree *biTree);
	return 1;
} */














