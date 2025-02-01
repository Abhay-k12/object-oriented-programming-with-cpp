#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class Student{
    private:
        int rollNumber;
        string name;
        int age;
        string course;
    public:
        //method to input student details
        void inputStudentDetails(){
            cout<<"Enter Roll NUmber:";
            cin>>rollNumber;
            cin.ignore();
            cout<<"Enter Name:";
            getline(cin,name);
            cout<<"Enter age:";
            cin>>age;
            cin.ignore();
            cout<<"Enter the course:";
            getline(cin,course);
        }

        //method to display student details
        void displayStudentDetails() const{
            cout<<"Roll Number:"<<rollNumber<<"\nName:"<<name
            <<"\nAge:"<<age<<"\nCourse:"<<course<<"\n";
        }

        //save student to file
        
}