#include<iostream>
#include<cstring>

using namespace std;

class FoodItem {
protected:
    char* type;
    int num;
public:
    virtual double getPrice() = 0;
    virtual int getTime() = 0;

    FoodItem(char* type, int num) {
        this->type = new char[strlen(type) + 1];
        strcpy(this->type, type);
        this->num = num;
    }

    virtual ~FoodItem() {
        delete[] type;
    }

    char * getType() {
        return type;
    }
};

class Pizza : public FoodItem {
private:
    char* dough;
public:
    Pizza(char* type = "", int num = 0, char* dough = "") : FoodItem(type, num) {
        this->dough = new char[strlen(dough) + 1];
        strcpy(this->dough, dough);
    }
    double getPrice() {
        if (strcmp(dough, "wholeWheat") == 0) {
            return 250 * num;
        }
        else if (strcmp(dough, "glutenFree") == 0) {
            return 350 * num;
        }
        else {
            return -1;
        }
    }

    int getTime() {
        return 25;
    }

    ~Pizza() {
        delete[] dough;
    }
};

class Steak : public FoodItem {
private:
    bool cooked;
public:
    Steak(char* type, int num,bool cooked) : FoodItem(type, num) {
        this->cooked = cooked;
    }

    double getPrice() {
        return 1300 * num;
    }

    int getTime() {
        if (cooked == 1 ) { //well-done
            return 20;
        }
        else {
            return 15;
        }
    }
};

FoodItem* getMaxFoodItem(FoodItem* pItem[], int n) {
    FoodItem* maxItem = pItem[0];
    double maxPrice = 0;
    for (int i = 1; i < n; i++) {
        if (pItem[i]->getPrice() > maxPrice) {
            maxPrice = pItem[i]->getPrice();
            maxItem = pItem[i];
        }
    }

    return maxItem;
}
int main() {
    FoodItem *p;
    int n;
    cin>>n;

    char type[30];
    char dough[30];
    bool cooked;
    int size;

    FoodItem *items[n];

    for (int i = 0; i <n; ++i) {
        cin>>type;
        cin>>size;


        if(strcmp(type, "pizza")==0 ) {
            cin>>dough;
            items[i] = new Pizza(type,size, dough);
        }else{
            cin>>cooked;
            items[i] = new Steak(type, size, cooked);
        }


    }

    FoodItem *it = getMaxFoodItem(items, n);
    cout<<"Type: "<<it->getType()<<endl;
    cout<<"The max price is: "<<it->getPrice()<<endl;
    cout<<"Time to cook: "<<it->getTime();
    return 0;
}
