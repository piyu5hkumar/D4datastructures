#include<iostream>
using namespace std;

class person
{
    protected:
        string name;
        char gender;
        int age;
        string mobile;
    public:
        person();
        person(string,char,int,string);
        void setdata();
        void getdata();
};
person::person()
{
    name="N.A";
    gender='U';
    age=0;
    mobile="N.A";
}
person::person(string name,char gender,int age,string mobile)
{
    this->name=name;
    this->gender=gender;
    this->age=age;
    this->mobile=mobile;
}
void person::setdata()
{
    cout<<"Enter name\n";
    cin>>name;
    cout<<"Enter gender\n";
    cin>>gender;
	cin.clear();
	fflush(stdin);
	cout<<"Enter age\t";
	cin>>age;
    cin.clear();
    fflush(stdin);
	cout<<"Enter mobile number\t";
    cin>>mobile;
}
void person::getdata()
{
    cout<<"name = "<<name;
    cout<<"\nGender = "<<gender;
    cout<<"\nage = "<<age;
    cout<<"\nMobile number = "<<mobile<<endl;
}
class student:private person
{
    private:
        int Class;
        long int roll;
        int marks[3];
    public:
        student():person("N.A",'U',0,"N.A")
        {
            Class=0;
            roll=0;
            marks[0]=marks[1]=marks[2]=0;
        }
        void setdata();
        void getdata();
};
void student::setdata()
{
    person::setdata();
    cout<<"Enter class\n";
    cin>>Class;
    cout<<"Enter roll number\n";
    cin>>roll;
    cout<<"Enter 3 subjects marks\n";
    cin>>marks[0]>>marks[1]>>marks[2];
}

void student::getdata()
{
    person::getdata();
    cout<<"\nclass = "<<Class;
    cout<<"\nroll = "<<roll;
    cout<<"\nmarks are = "<<marks[0]<<" "<<marks[1]<<" "<<marks[2]<<endl;
}

class employee:private person
{
    int empno;
    string department;
    int salary;
    public:
       employee():person("N.A",'U',0,"N.A")
        {
            empno=0;
            department="N.A";
            salary=0;
        } 
        void setdata();
        void getdata();
};
void employee::setdata()
{
    person::setdata();
    cout<<"Enter employee number\n";
    cin>>empno;
    cout<<"Enter department name\n";
    cin>>department;
    cout<<"Enter salary\n";
    cin>>salary;
}
void employee::getdata()
{
    person::getdata();
    cout<<"employee number = "<<empno;
    cout<<"\ndepartment = "<<department;
    cout<<"\nsalary = "<<salary<<endl;
}
int main()
{
    person p1;
    employee e1;
    student s1;
    cout<<"\nEnter values for a person\n\n";
    p1.setdata();
    cout<<"\n";
    p1.getdata();
    
    cout<<"\nEnter values for employee\n\n";
    e1.setdata();
    e1.getdata();

    cout<<"\nEnter values for student\n\n";
    s1.setdata();
    s1.getdata();
    return 0;
}
