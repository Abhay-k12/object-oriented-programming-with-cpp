/*11. Design a class to represent bank account. Includes the following members:
• Name of depositor
• Account number
• Type of account
• Balance amount in the account
Methods:
• To assign initial values
• To deposit an amount
• To withdraw an amount after checking balance.
• To display the name and balance.
Write a program to incorporate the constructor to provide initial values.
*/
#include <iostream>
using namespace std;
class Bank{
    private:
       string dname;
       string accno;
       string type;
       double bal;
    public:
       Bank(string dname,string accno,string type,double bal):dname(dname),accno(accno),type(type),bal(bal){}
       void deposit(int value){
          bal+=value;
          cout<<"The amount "<<value<<" has been credited to your account"<<endl;
       }
       void withdraw(int value){
          if(value>bal){
            cout<<"Insufficient bank balance"<<endl;
          }else{
            bal-=value;
            cout<<"The amount "<<value<<" has been debited from your account"<<endl;
          }
       }
       void display(){
        cout<<"*****Welcome to E-Bank site*****"<<endl;
        cout<<"Account holder:"<<dname<<endl;
        cout<<"Account number:"<<accno<<endl;
        cout<<"Account type:"<<type<<endl;
        cout<<"Balance:"<<bal<<endl;
        cout<<"***********Visit again***********"<<endl;
       }
};
int main(){
    Bank d1("Abhay kanojia","456789417","savings",300000);
    int choice=0;
    do{
        cout<<"\n1.To Deposit"<<endl;
        cout<<"2.To Withdraw"<<endl;
        cout<<"3.To Check balance"<<endl;
        cout<<"0.To exit"<<endl;
        cout<<"Enter your choice:";
        cin>>choice;
        switch(choice){
             case 1:{
                int value;
                cout<<"Enter the amount to deposit:";
                cin>>value;
                d1.deposit(value);
                break;
             }
             case 2:{
                int value;
                cout<<"Enter the amount to debit:";
                cin>>value;
                d1.withdraw(value);
                break;
             }
             case 3:{
                d1.display();
                break;
             }
        }
    }while(choice!=0);
    cout<<"********Thankyou*********"<<endl;
    cout<<"***************************************************"<<endl;
    cout<<"Program Preapred & Executed by: Abhay Kanojia     CSE(A1)    Class Roll no: 04"<<endl;
    cout<<"***************************************************"<<endl;
    return 0;
}