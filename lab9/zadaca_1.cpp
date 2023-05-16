#include <iostream>
#include <cstring>

using namespace std;
class Employee{
    protected:
    char name[20];
    int age;
    public:
    Employee(char *name="",int age=0){
        strcpy(this->name,name);
        this->age = age;
    }
    virtual void displayInfo() = 0;
};
class Payable{
protected:
    float salary;
public:
    Payable(float salary=0.0){
        this->salary = salary;
    }
    virtual float calculateSalary() = 0;
};
class Developer : public Employee,public  Payable
{
private:
    char language[20];
public:
    Developer(char *name="",int age = 0,float salary=0.0,char * language="") :Employee(name,age) , Payable(salary){
        strcpy(this->language,language);
    }
    float calculateSalary(){
       float tax = salary *0.1;
       float net;
       net = salary - tax;
        return net;

    }
    void displayInfo(){
        cout<<"-- Developer Information --"<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Salary: $"<<calculateSalary()<<endl;
        cout<<"Programming Language: "<<language<<endl;
    }
};
class Manager : public Employee,public  Payable
{
private:
  int oddel;
public:
    Manager(char *name="",int age = 0,float salary=0.0,int oddel =0) :Employee(name,age) , Payable(salary){
        this->oddel = oddel;
    }
    float calculateSalary(){
        float bonus = 0;
        bonus = (float)(0.05*oddel) *salary;
        float  max = 0;
        max = salary + bonus;
        return max;
    }
    void displayInfo(){
        cout<<"-- Manager Information --"<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Salary: $"<<calculateSalary()<<endl;
        cout<<"Number of Departments: "<<oddel<<endl;
    }
};
double biggestSalary(Payable* payable[], int n) {
    Payable* maxSalaryEmployee = payable[0];

    for (int i = 1; i < n; i++) {
        if (payable[i]->calculateSalary() > maxSalaryEmployee->calculateSalary()) {
            maxSalaryEmployee = payable[i];
        }
    }

    return maxSalaryEmployee->calculateSalary();
}

int main()
{
    Payable* payable[5];
    Developer developers[5];
    Manager managers[5];
    int j=0, k=0;
    for(int i=0; i<5; i++)
    {
        char name[50];
        int age;
        double salary;
        cin>>name>>age>>salary;
        if(i%2==0)
        {
            char programmingLanguage[50];
            cin>>programmingLanguage;
            developers[j]=Developer(name, age, salary, programmingLanguage);
            developers[j].displayInfo();
            payable[i]=&developers[j];
            j++;
        }
        else {
            int numberOfDepartments;
            cin>>numberOfDepartments;
            managers[k]=Manager(name, age, salary, numberOfDepartments);
            managers[k].displayInfo();
            payable[i]=&managers[k];
            k++;
        }
    }
    cout<<endl<<"Biggest Salary: "<<biggestSalary(payable, 5);
    return 0;
}

