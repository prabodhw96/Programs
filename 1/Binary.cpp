#include <iostream>
#include <cstdlib>
using namespace std;
class node
{
public:

	node *prev;
	int data;
	node *next;
};
class Binary
{
	node *head, *last, *temp;
	int rem;
public:
	void dec_to_bin(int);
	void ones_comp();
	void twos_comp();
	Binary add(Binary);
	void display();
	Binary()
	{
		head = last = temp = NULL;
        rem=0;
	}
	void Initiate()
	{
		head = last = temp = NULL;
        rem=0;
	}
};
void Binary::display()
{
	temp = last;
	while(temp!=NULL)
	{
		cout<<temp->data;
		temp = temp->prev;
	}
}
void Binary::dec_to_bin(int no)
{
	while(no != 0)
	{
		rem = no%2;
		temp = new node;
		temp->data = rem;
		temp->next = NULL;
		temp->prev = NULL;
		if(head == NULL)
		{
			head = temp;
			last = temp;
		}
		else
		{
			last->next = temp;
			temp->prev = last;
			temp->next = NULL;
			last = temp;
		}
		no = no/2;
	}
}
void Binary::ones_comp()
{
	temp=head;
	while(temp!=NULL)
	{
        temp->data = not(temp->data);
		temp = temp->next;
	}
	cout<<"\n1's Complement: "; display();
}
void Binary::twos_comp()
{
	int carry=1;
	temp=head;
    while(temp!=NULL)
	{
		temp->data=temp->data + carry;
		if(temp->data == 3)
		{
			temp->data = 1;
			carry = 1;
		}
    	else if(temp->data == 2)
		{
			temp->data = 0;
			carry=1;
		}
		else if(temp->data == 1)
		{
			temp->data = 1;
			carry=0;
		}
		else
		{
			temp->data = 0;
			carry = 0;
		}
        temp=temp->next;
	}
	if(carry == 1)
	{
  	    temp = new node;
    	temp->data = carry;
    	last->next = temp;
    	temp->prev = last;
    	last = temp;
    }
	cout<<"\n2's Complement: "; display(); cout<<"\n";
}
Binary Binary::add(Binary R)
{
	Binary X;
	int no, carry = 0;
	node *temp1,*temp2;
	temp1 = head;
	temp2 = R.head;
	while(temp1 != NULL || temp2 != NULL)
	{
		no = carry + (temp1? temp1->data:0) + (temp2? temp2->data:0);
		if(no == 3)
		{
			no = 1;
			carry = 1;
		}
		else if (no == 2)
		{
			no = 0;
			carry = 1;

		}
		else if (no == 1)
		{
			no = 1;
			carry = 0;
		}
		else
		{
			no = 0;
			carry = 0;
		}
		temp = new node;
		temp->data = no;
		temp->next = temp->prev = NULL;
		if(X.head == NULL)
			  X.head = X.last = temp;
		else
		{
			X.last->next =temp;
			temp->prev = X.last;
			X.last = temp;
		}
		if(temp1) temp1 = temp1->next;
		if(temp2) temp2 = temp2->next;
   }
   if(carry == 1)
   {
   		temp = new node;
	    temp->data = carry;
	    X.last->next = temp;
	    temp->prev = X.last;
	    temp->next = NULL;
	    X.last = temp;
	}
   return X;
}
int main()
{
	Binary B, B1, B2, B3;
	int num1, num2, ch;
    while(1)
    {
    	cout<<"\n1. Binary Conversion, 1's Complement and 2's Complement";
    	cout<<"\n2. Addition of two nos.";
    	cout<<"\n3. Exit ";
    	cout<<"\nEnter choice: ";
    	cin>>ch;
    	switch(ch)
    	{
    		case 1: cout<<"\nEnter a decimal no.: ";
    		cin>>num1;
   		  	B.dec_to_bin(num1);
    		cout<<" Binary Number: "; B.display();
    		B.ones_comp(); B.twos_comp();
    		B.Initiate();
    		break;
    		case 2: cout<<"\nEnter first decimal no.: ";
    		cin>>num1;
    		cout<<"Enter second decimal no.: ";
    		cin>>num2;
    		B1.dec_to_bin(num1);
    		cout<<"First Binary Number: ";
    		B1.display();
    		B2.dec_to_bin(num2);
    		cout<<"\nSecond Binary Number: ";
    		B2.display();
    		B3 = B1.add(B2);
    		cout<<"\n"; B1.display(); cout<<" + "; B2.display(); cout<<" = "; B3.display(); cout<<endl;
    		B1.Initiate(); B2.Initiate(); B3.Initiate();
    		break;
    		case 3: exit(0); break;
    		default: cout<<"Invalid Option"<<endl; break;
    	}
    }
	return 0;
}