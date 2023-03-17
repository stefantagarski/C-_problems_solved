#include<iostream>
#include<cstring>
using namespace std;

enum position{
    vraboten,direktor,shef
};

class Employee {
    private:
        int plata;
        position p;
        char ime[50];
    public:
        Employee(){} //default constructor
        Employee(char *i, int pl, position pp){ //constructor
            strcpy(ime,i);
            plata = pl;
            p = pp;
        }
        ~Employee(){} //destructor

        void print (){
            cout<<ime<<" "<<plata<<endl;
        }
       void set_all(char *i,int pl,int pp){
           strcpy(ime,i);
           plata = pl;
           p = (position)pp;
        }
        int get_plata(){
            return plata;
        }
};

int main (){
    Employee vraboteni[100];
    int n;
    cin>>n;
    char ime[50];
    int plata;
    int position;
    for (int i = 0; i < n; ++i) {
        cin>>ime>>plata>>position;
        vraboteni[i].set_all(ime,plata,position);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n-1-i; ++j) {
            if(vraboteni[j].get_plata() < vraboteni[j+1].get_plata()){
                Employee pom = vraboteni[j];
                vraboteni[j]= vraboteni[j+1];
                vraboteni[j+1] = pom;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        vraboteni[i].print();
    }
    return 0;
}