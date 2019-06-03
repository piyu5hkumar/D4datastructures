#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left,*right;
}*root=NULL,*temp=NULL;

//to find max among two values
int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;    
}

//to find the height of the tree
int height(struct node *r)
{
    if(r==NULL)
    {
        return -1;
    }
    else
    {
        int left_height=height(r->left);
        int right_height=height(r->right);
        return (max(left_height,right_height)+1);
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
	
    inorder(root);
    printf("\nheight of the given tree is %d",height(root));
	return 0;
}

