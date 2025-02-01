/*3. An electricity board charges the following rates to domestic users to discourage large 
consumption of energy. 
For the first 100 units: - 60 P per unit 
For the next 200 units: -80 P per unit 
Beyond 300 units: -90 P per unit
All users are charged a minimum of Rs 50 if the total amount is more than Rs 300 then 
an additional surcharge of 15% is added. 
Implement a C++ program to read the names of users and number of units 
consumed and display the charges with names*/
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
    cout<<"***************************************************"<<endl;
    cout<<"Program Preapred & Executed by: Abhay Kanojia     CSE(A1)    Class Roll no: 04"<<endl;
    cout<<"***************************************************"<<endl;
return 0;
}