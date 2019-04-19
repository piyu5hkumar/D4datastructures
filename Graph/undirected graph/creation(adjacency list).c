#include<stdio.h>
#include<stdlib.h>

/* structure of each node */
struct node
{
    int vertex;
    int weight;
    struct node *adj;
}*temp=NULL;

/* structure of each list */
struct list
{

/* cant do struct node *head=NULL(no initialization) */
  struct node *head;    
  struct node *tail;
};

void add(struct list *l,int v,int weight)
{
    temp=(struct node*)malloc(sizeof(struct node));
    temp->vertex=v;
    temp->weight=weight;
    temp->adj=NULL;
    if(l->head==NULL)
    {
        l->head=temp;
        l->tail=l->head;
    }
    else
    {
        l->tail->adj=temp;
        l->tail=temp;
    }
}

int main()
{
    int n,v,weight,i;
    printf("Enter total number of vertices\t");
    scanf("%d",&n);

/* array of list */
	struct list adjL[n]; 

/* initializing each head and tail as we cant intialize default values in structure */
    for(i=0;i<n;i++)
	{
		(adjL[i]).head=NULL;
		(adjL[i]).tail=NULL;
	}

	for(i=0;i<n;i++)
	{
		printf("Enter adjacent vertices of v%d enter -1 when no adjacent vertices remains\n",i);
        printf("\n\nVertex number,weight\n");

        scanf("%d",&v);
        while(v>-1)
        {
            scanf("%d",&weight);
            add(&(adjL[i]),v,weight);  //we are passing address of list '.' we are saving space
            scanf("%d",&v);
        }
	}

	printf("your graph is following\n");
	for(i=0;i<n;i++)
    {
        printf("vertices connected to v%d are \n",i);
        temp=(adjL[i]).head;
        while(temp)
        {
            printf("vertex = %d\t",temp->vertex);
            printf("weight = %d\n",temp->weight);
            temp=temp->adj;
        }
    }
return 0;
}
