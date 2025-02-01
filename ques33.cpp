/*33. Create a program to store and display a list of integers (up to 20 values) entered by the 
user. The program should: 
• Display the list in the order entered. 
• Remove the first and last element from the list. 
• Display the updated list.*/
#include <iostream>
#include <list>
using namespace std;

void display(list<int>&ls){
    for(auto it=ls.begin();it!=ls.end();it++)
        cout<<*it<<" ";
    cout<<endl;
}

int main(){
    list<int>ls;
    cout<<"Enter the values :";
    while(ls.size()!=20){
        int num;
        cin>>num;
        ls.push_back(num);
    }
    cout<<"Original Elements are :";
    display(ls);

    //Removing the first and last element
    ls.pop_back();
    ls.pop_front();
    cout<<"Elements after removing :";
    display(ls);
    cout<<"**************************************************"<<endl;
    cout<<"Program Preapred & Executed by: Abhay Kanojia     CSE(A1)    Class Roll no: 04"<<endl;
    cout<<"**************************************************\n"<<endl;
    return 0;
}