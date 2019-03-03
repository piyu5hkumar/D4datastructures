#include<stdio.h>
#include<stdlib.h>

int wait[3];
int set_level;

struct node
{
	int node_p;
	int data;
	struct node *next_node;
}*node_loc=NULL,*temp_node=NULL,*p=NULL;

struct level
{
	int level_p;
	struct node *ptr;
	struct level *next_level;
	struct level *prev_level;
}*level_start=NULL,*temp_level=NULL,*level_loc=NULL;

void insert(int priority,int dec)
{
	if (level_start==NULL)
	{
		level_start=(struct level*)(malloc(sizeof(struct level)));
		level_start->level_p=priority;
		level_start->ptr=NULL;
		level_start->prev_level=NULL;
		level_start->next_level=NULL;

		level_loc=level_start;


	}
	else if(priority+dec<level_loc->level_p)
	{
		if(level_loc->prev_level==NULL)
		{
			temp_level=(struct level*)(malloc(sizeof(struct level)));
			temp_level->level_p=priority+dec;
			temp_level->ptr=NULL;
			temp_level->prev_level=NULL;
			temp_level->next_level=level_loc;
			level_loc->prev_level=temp_level;
			
			level_loc=temp_level;
			level_start=temp_level;
		}
		else
		{
				if(((level_loc->level_p)-(level_loc->prev_level->level_p))>1)
				{
					temp_level=(struct level*)(malloc(sizeof(struct level)));
					temp_level->level_p=priority+dec;
					temp_level->ptr=NULL;
					temp_level->prev_level=level_loc->prev_level;
					level_loc->prev_level->next_level=temp_level;
					temp_level->next_level=level_loc;
					level_loc->prev_level=temp_level;
	
					level_loc=temp_level;

				}
				else
				{
					level_loc=level_loc->prev_level;
				}
		}
			
	}
	else if ( priority+dec>level_loc->level_p)
	{
		if(level_loc->next_level==NULL)
		{
			
			temp_level=(struct level*)(malloc(sizeof(struct level)));
			temp_level->level_p=priority+dec;
			temp_level->ptr=NULL;
			temp_level->next_level=NULL;
			temp_level->prev_level=level_loc;
			level_loc->next_level=temp_level;
			level_loc=temp_level;
		}
		else
		{
			if(((level_loc->next_level->level_p)-(level_loc->level_p))>1)
			{printf("hiii\n");
				temp_level=(struct level*)(malloc(sizeof(struct level)));
				temp_level->level_p=priority+dec;
				temp_level->ptr=NULL;
				temp_level->next_level=level_loc->next_level;
				level_loc->next_level->prev_level=temp_level;
				temp_level->prev_level=level_loc;
				level_loc->next_level=temp_level;

				level_loc=temp_level;
			}
			else
			{
				level_loc=level_loc->next_level;
			}
		}
	}
	
	if(priority+dec==level_loc->level_p)
	{
		node_loc=level_loc->ptr;
		if(node_loc!=NULL)
		{
			while(node_loc->next_node)
			{
				node_loc=node_loc->next_node;
			}
		}
	}

	in_level(priority,level_loc,node_loc,dec);
}

void in_level(int priority,struct level *level_loc,struct node* node_loc,int dec)
{

{
		set_level=priority+dec;
		if(set_level==1)
		{
			if(wait[0]>=3)
			{
				insert(priority,1);
				return;
			}
			else
			{
				enqueue(level_loc,node_loc,&wait[0],priority);
			}
		}
		if (set_level==2)
		{
			if(wait[1]>=2)
			{
				insert(priority,dec+1);
				return;
			}
			else
			{
				enqueue(level_loc,node_loc,&wait[1],priority);
			}
		}
		if (set_level==3)
		{
			if (wait[2]>=1)
			{
				printf("insertion not possible\n");
			}
			else
			{
				enqueue(level_loc,node_loc,&wait[2],priority);
			}
		}
	}

}

void enqueue(struct level* curr_level,struct node* curr_node,int *wait,int priority)
{
	temp_node=(struct node*)(malloc(sizeof(struct node)));
	temp_node->next_node=NULL;
	temp_node->node_p=priority;
	printf("Enter the data of the node\t");
	scanf("%d",&(temp_node->data));

	if (curr_level->level_p-1==priority)
	{
		if (curr_node==NULL)
		{
			curr_level->ptr=temp_node;
		}
		else if (curr_node->node_p==priority)
		{
			
			curr_node->next_node=temp_node;
		}
		else
		{
			temp_node->next_node=curr_level->ptr;
			curr_level->ptr=temp_node;
		}
	}
	else if(curr_level->level_p-2==priority)
	{
		
		p=curr_level->prev_level->ptr;
		while(p->next_node)
		{
			p=p->next_node;
			
		}
		if(p->node_p>temp_node->node_p)
		{
			printf("insertion not possible\n");
			return;
		}
		else
		{
			curr_level->ptr=temp_node;
		}
		
		
	}
	else
	{
		if (curr_node==NULL)
		{
			curr_level->ptr=temp_node;
		}
		else
		{
			curr_node->next_node=temp_node;
		}
	}
	(*wait)++;
}



void show()
{
	temp_level=level_start;
	while(temp_level)
	{
		printf("priority of this level is %d and nodes under this level are\n",temp_level->level_p );
		temp_node=temp_level->ptr;
		while(temp_node)
		{
			printf("%d\t", temp_node->data);
			temp_node=temp_node->next_node;
		}
		printf("\n");
		temp_level=temp_level->next_level;
	}

}



/*
void delete()
{
	temp_level=level_start;
	
	if(temp_level->next_level==NULL)
	{
		if(temp_level->ptr==NULL)
		{
			printf("Enpty");
		}
		else if(temp_level->ptr->next_node==NULL)
		{
			free(temp_level->ptr);
			free(level_start);
			level_start =NULL;
		}
		else
		{
			temp_node=temp_level->ptr;
			temp_level->ptr=temp_level->ptr->next_node;
			free(temp_node);
		}
	}
	else
	{
		if
	}
}

*/



int main()
{
	set_level=0;
	int i,priority;
	for (i=0;i<3;i++)
	{
		wait[i]=0;
	}
	
	int option;
	char yes;
	do
	{
		printf("\n1.insert");
		printf("\n2.dequeue");
		printf("\n3.show queue\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				printf("Enter priority of the node\n");
				scanf("%d",&priority);
				if(priority>=1&&priority<=3)
					insert(priority,0);
				else
					printf("priorityis not in range\n");
				break;
			case 2:
			//	delete();
				break;
			case 3:
				show();
				break;
			default:
				printf("Wrong choice\n");
		}
		// fflush(stdin);
		// printf("\nDO YOU WANT TO ENTER AGAIN (press y for yes)\t");
		// scanf("%c",&yes);
		yes='y';
	}
	while(yes=='y'||yes=='Y');
return 0;
}
