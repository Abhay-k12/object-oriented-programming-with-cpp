#include <iostream>
using namespace std;
int main(){
    int sum=0,num,val=10;
    cout<<"Enter the number of terms:";
    cin>>num;
    for(int i=1;i<=num;i++){
       sum+=val-1;
       cout<<val-1<<" ";
       val*=10;
    }
    cout<<"\nThe sum of the series="<<sum<<endl;
    cout<<"***************************************************"<<endl;
    cout<<"Program Preapred & Executed by: Abhay Kanojia     CSE(A1)    Class Roll no: 04"<<endl;
    cout<<"***************************************************"<<endl;
    return 0;
}