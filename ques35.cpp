/*QUES 35. Create a program that stores a list of integers entered by the user and then: 
• Displays the unique elements (i.e., elements that appear only once) in the list. */

#include <iostream> 
#include <list> 
#include <algorithm>
using namespace std; 

int main() { 
list<int> numbers; 
int num; 
cout << "Enter integers (enter a negative number to stop):\n"; 
while (true) { 
    cin >> num; 
    if (num < 0) break; 
    numbers.push_back(num); 
}  
numbers.sort();     // Sort the list and remove duplicates
numbers.unique();   // Display unique elements 
cout << "Unique elements in the list: "; 
for (int n : numbers) { 
    cout << n << " "; 
} 

cout<<"\n**************************************************"<<endl;
cout<<"Program Preapred & Executed by: Abhay Kanojia     CSE(A1)    Class Roll no: 04"<<endl;
cout<<"**************************************************\n"<<endl;
return 0; 
}