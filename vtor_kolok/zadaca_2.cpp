#include <iostream>
#include<cstring>

using namespace std;


class Vozac{
protected:
    char name[101];
    int age;
    int races;
    bool veteran;
public:
    Vozac(const char *name="",int age =0,int races = 0,bool veteran = false){
        strcpy(this->name, name);
        this->age = age;
        this->races = races;
        this->veteran = veteran;
    }

    friend ostream &operator<<(ostream &os, const Vozac &vozac) {
        os <<vozac.name <<endl;
        os <<vozac.age <<endl;
        os << vozac.races<<endl;
          if(vozac.veteran ==1){
              os<<"VETERAN"<<endl;
          }
        return os;
    }
    bool operator==(const Vozac& other) const {
        return this->zarabotuvacka() == other.zarabotuvacka();
    }
    virtual double zarabotuvacka() const = 0;
    virtual double danok() = 0;
};


class Avtomobilist : public Vozac{
private:
    float price;
public:
    Avtomobilist( const char *name="",int age =0,int races = 0,bool veteran = false,float price = 0.0) : Vozac(name,age,races,veteran){
        this->price = price;
    }
    double zarabotuvacka() const{
        return  price/5.0;
    }
    double danok() override{
        double tax = 0;
        if(races > 10){
            tax = zarabotuvacka() * 0.15;
            return tax;
        }
        tax = zarabotuvacka() * 0.1;
        return tax;
    }

};
class Motociklist : public  Vozac{
private:
    int moknost;
public:

    Motociklist(const char *name="",int age =0,int races = 0,bool veteran = false,int moknost = 0) : Vozac(name,age,races,veteran){
        this->moknost = moknost;
    }
    double zarabotuvacka()const  {
        return moknost * 20;
    }
    double danok() override{
        double tax = 0;
        if(veteran == 1){
            tax = zarabotuvacka() * 0.25;
            return tax;
        }
        tax = zarabotuvacka() * 0.20;
        return tax;
    }
};
int soIstaZarabotuvachka(Vozac** vozaci, int n, Vozac* proslVozac){
        int counter = 0;
    for (int i = 0; i < n; ++i) {
        if(vozaci[i]->zarabotuvacka() == proslVozac->zarabotuvacka()){
            counter++;
        }
    }
    return counter;
}
int main() {
    int n, x;
    cin >> n >> x;
    Vozac **v = new Vozac*[n];
    char ime[100];
    int vozrast;
    int trki;
    bool vet;
    for(int i = 0; i < n; ++i) {
        cin >> ime >> vozrast >> trki >> vet;
        if(i < x) {
            float cena_avto;
            cin >> cena_avto;
            v[i] = new Avtomobilist(ime, vozrast, trki, vet, cena_avto);
        } else {
            int mokjnost;
            cin >> mokjnost;
            v[i] = new Motociklist(ime, vozrast, trki, vet, mokjnost);
        }
    }
    cout << "=== DANOK ===" << endl;
    for(int i = 0; i < n; ++i) {
        cout << *v[i];
        cout << v[i]->danok() << endl;
    }
    cin >> ime >> vozrast >> trki >> vet;
    int mokjnost;
    cin >> mokjnost;
    Vozac *vx = new Motociklist(ime, vozrast, trki, vet, mokjnost);
    cout << "=== VOZAC X ===" << endl;
    cout << *vx;
    cout << "=== SO ISTA ZARABOTUVACKA KAKO VOZAC X ===" << endl;
    cout << soIstaZarabotuvachka(v, n, vx);
    for(int i = 0; i < n; ++i) {
        delete v[i];
    }
    delete [] v;
    delete vx;
    return 0;
}
