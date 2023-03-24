#include<iostream>
#include<cstring>

using namespace std;
class Film {
private:
    char name[101];
    float rating;
    float revenue;
public:
    Film() {
        strcpy(name," ");
        rating = 0.0;
        revenue = 0.0;
    }

    Film(char * n, float r, float rev) {
        strcpy(name,n);
       rating = r;
        revenue = rev;
    }

    ~Film() {}

    void setName(char _number[50]) {
        strcpy(name,_number);
    }

    void setRating(float r) {
        rating = r;
    }

    void setRevenue(float rev) {
        revenue = rev;
    }

    char *getName() {
        return name;
    }

    float getRating() {
        return rating;
    }

    float getRevenue() {
        return revenue;
    }

    void display() {
        cout << "Name of film: " << name << endl;
        cout << "Rating: " << rating << endl;
        cout << "Revenue: " << revenue << endl;
    }
};
void printMostPopularFilm(Film *films, int n) {
    float maxRevenue = 0.0;
    int maxIndex = 0;

    for (int i = 0; i < n; i++) {
        if (films[i].getRevenue() > maxRevenue) {
            maxRevenue = films[i].getRevenue();
            maxIndex = i;
        }
    }

    cout << "Name of film: " << films[maxIndex].getName() << endl;
    cout<<"Rating: "<<films[maxIndex].getRating()<<endl;
    cout<<"Revenue: "<<films[maxIndex].getRevenue()<<endl;

}



int main() {
    int n;
    cin >> n;
    Film films[100];

    char name[100];
    double rating;
    double revenue;

    for (int i = 0; i < n-1; i++)  {
        cin>>name;
        cin >> rating;
        cin >> revenue;

        // testing constructor with arguments
        films[i] = Film(name, rating, revenue);

    }


    // testing set methods and display for last element
    cin>>name;
    cin >> rating;
    cin >> revenue;
    films[n-1].setName(name);
    films[n-1].setRating(rating);
    films[n-1].setRevenue(revenue);

    cout<<"-->Testing set methods and display()"<<endl;
    films[n-1].display();
    cout<<endl;

    cout<<"-->Testing printMostPopularFilm()"<<endl;
    printMostPopularFilm(films , n);
    return 0;
}