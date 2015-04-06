#include "SortingHeader.h"

void BubbleSort(vector<int> &list)
{
	bool exchange = false;
	int i = list.size()-1;
	// 引入exchange，当上一轮冒泡没有出现交换时，说明已经有序，可退出循环
	while (i >0 && exchange)
	{
		exchange = false;
		for (int j = 0; j < i; ++j)
		{
			if (list[j] > list[j+1])
			{
				// 用异或来进行交换
				list[j] = list[j]^list[j+1];
				list[j+1] = list[j]^list[j+1]; // list[j]^list[j+1]^list[j+1]
				list[j] = list[j]^list[j+1]; // list[j]^list[j+1]^list[j]
				exchange = true;
			}
		}
		--i;
	}
}

void Qsort(vector<int> &list, int low, int high)
{
	int pivot = list[low]; // 设置pivot
	// 进行一次排序
	int low_tmp = low, high_tmp = high;
	while (low_tmp < high_tmp)
	{
		while (low_tmp < high_tmp && list[high_tmp] >= pivot)
			--high_tmp;
		// 小于pivot的数，换到左侧
		list[low_tmp] = list[high_tmp];
		while (low_tmp < high_tmp && list[low_tmp] <= pivot)
			++low_tmp;
		list[high_tmp] = list[low_tmp];
	}
	list[low_tmp] = pivot;
	// 完成一次排序
	Qsort(list, low, low_tmp-1); // 递归处理左子序列
	Qsort(list, low_tmp+1, high); // 递归处理左子序列
}

void QuickSort(vector<int> &list)
{
	// 初始low=0，high=len-1
	Qsort(list, 0, list.size()-1);
}