#include "BinarySearchTree.h"

BSTNode* BST_CreateNode(int NewData)
{
	BSTNode* NewNode = (BSTNode*)malloc(sizeof(BSTNode));

	NewNode->nData = NewData;
	NewNode->Left = NULL;
	NewNode->Right = NULL;

	return NewNode;
}

void BST_DestroyNode(BSTNode* Node)
{
	free(Node);
}

void BST_DestroyTree(BSTNode* Tree)
{
	if (Tree->Right != NULL)
	{
		BST_DestroyTree(Tree->Right);
	}

	if (Tree->Left != NULL)
	{
		BST_DestroyTree(Tree->Left);
	}
	
	Tree->Left = NULL;
	Tree->Right = NULL;

	BST_DestroyNode(Tree);
}

BSTNode* BST_SearchNode(BSTNode* Tree, int Target)
{
	if (Tree == NULL)
	{
		return NULL;
	}

	if (Tree->nData == Target)
	{
		return Tree;
	}
	else if (Tree->nData > Target)
	{
		return BST_SearchNode(Tree->Left, Target);
	}
	else
	{
		return BST_SearchNode(Tree->Right, Target);
	}
}

BSTNode* BST_SearchMinNode(BSTNode* Tree)
{
	if (Tree == NULL)
	{
		return NULL;
	}

	if (Tree->Left == NULL)
	{
		return Tree;
	}
	else
	{
		BST_SearchMinNode(Tree->Left);
	}
}

void BST_InsertNode(BSTNode* Tree, BSTNode* Child)
{
	if (Tree->nData < Child->nData)
	{
		if (Tree->Right == NULL)
		{
			Tree->Right = Child;
		}
		else
		{
			BST_InsertNode(Tree->Right, Child);
		}
	}
	else if (Tree->nData > Child->nData)
	{
		if (Tree->Left == NULL)
		{
			Tree->Left = Child;
		}
		else
		{
			BST_InsertNode(Tree->Left, Child);
		}
	}
}

BSTNode* BST_RemoveNode(BSTNode* Tree, BSTNode* Parent, int Target)
{
	BSTNode* Removed = NULL;

	if (Tree == NULL)
	{
		return NULL;
	}

	if (Tree->nData > Target)
	{
		Removed = BST_RemoveNode(Tree->Left, Tree, Target);
	}
	else if (Tree->nData < Target)
	{
		Removed = BST_RemoveNode(Tree->Right, Tree, Target);
	}
	else
	{
		Removed = Tree;

		if (Tree->Left == NULL && Tree->Right == NULL)
		{
			if (Parent->Left == Tree)
			{
				Parent->Left = NULL;
			}
			else
			{
				Parent->Right = NULL;
			}
		}
		else
		{
			if (Tree->Left != NULL && Tree->Right != NULL)
			{
				BSTNode* MinNode = BST_SearchMinNode(Tree->Right);
				MinNode = BST_RemoveNode(Tree, NULL, MinNode->nData);
				Tree->nData = MinNode->nData;
			}
			else
			{
				BSTNode* Temp = NULL;
				if (Tree->Left != NULL)
				{
					Temp = Tree->Left;
				}
				else
				{
					Temp = Tree->Right;
				}

				if (Parent->Left == Tree)
				{
					Parent->Left = Temp;
				}
				else
				{
					Parent->Right = Temp;
				}
			}
		}
	}

	return Removed;
}

void BST_InorderPrintTree(BSTNode* Node)
{
	if (Node == NULL)
	{
		return;
	}

	BST_InorderPrintTree(Node->Left);

	printf("%d ", Node->nData);

	BST_InorderPrintTree(Node->Right);
}
