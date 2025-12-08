#include <iostream>
#include <cstring>

using namespace std;

class Letter {
private:
    char mark;

public:
    Letter() {
    }

    Letter(char mark) {
        this->mark = mark;
    }

    char get() {
        return mark;
    }

    void upperLetter() {
        if (isalpha(this->mark)) {
            this->mark = toupper(this->mark);
        } else {
            cout << "Character is not a letter" << endl;
        }
    }
};

int main() {
    Letter obj;
    int n;
    cin >> n;
    int cmd;
    char k;
    for (int i = 0; i < n; i++) {
        cin >> cmd;
        switch (cmd) {
            case 1: {
                cin >> k;
                obj = Letter(k);
                cout << obj.get() << endl;
                break;
            }
            case 2: {
                obj.upperLetter();
                cout << obj.get() << endl;
                break;
            }
            case 3: {
                cin >> k;
                Letter obj2(k);
                obj2.upperLetter();
                cout << obj2.get() << endl;
                break;
            }
            default: {
                cout << obj.get() << endl;
                break;
            }
        }
    }
}
