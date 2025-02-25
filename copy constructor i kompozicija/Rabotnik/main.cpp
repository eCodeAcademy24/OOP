#include <iostream>
#include <cstring>

using namespace std;

class Rabotnik {
private:
    char ime[30];
    char prezime[30];
    int plata;
public:
    Rabotnik() {}

    Rabotnik(char *ime, char *prezime, int plata) {
        strcpy(this->ime, ime);
        strcpy(this->prezime, prezime);
        this->plata = plata;
    }

    ~Rabotnik() {}

    int getPlata() {
        return plata;
    }

    void pecati() {
        cout << ime << " " << prezime << " " << plata << endl;
    }
};

class Fabrika {
private:
    Rabotnik rabotnici[100];
    int brojVraboteni;
public:
    Fabrika() {}

    Fabrika(Rabotnik *rabotnici, int brojVraboteni) {
        this->brojVraboteni = brojVraboteni;
        for (int i = 0; i < brojVraboteni; i++) {
            this->rabotnici[i] = rabotnici[i];
        }
    }

    Fabrika(const Fabrika &fabrika) {
        brojVraboteni = fabrika.brojVraboteni;
        for (int i = 0; i < brojVraboteni; i++) {
            this->rabotnici[i] = fabrika.rabotnici[i];
        }
    }

    ~Fabrika() {}

    void pecatiVraboteni() {
        for (int i = 0; i < brojVraboteni; i++) {
            rabotnici[i].pecati();
        }
    }

    void pecatiSoPlata(int plata) {
        for (int i = 0; i < brojVraboteni; i++) {
            if (rabotnici[i].getPlata() >= plata) {
                rabotnici[i].pecati();
            }
        }
    }
};

int main() {
    int n;
    cin >> n;

    Rabotnik rabotnici[100];
    for (int i = 0; i < n; i++) {
        char ime[30], prezime[30];
        int plata;
        cin >> ime >> prezime >> plata;
        rabotnici[i] = Rabotnik(ime, prezime, plata);;
    }

    Fabrika fabrika(rabotnici, n);

    int minPlata;
    cin >> minPlata;

    cout << "Site vraboteni:" << endl;
    fabrika.pecatiVraboteni();

    cout << "Vraboteni so plata povisoka od " << minPlata << ":" << endl;
    fabrika.pecatiSoPlata(minPlata);
    return 0;
}
