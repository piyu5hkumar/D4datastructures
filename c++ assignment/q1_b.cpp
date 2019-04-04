#include<iostream>
using namespace std;

class student
{
    protected:
        string name;
        int Class;
        unsigned int roll;
        string gender;
    public:
        student()
        {
            name="NA";
            Class=0;
            roll=0;
            gender="unknown";
        }
        virtual void getdata()=0;
        virtual void setdata()=0;
};

class exam:protected student
{
    protected:
        int m[6];
    public:
        exam()
        {
            for(int i=0;i<6;i++)
            {
                m[i]=0;
            }
        }
    virtual void calcresult()=0;
};
class result:private exam
{
    private:
        int total;
        float avg;
        char grade;
    public:
        result()
        {
            total=0;
            avg=0;
            grade='U';
        }

        void setdata();
        void getdata();
        void calcresult();
};

void result::setdata()
{
    cout<<"Enter name\t";
    getline(cin,name);
    cout<<"Enter class\t";
    cin>>Class;
    cout<<"Enter roll number\t";
    cin>>roll;
    cin.clear();
    fflush(stdin);
    cout<<"Enter gender\t";
    cin>>gender;
    cout<<"Enter marks of 6 subjects\n\n";
    for(int i=0;i<6;i++)
    {
        cout<<"marks of subject "<<i+1<<"\t";
        cin>>m[i];
    }
    
    calcresult();
}

void result::calcresult()
{
    total=0;
    for(int i=0;i<6;i++)
    {
        total+=m[i];
    }
    avg=(float)total/6;
    if(avg>90)
        grade = 'A';
    else if(avg>80)
        grade = 'B';
    else if(avg>70)
        grade = 'C';
    else if(avg>60)
        grade = 'D';
    else
        grade = 'E';
}
 void result::getdata()
 {
     cout<<"name "<<name<<endl;
     cout<<"class "<<Class<<endl;
     cout<<"roll "<<roll<<endl;
     cout<<"gender "<<gender<<endl;
     cout<<"marks ";
     for(int i=0;i<6;i++)
     {
         cout<<m[i]<<" ";
     }
     cout<<endl;
     cout<<"total marks "<<total<<endl;
     cout<<"avg marks "<<avg<<endl;
     cout<<"grade "<<grade<<endl;
 }

 int main()
 {
     result r1;
     r1.setdata();
     cout<<"\n\n";
     r1.getdata();
     return 0;
 }
