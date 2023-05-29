#include <cstring>
#include <iostream>
using namespace std;

enum SIZE {
    MALA,GOLEMA,FAMILIJARNA
};

class Pizza{
protected:
    char name[21];
    char ingridients[101];
    double cena;
public:
    Pizza(const char *name ="dsd",const char *ingridients ="df",double cena =0.0){
        strcpy(this->name,name);
        strcpy(this->ingridients,ingridients);
        this->cena = cena;
    }
    virtual double price() const = 0;

    bool operator<(const Pizza& rhs) const {
        return price() < rhs.price();
    }

    friend ostream& operator<<(ostream& os, const Pizza& pizza) {
        os << pizza.name << ": " << pizza.ingridients << " - " << pizza.price()<<endl;
        return os;
    }

};
class FlatPizza : public Pizza{
private:
    SIZE golemina;
public:
    FlatPizza(const char *name ="",const char *ingridients ="",double cena =0.0,SIZE golemina=MALA) : Pizza(name,ingridients, cena){
        this->golemina = golemina;
    }
    double price() const  {
        if(golemina == MALA){
            return cena * 1.1;
        }else if(golemina == GOLEMA){
            return cena * 1.2;
        } else if(golemina == FAMILIJARNA){
            return cena * 1.3;
        }else {
            return cena;
        }
    }
    friend ostream& operator<<(ostream& out, FlatPizza &flatPizza) {
        out << flatPizza.name << ": " << flatPizza.ingridients << ", ";
        if(flatPizza.golemina == MALA){
            out<<"small";
        }else if(flatPizza.golemina == GOLEMA){
            out<<"medium";
        }else{
            out<<"family";
        }
        out<<" - "<< flatPizza.price() << endl;
        return out;
    }

};
class FoldedPizza : public Pizza {
private:
    bool whiteFlour;
public:
    FoldedPizza(const char* name, const char* ingredients, float basePrice)
            : Pizza(name, ingredients, basePrice), whiteFlour(true) {}

    void setWhiteFlour(bool isWhiteFlour)
    {
        whiteFlour = isWhiteFlour;
    }

    double price() const{
        if (whiteFlour)
            return cena * 1.1;
        else
            return cena * 1.3;
    }

    friend ostream& operator<<(ostream& os, const FoldedPizza& foldedPizza)
    {
        os<<foldedPizza.name<<": "<<foldedPizza.ingridients<<", ";
        foldedPizza.whiteFlour ? os << "wf " : os << "nwf ";
        os<<"- "<<foldedPizza.price()<<endl;
        return os;
    }
};
void expensivePizza(Pizza** pizzas, int numPizzas) {
    Pizza* mostExpensivePizza = pizzas[0];
    for (int i = 1; i < numPizzas; ++i) {
        if(pizzas[i]->price() > mostExpensivePizza->price()){
            mostExpensivePizza = pizzas[i];
        }
    }
    if(FlatPizza *casted = dynamic_cast <FlatPizza*>(mostExpensivePizza)){
        cout<<*casted<<endl;
    }
    if( FoldedPizza *_casted = dynamic_cast <FoldedPizza*>(mostExpensivePizza)){
        cout<<*_casted<<endl;
    }

}


int main() {
    int test_case;
    char name[20];
    char ingredients[100];
    float inPrice;

    cin >> test_case;
    if (test_case == 1) {
        // Test Case FlatPizza - Constructor, operator <<, price
        cin.get();
        cin.getline(name,20);
        cin.getline(ingredients,100);
        cin >> inPrice;
        FlatPizza fp(name, ingredients, inPrice);
        cout << fp;
    } else if (test_case == 2) {
        // Test Case FlatPizza - Constructor, operator <<, price
        cin.get();
        cin.getline(name,20);
        cin.getline(ingredients,100);
        cin >> inPrice;
        int s;
        cin>>s;
        FlatPizza fp(name, ingredients, inPrice, (SIZE)s);
        cout << fp;

    }
    else if (test_case == 3) {
        // Test Case FoldedPizza - Constructor, operator <<, price
        cin.get();
        cin.getline(name,20);
        cin.getline(ingredients,100);
        cin >> inPrice;
        FoldedPizza fp(name, ingredients, inPrice);
        cout << fp;
    }
    else if (test_case == 4) {
        // Test Case FoldedPizza - Constructor, operator <<, price
        cin.get();
        cin.getline(name,20);
        cin.getline(ingredients,100);
        cin >> inPrice;
        FoldedPizza fp(name, ingredients, inPrice);
        fp.setWhiteFlour(false);
        cout << fp;

    }
    else if (test_case == 5) {
        // Test Cast - operator <, price
        int s;

        cin.get();
        cin.getline(name,20);
        cin.getline(ingredients,100);
        cin >> inPrice;
        cin>>s;
        FlatPizza *fp1 = new FlatPizza(name, ingredients, inPrice, (SIZE)s);
        cout << *fp1;

        cin.get();
        cin.getline(name,20);
        cin.getline(ingredients,100);
        cin >> inPrice;
        cin>>s;
        FlatPizza *fp2 = new FlatPizza(name, ingredients, inPrice, (SIZE)s);
        cout << *fp2;

        cin.get();
        cin.getline(name,20);
        cin.getline(ingredients,100);
        cin >> inPrice;
        FoldedPizza *fp3 = new FoldedPizza(name, ingredients, inPrice);
        cout << *fp3;

        cin.get();
        cin.getline(name,20);
        cin.getline(ingredients,100);
        cin >> inPrice;
        FoldedPizza *fp4 = new FoldedPizza(name, ingredients, inPrice);
        fp4->setWhiteFlour(false);
        cout << *fp4;

        cout<<"Lower price: "<<endl;
        if(*fp1<*fp2)
            cout<<fp1->price()<<endl;
        else cout<<fp2->price()<<endl;

        if(*fp1<*fp3)
            cout<<fp1->price()<<endl;
        else cout<<fp3->price()<<endl;

        if(*fp4<*fp2)
            cout<<fp4->price()<<endl;
        else cout<<fp2->price()<<endl;

        if(*fp3<*fp4)
            cout<<fp3->price()<<endl;
        else cout<<fp4->price()<<endl;

    } else if (test_case == 6) {
        // Test Cast - expensivePizza
        int num_p;
        int pizza_type;

        cin >> num_p;
        Pizza **pi = new Pizza *[num_p];
        for (int j = 0; j < num_p; ++j) {

            cin >> pizza_type;
            if (pizza_type == 1) {
                cin.get();
                cin.getline(name,20);

                cin.getline(ingredients,100);
                cin >> inPrice;
                int s;
                cin>>s;
                FlatPizza *fp = new FlatPizza(name, ingredients, inPrice, (SIZE)s);
                cout << (*fp);
                pi[j] = fp;
            }
            if (pizza_type == 2) {

                cin.get();
                cin.getline(name,20);
                cin.getline(ingredients,100);
                cin >> inPrice;
                FoldedPizza *fp =
                        new FoldedPizza (name, ingredients, inPrice);
                if(j%2)
                    (*fp).setWhiteFlour(false);
                cout << (*fp);
                pi[j] = fp;

            }
        }

        cout << endl;
        cout << "The most expensive pizza:\n";
        expensivePizza(pi,num_p);


    }
    return 0;
}