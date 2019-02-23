#include<iostream>
#include<stack>

using namespace std;

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

template<class C>
tree<C> :: tree()
{
	root=NULL;
}

template<class C>
node<C>* tree<C> :: getRoot()
{
	return root;
}

template<class C>
stack<C> tree<C>::getAncestorList()
{
	return ancestor_list;
}

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

template<class C>
bool tree<C> :: ancestor(node<C> *r,C value)
{
	
	if(r==NULL)
	{
		return false;
	}
	else if(r->data == value)
	{
		return true;
	}
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
