#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int n, i;

struct student
{
	int rno;
	string name;
	float mark;
}st[100];

void average()
{
	float sum = 0.00;
	for(i=0; i<n; i++)
	{
		if(st[i].mark!=-1)
			sum+=st[i].mark;
	}
	float avg = sum/n;
	cout<<"Average marks of the class: " <<avg<<endl;
}

void hl_mark()
{
	float a[n];
	int j=0;
	for(i=0; i<n; i++)
	{
		if(st[i].mark!=-1)
		{
			a[j++] = st[i].mark;
		}
	}
	sort(a, a+j);
	cout<<"Highest mark: "<<a[j-1]<<endl;
	cout<<"Lowest mark: "<<a[0]<<endl;
}

void max_mark()
{
	float new_arr[n];
	int j=0;
	for(i=0; i<n; i++)
	{
		if(st[i].mark!=-1)
		{
			new_arr[j++] = st[i].mark;
		}
	}
	sort(new_arr, new_arr+j);
	float prev = new_arr[0];
	int cnt = 1;
	for(int i=1; i<j; i++)
	{
		if(new_arr[i]==prev) cnt++;
		else
		{
			cout<<cnt<<" students scored "<<prev<<" marks."<<endl;
			prev = new_arr[i];
			cnt = 1;
		}
	}
	cout<<cnt<<" students scored "<<prev<<" marks."<<endl;
}

void absent()
{
	int sno = 1;
	cout<<"\nAbsent Students"<<endl;
	cout<<"Sr. No."<<setw(15)<<"Roll No."<<setw(20)<<"Name of Student"<<endl;
	for(int i=0; i<n; i++)
	{
		if(st[i].mark == -1)
		{
			cout<<sno++<<setw(20)<<st[i].rno<<setw(20)<<st[i].name<<endl;
		}
	}
}

int main()
{
	int ch;
	cout<<"Enter number of students (If a student was absent, enter -1): ";
	cin>>n;
	for(i=0; i<n; i++)
	{
		cout<<"\nName: ";
		cin>>st[i].name;
		cout<<"Roll no.: ";
		cin>>st[i].rno;
		cout<<"Marks (out of 50): ";
		cin>>st[i].mark;
	}
	cout<<"\nRoll No."<<setw(20)<<"Name of Student"<<setw(15)<<"Marks"<<endl;
	for(i=0; i<n; i++)
		cout<<st[i].rno<<setw(20)<<st[i].name<<setw(20)<<st[i].mark<<endl;
	while(1)
	{
		cout<<"\n1. Average Marks of the class"<<endl;
		cout<<"2. Highest and lowest marks of the class"<<endl;
		cout<<"3. Marks scored by most of the students"<<endl;
		cout<<"4. Students absent in the test"<<endl;
		cout<<"5. Exit"<<endl;
		cout<<"Enter your choice: ";
		cin>>ch;
		cout<<endl;
		switch(ch)
		{
			case 1:	average();
			break;
			case 2:	hl_mark();
			break;
			case 3:	max_mark();
			break;
			case 4: absent();
			break;
			case 5: exit(0);
			break;
			default: cout<<"Invalid choice"<<endl;
			break;
		}
	}
	return 0;
}