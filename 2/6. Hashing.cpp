#include <iostream>
#include <cstdlib>
using namespace std;
#define SIZE 5
typedef long long int ll;
int currSize = 0;
class DataItem
{
public:
	string name;
	ll data;
};
DataItem HT[SIZE];
int hashCode(ll key)
{
	return key % SIZE;
}
void Display()
{
	for(int i=0; i<SIZE; i++)
		cout<<HT[i].name<<"->"<<HT[i].data<<endl;
}
void Insert(string name, ll phone)
{
    int hashKey = hashCode(phone);
    while(HT[hashKey].data != 0)
    {
        hashKey += 1;
        hashKey %= SIZE;
        if(currSize == SIZE)
        {
        cout<<"\nHash Table Overflow"<<endl;
        return;
        }
    }
    HT[hashKey].name = name;
    HT[hashKey].data = phone;
    currSize += 1;
}
void Delete(ll phone)
{
	int hashKey = hashCode(phone);
	int t = hashKey;
	while(HT[hashKey].data != phone)
	{
		hashKey += 1;
		hashKey %= SIZE;
		if(hashKey == t)
		{
			cout<<"Contact Not present"<<endl;
			return;
		}
	}
	HT[hashKey].name = "";
	HT[hashKey].data = 0;
	currSize -= 1;
}
void Search(ll phone)
{
	int hashKey = hashCode(phone);
	int t = hashKey;
	while(HT[hashKey].data != phone)
	{
		hashKey += 1;
		hashKey %= SIZE;
		if(hashKey == t)
		{
			cout<<"Contact Not present"<<endl;
			return;
		}
	}
	cout<<HT[hashKey].name<<"\t"<<HT[hashKey].data<<endl;
}
int main()
{
	string name;
	int ch;
	ll phone;
	while(true)
	{
		cout<<"\n1. Insert Contact"<<endl;
		cout<<"2. Display all Contacts"<<endl;
		cout<<"3. Search Contact"<<endl;
		cout<<"4. Delete Contact"<<endl;
		cout<<"5. Exit"<<endl;
		cout<<"Enter choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1: cout<<"Enter name: ";
			cin>>name;
			cout<<"Enter contact no.: ";
			cin>>phone;
			Insert(name, phone); break;
			case 2: Display(); break;
			case 3: cout<<"Enter contact no.: ";
			cin>>phone;
			Search(phone); break;
			case 4: cout<<"Enter contact no.: ";
			cin>>phone;
			Delete(phone); break;
			case 5: exit(1); break;
		}
	}
    return 0;
}