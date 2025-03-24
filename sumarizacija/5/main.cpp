#include <iostream>
#include <cstring>

using namespace std;

enum tip {
    pop, rap, rok
};

class Pesna {
private:
    char *ime;
    int vremetraenje;
    tip tipPesna;
public:
    Pesna() {
        ime = new char[0];
    }

    Pesna(char *ime, int vremetraenje, tip tipPesna) {
        this->ime = new char[strlen(ime) + 1];
        strcpy(this->ime, ime);
        this->vremetraenje = vremetraenje;
        this->tipPesna = tipPesna;
    }

    Pesna(const Pesna &pesna) {
        this->ime = new char[strlen(pesna.ime) + 1];
        strcpy(this->ime, pesna.ime);
        this->vremetraenje = pesna.vremetraenje;
        this->tipPesna = pesna.tipPesna;
    }

    Pesna &operator=(const Pesna &pesna) {
        if (this != &pesna) {
            delete[] ime;
            this->ime = new char[strlen(pesna.ime) + 1];
            strcpy(this->ime, pesna.ime);
            this->vremetraenje = pesna.vremetraenje;
            this->tipPesna = pesna.tipPesna;
        }

        return *this;
    }

    ~Pesna() {
        delete[] ime;
    }

    int getVremetraenje() {
        return vremetraenje;
    }

    enum tip getTip() {
        return tipPesna;
    }

    void pecati() {
        cout << "\"" << ime << "\"" << "-" << vremetraenje << "min" << endl;
    }
};

class CD {
private:
    Pesna pesna[10];
    int brPesni;
    int maxVremetraenje;
public:
    CD() {

    }

    CD(int maxVremetraenje) {
        this->maxVremetraenje = maxVremetraenje;
        brPesni = 0;
    }

    CD(const CD &cd) {
        this->maxVremetraenje = cd.maxVremetraenje;
        this->brPesni = cd.brPesni;
        for (int i = 0; i < brPesni; i++) {
            this->pesna[i] = cd.pesna[i];
        }
    }

    CD &operator=(const CD &cd) {
        if (this != &cd) {
            this->maxVremetraenje = cd.maxVremetraenje;
            this->brPesni = cd.brPesni;
            for (int i = 0; i < brPesni; i++) {
                this->pesna[i] = cd.pesna[i];
            }
        }

        return *this;
    }

    ~CD() {}

    Pesna getPesna(int id) {
        return pesna[id];
    }

    int getBroj() {
        return brPesni;
    }

    void dodadiPesna(Pesna p) {
        if (brPesni >= 10) {
            return;
        }

        int max = 0;
        for (int i = 0; i < brPesni; i++) {
            max += pesna[i].getVremetraenje();
        }

        if (max + p.getVremetraenje() > maxVremetraenje) {
            return;
        }

        pesna[brPesni] = p;
        ++brPesni;
    }

    void pecatiPesniPoTip(tip t) {
        for (int i = 0; i < this->brPesni; i++) {
            if (this->pesna[i].getTip() == t) this->pesna[i].pecati();
        }
    }
};

int main() {
    // se testira zadacata modularno
    int testCase;
    cin >> testCase;

    int n, minuti, kojtip;
    char ime[50];

    if (testCase == 1) {
        cout << "===== Testiranje na klasata Pesna ======" << endl;
        cin >> ime;
        cin >> minuti;
        cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
        Pesna p(ime, minuti, (tip) kojtip);
        p.pecati();
    } else if (testCase == 2) {
        cout << "===== Testiranje na klasata CD ======" << endl;
        CD omileno(20);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime, minuti, (tip) kojtip);
            omileno.dodadiPesna(p);
        }
        for (int i = 0; i < n; i++)
            (omileno.getPesna(i)).pecati();
    } else if (testCase == 3) {
        cout << "===== Testiranje na metodot dodadiPesna() od klasata CD ======" << endl;
        CD omileno(20);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime, minuti, (tip) kojtip);
            omileno.dodadiPesna(p);
        }
        for (int i = 0; i < omileno.getBroj(); i++)
            (omileno.getPesna(i)).pecati();
    } else if (testCase == 4) {
        cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======" << endl;
        CD omileno(20);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime, minuti, (tip) kojtip);
            omileno.dodadiPesna(p);
        }
        cin >> kojtip;
        omileno.pecatiPesniPoTip((tip) kojtip);

    } else if (testCase == 5) {
        cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======" << endl;
        CD omileno(20);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime, minuti, (tip) kojtip);
            omileno.dodadiPesna(p);
        }
        cin >> kojtip;
        omileno.pecatiPesniPoTip((tip) kojtip);

    }

    return 0;
}