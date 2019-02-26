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

//*tree class parameterized constructor.As soon as the object will be made its data will be assigned the passed value and the pointer will point to NULL*/

/* this will return the root of the tree's object */

template<class C>
node<C>* tree<C> :: getRoot()
{
	return root;
}

/* this will return the ancestor list of the node we just traveressed and checked */

template<class C>
stack<C> tree<C>::getAncestorList()
{
	return ancestor_list;
}

/* this will create the tree in the example we just showed */
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
/* recursive section */ 
	else
	{
		bool left,right;
		left=ancestor(r->left,value);
		if(left)
		{
			ancestor_list.push(r->data);
			return true;
		}
		else
		{
			right=ancestor(r->right,value);
			if(right)
			{
				ancestor_list.push(r->data);
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}

int main()
{
	tree<int> obj;
	int value ;
	value=46;
	
	obj.createTree();
	obj.ancestor(obj.getRoot(),value);
	stack<int> a_list = obj.getAncestorList();

	if(a_list.size()==0)
	{
		cout<<"no ancestor found\n";
	}
	else
	{
		cout<<"\nancestors of "<<value<<" are following (age wise)\n";
		while(a_list.size()!=0)
		{
			cout<< a_list.top()<<"\n";
			a_list.pop();
		}
	}

	return 0;
}
