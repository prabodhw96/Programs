#include <iostream>
#include <ctype.h>
using namespace std;
char stack[100];
int top = -1;
void push(char c)
{
	stack[++top] = c;
}
char pop()
{
	return stack[top--];
}
bool empty()
{
	return (top == -1);
}
bool isOperator(char x)
{
	if(x == '+' || x == '-' || x == '*' || x == '/' || x == '^') return true;
	else return false;
}
bool isOperand(char x)
{
	if(isalpha(x) || isdigit(x)) return true;
	else return false;
}
int precedence(char x)
{
	switch(x)
	{
	case '+':
	case '-':
		return 2;
	case '*':
	case '/':
		return 3;
	case '^':
		return 4;
	}
}
string Infix_to_Postfix(string str)
{
	string postfix = "";
	int len = str.length();
	for(int i = 0; i < len; i++)
	{
		if(isOperand(str[i])) postfix+=str[i];
		else if(str[i]=='(') push(str[i]);
		else if(str[i]==')')
		{
			while(!empty() && stack[top]!='(')
			{
				postfix += stack[top];
				pop();
			}
			pop();
		}
		else if(isOperator(str[i]))
		{
			if(empty() || stack[top] == '(' || precedence(stack[top]) < precedence(str[i])) push(str[i]);
			else
			{
				postfix += stack[top];
				pop();
				push(str[i]);
			}
		}
	}
	while(!empty())
	{
		postfix += stack[top];
		pop();
	}
	return postfix;
}
int main() {
	string s;
	cout<<"Enter Infix Expression (without spaces) : "<<endl;
	cin>>s;
	cout<<"Your Infix Expression is: "<<s<<endl;
	cout<<"Your Postfix Expression is: "<<Infix_to_Postfix(s)<<endl;
	return 0;
}