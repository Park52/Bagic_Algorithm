#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>
typedef struct tagSBTNode 
{
	struct tagSBTNode* Left;
	struct tagSBTNode* Right;

	char Data;
}SBTNode;

SBTNode* SBT_CreateNode(char NewData);
void SBT_DestroyNode(SBTNode* Node);
void SBT_DestroyTree(SBTNode* Root);

void SBT_PreorderPrintTree(SBTNode* Node);
void SBT_InorderPrintTree(SBTNode* Node);
void SBT_PostorderPrintTree(SBTNode* Node);

#endif
