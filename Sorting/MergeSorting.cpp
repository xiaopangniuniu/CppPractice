#include "SortingHeader.h"

void MergeSorting(vector<int> &list)
{
	vector<int> tempList; // 定义一个临时存储空作为mergeList
	int subLen = 1; // 初始有序子序列的长度为1
	while (subLen < list.size())
	{
		// 进行一次merge，initList -> mergeList
		MergePass(list, tempList, subLen);
		subLen *= 2;
		// 进行另一次merge, mergeList -> initList
		MergePass(tempList, list, subLen);
		subLen *= 2;
	}
}

void MergePass(vector<int> &initList, vector<int> &mergeList, int subLen)
{
	// length为list总长，subLen为子序列长度
	int length = initList.size();
	int i = 0;
	while (i+2*subLen-1 < length)
	{
		// 为一行中的每两个子序列做一次归并
		Merge(initList, mergeList, i, i+subLen-1, i+2*subLen-1);
		i += 2*subLen;
	}
	// 处理剩余无法配对的子序列
	if (i+subLen < length) // 1. 可以进行一次归并，但子序列2比子序列1短
		Merge(initList, mergeList, i, i+subLen-1, length-1);
	else // 2. 只剩一个子序列，无需归并
	{
		for (int j = i; j < length-1; ++j)
			mergeList[j] = initList[j];
	}
}

// 完成一次2路归并，即两个有序list merge成一个有序list
// left..mid, mid+1..right
void Merge(vector<int> &initList, vector<int> &mergeList, int left, int mid, int right)
{
	int i = left, j = mid+1, k = i;
	while (i < mid+1 && j < right+1)
	{
		if (initList[i] <= initList[j])
			mergeList[k++] = initList[i++];
		else
			mergeList[k++] = initList[j++];
	}
	while (i < mid+1) // len(子序列1) > len(子序列2)
		mergeList[k++] = initList[i++]; // 将子序列1剩余的并入mergeList
	while (j < right+1) // len(子序列1) < len(子序列2)
		mergeList[k++] = initList[j++]; // 将子序列2剩余的并入mergeList
	
}