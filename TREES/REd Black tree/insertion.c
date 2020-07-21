/*

Algo reference taken from CLRS

*/

#include <stdio.h>
#include <stdlib.h>

#define RED 1
#define BLACK 0
#define NIL NULL //it is sentinal, it's color is assumed to be black

typedef struct node node;

struct node
{
    int data;
    node *left;
    node *right;
    node *parent;
    int color;
} * root, *temp, *uncle;

node *right_rotate(node *pivot)
{
    node *grandParent = pivot->parent;
    node *child = pivot->left;

    if (grandParent == NIL)
    {
        root = child;
        child->parent = NIL;
    }
    else
    {
        if (pivot == grandParent->left)
        {
            grandParent->left = child;
        }
        else
        {
            grandParent->right = child;
        }
        child->parent = grandParent;
    }

    pivot->left = child->right;
    if (child->right != NIL)
    {
        child->right->parent = pivot;
    }

    child->right = pivot;
    pivot->parent = child;

    return pivot;
}

node *left_rotate(node *pivot)
{
    node *grandParent = pivot->parent;
    node *child = pivot->right;

    if (grandParent == NIL)
    {
        root = child;
        child->parent = NIL;
    }
    else
    {
        if (pivot == grandParent->left)
        {
            grandParent->left = child;
        }
        else
        {
            grandParent->right = child;
        }

        child->parent = grandParent;
    }

    pivot->right = child->left;
    if (child->left != NIL)
    {
        child->left->parent = pivot;
    }

    child->left = pivot;
    pivot->parent = child;
    return pivot;
}

node *newNode(int value)
{
    temp = (node *)malloc(sizeof(node));
    temp->data = value;
    temp->left = NIL;
    temp->right = NIL;
    temp->color = RED;
}

void insert_fixUp(node *Z)
{
    /*
        we have to extensively use short circuit operators
        as NIL is nothing but NULL which is acting as sentinal
    */

    while (Z != NIL && Z->parent != NIL && Z->parent->color != BLACK)
    {
        /*
            we are not checking Z->parent->parent!=NILL
            because that case will never occur :) thanks to short ciruit operators
            and root being black

            -   lets say the Z becomes root ultimately then due to second condition loop terminates
            -   if Z comes to the level 1(after root level) then the third condition makes the loop terminate
                as root is black :)
            -   tbh first condition never comes into play
        */
        printf("fixing %d\n", Z->data);

        if (Z->parent == Z->parent->parent->left) //Parent is left of GrandParent
        {
            uncle = Z->parent->parent->right;

            if (uncle != NIL && uncle->color == RED) //if NIL was there then it would've been black
            {
                //this is case 1
                Z->parent->color = BLACK;
                uncle->color = BLACK;

                Z->parent->parent->color = RED;
                Z = Z->parent->parent;
            }
            else if (uncle == NIL || uncle->color == BLACK) //if NIL was there then it would've been black
            {

                if (Z == Z->parent->right) // this will be left right case for Z
                {
                    //case 2 LR
                    Z = left_rotate(Z->parent);
                }
                else
                {
                    //case 3 LL
                    Z = right_rotate(Z->parent->parent);
                    Z->parent->color = BLACK;
                    Z->color = RED;
                }
            }
        }

        else //Parent is in right to GrandParent
        {
            uncle = Z->parent->parent->left;

            if (uncle != NIL && uncle->color == RED) //if NIL was there then it would've been black
            {
                //this is again case 1
                Z->parent->color = BLACK;
                uncle->color = BLACK;

                Z->parent->parent->color = RED;
                Z = Z->parent->parent;
            }
            else if (uncle == NIL || uncle->color == BLACK) //if NIL was there then it would've been blac
            {
                if (Z == Z->parent->left)
                {
                    //case 2 RL
                    Z = right_rotate(Z->parent);
                }
                else
                {
                    //case 3 RR
                    Z = left_rotate(Z->parent->parent);
                    Z->parent->color = BLACK;
                    Z->color = RED;
                }
            }
        }
    }

    root->color = BLACK;
}

void insert(int value) //can't do it recursively
{
    node *prev = NULL;
    node *curr = root;

    while (curr)
    {
        prev = curr;
        if (value < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }

    node *Z = newNode(value);

    if (prev == NULL) //this means the it's a root, use this approach now onwards for the insertion in iterative fashion
    {
        root = Z;
        root->parent = NIL;
    }
    else if (value < prev->data)
    {
        prev->left = Z;
        prev->left->parent = prev;
    }
    else
    {
        prev->right = Z;
        prev->right->parent = prev;
    }
    insert_fixUp(Z);
}

void inorder(node *r)
{
    if (r == NIL)
        return;

    inorder(r->left);

    printf("%d", r->data);
    printf(r->color == RED ? " RED\n" : " BLACK\n");

    inorder(r->right);
}
void main()
{
    insert(20);
    insert(1);
    insert(5);
    insert(-55);
    insert(100);
    insert(99);

    insert(7); 
    insert(6); 
    insert(5); 
    insert(4); 
    insert(3); 
    insert(2); 
    insert(1); 
    insert(10);
    insert(22);

    printf("\n\n");
    inorder(root);  //you can also show level order, but that would be to much for this :)

}