#include <iostream>
#include <cstring>

using namespace std;

class IceCream {
private:
    char *ime;
    char sostav[100];
    float cena;
    int popust;
public:
    IceCream() {
        ime = new char[0];
        popust = 0;
    }

    IceCream(char *ime, char *sostav, float cena) {
        this->ime = new char[strlen(ime) + 1];
        strcpy(this->ime, ime);
        strcpy(this->sostav, sostav);
        this->cena = cena;
        this->popust = 0;
    }

    IceCream(const IceCream &other) {
        ime = new char[strlen(other.ime) + 1];
        strcpy(ime, other.ime);
        strcpy(sostav, other.sostav);
        cena = other.cena;
        popust = other.popust;
    }

    IceCream &operator=(const IceCream &other) {
        if (this != &other) {
            delete[] ime;
            ime = new char[strlen(other.ime) + 1];
            strcpy(ime, other.ime);
            strcpy(sostav, other.sostav);
            cena = other.cena;
            popust = other.popust;
        }

        return *this;
    }

    ~IceCream() {
        delete[] ime;
    }

    void setDiscount(int popust) {
        this->popust = popust;
    }

    void setName(char *ime) {
        delete[] this->ime;
        this->ime = new char[strlen(ime) + 1];
        strcpy(this->ime, ime);
    }

    // 20 --> cena * (1 - (20 /100))
    friend ostream &operator<<(ostream &out, IceCream &other) {
        out << other.ime << ": " << other.sostav << " " << other.cena;
        if (other.popust > 0) {
            out << " (" << other.cena * (1 - ((float) other.popust / 100)) << ")";
        }
        return out;
    }

    IceCream &operator++() {
        popust += 5;
        return *this;
    }

    IceCream operator+(char *novo) {
        IceCream other;
        other.ime = new char[strlen(ime) + 3 + strlen(novo) + 1];
        strcpy(other.ime, ime);
        strcat(other.ime, " + ");
        strcat(other.ime, novo);
        strcpy(other.sostav, sostav);
        other.popust = popust;
        other.cena = cena + 10;
        return other;
    }
};

class IceCreamShop {
private:
    char ime[50];
    IceCream *array;
    int num;
public:
    IceCreamShop() {
        array = new IceCream[0];
        num = 0;
    }

    IceCreamShop(char *ime) {
        strcpy(this->ime, ime);
        array = new IceCream[0];
        num = 0;
    }

    IceCreamShop(const IceCreamShop &other) {
        strcpy(ime, other.ime);
        num = other.num;
        array = new IceCream[num];
        for (int i = 0; i < num; i++) {
            array[i] = other.array[i];
        }
    }

    IceCreamShop &operator=(const IceCreamShop &other) {
        if (this != &other) {
            delete[] array;
            strcpy(ime, other.ime);
            num = other.num;
            array = new IceCream[num];
            for (int i = 0; i < num; i++) {
                array[i] = other.array[i];
            }
        }

        return *this;
    }

    ~IceCreamShop() {
        delete[] array;
    }

    IceCreamShop &operator+=(const IceCream &other) {
        IceCream *tmp = new IceCream[num + 1];
        for (int i = 0; i < num; i++) {
            tmp[i] = array[i];
        }

        tmp[num] = other;
        delete[] array;
        num++;

        array = new IceCream[num];
        array = tmp;

        return *this;
    }

    friend ostream &operator<<(ostream &out, IceCreamShop &other) {
        out << other.ime << endl;
        for (int i = 0; i < other.num; i++) {
            out << other.array[i] << endl;
        }

        return out;
    }
};

int main() {
    char name[100];
    char ingr[100];
    float price;
    int discount;

    int testCase;

    cin >> testCase;
    cin.get();
    if (testCase == 1) {
        cout << "====== TESTING IceCream CLASS ======" << endl;
        cin.getline(name, 100);
        cin.getline(ingr, 100);
        cin >> price;
        cin >> discount;
        cout << "CONSTRUCTOR" << endl;
        IceCream ic1(name, ingr, price);
        ic1.setDiscount(discount);
        cin.get();
        cin.getline(name, 100);
        cin.getline(ingr, 100);
        cin >> price;
        cin >> discount;
        IceCream ic2(name, ingr, price);
        ic2.setDiscount(discount);
        cout << "OPERATOR <<" << endl;
        cout << ic1 << endl;
        cout << ic2 << endl;
        cout << "OPERATOR ++" << endl;
        ++ic1;
        cout << ic1 << endl;
        cout << "OPERATOR +" << endl;
        IceCream ic3 = ic2 + "chocolate";
        cout << ic3 << endl;
    } else if (testCase == 2) {
        cout << "====== TESTING IceCream CONSTRUCTORS ======" << endl;
        cin.getline(name, 100);
        cin.getline(ingr, 100);
        cin >> price;
        cout << "CONSTRUCTOR" << endl;
        IceCream ic1(name, ingr, price);
        cout << ic1 << endl;
        cout << "COPY CONSTRUCTOR" << endl;
        IceCream ic2(ic1);
        cin.get();
        cin.getline(name, 100);
        ic2.setName(name);
        cout << ic1 << endl;
        cout << ic2 << endl;
        cout << "OPERATOR =" << endl;
        ic1 = ic2;
        cin.getline(name, 100);
        ic2.setName(name);
        cout << ic1 << endl;
        cout << ic2 << endl;

        cin >> discount;
        ic1.setDiscount(discount);


    } else if (testCase == 3) {
        cout << "====== TESTING IceCreamShop ======" << endl;
        char icsName[50];
        cin.getline(icsName, 100);
        cout << "CONSTRUCTOR" << endl;
        IceCreamShop ics(icsName);
        int n;
        cin >> n;
        cout << "OPERATOR +=" << endl;
        for (int i = 0; i < n; ++i) {
            cin.get();
            cin.getline(name, 100);
            cin.getline(ingr, 100);
            cin >> price;
            IceCream ic(name, ingr, price);
            ics += ic;
        }
        cout << ics;
    } else if (testCase == 4) {
        cout << "====== TESTING IceCreamShop CONSTRUCTORS ======" << endl;
        char icsName[50];
        cin.getline(icsName, 100);
        IceCreamShop ics(icsName);
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin.get();
            cin.getline(name, 100);
            cin.getline(ingr, 100);
            cin >> price;
            IceCream ic(name, ingr, price);
            ics += ic;
        }
        IceCream x("Ecode fruits", "strawberry ice cream, raspberry ice cream, blueberry ice cream", 60);
        IceCreamShop icp = ics;
        ics += x;
        cout << ics << endl;
        cout << icp << endl;
    }


    return 0;
}

