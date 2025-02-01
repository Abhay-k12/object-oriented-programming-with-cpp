/*Program to demonstrates the visibility of public, protected, and private in 
different inheritance scenarios: */
#include <iostream>
using namespace std;
class Base{
    public:
        int publicVar;
    protected:
        int protectedVar;
    private:
        int privateVar;
    public:
        Base():publicVar(1),protectedVar(2),privateVar(3){}

        void showVars() const{
            cout<<"Base class-publicVar:"<<publicVar<<endl;
            cout<<"Base class-protectedVar:"<<protectedVar<<endl;
            cout<<"Base class-privateVar:"<<privateVar<<endl;
        }
};
//child class
class DerivedPrivate: private Base{
    public:
    void accessBaseMember(){
        cout<<"DerivedPublic class (private inheriance) -accessing"<<endl;
        cout<<"publicVar:"<<publicVar<<endl;
        cout<<"protectedVar:"<<protectedVar<<endl;
        cout<<"privateVar is not accessbile:\n"<<endl;
    }
};

class DerivedProtected: protected Base{
    public:
    void accessBaseMember(){
        cout<<"DerivedPublic class (protected inheriance) -accessing"<<endl;
        cout<<"publicVar:"<<publicVar<<endl;
        cout<<"protectedVar:"<<protectedVar<<endl;
        cout<<"privateVar is not accessbile:\n"<<endl;
    }
};

class DerivedPUblic: public Base{
    public:
    void accessBaseMember(){
        cout<<"DerivedPublic class (public inheriance) -accessing"<<endl;
        cout<<"publicVar:"<<publicVar<<endl;
        cout<<"protectedVar:"<<protectedVar<<endl;
        cout<<"privateVar is not accessbile:\n"<<endl;
    }
};
int main(){
    DerivedPrivate ob1;
    ob1.accessBaseMember();
    DerivedProtected ob2;
    ob2.accessBaseMember();
    DerivedPUblic ob3;
    ob3.accessBaseMember();
    cout<<"***************************************************"<<endl;
    cout<<"Program Preapred & Executed by: Abhay Kanojia     CSE(A1)    Class Roll no: 04"<<endl;
    cout<<"***************************************************"<<endl;
    return 0;
}