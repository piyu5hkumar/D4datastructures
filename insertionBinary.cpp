#include<iostream>
using namespace std;

template<class T>
class node
{
	public:
	
		T data;
		node *left;
		node *right;
	

		node();
};

template<class T>
node<T>::node()
{
	data=0;
	left=right=NULL;
}


template<class S>
class tree :public node<S>
{
	private:
		
		node<S> *root;

	public:
		tree();
		void insert(S);
		void preorder(node<S> *);
		node<S>* getroot();

};

template<class S>
tree<S>::tree()
{
	root=NULL;
}

template<class S>
node<S>* tree<S>::getroot()
{
	return root;
}

template<class S>
void tree <S>:: insert(S value)
{
	node<S> *temp = new node<S>;
	temp->data = value;
	if(root == NULL)
	{
		root=temp;
	}
	else
	{
		node<S> *current=root;
		node<S> *prev = NULL;
		
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

template<class S>
void tree<S>::preorder(node<S>* p)
{
	if(p==NULL)
	{
		return ;
	}
	preorder(p->left);
	preorder(p->right);
	cout<<p->data<<"\t";
}

int main(int argc, char const *argv[])
{
	tree<int> obj;
	obj.insert(5);
	obj.insert(2);
	obj.insert(8);
	obj.insert(4);
	obj.insert(1);
	obj.insert(7);
	obj.insert(10);
	obj.preorder(obj.getroot());
	return 0;
}
