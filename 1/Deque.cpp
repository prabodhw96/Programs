#include <iostream>
#include <cstdlib>
using namespace std;
class node
{
public:
	int data;
	node *next;
};
class Dequeue
{
	int data;
	node *temp, *front, *rear;
public:
	void addFront(int);
	void addRear(int);
	void removeFront();
	void removeRear();
	void display();
	Dequeue()
	{
		temp = front = rear = NULL;
		data = 0;
	}
};
void Dequeue::addFront(int item)
{
    temp = new node;
    temp->data = item;
    temp->next = NULL;
    if(front == NULL)
        front = rear = temp;
    else
    {
        temp->next = front;
        front = temp;
    }
    cout<<item<<" inserted to the front."<<endl;
}
void Dequeue::addRear(int item)
{
    temp = new node;
    temp->data = item;
    temp->next = NULL;
    if(rear == NULL)
        front = rear = temp;
    else
    {
        rear->next = temp;
        rear = temp;
    }
    cout<<item<<" inserted to the rear."<<endl;
}
void Dequeue::removeFront()
{
	node *temp1;
	int val;
	if(front == NULL)
		cout<<"Dequeue Underflow"<<endl;
	else if (front == rear)
	{
		val = front->data;
		front = rear = NULL;
		cout<<val<<" removed from front."<<endl;
	}
	else
	{
		val = front->data;
		temp1 = front;
		front = front->next;
		temp1->next = NULL;
		delete(temp1);
		cout<<val<<" removed from front."<<endl;
	}
}
void Dequeue::removeRear()
{
	node *temp1;
	int val;
	if(rear == NULL)
		cout<<"Dequeue Underflow"<<endl;
	else if (front == rear)
	{
		val = rear->data;
		front = rear = NULL;
		cout<<val<<" removed from rear."<<endl;
	}
	else
	{
		val = rear->data;
		temp = front;
		while(temp->next != rear)
			temp = temp->next;
		temp1 = rear;
		rear = temp;
		rear->next = NULL;
		delete(temp1);
		cout<<val<<" is removed from rear."<<endl;
	}
}
void Dequeue::display()
{
	if(front == NULL)
		cout<<"Dequeue is empty"<<endl;
	else if(front == rear)
	{
		cout<<"Dequeue has only one element"<<endl;
		cout<<front->data;
	}
	else
	{
		cout<<"Elements of Dequeue: "<<endl;
		temp = front;
		while(temp != NULL)
		{
			cout<<temp->data<<" ";
			temp = temp->next;
		}
		cout<<endl;
	}
}
int main()
{
	Dequeue D;
	int elem, ch;
	while(1)
	{
		cout<<"\n1. Add Element From Front";
		cout<<"\n2. Add Element From Rear";
		cout<<"\n3. Remove Element From Front";
		cout<<"\n4. Remove Element From Rear";
		cout<<"\n5. Display Dequeue";
		cout<<"\n6. Exit";
		cout<<"\n\n Enter Your Option: ";
	    cin>>ch;
	    switch(ch)
	    {
	    	case 1: cout<<"\nEnter element to be inserted: ";
	    	cin>>elem;
	    	D.addFront(elem);
	    	break;
	    	case 2: cout<<"\nEnter element to be inserted: ";
	    	cin>>elem;
	    	D.addRear(elem);
	    	break;
	    	case 3: D.removeFront();
	    	break;
	    	case 4: D.removeRear();
	    	break;
	    	case 5: D.display();
	    	break;
	    	case 6: exit(0);
	    	break;
	    	default: cout<<"\nInvalid choice"; break;
	    }
	}
	return 0;
}