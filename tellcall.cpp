/*10. A class Telcall calculates the monthly phone bill of a consumer. Some of the members of 
the class are given below:
Class name: 
Data members/instance variable : phno(phone Number), sname(subscriber Name ) 
n(number of calls made) and amt (bill amount).
Member function/methods: 
TelCall() : Parameterized constructor to assign values to data 
members.
Void compute( ) : to calculate the phone bill amount base on the slabs given 
below.
Void display( ) : to display the details in the specified format.
Number of calls Rate
1 – 100 Rs. 500/- rental charge only
101 – 200 Rs 1.00 per call + rental charge
201-300 Rs. 1.20 per call + rental charge
Above 300 Rs. 1.50 per call + rental charge*/
#include <iostream>
#include <iomanip>
using namespace std;
class TelCall{
    private:
       string sname;
       string phno;
       int n;
       float amt;
    public:
       TelCall():sname(""),phno(""),n(0),amt(0){}
       TelCall(string sname,string phno,int n):sname(sname),phno(phno),n(n){}
       void compute(){
        if(n<=100){
            amt=500;
        }else if(n<=200){
            amt=500+(n-100)*1;
        }else if(n<=300){
            amt=500+100+(n-200)*1.2;
        }else{
            amt=500+220+(n-300)*1.5;
        }
       }

       void display(){
        cout<<"********************HOTEL LARAVEL********************"<<endl;
        cout<<setw(17)<<"subscriber name:"<<setw(10)<<sname<<setw(20)<<"subscriber phno:"<<setw(10)<<phno<<endl;
        cout<<setw(17)<<"total calls:"<<setw(10)<<n<<setw(20)<<"Bill:"<<setw(10)<<amt<<endl;
        cout<<"**********************THANKYOU**********************"<<endl;
       }
};
int main(){
    TelCall a("Rahul","1234567890",300);
    a.compute();
    a.display();
    cout<<"***************************************************"<<endl;
    cout<<"Program Preapred & Executed by: Abhay Kanojia     CSE(A1)    Class Roll no: 04"<<endl;
    cout<<"***************************************************"<<endl;
    return 0;
} 