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
        cout<<"DerivedPublic class (public inheriance) -accessing"<<endl;
        cout<<"publicVar:"<<publicVar<<endl;
        cout<<"protectedVar:"<<protectedVar<<endl;
        cout<<"privateVar is not accessbile:"<<endl;
    }
};

int main(){
    DerivedPrivate ob;
    ob.accessBaseMember();
    return 0;
}