#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;
};

class Doublell 
{
  private:
    Node* head;
  public:
    Doublell()
	{
      head = NULL;
    }
 
    void push(int value) 
	{
      Node* newNode = new Node();
      newNode->data = value;
      newNode->next = NULL;
      newNode->prev = NULL; 
      if(head == NULL) 
	  {
        head = newNode;
      } 
	  else 
	  {
        Node* temp = head;
        while(temp->next != NULL)
          temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
      }    
    }

  	void deleteOddNodes() 
	{
  	  if(head != NULL) 
	  {
  	    Node* temp = head;
  	    head = head->next; 
  	    if(head != NULL) 
		{
  	      head->prev = NULL;
  	      Node* evenNode = head;
  	      Node* oddNode = head->next; 
  	      while(evenNode != NULL && oddNode != NULL) 
		  {
  	        evenNode->next = oddNode->next;
  	        temp = evenNode;
  	        evenNode = evenNode->next;
  	        if(evenNode != NULL) 
			{
  	          evenNode->prev = temp;
  	          oddNode = evenNode->next;
  	        }
  	      }
  	    }
  	  }
  	} 

    void Display() 
	{
      Node* temp = head;
      if(temp != NULL) {
        cout<<"The list contains: ";
        while(temp != NULL) 
		{
          cout<<temp->data<<" ";
          temp = temp->next;
        }
        cout<<"\n";
      } 
	  else 
	  {
        cout<<"The list is empty.\n";
      }
    }    
};

int main() 
{
  Doublell list;
  list.push(89);
  list.push(97);
  list.push(22);
  list.push(4);

  cout<<"Before deleting odd nodes.\n";
  list.Display();

  list.deleteOddNodes();

  cout<<"After deleting odd nodes.\n";
  list.Display();
  
  return 0; 
}
