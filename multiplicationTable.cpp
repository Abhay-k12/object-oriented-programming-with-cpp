#include <iostream>
using namespace std;
int main(){
    int num;
    cout<<"Input number upto:";
    cin>>num;
    for(int i=1;i<=10;i++){
        for(int j=1;j<=num;j++){
            cout<<j<<"x"<<i<<"="<<j*i<<" ";
        }
        cout<<endl;
    }
    return 0;
}