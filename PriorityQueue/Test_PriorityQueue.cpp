#include "PriorityQueue.h"

void PrintNode(PQNode* Node)
{
	printf("�۾��� : %s (�켱����:%d)\n", Node->Data, Node->Priority);
}
int main(void)
{
	PriorityQueue* PQ = PQ_Create(3);
	PQNode Popped;

	PQNode Nodes[7] = {
		{34, (void*)"�ڵ�"},
		{12, (void*)"������"},
		{87, (void*)"Ŀ��Ÿ��"},
		{45, (void*)"�����ۼ�"},
		{35, (void*)"�����"},
		{66, (void*)"�̴۱�"},
	};

	for (int i = 0; i < 6; i++)
	{
		PQ_Enqueue(PQ, Nodes[i]);
	}

	printf("ť�� ���� �ִ� �۾��� �� : %d\n", PQ->UsedSize);

	while (!PQ_IsEmptry(PQ))
	{
		PQ_Dequeue(PQ, &Popped);
		PrintNode(&Popped);
	}
	
	return 0;
}