#include<iostream>
#include<queue>

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
};

template<class C>
class tree:public node<C>
{
	private:
		node<C> *root;
	public:
		tree();
		node<C>* getRoot(); 
		void insert(C);
		queue<C> ancestor(node<C> *,C);
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
void tree <C>:: insert(C value)			
{
	node<C> *temp = new node<C>;
	temp->data = value;

	if(root == NULL)
	{
		root=temp;
	}

	else
	{
		node<C> *current=root;					
		node<C> *prev = NULL;
		
		while(current)
		{
			prev=current;	
			if(temp->data > current->data)		
			{
				current=current->right;
			}
			else
			{
				current=current->left;			
			}
		}
		if (temp->data > prev->data)			
		{
			prev->right = temp;
		}
		else
		{
			prev->left = temp;					
		}

	}
} 

template<class C>
queue<C> tree<C> :: ancestor(node<C> *r,C value)
{
	queue<C> ancestor_list;
	while(r)
	{
		ancestor_list.push(r->data);
		if(r->data == value)
		{
			return ancestor_list;
		}
		else if(value < r->data)
		{
			r=r->left;
		}
		else
		{
			r=r->right;
		}
	}
	ancestor_list=queue<C>();
	return (ancestor_list);
}

int main()
{
	tree<int> obj;
	int value ;
	cin>>value;
	queue<int> a_list;
	/*some initialisation.You can also insert by asking to the user but i did so to make the things more clear*/
	obj.insert(50);	
	obj.insert(30);
	obj.insert(55);
	obj.insert(10);
	obj.insert(40);
	obj.insert(36);
	obj.insert(45);
	obj.insert(53);
	obj.insert(44);

	a_list = obj.ancestor(obj.getRoot(),value);

	if(a_list.size()<=1)
	{
		cout<<"no ancestor found\n";
	}
	else
	{
		cout<<"\nancestors of "<<value<<" are following (age wise)\n";
		while(a_list.size()!=1)
		{
			cout<< a_list.front()<<"\n";
			a_list.pop();
		}
	}

	return 0;
}
