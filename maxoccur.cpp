/*Write a C++ program to find the maximum occurring character in a string*/
#include <iostream>
using namespace std;
char max_occur(string str){
    int arr[256]={0};
    int max=0;
    char ch;
    for(int i=0;i<str.length();i++){
        int val=(char)str[i];
        arr[val]++;
    }
    for(int i=0;i<256;i++){
       if(arr[i]>max){
        max=arr[i];
        ch=(int)i;
       }
    }
    return ch;
}

int main(){
    string str;
    char ch;
    cout<<"Enter the string:";
    getline(cin,str);
    ch=max_occur(str);
    cout<<"Maximum occuring character:"<<ch<<endl;
    cout<<"***************************************************"<<endl;
    cout<<"Program Preapred & Executed by: Abhay Kanojia     CSE(A1)    Class Roll no: 04"<<endl;
    cout<<"***************************************************"<<endl;
    return 0;


}