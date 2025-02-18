#include <iostream>
#include <cstring>

using namespace std;

class Chovek {
private:
    char ime[50];
    char prezime[50];
    int godini;
    long long EMBG;
public:
    Chovek() {
        strcpy(ime, "Nepoznato");
        strcpy(prezime, "Nepoznato");
        godini = 0;
        EMBG = 0000000000000;
    }

    Chovek(char *ime, char *prezime, int godini, long long EMBG) {
        strcpy(this->ime, ime);
        strcpy(this->prezime, prezime);
        this->godini = godini;
        this->EMBG = EMBG;
    }

    ~Chovek() {}

    char *getIme() {
        return ime;
    }

    char *getPrezime() {
        return prezime;
    }

    int getGodini() {
        return godini;
    }

    long long getEmbg() {
        return EMBG;
    }

    void setIme(char *ime) {
        strcpy(this->ime, ime);
    }

    void setPrezime(char *prezime) {
        strcpy(this->prezime, prezime);
    }

    void setGodini(int godini) {
        this->godini = godini;
    }

    void setEmbg(long long EMBG) {
        this->EMBG = EMBG;
    }

    void pecatiPodatoci() {
        cout << ime << " " << prezime << " " << godini << " " << EMBG << endl;
    }
};

int main() {
    Chovek chovek;
    cout << "Default" << endl;
    chovek.pecatiPodatoci();

    chovek.setIme("Ecode");
    chovek.setPrezime("MK");
    chovek.setGodini(30);
    chovek.setEmbg(1234567890123);

    cout << "Updated" << endl;
    chovek.pecatiPodatoci();

    Chovek chovek1("Jovan", "Srbinovski", 25, 2345678900123);
    chovek1.pecatiPodatoci();

    cout << "So pomosh na getteri" << endl;
    cout << chovek1.getIme() << " " << chovek1.getPrezime() << " " << chovek1.getGodini() << " " << chovek1.getEmbg()
         << endl;
    return 0;
}
