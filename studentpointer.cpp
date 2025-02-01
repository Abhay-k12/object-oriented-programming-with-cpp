/*Q17. Create a student database system where each student has attributes like name, roll 
number, course, and marks. The program should:
• Use a class Student to store student details.
• Use a pointer to a Student object to dynamically manage student records.
• Allow the user to add, delete, and view student records.
• Calculate and display the average marks of all students.
• Find and display the student with the highest marks
*/
#include <iostream>
#include <iomanip>
using namespace std;
class Student{
    private:
       string name;
       int rollno;
       string course;
       int marks[3];
       float avg;
    public:
       Student(string name,int rollno,string course,int marks[]){
        int sum=0;
         this->name=name;
         this->rollno=rollno;
         this->course=course;
         for(int i=0;i<3;i++){
            this->marks[i]=marks[i];
            sum+=marks[i];
         }
         this->avg=sum/3;
       }
       void display(){
        cout<<setw(20)<<name<<setw(8)<<rollno<<setw(10)<<course;
        for(int i=0;i<3;i++){
            cout<<setw(8)<<marks[i];
        }
        cout<<setw(8)<<avg<<endl;
       }
    friend Student* find_max(Student *arr[],int);
};

void display_menu(){
    cout<<"\n******Main Menu******"<<endl;
    cout<<"1. To create new student"<<endl;
    cout<<"2. To delete a student record"<<endl;
    cout<<"3. To view student data"<<endl;
    cout<<"4. To view student with maximum marks"<<endl;
    cout<<"5. To exit"<<endl;
}

Student* find_max(Student *arr[],int count){
    Student *temp=arr[0];
    for(int i=0;i<count-1;i++){
        if(temp->avg<arr[i]->avg){
            temp=arr[i];
        }
    }
    return temp;
}
int main(){
    //let us consider the database can have maximum 5 students
    Student *stud[5];
    int choice=0,n=5,count=0;
    do{
        display_menu();
        cout<<"Enter your choice:";
        cin>>choice;
        switch(choice){
          case 1:{
             string name,course;
             int roll,marks[3];
             cout<<"Enter the name:";
             cin.ignore();
             getline(cin,name);
             cout<<"Enter the roll number:";
             cin>>roll;
             cout<<"Enter the course:";
             cin.ignore();
             getline(cin,course);
             cout<<"Enter the marks:";
             for(int i=0;i<3;i++){
                cin>>marks[i];   
             }
             stud[count++]=new Student(name,roll,course,marks);
             cout<<"*******Record inserted*******"<<endl;
             break;
          }
          case 2:{
            int del;
            cout<<"Enter the record to be deleted:";
            cin>>del;
            delete stud[del-1];
            for(int i=del-1;i<count-1;i++){
               stud[i]=stud[i+1];
            }
            count--;
            cout<<"****Record has been deleted****"<<endl;
            break;
          }
          case 3:{
            cout<<setw(20)<<"NAME"<<setw(8)<<"ROLLNO."<<setw(10)<<"COURSE"<<setw(8)<<"MARKS1"<<setw(8)<<"MARKS2"<<setw(8)<<"MARKS3"<<setw(8)<<"AVERAGE"<<endl;
            for(int i=0;i<=count-1;i++){
                stud[i]->display();
            }
            break;
          }
          case 4:{
            Student *max=find_max(stud,count);
            max->display();
            break;
          }
        }
    }while(choice!=5);
    cout<<"***************************************************"<<endl;
    cout<<"Program Preapred & Executed by: Abhay Kanojia     CSE(A1)    Class Roll no: 04"<<endl;
    cout<<"***************************************************"<<endl;
    return 0;

}