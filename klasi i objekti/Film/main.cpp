#include <iostream>
#include <cstring>

using namespace std;

class Film {
private:
    char ime[100];
    char rezhiser[50];
    char zhanr[50];
    int godina;
public:
    Film() {}

    Film(char *ime, char *rezhiser, char *zhanr, int godina) {
        strcpy(this->ime, ime);
        strcpy(this->rezhiser, rezhiser);
        strcpy(this->zhanr, zhanr);
        this->godina = godina;
    }

    //TODO: make getter and setter methods for ime, rezhiser and zhanr

    int getGodina() {
        return godina;
    }

    //  Ime: Wall-E
    //  Reziser: Andrew_Stanton
    //  Zanr: Animation
    //  Godina: 2008
    void pecatiPodatociZaFilm() {
        cout << "Ime: " << ime << endl;
        cout << "Reziser: " << rezhiser << endl;
        cout << "Zanr: " << zhanr << endl;
        cout << "Godina: " << godina << endl;
    }
};

// [f("Frankenweenie", "Tim_Burton", "Animation", 2012), f("Lincoln", "Steven_Spielberg", "History", 2012)]
void pecati_po_godina(Film *filmovi, int n, int godina) {
    for (int i = 0; i < n; i++) {
        if (filmovi[i].getGodina() == godina) {
            filmovi[i].pecatiPodatociZaFilm();
        }
    }
}

int main() {
    int n;
    cin >> n;

    Film filmovi[n];

    for (int i = 0; i < n; i++) {
        char ime[100];
        char rezhiser[50];
        char zhanr[50];
        int godina;
        cin >> ime >> rezhiser >> zhanr >> godina;

        Film film(ime, rezhiser, zhanr, godina);
        filmovi[i] = film;
    }

    int godina;
    cin >> godina;

    pecati_po_godina(filmovi, n, godina);
    return 0;
}
