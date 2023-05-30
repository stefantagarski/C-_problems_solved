#include<iostream>
#include<cstring>

using namespace std;

class Transport {
protected:
    char destination[31];
    int base_price;
    int distance;
public:
    Transport(const char* destination = "", int base_price = 0, int distance = 0) {
        strcpy(this->destination, destination);
        this->base_price = base_price;
        this->distance = distance;
    }

    virtual double cenaTransport() const = 0;

    bool operator<(const Transport& other) const {
        return distance < other.distance;
    }

    const char* getDestination() const {
        return destination;
    }

    int getDistance() const {
        return distance;
    }
};

class AvtomobilTransport : public Transport {
private:
    bool driver;
public:
    AvtomobilTransport(const char* destination = "", int base_price = 0, int distance = 0, bool driver = false)
            : Transport(destination, base_price, distance) {
        this->driver = driver;
    }

    double cenaTransport() const override {
        if (driver) {
            return base_price + (base_price * 0.2);
        }
        return base_price;
    }
};

class KombeTransport : public Transport {
private:
    int capacity;
public:
    KombeTransport(const char* destination = "", int base_price = 0, int distance = 0, int capacity = 0)
            : Transport(destination, base_price, distance) {
        this->capacity = capacity;
    }

    double cenaTransport() const override {
        if (capacity < 0) {
            return 0;
        }
        else {
            return base_price - (capacity * 200);
        }
    }
};

void pecatiPoloshiPonudi(Transport* ponudi[], int n, const Transport& T) {
    Transport* polosi[n];
    int counter = 0;
    for (int i = 0; i < n; ++i) {
        if (ponudi[i]->cenaTransport() > T.cenaTransport()) {
            polosi[counter] = ponudi[i];
            counter++;
        }
    }
    for (int i = 0; i < counter; ++i) {
        for (int j = 0; j < counter-1-i; ++j) {
            if (polosi[j+1]->getDistance() < polosi[j]->getDistance()) {
                Transport* tmp = polosi[j];
                polosi[j] = polosi[j+1];
                polosi[j+1] = tmp;
            }
        }
    }
    for (int i = 0; i < counter; ++i) {
        cout << polosi[i]->getDestination() << " " << polosi[i]->getDistance() << " " << polosi[i]->cenaTransport() << endl;
    }
}

int main() {
    char destinacija[20];
    int tip, cena, rastojanie, lugje;
    bool shofer;
    int n;
    cin >> n;
    Transport** ponudi;
    ponudi = new Transport * [n];

    for (int i = 0; i < n; i++) {
        cin >> tip >> destinacija >> cena >> rastojanie;
        if (tip == 1) {
            cin >> shofer;
            ponudi[i] = new AvtomobilTransport(destinacija, cena, rastojanie, shofer);
        }
        else {
            cin >> lugje;
            ponudi[i] = new KombeTransport(destinacija, cena, rastojanie, lugje);
        }
    }

    AvtomobilTransport nov("Ohrid", 2000, 600, false);
    pecatiPoloshiPonudi(ponudi, n, nov);

    for (int i = 0; i < n; i++) {
        delete ponudi[i];
    }
    delete[] ponudi;
    return 0;
}
