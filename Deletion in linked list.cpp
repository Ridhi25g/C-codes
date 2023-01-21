#include<iostream>
using namespace std;
struct node{
int info;
node *link;
}*start,*n,*temp*temp2;
node*create_node(int i)
{
n=new node;
n->info=i;
n->link=NULL;
return n;
}
void delete_beg()
{
if(start==NULL)
{
cout<<"UNDERFLOW";
}
else
{
temp=start;
start=start->link; 
cout<<"\nelement to be deleted:";         
cout<<temp->info;
temp->link=NULL;
delete temp;
}
}
void delete_end()
{
if(start==NULL)
{
cout<<"\nUNDERFLOW";
}
else
{
temp=start;
while(temp->link!=NULL)
{
temp2=temp;
temp=temp->link;
}
delete temp;
temp2->link=NULL;
}
}
void display()
{
if(start==NULL)
{
cout<<"EMPTY";
}
else
{
temp=start;
while(temp->link!=NULL)
{
cout<<temp->info<<" <- ";
temp=temp->link;
}
cout<<temp->info;
}
}
main()
{
int val,m,l;
char choice;
node*p;
start=NULL;
do{
cout<<"----MENU----\n";
case 1:
cout<<"\n1.Deletion at begining";
cout<<"\n2.Deletion at end";
cout<<"\n3. Exit";
cout<<"\nEnter your choice::";
cin>>m;
switch(m)
{
case 1:cout<<"\nDELETION AT BEGINING";
delete_beg();
display();
break;
case 2:cout<<"\nDELETION AT END";
delete_end;
display();
break;
case 3:cout<<"EXIT\n";
exit(0);
break;
default:cout<<"\nwrong choice";
}
cout<<"\ndo you want to continue?";
cin>>choice;
}
while(choice=='y'||choice=='Y');
}
