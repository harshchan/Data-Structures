#include<stdio.h>
#include<iostream>

using namespace std;

class node
{
	int data;
	node * next;
	
	public:
		node()
		{
			data=0;
			next=NULL;
		}
		
		friend class List;//method(functions) of list can access node 
};

class List
{
	node * listptr;
	node * temp;
	node*q;
	//for 2nd list
	node *listptr2;
	
	public:
		//List();
		void create();
		void display();
		void reverse();//just reverse baaki hai
		int  length();
		void insertByPos(int num, int pos);
		void insertAtStart(int num);
		void insertAtEnd(int num);
		void deleteByValue(int val);
		void deleteByPosition(int pos);
		void deleteAtStart();
		void deleteAtEnd();
		void newList();
		void merge();
		
};
void List::newList()
{
	int n,i,x;
	node *newnode=new node;
	cout<<"\n how many elements do you want to enter";
	cin>>n;
	cout<<"\n input for first node";
	cin>>x;
	newnode->data=x;
	newnode->next=NULL;
	listptr2=newnode;
	temp=newnode;
	
	for(i=2;i<=n;i++)
	{
		cout<<"\n enter data for subsequent nodes ";
		cin>>x;
		newnode->data=x;
		newnode->next=NULL;
		temp->next=newnode;
		temp=temp->next;
	}
	temp->next=NULL;
	
	//display elements of 2nd list
	temp=listptr2;
cout<<endl;
cout<<temp->data<<" -----> ";
	while(temp->next!=NULL)
	{temp=temp->next;
		cout<<temp->data<<" -----> ";
		
	}
	cout<<"NULL";
	cout<<"\n \n";
}

void List::merge()
{
	temp=listptr;
	while(temp->next!=NULL)
	{temp=temp->next;}
	temp->next=listptr2;
	
}


void List::insertAtStart(int n)
{
	node * newnode=new node;
	newnode->data=n;
	newnode->next=NULL;
	newnode->next=listptr;
	listptr=newnode;
}

void List::insertAtEnd(int n)
{cout<<"xd";
	node * newnode=new node;
	newnode->data=n;
	newnode->next=NULL;
	temp=listptr;
	while(temp->next!=NULL)
	temp=temp->next;
	temp->next=newnode;
}

void List::insertByPos(int x,int n)
{//int x;
cout<<"xd";
	node * newnode =new node;
	newnode->data=x;
	newnode->next=NULL;
	temp=listptr;
	for(int i=0;i<n-1;i++)
	{
		temp=temp->next;
	}
	newnode->next=temp->next;
	temp->next=newnode;
}
void List::deleteAtEnd()
{
	node*newnode=new node;
	temp=listptr;
	while(temp->next->next!=NULL)
	{
		temp=temp->next;
	}
	q=temp->next;
	delete q;
	temp->next=NULL;
	
}

void List::deleteAtStart()
{
	temp=listptr;
	listptr=temp->next;
	delete temp;
}

void List::deleteByPosition(int pos)
{
	temp=listptr;
	
	if(pos=0)
	{deleteAtStart();
	}
	for(int i=0;i<pos-2;i++)//points to node before target node to be deleted
	temp=temp->next;
	q=temp->next;
	//delete q;
	temp->next=q->next;
	delete q;
}

void List::deleteByValue(int x)
{
	temp=listptr;
	
	while(temp->next->next->data!=x)
	temp=temp->next;
	q=temp->next;
	temp->next=q->next;
	delete q;
}

void List::display()
{temp=listptr;

cout<<endl;
cout<<temp->data<<" -----> ";
	while(temp->next!=NULL)
	{
		temp=temp->next;
		cout<<temp->data<<" -----> ";
		
		
	}cout<<"lol";
	cout<<"NULL";
	cout<<"\n \n";
	cout<<"xd;";
}

int List::length()
{int i=0;
	temp=listptr;
	while(temp->next!=NULL)
	{
		i++;
	}
	return i;
}

void List::reverse()
{
	
}


int main()
{
	int x=0,n,pos;
	List l;
	do{cout<<"\n 1. Insert at Start \n 2. Insert at end \n 3. Insert by position \n 4. Delete from Start \n 5. Delete from End \n 6. Delete by Position \n 7. Delete by Element \n 8. Reverse the Linked List \n 9. Concatenate Linked List \n 10. Display the linked list \n 11. Display number of nodes in LL \n 0.Exit";
		cout<<"\n\nEnter operation number\n";
		cin>>x;
		switch(x)
		{
			case 1:
				cout<<"Enter Element \n";
				cin>>n;
				l.insertAtStart(n);
				break;
			case 2:
				cout<<"Enter Element ";
				cin>>n;
				l.insertAtEnd(n);
					break;
			case 3:
				cout<<"Enter Element and Position";
				cin>>n>>pos;
				l.insertByPos(n,pos);
					break;
			case 4:
				l.deleteAtStart();
				break;
			case 5:
				l.deleteAtEnd();break;
			case 6:
				cout<<"\n Enter Position of Node \n";
				cin>>n;
				l.deleteByPosition(n);break;
			case 7:
				cout<<"\n Enter element to  be deleted\n";
				cin>>n;
				l.deleteByValue(n);break;
				
			case 8:
				l.reverse();break;
			case 9:
				l.newList();
				l.merge();
				break;
			case 10:
				l.display();break;
			case 11:
				cout<<"\n Total number of Nodes in LL are "<<l.length();break;
				
			case 0:
				cout<<"bye bye!";
				break;
				
			default:
				cout<<"wrong";break;
				
		}
	}while(x>0);
	cout<<"bye bye!";
	return 0;
	
}
