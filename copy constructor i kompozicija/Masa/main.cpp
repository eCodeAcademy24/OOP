#include <iostream>
#include <cstring>

using namespace std;

class Masa {
private:
    int dolzinaMasa;
    int sirinaMasa;
public:
    Masa() {}

    Masa(int dolzinaMasa, int sirinaMasa) {
        this->dolzinaMasa = dolzinaMasa;
        this->sirinaMasa = sirinaMasa;
    }

    Masa(const Masa &masa) {
        this->dolzinaMasa = masa.dolzinaMasa;
        this->sirinaMasa = masa.sirinaMasa;
    }

    int getDolzinaMasa() {
        return dolzinaMasa;
    }

    int getSirinaMasa() {
        return sirinaMasa;
    }

    void setDolzinaMasa(int dolzinaMasa) {
        this->dolzinaMasa = dolzinaMasa;
    }

    void setSirinaMasa(int sirinaMasa) {
        this->sirinaMasa = sirinaMasa;
    }

    ~Masa() {}

    void pecati() {
        cout << " Masa: " << dolzinaMasa << " " << sirinaMasa << endl;
    }
};

class Soba {
private:
    Masa masa;
    int dolzinaSoba;
    int sirinaSoba;
public:
    Soba() {}

    Soba(int dolzinaSoba, int sirinaSoba, Masa masa) {
        this->masa = masa;
        this->dolzinaSoba = dolzinaSoba;
        this->sirinaSoba = sirinaSoba;
    }

    Soba(const Soba &soba) {
        this->masa = soba.masa;
        this->dolzinaSoba = soba.dolzinaSoba;
        this->sirinaSoba = soba.sirinaSoba;
    }

    Masa getMasa() {
        return masa;
    }

    int getDolzinaSoba() {
        return dolzinaSoba;
    }

    int getSirinaSoba() {
        return sirinaSoba;
    }

    void setMasa(Masa masa) {
        this->masa = masa;
    }

    void setDolzinaSoba(int dolzinaSoba) {
        this->dolzinaSoba = dolzinaSoba;
    }

    void setSirinaSoba(int sirinaSoba) {
        this->sirinaSoba = sirinaSoba;
    }

    ~Soba() {}

    void pecati() {
        cout << " Soba: " << dolzinaSoba << " " << sirinaSoba;
        masa.pecati();
    }
};

class Kukja {
private:
    Soba soba;
    char adresa[50];
public:
    Kukja() {}

    Kukja(Soba soba, char *adresa) {
        this->soba = soba;
        strcpy(this->adresa, adresa);
    }

    Kukja(const Kukja &kukja) {
        this->soba = kukja.soba;
        strcpy(this->adresa, kukja.adresa);
    }

    Soba getSoba() {
        return soba;
    }

    char *getAdresa() {
        return adresa;
    }

    void setSoba(Soba soba) {
        this->soba = soba;
    }

    void setAdresa(char *adresa) {
        strcpy(this->adresa, adresa);
    }

    ~Kukja() {}

    void pecati() {
        cout << "Adresa: " << adresa;
        soba.pecati();
    }
};

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int masaSirina, masaDolzina;
        cin >> masaSirina;
        cin >> masaDolzina;
        Masa m(masaSirina, masaDolzina);
        int sobaSirina, sobaDolzina;
        cin >> sobaSirina;
        cin >> sobaDolzina;
        Soba s(sobaSirina, sobaDolzina, m);
        char adresa[30];
        cin >> adresa;
        Kukja k(s, adresa);
        k.pecati();
    }

    return 0;
}
