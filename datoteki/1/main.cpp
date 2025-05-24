#include <fstream>
#include <iostream>

using namespace std;

void wtf() {
    ofstream fout("input.txt");
    string line;
    while (getline(cin, line)) {
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

class StudentFailedException {
private:
    string id;
public:
    StudentFailedException(string id) {
        this->id = id;
    }

    void message() {
        cout << "Student with id " << id << " failed the course" << endl;
    }
};

class Student {
private:
    string id;
    string name;
    string surname;
    int points;

public:
    Student() {
        id = name = surname = "";
        points = 0;
    }

    Student(string id, string name, string surname, int points) {
        this->id = id;
        this->name = name;
        this->surname = surname;
        this->points = points;
    }

    ~Student() {}

    int getPoints() {
        return points;
    }

    string &getId() {
        return id;
    }

    int grade() {
        if (points >= 90) {
            return 10;
        } else if (points >= 80) {
            return 9;
        } else if (points >= 70) {
            return 8;
        } else if (points >= 60) {
            return 7;
        } else if (points >= 50) {
            return 6;
        } else {
            return 5;
        }
    }

    friend istream &operator>>(istream &in, Student &s1) {
        in >> s1.name >> s1.surname >> s1.points;
        in.ignore();
        return in;
    }

    friend ostream &operator<<(ostream &out, Student &s) {
        out << s.id << " " << s.name << " " << s.surname << " " << s.points << " Grade: " << s.grade() << endl;
        return out;
    }
};

class Results {
private:
    Student *studenti;
    int brojNaStudenti;
public:
    Results() {
        brojNaStudenti = 0;
        studenti = new Student[0];
    }

    Results(Student *studenti, int brojNaStudenti) {
        this->brojNaStudenti = brojNaStudenti;
        this->studenti = new Student[0];
        for (int i = 0; i < brojNaStudenti; i++) {
            this->studenti[i] = studenti[i];
        }
    }

    Results(const Results &r) {
        brojNaStudenti = r.brojNaStudenti;
        studenti = new Student[brojNaStudenti];
        for (int i = 0; i < brojNaStudenti; i++) {
            studenti[i] = r.studenti[i];
        }
    }

    Results &operator=(const Results &r) {
        if (this != &r) {
            delete[] studenti;
            brojNaStudenti = r.brojNaStudenti;
            studenti = new Student[brojNaStudenti];
            for (int i = 0; i < brojNaStudenti; i++) {
                studenti[i] = r.studenti[i];
            }
        }
        return *this;
    }

    ~Results() {
        delete[] studenti;
    }

    int getBrojNaStudenti() const {
        return brojNaStudenti;
    }

    Results &operator+=(Student &other) {
        if (other.getPoints() < 50) {
            throw StudentFailedException(other.getId());
        }

        Student *tmp = new Student[brojNaStudenti + 1];
        for (int i = 0; i < brojNaStudenti; i++) {
            tmp[i] = studenti[i];
        }

        tmp[brojNaStudenti] = other;
        delete[] studenti;
        brojNaStudenti++;

//        studenti = tmp;
        studenti = new Student[brojNaStudenti];
        for (int i = 0; i < brojNaStudenti; i++) {
            studenti[i] = tmp[i];
        }

        return *this;
    }

    friend ostream &operator<<(ostream &out, Results &r) {
        for (int i = 0; i < r.brojNaStudenti; i++) {
            out << r.studenti[i];
        }

        return out;
    }

    Results withGrade(int grade) {
        Results nov;
        for (int i = 0; i < brojNaStudenti; i++) {
            if (studenti[i].grade() == grade) {
                nov += studenti[i];
            }
        }

        return nov;
    }
};


int main() {

    wtf();

    Results results;
    //TODO your code here
    //TODO Read the students from the file and add them in `results`
    ifstream in;
    in.open(("input.txt"));
    string id;
    string name;
    string surname;
    int points;

    while (in >> id >> name >> surname >> points) {
        in.ignore();
        try {
            Student s(id, name, surname, points);
            results += s;
        } catch (StudentFailedException &sfe) {
            sfe.message();
        }
    }

    in.close();

    //DO NOT MODIFY THE CODE BETWEEN THIS AND THE NEXT COMMENT
    int grade;
    cin >> grade;
    //DO NOT MODIFY THE CODE BETWEEN THIS AND THE PREVIOUS COMMENT

    //TODO Save the results in the files output1.txt and output2.txt after this line
    ofstream out1, out2;
    out1.open("output1.txt");
    out2.open("output2.txt");

    out1 << results;
    out1.close();

    Results nov = results.withGrade(grade);
    if (!nov.getBrojNaStudenti()) {
        out2 << "None";
    } else {
        out2 << nov;
    }

    out2.close();

    //DO NOT MODIFY THE CODE BELLOW
    cout << "All students:" << endl;
    rff("output1.txt");
    cout << "Grade report for grade " << grade << ": " << endl;
    rff("output2.txt");


    return 0;
}