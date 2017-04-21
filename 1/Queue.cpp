#include <iostream>
#include <cstdlib>
using namespace std;
#define size 5
int queue[size];
int front=-1, rear = -1;
bool isEmpty()
{
	return (rear == -1 && front == -1);
}
bool isFull()
{
    return (rear == size-1);
}
void Display()
{
    if(isEmpty())
        cout<<"\nQueue Underflow"<<endl;
    else
    {
        for(int i=front; i<=rear; i++)
            cout<<queue[i]<<" ";
    }
}
void Enque(int n)
{
    if(isFull())
        cout<<"\nQueue Overflow"<<endl;
	else if(isEmpty())
	{
		queue[++rear] = n;
		++front;
	}
	else
        queue[++rear] = n;
}
void Deque()
{
    if(isEmpty())
        cout<<"\nQueue Underflow"<<endl;
    else if(front == rear)
        front = rear = -1;
    else
    {
        queue[front++];
        Display();
    }
}
int main() {
	int ch, val;
	while(1)
	{
		cout<<"1. Enque"<<endl;
		cout<<"2. Deque"<<endl;
		cout<<"3. Display"<<endl;
		cout<<"4. Exit"<<endl;
		cout<<"\nEnter choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1: cout<<"Enter a no.: ";
			cin>>val;
			Enque(val);
			cout<<"\n";
			break;
			case 2: Deque();
			cout<<"\n";
			break;
			case 3: Display();
			cout<<"\n";
			break;
			case 4: exit(0); break;
			default: cout<<"You entered wrong choice"<<endl; break;
		}
		cout<<"\n";
	}
	return 0;
}