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

int find_min_cost_vertex(int *found,int *weight,int size)
{
    int i,min_vertex,min_weight;
    
    for(i=0;i<size;i++)
    {
        if(found[i]==0)
        {
            min_weight = weight[i];
            break;
        }
    }

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

struct list *prims(struct list *v,int size)
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

        total_weight+=weight[min];
        add(&mst,min,weight[min]);
        found[min]=1;
        temp=v[min].head;
        while(temp)
        {
            weight[temp->vertex]=temp->weight;
            temp=temp->adj;
        }

        inserted++;
    }
    return mst.head;
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
		printf("Enter adjacent vertices of v%d enter -1 when no adjacent vertices remains\n",i);
        printf("\n\nVertex number,weight\n");
		fflush(stdin);
        scanf("%d",&adjv);
        while(adjv>0)
        {
        	//fflush(stdin);
            scanf("%d",&weight);
            add(&(v[i]),adjv,weight);  //we are passing address of list '.' we are saving space
            scanf("%d",&adjv);
        }
	}

    // add(&v[0],1,2);
    // add(&v[0],2,8);
    // add(&v[0],3,4);
    // add(&v[0],4,6);
	
    // add(&v[1],0,2);
    // add(&v[1],2,7);
    // add(&v[1],3,4);
    // add(&v[1],4,6);

    // add(&v[2],0,8);
    // add(&v[2],1,7);
    // add(&v[2],3,9);
    // add(&v[2],4,8);

    // add(&v[3],0,4);
    // add(&v[3],1,4);
    // add(&v[3],2,9);
    // add(&v[3],4,5);

    // add(&v[4],0,6);
    // add(&v[4],1,6);
    // add(&v[4],2,8);
    // add(&v[4],3,5);

    printf("your graph is following\n");
	for(i=0;i<n;i++)
    {
        printf("vertices connected to v%d are \n",i);
        temp=(v[i]).head;
        while(temp)
        {
            printf("vertex = %d\t",temp->vertex);
            printf("weight = %d\n",temp->weight);
            temp=temp->adj;
        }
    }

    temp= prims(v,n);
	while(temp)
	{
		printf("%d\t",temp->vertex);
		temp=temp->adj;
	}
    
    

return 0;
}
