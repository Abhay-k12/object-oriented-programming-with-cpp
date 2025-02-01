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
    Vehicle(){
        speed=0;
        fuelLevel=0;
    }
    Vehicle(float speed, int fuelLevel):speed(speed),fuelLevel(fuelLevel){}
};

class LandVehicle:public Vehicle{
    protected:
     int wheelCount;
     float altitude;
    public:
     LandVehicle():Vehicle(){
        wheelCount=0;
        altitude=0;
     }
     LandVehicle(float speed,int fuelLevel,int wheelCount,float altitude):Vehicle(speed,fuelLevel){
        this->wheelCount=wheelCount;
        this->altitude=altitude;
     }
     void start(){
        cout<<"vehicle is started"<<endl;
     }
     void running(){
        cout<<"vehicle is running at the speed of "<<speed<<"km/h"<<endl;
     }
     void ApplyBreak(){
        cout<<"vehicle is stoped"<<endl;
     }
};

class FlyingVehicle:public Vehicle{
    protected:
     int wheelCount;
     float altitude;
    public:
     FlyingVehicle():Vehicle(){
        wheelCount=0;
        altitude=0;
     }
     FlyingVehicle(float speed,int fuelLevel,int wheelCount,float altitude):Vehicle(speed,fuelLevel){
        this->wheelCount=wheelCount;
        this->altitude=altitude;
     }
    void start(){
        cout<<"vehicle's wing has started moving"<<endl;
    }
    void flying(){
        cout<<"vehicle is flying at the speed of "<<speed<<"km/h"<<" at altitude of"<<altitude<<endl;
    }
    void ApplyBreak(){
        cout<<"vehicle is in free air"<<endl;
    }
};

class FlyingCar:public LandVehicle,public FlyingVehicle{
    float speedLand;
    float speedAir;
   public:
   FlyingCar():LandVehicle(),FlyingVehicle(){}
   FlyingCar(float speedLand,float speedAir, int fuelLevel,int wheelCount,float altitude):LandVehicle(speedLand,fuelLevel,wheelCount,altitude),
   FlyingVehicle(speedAir,fuelLevel,wheelCount,altitude){}
};

int main(){
    FlyingCar car1();
    FlyingCar car2(50.50,120.56,500,4,1200);
    cout<<"when Flying car is at Land"<<endl;
    car2.LandVehicle::start();
    car2.LandVehicle::running();
    car2.LandVehicle::ApplyBreak();

    cout<<"\nwhen Flying car is in air"<<endl;
    car2.FlyingVehicle::start();
    car2.FlyingVehicle::flying();
    car2.FlyingVehicle::ApplyBreak();
    cout<<"***************************************************"<<endl;
    cout<<"Program Preapred & Executed by: Abhay Kanojia     CSE(A1)    Class Roll no: 04"<<endl;
    cout<<"***************************************************"<<endl;
}