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
	friend class Queue;
};

class Queue
{
	node *front,*rear,*temp;
	public:
		Queue()
		{
			front=NULL;
			rear=NULL;
		}
		
		
		void create();
		void insertRear();
		void deleteFront();
		void display();
		int displayFront();
		int displayRear();
		
};

void Queue::create()
{
	int x,n;
	cout<<"\n how many nodes you want to create";
	cin>>n;
	while(n>0)
	{
	
	node *newnode=new node;
	cout<<"\n enter data";
	cin>>x;
	newnode->data=x;
	newnode->next=NULL;
	
	if(rear==NULL)
	{
		rear=newnode;
		front=newnode;
		temp=rear;
		
	}
	else
	{
		rear->next=newnode;
		temp=newnode;
		rear=newnode;
	}
	n--;
	}
	
}

void Queue::insertRear()
{int x;
	node *newnode=new node;
	cout<<"\n enter Data";
	cin>>x;
	newnode->data=x;
	newnode->next=NULL;
	rear->next=newnode;
	rear=newnode;
}

void Queue::deleteFront()
{
	if(front==NULL)
	{
		cout<<"already empty queue";
	}
	else{
	temp=front;
	front=front->next;
	delete temp;
	}
}

void Queue::display()
{
	temp=front;
	cout<<temp->data<<" --> ";
	while(temp->next!=NULL ||temp!=rear)
	{temp=temp->next;	
	cout<<temp->data<<" --> ";
		
	}
}

int Queue::displayFront()
{
	return front->data;
}
int Queue::displayRear()
{
	return rear->data;
}


int main()
{
	int x;
	Queue q;
	do{
	cout<<"\n 1. create \n 2. insert from rear \n 3. delete from front \n 4. display \n 5. display front and rear val \n6. exit ";
	cin>>x;
	
	switch (x)
	{
		
	
		case 1:
			q.create();break;
		case 2:
			q.insertRear();break;
		case 3:
			q.deleteFront();break;
		case 4:
			q.display();
			break;
		case 5:
			cout<<"\n Front is "<<q.displayFront()<<"\n Rear is "<<q.displayRear();
			break;
		default:
			exit(0);
			
	}
	
}while(x>0&&x<6);
return 0;
			
}

