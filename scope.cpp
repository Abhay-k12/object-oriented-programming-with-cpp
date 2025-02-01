/*Program to demonstrates all the possible uses of the scope resolution operator in a 
single program:
Scope Resolution Operator used for following purposes:
1. Differentiating between the local and global variable.
2. To check the overriding of function display().
3. To access the variable of namespace n1.
4. To initialize a static variable university_name.*/

#include<iostream>
#include<iomanip>
using namespace std;
int size = 3;

namespace n1
{
    string name = "N.A.";
    string rollno = "N.A.";
}

class Student
{
    public:
     string sname;
     string rollno;
     static string university_name;
    public:
        //default constructor
        Student(){
            sname = n1::name;
            rollno = n1::rollno;
        }

        //parameterized constructor
        Student(string sname,string rollno){
            this->sname = sname;
            this->rollno = rollno;
        }

        void Display(){
            cout<<"Student Name:"<<sname<<"   "<<"Roll no:"<<rollno<<"   "<<"University:"<<university_name<<endl;
        }

};

class DerivedStudent: public Student{
    private:
      string address;
      string phoneno;
      float cgpa;
    public:
        DerivedStudent():Student(){
            address="N.A";
            phoneno="N.A";
            cgpa=0;
        }
        DerivedStudent(string sname,string rollno,string address,string phoneno, float cgpa):Student(sname,rollno){
            this->address=address;
            this->phoneno=phoneno;
            this->cgpa=cgpa;
        }

        void Display(){
            Student::Display();
            cout<<"Address: "<<address<<"   "<<"PhoneNO: "<<phoneno<<"   "<<"Cgpa: "<<cgpa<<"\n"<<endl;
        }
};
string Student::university_name = "G.E.H.U.";


int main()
{
    int size=5;
    int globalsize = ::size;
    DerivedStudent* s[globalsize];
    s[0] = new DerivedStudent();
    s[1] = new DerivedStudent("Abhay","04","clement Town","1234567890",9.98);

    s[0]->Display();
    s[1]->Display();
    cout<<"***************************************************"<<endl;
    cout<<"Program Preapred & Executed by: Abhay Kanojia     CSE(A1)    Class Roll no: 04"<<endl;
    cout<<"***************************************************"<<endl;
    return 0;
}

