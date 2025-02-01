/*QUES 30. Write a program to count number of characters, words and lines in a file. */
#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream inputFile("source.txt");
    int charCount=0,lineCount=0,wordCount=0;
    char ch;
    if(!inputFile.is_open()){
        cout<<"Error in openinf file!"<<endl;
        return 0;
    }
    string line;
    while(getline(inputFile,line)){
    lineCount++; 
    charCount+=line.length();
    bool inWord = false;
    for(char ch:line){
       if(isspace(ch)) {
          wordCount++;
        }
    } 
    wordCount++; //last word 
}
    cout<<"Number of characters : "<<charCount<<endl;
    cout<<"Number of words : "<<wordCount<<endl;
    cout<<"Number of lines : "<<lineCount<<endl;
    inputFile.close();
    return 0;
}
/*tring line;
  
        while(inputFile.get(ch)){
        if(isalpha(ch)){
            charCount++;
        }else if(isspace(ch)){
            wordCount++;
        }else if(ch=='\n'){
            lineCount++;
        }
    }
}*/