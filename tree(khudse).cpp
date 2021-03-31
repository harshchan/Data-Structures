// tree implementation khudse try karra hu

#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;
//node * root;

class node
{public:
	int data;
	node *left;
	node *right;
	//node(int &);
	
		node(int x=0)//constructor
	{
		left=NULL;
		right=NULL;
		data=x;
	}
	
	node()//constructor
	{
		left=NULL;
		right=NULL;
		data=0;
	}
	
	friend class tree;
};
//node * root;

class tree
{
		
		node * root;
		node *temp;
		void preorder(node * currentnode);
		void inorder(node * currentnode);
		void postorder(node * currentnode);
		
		public:
			tree(){
				root=NULL;temp=root;
			}
		
		void create();
		void inorder();
		void postorder();
		void preorder();
		void insert(int c);
		void delet(int c);
		int totalnodes();
		int leafnodes();
		
		void mirror(tree &);
		void copy(tree &);
		
	
};


 void tree::create()
{char c,ans;
int b,d;
	node * newnode,*temp;
	do{
		cout<<"Enter element to be attatched";
		cin>>d;
		newnode=new node(d);
		newnode->data=d;
		newnode->left=NULL;
		newnode->right=NULL;
		
		if(root==NULL)
		{
			root=newnode;
		}
		else
		{
			temp=root;
			while(1)
			{
				cout<<"left/right of  (l/r)"<<temp->data;
				cin>>ans;
				if(ans=='l')
					if(temp->left==NULL)
					{
						temp->left=newnode;break;
					}
					else
					temp=temp->left;
				
				if(ans=='r')
					if(temp->right==NULL)
					{
						temp->right=newnode;break;
					}
					else
					temp=temp->right;
			}
		}
		cout<<" press 1 to entermore nodes 0 to exit";
		cin>>b;
		
	}while(b==1);
}
void tree::inorder()
{
	inorder(root);
}
void tree::preorder()
{
	preorder(root);
}
void tree::postorder()
{
	postorder(root);
}

void tree::inorder(node *node)
{
	if(node!=NULL)
	{
	inorder(node->left);
	cout<<node->data;
	inorder(node->right);
	}
}
void tree::postorder(node *node)
{
	if(node!=NULL)
	{
	postorder(node->left);
	postorder(node->right);
	cout<<node->data;
	}
}
void tree::preorder(node *node)
{
	if(node!=NULL)
	{
	cout<<node->data;
	preorder(node->left);
	preorder(node->right);
	}
}


int main()
{
	int x;
	tree t;

	
	do {
		cout<<"\n 1. create \n 2. preorder \n 3. inorder \n 4. postorder\n\n";
		cin>>x;
		switch(x)
		{
			case 1:
				t.create();break;
			case 2:
				t.preorder();break;
			case 3:
				t.inorder();break;
			case 4:
				t.postorder();break;
			default:
				cout<<"\n wrong choice ";
		}
		
	}while(x>0 &&x<5);
}
