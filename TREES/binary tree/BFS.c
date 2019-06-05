#include<stdio.h>
#include<stdlib.h>

typedef enum boolean{true=1,false=0} bool;

struct node* queue[1000];
int rear=-1;
int front =-1;

void push(struct node*);
void pop();
struct node* first();
bool isempty();

struct node
{
	int data;
	struct node *left,*right;
}*root=NULL,*temp=NULL;


void BFS(struct node *r)
{
	if(r==NULL)
	{
		return;	
	}
    push(r);
    while(!isempty())
    {
        temp=first();
        pop();
        printf("%d \t",temp->data);
        if(temp->left)
            push(temp->left);
        if(temp->right)
            push(temp->right);
        
	}

}

void insert_dummy()
{
	root=(struct node*)malloc(sizeof(struct node));
	root->data=1;
	root->left=(struct node*)malloc(sizeof(struct node));
	root->left->data=5;
	root->left->left=NULL;
	root->left->right=NULL;
	root->right=(struct node*)malloc(sizeof(struct node));
	root->right->data=6;
	root->right->left=(struct node*)malloc(sizeof(struct node));
	root->right->left->data=10;
	root->right->left->left=NULL;
	root->right->left->right=NULL;
	root->right->right=NULL;
/*
	1
   /\
  5	 6
  	/
   10
	 
*/	

}


void push(struct node* r)
{
    if(rear==-1)
    {
        front=0;
    }
    if(rear<100)
    {
        queue[++rear]=r;
    }   
}
struct node* first()
{
	return queue[front];
}
void pop()
{
    if(front==-1)
        return;
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
    {
        front++;
    }
    
}

bool isempty()
{
    if(rear==-1)
        return true;
    else
        return false;
    
}
int main()
{
	insert_dummy();
	BFS(root);

	return 0;
}

