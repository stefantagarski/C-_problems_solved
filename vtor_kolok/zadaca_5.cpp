//
// Created by ACER on 5/29/2023.
//
#include<iostream>
#include<cstring>
const int MAX = 50;
using namespace std;
enum typeC{
    STANDARD,LOYAL,VIP
};
class UserAlreadyExists {
public:
    void showMessage(){
        cout<<"The user already exists in the list!"<<endl;
    }
};
class Customer{
protected:
    char name[51];
    char adress[51];
    typeC type;
    static  int primary_discount;
    const static int additional_discount;
    int n;
public:
    Customer(const char *name="",const char *adress="",typeC type={},int n = 0){
        strcpy(this->name,name);
        strcpy(this->adress,adress);
        this->type = type;
        this->n = n;
    }
    static void setDiscount1(int i){
        primary_discount = i;
    }
    friend ostream &operator<<(ostream &out, const Customer &customer)
    {
        out << customer.name << endl;
        out << customer.adress << endl;
        out << customer.n << endl;
        if(customer.type == STANDARD){
            out<<"standard ";
        }else if(customer.type == LOYAL){
            out<<"loyal ";
        }
        else {
            out << "vip ";
        }
        if (customer.type == STANDARD)
            out <<"0";
        else if (customer.type == LOYAL)
            out << customer.primary_discount;
        else if (customer.type == VIP)
            out<< customer.primary_discount + customer.additional_discount;

        return out;

    }

    const char *getAdress() const {
        return adress;
    }
    void update(){
        if (type == STANDARD && n > 5) {
            type = LOYAL;
        }
        else if (type == LOYAL && n > 10) {
            type = VIP;
        }
    }
};
int Customer::primary_discount = 10;
const int Customer::additional_discount = 20;


class FINKI_bookstore{
private:
    Customer *customers;
     int n;
    void copy(const FINKI_bookstore &g) {
        this->n = g.n;
        customers = new Customer[n];
        for (int i = 0; i < n; ++i) {
            customers[i] = g.customers[i];
        }
    }
public:
    FINKI_bookstore(){
        this->n = 0;
        this->customers = new Customer [0];
    }
    FINKI_bookstore(const FINKI_bookstore &g){
        copy(g);
    }
    FINKI_bookstore &operator=(const FINKI_bookstore &g){
        if(this != &g){
            delete [] customers;
            copy(g);
        }
        return  *this;
    }
    ~FINKI_bookstore(){
        delete [] customers;
    }

    void setCustomers(Customer *pCustomer, int num) {
        this->customers = new Customer[num];
        this->n = num;
        for (int i = 0; i < num; ++i) {
            this->customers[i] = pCustomer[i];
        }
    }
    void update(){
        for (int i = 0; i < n; ++i) {
            customers[i].update();
        }
    }

    FINKI_bookstore &operator+=(const Customer &u) {
        for (int i = 0; i < n; ++i) {
            if (strcmp(customers[i].getAdress(), u.getAdress()) == 0) {
                throw UserAlreadyExists();
            }
        }
        Customer *tmp = new Customer[n + 1];
        for (int i = 0; i < n; ++i) {
            tmp[i] = customers[i];
        }
        tmp[n++] = u;
        delete[] customers;
        customers = tmp;
        return *this;
    }

    friend ostream &operator<<(ostream &os, const FINKI_bookstore &bookstore) {
        for (int i = 0; i < bookstore.n; ++i) {
            os<<bookstore.customers[i]<<endl;
        }
        return os;
    }

};


int main(){
    int testCase;
    cin >> testCase;

    char name[MAX];
    char email[MAX];
    int tC;
    int discount;
    int numProducts;


    if (testCase == 1){
        cout << "===== Test Case - Customer Class ======" << endl;
        cin.get();
        cin.getline(name,MAX);
        cin.getline(email,MAX);
        cin >> tC;
        cin >> numProducts;
        cout << "===== CONSTRUCTOR ======" << endl;
        Customer c(name, email, (typeC) tC, numProducts);
        cout << c;

    }

    if (testCase == 2){
        cout << "===== Test Case - Static Members ======" << endl;
        cin.get();
        cin.getline(name,MAX);
        cin.getline(email,MAX);
        cin >> tC;
        cin >> numProducts;
        cout << "===== CONSTRUCTOR ======" << endl;
        Customer c(name, email, (typeC) tC, numProducts);
        cout << c;
        cout<<endl;

        c.setDiscount1(5);

        cout << c;
    }

    if (testCase == 3){
        cout << "===== Test Case - FINKI-bookstore ======" << endl;
        FINKI_bookstore fc;
        int n;
        cin >> n;
        Customer customers[MAX];
        for(int i = 0; i < n; ++i) {
            cin.get();
            cin.getline(name,MAX);
            cin.getline(email,MAX);
            cin >> tC;
            cin >> numProducts;
            Customer c(name, email, (typeC) tC, numProducts);
            customers[i] = c;
        }

        fc.setCustomers(customers, n);

        cout << fc <<endl;
    }

    if (testCase == 4){
        cout << "===== Test Case - operator+= ======" << endl;
        FINKI_bookstore fc;
        int n;
        cin >> n;
        Customer customers[MAX];
        for(int i = 0; i < n; ++i) {
            cin.get();
            cin.getline(name,MAX);
            cin.getline(email,MAX);
            cin >> tC;
            cin >> numProducts;
            Customer c(name, email, (typeC) tC, numProducts);
            customers[i] = c;
        }

        fc.setCustomers(customers, n);
        cout << "OPERATOR +=" << endl;
        cin.get();
        cin.getline(name,MAX);
        cin.getline(email,MAX);
        cin >> tC;
        cin >> numProducts;
        Customer c(name, email, (typeC) tC, numProducts);
        fc+=c;

        cout << fc;
    }

    if (testCase == 5){
        cout << "===== Test Case - operator+= (exception) ======" << endl;
        FINKI_bookstore fc;
        int n;
        cin >> n;
        Customer customers[MAX];
        for(int i = 0; i < n; ++i) {
            cin.get();
            cin.getline(name,MAX);
            cin.getline(email,MAX);
            cin >> tC;
            cin >> numProducts;
            Customer c(name, email, (typeC) tC, numProducts);
            customers[i] = c;
        }

        fc.setCustomers(customers, n);
        cout << "OPERATOR +=" << endl;
        cin.get();
        cin.getline(name,MAX);
        cin.getline(email,MAX);
        cin >> tC;
        cin >> numProducts;
        Customer c(name, email, (typeC) tC, numProducts);
        try {
            fc += c;
        } catch (UserAlreadyExists e){
            e.showMessage();
        }

        cout << fc;
    }

    if (testCase == 6){
        cout << "===== Test Case - update method  ======" << endl << endl;
        FINKI_bookstore fc;
        int n;
        cin >> n;
        Customer customers[MAX];
        for(int i = 0; i < n; ++i) {
            cin.get();
            cin.getline(name,MAX);
            cin.getline(email,MAX);
            cin >> tC;
            cin >> numProducts;
            Customer c(name, email, (typeC) tC, numProducts);
            customers[i] = c;
        }

        fc.setCustomers(customers, n);

        cout << "Update:" << endl;
        fc.update();
        cout << fc;
    }
    return 0;

}


