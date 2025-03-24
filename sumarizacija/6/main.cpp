#include<iostream>
#include<cstring>

using namespace std;

class Patnik {
private:
    char ime[100];
    int klasa;
    bool velosiped;
public:
    Patnik() {}

    Patnik(char *ime, int klasa, bool velosiped) {
        strcpy(this->ime, ime);
        this->klasa = klasa;
        this->velosiped = velosiped;
    }

    Patnik(const Patnik &p) {
        strcpy(ime, p.ime);
        klasa = p.klasa;
        velosiped = p.velosiped;
    }

    int getKlasa() {
        return klasa;
    }

    bool getVelosiped() {
        return velosiped;
    }

    ~Patnik() {}

    friend ostream &operator<<(ostream &out, Patnik &p) {
        out << p.ime << endl;
        out << p.klasa << endl;
        out << (p.velosiped ? 1 : 0) << endl;
        return out;
    }
};

class Voz {
private:
    char destinacija[100];
    Patnik *p;
    int brPatnici;
    int dozvoleniVelosipedi;
public:
    Voz() {
        p = new Patnik[0];
        brPatnici = 0;
    }

    Voz(char *destinacija, int dozvoleniVelosipedi) {
        strcpy(this->destinacija, destinacija);
        this->dozvoleniVelosipedi = dozvoleniVelosipedi;
        this->brPatnici = 0;
        this->p = new Patnik[0];
    }

    Voz(const Voz &v) {
        strcpy(destinacija, v.destinacija);
        dozvoleniVelosipedi = v.dozvoleniVelosipedi;
        brPatnici = v.brPatnici;
        p = new Patnik[v.brPatnici];
        for (int i = 0; i < v.brPatnici; i++) {
            p[i] = v.p[i];
        }
    }

    Voz &operator=(const Voz &v) {
        if (this != &v) {
            delete[] p;
            strcpy(destinacija, v.destinacija);
            dozvoleniVelosipedi = v.dozvoleniVelosipedi;
            brPatnici = v.brPatnici;
            p = new Patnik[v.brPatnici];
            for (int i = 0; i < v.brPatnici; i++) {
                p[i] = v.p[i];
            }
        }
        return *this;
    }

    ~Voz() {
        delete[] p;
    }

    Voz &operator+=(Patnik &pa) {
        if (pa.getVelosiped() && dozvoleniVelosipedi == 0)
            return *this;

        Patnik *tmp = new Patnik[brPatnici + 1];
        for (int i = 0; i < brPatnici; i++) {
            tmp[i] = p[i];
        }

        tmp[brPatnici] = pa;
        delete[] p;
        brPatnici++;

        p = new Patnik[brPatnici];
        for (int i = 0; i < brPatnici; i++) {
            p[i] = tmp[i];
        }

        return *this;
    }

    void patniciNemaMesto() {
        int preostanatiPrvaKlasa = 0, preostanatiVtoraKlasa = 0;
        int brojac = 0;
        for (int i = 0; i < brPatnici; i++) {
            if (p[i].getKlasa() == 1) {
                if (p[i].getVelosiped()) {
                    if (brojac < dozvoleniVelosipedi) {
                        brojac++;
                    } else {
                        preostanatiPrvaKlasa++;
                    }
                }
            }
        }

        for (int i = 0; i < brPatnici; i++) {
            if (p[i].getKlasa() == 2) {
                if (p[i].getVelosiped()) {
                    if (brojac < dozvoleniVelosipedi) {
                        brojac++;
                    } else {
                        preostanatiVtoraKlasa++;
                    }
                }
            }
        }
        cout << "Brojot na patnici od 1-va klasa koi ostanale bez mesto e: " << preostanatiPrvaKlasa << endl;
        cout << "Brojot na patnici od 2-ra klasa koi ostanale bez mesto e: " << preostanatiVtoraKlasa << endl;

    }

    friend ostream &operator<<(ostream &out, Voz &v) {
        out << v.destinacija << endl;
        for (int i = 0; i < v.brPatnici; i++) {
            out << v.p[i] << endl;
        }
    }

};


int main() {
    Patnik p;
    char ime[100], destinacija[100];
    int n;
    bool velosiped;
    int klasa;
    int maxv;
    cin >> destinacija >> maxv;
    cin >> n;
    Voz v(destinacija, maxv);
    //cout<<v<<endl;
    for (int i = 0; i < n; i++) {
        cin >> ime >> klasa >> velosiped;
        Patnik p(ime, klasa, velosiped);
        //cout<<p<<endl;
        v += p;
    }
    cout << v;
    v.patniciNemaMesto();

    return 0;
}
