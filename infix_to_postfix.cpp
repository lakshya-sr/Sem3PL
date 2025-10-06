#include <iostream>
using namespace std;
#include <cstring>
#include <cmath>
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
};

class expression
{
	public:
	Stack s;
	bool isoperator(char c);
	int optr(string c) ;
	void prefix_to_infix();
	void infix_to_postfix();
	void postfix();
};

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
