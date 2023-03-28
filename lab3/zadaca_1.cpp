#include <iostream>
#include<cstring>
using namespace std;

//YOUR CODE HERE
class MobilePhone{
    private:
    char model[20];
    int nummodel;
    int year;
public:
    MobilePhone(){
        strcpy(model," ");
        nummodel = 0;
        year = 0;
    }
    MobilePhone(char *m, int no, int y){
        strcpy(model,m);
        nummodel = no;
        year=y;

    }
    MobilePhone(const MobilePhone &mp){
        strcpy(model,mp.model);
        nummodel=mp.nummodel;
        year = mp.year;
    }
    ~MobilePhone(){}

    void print(){
        cout<<model<<" "<<nummodel<<" release year: "<<year<<endl;
    }
};

class Owner{
private:
    char name[20];
    char surname[20];
    MobilePhone mobile;
public:
    Owner(){
        strcpy(name," ");
        strcpy(surname, " ");


    }
    Owner(char *n, char *s, MobilePhone mp){
        strcpy(name,n);
        strcpy(surname,s);
        mobile = mp;


    }
    Owner(const Owner &o) {
        strcpy(name, o.name);
        strcpy(surname, o.surname);
        mobile = o.mobile;
    }
    ~Owner(){}

    void print(){
        cout<<name<<" "<<surname<<" has a mobile phone:"<<endl;
        mobile.print();
    }
};


//DO NOT CHANGE THE MAIN FUNCTION
int main() {
    char model[20];
    int modelNumber;
    int year;
    char name[20];
    char surname[20];

    int testCase;

    cin>>testCase;

    cin>>model;
    cin>>modelNumber;
    cin>>year;
    cin>>name;
    cin>>surname;

    if(testCase==1){
        MobilePhone mobilePhone(model,modelNumber,year);

        Owner owner(name,surname,mobilePhone);
        owner.print();
    }
    if(testCase==2){
        MobilePhone mobilePhone(MobilePhone(model,modelNumber,year));

        Owner owner(name,surname,mobilePhone);
        owner.print();
    }

}
