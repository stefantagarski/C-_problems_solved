#include <iostream>
#include <cstring>
using namespace std;
class Employee{
protected:
    char *name;
    int salary;
    int bonus;
    int experience;
public:
    Employee(const char *name="",int salary = 0,int bonus=0,int experience = 0){
        this-> name = new char [strlen(name)+1];
        strcpy(this->name,name);
        this->salary = salary;
        this->bonus = bonus;
        this->experience = experience;
    }
    Employee(const Employee &e){
        this-> name = new char [strlen(e.name)+1];
        strcpy(this->name,e.name);
        this->salary = e.salary;
        this->bonus = e.bonus;
        this->experience = e.experience;
    }
    Employee &operator = (const Employee &e){
        if(this != &e){
            delete [] name;
            this-> name = new char [strlen(e.name)+1];
            strcpy(this->name,e.name);
            this->salary = e.salary;
            this->bonus = e.bonus;
            this->experience = e.experience;
        }
        return *this;
    }
    ~Employee(){
        delete [] name;
    }

    int getSalary() const {
        return salary;
    }


   
    int getBonus() const {
        return bonus;
    }

   

    int getExperience() const {
        return experience;
    }

   
    virtual int getTotalSalary(){
         return getSalary()+(getBonus()*getExperience());
    }
    void print(){
        cout<<"Employee name: "<<name<<endl;
        cout<<"Salary: "<<getTotalSalary()<<endl;
        cout<<"Experience: "<<experience<<endl;
    }
};
class Manager : public Employee {
private:
    char *oddel;
    int manager_bonus;
public:
    Manager(const char *name = "", int salary = 0, int bonus = 0,int experience = 0,const char *oddel = "", int manager_bonus = 0) : Employee(name, salary, bonus, experience) {
        this->oddel = new char[strlen(oddel) + 1];
        strcpy(this->oddel, oddel);
        this->manager_bonus = manager_bonus;
    }
    Manager(Employee &e,const char *oddel = "", int manager_bonus = 0) : Employee(e) {
        this->oddel = new char[strlen(oddel) + 1];
        strcpy(this->oddel, oddel);
        this->manager_bonus = manager_bonus;
    }
    Manager(const Manager &m) : Employee(m) {
        this->oddel = new char[strlen(m.oddel) + 1];
        strcpy(this->oddel, m.oddel);
        this->manager_bonus = m.manager_bonus;
    }

    Manager &operator=(const Manager &m) {
        if (this != &m){
            delete [] name;
            this-> name = new char [strlen(m.name)+1];
            strcpy(this->name,m.name);
            this->salary = m.salary;
            this->bonus = m.bonus;
            this->experience = m.experience;
            delete [] oddel;
            this->oddel = new char[strlen(m.oddel) + 1];
            strcpy(this->oddel, m.oddel);
            this->manager_bonus = m.manager_bonus;
        }
        return *this;
    }
    ~Manager(){
        delete [] oddel;
    }

    int getManagerBonus() const {
        return manager_bonus;
    }

    void setManagerBonus(int managerBonus) {
        manager_bonus = managerBonus;
    }
    int getTotalManagerBonus(){
        return getBonus()+getManagerBonus();
    }
    int getTotalSalary(){
        return getSalary() + (getTotalManagerBonus()*getExperience());
    }
    void print(){
        cout<<"Manager name: "<<name<<endl;
        cout<<"Department: "<<oddel<<endl;
        cout<<"Salary: "<<getTotalSalary()<<endl;
        cout<<"Experience: "<<experience<<endl;
    }
};


// YOUR CODE STARTS HERE


//DO NOT EDIT THE MAIN FUNCTION

int main() {

    char name[20];
    int salary;
    int bonus;
    int experience;
    char department[50];
    int managerBonus;

    Employee * employees = new Employee[5];
    Manager * managers = new Manager[5];
    int n;
    cin >> n;

    if (n == 1) {

        cout << "EMPLOYEES:" << endl;
        cout << "=====================================" << endl;
        for (int i = 0; i < 5; ++i) {
            cin >> name >> salary >> bonus >> experience;
            employees[i] = Employee(name, salary, bonus, experience);
            employees[i].print();
            cout<<endl;
        }
    }
    else if (n == 2) {

        for (int i=0; i < 5; ++i){
            cin >> name >> salary >> bonus >> experience;
            cin >> department >> managerBonus;
            employees[i] = Employee(name, salary, bonus, experience);
            managers[i] = Manager(employees[i], department, managerBonus);
        }

        cout << "EMPLOYEES:" << endl;
        cout << "=====================================" << endl;
        for (int i=0; i < 5; ++i) {
            employees[i].print();
            cout<<endl;
        }


        cout << "MANAGERS:" << endl;
        cout << "=====================================" << endl;
        for (int i=0; i < 5; ++i) {
            managers[i].print();
            cout<<endl;
        }

    }
    else if (n == 3) {

        for (int i=0; i < 5; ++i){
            cin >> name >> salary >> bonus >> experience;
            cin >> department >> managerBonus;
            managers[i] = Manager(name, salary, bonus, experience, department, managerBonus);
        }
        cout << "MANAGERS:" << endl;
        cout << "=====================================" << endl;
        for (int i=0; i < 5; ++i) {
            managers[i].print();
            cout<<endl;
        }

    }

    delete [] employees;
    delete [] managers;
}


