#include <iostream>
using namespace std;
// class Stock{
//    private:
//     string name;
//     float price;
//     int isIncreased;
//    public:
//     int static stockCount;
//     Stock(string name="N.A", float price=0.0,int isIncreased=0):name(name),price(price),isIncreased(isIncreased){
//         stockCount++;
//     }
//     void isPriceIncreased(){
//         if(isIncreased==1){
//             cout<<"Stock Name: "<<name<<"    "<<"price: "<<price<<endl;
//         }
//     }
//     void isPriceDecreased(){
//         if(isIncreased==0){
//             cout<<"Stock Name: "<<name<<"    "<<"price: "<<price<<endl;
//         }
//     }
//     void display(){
//         cout<<name<<"   "<<price<<"   "<<isIncreased<<endl;   
//     }
//     friend void showSorted(Stock *arr[]);
// };

// int Stock::stockCount=0;
// void showSorted(Stock *arr[]){
//     int n=Stock::stockCount,min=-1;
//     Stock tarr[n];
//     for(int i=0;i<n;i++){
//         tarr[i]=Stock(arr[i]->name,arr[i]->price,arr[i]->isIncreased);
//     }
//     for(int i=0;i<n;i++){
//         min=i;
//         for(int j=0;j<n;j++){
//            if(tarr[min].price>tarr[j].price){
//             min=j;
//            }
//         }
//         cout<<"Stock Name: "<<tarr[min].name<<"    "<<"price: "<<tarr[min].price<<endl;
//         tarr[min].price=INT16_MAX;
//     }
// }

// int main(){
//    Stock *arr[5];
//    arr[0]=new Stock("uniliver",100.10,1);
//    arr[1]=new Stock("Tata-steel",99.30,1);
//    arr[2]=new Stock("Birla-marbel",200.47,0);
//    arr[3]=new Stock("NPTEL",12.45,0);
//    arr[4]=new Stock("Nifti",400.90,0);
//    int choice;
//    do{
//     cout<<"\n1. To see stocks of increased price"<<endl;
//     cout<<"2. To see stocks of decreased price"<<endl;
//     cout<<"3. To see stocks in sorted manner"<<endl;
//     cin>>choice;
//     switch(choice){
//         case 1:{
//             cout<<"*****Fetching details of Increased price stock*****"<<endl;
//             for(int i=0;i<Stock::stockCount;i++){
//                 arr[i]->isPriceIncreased();
//             }
//             break;
//         }
//         case 2:{
//             cout<<"*****Fetching details of Decreased price stock*****"<<endl;
//             for(int i=0;i<Stock::stockCount;i++){
//                 arr[i]->isPriceDecreased();
//             }
//             break;
//         }
//         case 3:{
//             cout<<"*****Fetching sorted data*****"<<endl;
//             showSorted(arr);
//         }
//     };
//    }while(choice!=0);
//    return 0;
// }
// class point{
//     int x;
//     int y;
//     public:
//     point(int x=0,int y=0):x(x),y(y){}
//     // friend istream& operator>>(istream &input,point &p){
//     //     input>>p.x>>p.y;
//     //     return input;
//     // }
//     // friend ostream& operator<<(ostream &output,point p){
//     //     output<<p.x<<" "<<p.y<<endl;
//     //     return output;
//     // }
//     friend point operator +(point &a,point &b);
//     friend void display(point &a);

// };
// point operator +(point &a,point &b){
//         point temp;
//         temp.x=a.x+b.x;
//         temp.y=a.y+b.y;
//         return temp;
//     }
//     void display(point &a){
//         cout<<a.x<<" "<<a.y<<endl;
//     }

// int main(){
//     point p1(12,35);
//     point p2(23,56);
//     point p3=p1+p2;
//     display(p3);
// }

class score{
    int s;
    public:
    score(int s=0):s(s){}
    void display(){
        cout<<s<<endl;
    }
    friend score operator ++(score &s);
    friend score operator --(score &s);
    friend score operator ++(score &s,int);
    friend score operator --(score &s,int);
};

    score operator ++(score &s){
        s.s=s.s+1;
        return s;
    }
    score operator --(score &s){
        s=s.s-1;
        return s;
    }
    score operator ++(score &s,int){
        score temp=s;
        s.s=s.s+1;
        return temp;
    }
    score operator --(score &s,int){
        score temp=s;
        s.s=s.s-1;
        return temp;
    }
int main(){
    score s1(100);
    s1.display();
    score temp=s1++;
    s1.display();
    temp.display();
    ++s1;
    s1.display();
    --s1;
    s1.display();
    temp=s1--;
    temp.display();
    s1.display();
    return 0;
}