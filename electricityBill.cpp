#include <iostream>
using namespace std;
float calcBill(int &unit){
    float bill=0;
    if(unit<=100){
        bill=unit*0.6;
    }else if(unit<=200){
        bill=60+(unit-100)*0.8;
    }else{
        bill=140+(unit-200)*0.9;
        bill+=50+0.15*bill;   //additional charge for more than 300 units
    }
    return bill;
}
void printBill(string name,float amt){
    cout<<"******ELECTRICITY BOARD*******"<<endl;
    cout<<"User name:\t"<<name<<endl;
    cout<<"Bill amount:\t"<<amt<<endl;
    cout<<"**********THANKYOU***********"<<endl;
}
int main(){
    int unit;
    float amt=0;
    string name;
    cout<<"Enter the name of user:";
    getline(cin,name);
    cout<<"Enter the units consumed:";
    cin>>unit;
    amt=calcBill(unit);
    printBill(name,amt);
return 0;
}