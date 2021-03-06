#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

class node
{
	int data;
	node * next;
	public:
//		node(x)
//		{
//			data=x;
//			next=NULL;
//		}
	friend class Stack;
};

class Stack
{
	node * top;
	node *temp;
	public:
		//Stack();
		void create();
		void insert();
		void del();
		void display();
		
};


void Stack::create()
{
	int n,x;
	cout<<"\n How many elements do you want to enter in Stack ";
	cin>>n;
	
	while(n>0)
	{
		
		node *newnode=new node;
		cout<<"\n Enter data ";
		cin>>x;
		newnode->next=NULL;
			if(top==NULL)
		{
		newnode->data=x;
		top=newnode;
		}
		else{
			newnode->data=x;
			temp=top;
			newnode->next=temp;
			top=newnode;
		}
		n--;
	}
}

void Stack::insert()
{int x;
	node *newnode=new node;
	cout<<"\n ENTER DATA ";
	cin>>x;
	newnode->data=x;
	newnode->next=NULL;
	newnode->next=top;
	top=newnode;
	
}

void Stack::display()
{
	temp=top;
	cout<<temp->data<<" --> ";
	while(temp->next!=NULL)
	{temp=temp->next;
	cout<<temp->data<<" --> ";
	}
}

void Stack::del()
{
	temp=top;
	top=top->next;
	delete temp;
	cout<<"Node deleted sucessfully! ";
}

int main()
{
	Stack s;
	
	int a,n;
	do{
	
	cout<<"\n Menu\n\n1.Create \n2.Insert \n3.Delete \n4.Display \n5.Exit";
	cin>>a;
	switch(a)
	{
		case 1:
			s.create();
			break;
		case 2:
			s.insert();break;
		case 3:
			s.del();break;
		case 4:
			s.display();break;
		case 5:
			exit(0);
			break;
		default:
			cout<<"wrong choice ";
	}
		}while(a<5&&a>0);
return 0;
}
	
