/*28. Demonstrate rethrowing an exception using some real life scenario. */

#include <iostream>
#include <exception>
#include <string>
using namespace std;

//FUNCTION TO VALIDATE ACCOUNT
void validateAccount(const string& account){
    if(account.empty() || !(account[0]<'9' && account[0]>'0')){
        throw invalid_argument("Invalid account : Account number is not valid.");
    }
}

//FUNCTION TO PROCESS FUND TRANSFER
void transferFunds(const string& account, double balance, double amount){
    try{
        validateAccount(account);

        if(balance<amount){
            throw runtime_error("Insufficient balance for the transfer");
        }
        //simulate fund transfer
        cout<<"Transferring $ "<<amount<<" to account:"<<account<<endl;
    }catch(const exception& e){
        cerr<<"Error in transferFund:"<<e.what()<<endl;
        throw; //rethrow the exception to be handeled at a higher level (main function())
    }
}

int main(){
    try{
        string account;
        double balance=500.00,amount;
        cout<<"Enter AccountNo. : ";
        cin>>account;
        cout<<"Enter the Amount to be transferred : ";
        cin>>amount;
        transferFunds(account, balance, amount);
    }
    catch(const invalid_argument &e){
        cout<<"User Notification:"<<e.what()<<endl;
    }catch(const runtime_error &e){
        cout<<"User Notification:"<<e.what()<<endl;
    }
    cout<<"End of Program"<<endl;
    cout<<"**************************************************"<<endl;
    cout<<"Program Preapred & Executed by: Abhay Kanojia     CSE(A1)    Class Roll no: 04"<<endl;
    cout<<"**************************************************\n"<<endl;
    return 0;
}