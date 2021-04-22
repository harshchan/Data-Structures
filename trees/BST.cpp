#include<iostream>

using namespace std;

class treeNode
{
public:
  int data;
  treeNode *left;
  treeNode *right;
};

treeNode* create(int value)
{
  treeNode *n=new treeNode;
  n->data=value;
  n->left=n->right=NULL;
  return n;
}

treeNode* Insert(treeNode* root, int data)
{
  if(root==NULL)
  {
    root=create(data);
  }
  else if(data<=root->data)
  {
    root->left=Insert(root->left, data);
  }
  else
  {
    root->right=Insert(root->right, data);
  }
  return root;
}

void inorder(treeNode *root)
{
  if(root==NULL) { return; }
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}
void preorder(treeNode * root)
{
	if(root==NULL)return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

void postorder(treeNode * root)
{
	if(root==NULL)return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}

treeNode* findmin(treeNode *root)
{
  treeNode *current=root;
  while(current->left!=NULL)
  {
    current=current->left;
  }
  return current;
}

void search(treeNode * roo,int data)
{int level=0;
	if(roo==NULL)
	{
		cout<<"\n tree is empty";
	}
	else
	{
	if(data>roo->data)
	{
	level++;	search(roo->right,data);
	}
	if(data<roo->data)
	{
	level++;	search(roo->left,data);
	}
	if(data==roo->data)
	{
		cout<<"\n data is present in tree at  "<<level<<" level";
	}
	}
}
treeNode* Delete(treeNode *root, int key)
 {
   //base case
   if(root==NULL) { return root; }

   if(key<root->data)
   {
     root->left=Delete(root->left, key);
   }

   else if(key>root->data)
   {
     root->right=Delete(root->right, key);
   }
//key found 
   else
   {//node is leaf node
   //no children
     if(root->left==NULL && root->right==NULL)
     {
       delete root;
       root=NULL;
     }
//node has right child but no left child
     else if(root->left==NULL)
     {
       treeNode *temp=root;
       root=root->right;
       delete temp;
     }
//node has left child but no right child
     else if(root->right==NULL)
     {
       treeNode *temp=root;
       root=root->left;
       delete temp;
     }
     //node has both the childs 
     else
     {
       treeNode *temp=findmin(root->right);//taking minimum value for right subtree of node to be deleted
       root->data=temp->data;
       root->right=Delete(root->right, temp->data);
     }
   }
   return root;
 }
 
 int  commonAncestor(int d1,int d2,treeNode *roo)
 {
 	if(roo->data>d1 && roo->data>d2)
 	commonAncestor(d1,d2,roo->left);
 	else if(roo->data<d1 && roo->data<d2)
 	commonAncestor(d1,d2,roo->right);
 	else
 	return roo->data;
 }

int main()
{
  treeNode *root=NULL,*temp;
  int x,n,r,d1,d2;
  do{
  
  cout<<"\n 1.Create tree \n 2.Inorder \n 3.Preorder \n 4.Postorder \n 5. Delete \n6.search \n7.Find Common Ancestor";
  cin>>x;
  switch(x)
  {
  	case 1:
  		while(n!=-1)
  		{
  			cout<<"\n Enter Data";
  			cin>>n;
  			if(n!=-1)
  			root=Insert(root,n);
  			
		  }break;
	case 2:
		inorder(root);break;
	case 3:
		preorder(root);break;
	case 4:
		postorder(root);break;
	case 5:
		{
			cout<<"\n Enter Data to be deleted";
			cin>>n;
			root=Delete(root,n);break;
		}
	case 6:
			cout<<"\n Enter data to be searched";
			cin>>r;
			search(root,r);break;
			
	case 7:
		cout<<"\n Enter 2 data to be searched";
		cin>>d1>>d2;
		
		cout<<"\n The common ancestor is"<<commonAncestor(d1,d2,root);break;
			
		
  }

}while(x<8 && x>0);

  return 0;
}
