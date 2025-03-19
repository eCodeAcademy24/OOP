#include <iostream>
#include <cstring>

using namespace std;

class Pica {
private:
    char ime[15];
    int cena;
    char *sostojki;
    int popust;
public:
    Pica() {
        sostojki = new char[0];
    }

    Pica(char *ime, int cena, char *sostojki, int popust) {
        strcpy(this->ime, ime);
        this->cena = cena;
        this->sostojki = new char[strlen(sostojki) + 1];
        strcpy(this->sostojki, sostojki);
        this->popust = popust;
    }

    Pica(const Pica &pica) {
        strcpy(ime, pica.ime);
        cena = pica.cena;
        sostojki = new char[strlen(pica.sostojki) + 1];
        strcpy(sostojki, pica.sostojki);
        popust = pica.popust;
    }

    Pica &operator=(const Pica &pica) {
        if (this != &pica) {
            delete[] sostojki;
            strcpy(ime, pica.ime);
            cena = pica.cena;
            sostojki = new char[strlen(pica.sostojki) + 1];
            strcpy(sostojki, pica.sostojki);
            popust = pica.popust;
        }

        return *this;
    }

    ~Pica() {
        delete[] sostojki;
    }

    int getCena() {
        return cena;
    }

    int getPopust() {
        return popust;
    }

    void pecati() {
        cout << ime << " - " << sostojki << ", " << cena;
    }

    bool istiSe(Pica pica) {
        return !strcmp(sostojki, pica.sostojki);
    }
};

class Picerija {
private:
    char ime[15];
    Pica *pici;
    int brPici;
public:
    Picerija() {
        pici = new Pica[0];
        brPici = 0;
    }

    Picerija(char *ime) {
        strcpy(this->ime, ime);
        pici = new Pica[0];
        brPici = 0;
    }

    Picerija(const Picerija &picerija) {
        strcpy(ime, picerija.ime);
        brPici = picerija.brPici;
        pici = new Pica[brPici];
        for (int i = 0; i < brPici; i++) {
            pici[i] = picerija.pici[i];
        }
    }

    Picerija &operator=(const Picerija &picerija) {
        if (this != &picerija) {
            delete[] pici;
            strcpy(ime, picerija.ime);
            brPici = picerija.brPici;
            pici = new Pica[brPici];
            for (int i = 0; i < brPici; i++) {
                pici[i] = picerija.pici[i];
            }
        }

        return *this;
    }

    ~Picerija() {
        delete[] pici;
    }

    char *getIme() {
        return ime;
    }

    void setIme(char *ime) {
        strcpy(this->ime, ime);
    }

    void dodadi(Pica pica) {
        for (int i = 0; i < brPici; i++) {
            if (pici[i].istiSe(pica)) {
                return;
            }
        }

        Pica *tmp = new Pica[brPici + 1];
        for (int i = 0; i < brPici; i++) {
            tmp[i] = pici[i];
        }

        tmp[brPici] = pica;
        delete[] pici;
        ++brPici;

        pici = new Pica[brPici];
//        for (int i = 0; i < brPici; i++) {
//            pici[i] = tmp[i];
//        }
        pici = tmp;
    }

    //30% --> 30 / 100 = 0.3
    // 1 - 0.3 = 0.7 * pici[i].getCena()
    void piciNaPromocija() {
        for (int i = 0; i < brPici; i++) {
            if (pici[i].getPopust()) {
                pici[i].pecati();
                cout << " " << pici[i].getCena() * (1 - pici[i].getPopust() / 100.0) << endl;
            }
        }
    }
};

int main() {

    int n;
    char ime[15];
    cin >> ime;
    cin >> n;

    Picerija p1(ime);
    for (int i = 0; i < n; i++) {
        char imp[100];
        cin.get();
        cin.getline(imp, 100);
        int cena;
        cin >> cena;
        char sostojki[100];
        cin.get();
        cin.getline(sostojki, 100);
        int popust;
        cin >> popust;
        Pica p(imp, cena, sostojki, popust);
        p1.dodadi(p);
    }

    Picerija p2 = p1;
    cin >> ime;
    p2.setIme(ime);
    char imp[100];
    cin.get();
    cin.getline(imp, 100);
    int cena;
    cin >> cena;
    char sostojki[100];
    cin.get();
    cin.getline(sostojki, 100);
    int popust;
    cin >> popust;
    Pica p(imp, cena, sostojki, popust);
    p2.dodadi(p);

    cout << p1.getIme() << endl;
    cout << "Pici na promocija:" << endl;
    p1.piciNaPromocija();

    cout << p2.getIme() << endl;
    cout << "Pici na promocija:" << endl;
    p2.piciNaPromocija();

    return 0;
}
