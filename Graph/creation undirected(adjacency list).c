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
    int n,adjv,weight,i;
    printf("Enter total number of vertices\t");
    scanf("%d",&n);

/* array of list */
	struct list v[n]; 

/* initializing each head and tail as we cant intialize default values in structure */
    for(i=0;i<n;i++)
	{
		(v[i]).head=NULL;
		(v[i]).tail=NULL;
	}

	for(i=0;i<n;i++)
	{
		printf("Enter adjacent vertices of v%d enter -1 when no adjacent vertices remains\n",i+1);
        printf("\n\nVertex number,weight\n");

        scanf("%d",&adjv);
        while(adjv>0)
        {
            scanf("%d",&weight);
            add(&(v[i]),adjv,weight);  //we are passing address of list '.' we are saving space
            scanf("%d",&adjv);
        }
	}

	printf("your graph is following\n");
	for(i=0;i<n;i++)
    {
        printf("vertices connected to v%d are \n",i+1);
        temp=(v[i]).head;
        while(temp)
        {
            printf("vertex = %d\t",temp->vertex);
            printf("weight = %d\n",temp->weight);
            temp=temp->adj;
        }
    }
return 0;
}
