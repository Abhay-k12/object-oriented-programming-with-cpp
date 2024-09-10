#include <iostream>
using namespace std;
class A{
    int a,t;
    public:
    A(){
        a=t=0;
     }
    A(int x,int y){
        a=x;
        t=y;
        cout<<"A::a"<<a<<endl;
        cout<<"A::t"<<t<<endl;
    }
};
class B:A{
    int b;
    public:
    // default constructor
    B():A(){
        b=0;
    }
    //parameterised constructor
    B(int x, int y,int z):A(x,y){
        b=z;
       cout<<"B::b"<<b<<endl;
    }
};
class C:B{
    int c;
    public:
    // default constructor
    C():B(){
        c=0;
    }
    //parameterised constructor
    C(int x, int y, int z,int s):B(x,y,z){
       c=s;
       cout<<"C::c"<<c<<endl;
    }
};
int main(){
    C ob1();
    C ob(7,8,9,10);
    return 0;
}