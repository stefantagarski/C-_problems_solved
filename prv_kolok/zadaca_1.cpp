#include <iostream>
#include <cstring>

using namespace std;

enum tip { POP, RAP, ROCK };

class Pesna {
private:
    char* ime;
    int minuti;
    tip pesnaTip;

public:
    Pesna(char* ime = "", int minuti = 0, tip pesnaTip = {}) {
        this->ime = new char[strlen(ime) + 1];
        strcpy(this->ime, ime);
        this->minuti = minuti;
        this->pesnaTip = pesnaTip;
    }

    Pesna(const Pesna& other) {
        this->ime = new char[strlen(other.ime) + 1];
        strcpy(this->ime, other.ime);
        this->minuti = other.minuti;
        this->pesnaTip = other.pesnaTip;
    }

    ~Pesna() {
        delete[] ime;
    }

    Pesna & operator=(const Pesna& other) {
        if (this != &other) {
            delete[] ime;
            this->ime = new char[strlen(other.ime) + 1];
            strcpy(this->ime, other.ime);
            this->minuti = other.minuti;
            this->pesnaTip = other.pesnaTip;
        }
        return *this;
    }

    void pecati() {
        cout << "" << ime << " - " << minuti << "min" << endl;
    }

    tip getTip() const {
        return pesnaTip;
    }

    int getMinuti() const {
        return minuti;
    }
};

class CD {
private:
    Pesna pesni[10];
    int brojPesni;
    int maksimalnaDolzina;

public:
    CD(int maksimalnaDolzina = 0,int brojPesni = 0) {
        this->maksimalnaDolzina = maksimalnaDolzina;
        this->brojPesni = brojPesni;
    }
    CD(const CD &cd){
        this->maksimalnaDolzina = cd.maksimalnaDolzina;
        this->brojPesni = cd.brojPesni;
        for (int i = 0; i < brojPesni; ++i) {
            this->pesni[i] = cd.pesni[i];
        }
    }

    void dodadiPesna(Pesna &p)  {
        if (brojPesni < 10 && p.getMinuti() <= maksimalnaDolzina - getDolzinaPesni()) {
            pesni[brojPesni++] = p;
        }
    }

    void pecatiPesniPoTip(tip t) {
        for (int i = 0; i < brojPesni; i++) {
            if (pesni[i].getTip() == t) {
                pesni[i].pecati();
            }
        }
    }

    Pesna & getPesna(int index) {
        return pesni[index];
    }

    int getBroj() const {
        return brojPesni;
    }

    int getDolzinaPesni() const {
        int dolzina = 0;
        for (int i = 0; i < brojPesni; i++) {
            dolzina += pesni[i].getMinuti();
        }
        return dolzina;
    }
};
int main() {
    // se testira zadacata modularno
    int testCase;
    cin >> testCase;

    int n, minuti, kojtip;
    char ime[50];

    if(testCase == 1) {
        cout << "===== Testiranje na klasata Pesna ======" << endl;
        cin >> ime;
        cin >> minuti;
        cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
        Pesna p(ime,minuti,(tip)kojtip);
        p.pecati();
    } else if(testCase == 2) {
        cout << "===== Testiranje na klasata CD ======" << endl;
        CD omileno(20);
        cin>>n;
        for (int i=0;i<n;i++){
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime,minuti,(tip)kojtip);
            omileno.dodadiPesna(p);
        }
        for (int i=0; i<n; i++)
            (omileno.getPesna(i)).pecati();
    }
    else if(testCase == 3) {
        cout << "===== Testiranje na metodot dodadiPesna() od klasata CD ======" << endl;
        CD omileno(20);
        cin>>n;
        for (int i=0;i<n;i++){
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime,minuti,(tip)kojtip);
            omileno.dodadiPesna(p);
        }
        for (int i=0; i<omileno.getBroj(); i++)
            (omileno.getPesna(i)).pecati();
    }
    else if(testCase == 4) {
        cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======" << endl;
        CD omileno(20);
        cin>>n;
        for (int i=0;i<n;i++){
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime,minuti,(tip)kojtip);
            omileno.dodadiPesna(p);
        }
        cin>>kojtip;
        omileno.pecatiPesniPoTip((tip)kojtip);

    }
    else if(testCase == 5) {
        cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======" << endl;
        CD omileno(20);
        cin>>n;
        for (int i=0;i<n;i++){
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime,minuti,(tip)kojtip);
            omileno.dodadiPesna(p);
        }
        cin>>kojtip;
        omileno.pecatiPesniPoTip((tip)kojtip);

    }

    return 0;
}