#include "CommonHeader.h"

typedef struct tagNode
{
	int nData;
	struct tagNode* NextNode;
} Node;


Node* SLL_CreateNode(int nNewData);
void SLL_DestroyNode(Node* Node);
void SLL_AppendNode(Node** Head, Node* NewNode);
Node* SLL_GetNodeAt(Node* Head, int Location);
void SLL_RemoveNode(Node** Head, Node* Remove);
void SLL_InsertAfter(Node* Current, Node* NewNode);
int SLL_GetNodeCount(Node* Head);
void SLL_InsertNewHead(Node** Head, Node* NewHead);