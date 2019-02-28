#include<iostream>

/*

C++ program to delete an entire binary tree.

*/

using namespace std;

/* a base class is created which contain the data of every node in the tree */

template<class P>
class node
{
	public:
		P data;
		node *left,*right;
		node()
		{
			left=NULL;
			right= NULL;
		}
		node(P value)
		{
			data = value;
			left=right=NULL;
		}
};

/* class tree inheriting node class and having a root object of the node as its class member */

template<class C>
class tree:public node<C>
{
	private:
		node<C> *root;
	public:
		tree();
		node<C>* getRoot();
		void createTree();
		void del_tree(node<C> *);
};

/* tree class default constructor.As soon as the object will be made its root will be pointed to NULL */

template<class C>
tree<C> :: tree()
{
	root=NULL;
}

/* this will return the root of the tree's object */

template<class C>
node<C>* tree<C> :: getRoot()
{
	return root;
}

/* this will create the tree in the example we just shown */
template<class C>
void tree<C>::createTree()
{
	root=new node<C>(10);
	
	root->left=new node<C>(3);
	root->right=new node<C>(6);
	root->right->left=new node<C>(-2);
	root->right->right=new node<C>(1);
}

/* Postorder approach to delete the full tree */
template<class C>
bool tree<C> :: del__leaf_value(node<C> *r)
{

/* check if the current root is NULL or not*/	
	
	if(r==NULL)
	{
		return true;
	}
/* if not then traverse its left and right child and atlast delete the desired node */ 
	else if(del__leaf_value(r->left) & del__leaf_value(r->right))
	{
		if(r->data == value)
		{
			node *temp= r;
			r=NULL;
			delete(temp);
		}
		return false; 
	}
	else
	{
		return false;
	}
}

int main()
{
	tree<int> obj;
	int value ;
	value=46;
	
	obj.createTree();
	obj.del_tree(obj.getRoot());

	return 0;
}
