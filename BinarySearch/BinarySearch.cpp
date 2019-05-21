#include <stdio.h>
#include <stdlib.h>

#include <algorithm>

#include "Score.h"


Score* BinarySearch(Score ScoreList[], int Size, double Target)
{
	int Left = 0;
	int Right = Size - 1;

	int Mid = 0;

	while (Left <= Right)
	{
		Mid = (Left + Right) / 2;

		if (Target == ScoreList[Mid].score)
		{
			return &(ScoreList[Mid]);
		}
		else if (Target > ScoreList[Mid].score)
		{
			Left = Mid + 1;
		}
		else
		{
			Right = Mid - 1;
		}
	}

	return NULL;
}

bool compare(const Score A, const Score B)
{
	return A.score < B.score;
}

int main(void)
{
	int Length = sizeof(DataSet) / sizeof(DataSet[0]);
	int i = 0;
	Score* found = NULL;

	std::sort(DataSet, DataSet + Length, compare);
	// STL 에서 사용하는 Sort 함수
	found = BinarySearch(DataSet, Length, 671.78);

	printf("found : %d %f \n", found->number, found->score);

	return 0;
}
