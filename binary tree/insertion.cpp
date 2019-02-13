#include<iostream>

/*

C++ program to remove duplicate elements from the binary search tree

*/

using namespace std;

/*a base class is created which contain the data of every node in the tree*/
template<class T>
class node						
{
	public:
	
		T data;
		node *left;
		node *right;
	

		node();
};

/*construtcor of the base class*/
template<class T>
node<T>::node()
{
	data=0;
	left=right=NULL;
}

/*class tree inherting node class and having a root object of node as its class member */
template<class S>
class tree :public node<S>		
{
	private:
		
		node<S> *root;

	public:
		tree();
		node<S>* getroot();
		void insert(S);
		void postorder(node<S> *);
};


/*tree class default constructor.As soon as the object will be made its root will be pointed to NULL*/
template<class S>
tree<S>::tree()							
{
	root=NULL;
}

/*tree class parameterized constructor ,just in case if we know the value of the node at its declaration*/
template<class S>
node<S>* tree<S>::getroot()				
{
	return root;
}

/*Insertion member function*/
template<class S>
void tree <S>:: insert(S value)			
{
	node<S> *temp = new node<S>;
	temp->data = value;

	/*if root is not pointing to anything ,that is tree is not existing*/
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
			/*storing the last node visited because at the end the pointer will point to the null*/
			prev=current;	

			/* If item is greater than current node go to right sub tree */					
			if(temp->data > current->data)		
			{
				current=current->right;
			}

			/* If item is samller than current node go to left sub tree */
			else
			{
				current=current->left;			
			}
		}

		/*last node in comparison*/ 

		/*if the data is more make the new node as right child*/
		if (temp->data > prev->data)			
		{
			prev->right = temp;
		}

		/*if new node data is less make it left child*/
		else
		{
			prev->left = temp;					
		}

	}
} 

/*tree traversing using postorder approach*/
template<class S>
void tree<S>::postorder(node<S>* p)				
{
	if(p==NULL)
	{
		return ;
	}
	postorder(p->left);
	postorder(p->right);
	cout<<p->data<<"\t";
}

/*main function*/
int main(int argc, char const *argv[])
{
	/*tree object*/
	tree<int> obj;

	/*some initialisation.You can also insert by asking to the user but i did so to make the things more clear*/
	obj.insert(5);	
	cout<<"after inserting 5\n";

	/*calling postorder everytime just to assure that data is inserted*/
	obj.postorder(obj.getroot());
	
	obj.insert(2);
	cout<<"\nafter inserting 2\n";
	obj.postorder(obj.getroot());
	
	obj.insert(8);
	cout<<"\nafter inserting 8\n";
	obj.postorder(obj.getroot());
	
	obj.insert(4);
	cout<<"\nafter inserting 4\n";
	obj.postorder(obj.getroot());
	
	obj.insert(1);
	cout<<"\nafter inserting 1\n";
	obj.postorder(obj.getroot());
	
	obj.insert(7);
	cout<<"\nafter inserting 7\n";
	obj.postorder(obj.getroot());
	
	obj.insert(10);
	cout<<"\nafter inserting 8\n";
	obj.postorder(obj.getroot());

	return 0;
}
