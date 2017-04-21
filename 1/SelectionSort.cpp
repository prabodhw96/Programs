#include <iostream>
using namespace std;
int main()
{
	int n, min, temp;
	cout<<"Enter no. of elements you want: ";
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
	{
		cout<<"Enter #"<<i<<": ";
		cin>>a[i];
	}
	for(int i=0; i<n-1; i++)
	{
		min = i;
		for(int j=i+1; j<n; j++)
			if(a[j]<a[min])
				min = j;
		temp = a[min];
		a[min] = a[i];
		a[i] = temp;
	}
	cout<<"Sorted Array: ";
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
	return 0;
}