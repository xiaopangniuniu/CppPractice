#include "SortingHeader.h"

int main(void)
{
	vector<int> list;
	int i(0), n(0);
	while (cin >> n)
	{
		list[i] = n;
		++i;
	}
	InsertSorting(list);
	BinInsertSorting(list);
	ShellSort(list);

	BubbleSort(list);
	QuickSort(list);

	SelectSorting(list);
	HeapSort(list);
	MergeSorting(list);
	return 0;
}