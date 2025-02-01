/*In a university, a University has multiple Departments. Define a University class that 
aggregates multiple Department objects. Each department has properties like name, 
facultyCount, and headOfDepartment. The university "has" departments, but departments can 
exist independently.
Note: The University aggregates Department objects, where the departments are part of the 
university but exist independently (e.g., a department might be transferred or merged with 
another university).*/

#include <iostream>
using namespace std;
class Department{
    public:
    string depName;
    string hod;
    int facCount;
    int studCount;
    public:
     Department(){
        depName="N.D";
        hod="N.D";
        facCount=0;
        studCount=0;
     }
     //parameterised constructor
     Department(string depName, string hod,int facCount, int studCount):depName(depName),hod(hod),facCount(facCount),studCount(studCount){}
     void display(){
        cout<<"Department Name: "<<depName<<"\n"<<"Head of Department: "<<hod<<endl;
        cout<<"No. of faculty: "<<facCount<<"\n"<<"No. of students: "<<studCount<<"\n"<<endl;
     }
};

class University{
    protected:
      string uniName;
      Department *arr[5];
    public:
      static int totalDepartment;
      University(string uniName="N.D"):uniName(uniName){
         for(int i=0;i<5;i++){
            arr[i]=nullptr;
         }
      }
      void display(){
         cout<<"University Name: "<<uniName<<endl;
         cout<<"*****List of Departments*****"<<endl;
         for(int i=0;i<5;i++){
            if(arr[i]!=nullptr){
               arr[i]->display();
            }
         }
      }
      void addDepartment(Department *dep){
         totalDepartment++;
         arr[totalDepartment]=dep;
         cout<<"\n*****Department added*****\n"<<endl;
      } 
};
int University::totalDepartment=-1;

int main(){
    Department *cse=new Department("computer Science","Dr. Amit mishra", 126,2000);
    Department *mec=new Department("mechanical engineering","Dr. M.S rawat",20,300);
    University gehu("Graphic Era Hill Uni");
    gehu.addDepartment(cse);
    gehu.display();
    gehu.addDepartment(mec);
    gehu.display();
    cout<<"***************************************************"<<endl;
    cout<<"Program Preapred & Executed by: Abhay Kanojia     CSE(A1)    Class Roll no: 04"<<endl;
    cout<<"***************************************************"<<endl;
    return 0; 
}