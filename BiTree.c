#include "BiTree.h"
#include <stdlib.h>
#include <stdio.h>
int bt_Create(BiTree *biTree, char c1, char c2, long freq)   // 创建一个二叉树 
{
	//biTree = (BiTree*)malloc(sizeof(BiTree));		//申请空间 
	if (biTree == NULL)			//判断是否申请成功 
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
		printf("%c ")
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

int bt_SetParent( BiTree *target,BiTree *leftT,BiTree *rightT)   //设置双亲节点 
{
	if(leftTree == NULL||rightTree == NULL)
	{
		return 0;
	}
	leftT->parent = target;
	rightT->parent = target;
	target->leftTree = leftT;
	target->rightTree = leftT;
	target->freq = leftT->freq + right->freq; 
	return 1;
}
//===============================测试区======================================= 

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

//==========================================测试区===================================== 


void bt_CreHuff(FLL_Node *node)    //创建哈夫曼树 	   *************************参数调用队列前两个树
{
	BiTree *parentT = (BiTree*)malloc(sizeof(BiTree));
	//调用队列前两个树
	bt_SetParent()    //对前两个树合成新树
	//将新树插入队列 
	bt_CreHuff()	 //递归调用函数 
}

int bt_HuffCode(BiTree *biTree)			//哈夫曼编码
{
	if(biTree == NULL)
	{
		return NULL;
	}
	bt_PreOrder(BiTree *biTree);
	return 1;
} 














