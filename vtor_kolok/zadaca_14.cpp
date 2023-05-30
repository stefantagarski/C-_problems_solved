//
// Created by ACER on 5/30/2023.
//
#include<iostream>
#include<cstring>

using namespace std;

class SMS {
protected:
    double base_price;
    char num[20];
    const static double tax;
public:
    SMS(const char *num ="",double base_price = 0.0)  {
        this->base_price = base_price;
        strcpy(this->num,num);
    }
    virtual double SMS_cena() const = 0;
    friend ostream &operator<<(ostream &os, const SMS &sms)  {
        os <<"Tel: "<<sms.num<<" - cena: "<<sms.SMS_cena()<<"den."<<endl;
        return os;
    }
};
const double SMS::tax = 0.18;

class RegularSMS : public SMS{
private:
    char text[1000];
    bool roam;
    static double tax_regural;
public:
    RegularSMS(const char *num ="",double base_price = 0.0,const char *text="",bool roam = false) : SMS(num,base_price){
        strcpy(this->text,text);
        this->roam = roam;
    }

    double SMS_cena() const override{

        int numMessages;
        if (strlen(text) <= 160) {
            numMessages = 1;
        } else {
            numMessages = (strlen(text) + 159) / 160;
        }
        double percentageIncrease = (roam) ? tax_regural : tax;
        return base_price * (1 + percentageIncrease) * numMessages;
    }
    static void set_rProcent(int i){
        RegularSMS::tax_regural = (double) i/100;
    }
};
double RegularSMS::tax_regural = 3.0;
class SpecialSMS : public SMS {
private:
    bool hum;
    static double tax_special;
public:
    SpecialSMS(const char *num ="",double base_price = 0.0,bool hum = false) : SMS(num,base_price){
        this-> hum = hum;
    }
    double SMS_cena() const override{
        if(hum == 0){
            return base_price *(1+tax_special);
        }
        else{
            return base_price;
        }
    }
    static void set_sProcent(int i){
       SpecialSMS::tax_special = (double) i /100;
    }
};
double SpecialSMS::tax_special = 1.5;

void vkupno_SMS(SMS **poraka,int n){
    int regural = 0, special = 0;
    double total_regural = 0.0 , total_special = 0.0;
    for (int i = 0; i < n; ++i) {
        if(dynamic_cast<RegularSMS*>(poraka[i])){
            regural++;
            total_regural += poraka[i]->SMS_cena();
        }
        if(dynamic_cast<SpecialSMS*>(poraka[i])){
            special++;
            total_special += poraka[i]->SMS_cena();
        }
    }
    cout<<"Vkupno ima "<<regural<<" regularni SMS poraki i nivnata cena e: "<<total_regural<<endl;
    cout<<"Vkupno ima "<<special<<" specijalni SMS poraki i nivnata cena e: "<<total_special<<endl;

}
int main(){

    char tel[20], msg[1000];
    float cena;
    float price;
    int p;
    bool roam, hum;
    SMS **sms;
    int n;
    int tip;

    int testCase;
    cin >> testCase;

    if (testCase == 1){
        cout << "====== Testing RegularSMS class ======" << endl;
        cin >> n;
        sms = new SMS *[n];

        for (int i = 0; i < n; i++){
            cin >> tel;
            cin >> cena;
            cin.get();
            cin.getline(msg, 1000);
            cin >> roam;
            cout << "CONSTRUCTOR" << endl;
            sms[i] = new RegularSMS(tel, cena, msg, roam);
            cout << "OPERATOR <<" << endl;
            cout << *sms[i];
        }
        for (int i = 0; i<n; i++) delete sms[i];
        delete[] sms;
    }
    if (testCase == 2){
        cout << "====== Testing SpecialSMS class ======" << endl;
        cin >> n;
        sms = new SMS *[n];

        for (int i = 0; i < n; i++){
            cin >> tel;
            cin >> cena;
            cin >> hum;
            cout << "CONSTRUCTOR" << endl;
            sms[i] = new SpecialSMS(tel, cena, hum);
            cout << "OPERATOR <<" << endl;
            cout << *sms[i];
        }
        for (int i = 0; i<n; i++) delete sms[i];
        delete[] sms;
    }
    if (testCase == 3){
        cout << "====== Testing method vkupno_SMS() ======" << endl;
        cin >> n;
        sms = new SMS *[n];

        for (int i = 0; i<n; i++){

            cin >> tip;
            cin >> tel;
            cin >> cena;
            if (tip == 1) {

                cin.get();
                cin.getline(msg, 1000);
                cin >> roam;

                sms[i] = new RegularSMS(tel, cena, msg, roam);

            }
            else {
                cin >> hum;

                sms[i] = new SpecialSMS(tel, cena, hum);
            }
        }

        vkupno_SMS(sms, n);
        for (int i = 0; i<n; i++) delete sms[i];
        delete[] sms;
    }
    if (testCase == 4){
        cout << "====== Testing RegularSMS class with a changed percentage======" << endl;
        SMS *sms1, *sms2;
        cin >> tel;
        cin >> cena;
        cin.get();
        cin.getline(msg, 1000);
        cin >> roam;
        sms1 = new RegularSMS(tel, cena, msg, roam);
        cout << *sms1;

        cin >> tel;
        cin >> cena;
        cin.get();
        cin.getline(msg, 1000);
        cin >> roam;
        cin >> p;
        RegularSMS::set_rProcent(p);
        sms2 = new RegularSMS(tel, cena, msg, roam);
        cout << *sms2;

        delete sms1, sms2;
    }
    if (testCase == 5){
        cout << "====== Testing SpecialSMS class with a changed percentage======" << endl;
        SMS *sms1, *sms2;
        cin >> tel;
        cin >> cena;
        cin >> hum;
        sms1 = new SpecialSMS(tel, cena, hum);
        cout << *sms1;

        cin >> tel;
        cin >> cena;
        cin >> hum;
        cin >> p;
        SpecialSMS::set_sProcent(p);
        sms2 = new SpecialSMS(tel, cena, hum);
        cout << *sms2;

        delete sms1, sms2;
    }

    return 0;
}
