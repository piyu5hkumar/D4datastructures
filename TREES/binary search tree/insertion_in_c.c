#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left,*right;
}*root = NULL,*temp = NULL;

struct node * create_node(int x)
{
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void insert(int x)
{
    if(root == NULL)
        root = create_node(x);
    else
    {
        struct node *next = root;
        struct node *prev = NULL;
        while(next)
        {
            prev = next;
            if(x < next->data)
                next = next->left;
            else
                next = next->right;
        }
        if(x < prev->data)
            prev->left = create_node(x);
        else
            prev->right = create_node(x); 
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

void main()
{
    insert(3);
    insert(55);
    insert(-6);
    insert(69);
    insert(0);
    inorder(root);
}