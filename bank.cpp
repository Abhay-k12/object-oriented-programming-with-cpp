#include <iostream>
using namespace std;
class Account{
    public:
     string accNo;
     string holderName;
    protected:
     float balance;
     float interestRate;
    private:
     int accPin;
    public:
     Account(string accNumber,string accHoldername,float bal, float intRate, int pinCode):
     accNo(accNumber),holderName(accHoldername),balance(bal),interestRate(intRate),accPin(pinCode){}

     void displayAccountDetails() const{
         cout<<"Account Number:"<<accNo<<endl;
         cout<<"Account Holder Name:"<<holderName<<endl;
         cout<<"Account Balance:"<<balance<<endl;
     }
};

class SavingAccount:public Account{
    public:
      SavingAccount(string accNumber,string accHoldername,float bal, float intRate, int pinCode):
      Account(accNumber,accHoldername,bal,intRate,pinCode){}
      
      void calculateInterest(){
        double interest=balance*(interestRate/100);
        cout<<"Interest calculated:"<<interest<<endl;
      }
      // we've created another display so that we can't access pin code.
       void displayAccountDetails() const{
         cout<<"Account Number:"<<accNo<<endl;
         cout<<"Account Holder Name:"<<holderName<<endl;
         cout<<"Account Balance:"<<balance<<endl;
     }
};

class CheckingAccount:protected Account{
    public:
      CheckingAccount(string accNumber,string accHoldername,float bal, float intRate, int pinCode):
      Account(accNumber,accHoldername,bal,intRate,pinCode){}

      void applyOverdraftFee(){
          double overdraftFee=30.0;
          balance-=overdraftFee;
          cout<<"overdraft Fee Applid:"<<overdraftFee<<endl;
      }

       void displayAccountDetails() const{
         cout<<"Account Number:"<<accNo<<endl;
         cout<<"Account Holder Name:"<<holderName<<endl;
         cout<<"Account Balance:"<<balance<<endl;
     }
};

int main(){
    //creating an instance of saving account
    SavingAccount saving("SA12345","JOHN DOE", 1500.00,5.0,1234);
    cout<<"Saving  Account Details:\n";
    saving.displayAccountDetails();
    saving.calculateInterest();

    //creating an instanse of checking account
    CheckingAccount checking("CA12234","JANE SMITH",2000.00,0.0,5678);
    checking.displayAccountDetails();
    checking.applyOverdraftFee();
    checking.displayAccountDetails();
    return 0;
}