#include<iostream>
using namespace std;
struct node{
int info;
node *link;
}*start,*n,*temp;
node*create_node(int i)
{
n=new node;
n->info=i;
n->link=NULL;
return n;
}
void insert_beg(node*k)
{
if(start==NULL)
{
start=k;
}
else
{
k->link=start;
start=k;
}
}
void insert_end(node*k)
{
if(start==NULL)
{
start=k;
}
else
{
temp=start;
while(temp->link!=NULL)
{
temp=temp->link;
}
k->link=temp->link;
temp->link=k;
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
cout<<"\n1.Insertion at beginning";
cout<<"\n2.Insertion at end";
cout<<"\n3. EXIT";
cout<<"\nEnter your choice::";
cin>>m;
switch(m)
{
case 1:cout<<"\nINSERTION AT BEGINNING";
cout<<"\nenter value to be pushed::";
cin>>val;
p=create_node(val);
insert_beg(p);
display();
break;
case 2:cout<<"\nINSERTION AT END";
cout<<"\nenter value to be pushed::";
cin>>val;
p=create_node(val);
insert_end(p);
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
