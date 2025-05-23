#include <iostream>
#include <cstring>

#define MAX 100
using namespace std;

enum typeC {
    standard = 0,
    loyal = 1,
    vip = 2
};

class UserExistsException {
public:
    UserExistsException() {}

    void pecati() {
        cout << "The user already exists in the list" << endl;
    }
};


class Customer {
private:
    char ime[50];
    char adresa[50];
    typeC kupuvac;
    static int popust;
    const static int dopPopust;
    int brProizvodi;
public:
    Customer() {}

    Customer(char *ime, char *adresa, typeC kupuvac, int brProizvodi) {
        strcpy(this->ime, ime);
        strcpy(this->adresa, adresa);
        this->kupuvac = kupuvac;
        this->brProizvodi = brProizvodi;
    }

    Customer(const Customer &customer) {
        strcpy(ime, customer.ime);
        strcpy(adresa, customer.adresa);
        kupuvac = customer.kupuvac;
        brProizvodi = customer.brProizvodi;
    }

    ~Customer() {}

    static void setDiscount1(int osnoven) {
        popust = osnoven;
    }

    char *getAdresa() {
        return adresa;
    }

    int getBrProizvodi() {
        return brProizvodi;
    }

    typeC getTip() {
        return kupuvac;
    }

    void setKupuvac(typeC kupuvac) {
        this->kupuvac = kupuvac;
    }

    int popustSporedTip() {
        if (kupuvac == 0) {
            return 0;
        } else if (kupuvac == 1) {
            return popust;
        }

        return popust + dopPopust;
    }

    friend ostream &operator<<(ostream &os, Customer &customer) {
        os << customer.ime << endl;
        os << customer.adresa << endl;
        os << customer.brProizvodi << endl;
        if (customer.kupuvac == standard) {
            os << "standard ";
        } else if (customer.kupuvac == loyal) {
            os << "loyal ";
        } else {
            os << "vip ";
        }

        os << customer.popustSporedTip() << endl;

        return os;
    }
};

int Customer::popust = 10;
const int Customer::dopPopust = 20;

class ECODE_bookstore {
private:
    Customer *customers;
    int numCustomers;
public:
    ECODE_bookstore() {
        customers = new Customer[0];
        numCustomers = 0;
    }

//    ECODE_bookstore(const ECODE_bookstore &eb) {
//        numCustomers = eb.numCustomers;
//        customers = new Customer[numCustomers];
//        for (int i = 0; i < numCustomers; i++) {
//            customers[i] = eb.customers[i];
//        }
//    }
//
//    ECODE_bookstore &operator=(const ECODE_bookstore &eb) {
//        if (this != &eb) {
//            delete[] customers;
//            numCustomers = eb.numCustomers;
//            customers = new Customer[numCustomers];
//            for (int i = 0; i < numCustomers; i++) {
//                customers[i] = eb.customers[i];
//            }
//        }
//
//        return *this;
//    }

    ~ECODE_bookstore() {
        delete[] customers;
    }

    void setCustomers(Customer *customers, int n) {
        numCustomers = n;
        this->customers = new Customer[numCustomers];
        for (int i = 0; i < numCustomers; i++) {
            this->customers[i] = customers[i];
        }
    }

    ECODE_bookstore &operator+=(Customer &nov) {
        for (int i = 0; i < numCustomers; i++) {
            if (strcmp(customers[i].getAdresa(), nov.getAdresa()) == 0) {
                throw UserExistsException();
            }
        }

        Customer *tmp = new Customer[numCustomers + 1];
        for (int i = 0; i < numCustomers; i++) {
            tmp[i] = customers[i];
        }

        tmp[numCustomers] = nov;
        delete[] customers;
        ++numCustomers;
        customers = new Customer[numCustomers];
        for (int i = 0; i < numCustomers; i++) {
            customers[i] = tmp[i];
        }

        return *this;
    }

    void update() {
        for (int i = 0; i < numCustomers; i++) {
            if (customers[i].getTip() == standard && customers[i].getBrProizvodi() > 5) {
                customers[i].setKupuvac(loyal);
            } else if (customers[i].getTip() == loyal && customers[i].getBrProizvodi() > 10) {
                customers[i].setKupuvac(vip);
            }
        }
    }

    friend ostream &operator<<(ostream &os, ECODE_bookstore &eb) {
        for (int i = 0; i < eb.numCustomers; i++) {
            os << eb.customers[i];
        }

        return os;
    }
};

int main() {
    int testCase;
    cin >> testCase;

    char name[MAX];
    char email[MAX];
    int tC;
    int discount;
    int numProducts;


    if (testCase == 1) {
        cout << "===== Test Case - Customer Class ======" << endl;
        cin.get();
        cin.getline(name, MAX);
        cin.getline(email, MAX);
        cin >> tC;
        cin >> numProducts;
        cout << "===== CONSTRUCTOR ======" << endl;
        Customer c(name, email, (typeC) tC, numProducts);
        cout << c;

    }

    if (testCase == 2) {
        cout << "===== Test Case - Static Members ======" << endl;
        cin.get();
        cin.getline(name, MAX);
        cin.getline(email, MAX);
        cin >> tC;
        cin >> numProducts;
        cout << "===== CONSTRUCTOR ======" << endl;
        Customer c(name, email, (typeC) tC, numProducts);
        cout << c;

        c.setDiscount1(5);

        cout << c;
    }

    if (testCase == 3) {
        cout << "===== Test Case - ECODE-bookstore ======" << endl;
        ECODE_bookstore fc;
        int n;
        cin >> n;
        Customer customers[MAX];
        for (int i = 0; i < n; ++i) {
            cin.get();
            cin.getline(name, MAX);
            cin.getline(email, MAX);
            cin >> tC;
            cin >> numProducts;
            Customer c(name, email, (typeC) tC, numProducts);
            customers[i] = c;
        }

        fc.setCustomers(customers, n);

        cout << fc << endl;
    }

    if (testCase == 4) {
        cout << "===== Test Case - operator+= ======" << endl;
        ECODE_bookstore fc;
        int n;
        cin >> n;
        Customer customers[MAX];
        for (int i = 0; i < n; ++i) {
            cin.get();
            cin.getline(name, MAX);
            cin.getline(email, MAX);
            cin >> tC;
            cin >> numProducts;
            Customer c(name, email, (typeC) tC, numProducts);
            customers[i] = c;
        }

        fc.setCustomers(customers, n);
        cout << "OPERATOR +=" << endl;
        cin.get();
        cin.getline(name, MAX);
        cin.getline(email, MAX);
        cin >> tC;
        cin >> numProducts;
        Customer c(name, email, (typeC) tC, numProducts);
        try {
            fc += c;
        } catch (UserExistsException &uee) {
            uee.pecati();
        }

        cout << fc;
    }

    if (testCase == 5) {
        cout << "===== Test Case - operator+= (exception) ======" << endl;
        ECODE_bookstore fc;
        int n;
        cin >> n;
        Customer customers[MAX];
        for (int i = 0; i < n; ++i) {
            cin.get();
            cin.getline(name, MAX);
            cin.getline(email, MAX);
            cin >> tC;
            cin >> numProducts;
            Customer c(name, email, (typeC) tC, numProducts);
            customers[i] = c;
        }

        fc.setCustomers(customers, n);
        cout << "OPERATOR +=" << endl;
        cin.get();
        cin.getline(name, MAX);
        cin.getline(email, MAX);
        cin >> tC;
        cin >> numProducts;
        Customer c(name, email, (typeC) tC, numProducts);
        try {
            fc += c;
        } catch (UserExistsException &uee) {
            uee.pecati();
        }

        cout << fc;
    }

    if (testCase == 6) {
        cout << "===== Test Case - update method  ======" << endl << endl;
        ECODE_bookstore fc;
        int n;
        cin >> n;
        Customer customers[MAX];
        for (int i = 0; i < n; ++i) {
            cin.get();
            cin.getline(name, MAX);
            cin.getline(email, MAX);
            cin >> tC;
            cin >> numProducts;
            Customer c(name, email, (typeC) tC, numProducts);
            customers[i] = c;
        }

        fc.setCustomers(customers, n);

        cout << "Update:" << endl;
        fc.update();
        cout << fc;
    }
    return 0;

}
