#include "LinkedListStack.h"

int main()
{
	int i = 0;
	int nCount = 0;
	Node* Popped = NULL;
	Node* NewNode = NULL;

	LinkedListStack* Stack = NULL;
	
	LLS_CreateStack(&Stack);

	LLS_Push( Stack, LLS_CreateNode("abc") );
	LLS_Push( Stack, LLS_CreateNode("def") );
	LLS_Push( Stack, LLS_CreateNode("efg") );
	LLS_Push( Stack, LLS_CreateNode("hij") );

	nCount = LLS_GetSize(Stack);
	printf("Sie: %d, Top: %s\n\n", nCount, LLS_Top(Stack)->Data);

	for (i = 0; i < nCount; i++)
	{
		if (LLS_IsEmpty(Stack))
		{
			break;
		}

		Popped = LLS_Pop(Stack);

		printf("Popped : %s, ", Popped->Data);

		LLS_DestroyNode(Popped);

		if (!LLS_IsEmpty(Stack))
		{
			printf("Current Top : %s\n", LLS_Top(Stack)->Data);
		}
		else
		{
			printf("Stack Is Empty\n");
		}
	}

	LLS_DestroyStack(Stack);
	return 0;
}