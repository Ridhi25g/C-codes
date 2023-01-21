#include<iostream>  
#include<string> 
#include<stack>  
#include<math.h> 
#include <bits/stdc++.h> 
using namespace std;  
int s[50], top=-1, n=50;
string infix_to_prefix(string infix_expression);
string infix_to_postfix(string infix_expression);
bool IsOperator(char);  
bool IsOperand(char);  
bool eqlOrhigher(char, char);  
int PerformOperation(char operation, int op1, int op2);
int convert_postfix(string postfix_expression);  
void pop();
void push(int val);
int main()  
{  
	string postfix_expression, infix_expression, prefix_expression;  
	int ch;  
	while(ch==1||ch==2||ch==3)
	{
	cout<<"1. Convert Infix expression into Prefix expression."<<endl;
	cout<<"2. Convert Infix expression into Postfix expression."<<endl;
	cout<<"3. Evaluation of Postfix expression.\n\n";
	cout<<"\nEnter the choice: ";
	
	cin>>ch;
	cout<< "\n Do you want to continue (press 1 to continue again or 0 to exit)?";
	cin>>ch;
	}
	while(ch==1) 
	{ 
		string result;
		cout<< "\nEnter an infix expression: ";  
	    cin>>infix_expression;   
	    result = infix_to_prefix(infix_expression);  
	    cout<<"Converting your expression...\n";
	    cout<< "\n Your Infix expression is: " <<infix_expression;  
	    cout<< "\n Your Prefix Expression is: "<<result;  
	    cout<< "\n Do you want to continue (press 1 to continue again or 0 to exit)?";  
	    cin>>ch;  
	}
	while(ch==2) { 
		string result;
		cout<< "\nEnter an infix expression: ";  
	    cin>>infix_expression;   
	    result = infix_to_postfix(infix_expression);  
	    cout<<"Converting your expression...\n";
	    cout<< "\n Your Infix expression is: " <<infix_expression;  
	    cout<< "\n Your Postfix Expression is: "<<result;  
	    cout<< "\n Do you want to enter infix expression (1 to continue again/ 0 to exit)?";  
	    cin>>ch;    
	}
	while(ch==3) // Code to evaluate postfix expression
	{  
		int result;
	    cout<< "\nEnter an postfix expression to be evaluated: ";  
	    cin>>postfix_expression;   
	    result = convert_postfix(postfix_expression);  
	    cout<<"Converting your expression...\n";
	    cout<< "\nYour Postfix expression is: " <<postfix_expression; 
	    cout<< "\nResult is: " <<result;  
	    cout<< "\nDo you want to enter postfix expression (1 to continue again/ 0 to exit)?";  
	    cin>>ch;    
	} 
return 0;  

}  


//function for checking amongst operators
bool IsOperator(char c)  
{  
	if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' )  
		return true;    
	return false;
}  
 
//function for checking alphabets
bool IsOperand(char c)  
{  
	if(( c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) /* Define the character in between A to Z or a to z. If not, it returns False.*/  
		return true;   
	else
		return false;  
}  

//function for operator precedence
int precedence(char op)  
{  
	if(op == '+' || op == '-')                   
		return 1;  
	else if(op == '*' || op == '/')  
		return 2;  
	else if(op == '^')                                
		return 3;      
	return 0;
}
//function for precedence input
bool eqlOrhigher (char op1, char op2)  
{  
	int p1 = precedence(op1);  
	int p2 = precedence(op2);  
	if(p1 == p2)  
	{  
		if(op1 == '^' )  
			return false;  
		return true;  
	}  
	return (p1>p2 ? true : false);  
}  
//function for pushing value in stack
void push(int val) 
{
   if(top>=n-1)
   cout<<"Stack Overflow"<<endl;
   else 
   {
      top++;
      s[top]=val;
   }
}
////function for poping out value in stack

void pop() 
{
   if(top<=-1)
   cout<<"Stack Underflow"<<endl;
   else 
   {
      cout<<"The popped element is "<<s[top]<<endl;
      top--;
   }
}


int convert_postfix(string postfix_expression) {
	stack<int> s;
	for(int i=0; i<postfix_expression.length();i++) {
		
		if(postfix_expression[i] == ' ' || postfix_expression[i] == ',') 
			continue;
			
		else if(IsOperator(postfix_expression[i])) {
			int op1 = s.top(); 
			s.pop();
			int op2 = s.top(); 
			s.pop();
			int result = PerformOperation(postfix_expression[i], op1, op2);
            
            s.push(result);
		} 
		else if(IsOperand(postfix_expression[i])) {
            s.push( postfix_expression[i] - '0');
        }
        
	}
	return s.top();
}

int PerformOperation(char operation, int op1, int op2)
{
    
    if(operation == '+') return op1 + op2;
    else if(operation == '-') return op2 - op1;
    else if(operation == '*') return op1 * op2;
    else if(operation == '/') return op2 / op1;
    else if(operation == '^') return pow(op1,op2);
    else cout<<"Unexpected Error \n";
    return -1;
}

string infix_to_postfix(string infix_expression) 
{
	
	stack<char> s;
	string postfix = ""; 
	for(int i = 0;i< infix_expression.length();i++) {

		
		if(infix_expression[i] == ' ' || infix_expression[i] == ',') continue; 

		 
		else if(IsOperator(infix_expression[i])) 
		{
			while(!s.empty() && s.top() != '(' && eqlOrhigher(s.top(),infix_expression[i]))
			{
				postfix+= s.top();
				s.pop();
			}
			s.push(infix_expression[i]);
		}
		
		else if(IsOperand(infix_expression[i]))
		{
			postfix +=infix_expression[i];
		}

		else if (infix_expression[i] == '(') 
		{
			s.push(infix_expression[i]);
		}

		else if(infix_expression[i] == ')') 
		{
			while(!s.empty() && s.top() !=  '(') {
				postfix += s.top();
				s.pop();
			}
			s.pop();
		}
	}

	while(!s.empty()) {
		postfix += s.top();
		s.pop();
	}

	return postfix;
}

string infix_to_prefix (string infix_expression) {
	
	reverse(infix_expression.begin(), infix_expression.end()); 
	stack<char> s;
	string prefix; 
	for(int i = 0; i<= infix_expression.length();i++) {

		
		if(infix_expression[i] == ' ' || infix_expression[i] == ',') continue; 
		 
		else if(IsOperator(infix_expression[i])) 
		{
			while(!s.empty() && s.top() != '(' && eqlOrhigher(s.top(),infix_expression[i]))
			{
				prefix+= s.top();
				s.pop();
			}
			s.push(infix_expression[i]);
		}
	
		else if(IsOperand(infix_expression[i]))
		{
			prefix +=infix_expression[i];
		}

		else if (infix_expression[i] == ')') 
		{
			s.push(infix_expression[i]);
		}

		else if(infix_expression[i] == '(') 
		{
			while(!s.empty() && s.top() !=  ')') {
				prefix += s.top();
				s.pop();
			}
            s.pop();
		}
		else {
			while(!s.empty() && precedence(s.top())>=precedence(infix_expression[i])) {
				prefix+=s.top();
				s.pop();
			}
			s.push(infix_expression[i]);
		}
	}
	while(!s.empty()) {
		prefix += s.top();
		s.pop();
	}
	reverse(prefix.begin(),prefix.end()); 
	return prefix;	
}

