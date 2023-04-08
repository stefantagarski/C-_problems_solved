#include<iostream>
#include <cstring>

using namespace std;
enum Tip {
    LINUX,UNIX,WINDOWS
};
class OperativenSistem {
private:
    char *name;
    float version;
    Tip tip;
    float capacity;
public:
    OperativenSistem(){
        name = nullptr;
        version = 0.0;
        tip = {};
        capacity = 0.0;
    }
    OperativenSistem(const char *name, float version, Tip tip, float capacity){
        this->name = new char[strlen(name)+1];
        strcpy(this->name,name);
        this->version = version;
        this->tip = tip;
        this->capacity = capacity;
    }
    OperativenSistem(const OperativenSistem &os){
        this->name = new char[strlen(os.name)+1];
        strcpy(this->name,os.name);
        this->version = os.version;
        this->tip = os.tip;
        this->capacity = os.capacity;
    }
    ~OperativenSistem(){
        delete [] name;
    }
    OperativenSistem operator=(const OperativenSistem &os) {
        if (this != &os) {
            delete [] name;
            this->name = new char[strlen(os.name) + 1];
            strcpy(this->name, os.name);
            this->version = os.version;
            this->tip = os.tip;
            this->capacity = os.capacity;
        }
        return *this;
    }
    void pecati() const {
        cout <<"Ime: "<< name << " Verzija: " << version << " Tip: "<<tip;
        cout <<" Golemina:"<< capacity << "GB" << endl;
    }

    bool ednakviSe(const OperativenSistem &os) {
        return (strcmp(name,os.name) == 0 && (version == os.version) && (tip == os.tip)
                && (capacity == os.capacity));
    }
    int SporediVerzija(const OperativenSistem &os) const{
        if(version == os.version){
            return 0;
        }else if(os.version > version){
            return -1;
        }else{
            return 1;
        }
    }
    bool istaFamilija(const OperativenSistem &sporedba){
        return ((strcmp(name,sporedba.name)==0) && (tip == sporedba.tip));
    }
};
class Repozitorum {
private:
    char name[20];
    OperativenSistem *niza;
    int n;
public:
    Repozitorum(const char *name) {
        strcpy(this->name, name);
        niza = nullptr;
        n = 0;
    }

    ~Repozitorum() {
        delete[] niza;
    }

    void pecatiOperativniSistemi() {
        cout << "Repozitorium: " << name << endl;
        for (int i = 0; i < n; ++i) {
            niza[i].pecati();
        }
    }

    void izbrishi(const OperativenSistem &operativenSistem)
    {
        int flag=0;

        for(int i=0;i<n;i++)
        {
            if(niza[i].ednakviSe(operativenSistem))
            {
                flag=1;
                break;
            }
        }
        if(flag)
        {
            return;
        }
        OperativenSistem *tmp=new OperativenSistem[n-1];
        int j=0;
        for(int i=0;i<n;i++)
        {
            if(!niza[i].ednakviSe(operativenSistem))
            {
                tmp[j]=niza[i];
                j++;
            }
        }
        delete[]niza;
        niza=tmp;
        n--;

    }

    void dodadi(const OperativenSistem &nov){
        for(int i=0;i<n;i++){
            if(niza[i].istaFamilija(nov))
            {
                if(niza[i].SporediVerzija(nov)==-1)
                {
                    niza[i]=nov;
                    return;
                }
            }
        }
        OperativenSistem *tmp=new OperativenSistem[n+1];
        for(int i=0;i<n;i++)
        {
            tmp[i]=niza[i];
        }
        tmp[n]=nov;
        n++;
        delete[]niza;
        niza=tmp;
    }

};
int main() {
    char repoName[20];
    cin>>repoName;
    Repozitorum repozitorium=Repozitorum(repoName);
    int brojOperativniSistemi = 0;
    cin>>brojOperativniSistemi;
    char ime[20];
    float verzija;
    int tip;
    float golemina;
    for (int i = 0; i<brojOperativniSistemi; i++){
        cin>>ime;
        cin>>verzija;
        cin>>tip;
        cin>>golemina;
        OperativenSistem os = OperativenSistem(ime, verzija, (Tip)tip, golemina);
        repozitorium.dodadi(os);
    }

    repozitorium.pecatiOperativniSistemi();
    cin>>ime;
    cin>>verzija;
    cin>>tip;
    cin>>golemina;
    OperativenSistem os = OperativenSistem(ime, verzija, (Tip)tip, golemina);
    cout<<"=====Brishenje na operativen sistem====="<<endl;
    repozitorium.izbrishi(os);
    repozitorium.pecatiOperativniSistemi();
    return 0;
}
