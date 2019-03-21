#include<iostream>

/*

C++ program to count the number of leaf and non leaf nodes in a BST

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

/*class tree inheriting node class and having a root object of the node as its class member */
template<class S>
class tree: public node<S>		
{
	private:
		
		node<S> *root;

	public:
		tree();
		node<S>* getroot();
		void insert(S);
		void inorder(node<S> *);
        int numleaves(node<S> *);
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

/*tree traversing using inorder approach*/
template<class S>
void tree<S>::inorder(node<S>* p)				
{
	if(p==NULL)
	{
		return ;
	}
	inorder(p->left);
    cout<<p->data<<"\t";
	inorder(p->right);
}

/*number of leaves and non leaves member in a tree*/
int leaves=0,nonleaves=0;
template<class S>
int tree<S>::numleaves(node<S> *r)
{
    if(r==NULL)
    {
        return 0;
    }
    int left = numleaves(r->left);
    int right = numleaves(r->right);
    if(left==0 && right==0)
    {
        leaves+=1;
    }
    else
    {
        nonleaves+=1;
    }
    return 1;
}

/*main function*/
int main(int argc, char const *argv[])
{
	/*tree object*/
	tree<int> obj;

	/*some initialisation.You can also insert by asking to the user but i did so to make the things more clear*/
	obj.insert(50);
    obj.insert(45);
    obj.insert(10);
    obj.insert(49);
    obj.insert(65);
    obj.insert(60);
    obj.insert(80);
    obj.insert(70);
    obj.insert(75);

	obj.inorder(obj.getroot());

    obj.numleaves(obj.getroot());
    cout<<"\nNumber of non leaves are = "<<nonleaves<<"\nnumber of leaves are = "<<leaves<<endl;
	return 0;
}