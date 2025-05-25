#include <iostream>
#include <cstring>

using namespace std;

class Book {
protected:
    char isbn[20];
    char naslov[50];
    char avtor[30];
    double cena;
public:
    Book() {}

    Book(char *isbn, char *naslov, char *avtor, double cena) {
        strcpy(this->isbn, isbn);
        strcpy(this->naslov, naslov);
        strcpy(this->avtor, avtor);
        this->cena = cena;
    }

    Book(const Book &book) {
        strcpy(isbn, book.isbn);
        strcpy(naslov, book.naslov);
        strcpy(avtor, book.avtor);
        cena = book.cena;
    }

    Book &operator=(const Book &book) {
        if (this != &book) {
            strcpy(isbn, book.isbn);
            strcpy(naslov, book.naslov);
            strcpy(avtor, book.avtor);
            cena = book.cena;
        }

        return *this;
    }

    ~Book() {}

    void setISBN(char *isbn) {
        strcpy(this->isbn, isbn);
    }

    virtual double price() = 0;

    bool operator>(Book &book) {
        return cena > book.cena;
    }

    friend ostream &operator<<(ostream &out, Book &book) {
        out << book.isbn << ": " << book.naslov << ", " << book.avtor << " " << book.price() << endl;
        return out;
    }
};

class OnlineBook : public Book {
private:
    char *url;
    int golemina;
public:
    OnlineBook() : Book() {
        url = new char[0];
        golemina = 0;
    }

    OnlineBook(char *isbn, char *naslov, char *avtor, double cena, char *url, int golemina) : Book(isbn, naslov, avtor,
                                                                                                   cena) {
        this->url = new char[strlen(url) + 1];
        strcpy(this->url, url);
        this->golemina = golemina;
    }

    OnlineBook(const OnlineBook &ob) : Book(ob) {
        url = new char[strlen(ob.url) + 1];
        strcpy(url, ob.url);
        golemina = ob.golemina;
    }

    OnlineBook &operator=(const OnlineBook &ob) {
        if (this != &ob) {
            delete[] url;
            strcpy(isbn, ob.isbn);
            strcpy(naslov, ob.naslov);
            strcpy(avtor, ob.avtor);
            cena = ob.cena;
            url = new char[strlen(ob.url) + 1];
            strcpy(url, ob.url);
            golemina = ob.golemina;
        }

        return *this;
    }

    ~OnlineBook() {
        delete[] url;
    }

    double price() {
        if (golemina > 20) {
            return cena * 1.2; // cena + (cena * 0.2);
        }

        return cena;
    }
};

class PrintBook : public Book {
private:
    double masa;
    bool zaliha;
public:
    PrintBook() : Book() {}

    PrintBook(char *isbn, char *naslov, char *avtor, double cena, double masa, bool zaliha) : Book(isbn, naslov, avtor,
                                                                                                   cena) {
        this->masa = masa;
        this->zaliha = zaliha;
    }

    PrintBook(const PrintBook &pb) : Book(pb) {
        masa = pb.masa;
        zaliha = pb.zaliha;
    }

    PrintBook &operator=(const PrintBook &pb) {
        if (this != &pb) {
            strcpy(this->isbn, pb.isbn);
            strcpy(this->naslov, pb.naslov);
            strcpy(this->avtor, pb.avtor);
            this->cena = pb.cena;
            masa = pb.masa;
            zaliha = pb.zaliha;
        }

        return *this;
    }


    ~PrintBook() {}

    double price() {
        if (masa > 0.7) {
            return cena * 1.15; // cena + (cena * 0.15);
        }

        return cena;
    }
};

void mostExpensiveBook(Book **books, int n) {
    cout << "ECODE-Education" << endl;

    int pb_counter = 0, ob_counter = 0;

    for (int i = 0; i < n; i++) {
        PrintBook *pb = dynamic_cast<PrintBook *>(books[i]);

        if (pb) {
            pb_counter++;
        } else {
            ob_counter++;
        }
    }

    cout << "Total number of online books: " << ob_counter << endl;
    cout << "Total number of print books: " << pb_counter << endl;

    cout << "The most expensive book is:" << endl;

    Book *max_book = books[0];

    for (int i = 1; i < n; i++) {
        if (books[i] > max_book) {
            max_book = books[i];
        }
    }

    cout << *max_book;
}

int main() {

    char isbn[20], title[50], author[30], url[100];
    int size, tip;
    float price, weight;
    bool inStock;
    Book **books;
    int n;

    int testCase;
    cin >> testCase;

    if (testCase == 1) {
        cout << "====== Testing OnlineBook class ======" << endl;
        cin >> n;
        books = new Book *[n];

        for (int i = 0; i < n; i++) {
            cin >> isbn;
            cin.get();
            cin.getline(title, 50);
            cin.getline(author, 30);
            cin >> price;
            cin >> url;
            cin >> size;
            cout << "CONSTRUCTOR" << endl;
            books[i] = new OnlineBook(isbn, title, author, price, url, size);
            cout << "OPERATOR <<" << endl;
            cout << *books[i];
        }
        cout << "OPERATOR >" << endl;
        cout << "Rezultat od sporedbata e: " << endl;
        if (*books[0] > *books[1])
            cout << *books[0];
        else
            cout << *books[1];
    }
    if (testCase == 2) {
        cout << "====== Testing OnlineBook CONSTRUCTORS ======" << endl;
        cin >> isbn;
        cin.get();
        cin.getline(title, 50);
        cin.getline(author, 30);
        cin >> price;
        cin >> url;
        cin >> size;
        cout << "CONSTRUCTOR" << endl;
        OnlineBook ob1(isbn, title, author, price, url, size);
        cout << ob1 << endl;
        cout << "COPY CONSTRUCTOR" << endl;
        OnlineBook ob2(ob1);
        cin >> isbn;
        ob2.setISBN(isbn);
        cout << ob1 << endl;
        cout << ob2 << endl;
        cout << "OPERATOR =" << endl;
        ob1 = ob2;
        cin >> isbn;
        ob2.setISBN(isbn);
        cout << ob1 << endl;
        cout << ob2 << endl;
    }
    if (testCase == 3) {
        cout << "====== Testing PrintBook class ======" << endl;
        cin >> n;
        books = new Book *[n];

        for (int i = 0; i < n; i++) {
            cin >> isbn;
            cin.get();
            cin.getline(title, 50);
            cin.getline(author, 30);
            cin >> price;
            cin >> weight;
            cin >> inStock;
            cout << "CONSTRUCTOR" << endl;
            books[i] = new PrintBook(isbn, title, author, price, weight, inStock);
            cout << "OPERATOR <<" << endl;
            cout << *books[i];
        }
        cout << "OPERATOR >" << endl;
        cout << "Rezultat od sporedbata e: " << endl;
        if (*books[0] > *books[1])
            cout << *books[0];
        else
            cout << *books[1];
    }
    if (testCase == 4) {
        cout << "====== Testing method mostExpensiveBook() ======" << endl;
        cin >> n;
        books = new Book *[n];

        for (int i = 0; i < n; i++) {

            cin >> tip >> isbn;
            cin.get();
            cin.getline(title, 50);
            cin.getline(author, 30);
            cin >> price;
            if (tip == 1) {

                cin >> url;
                cin >> size;

                books[i] = new OnlineBook(isbn, title, author, price, url, size);

            } else {
                cin >> weight;
                cin >> inStock;

                books[i] = new PrintBook(isbn, title, author, price, weight, inStock);
            }
        }

        mostExpensiveBook(books, n);
    }

    for (int i = 0; i < n; i++) delete books[i];
    delete[] books;
    return 0;
}
