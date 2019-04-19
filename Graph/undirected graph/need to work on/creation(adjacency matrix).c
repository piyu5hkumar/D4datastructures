#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int *queue;
int *visited;
int top=-1;
struct node
{
    int vertex;
    struct node *adj;
}*temp=NULL;

struct list
{
  struct node *head;    
  struct node *tail;
};

void add(struct list *l,int v)
{
	temp=(struct node*)malloc(sizeof(struct node));
    temp->vertex=v;
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

void create(int adj[100][100],int total,struct list *adjL)
{
    int i,j,v;
    for(i=0;i<total;i++)
    {
        printf("enter verteces adjacent to vertex%d (-1 if no vertex left)\n",i);
        scanf("%d",&v);
        while(v>=0)
        {
            add(&(adjL[i]),v);
            scanf("%d",&v);
        }
    }
}

void enqueue(int x)
{
    queue[++top]=x;
}
int dequeue()
{
    return queue[top--];
}
int isQueueEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}

void BFS(struct list *adjL,int start)
{
    enqueue(start);
    visited[start]=1;
    int dequeued;
    while(top!=-1)
    {
        dequeued=dequeue();
        printf("%d\t",dequeued);
        temp=adjL[dequeued].head;
        while(temp)
        {
            if(visited[temp->vertex]==0)
            {
                enqueue(temp->vertex);
                visited[temp->vertex]=1;
            }  
            temp=temp->adj;
        }
    }
   printf("\n");
}

int main()
{
    int i,v,n;
    printf("Enter total number of vertices\t");
    scanf("%d",&n);
    
    queue=(int *)malloc(n*sizeof(int));
    visited =(int *)malloc(n*sizeof(int));

    struct list *adjL = (struct list*)malloc(n*sizeof(struct list));
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
            add(&(adjL[i]),v);  //we are passing address of list '.' we are saving space
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
            temp=temp->adj;
        }
    }
    create(adjM,total,adjL);
    
    

    return 0;
}
