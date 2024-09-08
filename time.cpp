#include<iostream>
#include<iomanip>
using namespace std;
class Time{
    private:
    int hour;
    int min;
    int sec;
    public:
    Time(int hour,int min,int sec){
        this->hour=hour;
        this->min=min;
        this->sec=sec;
    }
    Time operator +(Time temp){
        Time t3(0,0,0);
        t3.sec=sec+temp.sec;    //(sec+temp.sec)%60;
        t3.min=min+temp.min;    // (min+temp.min)
        t3.hour=hour+temp.hour;
        if(t3.sec>=60){
            t3.sec-=60;
            t3.min+=1;
        }
        if(t3.min>=60){
            t3.min-=60;
            t3.hour+=1;
        }
        if(t3.hour>12){
            t3.hour-=12;
        }
        return t3;
    }
    void display(){
        cout<<setfill('0')<<setw(2)<<hour<<":"<<setfill('0')<<setw(2)<<min<<":"<<setfill('0')<<setw(2)<<sec<<":"<<endl;
    }

};
int main(){
    Time t1(10,50,55);
    cout<<"time 1= ";
    t1.display();
    Time t2(2,10,23);
    cout<<"time 2= ";
    t2.display();
    Time t3(0,0,0);
    t3=t1+t2;
    cout<<"time 3= ";
    t3.display();
    return 0;
}