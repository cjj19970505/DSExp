#ifndef TPQUEUE_H
#define TPQUEUE_H
#include "BiTree.h"
struct TPQ_Node
{
	BiTree *data;
	struct TPQ_Node *next;
};
typedef struct TPQ_Node TPQ_Node;
struct TPQueue
{
	TPQ_Node *front;
	TPQ_Node *rear;
};
typedef struct TPQueue TPQueue;
void tpq_Create(TPQueue *queue);
int tpq_IsEmpty(TPQueue *queue);
int tpq_Compare(BiTree *dataA, BiTree *dataB);
void tpq_InQueue(TPQueue *queue, BiTree *data);
BiTree *tpq_OutQueue(TPQueue *queue);
int tpq_DeleteNode(TPQ_Node *node);
void tpq_Print(TPQueue *queue);

#endif
