#include <iostream>
#include <cstring>

using namespace std;
class Athlete{
protected:
    char name[20];
    int age;
public:
    Athlete(char *name="",int age=0){
        strcpy(this->name,name);
        this->age = age;
    }
    virtual void displayInfo(){
        cout<<"Athlete: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
    }
};
class Runner : public Athlete{
protected:
    double speed;
public:
    Runner(char *name="",int age=0,double speed=0.0) : Athlete(name,age){
        this->speed = speed;
    }
    void displayInfo(){
        Athlete:: displayInfo();
        cout<<"Speed: "<<speed<<" mph"<<endl;
    }

    double getSpeed() const {
        return speed;
    }

};

class Jumper : public Athlete
{
protected:
    double height;
public:
    Jumper(char *name="",int age = 0,double height = 0.0) :Athlete(name,age){
        this->height = height;
    }

    void displayInfo(){
        Athlete::displayInfo();
        cout<<"Height: "<<height<<"m"<<endl;
    }

    double getHeight() const {
        return height;
    }

};
class AllRoundAthlete : public Runner,public Jumper
{
private:
    int stamina;
public:
    AllRoundAthlete(char *name="",int age = 0,double speed =0.0,double height =0.0,int stamina =0 ) : Runner(name,age,speed) , Jumper(name,age,height){
        this->stamina = stamina;
    }


    void displayInfo(){
        Runner::displayInfo();
        cout<<"Height: "<<height<<"m"<<endl;
        cout<<"Stamina: "<<stamina<<endl;
    }

};

Athlete* findAthleteWithMaxValue(Athlete** athletes, int n){
    Athlete* maxAthlete = nullptr;
    double max = 0.0;
    for (int i = 0; i < n; ++i) {
        if(Runner *casted = dynamic_cast<Runner*>(athletes[i])){
            if(casted->getSpeed() > max){
                max = casted->getSpeed();
                maxAthlete = casted;
            }
        }
        if(Jumper *jumper = dynamic_cast<Jumper*>(athletes[i])){
            if(jumper->getHeight() > max){
                max = jumper->getHeight();
                maxAthlete  = jumper;
            }
        }

    }
    return maxAthlete;
}

int main() {
    char name[50];
    int age;
    double speed;
    double height;
    int n;
    int choice;

    cin>>choice;
    if(choice==1)
    {
        cin>>name;
        cin>>age;
        AllRoundAthlete allRoundAthlete(name, age, 13.6, 1.80, 6);
        allRoundAthlete.displayInfo();
    }
    else {

        cin >> n;

        Athlete **athletes = new Athlete *[n];
        for (int i = 0; i < n; i++) {
            cin >> choice;
            if (choice == 1) {
                cin >> name >> age >> speed;

                athletes[i] = new Runner(name, age, speed);
            } else {
                cin >> name >> age >> height;

                athletes[i] = new Jumper(name, age, height);
            }

        }

        findAthleteWithMaxValue(athletes, n)->displayInfo();

    }


    return 0;
}
