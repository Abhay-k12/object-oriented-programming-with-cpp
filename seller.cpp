#include <iostream>
#include <string>
using namespace std;
//class for seller (base calass)
class Seller{
    protected:
     string name;
     double revenue;
    public:
     Seller(string name,double revenue):name(name),revenue(revenue){}
     void displaySellerInfo(){
        cout<<"Seller:"<<name<<endl;
     }
};

//class for individual seller
class IndividualSeller:public Seller{
public:
  IndividualSeller(string name,double revenue):Seller(name,revenue){}

  void displayInfo(){
    cout<<"Individual Seller Name:"<<name<<endl;
  }
  void showRevenue(){
    cout<<"Individual seller Revenue:"<<revenue<<endl;
  }
};

//class for business seller
class BusinessSeller:public Seller{
    string businessname;
public:
  BusinessSeller(string name,double revenue,string busname):Seller(name,revenue){
    businessname=busname;
  }
   void displayInfo(){
    cout<<"business Name:"<<businessname<<endl;
    cout<<"owner:"<<name<<endl;
  }
  void showRevenue(){
    cout<<"Business seller Revenue:"<<revenue<<endl;
  }
  void showBusinessDetails(){
    cout<<"Business Name:"<<businessname<<endl;
    cout<<"Business Ownwer:"<<name<<endl;
  }
};

class Product{
    string productName;
    double price;
    string category;
    IndividualSeller*indSeller; //pointer to individualSeller
    BusinessSeller*busSeller; //pointer to BusinessSeller
    public:
    //constructor for individual seller
     Product(string productname,double price,string category,IndividualSeller*seller):
     productName(productname),price(price),category(category),indSeller(seller),busSeller(nullptr){}
    
    //constructor for business seller
     Product(string productname,double price,string category,BusinessSeller*seller):
     productName(productname),price(price),category(category),indSeller(nullptr),busSeller(seller){}

    void display(){
        cout<<"\nProduct name:"<<productName<<endl;
        cout<<"Price:$"<<price<<endl;
        cout<<"Category:"<<category<<endl;
        
        //display seller if linked
        if(indSeller!=nullptr){
            indSeller->displayInfo();
        }else if(busSeller!=nullptr){
            busSeller->displayInfo();
        }
    }
};

int main(){
  IndividualSeller indSeller("john",5000.50);
  BusinessSeller busSeller("jane smith",15000.75,"tech.bizz.org");
  Product p1("laptop",999.9,"electronics",&indSeller);
  Product p2("tablet",100.99,"mobile phone",&indSeller);
  Product p3("t-shirt",50.9,"clothing",&busSeller);
  Product p4("shorts",50.9,"clothing",&busSeller);
  p1.display();
  p2.display();
  p3.display();
  p4.display();
    return 0;
}
