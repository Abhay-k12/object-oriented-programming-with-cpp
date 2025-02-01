/*QUES 27. Define an exception class called InvalidAgeException that accept user’s
 age and if the age is less than 18 then throw an exception with suitable error 
 message and catch it by displaying that message.*/

#include <iostream>
#include <exception>
using namespace std;

class AgeException:public exception{
    public:
    int age;

    //constructor
    AgeException(int age):age(age){}

    //what function to return error
    const char *what(){
        return " is not suitable age to vote";
    }
};

int main(){
    int num;
    cout<<"Enter the age:";
    cin>>num;
    try{
        if(num<18){
            AgeException obj(num);
            throw obj;
        }else{
            cout<<num<<" is perfect age to vote"<<endl;
        }
    }
    catch(AgeException e){
        cout<<e.age<<e.what()<<endl;;
    }
    cout<<"**************************************************"<<endl;
    cout<<"Program Preapred & Executed by: Abhay Kanojia     CSE(A1)    Class Roll no: 04"<<endl;
    cout<<"**************************************************\n"<<endl;
    return 0;
}