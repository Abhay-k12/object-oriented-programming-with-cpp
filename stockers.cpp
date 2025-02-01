#include <iostream>
using namespace std;

class Stock{
    private:
        double price;
        bool hype;
    public:
        Stock():price(0.00),hype(false){}
        Stock(double price, bool hype):price(price),hype(hype){}

        double getPrice(){
            return price;
        }

        bool getHype(){
            return hype;
        }
};

class Stockers{
    private:
        Stock **stocks;
        int size;
    public:
        Stockers(int n){
            stocks = new Stock*[n];
            size = n;
        }
        
        void merge(int start,int mid, int end){
            int left=start,right=mid+1,indx=0;
            Stock *temp= new Stock[end-start+1];
            while(left<=mid && right<=end){
                if(stocks[left]->getPrice()<stocks[right]->getPrice()){
                    temp[indx++]=*stocks[left++];
                }else{
                    temp[indx++]=*stocks[right++];
                }
            }
            while(left<=mid){
                temp[indx++]=*stocks[left++];
            }
            while(right<=end){
                temp[indx++]=*stocks[right++];
            }
            indx=0;
            while(start<=end){
                *stocks[start++]=temp[indx++];
            }
        }

        void mergeSort(int start,int end){
            if(start<end){
                int mid = start +(end-start)/2;
                mergeSort(start,mid);
                mergeSort(mid+1,end);
                merge(start,mid,end);
            }
        }

        void reverse(){
            for(int i=0,j=size-1;i<j;i++,j--){
                Stock temp = *stocks[i];
                *stocks[i] = *stocks[j];
                *stocks[j] = temp;
            }
        }

        void display(){
            for(int i=0;i<size;i++){
                cout<<stocks[i]->getPrice()<<" ";
            }
            cout<<endl;
        }

        void showDataAscending(){
            mergeSort(0,size-1);
            display();
        }

        void showDataDescending(){
            mergeSort(0,size-1);
            reverse();
            display();
        }

        int priceRoseToday(){
            int count=0;
            for(int i=0;i<size;i++){
                if(stocks[i]->getHype()) count++;
            }
            return count;
        }

        int priceDeclineToday(){
            int count = priceRoseToday();
            return size-count;
        }

        bool present(double key){
            for(int i=0;i<size;i++){
                if(stocks[i]->getPrice()==key) return true;
            }
            return false;
        }


    friend void input(Stockers &st,int);

};

void input(Stockers &st,int size){
    double price;
    bool hype;
    for(int i=0;i<size;i++){
        cout<<"Enter current stock price of the company "<<i+1<<endl;
        cin>>price;
        cout<<"Whether comapny's stock price rose today compare to yesterday?"<<endl;
        cin>>hype;
        st.stocks[i] = new Stock(price,hype);
    }
}

int main(){
    int n;
    cout<<"Enter the no of comapnies:"<<endl;
    cin>>n;
    Stockers st(n);
    input(st,n);
    int choice;
    do{
        cout<<"\n--------------------------------------------------"<<endl;
        cout<<"1.Display the companies stock in ascending order."<<endl;
        cout<<"2.Display the companies stock price in descending order"<<endl;
        cout<<"3.Display the total no of companies for which stock price rose today"<<endl;
        cout<<"4.Display the total no of companies for which stock price declined totay"<<endl;
        cout<<"5.Search a specific stock price"<<endl;
        cout<<"6.Press 0 to exit"<<endl;
        cin>>choice;
        switch(choice){
            case 1:{
                st.showDataAscending();
                break;
            }
            case 2:{
                st.showDataDescending();
                break;
            }
            case 3:{
                cout<<"Total no of companies whose stock price rose today : "<<st.priceRoseToday()<<endl;
                break;
            }
            case 4:{
                cout<<"Total no of companies whose price declined today : "<<st.priceDeclineToday()<<endl;
                break;
            }
            case 5:{
                double key;
                cout<<"Enter the key value : "<<endl;
                cin>>key;
                if(st.present(key)){
                    cout<<"Stock of value "<<key<<" is present"<<endl;
                }else{
                    cout<<"stock of value "<<key<<" is not present"<<endl;
                }
            }
        }
    }while(choice!=0);
    cout<<"Exited Successfully"<<endl;
    return 0;
}