#include <stdio.h>
#include <stdlib.h>
typedef enum
{
    true = 1,
    false = 0
} bool;

typedef struct node node;

struct node
{
    int data;
    node *left;
    node *right;
    bool rightThread;
} *root = NULL, *temp = NULL;

node *createNode(int x)
{
    temp = (node *)malloc(sizeof(node));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    temp->rightThread = false;
    return temp;
}

void insert(int x)
{
    if (root == NULL)
    {
        root = createNode(x);
    }
    else
    {
        node *current = root;
        node *prev;
        while (current)
        {
            prev = current;
            if (x > current->data && current->rightThread == false)
                current = current->right;
            else if (x > current->data && current->rightThread == true)
                break;
            else
                current = current->left;
        }
        if (x > prev->data)
        {
            node *newNode = createNode(x);
            newNode->left = NULL;
            newNode->right = prev->right;
            newNode->rightThread = true;

            prev->rightThread = false;
            prev->right = newNode;
        }
        else
        {
            node *newNode = createNode(x);
            newNode->left = NULL;
            newNode->right = prev;
            newNode->rightThread = true;

            prev->left = newNode;
        }
    }
}

node *leftMostNode(node *r)
{
    if (r == NULL)
        return NULL;
    while (r->left)
        r = r->left;
    return r;
}

void traversal()
{
    temp = leftMostNode(root);

    while (temp)
    {
        printf("%d\t", temp->data);
        // temp = temp->right;
        if (temp->rightThread == true)
            temp = temp->right;
        else
        {
            temp = temp->right;
            temp = leftMostNode(temp);
        }
    }
    printf("\n");
}
void main()
{
    insert(6);
    insert(3);
    insert(5);
    insert(1);
    insert(8);
    insert(7);
    insert(11);
    insert(13);
    insert(9);
    traversal();
}