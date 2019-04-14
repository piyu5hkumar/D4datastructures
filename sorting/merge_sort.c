#include<stdio.h>
#include<stdlib.h>
int *merged;
void merge(int *arr1,int *arr2,int size1,int size2)
{
    int i=0,j=0,k=0;
    while(i<=size1 && j<= size2)
    {
        if(arr1[i]<arr2[j])
        {
            merged[k]=arr1[i];
            i++;
        }
        else
        {
            merged[k]=arr2[j];
            j++;
        }
        k++;
    }
    while(i<=size1)
    {
        merged[k]=arr1[i];
        i++;
        k++;
    }
    while(j<=size2)
    {
        merged[k]=arr2[j];
        j++;
        k++;
    }
}

void enterarray(int *a,int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        scanf("%d",&a[i]);
    }
}
int main()
{
    int *arr1,*arr2,size1,size2,i;
    printf("Enter your first array size\t");
    scanf("%d",&size1);
    arr1=(int*)malloc(size1*sizeof(int));
    
    printf("Enter array 1(ascending order)\n");
    enterarray(arr1,size1);

    printf("Enter your second array size\t");
    scanf("%d",&size2);
    arr2=(int*)malloc(size2*sizeof(int));
    
    printf("Enter array 2(ascending order)\n");
    enterarray(arr2,size2);
    
    merged=(int*)malloc((size1+size2)*sizeof(int));
    
    merge(arr1,arr2,size1-1,size2-1);

    printf("\n\nmerged array is\n");
    for(i=0;i<(size1+size2);i++)
    {
        printf("%d\t",merged[i]);
    }
    return 0;
}
