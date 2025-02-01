/*QUES 24. Solve the following problem by using runtime polymorphism:
Following tables outlines the major creditd cards you might want to validate, 
along with their allowed prefixes and lengths. Major Credit Cards, Their Prefixes and Lengths.
CardType                                   Prefixes                        Length
MasterCard                                 51-55                            16
Visa                                             4                                   13,16
American Express                      34,37                             15

Sample well-Formed Credit Card Numbers
CardType                                     Sample Number 
MasterCard                                  5500 0000 0000 0004
Visa                                              4111 1111 1111 1111
American Express                        3400 0000 0000 009
 */
#include <iostream>
using namespace std;

class Card{
    protected:
     string cardno;
    public:
    Card(string cardno):cardno(cardno){}
    void virtual cardCheck()=0;
};

class MasterCard:public Card{
    public:
    MasterCard(string cardno):Card(cardno){}
    void cardCheck(){
          if(cardno[0]=='5' && (cardno[1]>='1'||cardno[1]<='5')){
             if(cardno.length()==16){
                cout<<"valid card number"<<endl;
             }
          }else{
             cout<<"in-valid card number"<<endl;
          }     
    }
};

class Visa:public Card{
    public:
    Visa(string cardno):Card(cardno){}
     void cardCheck(){
        if(cardno[0]=='4' && (cardno.length()>=13 && cardno.length()<=16 )){
            cout<<"valid card number"<<endl;
        }else{
        cout<<"in-valid card number"<<endl;
        }
      }
};

class AmericanExpress:public Card{
    public:
    AmericanExpress(string cardno):Card(cardno){}
     void cardCheck(){
        if(cardno[0]=='3' && (cardno[1]=='4' || cardno[1]=='7')){
            if(cardno.length()==15){
                cout<<"valid card number"<<endl;
            }
        }else{
         cout<<"in-valid card number"<<endl;
         }
      }
};

int main(){
    Card *cr;
    string cardno;
    int choice;
    do{
       cout<<"\n******Welcome to e-Card Lobby*****"<<endl;
       cout<<"1. For MasterCard"<<endl;
       cout<<"2. For Visa"<<endl;
       cout<<"3. For AmericanExpress"<<endl;
       cout<<"0. For exit"<<endl;
       cin>>choice;
       switch(choice){
          case 1:{
            cout<<"Enter the card number:";
            cin>>cardno;
            MasterCard c1(cardno);
            cr=&c1;
            cr->cardCheck();
            break;
          }
          case 2:{
            cout<<"Enter the card number:";
            cin>>cardno;
            Visa c2(cardno);
            cr=&c2;
            cr->cardCheck();
            break;
          }
          case 3:{
            cout<<"Enter the card number:";
            cin>>cardno;
            AmericanExpress c3(cardno);
            cr=&c3;
            cr->cardCheck();
            break;
          }
       }
    }while(choice!=0);
    cout<<"**************************************************"<<endl;
    cout<<"Program Preapred & Executed by: Abhay Kanojia     CSE(A1)    Class Roll no: 04"<<endl;
    cout<<"**************************************************"<<endl;
    return 0;
}