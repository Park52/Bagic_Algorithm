#include "NodeStruct.h"

Node* SLL_CreateNode(int nNewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->nData = nNewData;
	NewNode->NextNode = NULL;

	return NewNode;
}

void SLL_DestroyNode(Node* Node)
{
	free(Node);
}

void SLL_AppendNode(Node** Head, Node* NewNode)
{
	if (NULL == (*Head))
	{
		*Head = NewNode;
	}
	else
	{
		Node* tail = (*Head);
		while (tail->NextNode != NULL)
		{
			tail = tail->NextNode;
		}
		tail->NextNode = NewNode;
	}
}

Node* SLL_GetNodeAt(Node* Head, int Location)
{
	Node* Current = Head;

	while (Current->NextNode != NULL &&
		(--Location) >= 0)
	{
		Current = Current->NextNode;
	}
	return Current;
}

void SLL_RemoveNode(Node** Head, Node* Remove)
{
	if ((*Head) == Remove)
	{
		*Head = Remove->NextNode;
	}
	else
	{
		Node* Current = *Head;
		while (Current != NULL && Current->NextNode != Remove)
		{
			Current = Current->NextNode;
		}
		if (Current != NULL)
		{
			Current->NextNode = Remove->NextNode;
		}
	}
}

void SLL_InsertAfter(Node* Current, Node* NewNode)
{
	NewNode->NextNode = Current->NextNode;
	Current->NextNode = NewNode;
}

int SLL_GetNodeCount(Node* Head)
{
	int nCount = 0;
	Node* Current = Head;

	while (Current != NULL)
	{
		Current = Current->NextNode;
		nCount++;
	}

	return nCount;
}

void SLL_InsertNewHead(Node** Head, Node* NewHead)
{
	if (*Head == NULL)
	{
		(*Head) == NewHead;
	}
	else
	{
		NewHead->NextNode = (*Head);
		(*Head) = NewHead;
	}
}
