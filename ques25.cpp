/*25. Develop an abstract class Ride with a pure virtual function calculateFare(). Derive classes 
like StandardRide, PremiumRide, and CarpoolRide, each implementing calculateFare() based on 
unique pricing models. */

#include <iostream>
using namespace std;

class Ride{
   public:
    virtual int calculateFare(int)=0;
    virtual void menu()=0;
};

class StandardRide:public Ride{
   public:
   int calculateFare(int distance){
      return distance*250;
   }
   void menu(){
    cout<<"welcome to standard ride"<<endl;
    cout<<"here we will drop you at your destination with quality drive and sweet music.\ngive us an opourtunity to please you"<<endl;
    cout<<"Offered things: music,AC furnished car"<<endl;
    cout<<"Prices: 250Rs/km"<<endl;
   }
};

class PremiumRide:public Ride{
    public:
    int calculateFare(int distance){
        return distance*500;
    }
    void menu(){
    cout<<"welcome to premium ride"<<endl;
    cout<<"here we will drop you at your destination with quality drive and sweet\nmusic where you can enjoy your company all alone and might be with your friends"<<endl;
    cout<<"Offered things: music,AC furnished car,premium water"<<endl;
    cout<<"Prices: 500Rs/km"<<endl;
   }

};

class CarpoolRide:public Ride{
    public:
     int calculateFare(int distance){
        return distance*100;
     }
     void menu(){
        cout<<"welcome to carpooling ride\nhere we will drop you at your destination\nwith some people with you can match your vibes.";
        cout<<"Prices: 100Rs/km"<<endl;
     }
};

int main(){
    Ride *ptr;
    float dist;
    int choice;
    do{
       cout<<"\n1. To select premium ride"<<endl;
       cout<<"2. To select standard ride"<<endl;
       cout<<"3. To select carpooling"<<endl;
       cout<<"0. To exit"<<endl;
       cin>>choice;
       switch(choice){
        case 1:{
           PremiumRide ob1;
           ptr=&ob1;
           ptr->menu();
           cout<<"Enter the distance to travelled:"<<endl;
           cin>>dist;
           cout<<"Amount for "<<dist<<"km is "<<ptr->calculateFare(dist)<<endl;
           break;
        }
        case 2:{
           StandardRide ob2;
           ptr=&ob2;
           ptr->menu();
           cout<<"Enter the distance to travelled:"<<endl;
           cin>>dist;
           cout<<"Amount for "<<dist<<"km is "<<ptr->calculateFare(dist)<<endl;
           break;
        }
        case 3:{
           CarpoolRide ob3;
           ptr=&ob3;
           ptr->menu();
           cout<<"Enter the distance to travelled:"<<endl;
           cin>>dist;
           cout<<"Amount for "<<dist<<"km is "<<ptr->calculateFare(dist)<<endl;
        }
       }
    }while(choice!=0);
    cout<<"**************************************************"<<endl;
    cout<<"Program Preapred & Executed by: Abhay Kanojia     CSE(A1)    Class Roll no: 04"<<endl;
    cout<<"**************************************************"<<endl;
    return 0;
}