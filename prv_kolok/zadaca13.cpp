#include <iostream>
#include <cstring>

using namespace std;


class Zichara {
private:
    char *mesto;
    int cena;
public:

    Zichara() {
        this->mesto = new char[6];
        strcpy(this->mesto, "ace");
        this->cena = 0;
    }

    Zichara(char *mesto, int cena) {
        this->mesto = new char[strlen(mesto) + 1];
        strcpy(this->mesto, mesto);
        this->cena = cena;
    }

    Zichara(const Zichara &other) {
        this->mesto = new char[strlen(other.mesto) + 1];
        strcpy(this->mesto, other.mesto);
        this->cena = other.cena;
    }

    Zichara &operator=(const Zichara &other) {
        if (this != &other) {
            delete[] mesto;
            this->mesto = new char[strlen(other.mesto) + 1];
            strcpy(this->mesto, other.mesto);
            this->cena = other.cena;
        }
        return *this;
    }

    int getCena() const {
        return cena;
    }

    ~Zichara() {
        delete[] mesto;
    }
};

class PlaninarskiDom {
private:
    char name[15];
    int prices[2]; //leto i zima
    char znak;
    bool hasZichara;
    Zichara *zichara;
public:

    PlaninarskiDom() {
        this->prices[0] = 0;
        this->prices[1] = 0;
        strcpy(this->name, "");
        this->znak = 'F';
        this->hasZichara = false;
        this->zichara = nullptr;
    }

    PlaninarskiDom(char *name, const int *prices, char znak) {
        strcpy(this->name, name);
        for (int i = 0; i < 2; ++i) {
            this->prices[i] = prices[i];
        }
        this->znak = znak;
        this->hasZichara = false;
        this->zichara = nullptr;
    }

    PlaninarskiDom(const PlaninarskiDom &other) {
        strcpy(this->name, other.name);

        this->prices[0] = other.prices[0];
        this->prices[1] = other.prices[1];
        this->znak = other.znak;
        this->hasZichara = other.hasZichara;
        this->zichara = other.zichara;
    }

    PlaninarskiDom &operator=(const PlaninarskiDom &other) {
        if (this != &other) {
            //delete [] zichara;
            strcpy(this->name, other.name);
            this->prices[0] = other.prices[0];
            this->prices[1] = other.prices[1];
            this->znak = other.znak;
            this->hasZichara = other.hasZichara;
            this->zichara = other.zichara;
        }
        return *this;
    }

    PlaninarskiDom &operator--() {
        if (znak < 'F') {
            znak++;
        }
        return *this;
    }

    bool operator<=(char c) const {
        return znak >= c;
    }

    friend ostream &operator<<(ostream &os, const PlaninarskiDom &dom) {
        os << dom.name << " klasa:" << dom.znak;
        if (dom.hasZichara) {
            os << " so Zichara" << endl;
        } else {
            os << "" << endl;
        }
        return os;
    }


    void setZichara(Zichara zichara) {
        this->zichara = &zichara;
        hasZichara = true;
    }

    void presmetajDnevenPrestoj(int days, int months, int &cena) {
        cena = 0;

        if (zichara) {
            cena += zichara->getCena();
        }

        if (months < 1 || months > 12 || days < 1 || days > 31) {
            throw -1;
        }

        if ((months >= 4 && months <= 8) || months == 9 && days == 1) {
            cena += prices[0];
        } else {
            cena += prices[1];
        }
    }
};

int main() {

    PlaninarskiDom p; //креирање на нов објект од класата планинарски дом

    //во следниот дел се вчитуваат информации за планинарскиот дом
    char imePlaninarskiDom[15], mestoZichara[30], klasa;
    int ceni[12];
    int dnevnakartaZichara;
    bool daliZichara;
    cin >> imePlaninarskiDom;
    for (int i = 0; i < 2; i++) cin >> ceni[i];
    cin >> klasa;
    cin >> daliZichara;

    //во следниот дел се внесуваат информации и за жичарата ако постои
    if (daliZichara) {
        cin >> mestoZichara >> dnevnakartaZichara;
        PlaninarskiDom pom(imePlaninarskiDom, ceni, klasa);
        Zichara r(mestoZichara, dnevnakartaZichara);
        pom.setZichara(r);
        p = pom;
    } else {
        PlaninarskiDom *pok = new PlaninarskiDom(imePlaninarskiDom, ceni, klasa);
        p = *pok;
    }

    //се намалува класата на планинарскиот дом за 2
    --p;
    --p;

    int cena;
    int den, mesec;
    cin >> den >> mesec;
    try {
        p.presmetajDnevenPrestoj(den, mesec, cena); //тука се користи функцијата presmetajDnevenPrestoj
        cout << "Informacii za PlaninarskiDomot:" << endl;
        cout << p;
        if (p <= 'D')
            cout << "Planinarskiot dom za koj se vneseni informaciite ima klasa poniska ili ista so D\n";

        cout << "Cenata za " << den << "." << mesec << " e " << cena; //се печати цената за дадениот ден и месец
    }
    catch (int) {
        cout << "Mesecot ili denot e greshno vnesen!";
    }
}