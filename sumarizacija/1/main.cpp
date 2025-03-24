#include <iostream>
#include <cstring>

using namespace std;

class Gitara {
private:
    char seriski[25];
    double nabavnaCena;
    int godina;
    char tip[40];
public:
    Gitara() {}

    Gitara(char *tip, char *seriski, int godina, int nabavnaCena) {
        strcpy(this->tip, tip);
        strcpy(this->seriski, seriski);
        this->godina = godina;
        this->nabavnaCena = nabavnaCena;
    }

    Gitara(const Gitara &gitara) {
        strcpy(tip, gitara.tip);
        strcpy(seriski, gitara.seriski);
        godina = gitara.godina;
        nabavnaCena = gitara.nabavnaCena;
    }

    ~Gitara() {}

    bool daliIsti(Gitara &gitara) {
        return !strcmp(seriski, gitara.seriski);
    }

    void pecati() {
        cout << seriski << " " << tip << " " << nabavnaCena << endl;
    }

    char *getSeriski() {
        return seriski;
    }

    double getNabavna() {
        return nabavnaCena;
    }

    int getGodina() {
        return godina;
    }

    char *getTip() {
        return tip;
    }
};

class Magacin {
private:
    char ime[30];
    char lokacija[60];
    Gitara *gitari;
    int brGitari;
    int godinaOtvaranje;
public:
    Magacin() {
        gitari = new Gitara[0];
        brGitari = 0;
    }

    Magacin(char *ime, char *lokacija) {
        strcpy(this->ime, ime);
        strcpy(this->lokacija, lokacija);
        this->godinaOtvaranje = 0;
        gitari = new Gitara[0];
        brGitari = 0;
    }

    Magacin(char *ime, char *lokacija, int godinaOtvaranje) {
        strcpy(this->ime, ime);
        strcpy(this->lokacija, lokacija);
        this->godinaOtvaranje = godinaOtvaranje;
        gitari = new Gitara[0];
        brGitari = 0;
    }

    Magacin(const Magacin &magacin) {
        strcpy(ime, magacin.ime);
        strcpy(lokacija, magacin.lokacija);
        godinaOtvaranje = magacin.godinaOtvaranje;
        brGitari = magacin.brGitari;
        gitari = new Gitara[brGitari];
        for (int i = 0; i < brGitari; i++) {
            gitari[i] = magacin.gitari[i];
        }
    }

    Magacin &operator=(const Magacin &magacin) {
        if (this != &magacin) {
            delete[] gitari;
            strcpy(ime, magacin.ime);
            strcpy(lokacija, magacin.lokacija);
            godinaOtvaranje = magacin.godinaOtvaranje;
            brGitari = magacin.brGitari;
            gitari = new Gitara[brGitari];
            for (int i = 0; i < brGitari; i++) {
                gitari[i] = magacin.gitari[i];
            }
        }

        return *this;
    }

    ~Magacin() {
        delete[] gitari;
    }

    double vrednost() {
        double sum = 0;
        for (int i = 0; i < brGitari; i++) {
            sum += gitari[i].getNabavna();
        }

        return sum;
    }

    void dodadi(Gitara &gitara) {
        Gitara *tmp = new Gitara[brGitari + 1];
        for (int i = 0; i < brGitari; i++) {
            tmp[i] = gitari[i];
        }

        tmp[brGitari] = gitara;
        delete[] gitari;
        brGitari++;
        gitari = tmp;
    }

    void prodadi(Gitara &gitara) {
        int novaBrGitari = 0;
        for (int i = 0; i < brGitari; i++) {
            if (!gitari[i].daliIsti(gitara)) {
                ++novaBrGitari;
            }
        }

        Gitara *tmp = new Gitara[novaBrGitari];
        int index = 0;
        for (int i = 0; i < brGitari; i++) {
            if (!gitari[i].daliIsti((gitara))) {
                tmp[index] = gitari[i];
                index++;
            }
        }

        delete[] gitari;
        gitari = tmp;
        brGitari = novaBrGitari;
    }

    void pecati(bool daliNovi) {
        cout << ime << " " << lokacija << endl;
        for (int i = 0; i < brGitari; i++) {
            if (daliNovi && gitari[i].getGodina() > godinaOtvaranje) {
                gitari[i].pecati();
            } else if (!daliNovi) {
                gitari[i].pecati();
            }
        }
    }
};

int main() {
    // se testira zadacata modularno
    int testCase;
    cin >> testCase;

    int n, godina;
    float cena;
    char seriski[50], tip[50];

    if (testCase == 1) {
        cout << "===== Testiranje na klasata Gitara ======" << endl;
        cin >> tip;
        cin >> seriski;
        cin >> godina;
        cin >> cena;
        Gitara g(tip, seriski, godina, cena);
        cout << g.getTip() << endl;
        cout << g.getSeriski() << endl;
        cout << g.getGodina() << endl;
        cout << g.getNabavna() << endl;
    } else if (testCase == 2) {
        cout << "===== Testiranje na klasata Magacin so metodot print() ======" << endl;
        Magacin kb("Magacin1", "Lokacija1");
        kb.pecati(false);
    } else if (testCase == 3) {
        cout << "===== Testiranje na klasata Magacin so metodot dodadi() ======" << endl;
        Magacin kb("Magacin1", "Lokacija1", 2005);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tip;
            cin >> seriski;
            cin >> godina;
            cin >> cena;
            Gitara g(tip, seriski, godina, cena);
            cout << "gitara dodadi" << endl;
            kb.dodadi(g);
        }
        kb.pecati(true);
    } else if (testCase == 4) {
        cout << "===== Testiranje na klasata Magacin so metodot prodadi() ======" << endl;
        Magacin kb("Magacin1", "Lokacija1", 2012);
        cin >> n;
        Gitara brisi;
        for (int i = 0; i < n; i++) {
            cin >> tip;
            cin >> seriski;
            cin >> godina;
            cin >> cena;

            Gitara g(tip, seriski, godina, cena);
            if (i == 2)
                brisi = g;
            cout << "gitara dodadi" << endl;
            kb.dodadi(g);
        }
        kb.pecati(false);
        kb.prodadi(brisi);
        kb.pecati(false);
    } else if (testCase == 5) {
        cout << "===== Testiranje na klasata Magacin so metodot prodadi() i pecati(true) ======" << endl;
        Magacin kb("Magacin1", "Lokacija1", 2011);
        cin >> n;
        Gitara brisi;
        for (int i = 0; i < n; i++) {
            cin >> tip;
            cin >> seriski;
            cin >> godina;
            cin >> cena;

            Gitara g(tip, seriski, godina, cena);
            if (i == 2)
                brisi = g;
            cout << "gitara dodadi" << endl;
            kb.dodadi(g);
        }
        kb.pecati(true);
        kb.prodadi(brisi);
        cout << "Po brisenje:" << endl;
        Magacin kb3;
        kb3 = kb;
        kb3.pecati(true);
    } else if (testCase == 6) {
        cout << "===== Testiranje na klasata Magacin so metodot vrednost()======" << endl;
        Magacin kb("Magacin1", "Lokacija1", 2011);
        cin >> n;
        Gitara brisi;
        for (int i = 0; i < n; i++) {
            cin >> tip;
            cin >> seriski;
            cin >> godina;
            cin >> cena;

            Gitara g(tip, seriski, godina, cena);
            if (i == 2)
                brisi = g;
            kb.dodadi(g);
        }
        cout << kb.vrednost() << endl;
        kb.prodadi(brisi);
        cout << "Po brisenje:" << endl;
        cout << kb.vrednost();
        Magacin kb3;
        kb3 = kb;
    }
    return 0;
}
