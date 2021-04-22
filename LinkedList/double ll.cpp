#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

class node 
{
	public:
	int data;
	node *next;
	node *prev;
//	node()
//	{
//		node->next=NULL;
//		node->prev=NULL;
//	}
	
};

class list: public node 
{   
	node*dlistptr;
    node*temp;
    public:	
	list()
	{	dlistptr=NULL;
		temp=NULL;}
 
 void create();
 void display();
 
 void insertstart();
 void insertpos();
 //void insertdata();
 void insertend();
 
 void deletestart();
 void deleteend();
 //void deletepos();
 void deletedata();
 
 void reverse();
 void concatenate();

};

void list::create()
{int n,x;
	cout<<"\n How may nodes you want to enter ";
	cin>>n;
	while(n>0)
	{
		node *newnode=new node;
		newnode->next=NULL;
		newnode->prev=NULL;
		cout<<"\n Enter data";
		cin>>x;
		newnode->data=x;
		
		if(dlistptr==NULL)
		{dlistptr=newnode;temp=dlistptr;
		}
		
		else{
			temp->next=newnode;
			newnode->prev=temp;
			temp=temp->next;
		}
		n--;
		
	}
}

void list::insertstart()
{int x;
	cout<<"\n Enter data ";
	cin>>x;
	node * newnode=new node;
	newnode->next=NULL;
	newnode->prev=NULL;
	newnode->data=x;
	
	if(dlistptr==NULL)
	dlistptr=newnode;
	
	else
	{
		newnode->next=dlistptr;
		dlistptr->prev=newnode;
		dlistptr=newnode;
	}
	
}

void list::insertend()
{
	
	int x;
	cout<<"\n Enter data ";
	cin>>x;
	node *newnode=new node;
	newnode->prev=NULL;
	newnode->next=NULL;
	newnode->data=x;
	
	if(dlistptr==NULL)
	dlistptr=newnode;
	
	else{
		temp=dlistptr;
		while(temp->next!=NULL)
		temp=temp->next;
		
		temp->next=newnode;
		newnode->prev=temp;
	}
}

void list::insertpos()
{
	int x,n;
	cout<<"\n Enter position and element ";
	cin>>n>>x;
	node *newnode=new node;
	newnode->prev=NULL;
	newnode->next=NULL;
	newnode->data=x;
	temp=dlistptr;
	while(n>1)
	{
		temp=temp->next;n--;
	}
	cout<<"gg";
	newnode->next=temp->next;
	temp->next=newnode;
	newnode->prev=temp;
	newnode->next->prev=newnode;
	
}

void list::deletestart()
{
	temp=dlistptr;
	dlistptr=dlistptr->next;
	dlistptr->prev=NULL;
	delete temp;
	cout<<"\n Element deleted sucessfully!";
	
}

void list::deleteend()
{
	temp=dlistptr;
	while(temp->next!=NULL)
	temp=temp->next;
	
	//temp->prev=NULL;
	temp->prev->next=NULL;
//	temp->prev=NULL;
	delete temp;
	
}

void list::deletedata()
{
	int x;
	cout<<"\n Which data you want to delete";
	cin>>x;
	temp=dlistptr;
	while(temp->data!=x)
	temp=temp->next;
	temp->prev->next=temp->next;
	temp->next->prev=temp->prev;
	delete temp;
}

void list::display()
{
	temp=dlistptr;
	cout<<endl;
	cout<<temp->data<<" --> ";
	while(temp->next!=NULL)
	{temp=temp->next;
	cout<<temp->data<<" --> ";
	}
	cout<<"NULL";
}

void list::reverse()
{
	temp=dlistptr;
	while(temp->next!=NULL)
	temp=temp->next;
	cout<<endl<<temp->data<<" --> ";
	while(temp->prev!=NULL)
	{
		temp=temp->prev;
		cout<<temp->data<<" --> ";
	}
	cout<<" NULL";
}

void list::concatenate(){
	list l1,l2;
	node *dlistptr1=NULL,*dlistptr2=NULL;
	int n,x,m,y;
	cout<<"\n How may nodes you want to enter ";
	cin>>n;
	while(n>0)
	{
		node *newnode=new node;
		newnode->next=NULL;
		newnode->prev=NULL;
		cout<<"\n Enter data";
		cin>>x;
		newnode->data=x;
		
		if(dlistptr1==NULL)
		{dlistptr1=newnode;temp=dlistptr1;
		}
		
		else{
			temp->next=newnode;
			newnode->prev=temp;
			temp=temp->next;
		}
		n--;
		
	}
	
	cout<<"\n How may nodes you want to enter ";
	cin>>m;
	while(m>0)
	{
		node *newnode=new node;
		newnode->next=NULL;
		newnode->prev=NULL;
		cout<<"\n Enter data";
		cin>>y;
		newnode->data=y;
		
		if(dlistptr2==NULL)
		{dlistptr2=newnode;temp=dlistptr2;
		}
		
		else{
			temp->next=newnode;
			newnode->prev=temp;
			temp=temp->next;
		}
		m--;
		
	}
	
	temp=dlistptr1;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=dlistptr2;
	dlistptr2->prev=temp;
	
	
	cout<<"\n mergerd double linked list is ";
	temp=dlistptr1;
	cout<<endl;
	cout<<temp->data<<" --> ";
	while(temp->next!=NULL)
	{temp=temp->next;
	cout<<temp->data<<" --> ";
	}
	cout<<"NULL";
	
	
}

int main()
{int t;
	list l;
	do {
		cout<<"\n 1.Create a DLL \n 2.insert at beginning \n 3.insert at end \n 4.insert at intermediate \n 5.Delete at beginning \n 6.delete at end \n 7.Delete by data \n 8.Display \n 9.Reverse  \n 10.Concatenate ";
		cout<<"\n\n Enter serial number of operation";
		cin>>t;
		
		
		switch(t)
		{
			case 1:
				l.create();break;
			case 2:
				l.insertstart();break;
			case 3:
				l.insertend();break;
			case 4:
				l.insertpos();break;
			case 5:
				l.deletestart();break;
			case 6:
				l.deleteend();break;
			case 7:
				l.deletedata();break;
			case 8:
				l.display();break;
			case 9:
				l.reverse();break;
			case 10:
				l.concatenate();break;
				
				
				
		}
		l.display();
		
	}while(t>0&&t<10);
	
	return 0;
}


