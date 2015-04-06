#include "SortingHeader.h"

void SelectSorting(vector<int> &list)
{
	int len = list.size();
	for (int i = 0; i < len-1; ++i)
	{
		int min = list[i];
		int j;
		for (j = i; j < len; ++j)
		{
			if (list[j] < min)
				min = list[j]; // 从未排序列中选出最小值
		}
		if (min != list[i])
		{
			// 将最小值与未排序列中的第1个数值交换
			list[j] = list[i];
			list[i] = min;
		}
	}
}