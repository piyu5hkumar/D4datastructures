#include<iostream>
using namespace std;

template<class T>
class node						// a base class is created which contain the data of every node in the tree
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
class tree :public node<S>		// tree is being made which contains a root for every tree object
{
	private:
		
		node<S> *root;

	public:
		tree();
		node<S>* getroot();
		void insert(S);
		void postorder(node<S> *);
		

};

template<class S>
tree<S>::tree()							//as soon as the object will be made its root will be pointed to NULL
{
	root=NULL;
}

template<class S>
node<S>* tree<S>::getroot()				//this will give the pointer to the root
{
	return root;
}

template<class S>
void tree <S>:: insert(S value)			//insertion part
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
			prev=current;						//this will store the last node visited because at the end the pointer will point to the null
			if(temp->data > current->data)		// if the inserted data is greater than the available data in the node move to right sub tree
			{
				current=current->right;
			}
			else
			{
				current=current->left;			// if the inserted data is greater than the available data in the node move to left sub tree
			}
		}

		if (temp->data > prev->data)			//last node is compared if the data is more make the new node as right child
		{
			prev->right = temp;
		}
		else
		{
			prev->left = temp;					//if new node data is less make it left child
		}

	}
} 

template<class S>
void tree<S>::postorder(node<S>* p)				//tree traversing using postorder approach
{
	if(p==NULL)
	{
		return ;
	}
	postorder(p->left);
	postorder(p->right);
	cout<<p->data<<"\t";
}

int main(int argc, char const *argv[])
{
	tree<int> obj;								//tree object
	obj.insert(5);								//some initialisation.You can also insert by asking to the user but i did so to make the things more clear
	obj.insert(2);
	obj.insert(8);
	obj.insert(4);
	obj.insert(1);
	obj.insert(7);
	obj.insert(10);
	obj.postorder(obj.getroot());				//postorder traversel is being called in which the root of the tree is passed
	return 0;
}
