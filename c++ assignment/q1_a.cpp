#include<iostream>
#include<cmath>
using namespace std;

class A
{
    protected:
        int a;
    public:
        A()
        {
            cout<<"A's constructor\n";
        }
};
class B
{
    protected:
        int b;
    public:
        B()
        {
            cout<<"B's constructor\n";
        }
};
class C:private A,private B
{
    int c;
    public:
        C()
        {
            cout<<"C's constructor\n";
        }
        void setdata()
        {
            cin>>a>>b>>c;
        }
        void getdata()
        {
            cout<<"a "<<a<<"\nb "<<b<<"\nc "<<c<<"\n";
        }
};
int main()
{
    C obj;
    cout<<"Enter value of a b and c\n";
    obj.setdata();
    obj.getdata();
    return 0;
}
