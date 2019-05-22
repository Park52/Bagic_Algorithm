#include "RedBlackTree.h"

extern RBTNode* Nil;
void RBT_DestroyTree(RBTNode* Tree)
{
	if (Tree->Right != Nil)
	{
		RBT_DestroyTree(Tree->Right);
	}

	if (Tree->Left != Nil)
	{
		RBT_DestroyTree(Tree->Left);
	}

	Tree->Left = Nil;
	Tree->Right = Nil;

	RBT_DestroyNode( Tree );
}

RBTNode* RBT_CreateNode(int NewData)
{
	RBTNode* NewNode = (RBTNode*)malloc(sizeof(RBTNode));

	NewNode->Parent = NULL;
	NewNode->Left = NULL;
	NewNode->Right = NULL;
	NewNode->Data = NewData;
	NewNode->Color = NewNode->BLACK;
	
	return NewNode;
}

void RBT_DestroyNode(RBTNode* Node)
{
	free(Node);
}

RBTNode* RBT_SearchNode(RBTNode* Tree, int Target)
{
	if (Tree == Nil)
	{
		return NULL;
	}

	if (Tree->Data > Target)
	{
		return RBT_SearchNode(Tree->Left, Target);
	}
	else if (Tree->Data < Target)
	{
		return RBT_SearchNode(Tree->Right, Target);
	}
	else
	{
		return Tree;
	}
}

RBTNode* RBT_SearchMinNode(RBTNode* Tree)
{
	if (Tree == Nil)
	{
		return Nil;
	}

	if (Tree->Left == Nil)
	{
		return Tree;
	}
	else
	{
		return RBT_SearchMinNode(Tree->Left);
	}
}

void RBT_InsertNode(RBTNode** Tree, RBTNode* NewNode)
{
	RBT_InsertNodeHelper(Tree, NewNode);

	NewNode->Color = NewNode->RED;
	NewNode->Left = Nil;
	NewNode->Right = Nil;

	RBT_RebuildAfterInsert(Tree, NewNode);

}



void RBT_InsertNodeHelper(RBTNode** Tree, RBTNode* NewNode)
{
	if ((*Tree) == NULL)
	{
		(*Tree) = NewNode;
	}

	if ((*Tree)->Data < NewNode->Data) 
	{
		if ((*Tree)->Right == Nil)
		{
			(*Tree)->Right = NewNode;
			NewNode->Parent = (*Tree);
		}
		else
		{
			RBT_InsertNodeHelper(&(*Tree)->Right, NewNode);
		}
	}
	else if ((*Tree)->Data > NewNode->Data)
	{
		if ((*Tree)->Left == Nil)
		{
			(*Tree)->Left = NewNode;
			NewNode->Parent = (*Tree);
		}
		else
		{
			RBT_InsertNodeHelper(&(*Tree)->Left, NewNode);
		}
	}
}

RBTNode* RBT_RemoveNode(RBTNode** Root, int Target)
{
	RBTNode* Removed = NULL;
	RBTNode* Successor = NULL;
	RBTNode* TargetNode = RBT_SearchNode((*Root), Target);

	if (TargetNode == NULL)
	{
		return NULL;
	}

	if ( TargetNode->Left == Nil || TargetNode->Right == Nil )
	{
		Removed = TargetNode;
	}
	else
	{
		Removed = RBT_SearchMinNode(TargetNode->Right);
		TargetNode->Data = Removed->Data;
	}

	if (Removed->Left != Nil)
	{
		Successor = Removed->Left;
	}
	else
	{
		Successor = Removed->Right;
	}
	
	Successor->Parent = Removed->Parent;

	if (Removed->Parent == NULL)
	{
		(*Root) = Successor;
	}
	else
	{
		if (Removed == Removed->Parent->Left)
		{
			Removed->Parent->Left = Successor;
		}
		else
		{
			Removed->Parent->Right = Successor;
		}
	}

	if (Removed->Color == Removed->BLACK)
	{
		RBT_RebuildAfterRemove(Root, Successor);
	}

	return Removed;
}

void RBT_RebuildAfterInsert(RBTNode** Tree, RBTNode* NewNode)
{
	while (NewNode != (*Tree) && NewNode->Parent->Color == NewNode->RED)
	{
		if (NewNode->Parent == NewNode->Parent->Parent->Left)
		{
			RBTNode* Uncle = NewNode->Parent->Parent->Right;

			if (Uncle->Color == Uncle->RED)
			{
				NewNode->Parent->Color = NewNode->BLACK;
				Uncle->Color = Uncle->BLACK;
				NewNode->Parent->Parent->Color = NewNode->RED;

				NewNode = NewNode->Parent->Parent;
			}
			else
			{
				if (NewNode == NewNode->Parent->Right)
				{
					NewNode = NewNode->Parent;
					RBT_RotateLeft(Tree, NewNode);
				}

				NewNode->Parent->Color = NewNode->BLACK;
				NewNode->Parent->Parent->Color = NewNode->RED;

				RBT_RotateRight(Tree, NewNode->Parent->Parent);
			}
		}
		else
		{
			RBTNode* Uncle = NewNode->Parent->Parent->Left;
			if (Uncle->Color == Uncle->RED)
			{
				NewNode->Parent->Color = NewNode->BLACK;
				Uncle->Color = NewNode->BLACK;
				NewNode->Parent->Parent->Color = NewNode->RED;
				NewNode = NewNode->Parent->Parent;
			}
			else
			{
				if (NewNode == NewNode->Parent->Left)
				{
					NewNode = NewNode->Parent;
					RBT_RotateRight(Tree, NewNode);
				}

				NewNode->Parent->Color = NewNode->BLACK;
				NewNode->Parent->Parent->Color = NewNode->RED;
				RBT_RotateLeft(Tree, NewNode->Parent->Parent);
			}
		}
	}

	(*Tree)->Color = (*Tree)->BLACK;
}

void RBT_RebuildAfterRemove(RBTNode** Root, RBTNode* Successor)
{
	RBTNode* Sibling = NULL;

	while (Successor->Parent != NULL && Successor->Color == Successor->BLACK)
	{
		if (Successor == Successor->Parent->Right)
		{
			Sibling = Successor->Parent->Right;

			if (Sibling->Color == Sibling->RED)
			{
				Sibling->Color = Sibling->BLACK;
				Successor->Parent->Color = Successor->RED;
				RBT_RotateLeft(Root, Successor->Parent);
			}
			else
			{
				if (Sibling->Left->Color == Sibling->BLACK && 
					Sibling->Right->Color == Sibling->BLACK)
				{
					Sibling->Color = Sibling->RED;
					Successor = Successor->Parent;
				}
				else
				{
					if (Sibling->Left->Color == Sibling->RED)
					{
						Sibling->Left->Color = Sibling->BLACK;
						Sibling->Color = Sibling->RED;

						RBT_RotateRight(Root, Sibling);
						Sibling = Successor->Parent->Right;
					}

					Sibling->Color = Successor->Parent->Color;
					Successor->Parent->Color = Successor->BLACK;
					Sibling->Right->Color = Sibling->BLACK;
					RBT_RotateLeft(Root, Successor->Parent);
					Successor = (*Root);
				}
			}
		}
		else
		{
			Sibling = Successor->Parent->Left;

			if (Sibling->Color == Sibling->RED)
			{
				Sibling->Color = Sibling->BLACK;
				Successor->Parent->Color = Successor->RED;
				RBT_RotateRight(Root, Successor->Parent);
			}
			else
			{
				if (Sibling->Right->Color == Sibling->BLACK &&
					Sibling->Left->Color == Sibling->BLACK)
				{
					Sibling->Color = Sibling->RED;
					Successor = Successor->Parent;
				}
				else
				{
					if (Sibling->Right->Color == Sibling->RED)
					{
						Sibling->Right->Color = Sibling->BLACK;
						Sibling->Color = Sibling->RED;

						RBT_RotateLeft(Root, Sibling);
						Sibling = Successor->Parent->Left;
					}

					Sibling->Color = Successor->Parent->Color;
					Successor->Parent->Color = Successor->BLACK;
					Sibling->Left->Color = Sibling->BLACK;
					RBT_RotateRight(Root, Successor->Parent);
					Successor = (*Root);
				}
			}
		}
	}
	Successor->Color = Successor->BLACK;
}

void RBT_PrintTree(RBTNode* Node, int Depth, int BlackCount)
{
	int i = 0;
	char c = 'X';
	int v = -1;
	char cnt[100];

	if (Node == NULL || Node == Nil)
	{
		return;
	}

	if (Node->Color == Node->BLACK)
	{
		BlackCount++;
	}

	if (Node->Parent != NULL)
	{
		v = Node->Parent->Data;

		if (Node->Parent->Left == Node)
		{
			c = 'L';
		}
		else
		{
			c = 'R';
		}
	}

	if (Node->Left == Nil && Node->Right == Nil)
	{
		sprintf(cnt, "--------- %d", BlackCount);
	}
	else
	{
		sprintf(cnt, "");
	}

	for (i = 0; i < Depth; i++)
	{
		printf("  ");
	}

	printf("%d %s [%c. %d] %s\n", Node->Data, 
								  (Node->Color== Node->RED)? "RED":"BLACK", 
								  c, v, cnt);

	RBT_PrintTree(Node->Left, Depth + 1, BlackCount);
	RBT_PrintTree(Node->Right, Depth + 1, BlackCount);

}

void RBT_RotateLeft(RBTNode** Root, RBTNode* Parent)
{
	RBTNode* RightChild = Parent->Right;

	Parent->Right = RightChild->Left;

	if (RightChild->Left != Nil)
	{
		RightChild->Left->Parent = Parent;
	}

	RightChild->Parent = Parent->Parent;

	if (Parent->Parent == NULL)
	{
		(*Root) = RightChild;
	}
	else
	{
		if (Parent == Parent->Parent->Left)
		{
			Parent->Parent->Left = RightChild;
		}
		else
		{
			Parent->Parent->Right = RightChild;
		}
	}

	RightChild->Left = Parent;
	Parent->Parent = RightChild;
}

void RBT_RotateRight(RBTNode** Root, RBTNode* Parent)
{
	RBTNode* LeftChild = Parent->Left;

	Parent->Left = LeftChild->Right;

	if (LeftChild->Right != Nil)
	{
		LeftChild->Right->Parent = Parent;
	}

	LeftChild->Parent = Parent->Parent;

	if (Parent->Parent == NULL)
	{
		(*Root) = LeftChild;
	}
	else
	{
		if (Parent == Parent->Parent->Left)
		{
			Parent->Parent->Left = LeftChild;
		}
		else
		{
			Parent->Parent->Right = LeftChild;
		}
	}

	LeftChild->Right = Parent;
	Parent->Parent = LeftChild;
}
