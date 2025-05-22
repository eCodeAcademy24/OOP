#include <iostream>
#include <string.h>

using namespace std;

class ZicanInstrument {
protected:
    char ime[20];
    int brZici;
    float osnovnaCena;
public:
    ZicanInstrument() {}

    ZicanInstrument(char *ime, int brZici, float osnovnaCena) {
        strcpy(this->ime, ime);
        this->brZici = brZici;
        this->osnovnaCena = osnovnaCena;
    }

    ZicanInstrument(const ZicanInstrument &zi) {
        strcpy(ime, zi.ime);
        brZici = zi.brZici;
        osnovnaCena = zi.osnovnaCena;
    }

    ZicanInstrument &operator=(const ZicanInstrument &zi) {
        if (this != &zi) {
            strcpy(ime, zi.ime);
            brZici = zi.brZici;
            osnovnaCena = zi.osnovnaCena;
        }
        return *this;
    }

    ~ZicanInstrument() {}

    int getBrZici() {
        return brZici;
    }

    float getOsnovnaCena() {
        return osnovnaCena;
    }

    virtual float cena() = 0;

    bool operator==(ZicanInstrument &zi) {
        return brZici == zi.brZici;
    }

    friend ostream &operator<<(ostream &out, ZicanInstrument &z) {
        cout << z.ime << " " << z.brZici << " " << z.osnovnaCena << endl;
        return out;
    }
};

class Mandolina : public ZicanInstrument {
private:
    char forma[20];
public:
    Mandolina() : ZicanInstrument() {}

    Mandolina(char *ime, int brZici, float osnovnaCena, char *forma) : ZicanInstrument(ime, brZici, osnovnaCena) {
        strcpy(this->forma, forma);
    }

    Mandolina(const Mandolina &m) : ZicanInstrument(m) {
        strcpy(forma, m.forma);
    }

    Mandolina operator=(const Mandolina &m) {
        if (this != &m) {
            strcpy(ime, m.ime);
            brZici = m.brZici;
            osnovnaCena = m.osnovnaCena;
            strcpy(forma, m.forma);
        }
        return *this;
    }

    ~Mandolina() {}

    float cena() {
        if (strcmp(forma, "Neapolitan") == 0) {
            return getOsnovnaCena() + (getOsnovnaCena() * 15 / 100);
        }
        return getOsnovnaCena();
    }

    bool operator==(Mandolina &m) {
        return getBrZici() == m.getBrZici();
    }

    friend ostream &operator<<(ostream &out, Mandolina &m) {
        out << m.ime << " " << m.brZici << " " << m.osnovnaCena << endl;
        return out;
    }
};

class Violina : public ZicanInstrument {
private:
    float golemina;
public:
    Violina() : ZicanInstrument() {}

    Violina(char *ime, int brZici, float osnovnaCena, float golemina) : ZicanInstrument(ime, brZici, osnovnaCena) {
        this->golemina = golemina;
    }

    Violina(const Violina &v) : ZicanInstrument(v) {
        golemina = v.golemina;
    }

    Violina operator=(const Violina &v) {
        if (this != &v) {
            strcpy(ime, v.ime);
            brZici = v.brZici;
            osnovnaCena = v.osnovnaCena;
            golemina = v.golemina;
        }
        return *this;
    }

    float cena() {
        if (golemina == 0.25) {
            return getOsnovnaCena() + (getOsnovnaCena() * 10 / 100);
        } else if (golemina == 1.00) {
            return getOsnovnaCena() + (getOsnovnaCena() * 20 / 100);
        }
        return getOsnovnaCena();

    }

    bool operator==(Violina &v) {
        return getBrZici() == v.getBrZici();
    }

    friend ostream &operator<<(ostream &out, Violina &v) {
        out << v.ime << " " << v.brZici << " " << v.osnovnaCena << endl;
        return out;
    }
};

void pecatiInstrumenti(ZicanInstrument &zi, ZicanInstrument **i, int n) {
    for (int j = 0; j < n; j++) {
        if (i[j]->getBrZici() == zi.getBrZici()) {
            cout << i[j]->cena() << endl;
        }
    }
}

int main() {
    char ime[20];
    int brojZici;
    float cena;
    char forma[20];
    cin >> ime >> brojZici >> cena >> forma;
    Mandolina m(ime, brojZici, cena, forma);
    int n;
    cin >> n;
    ZicanInstrument **zi = new ZicanInstrument *[2 * n];
    for (int i = 0; i < n; ++i) {
        cin >> ime >> brojZici >> cena >> forma;
        zi[i] = new Mandolina(ime, brojZici, cena, forma);
    }
    for (int i = 0; i < n; ++i) {
        float golemina;
        cin >> ime >> brojZici >> cena >> golemina;
        zi[n + i] = new Violina(ime, brojZici, cena, golemina);
    }
    pecatiInstrumenti(m, zi, 2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        delete zi[i];
    }
    delete[] zi;
    return 0;
}
