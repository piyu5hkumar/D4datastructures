#include<stdio.h>
#include<stdlib.h>

int arr[100];
int k=-1;
int l=0;

struct node
{
	int data;
	struct node *left,*right;
}*root=NULL,*temp=NULL;

/*
here inorder approach is necessary 
because our array is arranged in ascending order
*/
void convert_to_BST(struct node *r)
{
    if(r==NULL)
        return;
    convert_to_BST(r->left);
    r->data=arr[l++];
    convert_to_BST(r->right);
}

/*can use any approach*/
void inorderBT2BST(struct node *r)
{
    if(r==NULL)
        return;
    inorderBT2BST(r->left);
    arr[++k]=r->data;
    inorderBT2BST(r->right);
}

void inorder(struct node *r)
{
    if(r==NULL)
        return;
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

	printf("your binary tree before is\t");
    inorder(root);
    
    //converting
    inorderBT2BST(root);
    
    //use merge sort,im using insertion which is bad
    int i,j,key;
    for(i=1;i<=k;i++)
    {
        key=arr[i];
        j=i-1;
        while (j>=0 && key<arr[j])
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    
    convert_to_BST(root);

    printf("\nyour corresponding binary search tree is\t");
    inorder(root);
   
    return 0;
}

