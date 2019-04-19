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

/* this will find the minimun of available weights */
int find_min_cost_vertex(int *found,int *weight,int size)
{
    int i,min_vertex,min_weight=INT_MAX;

    for(i=0;i<size;i++)
    {
        if(found[i]==0 && weight[i]<=min_weight)
        {
            min_weight=weight[i];
            min_vertex=i;
        }
    }
    return min_vertex;
}

struct list *prims(struct list *adjL,int size)
{
    struct list mst;
    int found[size],i;
    int weight[size];
    int inserted=0;
    int min=0;
    int total_weight=0;

    mst.head=NULL;
    mst.tail=NULL;

    for(i=0;i<size;i++)
    {
        found[i]=0;
        weight[i]=INT_MAX;
    }
    weight[0]=0;
    while(inserted!=size)
    {
        
        min=find_min_cost_vertex(found,weight,size);
        printf("weight found = %d\n",weight[min]);
        total_weight+=weight[min];
        add(&mst,min,weight[min]);
        found[min]=1;
        temp=adjL[min].head;
        while(temp)
        {
            //update the weight if new edge weight is lesser else leave it
            if(temp->weight<weight[temp->vertex])
            {
                weight[temp->vertex]=temp->weight;
            }
            temp=temp->adj;
        }

        inserted++;
    }
    printf("\ntotal weight is %d\n",total_weight);
    return mst.head;
}
int main()
{
    int n,v,weight,i;
    printf("Enter total number of verteces\t");
    scanf("%d",&n);

/* array of list */
	struct list adjL[n]; 

/* initializing each head and tail as we cant intialize default values in structure */
    for(i=0;i<n;i++)
	{
		(adjL[i]).head=NULL;
		(adjL[i]).tail=NULL;
	}

    printf("\nEnter your adjacency list\n\n");
    
    printf("\nEnter -1 in case there is no vertex left for adjacency\n");
    for(i=0;i<n;i++)
    {
        printf("Enter vertices and their weight adjacent to vertex v%d\n",i);
        scanf("%d",&v);
        while(v>-1)
        {
            scanf("%d",&weight);
            add(&adjL[i],v,weight);
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
    
	printf("\n\n");
    
	temp= prims(adjL,n);
	
	printf("\n\n");
	while(temp)
	{
		printf("%d\t",temp->vertex);
		temp=temp->adj;
	}
    
    

return 0;
}
