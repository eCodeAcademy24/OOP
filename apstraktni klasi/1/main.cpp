#include <iostream>
#include <cstring>

using namespace std;

class Employee {
protected:
    char *name;
    int year;
    int experience;
public:
    Employee() {
        name = new char[0];
    }

    Employee(char *name, int year, int experience) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->year = year;
        this->experience = experience;
    }

    Employee(const Employee &employee) {
        name = new char[strlen(employee.name) + 1];
        strcpy(name, employee.name);
        year = employee.year;
        experience = employee.experience;
    }

    Employee &operator=(const Employee &employee) {
        if (this != &employee) {
            delete[] name;
            name = new char[strlen(employee.name) + 1];
            strcpy(name, employee.name);
            year = employee.year;
            experience = employee.experience;
        }

        return *this;
    }

    ~Employee() {
        delete[] name;
    }

    virtual double plata() = 0;

    virtual double bonus() = 0;

    bool operator==(Employee &employee) {
        return year == employee.year;
    }
};

class SalaryEmployee : public Employee {
private:
    int basicSalary;
public:
    SalaryEmployee() : Employee() {}

    SalaryEmployee(char *name, int year, int experience, int basicSalary) : Employee(name, year, experience) {
        this->basicSalary = basicSalary;
    }

    SalaryEmployee(const SalaryEmployee &se) : Employee(se) {
        basicSalary = se.basicSalary;
    }

    SalaryEmployee &operator=(const SalaryEmployee &se) {
        if (this != &se) {
            delete[] name;
            name = new char[strlen(se.name) + 1];
            strcpy(name, se.name);
            year = se.year;
            experience = se.experience;
            basicSalary = se.basicSalary;
        }
        return *this;
    }

    ~SalaryEmployee() {}

    double bonus() {
        return ((float) basicSalary * experience) / 100;
    }

    double plata() {
        return basicSalary + bonus();
    }
};

class HourlyEmployee : public Employee {
private:
    int hoursWorked;
    int hourlyPay;
public:
    HourlyEmployee() : Employee() {}

    HourlyEmployee(char *name, int year, int experience, int hoursWorked, int hourlyPay) : Employee(name, year,
                                                                                                    experience) {
        this->hoursWorked = hoursWorked;
        this->hourlyPay = hourlyPay;
    }

    HourlyEmployee(const HourlyEmployee &he) : Employee(he) {
        hoursWorked = he.hoursWorked;
        hourlyPay = he.hourlyPay;
    }

    HourlyEmployee &operator=(const HourlyEmployee &he) {
        if (this != &he) {
            delete[] name;
            name = new char[strlen(he.name) + 1];
            strcpy(name, he.name);
            year = he.year;
            experience = he.experience;
            hoursWorked = he.hoursWorked;
            hourlyPay = he.hourlyPay;
        }
        return *this;
    }

    ~HourlyEmployee() {}

    double bonus() {
        double bonus = 0;

        if (hoursWorked > 320) {
            bonus = (hoursWorked - 320) * (0.5 * hourlyPay);
        }

        return bonus;
    }

    double plata() {
        return (hoursWorked * hourlyPay) + bonus();
    }
};

class Freelancer : public Employee {
private:
    int numProjects;
    double *projects;
public:
    Freelancer() : Employee() {
        numProjects = 0;
        projects = new double[0];
    }

    Freelancer(char *name, int year, int experience, int numProjects, double *projects) : Employee(name, year,
                                                                                                   experience) {
        this->numProjects = numProjects;
        this->projects = new double[numProjects];
        for (int i = 0; i < numProjects; i++) {
            this->projects[i] = projects[i];
        }
    }

    Freelancer(const Freelancer &fl) : Employee(fl) {
        numProjects = fl.numProjects;
        projects = new double[numProjects];
        for (int i = 0; i < numProjects; i++) {
            projects[i] = fl.projects[i];
        }
    }

    Freelancer &operator=(const Freelancer &fl) {
        if (this != &fl) {
            delete[] name;
            delete[] projects;
            name = new char[strlen(fl.name) + 1];
            strcpy(name, fl.name);
            year = fl.year;
            experience = fl.experience;
            numProjects = fl.numProjects;
            projects = new double[numProjects];
            for (int i = 0; i < numProjects; i++) {
                projects[i] = fl.projects[i];
            }
        }

        return *this;
    }

    ~Freelancer() {
        delete[] projects;
    }

    double bonus() {
        double count = 0;

        if (numProjects > 5) {
            count = (numProjects - 5) * 1000;
        }

        return count;
    }

    double sum() {
        double total = 0;
        for (int i = 0; i < numProjects; i++) {
            total += projects[i];
        }

        return total;
    }

    double plata() {
        return sum() + bonus();
    }
};

class Company {
private:
    char *name;
    int numEmployees;
    Employee **employees;
public:
    Company() {
        name = new char[0];
        numEmployees = 0;
        employees = new Employee *[0];
    }

    Company(char *name) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        numEmployees = 0;
        employees = new Employee *[0];
    }

    Company(const Company &company) {
        name = new char[strlen(company.name) + 1];
        strcpy(name, company.name);
        numEmployees = company.numEmployees;
        employees = new Employee *[numEmployees];
        for (int i = 0; i < numEmployees; i++) {
            employees[i] = company.employees[i];
        }
    }

    Company &operator=(const Company &company) {
        if (this != &company) {
            delete[] name;
            delete[] employees;
            name = new char[strlen(company.name) + 1];
            strcpy(name, company.name);
            numEmployees = company.numEmployees;
            employees = new Employee *[numEmployees];
            for (int i = 0; i < numEmployees; i++) {
                employees[i] = company.employees[i];
            }
        }
        return *this;
    }

    ~Company() {
        delete[] name;
        delete[] employees;
    }

    Company &operator+=(Employee *emp) {
        Employee **tmp = new Employee *[numEmployees + 1];
        for (int i = 0; i < numEmployees; i++) {
            tmp[i] = employees[i];
        }

        tmp[numEmployees] = emp;
        ++numEmployees;
        delete[] employees;

        employees = new Employee *[numEmployees];
        for (int i = 0; i < numEmployees; i++) {
            employees[i] = tmp[i];
        }

        return *this;
    }

    double vkupnaPlata() {
        double totalSalary = 0;
        for (int i = 0; i < numEmployees; i++) {
            totalSalary += employees[i]->plata();
        }

        return totalSalary;
    }

    double filtriranaPlata(Employee *emp) {
        double total = 0;
        for (int i = 0; i < numEmployees; i++) {
            if (*emp == *employees[i]) {
                total += employees[i]->plata();
            }
        }

        return total;
    }

    void pecatiRabotnici() {
        SalaryEmployee *se;
        HourlyEmployee *he;
        Freelancer *fl;
        int salary_count = 0, hourly_count = 0, freelancers_count = 0;
        for (int i = 0; i < numEmployees; i++) {
            se = dynamic_cast<SalaryEmployee *>(employees[i]);
            he = dynamic_cast<HourlyEmployee *>(employees[i]);
            fl = dynamic_cast<Freelancer *>(employees[i]);

            if (se) {
                salary_count++;
            } else if (he) {
                hourly_count++;
            } else {
                freelancers_count++;
            }
        }

        cout << "Vo kompanijata " << name << " rabotat:" << endl;
        cout << "Salary employees: " << salary_count << endl;
        cout << "Hourly employees: " << hourly_count << endl;
        cout << "Freelancers: " << freelancers_count << endl;
    }
};


int main() {
    char name[50];
    cin >> name;
    Company c(name);

    int n;
    cin >> n;

    char employeeName[50];
    int age;
    int experience;
    int type;

    for (int i = 0; i < n; ++i) {
        cin >> type;
        cin >> employeeName >> age >> experience;

        if (type == 1) {
            int basicSalary;
            cin >> basicSalary;
            c += new SalaryEmployee(employeeName, age, experience, basicSalary);
        } else if (type == 2) {
            int hoursWorked;
            int hourlyPay;
            cin >> hoursWorked >> hourlyPay;
            c += new HourlyEmployee(employeeName, age, experience, hoursWorked, hourlyPay);
        } else {
            int numProjects;
            cin >> numProjects;
            double projects[10];
            for (int i = 0; i < numProjects; ++i) {
                cin >> projects[i];
            }
            c += new Freelancer(employeeName, age, experience, numProjects, projects);
        }
    }

    c.pecatiRabotnici();
    cout << "Vkupnata plata e: " << c.vkupnaPlata() << endl;
    Employee *emp = new HourlyEmployee("Petre_Petrov", 31, 6, 340, 80);
    cout << "Filtriranata plata e: " << c.filtriranaPlata(emp);

    delete emp;
}
