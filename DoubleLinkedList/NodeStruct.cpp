#include "NodeStruct.h"

Node* DLL_CreateNode(int nNewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->nData = nNewData;

	NewNode->PrevNode = NULL;
	NewNode->NextNode = NULL;

	return NewNode;
}

void DLL_DestroyNode(Node* Node)
{
	free(Node);
}

void DLL_AppendNode(Node** Head, Node* NewNode)
{
	if ((*Head) == NULL)
	{
		*Head = NewNode;
	}
	else
	{
		Node* Tail = (*Head);
		while (Tail->NextNode != NULL)
		{
			Tail = Tail->NextNode;
		}
		Tail->NextNode = NewNode;
		NewNode->PrevNode = Tail;
	}
}

Node* DLL_GetNodeAt(Node* Head, int nLocation)
{
	Node* Current = Head;

	while (Current != NULL && (--nLocation) >= 0)
	{
		Current = Current->NextNode;
	}

	return Current;
}

void DLL_RemoveNode(Node** Head, Node* Remove)
{
	if (*Head == Remove)
	{
		*Head = Remove->NextNode;
		if ((*Head) != NULL)
		{
			(*Head)->PrevNode = NULL;
		}
		Remove->PrevNode = NULL;
		Remove->NextNode = NULL;
	}
	else
	{
		Node* Temp = Remove;

		Remove->PrevNode->NextNode = Temp->NextNode;
		if (Remove->NextNode != NULL)
		{
			Remove->NextNode->PrevNode = Temp->PrevNode;
		}

		Remove->NextNode = NULL;
		Remove->PrevNode = NULL;
	}
}

void DLL_InsertAfter(Node* Current, Node* NewNode)
{
	NewNode->NextNode = Current->NextNode;
	NewNode->PrevNode = Current;

	if (Current->NextNode != NULL)
	{
		Current->NextNode->PrevNode = NewNode;
	}
	Current->NextNode = NewNode;
}

int DLL_GetNodeCount(Node* Head)
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
