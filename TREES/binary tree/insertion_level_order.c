#include<stdio.h>
#include<stdlib.h>

typedef enum boolvlaues{true=1,false=0} bool;

struct node
{
	int data;
	struct node *left,*right;
}*root=NULL,*temp=NULL;

struct queue
{
	struct node *tdata;
	struct queue *next;
}*front=NULL,*rear=NULL,*qtemp=NULL;

void push(struct node *x)
{
	qtemp=(struct queue*)malloc(sizeof(struct queue));
	qtemp->tdata=x;
	
	if(front==NULL)
	{
		front=qtemp;
		rear=front;
	}
	else
	{
		rear->next=qtemp;
		rear=qtemp;
	}
};

struct node* frontv()
{
	return front->tdata;
}

void pop()
{
	if(rear==NULL)
	{
		return;
	}
	else if(front==rear)
	{
		free (front);
		front=NULL;
		rear=NULL;
	}
	else
	{
		qtemp=front;
		front=front->next;
		free(qtemp);
	}
}

bool isempty()
{
	if(rear==NULL)
		return true;
	else
		return false;
}

void insert(int x)
{
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->left=NULL;
	temp->right=NULL;
	
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		struct node *p =NULL;
		push(root);
		while(!isempty())
		{
			p=frontv();
			pop();			

			if(p->left==NULL)
			{
				p->left=temp;
				break;
			}
			/* dont forget break and else */
			else
			{
				push(p->left);
			}
			if(p->right==NULL)
			{
				p->right=temp;
				break;
			}
			else
			{
				push(p->right);
			};
		}
		while(!isempty()){pop();}; //we have to empty the queue
	}
}

void inorder(struct node *r)
{
	if(r==NULL)
	{
		return;	
	}	
	inorder(r->left);
	printf("%d\t",r->data);
	inorder(r->right);
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

int main()
{
	insert_dummy();
	
	insert(55);
	insert(44);
	insert(999);
	inorder(root);
	return 0;
}

