
#include "CircularDoublyLinkedList.h"

int main()
{
	int i = 0;
	int nCount = 0;
	Node* List = NULL;
	Node* NewNode = NULL;
	Node* Current = NULL;

	for (i = 0; i < 5; i++)
	{
		NewNode = CDLL_CreateNode( i );
		CDLL_AppendNode( &List, NewNode );
	}

	nCount = CDLL_GetNodeCount( List );
	for (i = 0; i < nCount; i++)
	{
		Current = CDLL_GetNodeAt( List, i );
		printf("List[%d] : %d\n", i, Current->nData);
	}

	printf("\nInserting 3000 After [2]....\n\n");

	Current = CDLL_GetNodeAt( List, 2 );
	NewNode = CDLL_CreateNode( 3000 );
	CDLL_InsertAfter( Current, NewNode );

	nCount = CDLL_GetNodeCount( List );
	//ȯ������ Ȯ���ϱ� ���� 2�赹��
	for (i = 0; i < nCount*2; i++)
	{
		if (i == 0)
		{
			Current = List;
		}
		else
		{
			Current = Current->NextNode;
		}

		printf("List[%d] : %d\n", i, Current->nData );
	}
	
	printf("\nDestroying List...\n");

	nCount = CDLL_GetNodeCount( List );

	for (i = 0; i < nCount; i++)
	{
		Current = CDLL_GetNodeAt(List, i);

		if (Current != NULL)
		{
			CDLL_RemoveNode( &List, Current );
			CDLL_DestroyNode( Current );
		}
	}

	return 1;
}