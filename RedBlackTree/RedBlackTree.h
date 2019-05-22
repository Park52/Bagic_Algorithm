#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct tagRBTNode
{
	struct tagRBTNode* Parent;
	struct tagRBTNode* Left;
	struct tagRBTNode* Right;

	enum{RED, BLACK} Color;

	int Data;
}RBTNode;

void		RBT_DestroyTree(RBTNode* Tree);
RBTNode*	RBT_CreateNode(int NewData);
void		RBT_DestroyNode(RBTNode* Node);

RBTNode*	RBT_SearchNode(RBTNode* Tree, int Target);
RBTNode*	RBT_SearchMinNode(RBTNode* Tree);
void		RBT_InsertNode(RBTNode** Tree, RBTNode* NewNode);
void		RBT_InsertNodeHelper(RBTNode** Tree, RBTNode* NewNode);
RBTNode*	RBT_RemoveNode(RBTNode** Root, int Target);
void		RBT_RebuildAfterInsert(RBTNode** Tree, RBTNode* NewNode);
void		RBT_RebuildAfterRemove(RBTNode** Root, RBTNode* X);

void		RBT_PrintTree(RBTNode* Node, int Depth, int BlackCount);
void		RBT_RotateLeft(RBTNode** Root, RBTNode* Parent);
void		RBT_RotateRight(RBTNode** Root, RBTNode* Parent);

#endif // !REDBLACKTREE_H
