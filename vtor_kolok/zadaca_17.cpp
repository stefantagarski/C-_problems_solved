//
// Created by ACER on 5/31/2023.
//
#include <iostream>
#include <cstring>
using namespace std;

class FudbalskaEkipa{
protected:
    char name[101];
    int goals[10];
public:
    FudbalskaEkipa(const char *name="",const int goals[10] = nullptr){
        strcpy(this->name, name);
        for (int i = 0; i < 10; ++i) {
            this->goals[i]  = goals[i];
        }
    }
    virtual int uspeh() const = 0;

   FudbalskaEkipa &operator+=(int gol){
       for (int i = 0; i < 9; ++i) {
           goals[i] = goals[i+1];
       }
       goals[9] = gol;
       return *this;
   }

    bool operator>(const FudbalskaEkipa &rhs) const {
        return uspeh() < rhs.uspeh();
    }
    virtual const char *getName() const = 0;
    friend ostream &operator<<(ostream &os, const FudbalskaEkipa &ekipa) {
        os << ekipa.getName() << endl;
        os<<ekipa.name<<endl;
        os<<ekipa.uspeh()<<endl;
        return os;
    }
};
class Klub: public FudbalskaEkipa{
private:
    char club[101];
    int titles;
public:
    Klub(const char *name="",const int goals[10] = nullptr,const char*club = "",int titles = 0) : FudbalskaEkipa(name,goals){
        strcpy(this->club,club);
        this->titles = titles;
    }
    int uspeh() const override{
        int sum = 0;
        for (int i = 0; i < 10; ++i) {
            sum += goals[i];
        }
        return sum * 3 + (titles * 1000);
    }
    const char *getName() const override{
        return  club;
    }

};
class Reprezentacija : public FudbalskaEkipa{
private:
    char country[101];
    int games;
public:
    Reprezentacija(const char *name="",const int goals[10] = nullptr,const char* country = "",int games = 0) : FudbalskaEkipa(name,goals){
        strcpy(this->country,country);
        this->games = games;
    }
    const char *getName() const override{
        return country;
    }
    int uspeh() const override{
        int sum = 0;
        for (int i = 0; i < 10; ++i) {
            sum += goals[i];
        }
        return sum * 3 + (50 *games);
    }

};

void najdobarTrener(FudbalskaEkipa **ekipi,int n){
    FudbalskaEkipa *max = ekipi[0];
    for (int i = 1; i < n; ++i) {
        if(ekipi[i]->uspeh() > max->uspeh()){
           max = ekipi[i];
        }
    }
    cout<<*max;
}

int main() {
    int n;
    cin >> n;
    FudbalskaEkipa **ekipi = new FudbalskaEkipa*[n];
    char coach[100];
    int goals[10];
    char x[100];
    int tg;
    for (int i = 0; i < n; ++i) {
        int type;
        cin >> type;
        cin.getline(coach, 100);
        cin.getline(coach, 100);
        for (int j = 0; j < 10; ++j) {
            cin >> goals[j];
        }
        cin.getline(x, 100);
        cin.getline(x, 100);
        cin >> tg;
        if (type == 0) {
            ekipi[i] = new Klub(coach, goals, x, tg);
        } else if (type == 1) {
            ekipi[i] = new Reprezentacija(coach, goals, x, tg);
        }
    }
    cout << "===== SITE EKIPI =====" << endl;
    for (int i = 0; i < n; ++i) {
        cout << *ekipi[i];
    }
    cout << "===== DODADI GOLOVI =====" << endl;
    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p;
        cout << "dodavam golovi: " << p << endl;
        *ekipi[i] += p;
    }
    cout << "===== SITE EKIPI =====" << endl;
    for (int i = 0; i < n; ++i) {
        cout << *ekipi[i];
    }
    cout << "===== NAJDOBAR TRENER =====" << endl;
    najdobarTrener(ekipi, n);
    for (int i = 0; i < n; ++i) {
        delete ekipi[i];
    }
    delete [] ekipi;
    return 0;
}