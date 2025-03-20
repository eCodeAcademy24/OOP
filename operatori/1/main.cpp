#include <iostream>
#include <cstring>

using namespace std;

class Automobile {
private:
    char *brand;
    int *registration;
    int maxSpeed;
public:
    Automobile() {
        brand = new char[0];
        registration = new int[0];
    }

    Automobile(char *brand, int *registration, int maxSpeed) {
        this->brand = new char[strlen(brand) + 1];
        strcpy(this->brand, brand);
        this->registration = new int[5];
        for (int i = 0; i < 5; i++) {
            this->registration[i] = registration[i];
        }
        this->maxSpeed = maxSpeed;
    }

    Automobile(const Automobile &automobile) {
        brand = new char[strlen(automobile.brand) + 1];
        strcpy(brand, automobile.brand);
        registration = new int[5];
        for (int i = 0; i < 5; i++) {
            registration[i] = automobile.registration[i];
        }
        maxSpeed = automobile.maxSpeed;
    }

    Automobile &operator=(const Automobile &automobile) {
        if (this != &automobile) {
            delete[] brand;
            delete[] registration;
            brand = new char[strlen(automobile.brand) + 1];
            strcpy(brand, automobile.brand);
            registration = new int[5];
            for (int i = 0; i < 5; i++) {
                registration[i] = automobile.registration[i];
            }
            maxSpeed = automobile.maxSpeed;
        }

        return *this;
    }

    ~Automobile() {
        delete[] brand;
        delete[] registration;
    }

    int getMaxSpeed() {
        return maxSpeed;
    }

    bool operator==(const Automobile &other) {
        return registration == other.registration;
    }

    friend ostream &operator<<(ostream &out, const Automobile &other) {
        out << "Marka\t" << other.brand << "\tRegistracija[ ";
        for (int i = 0; i < 5; i++) {
            out << other.registration[i] << " ";
        }
        out << "]" << endl;
        return out;
    }
};

class RentACar {
private:
    char name[100];
    Automobile *autos;
    int numAutos;
public:
    RentACar() {
        autos = new Automobile[0];
        numAutos = 0;
    }

    RentACar(char *name) {
        strcpy(this->name, name);
        autos = new Automobile[0];
        numAutos = 0;
    }

    RentACar(const RentACar &rc) {
        strcpy(name, rc.name);
        numAutos = rc.numAutos;
        autos = new Automobile[numAutos];
        for (int i = 0; i < numAutos; i++) {
            autos[i] = rc.autos[i];
        }
    }

    RentACar &operator=(const RentACar &rc) {
        if (this != &rc) {
            delete[] autos;
            strcpy(name, rc.name);
            numAutos = rc.numAutos;
            autos = new Automobile[numAutos];
            for (int i = 0; i < numAutos; i++) {
                autos[i] = rc.autos[i];
            }
        }

        return *this;
    }

    ~RentACar() {
        delete[] autos;
    }

    RentACar &operator+=(const Automobile &other) {
        Automobile *tmp = new Automobile[numAutos + 1];
        for (int i = 0; i < numAutos; i++) {
            tmp[i] = autos[i];
        }

        tmp[numAutos] = other;
        delete[] autos;
        numAutos++;

        autos = new Automobile[numAutos];
        autos = tmp;

        return *this;
    }

    RentACar &operator-=(const Automobile &other) {
        bool flag = false;
        for (int i = 0; i < numAutos; i++) {
            if (autos[i] == other) {
                flag = true;
            }
        }

        if (!flag) return *this;

        Automobile *tmp = new Automobile[numAutos - 1];
        int index = 0;
        for (int i = 0; i < numAutos; i++) {
            if (!(autos[i] == other)) {
                tmp[index] = autos[i];
                ++index;
            }
        }

        delete[] autos;
        --numAutos;

        autos = new Automobile[numAutos];
        autos = tmp;
    }

    void pecatiNadBrzina(int max) {
        cout << name << endl;
        for (int i = 0; i < numAutos; i++) {
            if (autos[i].getMaxSpeed() > max) {
                cout << autos[i];
            }
        }
    }
};

int main() {
    RentACar agencija("Ecode-Car");
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        char marka[100];
        int regisracija[5];
        int maximumBrzina;

        cin >> marka;

        for (int i = 0; i < 5; i++)
            cin >> regisracija[i];

        cin >> maximumBrzina;

        Automobile nov = Automobile(marka, regisracija, maximumBrzina);

        //dodavanje na avtomobil
        agencija += nov;

    }
    //se cita grehsniot avtmobil, za koj shto avtmobilot so ista registracija treba da se izbrishe
    char marka[100];
    int regisracija[5];
    int maximumBrzina;
    cin >> marka;
    for (int i = 0; i < 5; i++)
        cin >> regisracija[i];
    cin >> maximumBrzina;

    Automobile greshka = Automobile(marka, regisracija, maximumBrzina);

    //brishenje na avtomobil
    agencija -= greshka;

    agencija.pecatiNadBrzina(150);

    return 0;
}
