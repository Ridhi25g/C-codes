#include<iostream>
using namespace std;
int binary_search(int a[], int beg, int end, int val)
{
    int mid;
    while(beg <= end)
    {
        mid = (beg + end)/2;
        if(val<a[mid])
        {
            end = mid - 1;
        }
        else if(val>a[mid])
        {
            beg = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}


int main ()
{
  int n,element,result,ch;
    cout<<"Enter the size of array: ";
    cin>>n;
    cout<<"Enter the elements of the array: ";
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the element to be searched: ";
    cin>>element;
    result = binary_search(arr,0,n-1,element);
    if(result == -1)
    {
        cout<<"Element not found";
    }
    else
    {
        cout<<"Element found at "<<result + 1;
    }
    return 0;
}
