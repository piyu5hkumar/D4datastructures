#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000

/*

In 1 indexed approach the left and right childs of a node i are 2*i and 2*i+1 respectively,
the parent in this case is i/2

whereas in 0 indexed the left and right childs of a node i are 2*i+1 and 2*i+2 respectively,
the parent in this case is (i-1)/2


So we are using 0 indexed approach here(which is bydefault used in heap in c++ stl)
FOR THEORITICAL APPROACH ALWAYS GO FOR 1 BASED INDEX.

*/

void exchange(int *heap, int index1, int index2)
{
	int temp = heap[index1];
	heap[index1] = heap[index2];
	heap[index2] = temp;
}

void heapifyUp(int *heap, int currentNodeIndex)
{
	if (currentNodeIndex == 0) //not a possible node
		return;

	int parentIndex = (currentNodeIndex - 1 ) >> 1;

	if (heap[currentNodeIndex] < heap[parentIndex]) //it's smaller than its parentIndex, great!!!
		return;
	else
	{
		exchange(heap, currentNodeIndex, parentIndex);
		heapifyUp(heap, parentIndex);
	}
}

void heapifyDown(int *heap, int parentIndex, int size) //this is what we're gonna use
{
	int leftChildIndex = (parentIndex << 1) + 1;	// you can use i<<1|1
	int rightChildIndex = (parentIndex << 1) + 2;	// you can use (i+1)<<1
	int maxValueIndex = parentIndex;

	if (leftChildIndex < size && heap[leftChildIndex] > heap[maxValueIndex])
	{
		maxValueIndex = leftChildIndex;
	}

	if (rightChildIndex < size && heap[rightChildIndex] > heap[maxValueIndex])
	{
		maxValueIndex = rightChildIndex;
	}

	if (maxValueIndex != parentIndex)
	{
		exchange(heap, parentIndex, maxValueIndex);
		heapifyDown(heap, maxValueIndex, size);
	}
	else
	{
		return;
	}
}

void insert(int *heap, int value, int *size)
{
	if (*size == MAX_SIZE)
	{
		printf("Heap size can't be more than %d", MAX_SIZE);
		return;
	}

	heap[*size] = value;
	(*size)++;

	heapifyUp(heap, *(size) - 1);
}

void show(int *heap, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%d\t", heap[i]);
	}
	printf("\n");
}

void buildMaxHeap(int *arr, int size)
{
	printf("size is %d\n", size);
	/*
		-if it is was a 1 based array
	        then the leaves would have started from (size/2) + 1 index
	        or we can say that from [size/2 to 1] we have non leaf nodes.

	    -it is a 0 based array
	        therefore the leaves starts from size/2
	        or we can say that from [(size/2) - 1 to 0] we have non leaf nodes.

	    here size is the size of the heap
	*/

	for (int i = (size / 2) - 1; i >= 0; i--)
	{
		heapifyDown(arr, i, size);
	}
}

int peak(int *heap, int size)
{
	if (size <= 0)
	{
		printf("heap is empty returning garbage value");
		return -999;
	}
	else
		return heap[0];
}

void extractMax(int *heap, int *size)
{
	if (*size <= 0)
	{
		printf("Nothing to extract, heap is empty");
	}
	else
	{
		heap[0] = heap[*(size) - 1];
		(*size)--;
		heapifyDown(heap, 0, *size);
	}
}

void main()
{
	int size = 0;

	// int *heap = (int *)malloc(sizeof(int) * MAX_SIZE);
	// insert(heap, 10, &size);
	// show(heap, size);
	// insert(heap, 5, &size);
	// show(heap, size);
	// insert(heap, 3, &size);
	// show(heap, size);
	// insert(heap, 2, &size);
	// show(heap, size);
	// insert(heap, 4, &size);
	// show(heap, size);
	// insert(heap, 15, &size);
	// show(heap, size);

	printf("\n\nbuilding max heap from given array {4, 1, 3, 2, 16, 9, 10, 14, 8, 7}\n\n");

	int arr[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7}; //since we are not considering 0 index
	int arrSize = sizeof(arr) / sizeof(int);
	buildMaxHeap(arr, arrSize);
	show(arr, arrSize);
	printf("peaking %d\n", peak(arr, arrSize));
	extractMax(arr, &arrSize);

	show(arr, arrSize);
	printf("peaking %d\n", peak(arr, arrSize));
	extractMax(arr, &arrSize);

	show(arr, arrSize);
	printf("peaking %d\n", peak(arr, arrSize));
	extractMax(arr, &arrSize);

	show(arr, arrSize);
	printf("peaking %d\n", peak(arr, arrSize));

	// checking insert one more time
	insert(arr, 69, &arrSize);
	show(arr, arrSize);

}