#include <stdio.h>

void InsertionSort(int DataSet[], int Length)
{
	int i = 0, j = 0;
	int Key = 0, temp = 0;

	for (i =1; i < Length; i++)
	{
		if (DataSet[i - 1] <= DataSet[i])
		{
			continue;
		}

		Key = DataSet[i];

		for (j = i-1; j >= 0; j--)
		{
			if (Key < DataSet[j])
			{
				temp = DataSet[j];
				DataSet[j] = DataSet[j + 1];
				DataSet[j + 1] = temp;
			}
		}
	}
}

int main(void)
{
	int DataSet[] = { 1,2,3,4,6,5 };	//6,4,2,3,1,5
	int Length = sizeof(DataSet) / sizeof(DataSet[0]);
	int i = 0;

	InsertionSort(DataSet, Length);

	for (i = 0; i < Length; i++)
	{
		printf("%d ", DataSet[i]);
	}

	printf("\n");

	return 0;
}
