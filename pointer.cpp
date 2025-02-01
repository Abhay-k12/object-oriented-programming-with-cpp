/*16. Write a C++ program to declare a class. Declare pointer to class. Initialize and display the 
 contents of the class member.*/
 #include <iostream>
 using namespace std;
 class Student{
    string name;
    int rollno;
    string course;
    float sgpa;
    public:
    Student(){
        name="";
        rollno=0;
        course="";
        sgpa=0.0;
    }
     Student(string name,int rollno,string course,float sgpa):
     name(name),rollno(rollno),course(course),sgpa(sgpa){}

     void display(){
        cout<<"Student Name:"<<name<<endl;
        cout<<"Studnet Rollno:"<<rollno<<endl;
        cout<<"student course:"<<course<<endl;
        cout<<"student sgpa:"<<sgpa<<endl;
     }
 };
 int main(){
    Student *s1;
    s1=new Student("john smith",1,"bba",8.9);
    s1->display();
    cout<<"***************************************************"<<endl;
    cout<<"Program Preapred & Executed by: Abhay Kanojia     CSE(A1)    Class Roll no: 04"<<endl;
    cout<<"***************************************************"<<endl;
    return 0;
 }