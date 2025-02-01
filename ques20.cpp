/*Develop a simulation for an autonomous vehicle. Create a base class Vehicle with 
properties like speed and fuelLevel. Then, derive LandVehicle and FlyingVehicle, where each 
has unique attributes like wheelCount and altitude. Create a FlyingCar class that inherits from 
both LandVehicle and FlyingVehicle, demonstrating how a flying car would combine the 
capabilities of land and aerial vehicles.*/
#include <iostream>
using namespace std;

class Vehicle{
    protected:
      float speed;
      int fuelLevel;
    public:
      Vehicle(float speed,int fuelLevel):speed(speed),fuelLevel(fuelLevel){}
};

class LandVehicle:virtual public Vehicle{
    protected:
      int wheelCount;
      int rpm;
    public:
      LandVehicle(float speed,int fuelLevel,int wheelCount,int rpm):Vehicle(speed,fuelLevel){
        this->wheelCount=wheelCount;
        this->rpm=0;
      }
};

class FlyingVehicle:virtual public Vehicle{
    protected:
     int altitude;
    public:
     FlyingVehicle(float speed,int fuelLevel,int altitude):Vehicle(speed,fuelLevel){
        this->altitude=altitude;
     }
};

class FlyingCar:public LandVehicle,public FlyingVehicle{
    public:
    FlyingCar(float speed,int fuelLevel,int wheelCount,int rpm,int altitude):Vehicle(speed,fuelLevel),LandVehicle(speed,fuelLevel,wheelCount,rpm),FlyingVehicle(speed,fuelLevel,altitude){}
      void landMode(){
        cout<<"Vehicle is running at the speed of "<<speed<<" and has fuel level of "<<fuelLevel<<endl;
        cout<<"Vehicle has "<<wheelCount<<" wheels which are moving with "<<rpm<<"RPM"<<endl;
      }
      void airMode(){
        cout<<"Vehicle is flying at the speed of "<<speed<<" and is at an altitude of "<<altitude<<endl;
      }
};

int main(){
    FlyingCar car1(100,500,4,78,500);
    int choice;
    do{
        cout<<"1.For Land mode"<<endl;
        cout<<"2.For Air mode"<<endl;
        cout<<"3.Stop vehicle"<<endl;
        cout<<"Enter the choice:";
        cin>>choice;
        if(choice==1){
            car1.landMode();
        }else if(choice==2){
            car1.airMode();
        }
        else{
            cout<<"Invalid-choice"<<endl;
            break;
        }
    }while(choice!=3);
    return 0;
}

