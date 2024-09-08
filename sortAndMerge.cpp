#include <iostream>
using namespace std;
void input(int arr[],int size){
    for(int i=0;i<size;i++)
        cin>>arr[i];
}
void bubbleSort(int arr[], int size){
     for(int i=0;i<size;i++){
        for(int j=0;j<size-1;j++){
            if(arr[i]>arr[i+1]){
                int temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
        }
     }
}
int main(){
    int arr1[10],arr2[10],ans[20];
    int size1,size2,size3=0;
    cout<<"Enter the number of elements in array 1:";
    cin>>size1;
    cout<<"Enter the number of elements in array 2:";
    cin>>size2;
    cout<<"Enter the elements of array 1:";
    input(arr1,size1);
    cout<<"Enter the elements of array 2:";
    input(arr2,size2);
    for(int i=0;i<size1;i++){
        ans[size3++]=arr1[i];
    }
    for(int i=0;i<size2;i++){
        ans[size3++]=arr2[i];
    }
    size3--;
    bubbleSort(ans,size3);
    cout<<"new sorted array: ";
    for(int i=0;i<size3;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}