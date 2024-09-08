#include<iostream>
using namespace std;
class Student{
    private:
      int score[5];
    public:
      void input(){
        for(int i=0;i<5;i++)
           cin>>score[i];
      }
      int totalScore(){
        int sum=0;
        for(int i=0;i<5;i++){
            sum+=score[i];
        }
        return sum;
      }

};
int main(){
    int n,annaScore,count=0;
    cout<<"enter the no. of student:";
    cin>>n;
    Student students[n];
    for(int i=0;i<n;i++){
        cout<<"marks of student "<<i+1<<":";
        students[i].input();
    }
    annaScore=students[0].totalScore();
    for(int i=1;i<n;i++){
       if(annaScore<students[i].totalScore()){
          count++;
       }
    }
    cout<<"students scored more than anna:"<<count<<endl;
    return 0;
}