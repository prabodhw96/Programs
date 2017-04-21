#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int i, j, k;

int str_len(char str[])
{
	int length = 0;
	for(i=0; str[i]!='\0'; i++)
		length++;
	return length;
}

void str_cpy(char str[])
{
	int l = str_len(str);
	char str_cp[l];
	for(i=0; i<l; i++)
		str_cp[i] = str[i];
    str_cp[l] = '\0';
	cout<<"Copied string is "<<str_cp<<endl;
}

void str_cmp(char str1[], char str2[])
{
	int count = 0, l1 = str_len(str1), l2 = str_len(str2);
	if(l1 == l2)
	{
		for(i=0; i<l1; i++)
		{
			if(str1[i] == str2[i])
				count++;
		}
		if(count == l1)
			cout<<"Both strings are same";
		else
			cout<<"Both strings are not same";
	}
	else
	{
		cout<<"Both strings are not same";
		return;
	}
}

void str_cat(char str1[], char str2[])
{
	j=0;
	for(i=str_len(str1); str2[j]!='\0'; i++)
		str1[i] = str2[j++];
	str1[i] = '\0';
	cout<<"Concatenation of strings is: "<<str1;
}

void str_rev(char str[])
{
	int l = str_len(str), j=0;
	char rev[l];
	for(i=l-1; i>=0; i--)
		rev[j++] = str[i];
	rev[j] = '\0';
	cout<<"Reverse of the string is: "<<rev;
}

void str_palin(char str[])
{
    int l = str_len(str);
	char pal[l];
 	int j=0,count=0;
 	for(i=l-1; i>=0; i--)
  		pal[j++] = str[i];
 	pal[j] = '\0';
 	for(i=0; i<l; i++)
 	{
  		if(str[i] == pal[i])
			count++;
  	else
		break;
	}
 	(count == l)?cout<<"String is palindrome":cout<<"String is not a palindrome";
}

void sub_str(char str[], char sub[])
{
    j = 0;
	for(i=0; str[i]; i++)
		if(str[i] == sub[j])
			for(k=i, j=0; str[k] && sub[j]; j++, k++)
				if(str[k]!=sub[j])
					break;
				if(!sub[j])
				{
					cout<<"Substring";
					return;
				}
	cout<<"Not a substring";
	return;
}

int main()
{
	char str1[100], str2[100];
	int ch;
	while(1)
	{
		cout<<"\n\n**********String Operations**********";
		cout<<"\n\n1. Length of string";
		cout<<"\n2. Copy the string";
		cout<<"\n3. Compare the two strings";
		cout<<"\n4. Concatenation of two strings";
		cout<<"\n5. Reverse the string";
		cout<<"\n6. Check if the string is palindrome or not";
		cout<<"\n7. Check if one string is substring of another string or not";
		cout<<"\n8. Exit";
		cout<<"\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1: cin.getline(str1, 100);
			cout<<"\nEnter string: ";
			cin.getline(str1, 100);
			cout<<"Length of the string is "<<str_len(str1); 
			break;
			case 2: cin.getline(str1, 100);
			cout<<"\nEnter string: ";
			cin.getline(str1, 100);
			str_cpy(str1); 
			break;
			case 3: cin.getline(str1, 100);
			cout<<"\nEnter first string: ";
			cin.getline(str1, 100);
			cout<<"Enter second string: ";
			cin.getline(str2,100);
			str_cmp(str1, str2);
			break;
			case 4: cin.getline(str1, 100);
			cout<<"\nEnter first string: ";
			cin.getline(str1, 100);
			cout<<"Enter second string: ";
			cin.getline(str2,100);
			str_cat(str1, str2);
			break;
			case 5: cin.getline(str1, 100);
			cout<<"\nEnter string: ";
			cin.getline(str1, 100);
			str_rev(str1);
			break;
			case 6: cin.getline(str1, 100);
			cout<<"\nEnter string: ";
			cin.getline(str1, 100);
			str_palin(str1);
			break;
			case 7: cin.getline(str1, 100);
			cout<<"\nEnter first string: ";
			cin.getline(str1, 100);
			cout<<"Enter second string: ";
			cin.getline(str2, 100);
			if(str_len(str1)>=str_len(str2))
				sub_str(str1, str2);
			else
				sub_str(str2, str1);
			break;
			case 8: exit(0); break;
			default: cout<<"\nInvalid choice"; break;
		}
	}
	return 0;
}