#include <iostream>
using namespace std;
class Space{
    private:
      int x;
      int y;
      int z;
    public:
      Space(int a,int b,int c){
        x=a;
        y=b;
        z=c;
      }
      Space operator -(Space temp){
        temp.x=x-temp.x; //x,y,z have s1 values and temp will have s1 values the can be accessed through . operator.
        temp.y=y-temp.y;
        temp.z=z-temp.z;
        return temp;
      }
      friend void display(Space);
};

void display(Space temp){
        cout<<temp.x<<" "<<temp.y<<" "<<temp.z<<endl;
        //values changed here won't be reflected in the main class because it's call by value.
      }
      
int main(){
    Space s1(10,-20,30);
    Space s2(9,20,30);
    Space s3(0,0,0);
    cout<<"s1:";
    display(s1);
    cout<<"s2:";
    display(s2);
    s3=s1-s2; //s1.-(s2) s1 called , s2 passed as parameter.
    cout<<"s1:";
    display(s1);
    cout<<"s2:";
    display(s2);
    cout<<"s3:";
    display(s3);
    return 0;
}

