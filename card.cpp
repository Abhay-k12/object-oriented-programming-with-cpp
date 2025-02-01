#include<iostream>
using namespace std;
class Card{
    private:
      string cardno;
      string type;
    public:
    Card(string cardno="", string type=""){
        this->cardno=cardno;
        this->type=type;
    }
      void masterCardChecker(){
          if(cardno[0]=='5' && (cardno[1]>='1'||cardno[1]<='5')){
             if(cardno.length()==16){
                cout<<"valid card number"<<endl;
             }
          }else{
             cout<<"in-valid card number"<<endl;
          }
          
      }
      void visaCardChecker(){
        if(cardno[0]=='4' && (cardno.length()>=13 && cardno.length()<=16 )){
            cout<<"valid card number"<<endl;
        }else{
        cout<<"in-valid card number"<<endl;
        }
      }
      void AmericanExpressCardChecker(){
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
    int choice;
    do{
        string cardnum,cardtype;
        cout<<"\nSelect the card type:"<<endl;
        cout<<"1.Master card"<<endl;
        cout<<"2.Visa"<<endl;
        cout<<"3.American Express"<<endl;
        cout<<"0. EXIT"<<endl;
        cin>>choice;
        switch(choice){
            case 1:{
                cout<<"Enter the card number:";
                cin>>cardnum;
                Card c1(cardnum,"master card");
                break;
            }
            case 2:{
                cout<<"Enter the card number:";
                cin>>cardnum;
                Card c1(cardnum,"visa");
                break;
            }
            case 3:{
                cout<<"Enter the card number:";
                cin>>cardnum;
                Card c1(cardnum,"American express");
                break;
            }
        }
    }while(choice!=0);
    return 0;
}