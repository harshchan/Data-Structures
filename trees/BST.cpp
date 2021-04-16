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

   else
   {
     if(root->left==NULL && root->right==NULL)
     {
       delete root;
       root=NULL;
     }

     else if(root->left==NULL)
     {
       treeNode *temp=root;
       root=root->right;
       delete temp;
     }

     else if(root->right==NULL)
     {
       treeNode *temp=root;
       root=root->left;
       delete temp;
     }
     else
     {
       treeNode *temp=findmin(root->right);
       root->data=temp->data;
       root->right=Delete(root->right, temp->data);
     }
   }
   return root;
 }

int main()
{
  treeNode *root=NULL;
  int x,n;
  do{
  
  cout<<"\n 1.Create tree \n 2.Inorder \n 3.Preorder \n 4.Postorder \n 5. Delete \n ";
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
			root=Delete(root,n);
		}
		
  }

}while(x<6 && x>0);

  return 0;
}
