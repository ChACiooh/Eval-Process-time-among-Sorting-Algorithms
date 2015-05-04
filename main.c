#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "heap.h"
#include "smpsort.h"
#include <time.h>

#define MAX_VAL	6

int randomNum[MAX_VAL+1][MAX_VAL*10000+1];
int check[MAX_VAL+1][60001];

void EvaluateProcessTimes(int* for_sort_, int __size__, void Sort(int* arr, int _size_))
{
    HANDLE hwnd;
    hwnd = GetCurrentProcess(); // current process handle
	ULONG64 start_time, end_time;
	QueryProcessCycleTime(hwnd, &start_time);

	/** <the time that I want to evalute with certain process> **/
	Sort(for_sort_, __size__);
    /***/
	QueryProcessCycleTime(hwnd, &end_time);
    printf("%12llu cycles\n", end_time - start_time);
}

void GenerateRandomVariable()
{
	int i, j, tmp;
	for(i=1;i<=MAX_VAL;i++)
	{
		for(j=1;j<=i*10000;j++)
		{
			tmp = (rand()*rand())%(i*10000)+1;
			if(check[i][tmp])
			{
				--j;
				continue;
			}
			check[i][tmp] = 1;
			randomNum[i][j] = tmp;
		}
	}
}

void evalute_along_number_of_elements(int _num_)
{
	Heap h;
	Init_Heap(&h, _num_);
	int i;
	int *for_insertion, *for_bubble, *for_selection;
	for_insertion = (int*)malloc(sizeof(int)*_num_);
	for_bubble = (int*)malloc(sizeof(int)*_num_);
	for_selection = (int*)malloc(sizeof(int)*_num_);

	/// generating
	for(i=0;i<_num_;i++)
	{
		for_insertion[i] = for_bubble[i] = for_selection[i] = randomNum[_num_/10000][i+1];
	}
	for(i=1;i<=_num_;i++)
	{
		Insert_Heap(&h, randomNum[_num_/10000][i]);
	}

	/// printing
	printf("%d elements\n", _num_);
	printf("Insertion sort : ");
	EvaluateProcessTimes(for_insertion, _num_, InsertionSort);
	printf("   Bubble sort : ");
	EvaluateProcessTimes(for_bubble, _num_, BubbleSort);
	printf("Selection sort : ");
	EvaluateProcessTimes(for_selection, _num_, SelectionSort);
	printf("     Heap sort : ");
	EvaluateProcessTimes(h.heap, h._heap_size_, HeapSort);
	puts(""); // for margine

	/// deletion
	free(for_insertion);
	free(for_bubble);
	free(for_selection);
	Delete_Heap(&h);
}

int main()
{
	srand(time(NULL));
	GenerateRandomVariable();
	int i;
	for(i=10000;i<=MAX_VAL*10000;i+=10000)
	{
		evalute_along_number_of_elements(i);
	}
	puts("end");
	getchar();
    return 0;
}
