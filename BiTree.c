#include "BiTree.h"
#include "statis.h"
#include "TPQueue.h"
#include <stdlib.h>
#include <stdio.h>

BiTree *bt_Create(char c1, char c2, long freq)   // 创建一个二叉树 
{
	BiTree *biTree = (BiTree*)malloc(sizeof(BiTree));	 
	if (biTree == NULL)			//判断是否申请成功 
	{
		return NULL;
	}
	biTree->leftTree = NULL;
	biTree->rightTree = NULL;
	biTree->parent = NULL;
	biTree->c1 = c1;
	biTree->c2 = c2;
	biTree->freq = freq;
	return biTree;
}

BiTree *bt_GetParent(BiTree *biTree)     //返回当前节点的双亲节点 
{
	if (biTree == NULL)			//判断输入二叉树是否为空 
	{
		return NULL;
	}
	return biTree->parent;
}
BiTree *bt_GetLeftTree(BiTree *biTree)     //返回当前节点左节点 
{
	if (biTree == NULL)			//判断输入二叉树是否为空
	{
		return NULL;		
	}
	return biTree->leftTree;
}

BiTree *bt_GetRightTree(BiTree *biTree)     //返回当前节点的右节点 
{
	if (biTree == NULL)			//判断输入二叉树是否为空
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
void bt_PreOrderRight(BiTree *biTree);
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
void bt_PrintPreOrder(BiTree *biTree)
{
	if(biTree == NULL)
	{
		return;
	}
	printf("(");
	if(biTree->c1 < 0)
	{
		printf("char:%c%c,fre:%d",biTree->c1,biTree->c2,biTree->freq);
	}
	else
	{
		printf("char:%c,fre:%d",biTree->c1,biTree->freq);
	}
	printf(") ");
	bt_PrintPreOrder(biTree->leftTree);
	bt_PrintPreOrder(biTree->rightTree); 
	
}


void bt_PreOrder(BiTree *biTree)    //先序遍历 
{
	if (biTree == NULL)			//判断输入二叉树是否为空
	{
		return;
	}
	bt_PreOrderLeft(biTree->leftTree);
	bt_PreOrderRight(biTree->rightTree); 
}

int bt_SetLeft(BiTree *biTree, BiTree *value)    //设置左节点 
{
	if(biTree == NULL)
	{
		return 0;
	}
	biTree->leftTree = value;
	value->parent = biTree;
	return 1;
}
int bt_SetRight(BiTree *biTree, BiTree *value)    //设置右节点 
{
	if(biTree == NULL)
	{
		return 0;
	}
	biTree->rightTree = value;
	value->parent = biTree;
	return 1;
}

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


BiTree *bt_CreHuff(FreLinkList *linkList)    //创建哈夫曼树
{
	TPQueue *tpqueue = tpq_CreateFromFLL(linkList);
	BiTree *tree1;
	BiTree *tree2;
	tree1 = tpq_OutQueue(tpqueue);
	tree2 = tpq_OutQueue(tpqueue);
	while (tree2 != NULL)
	{
		BiTree *parentT = bt_Create(128,0,tree1->freq + tree2->freq);
		bt_SetLeft(parentT,tree1);
		bt_SetRight(parentT,tree2);
		tpq_InQueue(tpqueue, parentT);
		tree1 = tpq_OutQueue(tpqueue);
		tree2 = tpq_OutQueue(tpqueue);
	}
	//bt_PrintPreOrder(tree1);
	return tree1;
	
	//printf("%d",tree1->);
	//*/
}

//删除
//注意 该删除操作并不会删除其子树，但会 
int bi_Delete(BiTree *biTree)
{
	if(biTree == NULL)
	{
		return 0;
	}
	if(biTree->parent != NULL)
	{
		BiTree *parent = biTree->parent;
		if(parent->leftTree == biTree)
		{
			parent->leftTree = NULL;
		}
		if(parent->rightTree == biTree)
		{
			parent->rightTree = NULL;
		}
	}
	if(biTree->leftTree != NULL)
	{
		biTree->leftTree->parent = NULL;
	}
	if(biTree->rightTree != NULL)
	{
		biTree->rightTree->parent = NULL;
	}
	free(biTree);
}

void bt_HuffCodeHelper(BiTree *huffTree, Bit *bit, FreLinkList *frelinklist)
{
	if(huffTree->leftTree != NULL)
	{
		bit_Append(bit, 0);
		bt_HuffCodeHelper(huffTree->leftTree, bit, frelinklist);
		bit_Pop(bit);
	}
	if(huffTree->rightTree != NULL)
	{
		bit_Append(bit, 1);
		bt_HuffCodeHelper(huffTree->rightTree, bit, frelinklist);
		bit_Pop(bit);
	}
	if(huffTree->leftTree == NULL && huffTree->rightTree == NULL)
	{
		fll_SetHuffCode(frelinklist, huffTree->c1, huffTree->c2, bit_CopyFrom(bit));
	}
}
void bt_HuffCode(BiTree *huffTree,FreLinkList *frelinklist)
{
	Bit *bit = bit_CreateBit();
	bt_HuffCodeHelper(huffTree, bit, frelinklist);
}

int bt_LeaveCount(BiTree *tree)
{
	int total = 0;
	if(tree->leftTree == NULL && tree->rightTree == NULL)
	{
		total += 1;
	}
	else
	{
		if(tree->leftTree != NULL)
		{
			total += bt_LeaveCount(tree->leftTree);
		}
		if(tree->rightTree != NULL)
		{
			total += bt_LeaveCount(tree->rightTree);
		}
	}
	return total;
}
















