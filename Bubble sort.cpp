#include<iostream>
using namespace std;
main()
{
int A[100],k,n,z,i,ch,j,p,small;
cout<<"Enter the size of array\n";
cin>>n;
cout<<"Enter the elements of array\n";
for(i=0;i<n;i++)
cin>>A[i];
for(i=1;i<n;i++)
{
for(j=0;j<n-i;j++)
{
if(A[j]>A[j+1])
{
small=A[j];
A[j]=A[j+1];
A[j+1]=small;
}
}
}
cout<<"\nSorted array is:\n";
for(i=0;i<n;i++)
cout<<A[i]<<" ";
}


