#include <stdio.h>
#include <limits.h>
int min(int n1, int n2)
{
    return n1 < n2 ? n1 : n2;
}

int build(int *ST, int *A, int S_index, int start, int end)
{
    //last calls mid will be itself
    if (start == end)
    {
        return A[start];
    }
    int mid = (start + end) / 2;
    //left child
    ST[S_index * 2] = build(ST, A, S_index * 2, start, mid);

    //right child
    ST[S_index * 2 + 1] = build(ST, A, S_index * 2 + 1, mid + 1, end);

    //update the current child
    ST[S_index] = min(ST[S_index * 2], ST[S_index * 2 + 1]);

    //return current child, as from here the calls were made
    return ST[S_index];
}

int query(int *ST, int S_index, int l, int r, int start, int end)
{
    if (r < start || end < l) //out of range node
    {
        return INT_MAX;
    }
    else if (l <= start && end <= r) //complete overlapping node
    {
        return ST[S_index];
    }
    else //partial overlapping node
    {
        int mid = (start + end) / 2;
        int left = query(ST, S_index * 2, l, r, start, mid);
        int right = query(ST, S_index * 2 + 1, l, r, mid + 1, end);
        return min(left, right);
    }
}
int update_node(int *ST, int S_index, int A_index, int value, int start, int end)
{
    //no need of no overlapping case, because we are manipulating calls to the desired node only
    if (start == end) // complete overlapping node (always the root in this case)
    {
        return value;
    }
    else //partial overlapping
    {
        int mid = (start + end) / 2;
        if (A_index <= mid)
        {
            ST[S_index * 2] =
                update_node(ST, S_index * 2, A_index, value, start, mid);
        }
        else
        {
            ST[S_index * 2 + 1] =
                update_node(ST, S_index * 2 + 1, A_index, value, mid + 1, end);
        }
        ST[S_index] = min(ST[S_index * 2], ST[S_index * 2 + 1]);
        return ST[S_index];
    }
}

int update_range(int *ST, int S_index, int A_l, int A_r, int increment, int start, int end)
{
    if (A_r < start || end < A_l) //out of range node
    {
        return ST[S_index];
    }
    else if (start == end) // complete overlapping on leaves is considered
    {
        return ST[S_index] + increment;
    }
    else //for partiall or complete overlapping we'll traverse both sides
    {
        int mid = (start + end) / 2;
        ST[S_index * 2] =
            update_range(ST, S_index * 2, A_l, A_r, increment, start, mid);
        ST[S_index * 2 + 1] =
            update_range(ST, S_index * 2 + 1, A_l, A_r, increment, mid + 1, end);
        ST[S_index] = min(ST[S_index * 2], ST[S_index * 2 + 1]);
        return ST[S_index];
    }
}

void main()
{
    int A[] = {1, 3, 2, 7, 9, 11};
    int N = sizeof(A) / sizeof(int);
    int ST[4 * N + 1];
    int i;
    for (i = 0; i < 4 * N + 1; i++)
        ST[i] = 0;

    ST[1] = build(ST, A, 1, 0, N - 1);

    printf("build tree :\n");
    for (i = 0; i < 4 * N + 1; i++)
        printf("%d ", ST[i]);

    int l = 1, r = 5;
    printf("\nmin in range[%d,%d] is: %d\n", l, r, query(ST, 1, l, r, 0, N - 1));

    int A_index = 4, value = -2;
    printf("\nupdating index %d with value %d\n", A_index, value);

    ST[1] = update_node(ST, 1, A_index, value, 0, N - 1);

    printf("updated tree after one node change:\n");
    for (i = 0; i < 4 * N + 1; i++)
        printf("%d ", ST[i]);
    printf("\n\nmaintaing back the orginal tree");
    ST[1] = update_node(ST, 1, A_index, A[A_index], 0, N - 1);

    printf("\noriginal tree :\n");
    for (i = 0; i < 4 * N + 1; i++)
        printf("%d ", ST[i]);

    int A_l = 2, A_r = 4, increment = -1;
    printf("\n\nincrementing A[%d,%d] with value %d", A_l, A_r, increment);
    update_range(ST, 1, A_l, A_r, increment, 0, N - 1);

    printf("\n\ntree after range update:\n");
    for (i = 0; i < 4 * N + 1; i++)
        printf("%d ", ST[i]);
}