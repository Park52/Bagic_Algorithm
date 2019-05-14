#ifndef CIRCULAR_DOUBLY_LINKEDLIST_H
#define CIRCULAR_DOUBLY_LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode
{
	int nData;
	struct tagNode* PrevNode;
	struct tagNode* NextNode;
}Node;

Node* CDLL_CreateNode(int nNewData);
void CDLL_DestroyNode(Node* Node);
void CDLL_AppendNode(Node** Head, Node* NewNode);
void CDLL_InsertAfter(Node* Current, Node* NewNode);
void CDLL_RemoveNode(Node** Head, Node* Remove);
Node* CDLL_GetNodeAt(Node* Head, int nLocation);
int CDLL_GetNodeCount(Node* Head);
void PrintNode(Node* _Node);
#endif