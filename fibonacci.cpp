#include <iostream>  
using namespace std;

int main() 
{  
  int ft=0,st=1,nt,i,num;    
 cout<<"Enter the number of elements to be printed: ";    
 cin>>num;    
 cout<<ft<<" "<<st<<" ";    
 for(i=2;i<num;++i)  
 {    
  nt=ft+st;    
  cout<<nt<<" ";    
  ft=st;    
  st=nt;    
 }    
   return 0;  
}
