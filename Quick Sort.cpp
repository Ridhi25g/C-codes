#include <iostream>

using namespace std;


void exchange(int *a, int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int Partition(int A[],int p,int r)
{
    int x = A[r];
    int i = p - 1;
    for(int j=p;j<r;j++)
    {
        if(A[j]<=x)
        {
            i = i + 1;
            exchange(&A[i],&A[j]);
        }
    }
    exchange(&A[i+1],&A[r]);
    return i+1;
}

void QuickSort(int A[],int p,int r)
{
    if(p < r)
    {
        int q = Partition(A,p,r);
        QuickSort(A,p,q-1);
        QuickSort(A,q+1,r);
    }
}
int main()
{
    int size;
    cout<<"Enter the size of array: ";
    cin>>size;
    int arr[size];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    QuickSort(arr,0,size-1);
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
