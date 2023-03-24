#include<iostream>
#include<cstring>
using namespace std;
class Country{
private:
    char name[101];
    char capital[101];
    double area;
    double population;
public:
    Country(){
        strcpy(name," ");
        strcpy(capital," ");
        area = 0.0;
        population = 0.0;
    }
    Country(char *n,char *c,double ar,double pop){
        strcpy(name,n);
        strcpy(capital,c);
        area = ar;
        population = pop;
    }
    ~Country(){}

    void setName(char _number[100]) {
        strcpy(name,_number);
    }
    void setCapital(char _capital[100]){
        strcpy(capital,_capital);
    }
    void setArea(double _area) {
        area = _area;
    }
    void setPopulation (double _population){
        population = _population;
    }

    char *getName() {
        return name;
    }

    char *getCapital(){
        return capital;
    }
    double getArea(){
        return area;
    }
    double getPopulation(){
        return population;
    }

    void display() {
        cout << "Country: " << name << endl;
        cout << "Capital: " << capital << endl;
        cout << "Area: " << area << endl;
        cout << "Population: "<<population<<endl;
    }
void print(){
    cout << "Country: " << name << endl;
    cout << "Capital: " << capital << endl;
    cout << "Area: " << area << endl;
    cout << "Population: "<<population<<endl;
    }
};
void sortCountries(Country *countries,int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n-1-i; ++j) {
            if(countries[j].getArea() > countries[j+1].getArea()){
                Country temp = countries[j];
                countries[j] = countries[j+1];
                countries[j+1] = temp;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        countries[i].print();
    }

}

int main() {
    int n;
    cin >> n;
    Country countries[100];

    char name[100];
    char capital[100];
    double area;
    double population;

    for (int i = 0; i < n-1; i++)  {
        cin>>name;
        cin >> capital;
        cin >> area;
        cin>>population;
        // testing constructor with arguments
        countries[i] = Country(name, capital, area, population);
    }
    // testing set methods and display for last element
    cin>>name;
    cin >> capital;
    cin >> area;
    cin>>population;
    countries[n-1].setName(name);
    countries[n-1].setCapital(capital);
    countries[n-1].setArea(area);
    countries[n-1].setPopulation(population);

    cout<<"-->Testing set methods and display()"<<endl;
    countries[n-1].display();
    cout<<endl;
    cout<<"-->Testing sortCountries()"<<endl;
    sortCountries(countries,n);
    return 0;
}