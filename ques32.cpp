/*QUES 32. Write a program that reads 10 integer values from the user, stores them in a vector, and 
then: 
• Displays the elements in the vector. 
• Finds and displays the largest and smallest elements in the vector.*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void display(vector<int>&vec){
    for(int i=0;i<vec.size();i++)
        cout<<vec[i]<<" ";
    cout<<endl;
}

int main(){
    vector<int>vec(10);
    cout<<"Enter the 10 values : ";
    for(int i=0;i<10;i++)
        cin>>vec[i];
    cout<<"Entered elements are :";
    display(vec);
int min=*min_element(vec.begin(),vec.end());
int max=*max_element(vec.begin(),vec.end());
cout<<"Minimum Element : "<<min<<endl;
cout<<"Maximun Element : "<<max<<endl;
cout<<"**************************************************"<<endl;
cout<<"Program Preapred & Executed by: Abhay Kanojia     CSE(A1)    Class Roll no: 04"<<endl;
cout<<"**************************************************\n"<<endl;
}