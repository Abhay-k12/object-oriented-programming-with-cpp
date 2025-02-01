/*Develop a class Score that tracks a player's score in a game. Implement the following:
1. Data Member: An int data member to store the score. 
2. Constructors: o A default constructor to initialize the score to 0.  A parameterized constructor to initialize the score to a specific value. 
3. Overloaded Operators:  Overload the pre-increment (++) operator to increase the score by 10 points and return the updated object. Overload the post-increment (++) operator to increase the score by 10 points but return the original object before the increment. 
4. Main Function: Create a Score object, demonstrate the use of both pre-increment and post increment operators, and display the score after each.
*/
#include<iostream>
using namespace std;
class Score{
    private:
       int score;
    public:
    Score(){
        score=0;  
    }
    Score(int score){   //Score(int s):score(s){}
        this->score=score;
    }
    Score operator ++(){  //pre
        score+=10;
        return *this; // when we've used & this repp that we're returning the reference of the object that has envoked the function.
    }
    Score& operator ++(int){  //post
        Score temp=*this;  //assigning values(reference) of s1 to temp
        score+=10;
        return temp;
    }
    void display()const{
        cout<<"score="<<score<<endl;
    }
};
int main(){
   Score s1(50);
   ++s1;
   s1.display();
   Score temp=s1++;
   temp.display();
   s1.display();
    cout<<"***************************************************"<<endl;
    cout<<"Program Preapred & Executed by: Abhay Kanojia     CSE(A1)    Class Roll no: 04"<<endl;
    cout<<"***************************************************"<<endl;
   return 0;
}