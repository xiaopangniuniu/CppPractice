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
#endif