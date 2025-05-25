#include<iostream>
#include<cstring>

using namespace std;

class NoCourseException {
private:
    int indeks;
public:
    NoCourseException(int indeks) {
        this->indeks = indeks;
    }

    void message() {
        cout << "Demonstratorot so indeks " << indeks << " ne drzi laboratoriski vezbi" << endl;
    }
};

class Kurs {
private:
    char ime[20];
    int krediti;
public:
    Kurs() {
        strcpy(this->ime, "");
        krediti = 0;
    }

    Kurs(char *ime, int krediti) {
        strcpy(this->ime, ime);
        this->krediti = krediti;
    }

    char *getIme() {
        return ime;
    }

    void pecati() {
        cout << ime << " " << krediti << " ECTS";
    }
};

class Student {
protected:
    int indeks;
    int *ocenki;
    int brOcenki;
public:
    Student() {
        ocenki = new int[0];
        brOcenki = 0;
    }

    Student(int indeks, int *ocenki, int brOcenki) {
        this->indeks = indeks;
        this->brOcenki = brOcenki;
        this->ocenki = new int[brOcenki];
        for (int i = 0; i < brOcenki; i++) {
            this->ocenki[i] = ocenki[i];
        }
    }

    Student(const Student &student) {
        indeks = student.indeks;
        brOcenki = student.brOcenki;
        ocenki = new int[brOcenki];
        for (int i = 0; i < brOcenki; i++) {
            ocenki[i] = student.ocenki[i];
        }
    }

    Student &operator=(const Student &student) {
        if (this != &student) {
            delete[] ocenki;
            indeks = student.indeks;
            brOcenki = student.brOcenki;
            ocenki = new int[brOcenki];
            for (int i = 0; i < brOcenki; i++) {
                ocenki[i] = student.ocenki[i];
            }
        }

        return *this;
    }

    ~Student() {
        delete[] ocenki;
    }

    virtual int getBodovi() {
        int counter = 0;
        for (int i = 0; i < brOcenki; i++) {
            if (ocenki[i] > 5) {
                counter++;
            }
        }

        return (counter * 100) / brOcenki;
    }

    virtual void pecati() {
        cout << indeks;
    }
};

class Predavach {
protected:
    char *ime;
    Kurs kursevi[10];
    int brKursevi;
public:
    Predavach() {
        ime = new char[0];
    }

    Predavach(char *ime, Kurs *kursevi, int brKursevi) {
        this->ime = new char[strlen(ime) + 1];
        strcpy(this->ime, ime);
        this->brKursevi = brKursevi;
        for (int i = 0; i < brKursevi; i++) {
            this->kursevi[i] = kursevi[i];
        }
    }

    Predavach(const Predavach &pr) {
        ime = new char[strlen(pr.ime) + 1];
        strcpy(ime, pr.ime);
        brKursevi = pr.brKursevi;
        for (int i = 0; i < brKursevi; i++) {
            kursevi[i] = pr.kursevi[i];
        }
    }

    Predavach &operator=(const Predavach &pr) {
        if (this != &pr) {
            delete[] ime;
            ime = new char[strlen(pr.ime) + 1];
            strcpy(ime, pr.ime);
            brKursevi = pr.brKursevi;
            for (int i = 0; i < brKursevi; i++) {
                kursevi[i] = pr.kursevi[i];
            }
        }

        return *this;
    }

    ~Predavach() {
        delete[] ime;
    }

    int getBrojKursevi() {
        return brKursevi;
    }

    Kurs operator[](int i) {
        if (i < brKursevi && i >= 0) {
            return kursevi[i];
        }

        return Kurs();
    }
};

class Demonstrator : public Student, public Predavach {
private:
    int brChasovi;
public:
    Demonstrator(int indeks, int *ocenki, int brOcenki, char *ime, Kurs *kursevi, int brKursevi, int brChasovi)
            : Student(indeks, ocenki, brOcenki), Predavach(ime, kursevi, brKursevi) {
        this->brChasovi = brChasovi;
    }

    int getBodovi() {
        int osnovniBodovi = Student::getBodovi();
        if (brKursevi == 0) {
            throw NoCourseException(indeks);
        }

        return osnovniBodovi + ((20 * brChasovi) / brKursevi);
    }

    void pecati() {
        Student::pecati();
        cout << ": " << ime << " (";
        for (int i = 0; i < brKursevi; i++) {
            kursevi[i].pecati();
            if (i < brKursevi - 1)
                cout << ", ";
            else
                cout << ")";
        }
    }
};

Student &vratiNajdobroRangiran(Student **studenti, int n) {
    Student *najdobarStudent = studenti[0];

    for (int i = 0; i < n; i++) {
        int bodovi = 0;

        try {
            bodovi = studenti[i]->getBodovi();
        } catch (NoCourseException &nce) {
            nce.message();
        }

        if (bodovi > najdobarStudent->getBodovi()) {
            najdobarStudent = studenti[i];
        }
    }

    return *najdobarStudent;
}

void pecatiDemonstratoriKurs(char *kurs, Student **studenti, int n) {
    for (int i = 0; i < n; i++) {
        Demonstrator *demonstrator = dynamic_cast<Demonstrator *>(studenti[i]);
        if (demonstrator) {
            for (int j = 0; j < demonstrator->getBrojKursevi(); j++) {
                if (strcmp(demonstrator->operator[](j).getIme(), kurs) == 0) {
                    demonstrator->pecati();
                    cout << endl;
                    break;
                }
            }
        }
    }
}

int main() {
    Kurs kursevi[10];
    int indeks, brojKursevi, ocenki[20], ocenka, brojOcenki, tip, brojCasovi, krediti;
    char ime[20], imeIPrezime[50];

    cin >> tip;

    if (tip == 1) //test class Demonstrator
    {
        cout << "-----TEST Demonstrator-----" << endl;
        cin >> indeks >> brojOcenki;
        for (int i = 0; i < brojOcenki; i++) {
            cin >> ocenka;
            ocenki[i] = ocenka;
        }
        cin >> imeIPrezime >> brojKursevi;
        for (int i = 0; i < brojKursevi; i++) {
            cin >> ime >> krediti;
            kursevi[i] = Kurs(ime, krediti);
        }
        cin >> brojCasovi;

        Demonstrator d(indeks, ocenki, brojOcenki, imeIPrezime, kursevi, brojKursevi, brojCasovi);
        cout << "Objekt od klasata Demonstrator e kreiran";
    } else if (tip == 2) //funkcija pecati vo Student
    {
        cout << "-----TEST pecati-----" << endl;
        cin >> indeks >> brojOcenki;
        for (int i = 0; i < brojOcenki; i++) {
            cin >> ocenka;
            ocenki[i] = ocenka;
        }

        Student s(indeks, ocenki, brojOcenki);
        s.pecati();
    } else if (tip == 3) //funkcija getVkupnaOcenka vo Student
    {
        cout << "-----TEST getVkupnaOcenka-----" << endl;
        cin >> indeks >> brojOcenki;
        for (int i = 0; i < brojOcenki; i++) {
            cin >> ocenka;
            ocenki[i] = ocenka;
        }
        Student s(indeks, ocenki, brojOcenki);
        cout << "Broj na bodovi: " << s.getBodovi() << endl;
    } else if (tip == 4) //funkcija getVkupnaOcenka vo Demonstrator
    {
        cout << "-----TEST getVkupnaOcenka-----" << endl;
        cin >> indeks >> brojOcenki;
        for (int i = 0; i < brojOcenki; i++) {
            cin >> ocenka;
            ocenki[i] = ocenka;
        }
        cin >> imeIPrezime >> brojKursevi;
        for (int i = 0; i < brojKursevi; i++) {
            cin >> ime >> krediti;
            kursevi[i] = Kurs(ime, krediti);
        }
        cin >> brojCasovi;

        Demonstrator d(indeks, ocenki, brojOcenki, imeIPrezime, kursevi, brojKursevi, brojCasovi);
        cout << "Broj na bodovi: " << d.getBodovi() << endl;
    } else if (tip == 5) //funkcija pecati vo Demonstrator
    {
        cout << "-----TEST pecati -----" << endl;
        cin >> indeks >> brojOcenki;
        for (int i = 0; i < brojOcenki; i++) {
            cin >> ocenka;
            ocenki[i] = ocenka;
        }
        cin >> imeIPrezime >> brojKursevi;
        for (int i = 0; i < brojKursevi; i++) {
            cin >> ime >> krediti;
            kursevi[i] = Kurs(ime, krediti);
        }
        cin >> brojCasovi;

        Demonstrator d(indeks, ocenki, brojOcenki, imeIPrezime, kursevi, brojKursevi, brojCasovi);
        d.pecati();
    } else if (tip == 6) //site klasi
    {
        cout << "-----TEST Student i Demonstrator-----" << endl;
        cin >> indeks >> brojOcenki;
        for (int i = 0; i < brojOcenki; i++) {
            cin >> ocenka;
            ocenki[i] = ocenka;
        }
        cin >> imeIPrezime >> brojKursevi;
        for (int i = 0; i < brojKursevi; i++) {
            cin >> ime >> krediti;
            kursevi[i] = Kurs(ime, krediti);
        }
        cin >> brojCasovi;

        Student *s = new Demonstrator(indeks, ocenki, brojOcenki, imeIPrezime, kursevi, brojKursevi, brojCasovi);
        s->pecati();
        cout << "\nBroj na bodovi: " << s->getBodovi() << endl;
        delete s;
    } else if (tip == 7) //funkcija vratiNajdobroRangiran
    {
        cout << "-----TEST vratiNajdobroRangiran-----" << endl;
        int k, opt;
        cin >> k;
        Student **studenti = new Student *[k];
        for (int j = 0; j < k; j++) {
            cin >> opt; //1 Student 2 Demonstrator
            cin >> indeks >> brojOcenki;
            for (int i = 0; i < brojOcenki; i++) {
                cin >> ocenka;
                ocenki[i] = ocenka;
            }
            if (opt == 1) {
                studenti[j] = new Student(indeks, ocenki, brojOcenki);
            } else {
                cin >> imeIPrezime >> brojKursevi;
                for (int i = 0; i < brojKursevi; i++) {
                    cin >> ime >> krediti;
                    kursevi[i] = Kurs(ime, krediti);
                }
                cin >> brojCasovi;
                studenti[j] = new Demonstrator(indeks, ocenki, brojOcenki, imeIPrezime, kursevi, brojKursevi,
                                               brojCasovi);
            }
        }
        Student &najdobar = vratiNajdobroRangiran(studenti, k);
        cout << "Maksimalniot broj na bodovi e:" << najdobar.getBodovi();
        cout << "\nNajdobro rangiran:";
        najdobar.pecati();

        for (int j = 0; j < k; j++) delete studenti[j];
        delete[] studenti;
    } else if (tip == 8) //funkcija pecatiDemonstratoriKurs
    {
        cout << "-----TEST pecatiDemonstratoriKurs-----" << endl;
        int k, opt;
        cin >> k;
        Student **studenti = new Student *[k];
        for (int j = 0; j < k; j++) {
            cin >> opt; //1 Student 2 Demonstrator
            cin >> indeks >> brojOcenki;
            for (int i = 0; i < brojOcenki; i++) {
                cin >> ocenka;
                ocenki[i] = ocenka;
            }
            if (opt == 1) {
                studenti[j] = new Student(indeks, ocenki, brojOcenki);
            } else {
                cin >> imeIPrezime >> brojKursevi;
                for (int i = 0; i < brojKursevi; i++) {
                    cin >> ime >> krediti;
                    kursevi[i] = Kurs(ime, krediti);
                }
                cin >> brojCasovi;
                studenti[j] = new Demonstrator(indeks, ocenki, brojOcenki, imeIPrezime, kursevi, brojKursevi,
                                               brojCasovi);
            }
        }
        char kurs[20];
        cin >> kurs;
        cout << "Demonstratori na " << kurs << " se:" << endl;
        pecatiDemonstratoriKurs(kurs, studenti, k);
        for (int j = 0; j < k; j++) delete studenti[j];
        delete[] studenti;
    }


    return 0;
}
