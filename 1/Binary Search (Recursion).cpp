#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(int array[],int first,int last, int target);

int main() {
    int i,n;
    cout<<"Enter number of elements you want: ";
    cin>>n;
    int list[n];
    for(i=0;i<n;i++){
        cout<<"Enter element #"<<i<<": ";
        cin>>list[i];
    }
    sort(list, list+n);
    cout<<"\nYour sorted array is: ";
    for(i=0; i<n; i++)
        cout<<list[i]<<" ";
    cout<<"\nEnter number you want to find: ";
    int target;
    cin>>target;
    (binarySearch(list,1,n,target) == -1)?cout<<"Key not found":cout<<"Key found at "<<binarySearch(list,1,n,target);
    return 0;
}
int binarySearch(int array[],int first,int last, int target)
{
 int index;

 if (first > last)
 index = -1;

 else
 {
 int mid = (first + last)/2;

 if (target == array[mid])
 index = mid;
 else

 if (target < array[mid])
 index = binarySearch(array,first, mid-1, target);
 else
 index = binarySearch(array, mid+1, last, target);

 }
 return index;
 }