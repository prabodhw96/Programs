#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(int a[], int n, int target){
    int low=0;
    int high=n;
    while(low<=high)
            {
                int mid=(low+high)/2;
                if(a[mid]<target)
                    low=mid+1;
                else if(a[mid]>target)
                    high=mid-1;
                else
                    return mid;
            }
    return -1;

}
int main() {
    int n, i;
    cout<<"Enter no. of elements you want: ";
    cin>>n;
    int a[n];
    for(i=0;i<n;i++){
        cout<<"Enter element #"<<i<<": ";
        cin>>a[i];
    }
    sort(a, a+n);
    cout<<"Your sorted array is: ";
    for(i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<"\nEnter the number you want to find: ";
    int target;
    cin>>target;
    (binarySearch(a,n,target) == -1)?cout<<"Key not found":cout<<"Key found at index "<<binarySearch(a,n,target)<<endl;
    return 0;
}