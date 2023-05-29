//
// Created by ACER on 5/28/2023.
//
#include <iostream>
#include <cstring>


using namespace std;
class NegativnaVrednost{
public:
    void showMessage(){
        cout<<"Oglasot ima nevalidna vrednost za cenata i nema da bide evidentiran!"<<endl;
    }
};
class Oglas {
protected:
    char title[51];
    char category[31];
    char description[101];
    double price;
public:
    Oglas(const char *title = "",const char *category="",const char* description = "",double price = 0.0){
        strcpy(this->title,title);
        strcpy(this->category,category);
        strcpy(this->description,description);
        this->price = price;
    }

    bool operator>(const Oglas &rhs) const {
        return price > rhs.price;
    }

    friend ostream &operator<<(ostream &os, const Oglas &oglas) {
        os <<oglas.title<<endl;
        os<<oglas.description<<endl;
        os<<oglas.price<<" evra"<<endl;
        return os;
    }

    double getPrice() const {
        return price;
    }

    const char *getCategory() const {
        return category;
    }
};
class Oglasnik {
private:
    char name[21];
    Oglas *oglasi;
    int n;
public:
    Oglasnik(const char *name = ""){
        strcpy(this->name,name);
        n = 0;
        oglasi = new Oglas[0];
    }
    Oglasnik(const Oglasnik &o){
        strcpy(this->name,o.name);
        this->n = o.n;
        this->oglasi = new Oglas[n];
        for (int i = 0; i < n; ++i) {
            oglasi[i] = o.oglasi[i];
        }
    }
    Oglasnik &operator=(const Oglasnik &o){
        if(this != &o){
            strcpy(this->name,o.name);
            this->n = o.n;
            delete [] oglasi;
            this->oglasi = new Oglas[n];
            for (int i = 0; i < n; ++i) {
                oglasi[i] = o.oglasi[i];
            }
        }
        return *this;
    }
    ~Oglasnik() {
        delete [] oglasi;
    }

    friend ostream &operator<<(ostream &os, const Oglasnik &oglasnik) {
        os<< oglasnik.name<<endl;
        for (int i = 0; i < oglasnik.n; ++i) {
            os<<oglasnik.oglasi[i]<<endl;
        }
        return os;
    }
    void operator+=(const Oglas &oglas){
        if(oglas.getPrice() < 0){
                throw NegativnaVrednost();
        }
        Oglas *tmp = new Oglas[n+1];
        for (int i = 0; i < n; ++i) {
            tmp[i] = oglasi[i];
        }
        tmp[n++] = oglas;
        delete [] oglasi;
        oglasi = tmp;
    }
    void oglasiOdKategorija(const char *k){
        for (int i = 0; i < n; ++i) {
            if(strcmp(oglasi[i].getCategory(),k) == 0){
                cout<<oglasi[i]<<endl;
            }
        }
    }
    void najniskaCena(){
        int minInx =0;
        for (int i = 0; i < n; ++i) {
            if(oglasi[i].getPrice() < oglasi[minInx].getPrice()){
                minInx = i;
            }
        }
        cout<<oglasi[minInx]<<endl;
    }
};


int main(){

    char naslov[50];
    char kategorija[30];
    char opis[100];
    float cena;
    char naziv[50];
    char k[30];
    int n;

    int tip;
    cin>>tip;

    if (tip==1){
        cout<<"-----Test Oglas & operator <<-----" <<endl;
        cin.get();
        cin.getline(naslov,49);
        cin.getline(kategorija,29);
        cin.getline(opis,99);
        cin>>cena;
        Oglas o(naslov, kategorija, opis, cena);
        cout<<o;
    }
    else if (tip==2){
        cout<<"-----Test Oglas & operator > -----" <<endl;
        cin.get();
        cin.getline(naslov,49);
        cin.getline(kategorija,29);
        cin.getline(opis,99);
        cin>>cena;
        Oglas o1(naslov, kategorija, opis, cena);
        cin.get();
        cin.getline(naslov,49);
        cin.getline(kategorija,29);
        cin.getline(opis,99);
        cin>>cena;
        Oglas o2(naslov, kategorija, opis, cena);
        if (o1>o2) cout<<"Prviot oglas e poskap."<<endl;
        else cout<<"Prviot oglas ne e poskap."<<endl;
    }
    else if (tip==3){
        cout<<"-----Test Oglasnik, operator +=, operator << -----" <<endl ;
        cin.get();
        cin.getline(naziv,49);
        cin>>n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++){
            cin.get();
            cin.getline(naslov,49);
            cin.getline(kategorija,29);
            cin.getline(opis,99);
            cin>>cena;
            Oglas o(naslov, kategorija, opis, cena);
           try{
               ogl+=o;
           } catch(NegativnaVrednost e) {
               e.showMessage();
           }
        }
        cout<<ogl;
    }
    else if (tip==4){
        cout<<"-----Test oglasOdKategorija -----" <<endl ;
        cin.get();
        cin.getline(naziv,49);
        cin>>n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++){
            cin.get();
            cin.getline(naslov,49);
            cin.getline(kategorija,29);
            cin.getline(opis,99);
            cin>>cena;
            Oglas o(naslov, kategorija, opis, cena);
            try{
                ogl+=o;
            } catch(NegativnaVrednost e) {
                e.showMessage();
            }
        }
        cin.get();
        cin.getline(k,29);
        cout<<"Oglasi od kategorijata: " <<k<<endl;
        ogl.oglasiOdKategorija(k);

    }
    else if (tip==5){
        cout<<"-----Test Exception -----" <<endl ;
        cin.get();
        cin.getline(naziv,49);
        cin>>n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++){
            cin.get();
            cin.getline(naslov,49);
            cin.getline(kategorija,29);
            cin.getline(opis,99);
            cin>>cena;
            Oglas o(naslov, kategorija, opis, cena);
            try{
                ogl+=o;
            } catch(NegativnaVrednost e) {
                e.showMessage();
            }
        }
        cout<<ogl;

    }
    else if (tip==6){
        cout<<"-----Test najniskaCena -----" <<endl ;
        cin.get();
        cin.getline(naziv,49);
        cin>>n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++){
            cin.get();
            cin.getline(naslov,49);
            cin.getline(kategorija,29);
            cin.getline(opis,99);
            cin>>cena;
            Oglas o(naslov, kategorija, opis, cena);
            try{
                ogl+=o;
            } catch(NegativnaVrednost e) {
                e.showMessage();
            }
        }
        cout<<"Oglas so najniska cena:"<<endl;
        ogl.najniskaCena();

    }
    else if (tip==7){
        cout<<"-----Test All -----" <<endl ;
        cin.get();
        cin.getline(naziv,49);
        cin>>n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++){
            cin.get();
            cin.getline(naslov,49);
            cin.getline(kategorija,29);
            cin.getline(opis,99);
            cin>>cena;
            Oglas o(naslov, kategorija, opis, cena);
            try{
                ogl+=o;
            } catch(NegativnaVrednost e) {
                e.showMessage();
            }
        }
        cout<<ogl;


        cin.get();
        cin.get();
        cin.getline(k,29);
        cout<<"Oglasi od kategorijata: " <<k<<endl;
        ogl.oglasiOdKategorija(k);

        cout<<"Oglas so najniska cena:"<<endl;
        ogl.najniskaCena();

    }

    return 0;
}
