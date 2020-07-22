#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000

void exchange(int *heap, int index1, int index2)
{
    int temp = heap[index1];
    heap[index1] = heap[index2];
    heap[index2] = temp;
}

void heapify(int *heap, int currentNodeIndex)
{
    if (currentNodeIndex == 0) //not a possible node
        return;

    int parentIndex = currentNodeIndex >> 1;

    if (heap[currentNodeIndex] < heap[parentIndex]) //it's smaller than its parentIndex, great!!!
        return;
    else
    {
        exchange(heap, currentNodeIndex, parentIndex);
        heapify(heap, parentIndex);
    }
}

void insert(int *heap, int value, int *lastIndex)
{
    if (*lastIndex == MAX_SIZE)
    {
        printf("Heap size can't be more than %d", MAX_SIZE);
        return;
    }
    (*lastIndex)++;
    heap[*lastIndex] = value;
    heapify(heap, *lastIndex);
}

void show(int *heap, int lastIndex)
{
    int i;
    for (i = 1; i <= lastIndex; i++)
    {
        printf("%d\t", heap[i]);
    }
    printf("\n");
}
void main()
{
    int lastIndex = 0;
    /*
        heap should start from index 1 
        because of the following 2 problems
        
        1. Since 0's left child will be 2*0 = 0, which is 0 itself
        so it's wrong.
        
        2. Problem while heapifying at index 2
        because it's parent will be 1
         0
        /\
        1 2

        and you can clearly see it's not the case if we take 0 index as the root

        ------------------------

        with 1 as root index

        1
        /\ 
        2 3

        now it's fine.

        --------------

        I've taken lastIndex as 0 because we are increamenting and then inserting,
        so the first element should be inserted at index 1
    */
    int *heap = (int *)malloc(sizeof(int) * MAX_SIZE);
    insert(heap, 10, &lastIndex);
    show(heap, lastIndex);
    insert(heap, 5, &lastIndex);
    show(heap, lastIndex);
    insert(heap, 3, &lastIndex);
    show(heap, lastIndex);
    insert(heap, 2, &lastIndex);
    show(heap, lastIndex);
    insert(heap, 4, &lastIndex);
    show(heap, lastIndex);
    insert(heap, 15, &lastIndex);
    show(heap, lastIndex);
}