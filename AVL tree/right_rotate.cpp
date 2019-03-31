#include<iostream>
#include<queue>
using namespace std;

class node
{
    public:

        int data;
        node *left,*right;
        node()
        {
            data=0;
            left=right=NULL;
        }
        node(int data)
        {
            this->data=data;
            left=NULL;
            right=NULL;
        }
};

class tree:private node
{
    private:
        node *root;
    public:
        tree();
        void insert(int);
        node * getroot();
        void BFS(node*);
        node* right_rotate(node*);
        node* left_rotate(node*);
        node *right_left(node *);

};

tree::tree()
{
    root=NULL;
}

node* tree::getroot()
{
    return root;
}

void tree:: insert(int value)			
{
	node *temp = new node;
	temp->data = value;

	if(root == NULL)
	{
		root=temp;
	}

	else
	{
		node *current=root;					
		node *prev = NULL;
		
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


queue<node*> bfs;
void tree::BFS(node *r)
{
    bfs.push(r);
    while(!bfs.empty())
    {
        node *p=bfs.front();
        bfs.pop();
        cout<<p->data<<"\t";
        if(p->left!=NULL)
        {
            bfs.push(p->left);
        }
        if(p->right!=NULL)
        {
            bfs.push(p->right);
        }
    }
}


node* tree::right_rotate(node *pred)
{
    node *x=pred->left;
    pred->left=pred->left->left;
    node *beta = pred->left->right;
    pred->left->right=x;
    x->left=beta;
    return pred->left;
}

node* tree::left_rotate(node *pred)
{
    node *x=pred->right;
    pred->right=pred->right->right;
    node *alpha=pred->right->left;
    pred->right->left=x;
    x->right=alpha;
    return pred->right;
}

node* tree::right_left(node *pred)
{
    
}
int main()
{
    tree obj1;
    obj1.insert(50);
    obj1.insert(40);
    obj1.insert(45);
    obj1.insert(30);
    obj1.insert(35);
    obj1.insert(20);

    obj1.BFS(obj1.getroot());
    cout<<endl;

    obj1.right_rotate(obj1.getroot());
    obj1.BFS(obj1.getroot());

    cout<<endl<<"\n\ntree 2\n\n";   

    tree obj2;
    obj2.insert(50);
    obj2.insert(60);
    obj2.insert(55);
    obj2.insert(70);
    obj2.insert(65);
    obj2.insert(80);

    obj1.BFS(obj2.getroot());
    cout<<endl;

    obj1.left_rotate(obj2.getroot());
    obj1.BFS(obj2.getroot());



    return 0; 
}