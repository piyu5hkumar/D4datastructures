#include<stdio.h>
#include<stdlib.h>
typedef struct node node;

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
void preorder(node *r)
{
    if(r==NULL)
        return;
    printf("%d\t",r->data);
    preorder(r->left);
    preorder(r->right);
}

void postorder(node *r)
{
    if(r==NULL)
        return;
    postorder(r->left);
    postorder(r->right);
    printf("%d\t",r->data);
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
    
    printf("inorder = ");
    inorder(root);
    printf("\n");
    
    printf("preorder = ");
    preorder(root);
    printf("\n");
    
    printf("postorder = ");
    postorder(root);
    printf("\n");
}