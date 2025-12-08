#include<iostream>

using namespace std;

class Book {
private:
    string title;
    int numOfReadPages;

public:
    Book(string title = "TEST_BOOK", int numOfReadPages = 0) {
        this->title = title;
        this->numOfReadPages = numOfReadPages;
    }

    void readPages(int pages) {
        this->numOfReadPages += pages;
        if (numOfReadPages > 200) {
            numOfReadPages = 200;
        }
    }

    void print() {
        if (numOfReadPages < 100) {
            cout << title << " - " << numOfReadPages << "/200" << " IN PROGRESS" << endl;
        } else if (numOfReadPages >= 100 && numOfReadPages < 200) {
            cout << title << " - " << numOfReadPages << "/200" << " ALMOST DONE" << endl;
        } else {
            cout << title << " - " << numOfReadPages << "/200" << " FINISHED" << endl;
        }
    }
};

int main() {
    string command;
    Book s;
    string name;
    int pagesRead;

    while (cin >> command) {
        if (command == "constructor1") {
            cin >> name >> pagesRead;
            s = Book(name, pagesRead);
        } else if (command == "constructor2") {
            cin >> name;
            s = Book(name);
        } else if (command == "readPages") {
            cin >> pagesRead;
            s.readPages(pagesRead);
        } else if (command == "print") {
            s.print();
        }
    }


    return 0;
}
