#include <iostream>
using namespace std;
#include <cstring>
#include <cmath>
#include <string>

#define max 50

class Stack
{
	public:
	int top;
	string st[max];
	Stack(){
		top=-1;
	}
	
	bool isempty();
	bool isfull();
	void push(string s1);
	string pop();
	void display();
};

class expression
{
	public:
	Stack s;
	bool isoperator(char c);
	int optr(string c) ;
	void prefix_to_infix();
	void infix_to_postfix();
	void postfix_eval();
};

void Stack::display(){
	for(int i = 0; i <= top; i++)
	{
		cout << st[i] << " ";
	}
	cout << endl;
}

bool Stack::isempty(){ return top == -1; }
bool Stack::isfull(){ return top == max-1; }

void Stack::push(string s1){
	if(isfull()){
		cout<<"Stack is full";
	}
	else{
		st[++top] = s1;
	}
}

string Stack::pop(){
	if(isempty()){
		cout<<"Stack is not having any data"<<endl;
		return "empty";
	}
	else{
		return st[top--];
	}
}

void expression::infix_to_postfix(){
	Stack s;
	string infix , postfix;
	cout<<"Enter the infix expression"<<endl;
	cin.ignore();
	getline(cin,infix);
	int len = infix.length();
	string number = "";
	for(int i=0;i<len;i++){
		char current = infix[i];
		if(isdigit(current)){
			number += current;
			if(i == len-1 || !isdigit(infix[i+1])){
				postfix += number + " ";
				number = "";
			}
		}
		else if(isalpha(current)){
			postfix += current;
			postfix += " ";
		}
		else if(current == '('){
			s.push("(");
		}
		else if(current == ')'){
			while(!s.isempty() && s.st[s.top] != "("){
				postfix += s.pop() + " ";
			}
			if(!s.isempty()) s.pop();
		}
		else if(isoperator(current)){
			string currOp(1, current);
			while(!s.isempty() && optr(currOp) <= optr(s.st[s.top])){
				postfix += s.pop() + " ";
			}
			s.push(currOp);
		}
	}
	while(!s.isempty()){
		postfix += s.pop() + " ";
	}
	cout<<"The postfix expression is: "<<postfix<<endl;
}

int expression::optr(string c)
{
	if(c == "+" || c == "-") return 1;
	else if(c == "" || c == "/") return 2;
	else if(c == "^") return 3;
	else return 0;
}

bool expression::isoperator(char c){
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

void expression::prefix_to_infix()
{
	Stack s;
	string prefix, infix;
	cout<<"Enter the prefix expression"<<endl;
	cin.ignore();
	getline(cin,infix);
	int len = infix.length();
	string number = "";
	
	for(int i = len-1; i >= 0; i--)
	{
		//cout << "what" << endl;
		if(isoperator(prefix[i]))
		{
			string x = s.pop();
			string y = s.pop();
			string temp = "(" + x + prefix[i] + y + ")";
			//cout << temp << endl;
			//cout << "what" << endl;
			s.push(temp);
			//cout << s.st[s.top] << endl;
			

		}
		else
		{
			s.push(string(1,prefix[i]));
		}
		
		//cout << s.st[s.top];
		//cout << s.top << endl;
	}
	
	cout << s.pop() << endl;
}

void expression::postfix_eval()
{
	Stack s;
	string postfix;
	int a, b;
	cout << "Enter postfix expression: ";
	cin.ignore();
	cin.getline(postfix);
	string number = "";
	int len = postfix.length();
	
	for(int i = 0; i < len; i++)
	{
		char current = postfix[i];
		if(isdigit(current))
		{
			number += current;
			if(i == len-1 || !isdigit(postfix[i+1]))
			{
				s.push(number);
				number = "";
			}
		}
		else
		{
			a = atoi(s.pop());
			b = atoi(s.pop());
			switch(current)
			{
				case '+':
					result = b+a;
					break;
				case '-':
					result = b-a;
					break;
				case '*':
					result = b*a;
					break;
				case '/':
					result = b/a;
					break;
				case '^':
					result = pow(b, a);
					break;
				default:
					cout << "Invalid operator" << endl;
			}
			s.push(result);
		}
	}
	
	cout << s.pop() << endl;
}

int main(){
	expression E;
	int choice;
	while(true){
		cout<<"1. Infix to Postfix"<<endl;
		cout<<"2. Prefix to Infix"<<endl;
		cout<<"3. Postfix to Infix"<<endl;
		cout<<"4. Exit"<<endl;
		cout<<"Enter your choice: "<<endl;
		cin>>choice;
		switch(choice){
		case 1:
			E.infix_to_postfix();
			break;
		case 2:
			E.prefix_to_infix();
			break;
		case 3:
			break;
		case 4:
			exit(0);
		default:
			cout<<"Invalid choice"<<endl;
		}
	}
}
