#ifndef BITREE_H
#define BITREE_H
#include "statis.h"

struct BiTree
{
	char c1;
	char c2;
	long freq;
	struct BiTree *leftTree;
	struct BiTree *rightTree;
	struct BiTree *parent;
};
typedef struct BiTree BiTree;
BiTree *bt_Create(char c1, char c2, long freq);
BiTree *bt_GetParent(BiTree *biTree);
BiTree *bt_GetLeftTree(BiTree *biTree);
BiTree *bt_GetRightTree(BiTree *biTree);
int bt_SetLeft(BiTree *biTree, BiTree *value);
int bt_SetRight(BiTree *biTree, BiTree *value);
BiTree *bt_NewRight(BiTree *biTree, char c1, char c2, long freq);
BiTree *bt_NewLeft(BiTree *biTree, char c1, char c2, long freq);
void bt_PreOrder(BiTree *biTree);
void bt_PreOrderRight(BiTree *biTree);
void bt_PreOrderLeft(BiTree *biTree);
int bt_SetParent( BiTree *target,BiTree *dad);
BiTree *bt_CreHuff(FreLinkList *linkList);
void bt_PrintPreOrder(BiTree *biTree);
#endif
