#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left,*right;
}*root=NULL,*temp=NULL,*rootBST=NULL;

void insert_BST(struct node *r)
{
    r->left=NULL;
    r->right=NULL;
    if(rootBST==NULL)
    {
        rootBST=r;
    }
    else
    {
        struct node *prev=NULL;
        struct node *current=rootBST;
        while(current)
        {
            prev=current;
            if(r->data<current->data)
                current=current->left;
            else
                current=current->right;
        }
        if(r->data < prev->data)
            prev->left=r;
        else
            prev->right=r;
    }
    
}

void inorder(struct node *r)
{
    if(r==NULL)
        return;
    inorder(r->left);
    printf("%d\t",r->data);
    inorder(r->right);
}


/*
we cant do it with pre or inorder approach
because as you can see in insert_bst() we are nullifying 
left and right
so if by chance we passed a root then its left and
right will be nullified first

therefor we have to go for postorder
so that first left child then right child of root
gets passed(and even the pointer of those gets
changed,it won't affect the parent)
*/

void postorder_conversion(struct node *r)
{
	if(r==NULL)
	{
		return;	
	}	
	postorder_conversion(r->left);
    postorder_conversion(r->right);
	insert_BST(r);
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

	printf("your binary tree is\t");
    inorder(root);
    
    //converting
    postorder_conversion(root);
    
    printf("\nyour corresponding binary search tree is\t");
    inorder(rootBST);
   
    return 0;
}

