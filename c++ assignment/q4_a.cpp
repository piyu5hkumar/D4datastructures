#include<iostream>
using namespace std;

class A
{
    public:
        virtual void show()=0;
};
class B:public A
{
    void show()
    {
        cout<<"in class B\n";
    }    
};
int main()
{
    A *obj;
    obj = new B();
    obj->show();
    return 0;
}
