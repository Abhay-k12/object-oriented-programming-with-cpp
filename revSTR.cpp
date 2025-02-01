/*Write C++ program to reverse each word of string.*/
#include <iostream>
using namespace std;
void revstr(string &str){
    int i=0,j=str.length()-1;
    while(i<j){
        char temp=str[i];
        str[i++]=str[j];
        str[j--]=temp;
    }
}
int main(){
    string str;
    cout<<"Enter the string:";
    getline(cin,str);
    cout<<"Entered string:"<<str<<endl;
    revstr(str);
    cout<<"Reversed string:"<<str<<endl;
    cout<<"***************************************************"<<endl;
    cout<<"Program Preapred & Executed by: Abhay Kanojia     CSE(A1)    Class Roll no: 04"<<endl;
    cout<<"***************************************************"<<endl;
    return 0;
}