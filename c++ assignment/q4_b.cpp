#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s1,s2;
    cout<<"Enter string 1\n";
    getline(cin,s1);
    cout<<"Enter string 2\n";
    getline(cin,s2);
    
    cout<<"concatination of these two strings is - ";
    cout<<(s1+s2);
    
    cout<<"\ncapacity of string 1 is - "<<s1.capacity();

    s1.shrink_to_fit();
    cout<<"\ncapacity of string 1 after shrink to fit is -  "<<s1;

    cout<<"\n\nEnter the character to pushback in string s1\t";
    char c;
    cin>>c;
    s1.push_back(c);
    cout<<"\nvalue after pushback is -  "<<s1;
    
    s1.pop_back();
    cout<<"\nvalue after popback is -  "<<s1;
    
    s1.resize(3);
    cout<<"\nvalue of string after resizeing it to 3 is -  "<<s1;
    return 0;
}