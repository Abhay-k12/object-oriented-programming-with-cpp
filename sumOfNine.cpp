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
    return 0;
}