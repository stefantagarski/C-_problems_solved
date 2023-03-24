#include<iostream>
#include<cstring>
using namespace std;

class BasketballPlayer {
private:
    char name[50];
    char surname[50];
    int number;
    int num_first;
    int num_second;
    int num_third;
public:
    BasketballPlayer( char * n,char * sur,int _number,int first,int second,int third) {
        strcpy(name,n);
        strcpy(surname,sur);
        number = _number;
        num_first = first;
        num_second = second;
        num_third = third;

    }

    ~BasketballPlayer(){

    }
    void printInfo() {
        int totalPoints = num_first + num_second + num_third;
        float avgPoints =  totalPoints / 3.0;
        cout << "Player: " << name <<" "<< surname << " with number: " << number << " has " << avgPoints << " points on average" << endl;
    }
};

int main(){
    char name[50];
    char surname[50];
    int jerseyNumber, pointsMatch1, pointsMatch2, pointsMatch3;
    cin>>name;
    cin>>surname;
    cin>>jerseyNumber;
    cin>>pointsMatch1;
    cin>>pointsMatch2;
    cin>>pointsMatch3;
BasketballPlayer player(name,surname,jerseyNumber,pointsMatch1,pointsMatch2,pointsMatch3);
player.printInfo();

return 0;
}