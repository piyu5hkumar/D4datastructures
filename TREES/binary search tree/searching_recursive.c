#include<stdio.h>
#include<stdlib.h>
typedef struct node node;

typedef enum {true = 1, false = 0} bool;

struct node
{
    int data;
    node *left;
    node *right;
}*root = NULL,*temp = NULL;


node* new_node(int x)
{
    temp = (node*)malloc(sizeof(node));
    temp->left=NULL;
    temp->right=NULL;
    temp->data=x;
    return temp;
}


void insert(int x)
{
    if(root==NULL)
        root=new_node(x);
    else
    {
        node *current = root;
        node *visited;
        while(current)
        {
            visited = current;
            if(x<current->data)
                current=current->left;
            else
                current=current->right;
        }
        if(x<visited->data)
            visited->left=new_node(x);
        else
            visited->right=new_node(x);
    }
    
}


void inorder(node *r)
{
    if(r==NULL)
        return;
    inorder(r->left);
    printf("%d\t",r->data);
    inorder(r->right);
}


bool search(node *r,int x)
{
    if(r==NULL)
        return false;
    else if(x== r->data)
        return true;
    else if(x<r->data)
        return search(r->left,x);
    else
        return search(r->right,x);
}


void main()
{
    insert(0);
    insert(-1);
    insert(15);
    insert(10);
    insert(30);
    insert(20);
    insert(5);
    insert(11);
    insert(12);
    insert(3);
    insert(40);
    inorder(root);
    printf("\n");

    printf(search(root,3)==1?"found\n":"not found\n");
    printf(search(root,69)==1?"found\n":"not found\n");
    printf(search(root,40)==1?"found\n":"not found\n");
}