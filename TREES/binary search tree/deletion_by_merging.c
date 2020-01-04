/*
this program is only applicable for deleting nodes
which has two child 
*/
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
node* rightmost(node *r)
{
    if(r->right==NULL)
        return r;
    return rightmost(r->right);
    /*
    //below code is for iterative approach
    node *current = r;
    node *predecessor;
    while(current)
    {
        predecessor = current;
        current = current->right;
    }
    return predecessor;    
    */
}
void delete(int x)
{
    node *current = root;
    node *pred=NULL;
    node *rchild;
    while(current)
    {
        if(x==current->data)
        { 
            //step 1
            rchild=rightmost(current->left);
            printf("rightmost child is %d\n",rchild->data);
            
            //step 2
            rchild->right=current->right;

            if(pred!=NULL) // it means the node to be deleted is not root
            {
                //step 3
                if(pred->right==current)
                    pred->right=current->left;
                else 
                    pred->left=current->left;
                
                //step 4
                current=NULL;
                free(current);
            }
            else // that means the node to be deleted is a root
            {
                temp=root;
                
                //step 3
                root=current->left;

                //step 4
                //free(temp);
            }
            break;
        }

        //always assign predeccor just before shifting
        pred =current;
        
        if(x<current->data)
            current=current->left;
        else
            current=current->right;
        
        
    }
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
    printf("deleting 15\n");
    delete(15);
    inorder(root);
    printf("\n");
    printf("deleting 10\n");
    delete(10);
    inorder(root);
    printf("\n");
    printf("deleting 0\n");
    delete(0);
    inorder(root);
    printf("\n");
}