// tree implementation khudse try karra hu

#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<bits/stdc++.h>

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
		node * createTree();
		node * copy(node * root1,node* root2);
		node * mirror(node * root1,node *root2);
		int totalnodes(node *root);
		int leafnodes(node *root);
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
		void stackInorder();
		void stackPreorder();
		void stackPostorder();
		
		void mirror(tree &);
		void copy(tree &);
		
	
};

node * tree::createTree()
{int d;

//if dont want to enter data then enter data as -1. 
	
	node *root=NULL;
	cout<<"\nEnter data";
	cin>>d;
	if(d==-1)
	{
		return NULL;
	}
	root=new node(d);
	cout<<"\n enter left of  "<<d;
	root->left=createTree();
	cout<<"\nEnter right of "<<d;
	root->right=createTree();
	return root;
}


 void tree::create()
{
root=createTree();

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
	cout<<node->data<<" ";
	inorder(node->right);
	}
}
void tree::postorder(node *node)
{
	if(node!=NULL)
	{
	postorder(node->left);
	postorder(node->right);
	cout<<node->data<<" ";
	}
}
void tree::preorder(node *node)
{
	if(node!=NULL)
	{
	cout<<node->data<<" ";
	preorder(node->left);
	preorder(node->right);
	}
}


void tree::insert(int data)
{int x;
char ch;
	node *newnode=new node(data);
	if(root==NULL)
	root=newnode;
	
	else{
		temp=root;
		while(1)
		{
			cout<<"left or right(l/r) of "<<temp->data<<endl;
			cin>>ch;
			if(ch=='l')
			{
				if(temp->left==NULL)
				{
					temp->left=newnode;break;
				}
				else
				temp=temp->left;
			}
			if(ch=='r')
			{
				if(temp->right==NULL)
				{
					temp->right=newnode;break;
				}
				else
				temp=temp->right;
			}
		}
	}
}

void tree::copy(tree &t)
{
	copy(root,t.root);
}

node * tree::copy(node *root1,node *root2=NULL)
{
	if(root1!=NULL)
	{
		root2=new node(root1->data);
		root2->left=copy(root1->left);
		root2->right=copy(root1->right);
		return root;
	}
	else
	return NULL;
}
//public fn to call
void tree::mirror(tree &t)
{
	mirror(root,t.root);
}
//private fn
node * tree::mirror(node * root1,node *root2=NULL)
{
//	node * root2=NULL;
	if(root1!=NULL)
	{
		root2=new node(root1->data);
		root2->left=mirror(root1->right);
		root2->right=mirror(root->left);
	}
	return root2;
}


int tree::totalnodes()
{
	return totalnodes(root);
}

int tree::totalnodes(node *root)
{int countnode=0;
	if(root!=NULL)
	{countnode++;
	totalnodes(root->left);
	totalnodes(root->right);
		
	}

	return countnode;
}

int tree::leafnodes()
{
	return leafnodes(root);
}

int tree::leafnodes(node *root)
{
	int countleaf=0;
	if(root==NULL)
	return countleaf;
	if(root->right==NULL && root->left==NULL)
	return ++countleaf;
	leafnodes(root->left);
	leafnodes(root->right);
}


void tree::stackInorder()
{
	node *temp=root;
	stack <node *>s;
	cout<<"\n NOn recursive inorder traversal is ";
	while(1)
	{
		while(temp!=NULL)
		{s.push(temp);temp=temp->left;
		}
		if(s.empty())break;
		temp=s.top();
		s.pop();
		cout<<" "<<temp->data;
		temp=temp->right;
	}
}

void tree::stackPreorder()
{
	node *temp=root;
	stack<node *>s;
	cout<<"\n Non recursive preorder traversal  ";
	while(1)
	{
		while(temp!=NULL)
		{
			s.push(temp);cout<<" "<<temp->data;
			temp=temp->left;
		}
		if(s.empty())break;
		temp=s.top();
		s.pop();
		temp=temp->right;
	}
}
void tree::stackPostorder()
{
	node *temp=root;
	stack <node *>s;
	cout<<"postorder traversal ";
	while(1)
	{
		while(temp!=NULL)
		{
			s.push(temp);temp=temp->left;
		}
		if(s.empty())break;
		temp=s.top();
		s.pop();
		temp=temp->right;
		cout<<" "<<temp->data;
		
	}
}

int main()
{
	int x;
	tree t,t2,t3;

	
	do {
		cout<<"\n 1. Create \n 2. Preorder \n 3. Inorder \n 4. Postorder\n 5. Stack Preorder \n 6. Stack Inorder\n 7. Stack Postorder\n 8. Insert element in  tree \n 9. Total leaf nodes \n 10.Total nodes";
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
			case 5:
				
				t.stackPreorder();
				break;
			
			case 6:
				t.stackInorder();break;
			
			case 7:
				t.stackPostorder();break;
				
			case 8:
				int data;
				cout<<"\n Enter data";
				cin>>data;
				t.insert(data);break;
			
			case 9:
				cout<<"\n Total number of leaf nodes are "<<t.leafnodes()<<endl;break;
			case 10:
				cout<<"\n Total number of nodes in list is "<<t.totalnodes()<<endl;break;
				
			default:
				cout<<"\n wrong choice ";
		}
		
	}while(x>0 &&x<11);
}
