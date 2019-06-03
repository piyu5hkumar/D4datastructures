#include<stdio.h>
#include<math.h>

void reheap(int *,int,int);
void reheapUp(int *,int);

void insert(int *heap,int value,int *limit)
{
	(*limit)=(*limit)+1;
	heap[*limit]=value;
	reheapUp(heap,*limit);
}

int getmax(int *heap,int *limit)
{
	int root =heap[0];
	heap[0]=heap[*limit];
	*limit=*limit-1;
	reheap(heap,0,*limit);
	return root;
}
void reheap(int *heap,int pos,int limit)
{
	int left=(2*pos)+1;
	int right = left+1;
	int lvalue=0,rvalue=0;
	if(left<=limit)
	{
		lvalue=heap[left];
	}
	if(right<=limit)
	{
		rvalue=heap[right];
	}
	if(right > limit && left > limit)
	{
		return;
	}
	int temp=heap[pos], index;
	if(lvalue>heap[pos] && lvalue > rvalue)
	{
		heap[pos]=lvalue;
		heap[left]=temp;	
		index=left;
	}
	else
	{
		heap[pos]=rvalue;
		heap[right]=temp;
		index=right;
	}
	reheap( heap, index, limit);
}

void reheapUp(int *heap,int pos)
{
	if(pos<=0)
	{
		return;
	}
	
	int parent=floor((double)pos/2);
	if(heap[pos]>heap[parent])
	{
		int temp = heap[parent];
		heap[parent]=heap[pos];
		heap[pos]=temp;
		
		reheapUp(heap,parent);
	}
	return;	
	
}
int main()
{
	int heap[]={100,80,70,28,45,66,52,10,20,40};
	int limit=9;
	int choice;
	while(1)
	{
		printf("\n1.getmax\n");
		printf("2.insert an element\n");
		printf("3.see heap\n");
		printf("4.exit\n");
		scanf("%d",&choice);
		if(choice==1)
		{
			printf("\nmax = %d\n",getmax(heap,&limit));
		}
		else if(choice == 2)
		{
			int element;
			printf("Enter an element\t");
			scanf("%d",&element);
			insert(heap,element,&limit);
		}
		else if(choice==3)
		{
			int i;
			for(i=0;i<=limit;i++)
			{
				printf("%d\t",heap[i]);
			}
			printf("\n");
		}
		else if(choice == 4)
		{
			exit(0);
		}
		else
		{
			printf("\n\nEnter again\n\n");
		}
	}
	
	return 0;
}
