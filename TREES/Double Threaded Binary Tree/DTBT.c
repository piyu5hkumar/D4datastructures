#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left,*right;
    int lthread,rthread;
}*root=NULL,*temp=NULL;
void insert(int x)
{
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->left=NULL;
    temp->right=NULL;
    temp->lthread=0;
    temp->rthread=0;
    if(root==NULL)
    {
        root=temp;
    }
    else
    {
        struct node *curr=root;
        struct node *parent;
        while(curr)
        {
            parent=curr;
            if(temp->data < curr->data)
            {
                if(curr->lthread==1)
                {
                    break;
                }
                curr=curr->left;
            }
            else
            {
                if(curr->rthread==1)
                {
                    break;
                }
                curr=curr->right;
            }
        }
        if(temp->data < parent->data)
        {
            temp->right=parent;
            temp->rthread=1;
            temp->left=parent->left;
            if(parent->left!=NULL)
            {
                temp->lthread=1;
            }
            parent->left=temp;
            parent->lthread=0;
        }
        else
        {
            temp->left=parent;
            temp->lthread=1;
            temp->right=parent->right;
            if(parent->right!=NULL)
            {
                temp->rthread=1;
            }
            parent->right=temp;
            parent->rthread=0;
        }
    }
}
struct node *leftmost(struct node *p)
{
    if(p==NULL)
    {
        return NULL;
    }
    else
    {
        while(p->left)
        {
            if(p->lthread==1)
            {
                break;
            }
            p=p->left;
        }
        return p;
    }
};
void inorder(struct node *r)
{
    r=leftmost(r);
    while(r)
    {
        printf("%d\t",r->data);
        if(r->rthread==1)
        {
            r=r->right;
        }
        else
        {
            if(r->right==NULL)
                printf("stop now\n");
            r=leftmost(r->right);
        }
    }
}
int main()
{
    insert(50);
    insert(45);
    insert(65);
    insert(10);
    insert(47);
    insert(60);
    insert(80);
    insert(70);
    insert(75);
    inorder(root);
    return 0;
}
