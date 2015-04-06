#include "SortingHeader.h"

void InsertSorting(vector<int> &list)
{
	for (int i = 1; i < list.size(); ++i)
	{
		int temp = list[i];
		// 如果新的一个待排值，比上一个小，则开始移位
		if (temp < list[i-1]) 
		{
			// 从i-1开始，后移，一直到temp插入比它小的数值之后
			int j;
			for (j = i-1; j >= 0 && temp < list[j]; --j)
				list[j+1] = list[j];
			list[j+1] = temp;
		}
	}
}

void BinInsertSorting(vector<int> &list)
{
	for (int i = 1; i < list.size(); ++i)
	{
		int temp = list[i];
		// 开始进行折半查找
		int low = 0, high = i-1, mid = 0;
		while (low <= high)
		{
			mid = (low+high) / 2;
			if (temp > mid)
				low = mid + 1;
			else if (temp < mid)
				high = mid - 1;
			else // mid == temp
				break;
		}
		// 查找结束后，high+1或low-1, 或者mid+1的位置即为插入位置
		if (low <= high)
			high = mid;
	    // 开始后移
		for (int j = i - 1; j < high;--j)
			list[j+1] = list[j];
		list[high+1] = temp;
	}
}

void ShellSort(vector<int> &list)
{
    int len = list.size();
	int gap = len/3 + 1;
    while (gap > 1) 
	{
		// 对每个子序列都做一次直接插入排序
        for (int i = gap; i < len; ++i)
		{
			int temp = list[i];
			// 如果新的一个待排值，比子序列中的上一个小，则开始移位
			if (temp < list[i-gap])
			{
				// 从i-gap开始后移，一直到temp插入比它小的数值之后
				int j;
				for (j = i-gap; j >= 0 && temp < list[j]; j -= gap) 
					list[j+gap] = list[j]; 
                list[j+gap] = temp; // 插入
			}
        }
		gap=gap/3 + 1;
    }
} 
