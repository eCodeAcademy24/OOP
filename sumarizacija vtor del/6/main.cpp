#include <iostream>
#include <string>

using namespace std;

class InvalidCodeFormatException {
private:
    string code;
public:
    InvalidCodeFormatException(string code) {
        this->code = code;
    }

    void print() {
        cout << "The code " << code
             << " is invalid doctor code format. THE CODE MUST BE 8 CHARACTERS LONG AND CANNOT CONTAIN COMMA."
             << endl;
    }
};

class Doctor {
protected:
    string firstName;
    string lastName;
    float salary;
    string code;
public:
    Doctor(string firstName, string lastName, string code) {
        this->firstName = firstName;
        this->lastName = lastName;

        if (code.length() != 8 /*&& code.find(',') != string::npos*/) {
            throw InvalidCodeFormatException(code);
        }

        for (char c: code) {
            if (c == ',') {
                throw InvalidCodeFormatException(code);
            }
        }

        this->code = code;
    }

    virtual float calculateSalary() = 0;

    virtual void print() = 0;
};

class GeneralDoctor : public Doctor {
private:
    int numOfPatients;
public:
    GeneralDoctor(string firstName, string lastName, string code, int numOfPatients) : Doctor(firstName, lastName,
                                                                                              code) {
        this->numOfPatients = numOfPatients;
        this->salary = 45000;
    }

    float calculateSalary() {
        int bonus = 0;
        if (numOfPatients >= 10) {
            bonus = 3000 * (numOfPatients / 10);
        }

        float totalSalary = bonus + salary;
        return totalSalary * 0.93;
    }

    void print() {
        cout << "General Doctor: " << firstName << " " << lastName << " CODE:" << code << " Salary: "
             << calculateSalary() << endl;
    }
};

class Specialist : public Doctor {
private:
    string specialty;
    int numOfInterventions;
    int yearsOfExperience;
public:
    Specialist(string firstName, string lastName, string code, string specialty, int numOfInterventions,
               int yearsOfExperience) : Doctor(firstName, lastName, code) {
        this->specialty = specialty;
        this->numOfInterventions = numOfInterventions;
        this->yearsOfExperience = yearsOfExperience;
        this->salary = 55000;
    }

    float calculateSalary() {
        return (salary + (numOfInterventions * 85) + (yearsOfExperience * (salary * 0.05))) * 0.93;
    }

    void print() {
        cout << "Specialist: " << firstName << " " << lastName << " CODE:" << code << " " << specialty << " Salary: "
             << calculateSalary() << endl;
    }
};

void findDoctorsPercentage(Doctor **doctors, int n) {
    int specialistCounter = 0, generalDoctorCounter = 0;

    for (int i = 0; i < n; i++) {
        if (doctors[i] != nullptr) {
            Specialist *specialist = dynamic_cast<Specialist *>(doctors[i]);

            if (specialist) {
                ++specialistCounter;
            } else {
                generalDoctorCounter++;
            }
        }
    }

    cout << ((float) specialistCounter / n) * 100 << "% of the doctors are specialists and "
         << ((float) generalDoctorCounter / n) * 100 << "% are general doctors.";
}

int main() {
    int testCase, n;
    string name, surname, specialty, code;
    int numberOfPatients, yearsOfExperience, numberOfInterventions;
    cin >> testCase;

    if (testCase == 1) {
        cout << "TESTING GENERAL DOCTOR CLASS" << endl;
        Doctor *d = new GeneralDoctor("John", "Smith", "236XY@2B", 120);
        Doctor *d1 = new GeneralDoctor("Marco", "Brown", "345X!Y2B", 120);
        Doctor *d2 = new GeneralDoctor("Emily", "Johnson", "ABCD123@", 230);
        d->print();
        d1->print();
        d2->print();

        cout << "GENERAL DOCTOR CLASS OK!" << endl;
    } else if (testCase == 2) {
        cout << "TESTING SPECIALIST DOCTOR CLASS" << endl;
        Doctor *d = new Specialist("Beth", "Davis", "96Tr$$33", "Cardiologist", 45, 5);
        Doctor *d1 = new Specialist("William", "Wilson", "785#Qy2B", "Pulmonologist", 50, 7);
        Doctor *d2 = new Specialist("Micheal", "Rosen", "7896YZ$s", "Radiologist", 41, 10);
        d->print();
        d1->print();
        d2->print();
        cout << "SPECIALIST DOCTOR CLASS OK!" << endl;
    } else if (testCase == 3) {
        cout << "TESTING EXCEPTION HANDLING" << endl;
        try {
            Doctor *d = new GeneralDoctor("John", "Smith", "23Y@2B", 120);
            d->print();
        } catch (InvalidCodeFormatException &icfe) {
            icfe.print();
        }

        cout << "EXCEPTION HANDLING OK!" << endl;
    } else if (testCase == 4) {
        cout << "TESTING EXCEPTION HANDLING" << endl;

        try {
            Doctor *d = new Specialist("Beth", "Davis", "9,R$$334", "Cardiologist", 45, 5);
            d->print();
        } catch (InvalidCodeFormatException &icfe) {
            icfe.print();
        }


        cout << "EXCEPTION HANDLING OK!" << endl;
    } else if (testCase == 5) {
        cout << "TESTING EXCEPTION HANDLING" << endl;

        try {
            Doctor *d = new Specialist("Beth", "Davis", "9,R$$334", "Cardiologist", 45, 5);
            d->print();
        } catch (InvalidCodeFormatException &icfe) {
            icfe.print();
        }

        try {
            Doctor *d1 = new Specialist("William", "Wilson", "785#Qy2B", "Pulmonologist", 50, 7);
            d1->print();
        } catch (InvalidCodeFormatException &icfe) {
            icfe.print();
        }

        try {
            Doctor *d2 = new Specialist("Beth", "Davis", "96Tr,", "Cardiologist", 45, 5);
            d2->print();
        } catch (InvalidCodeFormatException &icfe) {
            icfe.print();
        }

        cout << "EXCEPTION HANDLING OK!" << endl;
    } else {
        cout << "INTEGRATION TEST AND TESTING GLOBAL FUNCTION!" << endl;
        cin >> n;
        Doctor **doctors = new Doctor *[n];
        for (int i = 0; i < n; i++) {
            doctors[i] = nullptr;
            int t;
            cin >> t;
            cin >> name >> surname;
            cin >> code;
            if (t == 1) // General doctor
            {
                cin >> numberOfPatients;

                try {
                    doctors[i] = new GeneralDoctor(name, surname, code, numberOfPatients);
                } catch (InvalidCodeFormatException &icfe) {
                    icfe.print();
                }
            } else // Specialist
            {
                cin >> specialty;
                cin >> numberOfInterventions >> yearsOfExperience;

                try {
                    doctors[i] = new Specialist(name, surname, code, specialty, numberOfInterventions,
                                                yearsOfExperience);
                } catch (InvalidCodeFormatException &icfe) {
                    icfe.print();
                }
            }
        }
        cout << "LIST OF ALL DOCTORS: " << endl;
        for (int i = 0; i < n; i++) {
            if (doctors[i] != nullptr)
                doctors[i]->print();
        }
        findDoctorsPercentage(doctors, n);
        for (int i = 0; i < n; i++) {
            delete doctors[i];
        }
        delete[] doctors;
    }
    return 0;
}
