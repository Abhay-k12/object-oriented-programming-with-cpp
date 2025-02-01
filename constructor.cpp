#include <iostream>
using namespace std;

class A{
    int a;
    public:
    A(){
        cout<<"constructor of class A"<<endl;
    }
    ~A(){
        cout<<"destructor of class A"<<endl;
    }
};

class B:public A{
    int b;
    public:
    B():A(){
        cout<<"constructor of class B"<<endl;
    }
    ~B(){
        cout<<"destructor of class B"<<endl;
    }
};

class C:public B{
    int c;
    public:
    C():B(){
        cout<<"constructor of class C"<<endl;
    }
    ~C(){
        cout<<"destructor of class C"<<endl;
    }
};

int main(){
    C obj;
    cout<<"***************************************************"<<endl;
    cout<<"Program Preapred & Executed by: Abhay Kanojia     CSE(A1)    Class Roll no: 04"<<endl;
    cout<<"***************************************************"<<endl;
    return 0;
}