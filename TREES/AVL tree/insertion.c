#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef struct node node;

struct node
{
    int data;
    int height;
    node *left;
    node *right;
} *root = NULL, *temp = NULL;

int max(int n1, int n2)
{
    return n1 > n2 ? n1 : n2;
}

node *new_node(int value)
{
    temp = (node *)malloc(sizeof(node));
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    temp->height = 0;
    return temp;
}
int get_height(node *x)
{
    if (x == NULL)
    {
        return -1;
    }

    return x->height;
}

node *insert(node *r, int value)
{
    if (r == NULL)
    {
        return new_node(value);
    }
    else
    {
        if (value < r->data)
            r->left = insert(r->left, value);
        else
            r->right = insert(r->right, value);

        int height = max(get_height(r->left), get_height(r->right)) + 1;
        int balance_factor = get_height(r->left) - get_height(r->right);
        return r;
    }
}

void inorder(node *r)
{
    if (r == NULL)
        return;
    inorder(r->left);
    printf("node = %d, height = %d\n", r->data, r->height);
    inorder(r->right);
}

void main()
{
    root = insert(root, 10);  
    root = insert(root, 20);  
    root = insert(root, 30);  
    root = insert(root, 40);  
    root = insert(root, 50);  
    root = insert(root, 25);
    
    inorder(root);
}