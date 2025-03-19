#include<iostream>
#include<cstring>

using namespace std;
enum Tip {
    LINUX, UNIX, WINDOWS
};

class OperativenSistem {
private:
    char *ime;
    float verzija;
    Tip ti;
    float golemina;
public:
    OperativenSistem() {
        ime = new char[0];
    }

    OperativenSistem(char *ime, float verzija, Tip ti, float golemina) {
        this->ime = new char[strlen(ime) + 1];
        strcpy(this->ime, ime);
        this->verzija = verzija;
        this->ti = ti;
        this->golemina = golemina;
    }

    OperativenSistem(const OperativenSistem &o) {
        ime = new char[strlen(o.ime) + 1];
        strcpy(ime, o.ime);
        verzija = o.verzija;
        ti = o.ti;
        golemina = o.golemina;
    }

    OperativenSistem &operator=(const OperativenSistem &o) {
        if (this != &o) {
            delete[] ime;
            ime = new char[strlen(o.ime) + 1];
            strcpy(ime, o.ime);
            verzija = o.verzija;
            ti = o.ti;
            golemina = o.golemina;
        }
        return *this;
    }

    ~OperativenSistem() {
        delete[] ime;
    }

    void pecati() {
        cout << "Ime: " << ime << " Verzija: " << verzija << " Tip: " << ti << " Golemina:" << golemina << "GB" << endl;
    }

    bool ednakviSe(const OperativenSistem &os) {
        return !strcmp(ime, os.ime) && verzija == os.verzija && ti == os.ti && golemina == os.golemina;
    }

    int sporediVerzija(const OperativenSistem &os) {
        if (verzija == os.verzija)
            return 0;
        else if (verzija < os.verzija)
            return -1;
        else
            return 1;
    }

    bool istaFamilija(const OperativenSistem &sporedba) {
        return !strcmp(ime, sporedba.ime) && ti == sporedba.ti;
    }
};

class Repozitorium {
private:
    char ime[20];
    OperativenSistem *os;
    int brOS;
public:
    Repozitorium() {
        os = new OperativenSistem[0];
        brOS = 0;
    }

    Repozitorium(char *ime) {
        strcpy(this->ime, ime);
        this->brOS = 0;
        os = new OperativenSistem[0];
    }

    Repozitorium(const Repozitorium &r) {
        strcpy(ime, r.ime);
        brOS = r.brOS;
        os = new OperativenSistem[brOS];
        for (int i = 0; i < r.brOS; i++) {
            os[i] = r.os[i];
        }
    }

    Repozitorium &operator=(const Repozitorium &r) {
        if (this != &r) {
            delete[] os;
            strcpy(ime, r.ime);
            brOS = r.brOS;
            os = new OperativenSistem[brOS];
            for (int i = 0; i < r.brOS; i++) {
                os[i] = r.os[i];
            }
        }
        return *this;
    }

    ~Repozitorium() {
        delete[] os;
    }

    void pecatiOperativniSistemi() {
        cout << "Repozitorium: " << ime << endl;
        for (int i = 0; i < brOS; i++) {
            os[i].pecati();
        }
    }

    void izbrishi(const OperativenSistem &operativenSistem) {
        bool flag = false;
        for (int i = 0; i < brOS; i++) {
            if (os[i].ednakviSe(operativenSistem)) {
                flag = true;
                break;
            }
        }
        if (!flag)
            return;

        OperativenSistem *tmp = new OperativenSistem[brOS - 1];
        int k = 0;
        for (int i = 0; i < brOS; i++) {
            if (!os[i].ednakviSe(operativenSistem)) {
                tmp[k] = os[i];
                k++;
            }
        }
        brOS--;
        delete[] os;
        os = new OperativenSistem[brOS];
        for (int i = 0; i < brOS; i++) {
            os[i] = tmp[i];
        }
    }

    void dodadi(const OperativenSistem &nov) {
        for (int i = 0; i < brOS; i++) {
            if (os[i].istaFamilija(nov) && os[i].sporediVerzija(nov) < 0) {
                os[i] = nov;
                return;
            }
        }

        OperativenSistem *tmp = new OperativenSistem[brOS + 1];
        for (int i = 0; i < brOS; i++) {
            tmp[i] = os[i];
        }
        tmp[brOS] = nov;
        delete[] os;
        brOS++;
        os = new OperativenSistem[brOS];
        for (int i = 0; i < brOS; i++) {
            os[i] = tmp[i];
        }
    }
};

int main() {
    char repoName[20];
    cin >> repoName;
    Repozitorium repozitorium = Repozitorium(repoName);
    int brojOperativniSistemi = 0;
    cin >> brojOperativniSistemi;
    char ime[20];
    float verzija;
    int tip;
    float golemina;
    for (int i = 0; i < brojOperativniSistemi; i++) {
        cin >> ime;
        cin >> verzija;
        cin >> tip;
        cin >> golemina;
        OperativenSistem os = OperativenSistem(ime, verzija, (Tip) tip, golemina);
        repozitorium.dodadi(os);
    }

    repozitorium.pecatiOperativniSistemi();
    cin >> ime;
    cin >> verzija;
    cin >> tip;
    cin >> golemina;
    OperativenSistem os = OperativenSistem(ime, verzija, (Tip) tip, golemina);
    cout << "=====Brishenje na operativen sistem=====" << endl;
    repozitorium.izbrishi(os);
    repozitorium.pecatiOperativniSistemi();
    return 0;
}
