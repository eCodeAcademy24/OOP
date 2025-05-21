#include <iostream>
#include <cstring>

using namespace std;

class Lekar {
protected:
    int faksimil;
    char ime[10];
    char prezime[15];
    float osnovnaPlata;
public:
    Lekar() {}

    Lekar(int faksimil, char *ime, char *prezime, float osnovnaPlata) {
        this->faksimil = faksimil;
        strcpy(this->ime, ime);
        strcpy(this->prezime, prezime);
        this->osnovnaPlata = osnovnaPlata;
    }

    Lekar(const Lekar &le) {
        faksimil = le.faksimil;
        strcpy(ime, le.ime);
        strcpy(prezime, le.prezime);
        osnovnaPlata = le.osnovnaPlata;
    }

    void pecati() {
        cout << faksimil << ": " << ime << " " << prezime << endl;
    }

    double plata() {
        return osnovnaPlata;
    }
};

class MaticenLekar : public Lekar {
private:
    int brPacienti;
    double *kotizacii;
public:
    MaticenLekar() : Lekar() {
        kotizacii = new double[0];
        brPacienti = 0;
    }

    MaticenLekar(Lekar l, int brPacienti, double *kotizacii) : Lekar(l) {
        this->brPacienti = brPacienti;
        this->kotizacii = new double[brPacienti];
        for (int i = 0; i < brPacienti; i++) {
            this->kotizacii[i] = kotizacii[i];
        }
    }

    MaticenLekar(const MaticenLekar &ml) : Lekar(ml) {
        brPacienti = ml.brPacienti;
        kotizacii = new double[ml.brPacienti];
        for (int i = 0; i < ml.brPacienti; i++) {
            kotizacii[i] = ml.kotizacii[i];
        }
    }

    MaticenLekar operator=(const MaticenLekar &ml) {
        if (this != &ml) {
            delete[] kotizacii;
            faksimil = ml.faksimil;
            strcpy(ime, ml.ime);
            strcpy(prezime, ml.prezime);
            osnovnaPlata = ml.osnovnaPlata;
            brPacienti = ml.brPacienti;
            kotizacii = new double[ml.brPacienti];
            for (int i = 0; i < ml.brPacienti; i++) {
                kotizacii[i] = ml.kotizacii[i];
            }
        }
        return *this;
    }

    ~MaticenLekar() {
        delete[] kotizacii;
    }

    double prosek() {
        double suma = 0.0;
        for (int i = 0; i < brPacienti; i++) {
            suma += kotizacii[i];
        }
        return suma / brPacienti * 1.0;
    }

    void pecati() {
        Lekar::pecati();
        cout << "Prosek na kotizacii: " << prosek() << endl;
    }

    double plata() {
        return Lekar::plata() + 0.3 * prosek();
    }

};

int main() {
    int n;
    cin >> n;
    int pacienti;
    double kotizacii[100];
    int faksimil;
    char ime[20];
    char prezime[20];
    double osnovnaPlata;

    Lekar *lekari = new Lekar[n];
    MaticenLekar *maticni = new MaticenLekar[n];

    for (int i = 0; i < n; i++) {
        cin >> faksimil >> ime >> prezime >> osnovnaPlata;
        lekari[i] = Lekar(faksimil, ime, prezime, osnovnaPlata);
    }

    for (int i = 0; i < n; i++) {
        cin >> pacienti;
        for (int j = 0; j < pacienti; j++) {
            cin >> kotizacii[j];
        }
        maticni[i] = MaticenLekar(lekari[i], pacienti, kotizacii);
    }

    int testCase;
    cin >> testCase;

    if (testCase == 1) {
        cout << "===TESTIRANJE NA KLASATA LEKAR===" << endl;
        for (int i = 0; i < n; i++) {
            lekari[i].pecati();
            cout << "Osnovnata plata na gorenavedeniot lekar e: " << lekari[i].plata() << endl;
        }
    } else {
        cout << "===TESTIRANJE NA KLASATA MATICENLEKAR===" << endl;
        for (int i = 0; i < n; i++) {
            maticni[i].pecati();
            cout << "Platata na gorenavedeniot maticen lekar e: " << maticni[i].plata() << endl;
        }
    }

    delete[] lekari;
    delete[] maticni;

    return 0;
}
