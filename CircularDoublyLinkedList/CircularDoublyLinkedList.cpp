#include "CircularDoublyLinkedList.h"

Node* CDLL_CreateNode(int nNewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->nData = nNewData;

	NewNode->PrevNode = NULL;
	NewNode->NextNode = NULL;

	return NewNode;
}

void CDLL_DestroyNode(Node* Node)
{
	free(Node);
}
/*테일과 헤드 사이에 새 노드를 삽입한다*/
void CDLL_AppendNode(Node** Head, Node* NewNode)
{
	if ((*Head) == NULL)
	{
		*Head = NewNode;
		(*Head)->PrevNode = *Head;
		(*Head)->NextNode = *Head;
	}
	else
	{
		Node* tail = (*Head)->PrevNode;

		//헤드 시점에서 새로운 노드를 바라보게 만든다
		tail->NextNode->PrevNode = NewNode;
		tail->NextNode = NewNode;

		NewNode->NextNode = (*Head);
		NewNode->PrevNode = tail;
	}
}

void CDLL_InsertAfter(Node* Current, Node* NewNode)
{
	NewNode->NextNode = Current->NextNode;
	NewNode->PrevNode = Current;

	Current->NextNode->PrevNode = NewNode;
	Current->NextNode = NewNode;
	
}

void CDLL_RemoveNode(Node** Head, Node* Remove)
{
	if ((*Head) == Remove )
	{
		(*Head)->PrevNode->NextNode = Remove->NextNode;
		(*Head)->NextNode->PrevNode = Remove->PrevNode;

		*Head = Remove->NextNode;
		Remove->NextNode = NULL;
		Remove->PrevNode = NULL;
	}
	else
	{
		Node* Temp = Remove;

		Remove->PrevNode->NextNode = Temp->NextNode;
		Remove->NextNode->PrevNode = Temp->PrevNode;

		Remove->NextNode = NULL;
		Remove->PrevNode = NULL;
	}
}

Node* CDLL_GetNodeAt(Node* Head, int nLocation)
{
	Node* Current = Head;

	while (Current != NULL && (--nLocation) >= 0)
	{
		Current = Current->NextNode;
	}


	return Current;
}

int CDLL_GetNodeCount(Node* Head)
{
	int nCount = 0;
	Node* Current = Head;

	while (Current != NULL)
	{
		nCount++;
		Current = Current->NextNode;

		if (Current == Head)
		{
			break;
		}
	}

	return nCount;
}

void PrintNode(Node* _Node)
{
	if (_Node->NextNode == NULL)
	{
		printf("Next: NULL\n");
	}
	else
	{
		printf("Next: %d\n", _Node->NextNode->nData);
	}
}
