#pragma once
#include "CommonHeader.h"


typedef struct tagNode
{
	int nData;
	struct tagNode* PrevNode;
	struct tagNode* NextNode;
}Node;

Node* DLL_CreateNode(int nNewData);
void DLL_DestroyNode(Node* Node);
void DLL_AppendNode(Node** Head, Node* NewNode);
Node* DLL_GetNodeAt(Node* Head, int nLocation);
void DLL_RemoveNode(Node** Head, Node* Remove);
void DLL_InsertAfter(Node* Current, Node* NewNode);
int DLL_GetNodeCount(Node* Head);