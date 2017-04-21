#include <iostream>
#include <cstdlib>
using namespace std;
class node
{
public:
	string name;
	node *next;
};
node *temp1;
class Set
{
	node *head, *last, *temp;
public:
	void add();
	Set union_list(Set);
	Set intersection_list(Set);
	void display();
	bool isPresent(Set, string);
	Set()
	{
		head = last = temp = NULL;
	}
};
void Set::display()
{
	temp = head;
	while(temp!=NULL)
	{
		cout<<temp->name<<"    ";
		temp = temp->next;
	}
}
void Set::add()
{
	temp = new node;
	cout<<"\nEnter name: ";
	cin>>temp->name;
	temp->next = NULL;
	if(head == NULL)
		head = last = temp;
	else
	{
		last->next = temp;
		last = temp;
	}
}
bool Set::isPresent(Set X, string str)
{
	temp = X.head;
	while(temp != NULL)
	{
		if(temp->name == str)
			return true;
		temp = temp->next;
	}
	return false;
}
Set Set::union_list(Set C)
{
	Set X;
	node *temp1 = head, *temp2 = C.head;
	while(temp1 != NULL)
	{
		temp = new node;
		temp->name = temp1->name;
		temp->next = NULL;
		if(X.head == NULL)
			X.head = X.last = temp;
		else
		{
			X.last->next = temp;
			X.last = temp;
		}
		temp1 = temp1->next;
	}
	while(temp2 != NULL)
	{
		if(!isPresent(X, temp2->name))
		{
			temp = new node;
			temp->name = temp2->name;
			temp->next = NULL;
			if(X.head == NULL)
				X.head = X.last = temp;
			else
			{
				X.last->next = temp;
				X.last = temp;
			}
		}
		temp2 = temp2->next;
	}
	return X;
}
Set Set::intersection_list(Set C)
{
	Set X;
	node *temp1 = head;
	while(temp1 != NULL)
	{
		if(isPresent(C, temp1->name))
		{
			temp = new node;
			temp->name = temp1->name;
			temp->next = NULL;
			if(X.head == NULL)
				X.head = X.last = temp;
			else
			{
				X.last->next = temp;
				X.last = temp;
			}
		}
		temp1 = temp1->next;
	}
	return X;
};
int main()
{
	int ch;
	Set V, B, U, I, T;
	while(1)
	{
		cout<<"\n\n1. Enter name of students who like vanilla ice-cream.";
		cout<<"\n2. Enter name of students who like butter-scotch ice-cream.";
		cout<<"\n3. Display list of students who like vanilla. ";
		cout<<"\n4. Display list of students who like ice-cream.";
		cout<<"\n5. Display union. ";
		cout<<"\n6. Display intersection";
		cout<<"\n7. Exit";
		cout<<"\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1: V.add(); break;
			case 2: B.add(); break;
			case 3: cout<<"\nStudents who like vanilla: "<<endl;
			V.display(); break;
			case 4: cout<<"\nStudents who like butter-scotch: "<<endl;
			B.display(); break;
			case 5: cout<<"\nStudents who like vanilla: "<<endl;
			V.display();
			cout<<"\nStudents who like butter-scotch: "<<endl;
			B.display();
			cout<<"\nUnion: "<<endl;
			U = V.union_list(B); U.display(); break;
			case 6: cout<<"\nStudents who like vanilla: "<<endl;
			V.display();
			cout<<"\nStudents who like butter-scotch: "<<endl;
			B.display();
			cout<<"\nIntersection: "<<endl;
			I = V.intersection_list(B); I.display(); break;
			case 7: exit(0); break;
			default: cout<<"\nInvalid choice"; break;
		}
	}
	return 0;
}