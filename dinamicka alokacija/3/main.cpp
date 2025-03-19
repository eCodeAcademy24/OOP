#include <iostream>
#include <cstring>

using namespace std;

enum zanr {
    akcija,
    komedija,
    drama
};

class Film {
private:
    char *ime;
    int memorija;
    zanr kojzanr;
public:
    Film() {
        memorija = 0;
        ime = new char[0];
    }

    Film(char *ime, int memorija, zanr kojzanr) {
        this->memorija = memorija;
        this->kojzanr = kojzanr;
        this->ime = new char[strlen(ime) + 1];
        strcpy(this->ime, ime);
    }

    Film(const Film &film) {
        memorija = film.memorija;
        kojzanr = film.kojzanr;
        ime = new char[strlen(film.ime) + 1];
        strcpy(ime, film.ime);
    }

    Film &operator=(const Film &film) {
        if (this != &film) {
            delete[] ime;
            memorija = film.memorija;
            kojzanr = film.kojzanr;
            ime = new char[strlen(film.ime) + 1];
            strcpy(ime, film.ime);
        }

        return *this;
    }

    ~Film() {
        delete[] ime;
    }

    int getMemorija() {
        return memorija;
    }

    zanr getZanr() {
        return kojzanr;
    }

    //20MB-"Up"
    void pecati() {
        cout << memorija << "MB-\"" << ime << "\"" << endl;
    }
};

class DVD {
private:
    Film film[5];
    int brFilmovi;
    int kapacitet;
public:
    DVD() {}

    DVD(int kapacitet) {
        this->kapacitet = kapacitet;
        brFilmovi = 0;
    }

    DVD(const DVD &dvd) {
        kapacitet = dvd.kapacitet;
        brFilmovi = dvd.brFilmovi;
        for (int i = 0; i < brFilmovi; i++) {
            film[i] = dvd.film[i];
        }
    }

    DVD &operator=(const DVD &dvd) {
        if (this != &dvd) {
            kapacitet = dvd.kapacitet;
            brFilmovi = dvd.brFilmovi;
            for (int i = 0; i < brFilmovi; i++) {
                film[i] = dvd.film[i];
            }
        }

        return *this;
    }

    ~DVD() {}

    int getBroj() {
        return brFilmovi;
    }

    Film &getFilm(int index) {
        return film[index];
    }

    int sumMemorija() {
        int sum = 0;
        for (int i = 0; i < brFilmovi; i++) {
            sum += film[i].getMemorija();
        }

        return sum;
    }

    int daliImaMesto(int novFilmMemorija) {
        return novFilmMemorija + sumMemorija();
    }

    void dodadiFilm(Film &f) {
        int mesto = daliImaMesto(f.getMemorija());

        if (brFilmovi < 5 && mesto <= kapacitet) {
            film[brFilmovi] = f;
            brFilmovi++;
        }
    }

    void pecatiFilmoviDrugZanr(zanr z) {
        for (int i = 0; i < brFilmovi; i++) {
            if (film[i].getZanr() != z) {
                film[i].pecati();
            }
        }
    }

    float procentNaMemorijaOdZanr(zanr z) {
        int sumZanr = 0;
        for (int i = 0; i < brFilmovi; i++) {
            if (film[i].getZanr() == z) {
                sumZanr += film[i].getMemorija();
            }
        }

        return ((float) sumZanr / sumMemorija()) * 100.0;
    }
};

int main() {
    // se testira zadacata modularno
    int testCase;
    cin >> testCase;

    int n, memorija, kojzanr;
    char ime[50];

    if (testCase == 1) {
        cout << "===== Testiranje na klasata Film ======" << endl;
        cin >> ime;
        cin >> memorija;
        cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
        Film f(ime, memorija, (zanr) kojzanr);
        f.pecati();
    } else if (testCase == 2) {
        cout << "===== Testiranje na klasata DVD ======" << endl;
        DVD omileno(50);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> memorija;
            cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
            Film f(ime, memorija, (zanr) kojzanr);
            omileno.dodadiFilm(f);
        }
        for (int i = 0; i < n; i++)
            (omileno.getFilm(i)).pecati();
    } else if (testCase == 3) {
        cout << "===== Testiranje na metodot dodadiFilm() od klasata DVD ======" << endl;
        DVD omileno(50);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> memorija;
            cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
            Film f(ime, memorija, (zanr) kojzanr);
            omileno.dodadiFilm(f);
        }
        for (int i = 0; i < omileno.getBroj(); i++)
            (omileno.getFilm(i)).pecati();
    } else if (testCase == 4) {
        cout << "===== Testiranje na metodot pecatiFilmoviDrugZanr() od klasata DVD ======" << endl;
        DVD omileno(50);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> memorija;
            cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
            Film f(ime, memorija, (zanr) kojzanr);
            omileno.dodadiFilm(f);
        }
        cin >> kojzanr;
        omileno.pecatiFilmoviDrugZanr((zanr) kojzanr);
    } else if (testCase == 5) {
        cout << "===== Testiranje na metodot pecatiFilmoviDrugZanr() od klasata DVD ======" << endl;
        DVD omileno(50);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> memorija;
            cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
            Film f(ime, memorija, (zanr) kojzanr);
            omileno.dodadiFilm(f);
        }
        cin >> kojzanr;
        omileno.pecatiFilmoviDrugZanr((zanr) kojzanr);
    } else if (testCase == 6) {
        cout << "===== Testiranje na metodot procentNaMemorijaOdZanr() od klasata DVD =====" << endl;
        DVD omileno(40);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> memorija;
            cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
            Film f(ime, memorija, (zanr) kojzanr);
            omileno.dodadiFilm(f);
        }
        cin >> kojzanr;
        cout << "Procent na filmovi od dadeniot zanr iznesuva: " << omileno.procentNaMemorijaOdZanr((zanr) kojzanr)
             << "%\n";
    }

    return 0;
}
