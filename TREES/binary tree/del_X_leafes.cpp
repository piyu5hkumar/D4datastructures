#include<iostream>

/*

C++ program to delete leaf nodes with value as x
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
		void setRoot(node<C>*);
		void createTree();
		void inorder(node<C>*);
		node<C>* del_leaf_value(node<C>*,const int&);
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

/* A setter function to set the root of the tree */
template<class C>
void tree<C>::setRoot(node<C>*p)
{
	root=p;
}

/* this will create the tree in the example we just shown */
template<class C>
void tree<C>::createTree()
{
	root=new node<C>(10);
	
	root->left=new node<C>(3);
	root->left->right=new node<C>(10);
	root->right=new node<C>(6);
	root->right->left=new node<C>(10);
	root->right->right=new node<C>(4);
}

template<class C>
void tree<C>::inorder(node<C> *r)
{
	if (r==NULL) {
		return;
	}
	else
	{
		inorder(r->left);
		cout<<r->data<<"\t";
		inorder(r->right);
	}
	
	
}

/* Postorder approach to delete the full tree */
template<class C>
node<C>* tree<C>::del_leaf_value(node<C>*r,const int& value)
{
	if(r==NULL)
	{
		return NULL;
	}
	
	r->left=del_leaf_value(r->left,value);
	r->right=del_leaf_value(r->right,value);

	if(r->left==NULL && r->right==NULL && r->data == value)
	{
		delete(r);
		return NULL;
	}
	else
	{
		return r;
	}
	
}

int main()
{
	tree<int> obj;
	int value ;
	value=46;
	
	obj.createTree();
	obj.inorder(obj.getRoot());
	cout<<"\n";
	obj.setRoot(obj.del_leaf_value(obj.getRoot(),10));
	obj.inorder(obj.getRoot());
	return 0;
}
