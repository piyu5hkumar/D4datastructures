#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left,*right;
}*root=NULL,*temp=NULL;



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

void inorder(struct node *r)
{
    if(r==NULL)
        return;
    inorder(r->left);
    printf("%d\t",r->data);
    inorder(r->right);
}

void preorder(struct node *r)
{
    if(r==NULL)
        return;
    printf("%d\t",r->data);
    preorder(r->left);
    preorder(r->right);
}

void postorder(struct node *r)
{
    if(r==NULL)
        return;
    postorder(r->left);
    postorder(r->right);
    printf("%d\t",r->data);
}

int main()
{
	insert_dummy();
	
    printf("inorder = ");inorder(root);
    printf("\npreorder = ");preorder(root);
    printf("\npostorder = ");postorder(root);
	return 0;
}

