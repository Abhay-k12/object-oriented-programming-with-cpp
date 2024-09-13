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
    Score& operator ++(){  //pre
        score+=10;
        //return *this; // when we've used & this repp that we're returning the reference of the object that has envoked the function.
    }
    Score  operator ++(int){  //post
        Score temp=*this;  //assigning values(reference) of s1 to temp
        score+=10;
        //return temp;
    }
    void display()const{
        cout<<"score="<<score<<endl;
    }
};
int main(){
   Score s1(50);
   ++s1;
   s1.display();
   s1++;
   s1.display();
   return 0;
}