#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int w=low-1;
    for(int j=low; j<high; j++)
    {
        if(arr[j]<=pivot)
        {
            w++;
            swap(&arr[w], &arr[j]);
        }
    }
    swap(&arr[w+1], &arr[high]);
    return w+1;
}

void quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int part = partition(arr, low, high);
        quickSort(arr, low, part-1);
        quickSort(arr, part+1, high);
    }
}

int main()
{
    int n;
    cout<<"Enter no. of elements: ";
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cout<<"Enter #"<<i<<": ";
        cin>>arr[i];
    }
    quickSort(arr, 0, n-1);
    cout<<"\nSorted Array: ";
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    return 0;
}