#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    string cities[5]={"Delhi","Mumbai","Kolkata","Chennai","Dehradun"};
    int arr[10][5];
    int min_city=0,min_day=0,max_city=0,max_day=0;
    for(int i=0;i<10;i++){
        for(int j=0;j<5;j++){
            cin>>arr[i][j];
            if(arr[i][j]<arr[min_day][min_city]){
                min_day=i;
                min_city=j;
            }
            if(arr[i][j]>arr[max_day][max_city]){
                max_day=i;
                max_city=j;
            }
        }
    }
    cout<<setw(5)<<"Days";
    for(int i=0;i<5;i++){
        cout<<setw(10)<<cities[i];
    }
    cout<<endl;
    for(int i=0;i<10;i++){
        cout<<setw(5)<<i+1;
        for(int j=0;j<5;j++){
            cout<<setw(10)<<arr[i][j];
        }
        cout<<endl;
    }
    cout<<cities[max_city]<<" has a maximum temperature of "<<arr[max_day][max_city]<<" on day "<<max_day+1<<endl;
    cout<<cities[min_city]<<" has a minimum temperature of "<<arr[min_day][min_city]<<" on day "<<min_day+1<<endl;
    return 0;
}