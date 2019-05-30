#include<iostream>
#include<stack>
using namespace std;
int precedance(char ch)
{
	switch(ch)
	{

		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;
		case '_':
			return -1;
		default:	
			return 44;
	}
}
int main()
{
	cout<<"total test cases\t";
	int t;
	cin>>t;
	while(t--)
	{
		stack<char> s;
		string str;
		cin>>str;
		s.push('_');
		for(int i=0;str[i]!='\0';i++)
		{
			if(97<=str[i]&&122>=str[i])
			{
				cout<<str[i];
			}
			else if(str[i]=='(')
			{
				s.push(str[i]);
			}
			else if(str[i]==')')
			{
				while(s.top()!='(')
				{
					cout<<s.top();
					s.pop();
				}
				s.pop();
			}
			else
			{
				if(precedance(str[i])>precedance(s.top()))
				{
					s.push(str[i]);
				}
				else if(!s.empty())
				{
					while(precedance(str[i])<=precedance(s.top())&&s.top()!='(')
					{
						cout<<s.top();
						s.pop();
					}
					s.push(str[i]);
				}
			}
		}
		while(s.top()!='_')
		{
			cout<<s.top();
			s.pop();
		}
		s.pop();
		cout<<endl;
	}
	return 0;
}
