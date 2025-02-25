#include <iostream>
#include <cstring>

using namespace std;

class Person {
private:
    char name[20];
    char lastName[20];
public:
    Person() {
        strcpy(name, "not specified");
        strcpy(lastName, "not specified");
    }

    Person(char *name, char *lastName) {
        strcpy(this->name, name);
        strcpy(this->lastName, lastName);
    }

    Person(const Person &person) {
        strcpy(this->name, person.name);
        strcpy(this->lastName, person.lastName);
    }

    ~Person() {}

    void print() {
        cout << name << " " << lastName << endl;
    }
};

class Date {
private:
    int year;
    int month;
    int day;
public:
    Date() {}

    Date(int year, int month, int day) {
        this->year = year;
        this->month = month;
        this->day = day;
    }

    Date(const Date &date) {
        this->year = date.year;
        this->month = date.month;
        this->day = date.day;
    }

    ~Date() {}

    void print() {
        cout << year << "." << month << "." << day << endl;
    }
};

class Car {
private:
    Person person;
    Date date;
    float price;
public:
    Car() {
        price = 0;
    }

    Car(Person person, Date date, float price) {
        this->person = person;
        this->date = date;
        this->price = price;
    }

    ~Car() {}

    float getPrice() {
        return price;
    }

    void print() {
        person.print();
        date.print();
        cout << "Price: " << price << endl;
    }

};

void cheaperThan(Car *cars, int numCars, float price) {
    for (int i = 0; i < numCars; i++) {
        if (cars[i].getPrice() < price) {
            cars[i].print();
        }
    }
}

int main() {
    char name[20];
    char lastName[20];
    int year;
    int month;
    int day;
    float price;

    int testCase;
    cin >> testCase;

    if (testCase == 1) {
        cin >> name;
        cin >> lastName;
        Person lik(name, lastName);

        cin >> year;
        cin >> month;
        cin >> day;
        Date date(year, month, day);

        cin >> price;
        Car car(lik, date, price);

        car.print();
    } else if (testCase == 2) {
        cin >> name;
        cin >> lastName;
        Person lik(name, lastName);

        cin >> year;
        cin >> month;
        cin >> day;
        Date date(Date(year, month, day));

        cin >> price;
        Car car(lik, date, price);
        car.print();
    } else {
        int numCars;
        cin >> numCars;

        Car cars[10];
        for (int i = 0; i < numCars; i++) {
            cin >> name;
            cin >> lastName;
            Person lik(name, lastName);

            cin >> year;
            cin >> month;
            cin >> day;
            Date date(year, month, day);

            cin >> price;
            cars[i] = Car(lik, date, price);
        }
        float priceLimit;
        cin >> priceLimit;
        cheaperThan(cars, numCars, priceLimit);
    }

    return 0;
}
