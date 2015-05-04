#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

/**< heap >**/
#include "common.h"

typedef struct Heap
{
	int _heap_size_;
	int _heap_alloc_;
	int *heap; // will be allocated
} Heap;

void Init_Heap(Heap *h, int);
void Insert_Heap(Heap *h, int data);
void HeapSort(int *heap, int);
void Delete_Heap(Heap *h);

#endif // HEAP_H_INCLUDED
