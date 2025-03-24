#include <iostream>
#include <cstring>

using namespace std;

class Ucesnik {
private:
    char *ime;
    bool pol;
    int vozrast;
public:
    Ucesnik() {
        ime = new char[0];
    }

    Ucesnik(char *ime, bool pol, int vozrast) {
        this->ime = new char[strlen(ime) + 1];
        strcpy(this->ime, ime);
        this->pol = pol;
        this->vozrast = vozrast;
    }

    Ucesnik(const Ucesnik &ucesnik) {
        ime = new char[strlen(ucesnik.ime) + 1];
        strcpy(ime, ucesnik.ime);
        pol = ucesnik.pol;
        vozrast = ucesnik.vozrast;
    }

    Ucesnik &operator=(const Ucesnik &ucesnik) {
        if (this != &ucesnik) {
            delete[] ime;
            ime = new char[strlen(ucesnik.ime) + 1];
            strcpy(ime, ucesnik.ime);
            pol = ucesnik.pol;
            vozrast = ucesnik.vozrast;
        }

        return *this;
    }

    ~Ucesnik() {
        delete[] ime;
    }

    int getVozrast() {
        return vozrast;
    }

    bool operator>(const Ucesnik &ucesnik) {
        return vozrast > ucesnik.vozrast;
    }

    friend ostream &operator<<(ostream &out, const Ucesnik &ucesnik) {
        out << ucesnik.ime << endl;
        if (ucesnik.pol) {
            out << "mashki" << endl;
        } else {
            out << "zhenski" << endl;
        }

        out << ucesnik.vozrast << endl;
        return out;
    }
};

class Maraton {
private:
    char lokacija[100];
    Ucesnik *array;
    int num;
public:
    Maraton() {
        array = new Ucesnik[0];
        num = 0;
    }

    Maraton(char *lokacija) {
        strcpy(this->lokacija, lokacija);
        array = new Ucesnik[0];
        num = 0;
    }

    Maraton(const Maraton &maraton) {
        strcpy(lokacija, maraton.lokacija);
        num = maraton.num;
        array = new Ucesnik[num];
        for (int i = 0; i < num; i++) {
            array[i] = maraton.array[i];
        }
    }

    Maraton &operator=(const Maraton &maraton) {
        if (this != &maraton) {
            delete[] array;
            strcpy(lokacija, maraton.lokacija);
            num = maraton.num;
            array = new Ucesnik[num];
            for (int i = 0; i < num; i++) {
                array[i] = maraton.array[i];
            }
        }

        return *this;
    }

    ~Maraton() {
        delete[] array;
    }

    Maraton &operator+=(const Ucesnik &other) {
        Ucesnik *tmp = new Ucesnik[num + 1];
        for (int i = 0; i < num; i++) {
            tmp[i] = array[i];
        }

        tmp[num] = other;
        delete[] array;
        ++num;
        array = new Ucesnik[num];
        array = tmp;
        return *this;
    }

    int sum() {
        int sum = 0;
        for (int i = 0; i < num; i++) {
            sum += array[i].getVozrast();
        }

        return sum;
    }

    double prosecnoVozrast() {
        return (double) sum() / num;
    }

    void pecatiPomladi(Ucesnik &ucesnik) {
        for (int i = 0; i < num; i++) {
            if (ucesnik > array[i]) {
                cout << array[i];
            }
        }
    }
};

int main() {
    char ime[100];
    bool maski;
    int vozrast, n;
    cin >> n;
    char lokacija[100];
    cin >> lokacija;
    Maraton m(lokacija);
    Ucesnik **u = new Ucesnik *[n];
    for (int i = 0; i < n; ++i) {
        cin >> ime >> maski >> vozrast;
        u[i] = new Ucesnik(ime, maski, vozrast);
        m += *u[i];
    }
    m.pecatiPomladi(*u[n - 1]);
    cout << m.prosecnoVozrast() << endl;
    for (int i = 0; i < n; ++i) {
        delete u[i];
    }
    delete[] u;
    return 0;
}
