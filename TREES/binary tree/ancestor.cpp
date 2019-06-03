#include<iostream>
#include<stack>

/*

C++ program to print ancestors of a given node in binary tree.

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
		stack<C> ancestor_list;
	public:
		tree();
		node<C>* getRoot();
		stack<C> getAncestorList();
		void createTree();
		bool ancestor(node<C> *,C);
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

/* this will return the ancestor list of the node we just traversed and checked */

template<class C>
stack<C> tree<C>::getAncestorList()
{
	return ancestor_list;
}

/* this will create the tree in the example we just shown */
template<class C>
void tree<C>::createTree()
{
	root=new node<C>(50);
	
	root->left=new node<C>(80);
	root->left->left=new node<C>(10);
	root->left->right=new node<C>(40);
	root->left->right->left=new node<C>(46);

	root->right=new node<C>(9);
}

/* A recursive function to find the ancestor of a node */
template<class C>
bool tree<C> :: ancestor(node<C> *r,C value)
{

/* check if the current root is NULL or not*/	
	
	if(r==NULL)
	{
		return false;
	}

/* this will check if the current node is value or not */
	
	else if(r->data == value)
	{
		return true;
	}

/* recursive section where we OR the bool value from the left and right subtree of the root */ 
	
	else if(ancestor(r->left,value) | ancestor(r->right,value) )
	{
		ancestor_list.push(r->data);
		return true;
	}

/* if nothing found or the above condition is also false */

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
	obj.ancestor(obj.getRoot(),value);

/* a_list will store the ancestor list stack */

	stack<int> a_list = obj.getAncestorList();

/* if there is no ancestor then there might a case of no node found or the root being the node that was the node to be searched upon */
	
	if(a_list.size()==0)
	{
		cout<<"no ancestor found\n";
	}

/* if there are ancesotor just show them */

	else
	{
		cout<<"\nancestors of "<<value<<" are following\n";
		while(a_list.size()!=0)
		{
			cout<< a_list.top()<<"\n";
			a_list.pop();
		}
	}

	return 0;
}
