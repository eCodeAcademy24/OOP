#include <iostream>
#include <cstring>

using namespace std;

class Ekipa {
private:
    char ime[15];
    int brPobedi;
    int brPorazi;
public:
    Ekipa() {}

    Ekipa(char *ime, int brPobedi, int brPorazi) {
        strcpy(this->ime, ime);
        this->brPobedi = brPobedi;
        this->brPorazi = brPorazi;
    }

    Ekipa(const Ekipa &ek) {
        strcpy(ime, ek.ime);
        brPobedi = ek.brPobedi;
        brPorazi = ek.brPorazi;
    }

    int getBrPobedi() {
        return brPobedi;
    }

    void pecati() {
        cout << "Ime: " << ime << " Pobedi: " << brPobedi << " Porazi: " << brPorazi;
    }

    ~Ekipa() {}
};

class FudbalskaEkipa : public Ekipa {
private:
    int brCrveni;
    int brZholti;
    int brNeresheni;
public:
    FudbalskaEkipa() : Ekipa() {}

    FudbalskaEkipa(char *ime, int brPobedi, int brPorazi, int brCrveni, int brZholti, int brNeresheni) : Ekipa(ime,
                                                                                                               brPobedi,
                                                                                                               brPorazi) {
        this->brCrveni = brCrveni;
        this->brZholti = brZholti;
        this->brNeresheni = brNeresheni;
    }

    FudbalskaEkipa(const FudbalskaEkipa &fe) : Ekipa(fe) {
        brCrveni = fe.brCrveni;
        brZholti = fe.brZholti;
        brNeresheni = fe.brNeresheni;
    }

    void pecati() {
        Ekipa::pecati();
        cout << " Nereseni: " << brNeresheni << " Poeni: " << (getBrPobedi() * 3 + brNeresheni * 1) << endl;
    }

    ~FudbalskaEkipa() {}
};

int main() {
    char ime[15];
    int pob, por, ck, zk, ner;
    cin >> ime >> pob >> por >> ck >> zk >> ner;
    FudbalskaEkipa f1(ime, pob, por, ck, zk, ner);
    f1.pecati();
    return 0;
}
