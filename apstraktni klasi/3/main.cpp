#include<iostream>

using namespace std;

class Vozilo {
protected:
    float masa;
    int shirina;
    int visina;
public:
    Vozilo() {}

    Vozilo(float masa, int shirina, int visina) {
        this->masa = masa;
        this->shirina = shirina;
        this->visina = visina;
    }

    Vozilo(const Vozilo &vozilo) {
        masa = vozilo.masa;
        shirina = vozilo.shirina;
        visina = vozilo.visina;
    }

    ~Vozilo() {}

    float getMasa() {
        return masa;
    }

    int getShirina() {
        return shirina;
    }

    virtual int vratiDnevnaCena() = 0;
};

class Avtomobil : public Vozilo {
private:
    int brVrati;
public:
    Avtomobil() : Vozilo() {}

    Avtomobil(float masa, int shirina, int visina, int brVrati) : Vozilo(masa, shirina, visina) {
        this->brVrati = brVrati;
    }

    Avtomobil(const Avtomobil &a) : Vozilo(a) {
        brVrati = a.brVrati;
    }

    ~Avtomobil() {}

    int vratiDnevnaCena() {
//        if (brVrati < 5) return 100;
//        return 130;
        return brVrati < 5 ? 100 : 130;
    }
};

class Avtobus : public Vozilo {
private:
    int brPatnici;
public:
    Avtobus() : Vozilo() {}

    Avtobus(float masa, int shirina, int visina, int brPatnici) : Vozilo(masa, shirina, visina) {
        this->brPatnici = brPatnici;
    }

    Avtobus(const Avtobus &avtobus) : Vozilo(avtobus) {
        brPatnici = avtobus.brPatnici;
    }

    ~Avtobus() {}

    int vratiDnevnaCena() {
        return brPatnici * 5;
    }
};

class Kamion : public Vozilo {
private:
    float nosivost;
public:
    Kamion() : Vozilo() {}

    Kamion(float masa, int shirina, int visina, float nosivost) : Vozilo(masa, shirina, visina) {
        this->nosivost = nosivost;
    }

    Kamion(const Kamion &kamion) : Vozilo(kamion) {
        nosivost = kamion.nosivost;
    }

    ~Kamion() {}

    float getNosivost() {
        return nosivost;
    }

    // За секој камион цената се пресметува со формулата:
    // (masa+nosivost)*0.02.
    int vratiDnevnaCena() {
        return (masa + nosivost) * 0.02;
    }
};

class ParkingPlac {
private:
    Vozilo **vozila;
    int brVozila;
public:
    ParkingPlac() {
        vozila = new Vozilo *[0];
        brVozila = 0;
    }

    ParkingPlac(const ParkingPlac &pp) {
        brVozila = pp.brVozila;
        vozila = new Vozilo *[brVozila];
        for (int i = 0; i < brVozila; i++) {
            vozila[i] = pp.vozila[i];
        }
    }

    ParkingPlac &operator=(const ParkingPlac &pp) {
        if (this != &pp) {
            delete[] vozila;
            brVozila = pp.brVozila;
            vozila = new Vozilo *[brVozila];
            for (int i = 0; i < brVozila; i++) {
                vozila[i] = pp.vozila[i];
            }
        }

        return *this;
    }

    ~ParkingPlac() {
        delete[] vozila;
    }

    ParkingPlac &operator+=(Vozilo *vozilo) {
        Vozilo **tmp = new Vozilo *[brVozila + 1];
        for (int i = 0; i < brVozila; i++) {
            tmp[i] = vozila[i];
        }

        tmp[brVozila] = vozilo;
        delete[] vozila;
        brVozila++;

        vozila = new Vozilo *[brVozila];
        for (int i = 0; i < brVozila; i++) {
            vozila[i] = tmp[i];
        }

        return *this;
    }

    float presmetajVkupnaMasa() {
        float vkupno = 0;
        for (int i = 0; i < brVozila; i++) {
            vkupno += vozila[i]->getMasa();
        }

        return vkupno;
    }

    int brojVozilaPoshirokiOd(int value) {
        int brojac = 0;
        for (int i = 0; i < brVozila; i++) {
            if (vozila[i]->getShirina() > value) {
                brojac++;
            }
        }

        return brojac;
    }

    void pecati() {
        int brojacAvtomobili = 0, brojacAvtobusi = 0, brojacKamioni = 0;

        for (int i = 0; i < brVozila; i++) {
            Avtomobil *avtomobil = dynamic_cast<Avtomobil *>(vozila[i]);
            Avtobus *avtobus = dynamic_cast<Avtobus *>(vozila[i]);

            if (avtomobil) {
                brojacAvtomobili++;
            } else if (avtobus) {
                brojacAvtobusi++;
            } else {
                brojacKamioni++;
            }
        }

        cout << "Brojot na avtomobili e " << brojacAvtomobili << ", brojot na avtobusi e " << brojacAvtobusi
             << " i brojot na kamioni e " << brojacKamioni << endl;
    }

    int pogolemaNosivostOd(Vozilo &vozilo) {
        int brojac = 0;
        for (int i = 0; i < brVozila; i++) {
            Kamion *kamion = dynamic_cast<Kamion *>(vozila[i]);

            if (kamion) {
                if (kamion->getNosivost() > vozilo.getMasa()) {
                    brojac++;
                }
            }
        }
        return brojac;
    }

    int vratiDnevnaZarabotka() {
        int vkupno = 0;
        for (int i = 0; i < brVozila; i++) {
            vkupno += vozila[i]->vratiDnevnaCena();
        }

        return vkupno;
    }
};

int main() {
    ParkingPlac p;

    int n;
    cin >> n;
    int shirina, visina, broj;
    float masa, nosivost;
    for (int i = 0; i < n; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            cin >> masa >> shirina >> visina >> broj;
            Avtomobil *a = new Avtomobil(masa, shirina, visina, broj);
            p += a;
        }
        if (type == 2) {
            cin >> masa >> shirina >> visina >> broj;
            p += new Avtobus(masa, shirina, visina, broj);
        }
        if (type == 3) {
            cin >> masa >> shirina >> visina >> nosivost;
            p += new Kamion(masa, shirina, visina, nosivost);
        }
    }

    p.pecati();

    cout << "\nZarabotkata e " << p.vratiDnevnaZarabotka() << endl;
    cout << "Vkupnata masa e " << p.presmetajVkupnaMasa() << endl;
    cout << "Brojot poshiroki od 5 e " << p.brojVozilaPoshirokiOd(5) << endl;
    Avtomobil a(1200, 4, 3, 5);
    cout << "Brojot na kamioni so nosivost pogolema od avtomobilot e " << p.pogolemaNosivostOd(a) << endl;


}
