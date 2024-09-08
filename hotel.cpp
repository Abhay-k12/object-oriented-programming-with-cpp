#include<iostream>
#include<string>
using namespace std;
class Room{
    public:
    int roomno;
    string type;
    double price;
    bool isavailable;

    //constructor to initialise room 
    Room(int rn,string t,double p){
       roomno=rn;
       type=t;
       price=p;
       isavailable=true; //initially, every room is available
    }

    void displayinfo(){
        cout<<"ROOM NUMBER: "<<roomno<<", TYPE: "<<type<<", PRICE: "<<price<<", AVAILABLE:"<<(isavailable?"available":"booked")<<endl;
    }

    void bookRoom(){
        if(isavailable){
            isavailable=false;
            cout<<"THE ROOM NUMBER "<<roomno<<" HAS BEEN SUCCESSFULLY BOOKED"<<endl;
        }else{
            cout<<"SORRY "<<"THE ROOM "<<roomno<<" IS ALREADY BOOKED"<<endl;
        }
    }

    void cancelRoom(){
        if(!isavailable){
            isavailable=true;
            cout<<"THE ROOM "<<roomno<<" HAS BEEN SUCCESFULLY CANCELED"<<endl;
        }else{
            cout<<"THE ROOM "<<roomno<<" IS ALREADY EMPTY"<<endl;
        }
    }
};

int main(){
    const int numberOfRoom=5;
    //array of pointers that can store the address of obj of class
    Room *hotelRooms[numberOfRoom]; 
    hotelRooms[0]=new Room(101,"single",50.0);
    hotelRooms[1]=new Room(102,"single",50.0);
    hotelRooms[2]=new Room(103,"double",80.0);
    hotelRooms[3]=new Room(104,"double",80.0);
    hotelRooms[4]=new Room(105,"suite",150.0);
    int choice;
    do{
        cout<<"\nHOTEL ROOM BOOKING SYSTEM"<<endl;
        cout<<"1.Display all rooms"<<endl;
        cout<<"2.Book a room"<<endl;
        cout<<"3.Cancel a booking"<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"Enter your choice:";
        cin>>choice;

        switch(choice){
            case 1:{
               cout<<"Available rooms:"<<endl;
               for(int i=0;i<numberOfRoom;i++){
                hotelRooms[i]->displayinfo();
               }
               break;
            }
            case 2:{
               int roomNum;
               cout<<"Enter the room number to book:";
               cin>>roomNum;
               bool found=false;
                for(int i=0;i<numberOfRoom;i++){
                   if(hotelRooms[i]->roomno==roomNum){
                      hotelRooms[i]->bookRoom();
                      found=true;
                   }
               }
               if(!found){
                cout<<"Room number:"<<roomNum<<"is not available"<<endl;
               }
               break;
               }
            case 3:{
               int roomNum;
               cout<<"Enter the room number to cancel:";
               cin>>roomNum;
               bool found=false;
                for(int i=0;i<numberOfRoom;i++){
                   if(hotelRooms[i]->roomno==roomNum){
                      hotelRooms[i]->cancelRoom();
                      found=true;
                   }
               }
               if(!found){
                cout<<"Room number:"<<roomNum<<"is not available"<<endl;
               }
               break;
               }
            case 4:{
                cout<<"Exiting the program, thankyou"<<endl;
                break;
            }
            default:
                cout<<"Invalid choice! please try again"<<endl;
        }
    }while(choice!=4);
    return 0;
}