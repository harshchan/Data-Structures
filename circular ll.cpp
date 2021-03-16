#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

class node 
{
	public:
	int data;
	node*next;
	
};

class list: public node 
{   
	node*listptr;
    node*temp;
    public:	
	list()
	{	listptr=NULL;
		temp=NULL;}
 
 void create();
 void display();
 
 void insertstart();
 void insertpos();
 void insertdata();
 void insertend();
 
 void deletestart();
 void deleteend();
 void deletepos();
 void deletedata();
 
 void reverse();
 void concatenate();

};

void list::create()
{   int x,i,n;
    cout<<"Enter the number of nodes";
    cin>>n;
    for(i=0;i<n;i++)
	{node * newnode= new node;
	cout<<"Enter the data";
	cin>>x;
	newnode->data=x;
	newnode->next=NULL;
	
	if(listptr==NULL)
	{
		listptr=temp=newnode;
		newnode->next=listptr;
	}
	
	else
	   {temp->next=newnode;
	   newnode->next=listptr;
	    temp= temp->next;// or temp=temp->next
   	 }}
}

void list::display()
{
	temp=listptr;
	cout<<temp->data<<"--->";
	while(temp->next!=listptr)
	{temp=temp->next;
     cout<<temp->data<<"--->";
	 }
	 //cout<<"NULL";
	 cout<<listptr->data;
     
}

void list::insertstart()
{   int x;
	cout<<"Enter the data: ";
	cin>>x;
	node*newnode= new node;
	newnode->data=x;
	newnode->next=listptr;
	temp=listptr;
	while(temp->next!=listptr)
	temp=temp->next;
	temp->next=newnode;
	listptr=newnode;
	//listptr=newnode;
}

void list::insertend()
{   int x;
	cout<<"Enter the data";
	cin>>x;
	node* newnode= new node;
	newnode->data=x;
	newnode->next=NULL;
	temp=listptr;
	while(temp->next!=listptr)
	  temp=temp->next;
	temp->next=newnode;  
	newnode->next=listptr;
}

void list::insertpos()
{
	int pos,  x, i=0;
	cout<<"Enter the position to insert at: ";
	cin>>pos;
	cout<<"Enter the data to be inserted: ";
	cin>>x;
	temp=listptr;
	node* newnode= new node;
	newnode->data=x;
	newnode->next=NULL;
	while(i!=pos-1)
	{
		temp=temp->next;
		i++;
	}
	newnode->next=temp->next;
	temp->next=newnode;
	
}

void list::insertdata()
{
	int pos,x; 
	temp=listptr;
	cout<<"Enter the data to be inserted";
	cin>>x;
	cout<<"Enter the data after which "<<x<<" needs to be inserted";
    cin>>pos;
    node *newnode= new node;
    newnode->data=x;
    newnode->next=NULL;
    while(temp->data!=pos)
    {temp=temp->next;}
    newnode->next=temp->next;
    temp->next=newnode;
    
}

void list::deletestart()
{node *q;
	q=temp=listptr;
	while(temp->next!=listptr)
	temp=temp->next;
	listptr=listptr->next;
	temp->next=listptr;
	delete(q);
}

void list::deleteend()
{   
    node*q;
	temp=listptr;
	while(temp->next->next!=listptr)
	temp=temp->next;
	q=temp->next;
	temp->next=listptr;//can delete first also.
	delete(q);
	
}

void list::deletepos()
{   temp=listptr;
    node*q;
    int pos,i=0;
	cout<<"Enter the position to be deleted";
	cin>>pos;
	while(i!=pos-2)
	{
		temp=temp->next;
		i++;
	}
	q=temp->next;
	temp->next=q->next;
	delete(q);
	
}

void list::deletedata()
{
	temp=listptr;
	node*q;
	int x;
	cout<<"Enter the data to be deleted";
	cin>>x;
	while(temp->next->data!=x)
	  temp=temp->next;
	q=temp->next;
	temp->next=q->next;
	delete(q);
}

void list::reverse()
{
	node *forward, *curr, *back;
	forward=listptr;
	curr=NULL;
	while(forward->next!=listptr)
	{   back=curr;
	    curr=forward;
		forward=forward->next;
		curr->next=back;
	}
	back=curr;
	curr=forward;
	forward=forward->next;
	curr->next=back;

	listptr=curr;
	
	
	temp=listptr;
	while(temp->next!=NULL)
	temp=temp->next;
	temp->next=listptr;

//forward->next=curr;


//listptr=curr;
//temp=listptr;
//while(temp->next!=NULL)
//temp=temp->next;
//temp->next=listptr;
}


void list::concatenate()
{
    node *listptr1, *listptr2, *temp1, *temp2;
    listptr1=NULL;
    listptr2=NULL;
    temp1=NULL;
    temp2=NULL;
	int x,i,j,n1,n2;
    cout<<"Enter the number of nodes in List 1:";
    cin>>n1;
    for(i=0;i<n1;i++)
	{node * newnode1= new node;
	cout<<"Enter the data";
	cin>>x;
	newnode1->data=x;
	newnode1->next=NULL;
	
	if(listptr1==NULL)
	{
		listptr1=newnode1;
		temp1=newnode1;
	}
	
	else
	   {temp1->next=newnode1;
	    temp1= newnode1;// or temp=temp->next
   	 }}
   	 
   	 
    cout<<"Enter the number of nodes in List 2: ";
    cin>>n2;
    for(j=0;j<n2;j++)
	{node * newnode2= new node;
	cout<<"Enter the data";
	cin>>x;
	newnode2->data=x;
	newnode2->next=NULL;
	
	if(listptr2==NULL)
	{
		listptr2=newnode2;
		temp2=newnode2;
	}
	
	else
	   {temp2->next=newnode2;
	    temp2= newnode2;// or temp=temp->next
   	 }}  
   	 
   	 temp1=listptr1;
   	 while(temp1->next!=NULL)
   	 temp1=temp1->next;
   	 temp1->next=listptr2;
   	 //temp=temp->next;
   	 while(temp1->next!=NULL)
   	 temp1=temp1->next;
   	 temp1->next=listptr1;
   	 
   	 temp1=listptr1;
	cout<<temp1->data<<"--->";
	while(temp1->next!=listptr1)
	{temp1=temp1->next;
     cout<<temp1->data<<"--->";
	 }
	 temp1=temp1->next;
	 cout<<temp1->data;
   	 
   	 
   	
}


main()
{   int ch; list l;
	do{
	cout<<"\nMENU";
	cout<<"\n1.Create Linked List.";
	cout<<"\n2.Display Linked List.";
	cout<<"\n3.Insert at the start of Linked List.";
	cout<<"\n4.Insert at the end of Linked List.";
	cout<<"\n5.Insert w.r.t position";
	cout<<"\n6.Insert w.r.t data";
	cout<<"\n7.Delete at the start of the Linked List";
	cout<<"\n8.Delete at the end of the Linked List";
	cout<<"\n9.Delete w.r.t position";
	cout<<"\n10.Delete w.r.t data";
	cout<<"\n11.Reverse the Linked List";
	cout<<"\n12.Concatenate two Linked Lists";
	cout<<"\n13.Exit.";
	cout<<"\nEnter your choice: ";
	cin>>ch;
	if(ch==1)
	l.create();
	else if (ch==2)
	l.display();
	else if(ch==3)
	{l.insertstart(); l.display();}
	else if(ch==4)
	{l.insertend(); l.display();}
	else if(ch==5)
	{l.insertpos(); l.display();}
	else if(ch==6)
	{l.insertdata(); l.display();}
	else if(ch==7)
	{l.deletestart(); l.display();}
	else if(ch==8)
	{l.deleteend(); l.display();}
	else if(ch==9)
	{l.deletepos(); l.display();}
	else if(ch==10)
	{l.deletedata(); l.display();} 
	else if(ch==11)
	{l.reverse(); l.display();}
	else if(ch==12)
	{l.concatenate();}
	else if(ch>13)
	cout<<"Invalid option!";
	
    }while(ch!=13);
}













