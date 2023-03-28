#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;


class FoodProduct {
private:
    char name[50];
    int amount;
    int price;

public:
    FoodProduct() {
        strcpy(this->name, "");
        this->amount = 0;
        this->price = 0;
    }

    FoodProduct(char *name, int amount, int price) {
        strcpy(this->name, name);
       this->amount = amount;
        this->price = price;
    }

    FoodProduct(const FoodProduct & other) {
        strcpy(name, other.name);
        amount = other.amount;
        price = other.price;
    }

    ~FoodProduct() {}

    int getAmount() const {
        return amount;
    }

    void setAmount(int amount) {
        this->amount = amount;
    }

    int getPrice() const {
        return price;
    }

    void setPrice(int price) {
        this->price = price;
    }

    int income() const {
        return amount * price;
    }

    void print() const {
        cout << "Name: " << name <<endl;
        cout << "Amount available: " << amount <<endl;
        cout << "Price: " << price <<endl;
    }
};

class Menu {
private:
    char name[50];
    int numberOfProducts;
    FoodProduct products[50];

public:
    Menu() {
        strcpy(name, "");
        numberOfProducts = 0;
    }

    Menu(char * _name) {
        strcpy(name, _name);
        this->numberOfProducts = 0;
    }

    Menu(const Menu & other) {
        strcpy(this->name, other.name);
        numberOfProducts = other.numberOfProducts;

        for(int i = 0; i < numberOfProducts; i++) {
            products[i] = other.products[i];
        }
    }

    ~Menu() {}

    const char *getName() const {
        return name;
    }

    int getNumberOfProducts() const {
        return numberOfProducts;
    }

    void setNumberOfProducts(int _numberOfProducts) {
        numberOfProducts = _numberOfProducts;
    }

    void setName(char * _name) {
        strcpy(name, _name);
    }

    void addProduct(FoodProduct product) {

        products[numberOfProducts++] = product;
    }

    void print() const {
        cout << "Name: " << name << "\n";
        cout << "Products:\n";

        for (int i = 0; i < numberOfProducts; i++)
            products[i].print();
    }

    int totalIncome() const {
        int total = 0;

        for(int i = 0; i < numberOfProducts; i++)
            total += products[i].income();

        return total;
    }
};

void printWorstMenu(Menu * menus, int  n) {
    Menu worst = menus[0];

    for (int i = 0; i < n; i++) {
        if(worst.totalIncome() > menus[i].totalIncome())
            worst = menus[i];
    }

    worst.print();
}


//DO NOT CHANGE main() FUNCTION

int main() {
    int n;
    cin >> n;

    /// BASIC INPUT & ADD PRODUCT
    Menu menus[n];

    for(int i = 0; i < n; i++) {
        int m;
        char name[50];

        cin >> name >> m;
        menus[i] = Menu(name);

        for(int j = 0; j < m; j++) {
            char itemName[50];
            int amount, price;

            cin >> itemName >> amount >> price;

            FoodProduct product(itemName, amount, price);
            menus[i].addProduct(product);
        }
    }

    /// TESTING ADD PRODUCT

    cout << "-- Testing add product & getNumberOfProducts() --\n\n";

    char tempName[50] = "test";
    Menu temp(tempName);

    cout << "Number of products before adding: " << temp.getNumberOfProducts() << '\n';

    temp.addProduct(FoodProduct(tempName, 0, 0));

    cout << "Number of products after adding: " << temp.getNumberOfProducts() << '\n';
    temp.print();

    /// TESTING COPY CONSTRUCTOR

    Menu tester(menus[0]);
    std::strcpy(tempName, "Tester Name");
    tester.setName(tempName);

    cout << "\n-- Testing copy constructor & setName() --\n";
    cout << "-------------\n";
    cout << "Source:\n";
    cout << "-------------\n";
    menus[0].print();

    cout << "\n-------------\n";
    cout << "Copied and edited:\n";
    cout << "-------------\n";
    tester.print();

    /// TESTING WORST PRODUCT

    cout << "\n-- Testing printWorstMenu() --\n";
    printWorstMenu(menus, n);
    return 0;
}
