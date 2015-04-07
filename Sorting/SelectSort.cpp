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

// 大顶堆调整算法
void HeapAdjust(vector<int> &list, int root, int last)
{
	int root_value = list[root];
	int j;
	for (j = 2*root+1; j <= last; j = 2*j+1)
	{
		// 如果存在左子和右子，比较左右子的大小，将j指向较大的那个孩子
		if (j < last && list[j] < list[j+1])
			++j;
		if (root_value >= list[j]) // 比较根节点和较大子节点的大小
			break; // 若根节点最大，无需调整
		list[root] = list[j]; // 若子节点更大
		root = j; // 将root指向新的根节点
	}
	list[j] = root_value;
}

void HeapSort(vector<int> &list)
{
	// 大顶堆依然用list数组表示
	// 对于某一个节点i，其左子节点为2i+1, 右子节点为2i+2
	int len = list.size();
	// 建立初始大顶堆
	for (int i = len/2-1; i >= 0; --i)
		HeapAdjust(list, i, len-1);
	// 排序
	for (int i = len-1; i > 0; --i)
	{
		// 取出大顶堆根节点，即最大值与最后一个值交换
		list[0] = list[0]^list[i];
		list[i] = list[i]^list[0];
		list[0] = list[0]^list[i];
		// 交换完，重新调整成新的大顶堆
		HeapAdjust(list, 0, i-1);
	}
}