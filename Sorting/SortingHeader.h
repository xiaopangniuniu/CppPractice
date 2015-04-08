#ifndef __SORTING_H__
#include <iostream>
#include <vector>
using namespace std;

void InsertSorting(vector<int> &list);
void BinInsertSorting(vector<int> &list);
void ShellSort(vector<int> &list);

void BubbleSort(vector<int> &list);
void Qsort(vector<int> &list, int low, int high);
void QuickSort(vector<int> &list);

void SelectSorting(vector<int> &list);
void HeapAdjust(vector<int> &list, int root, int last);
void HeapSort(vector<int> &list);

void Merge(vector<int> &initList, vector<int> &mergeList, int left, int mid, int right);
void MergePass(vector<int> &initList, vector<int> &mergeList, int subLen);
void MergeSorting(vector<int> &list);
#endif