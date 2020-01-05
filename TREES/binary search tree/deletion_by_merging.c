
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


void freemem(node *prev,node *current,node *tobepointed)
{
    if(prev==NULL)
    {
        temp=root;
        root=tobepointed;
        free(temp);
    }
    else
    {
        if(prev->left==current)
            prev->left=tobepointed;
        else
            prev->right=tobepointed;
    }
    free(current);
}

void delete(int x)
{
    node *current = root;
    node *prev=NULL;
    node *rchild;
    while(current)
    {
        if(x==current->data)
        {
            //case 1, no child
            if(current->left==NULL&&current->right==NULL)
            {
                freemem(prev,current,NULL);
            }

            //case 2, one child
            else if((current->left==NULL ^ current->right==NULL)==1)
            {
                if(current->left!=NULL)
                    freemem(prev,current,current->left);
                else
                    freemem(prev,current,current->right);
            }

            //case 3, two child
            else 
            {
                //step 1
                rchild=rightmost(current->left);
                printf("rightmost child is %d\n",rchild->data);
                
                //step 2
                rchild->right=current->right;

                //step 3 and step 4
                freemem(prev,current,current->left);

            }
            
            break;
        }

        //always assign predeccor just before shifting
        prev =current;
        
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

    printf("deleting 12\n"); //no child node
    delete(12);
    inorder(root);
    printf("\n");
    
    printf("deleting 5\n"); //one child node
    delete(5);
    inorder(root);
    printf("\n");

    printf("deleting 15\n"); //two child node
    delete(15);
    inorder(root);
    printf("\n");

    printf("deleting 10\n"); //two child node
    delete(10);
    inorder(root);
    printf("\n");
    
    printf("deleting 0\n"); //two child node
    delete(0);
    inorder(root);
    printf("\n");
}