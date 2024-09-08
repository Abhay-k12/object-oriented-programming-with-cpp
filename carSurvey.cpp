#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    string cities[5]={"Delhi","Mumbai","Chennai","Kolkata"};
    string cars[5]={"Maruti-K10","Zen-Astelo","Wagnor","Maruti-SX4"};
    int arr[10][10]={0},city,car;
    do{
        cout<<"*****MAIN MENU*****"<<endl;
        cout<<"Press 1 for Delhi"<<endl;
        cout<<"Press 2 for Mumbai"<<endl;
        cout<<"Press 3 for Chennai"<<endl;
        cout<<"Press 4 for Kolkata"<<endl;
        cout<<"Press 0 to exit"<<endl;
        cin>>city;
        if(city==0) break;
        cout<<"Press 1 for Maruti-K10"<<endl;
        cout<<"Press 2 for Zen-Astelo"<<endl;
        cout<<"Press 3 for Wagnor"<<endl;
        cout<<"Press 4 for Maruti-SX4"<<endl;
        cin>>car;
        arr[city-1][car-1]++;
    }while(car!=0);
    cout<<setw(10)<<"City";
    for(int i=0;i<4;i++){
        cout<<setw(15)<<cars[i];
    }
    for(int i=0;i<4;i++){
        cout<<"\n"<<setw(10)<<cities[i];
        for(int j=0;j<4;j++){
            cout<<setw(15)<<arr[i][j];
        }
    }
    return 0;
}