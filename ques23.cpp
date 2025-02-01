/*QUES 23. Write a program to create a class named shape. In this class we have three sub classes
 circle, triangle and square each class has two member functions named draw () and erase (). 
Implements these functions using runtime polymorphism concepts.*/

#include <iostream>
using namespace std;
class Shape{
    public:
     void virtual draw()=0;
     void virtual erase()=0;
};

class Circle:public Shape{
    public:
      void draw(){
        cout<<"Drawing circle"<<endl;
      }
      void erase(){
        cout<<"Erasing the circle"<<endl;
      }
};

class Triangle:public Shape{
    public:
      void draw(){
        cout<<"Drawing triangle"<<endl;
      }
      void erase(){
        cout<<"Erasing the triangle"<<endl;
      }
};

class Rectangle:public Shape{
    public:
      void draw(){
        cout<<"Drawing rectangle"<<endl;
      }
      void erase(){
        cout<<"Erasing the rectangle"<<endl;
      }
};

int main(){
    Shape *ptr;
    Circle ob1;
    ptr=&ob1;
    cout<<"Demonstration of Run-time Polymorphism using pure virtual function"<<endl;
    cout<<"Drawing (ptr->draw()) and Erasing circle (ptr->erase())"<<endl;
    ptr->draw();
    ptr->erase();
    Triangle ob2;
    ptr=&ob2;
    cout<<"\nDrawing (ptr->draw()) and Erasing triangle (ptr->erase())"<<endl;
    ptr->draw();
    ptr->erase();
    Rectangle ob3;
    ptr=&ob3;
    cout<<"\nDrawing (ptr->draw()) and Erasing rectangle (ptr->erase())"<<endl;
    ptr->draw();
    ptr->erase();
    cout<<"**************************************************"<<endl;
    cout<<"Program Preapred & Executed by: Abhay Kanojia     CSE(A1)    Class Roll no: 04"<<endl;
    cout<<"**************************************************"<<endl;
    return 0;
}