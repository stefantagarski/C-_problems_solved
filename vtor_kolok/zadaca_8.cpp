#include<iostream>
#include<cstring>

using namespace std;



class Koncert {
private:
    char naziv[21];
    char location[21];
    static double sez_popust;
    double price;
public:
    Koncert(const char *naziv="",const char *location ="",double price = 0.0){
        strcpy(this->naziv, naziv);
        strcpy(this->location,location);
        this->price = price;
    }
    Koncert(const Koncert &k){
        strcpy(this->naziv, k.naziv);
        strcpy(this->location,k.location);
        this->price = k.price;
    }
    static void setSezonskiPopust(double i){
        sez_popust = i;
    }
    static double getSezonskiPopust(){
        return sez_popust;
    }

    const char *getNaziv() const {
        return naziv;
    }
    virtual double cena(){
        return price * (1-sez_popust);
    }
};
double Koncert::sez_popust = 0.2;

class ElektronskiKoncert : public  Koncert{
private:
    char *DJ;
    double time;
    bool part;
public:
    ElektronskiKoncert(const char *naziv,const char *location,double price,const char *DJ = nullptr,double time = 0.0, bool part = false)
    : Koncert(naziv,location,price){
        this->DJ = new char[strlen(DJ) + 1];
        strcpy(this->DJ,DJ);
        this->time = time;
        this->part = part;
    }
    ElektronskiKoncert(const ElektronskiKoncert &e): Koncert(e){
        this->DJ = new char[strlen(DJ) + 1];
        strcpy(this->DJ,e.DJ);
        this->time = e.time;
        this->part = e.part;
    }

    ~ElektronskiKoncert(){
        delete [] DJ;
    }
    double cena() {
        double pr = Koncert::cena();
        if(time > 7.0){
            pr +=360.0;
        }
        else if(time > 5.0){
            pr +=150.0;
        }
        if(part){
            pr -=50.0;
        }else{
            pr += 100.0;
        }
        return pr;
    }
};

void najskapKoncert(Koncert**koncerti , int n){
    double max = 0.0;
    int edm = 0;

    for (int i = 0; i < n; ++i) {
        if (koncerti[i]->cena() > max) {
            max = koncerti[i]->cena();
        }

        if (dynamic_cast<ElektronskiKoncert *>(koncerti[i]) != nullptr) {
            edm++;
        }
    }
    cout<<"Najskap koncert: ";
    for (int i = 0; i < n; ++i) {
        if (max == koncerti[i]->cena()) {
            cout << koncerti[i]->getNaziv() << " " << koncerti[i]->cena() << endl;
        }
    }
    cout<<"Elektronski koncerti: "<<edm<<" od vkupno "<<n<<endl;
}

bool prebarajKoncert(Koncert **koncerti,int n , char *naziv , bool elektronski)
{
    for (int i = 0; i < n; ++i) {
        if (elektronski) {
            if (dynamic_cast<ElektronskiKoncert *>(koncerti[i])) {
                if (strcmp(koncerti[i]->getNaziv(), naziv) == 0) {
                    cout << koncerti[i]->getNaziv() << " " << koncerti[i]->cena() << endl;
                    return true;
                }

            }
        }
        else if (!elektronski){
            if(dynamic_cast<Koncert*>(koncerti[i])) {
                if (strcmp(koncerti[i]->getNaziv(), naziv) == 0) {
                    cout << koncerti[i]->getNaziv() << " " << koncerti[i]->cena() << endl;
                    return true;
                }
            }
        }
    }
    return false;
}

int main(){

    int tip,n,novaCena;
    char naziv[100], lokacija[100], imeDJ[40];
    bool dnevna;
    float cenaBilet, novPopust;
    float casovi;

    cin>>tip;
    if (tip==1){//Koncert
        cin>>naziv>>lokacija>>cenaBilet;
        Koncert k1(naziv,lokacija,cenaBilet);
        cout<<"Kreiran e koncert so naziv: "<<k1.getNaziv()<<endl;
    }
    else if (tip==2){//cena - Koncert
        cin>>naziv>>lokacija>>cenaBilet;
        Koncert k1(naziv,lokacija,cenaBilet);
        cout<<"Osnovna cena na koncertot so naziv "<<k1.getNaziv()<< " e: " <<k1.cena()<<endl;
    }
    else if (tip==3){//ElektronskiKoncert
        cin>>naziv>>lokacija>>cenaBilet>>imeDJ>>casovi>>dnevna;
        ElektronskiKoncert s(naziv,lokacija,cenaBilet,imeDJ,casovi,dnevna);
        cout<<"Kreiran e elektronski koncert so naziv "<<s.getNaziv()<<" i sezonskiPopust "<<s.getSezonskiPopust()<<endl;
    }
    else if (tip==4){//cena - ElektronskiKoncert
        cin>>naziv>>lokacija>>cenaBilet>>imeDJ>>casovi>>dnevna;
        ElektronskiKoncert s(naziv,lokacija,cenaBilet,imeDJ,casovi,dnevna);
        cout<<"Cenata na elektronskiot koncert so naziv "<<s.getNaziv()<<" e: "<<s.cena()<<endl;
    }
    else if (tip==5) {//najskapKoncert

    }
    else if (tip==6) {//prebarajKoncert
        Koncert ** koncerti = new Koncert *[5];
        int n;
        koncerti[0] = new Koncert("Area","BorisTrajkovski",350);
        koncerti[1] = new ElektronskiKoncert("TomorrowLand","Belgium",8000,"Afrojack",7.5,false);
        koncerti[2] = new ElektronskiKoncert("SeaDance","Budva",9100,"Tiesto",5,true);
        koncerti[3] = new Koncert("Superhiks","PlatoUkim",100);
        koncerti[4] = new ElektronskiKoncert("CavoParadiso","Mykonos",8800,"Guetta",3,true);
        char naziv[100];
        najskapKoncert(koncerti,5);
    }
    else if (tip==7){//prebaraj
        Koncert ** koncerti = new Koncert *[5];
        int n;
        koncerti[0] = new Koncert("Area","BorisTrajkovski",350);
        koncerti[1] = new ElektronskiKoncert("TomorrowLand","Belgium",8000,"Afrojack",7.5,false);
        koncerti[2] = new ElektronskiKoncert("SeaDance","Budva",9100,"Tiesto",5,true);
        koncerti[3] = new Koncert("Superhiks","PlatoUkim",100);
        koncerti[4] = new ElektronskiKoncert("CavoParadiso","Mykonos",8800,"Guetta",3,true);
        char naziv[100];
        bool elektronski;
        cin>>elektronski;
        if(prebarajKoncert(koncerti,5, "Area",elektronski))
            cout<<"Pronajden"<<endl;
        else cout<<"Ne e pronajden"<<endl;

        if(prebarajKoncert(koncerti,5, "Area",!elektronski))
            cout<<"Pronajden"<<endl;
        else cout<<"Ne e pronajden"<<endl;

    }
    else if (tip==8){//smeni cena
        Koncert ** koncerti = new Koncert *[5];
        int n;
        koncerti[0] = new Koncert("Area","BorisTrajkovski",350);
        koncerti[1] = new ElektronskiKoncert("TomorrowLand","Belgium",8000,"Afrojack",7.5,false);
        koncerti[2] = new ElektronskiKoncert("SeaDance","Budva",9100,"Tiesto",5,true);
        koncerti[3] = new Koncert("Superhiks","PlatoUkim",100);
        koncerti[2] -> setSezonskiPopust(0.9);
        najskapKoncert(koncerti,4);
    }

    return 0;
}
