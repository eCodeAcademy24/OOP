#include <iostream>
#include <cstring>

using namespace std;

class PlDrustvo {
private:
    char *ime;
    int brTuri;
    int brClenovi;
public:
    PlDrustvo() {
        brClenovi = 0;
        brTuri = 0;
        ime = new char[0];
    }

    PlDrustvo(char *ime, int brTuri, int brClenovi) {
        this->ime = new char[strlen(ime) + 1];
        strcpy(this->ime, ime);
        this->brTuri = brTuri;
        this->brClenovi = brClenovi;
    }

    PlDrustvo(const PlDrustvo &pld) {
        ime = new char[strlen(pld.ime) + 1];
        strcpy(ime, pld.ime);
        brTuri = pld.brTuri;
        brClenovi = pld.brClenovi;
    }

    PlDrustvo &operator=(const PlDrustvo &pld) {
        if (this != &pld) {
            delete[] ime;
            ime = new char[strlen(pld.ime) + 1];
            strcpy(ime, pld.ime);
            brTuri = pld.brTuri;
            brClenovi = pld.brClenovi;
        }

        return *this;
    }

    ~PlDrustvo() {
        delete[] ime;
    }

    PlDrustvo operator+(const PlDrustvo &other) {
        PlDrustvo nov;
        nov.brClenovi = this->brClenovi + other.brClenovi;

        if (this->brClenovi > other.brClenovi) {
            nov.ime = new char[strlen(this->ime) + 1];
            strcpy(nov.ime, this->ime);
            nov.brTuri = this->brTuri;
        } else if (this->brClenovi < other.brClenovi) {
            nov.ime = new char[strlen(other.ime) + 1];
            strcpy(nov.ime, other.ime);
            nov.brTuri = other.brTuri;
        }

        return nov;
    }

    bool operator>(const PlDrustvo &other) {
        return brClenovi > other.brClenovi;
    }

    bool operator<(const PlDrustvo &other) {
        return brClenovi < other.brClenovi;
    }

    friend ostream &operator<<(ostream &out, const PlDrustvo &other) {
        // Ime: Kozuv Turi: 15 Clenovi: 164
        out << "Ime: " << other.ime << " Turi: " << other.brTuri << " Clenovi: " << other.brClenovi << endl;
        return out;
    }
};

void najmnoguClenovi(PlDrustvo *drustva, int n) {
    PlDrustvo maxDrustvo = drustva[0];
    for (int i = 1; i < n; i++) {
        if (maxDrustvo < drustva[i]) {
            maxDrustvo = drustva[i];
        }
    }

    cout << "Najmnogu clenovi ima planinarskoto drustvo: " << maxDrustvo;
}

int main() {

    PlDrustvo drustva[3];
    PlDrustvo pl;
    for (int i = 0; i < 3; i++) {
        char ime[100];
        int brTuri;
        int brClenovi;
        cin >> ime;
        cin >> brTuri;
        cin >> brClenovi;
        PlDrustvo p(ime, brTuri, brClenovi);
        drustva[i] = p;
    }

    pl = drustva[0] + drustva[1];
    cout << pl;

    najmnoguClenovi(drustva, 3);
    return 0;
}
