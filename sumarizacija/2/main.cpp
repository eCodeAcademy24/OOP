#include <iostream>
#include <cstring>

using namespace std;

class StockRecord {
private:
    char id[12];
    char kompanija[50];
    double cena;
    double momentalnaCena;
    int brAkcii;
public:
    StockRecord() {}

    StockRecord(char *id, char *kompanija, double cena, int brAkcii) {
        strcpy(this->id, id);
        strcpy(this->kompanija, kompanija);
        this->cena = cena;
        this->brAkcii = brAkcii;
        this->momentalnaCena = 0;
    }

    StockRecord(const StockRecord &sr) {
        strcpy(id, sr.id);
        strcpy(kompanija, sr.kompanija);
        cena = sr.cena;
        brAkcii = sr.brAkcii;
        momentalnaCena = sr.momentalnaCena;
    }

    ~StockRecord() {}

    void setNewPrice(double momentalnaCena) {
        this->momentalnaCena = momentalnaCena;
    }

    double value() {
        return brAkcii * momentalnaCena;
    }

    double profit() const {
        return brAkcii * (momentalnaCena - cena);
    }

    friend ostream &operator<<(ostream &out, const StockRecord &sr) {
        out << sr.kompanija << " " << sr.brAkcii << " " << sr.cena << " " << sr.momentalnaCena << " " << sr.profit()
            << endl;

        return out;
    }
};

class Client {
private:
    char fullName[60];
    int id;
    StockRecord *sr;
    int numSr;
public:
    Client() {
        sr = new StockRecord[0];
        numSr = 0;
    }

    Client(char *fullName, int id) {
        strcpy(this->fullName, fullName);
        this->id = id;
        sr = new StockRecord[0];
        numSr = 0;
    }

    Client(const Client &client) {
        strcpy(fullName, client.fullName);
        id = client.id;
        numSr = client.numSr;
        sr = new StockRecord[numSr];
        for (int i = 0; i < numSr; i++) {
            sr[i] = client.sr[i];
        }
    }

    Client &operator=(const Client &client) {
        if (this != &client) {
            delete[] sr;
            strcpy(fullName, client.fullName);
            id = client.id;
            numSr = client.numSr;
            sr = new StockRecord[numSr];
            for (int i = 0; i < numSr; i++) {
                sr[i] = client.sr[i];
            }
        }

        return *this;
    }

    ~Client() {
        delete[] sr;
    }

    double totalValue() const {
        double total = 0;
        for (int i = 0; i < numSr; i++) {
            total += sr[i].value();
        }

        return total;
    }

    Client &operator+=(const StockRecord &other) {
        StockRecord *tmp = new StockRecord[numSr + 1];
        for (int i = 0; i < numSr; i++) {
            tmp[i] = sr[i];
        }

        tmp[numSr] = other;
        delete[] sr;
        ++numSr;

        sr = new StockRecord[numSr];
        sr = tmp;
        return *this;
    }

    friend ostream &operator<<(ostream &out, const Client &client) {
        out << client.id << " " << client.totalValue() << endl;
        for (int i = 0; i < client.numSr; i++) {
            out << client.sr[i];
        }

        return out;
    }
};

int main() {

    int test;
    cin >> test;

    if (test == 1) {
        double price;
        cout << "=====TEST NA KLASATA StockRecord=====" << endl;
        StockRecord sr("1", "Microsoft", 60.0, 100);
        cout << "Konstruktor OK" << endl;
        cin >> price;
        sr.setNewPrice(price);
        cout << "SET metoda OK" << endl;
    } else if (test == 2) {
        cout << "=====TEST NA METODITE I OPERATOR << OD KLASATA StockRecord=====" << endl;
        char id[12], company[50];
        double price, newPrice;
        int n, shares;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> id;
            cin >> company;
            cin >> price;
            cin >> newPrice;
            cin >> shares;
            StockRecord sr(id, company, price, shares);
            sr.setNewPrice(newPrice);
            cout << sr.value() << endl;
            cout << sr;
        }
    } else if (test == 3) {
        cout << "=====TEST NA KLASATA Client=====" << endl;
        char companyID[12], companyName[50], clientName[50];
        int clientID, n, shares;
        double oldPrice, newPrice;
        bool flag = true;
        cin >> clientName;
        cin >> clientID;
        cin >> n;
        Client c(clientName, clientID);
        cout << "Konstruktor OK" << endl;
        for (int i = 0; i < n; ++i) {
            cin >> companyID;
            cin >> companyName;
            cin >> oldPrice;
            cin >> newPrice;
            cin >> shares;
            StockRecord sr(companyID, companyName, oldPrice, shares);
            sr.setNewPrice(newPrice);
            c += sr;
            if (flag) {
                cout << "Operator += OK" << endl;
                flag = false;
            }
        }
        cout << c;
        cout << "Operator << OK" << endl;
    }
    return 0;

}