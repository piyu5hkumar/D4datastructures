#include<iostream>
#include<stack>
using namespace std;

struct node
{
	int data;
	struct node *left,*right;
}*root=NULL,*temp=NULL;



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

void preorder_iterative(struct node *r)
{
    if(r==NULL)
    {
        return;
    }

    stack<struct node*>st;
    st.push(r);
    while(!st.empty())
    {
        temp=st.top();
        cout<<temp->data<<"\t";
        st.pop();
        if(temp->right!=NULL)
            st.push(temp->right);
        if(temp->left!=NULL)
            st.push(temp->left);
    }
}


int main()
{
	insert_dummy();
	
    preorder_iterative(root);
    cout<<endl;
    return 0;
}
