#include "smpsort.h"

void BubbleSort(int *arr, int _size_)
{
	int i, j;
	for(i=_size_-1;i>=0;--i)
	{
		for(j=0;j<i;++j)
		{
			if(arr[j] > arr[j+1])	swap(arr+j, arr+j+1);
		}
	}
}

void InsertionSort(int *arr, int _size_)
{
	int i, j, temp;
	for(i = 1;i<_size_;++i)
	{
		temp = arr[i];
		for(j=i-1;j>=0 && arr[j] > temp;--j)
			arr[j+1] = arr[j];
		arr[j+1] = temp;
	}
}

void SelectionSort(int *arr, int _size_)
{
	int i, j, min, mj;
	for(i=0;i<_size_-1;i++)
	{
		min = arr[i];
		for(j=i+1;j<_size_;j++)
		{
			if(min > arr[j])
			{
				min = arr[j];
				mj = j;
			}
		}
		if(min != arr[i])
		{
			swap(arr+i, arr+mj);
		}
	}
}
