#include <iostream>
#include <cstring>

using namespace std;

class Nedviznina {
protected:
    char *adresa;
    int kvadratura;
    int cenaKvadrat;
public:
    Nedviznina() {
        adresa = new char[0];
    }

    Nedviznina(const Nedviznina &ned) {
        adresa = new char[strlen(ned.adresa) + 1];
        strcpy(adresa, ned.adresa);
        kvadratura = ned.kvadratura;
        cenaKvadrat = ned.cenaKvadrat;
    }

    Nedviznina &operator=(const Nedviznina &ned) {
        if (this != &ned) {
            delete[] adresa;
            adresa = new char[strlen(ned.adresa) + 1];
            strcpy(adresa, ned.adresa);
            kvadratura = ned.kvadratura;
            cenaKvadrat = ned.cenaKvadrat;
        }

        return *this;
    }

    ~Nedviznina() {
        delete[] adresa;
    }

    char *getAdresa() {
        return adresa;
    }

    int cena() {
        return kvadratura * cenaKvadrat;
    }

    virtual float danokNaImot() {
        return ((float) 5 * cena()) / 100;
    }

    virtual void pecati() {
        cout << adresa << ", Kvadratura: " << kvadratura << ", Cena po Kvadrat: " << cenaKvadrat << endl;
    }

    friend istream &operator>>(istream &in, Nedviznina &ned) {
        in >> ned.adresa >> ned.kvadratura >> ned.cenaKvadrat;
        return in;
    }
};

class Vila : public Nedviznina {
private:
    int danokLuksuz;
public:
    Vila() : Nedviznina() {}

    Vila(const Vila &vila) : Nedviznina(vila) {
        danokLuksuz = vila.danokLuksuz;
    }

    Vila &operator=(const Vila &vila) {
        if (this != &vila) {
            delete[] adresa;
            adresa = new char[strlen(vila.adresa) + 1];
            strcpy(adresa, vila.adresa);
            kvadratura = vila.kvadratura;
            cenaKvadrat = vila.cenaKvadrat;
            danokLuksuz = vila.danokLuksuz;
        }

        return *this;
    }

    ~Vila() {}

    void pecati() {
        cout << adresa << ", Kvadratura: " << kvadratura << ", Cena po Kvadrat: " << cenaKvadrat
             << ", Danok na luksuz: " << danokLuksuz << endl;
    }

    float danokNaImot() {
        float danok = Nedviznina::danokNaImot();
        float novDanok = ((float) danokLuksuz * cena()) / 100;
        return danok + novDanok;
    }

    friend istream &operator>>(istream &in, Vila &vila) {
        in >> vila.adresa >> vila.kvadratura >> vila.cenaKvadrat >> vila.danokLuksuz;
        return in;
    }
};

int main() {
    Nedviznina n;
    Vila v;
    cin >> n;
    cin >> v;
    n.pecati();
    cout << "Danok za: " << n.getAdresa() << ", e: " << n.danokNaImot() << endl;
    v.pecati();
    cout << "Danok za: " << v.getAdresa() << ", e: " << v.danokNaImot() << endl;
    return 0;
}
