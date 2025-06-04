#include <iostream>
#include <fstream>


using namespace std;

void wtf() {
    ofstream fout("vlezna.txt");
    string line;
    while (getline(std::cin, line)) {
        if (line == "----") {
            break;
        }
        fout << line << endl;
    }
}

void rff(string path) {
    ifstream fin(path);
    string line;
    while (getline(fin, line)) {
        cout << line << endl;
    }
}

class EmptyListException {
public:
    EmptyListException() {}

    void print() {
        cout << "Trying to delete from an empty list!" << endl;
    }
};

class Song {
private:
    string naslov;
    string imePrezime;
    string izveduvac;
    int vremetraenje;
public:

    Song() {
        naslov = imePrezime = izveduvac = "";
        vremetraenje = 0;
    }

    string getNaslov() {
        return naslov;
    }

    string getImePrezime() {
        return imePrezime;
    }

    string getIzveduvac() {
        return izveduvac;
    }

    int getVremetraenje() {
        return vremetraenje;
    }

    friend istream &operator>>(istream &in, Song &song) {
        getline(in, song.naslov);
        getline(in, song.imePrezime);
        getline(in, song.izveduvac);
        in >> song.vremetraenje;
        in.ignore();
        return in;
    }

    void print(ofstream &out) {
        out << "Song title: " << naslov << ", Author: " << imePrezime << ", Interpreted by: " << izveduvac
            << ", " << vremetraenje << " sek." << endl;
    }
};

class Festival {
private:
    string ime;
    string grad;
    string datum;
    Song *pesni;
    int n;

public:
    Festival() {
        ime = grad = datum = "";
        n = 0;
        pesni = new Song[0];
    }

    Festival(const Festival &festival) {
        ime = festival.ime;
        grad = festival.grad;
        datum = festival.datum;
        n = festival.n;
        pesni = new Song[n];
        for (int i = 0; i < n; i++) {
            pesni[i] = festival.pesni[i];
        }
    }

    Festival &operator=(const Festival &festival) {
        if (this != &festival) {
            delete[] pesni;
            ime = festival.ime;
            grad = festival.grad;
            datum = festival.datum;
            n = festival.n;
            pesni = new Song[n];
            for (int i = 0; i < n; i++) {
                pesni[i] = festival.pesni[i];
            }
        }
        return *this;
    }

    ~Festival() {
        delete[] pesni;
    }

    Festival &operator-=(Song &song) {
        if (n == 0) {
            throw EmptyListException();
        }

        int nov = 0;
        for (int i = 0; i < n; i++) {
            if (!(pesni[i].getNaslov() == song.getNaslov() && pesni[i].getIzveduvac() == song.getIzveduvac() &&
                  pesni[i].getImePrezime() == song.getImePrezime() &&
                  pesni[i].getVremetraenje() == song.getVremetraenje())) {
                nov++;
            }
        }

        Song *tmp = new Song[nov];
        for (int i = 0, j = 0; i < n; i++) {
            if (!(pesni[i].getNaslov() == song.getNaslov() && pesni[i].getIzveduvac() == song.getIzveduvac() &&
                  pesni[i].getImePrezime() == song.getImePrezime() &&
                  pesni[i].getVremetraenje() == song.getVremetraenje())) {
                tmp[j] = pesni[i];
                j++;
            }
        }

        delete[] pesni;
        pesni = tmp;
        n = nov;
        return *this;
    }

    void print(ofstream &out) {
        out << "Festival: " << ime << " - " << grad << ", " << datum << endl;
        for (int i = 0; i < n; i++) {
            pesni[i].print(out);
        }
    }

    friend istream &operator>>(istream &in, Festival &festival) {
        getline(in, festival.ime);
        getline(in, festival.grad);
        getline(in, festival.datum);
        in >> festival.n;
        in.ignore();
        festival.pesni = new Song[festival.n];
        for (int i = 0; i < festival.n; i++) {
            in >> festival.pesni[i];
        }

        return in;
    }

    Festival notFromAuthor(string author) {
        Festival tmp = *this;

        try {
            if (n == 0) {
                Song song;
                tmp -= song;
            }

            for (int i = 0; i < n; i++) {
                if (pesni[i].getImePrezime() == author) {
                    tmp -= pesni[i];
                }
            }
        } catch (EmptyListException &e) {
            e.print();
        }


        return tmp;
    }
};

int main() {

    wtf();

    Festival festival;
    //TODO your code here
    //TODO Read the data from the file and store them in `festival`
    ifstream in("vlezna.txt");
    in >> festival;

    in.close();
    //DO NOT MODIFY THE CODE BETWEEN THIS AND THE NEXT COMMENT
    string author;
    getline(cin, author);
    //DO NOT MODIFY THE CODE BETWEEN THIS AND THE PREVIOUS COMMENT

    ofstream out1("izlezna1.txt");
    ofstream out2("izlezna2.txt");
    //TODO Save the results in the files izlezna1.txt and izlezna2.txt after this line
    festival.print(out1);

    Festival tmp = festival.notFromAuthor(author);
    tmp.print(out2);

    out1.close();
    out2.close();
    //DO NOT MODIFY THE CODE BELLOW

    cout << "All the data for the festival:" << endl;
    rff("izlezna1.txt");
    cout << "Songs NOT from the author " << author << ": " << endl;
    rff("izlezna2.txt");


    return 0;
}