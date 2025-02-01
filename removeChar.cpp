/*Construct a C++ program that removes a specific character from a given string and return the updated string.*/
#include <iostream>
using namespace std;
string remove_char(string str,char ch){
    string ans="";
    int indx=0;
    for(int i=0;i<str.length();i++){
        if(str[i]!=ch){
            ans+=str[i];
        }
    }
    return ans;
}
int main(){
    string str,ans;
    char ch;
    cout<<"Enter the string:";
    getline(cin,str);
    cout<<"Enter the character to delete:";
    cin>>ch;
    cout<<"main string:"<<str<<endl;
    ans=remove_char(str,ch);
    cout<<"Modified string:"<<ans<<endl;
    cout<<"***************************************************"<<endl;
    cout<<"Program Preapred & Executed by: Abhay Kanojia     CSE(A1)    Class Roll no: 04"<<endl;
    cout<<"***************************************************"<<endl;
    return 0;
}