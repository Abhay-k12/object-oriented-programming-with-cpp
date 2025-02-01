/*34. Write a program that uses a map to store student names and their corresponding scores. The 
program should: 
• Allow the user to add a student and score. 
• Search for a student by name and display their score. 
• Update the score of a student if the student is already present in the map.*/
#include<iostream>
#include <map>
#include <string>
using namespace std;

void displayMenu(){
    cout<<"1. For inserting a record"<<endl;
    cout<<"2. For searching a record"<<endl;
    cout<<"3. For updating a record"<<endl;
    cout<<"0. For exiting the program"<<endl;
}

int main(){
    map<string,int>studentScore;
    string name;
    int num,choice;
    displayMenu();
    do{
        cout<<"Enter your choice:";
        cin>>choice;
        switch(choice){
            case 1:{
                cout<<"Enter the name :";
                cin>>name;
                cin.ignore();
                cout<<"Enter the score:";
                cin>>num;
                studentScore[name]=num;
                break;
            }  
            case 2:{
                cout<<"Enter the name to search:";
                cin>>name;
                if(studentScore.find(name)!=studentScore.end()){
                cout<<name<<" is present with marks "<<studentScore[name]<<endl;
                }else{
                cout<<"***Record not found***"<<endl;
                }
                break;
            } 
            case 3:{
                cout<<"Enter student name to update:";
                cin>>name;
                if(studentScore.find(name)!=studentScore.end()){
                    cout<<"Enter the updated marks:";
                    cin.ignore();
                    cin>>num;
                    studentScore[name]=num;
                    cout<<"***Updation sucessfull***"<<endl;
                }else{
                    cout<<"***Record not found***"<<endl;
                }
            }
        }
        cout<<endl;
    }while(choice!=0);
    cout<<"**************************************************"<<endl;
    cout<<"Program Preapred & Executed by: Abhay Kanojia     CSE(A1)    Class Roll no: 04"<<endl;
    cout<<"**************************************************\n"<<endl;
    return 0;
}