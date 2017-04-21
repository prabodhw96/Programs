#include <iostream>
#include <string.h>
#include <ctype.h>
using namespace std;
#define size 100
char stack[size];
int top=-1;
void push(char c)
{
    stack[++top] = c;
}
char pop()
{
    return stack[top--];
}
void palin(char str[])
{
    int i, count=0, co=0;
    for(i=0; i<strlen(str); i++)
    {
        if(isupper(str[i]))
            str[i] = tolower(str[i]);
        if(str[i] != ' ' && !ispunct(str[i]))
            str[co++] = str[i];
    }
    str[co] = '\0';
    for(i=0; i<strlen(str); i++)
            push(str[i]);
    for(i=0; i<strlen(str); i++)
    {
        if(str[i] == pop())
            count++;
    }
    if(count == strlen(str)) cout<<"Palindrome"<<endl;
    else cout<<"NOT a Palindrome"<<endl;
}
int main() {
    char str[size];
    cout<<"Enter string you want to check if it is a palindrome or not: "<<endl;
    cin.getline(str, size);
    palin(str);
    return 0;
}