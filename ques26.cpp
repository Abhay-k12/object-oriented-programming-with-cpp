/*QUES 26. Define an exception class called “MyNation” 
that is thrown when a string is not equal to “jai hind” or 
“JAI HIND”. Write a program that implements this exception.*/

#include <iostream>
#include <exception>
using namespace std;

class MyNation:public exception{
    public:
    string inp;

    //constructor
    MyNation(string inp):inp(inp){}

    //what function to describe the error
    const char *what(){
        return " not equals to required string.";
    }
};

int main(){
    string str;
    cout<<"Enter the string: ";
    getline(cin,str);
    try{
        if(str=="JAI HIND" || str=="jai hind"){
            cout<<str<<" is equals to required string"<<endl;
        }else{
            MyNation obj(str);
            throw obj;
        }
    }
    catch(MyNation e){
        cout<<str<<e.what()<<endl;
    }
    cout<<"**************************************************"<<endl;
    cout<<"Program Preapred & Executed by: Abhay Kanojia     CSE(A1)    Class Roll no: 04"<<endl;
    cout<<"**************************************************\n"<<endl;
    return 0;  
}
