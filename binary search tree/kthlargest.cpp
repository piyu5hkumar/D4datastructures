#include<iostream>

/*

C++ program to find K’th largest element in binary search tree when tree modification is not allowed

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
		bool reverse_Inorder(node<S> *,const int&);
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

/*tree traversing using reverse_Inorder approach i.e. we will traverse right subtree and then left subtree of the current */
template<class S>
bool tree<S>::reverse_Inorder(node<S>* p,const int &count)				
{
	/* this will be incremented and compared to count and when they are equal we will how that our kth largest node is found */
	static int i=1;

	/* this is a flag whih will tell if the value exist or not */
	static bool found_status= false;
	if(p==NULL)  
	{
		return found_status ;
	}
	
	reverse_Inorder(p->right,count);
	
	if(i==count)
	{
		cout<<p->data<<endl;
		found_status=true;
	}
	i++;
	
	reverse_Inorder(p->left,count);
}

/*main function*/
int main(int argc, char const *argv[])
{
	/* tree object */
	tree<int> obj;

	/* some initialisation.You can also insert by asking to the user but i did so to make the things more clear */
	obj.insert(5);	
	obj.insert(2);
	obj.insert(8);
	obj.insert(4);
	obj.insert(1);
	obj.insert(7);
	obj.insert(10);
	
	/* value of K is taken */
	int K;
	cin>>K;

	/* procedure called, if it wont find the node it will return false */
	if(!obj.reverse_Inorder(obj.getroot(),K))
	{
		cout<<"Elemnt not found\n"<<endl;
	}

	return 0;
}
