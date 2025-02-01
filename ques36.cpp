/*QUES 36. Found the frequency of each word in a sentence using map*/
#include <iostream>
#include <string>
#include <cctype>
#include<map>
using namespace std;
int main(){
    string str;
    cout<<"Enter the string:";
    getline(cin,str);
    map<string,int>wordCount;
    string word=""; //temporaray to store each word
    //phrase the string to store each word
    for(char ch:str){
        if(isalnum(ch))  //checks if the character is aplphanumeric
        {
            //build the current word
            word+=ch;    
        }else if(!word.empty())
        {
            //if a non-alphanumeric character is encounter,
            //add the word to the word count
            wordCount[word]++;
            word="";    //reset the word
        }
    }
    //Add the last word if the string ends without a separator
    if(!word.empty()){
        wordCount[word]++;
    }
    //displaying word Frequency
    cout<<"Word Frequencies:"<<endl;
    for(auto it=wordCount.begin();it!=wordCount.end();++it){
        cout<<it->first<<":"<<it->second<<endl;
    }
    cout<<"**************************************************"<<endl;
    cout<<"Program Preapred & Executed by: Abhay Kanojia     CSE(A1)    Class Roll no: 04"<<endl;
    cout<<"**************************************************\n"<<endl;
    return 0;
}