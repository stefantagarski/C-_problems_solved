#include <iostream>
#include <cstring>

using namespace std;

// your code here
class InvoiceItem{
    private:
    char name[100];
    int price;
public:
    InvoiceItem(){}
    InvoiceItem(char *n, int p){
        strcpy(name,n);
        price = p;


    }
    InvoiceItem(const InvoiceItem &i){
        strcpy(name,i.name);
       price= i.price;
    }
    ~InvoiceItem(){}


   char *getname(){
       return name;
    }

    int getPrice(){
        return price;
    }


};


class Invoice{
private:
    char name[10];
    int stavki;
    InvoiceItem niza[100];
public:

    Invoice(char *n, int  s, InvoiceItem *_niza){
        strcpy(name,n);
        stavki = s;
        for (int i = 0; i < s; ++i) {
                niza[i]=_niza[i];
        }
    }

    ~Invoice(){}
    int getStavki(){
        return stavki;
    }
    char *getInvoiceNumber(){
        return name;
    }

   int totalPrice(){
        int total = 0;
      
       for (int i = 0; i < getStavki(); ++i) {
               total += niza[i].getPrice();
       }
       return  total;
    }


};

// DO NOT CHANGE THE MAIN FUNCTION
int main()
{
    char number[10];
    int n;
    // testing default constructor
    InvoiceItem items[100];
    cin >> number >> n;
    for (int i = 0; i < n; i++) {
        char name[100];
        int price;
        cin >> name;
        cin >> price;
        
        // testing constructor with parameters
        InvoiceItem item(name, price);
        
        // testing copy constructor
        items[i] = InvoiceItem(item);
    }
    // testing constructor with parameters for Invoice
    Invoice invoice(number, n, items);
    
    // testing totalPrice function
    cout << "Total price for invoice number " << invoice.getInvoiceNumber() << " is " << invoice.totalPrice() << endl;

    return 0;
}
