#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *link;
};
Node *top = NULL;
bool isempty()
{
    if(top == NULL)
    return true; else
    return false;
}
void push (int value)
{
    Node *ptr = new Node();
    ptr->data = value;
    ptr->link = top;
    top = ptr;
}
void pop ( )
{
    if ( isempty() )
        cout<<"Stack is Empty";
    else
{
Node *ptr = top;
top = top -> link;
delete(ptr);
}
}
void Peek()
{
    if ( isempty() )
        cout<<"Stack is empty";
    else
        cout<<"Element at top is : "<< top->data;
}
bool isEmpty() 
{
    if (top == NULL) 
    {
    return true;
    }
    else 
    {
    return false;
}
}
bool isFull()
{
	int n=100;
	if(top== n-1)
	{
		return true;
	}
	else 
	{
	return false;
}
}
void display()
{
        Node *temp;
        if ( top==NULL)
        {
                cout<<"\nStack is empty\n";
        }
        else
        {
        	temp = top;
        	while(temp!=NULL)
        	{
        	    cout<<temp->data<<"->";
        		temp=temp->link;
	        }
        }
}

int main()
{
int choice, flag=1, value;
while( flag == 1)
{
    cout<<"\n1. Push the element";
    cout<<"\n2. Pop the element";
    cout<<"\n3. Peek the top element";
    cout<<"\n4. Is Stack Full or empty\n";
    cout<<"\n5. Display the stack";
    cout<<"\n6. Is Stack Full or empty\n";
    cout<<"\n7. Exit Menu\n";
    cout<<"\nEnter the choice: ";
    cin>>choice;
    switch (choice)
    {
        case 1:
        cout<<"\nEnter Value:";
        cin>>value;
        push(value);
        break;
        case 2:
        pop();
        break;
        case 3:
        Peek();
        break;
        case 4:
        if(isEmpty())
        {
            cout<<"\nStack is empty!\n";
        }
        else 
        {
            cout<<"\nStack is not empty!\n";
        }
        break;
        case 5:
        display();
        break;
        case 6:
        if(isFull()==1)
        {
        	cout<<"\nStack is full\n";
		}
		else 
        {
            cout<<"\nStack is not full!\n";
        }
        case 7: flag = 0;
        break;
    }
}
return 0;
}
