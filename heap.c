#include "heap.h"
#include <stdlib.h>

void Init_Heap(Heap *h, int _length_)
{
	h->heap = (int*)malloc(sizeof(int)*(_length_+1)); // don't use 0-th
	h->_heap_alloc_ = _length_+1;
	h->_heap_size_ = 0;
}

void Insert_Heap(Heap *h, int data)
{
	int parent, child;
	if(!h)	return;
	if(h->_heap_size_+1 == h->_heap_alloc_){
		h->heap = (int*)realloc(h->heap, ++(h->_heap_alloc_));
	}
	h->heap[++(h->_heap_size_)] = data;
	child = h->_heap_size_;
	parent = child/2;
	while(child > 1)
	{
		// shift up
		if(h->heap[parent] < h->heap[child])
		{
			swap(&(h->heap[parent]), &(h->heap[child]));
			child = parent;
			parent = child/2;
		}
		else break;
	}
}

void HeapSort(int *heap, int _heap_size_)
{
	if(!heap)	return;
	int n = _heap_size_, parent, child;
	while(n>1)
	{
		swap(&(heap[1]), &(heap[n--]));
		parent = 1;
		child = parent*2;
		while(child <= n)
		{
			// shift down
			if(child < n && heap[child] < heap[child+1])	++child;
			if(heap[child] > heap[parent])
			{
				swap(&(heap[child]), &(heap[parent]));
				parent = child;
				child = parent*2;
			}
			else	break;
		}
	}
}

void Delete_Heap(Heap *h)
{
	if(!h)	return;
	free(h->heap);
}
