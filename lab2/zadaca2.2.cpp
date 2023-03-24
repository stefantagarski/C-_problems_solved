#include<iostream>
#include<cstring>

using namespace std;

class Programmer {
private:
    char name[100];
    char language[100];
    int salary;

public:
    Programmer (){}
    Programmer(char *n,char*l,int s){
        strcpy(name,n);
        strcpy(language,l);
        salary = s;
    }
    ~Programmer(){}
    void setName(char nn[100]){
        strcpy(name,nn);
    }
    char *getName(){
        return name;
    }
    void setProgrammingLanguage(char pl[100]){
        strcpy(language,pl);
    }
    char *getLanguage(){
        return language;
    }
    void setSalary (int ss){
        salary = ss;
    }
    int getSalary(){
        return salary;
    }

    void display (){
        cout<<"Name: "<<name<<endl;
        cout<<"Programming language: "<<language<<endl;
        cout<<"Salary: "<<salary<<endl;
    }
};
void printProgrammerWithHighestSalary(Programmer *programmers, int n,char *lang) {
    int maxSalary = 0;
    int maxIndex = 0;

    for (int i = 0; i < n; i++) {
        if (programmers[i].getSalary() > maxSalary) {
            maxSalary = programmers[i].getSalary();
            maxIndex = i;
            }
        }
        cout<<"Name: "<<programmers[maxIndex].getName()<<endl;
        cout<<"Programming language: "<<programmers[maxIndex].getLanguage()<<endl;
        cout<<"Salary: "<<programmers[maxIndex].getSalary()<<endl;
    }
// DO NOT CHANGE THE MAIN FUNCTION
int main() {
    int n;
    cin >> n;
    Programmer programmers[100];

    char name[100];
    char programmingLanguage[100];
    int salary;

    for (int i = 0; i < n-1; i++)  {
        cin>>name;
        cin>>programmingLanguage;
        cin>>salary;

        // testing constructor with arguments
        programmers[i] = Programmer(name, programmingLanguage, salary);

    }


    // testing set methods and display for last element
    cin>>name;
    cin>>programmingLanguage;
    cin>>salary;
    programmers[n-1].setName(name);
    programmers[n-1].setProgrammingLanguage(programmingLanguage);
    programmers[n-1].setSalary(salary);

    cout<<"-->Testing set methods and display()"<<endl;
    programmers[n-1].display();
    cout<<endl;

    char lang[100];
    cin>>lang;
    cout<<"-->Testing printProgrammerWithHighestSalary() for language "<<lang<<endl;
   printProgrammerWithHighestSalary(programmers, n, lang);
    return 0;
}
