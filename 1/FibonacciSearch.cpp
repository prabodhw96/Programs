#include <iostream>
#include <algorithm>
using namespace std;

int FibSearch(int arr[], int key, int n)
{
    int Fibk2 = 0;	// (k-2)'th Fibonacci No.
    int Fibk1 = 1;	// (k-1)'th Fibonacci No.
    int Fibk = Fibk2 + Fibk1; 	// m'th Fibonacci
    while (Fibk < n)
    {
        Fibk2 = Fibk1;
        Fibk1 = Fibk;
        Fibk  = Fibk2 + Fibk1;
    }
    int offset = -1;
    while (Fibk > 1)
    {
        int i = min(offset+Fibk2, n-1);
        if (arr[i] < key)
        {
            Fibk  = Fibk1;
            Fibk1 = Fibk2;
            Fibk2 = Fibk - Fibk1;
            offset = i;
        }
        else if (arr[i] > key)
        {
            Fibk  = Fibk2;
            Fibk1 = Fibk1 - Fibk2;
            Fibk2 = Fibk - Fibk1;
        }
        else return i;
    }
    if(Fibk1 && arr[offset+1]==key) return offset+1;
    return -1;
}

int main()
{
    int n, key;
    cout<<"Enter no. of elements: ";
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
    {
    	cout<<"Enter #"<<i<<": ";
    	cin>>a[i];
    }
    sort(a, a+n);
    cout<<"After sorting: "<<endl;
    for(int i=0; i<n; i++)
    	cout<<a[i]<<" ";
    cout<<"\nEnter the element you want to find: ";
    cin>>key;
    int res = FibSearch(a, key, n);
    (res == -1)?cout<<"Not Found":cout<<"Found at index: "<<res;
    return 0;
}