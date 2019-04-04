#include<iostream>
using namespace std;

class value
{
    protected:
        int a,b;
    public:
        value()
        {
            a=b=0;
        }
        value(int a,int b)
        {
            this->a=a;
            this->b=b;
        }
};
class addition:private value
{
    public:
    int sum()
    {
        return a+b;
    }
    addition(int a,int b):value(a,b){}
};
class subtraction:private value
{
    public:
    int difference()
    {
        return a-b;
    }
    subtraction(int a,int b):value(a,b){}
};
class multiplication:private value
{
    public:
    int product()
    {
        return a*b;
    }
    multiplication(int a,int b):value(a,b){}
};

int main()
{
    cout<<"Enter two values\t";
    int a,b;
    cin>>a>>b;
    cout<<"\nsum = "<<(new addition(a,b))->sum();
    cout<<"\ndifference = "<<(new subtraction(a,b))->difference();
    cout<<"\nproduct = "<<(new multiplication(a,b))->product();
    return 0;
}