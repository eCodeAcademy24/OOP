#include <iostream>

using namespace std;

class Number {
private:
    int value;
public:
    Number() {

    }

    Number(int value) {
        this->value = value;
    }

    Number operator+(const Number &other) {
        return Number(value + other.value);
    }

    Number operator-(const Number &other) {
        return Number(value - other.value);
    }

    Number operator*(const Number &other) {
        return Number(value * other.value);
    }

    Number operator/(const Number &other) {
        return Number(value / other.value);
    }

    Number &operator++() {
        value++;
        return *this;
    }

//    Number operator++(int) {
//        Number temp = *this;
//        value++;
//        return temp;
//    }

    Number &operator--() {
        value--;
        return *this;
    }

    bool operator==(const Number &other) {
        return value == other.value;
    }

    bool operator!=(const Number &other) {
        return value != other.value;
    }

    bool operator<(const Number &other) {
        return value < other.value;
    }

    bool operator>(const Number &other) {
        return value > other.value;
    }

    Number &operator+=(const Number &other) {
        value += other.value;
        return *this;
    }

    Number &operator-=(const Number &other) {
        value -= other.value;
        return *this;
    }

    Number &operator*=(const Number &other) {
        value *= other.value;
        return *this;
    }

    Number &operator/=(const Number &other) {
        value /= other.value;
        return *this;
    }

    friend ostream &operator<<(ostream &os, const Number &n) {
        os << n.value;
        return os;
    }

    friend istream &operator>>(istream &is, Number &n) {
        is >> n.value;
        return is;
    }

    int getValue() {
        return value;
    }
};

int main() {
    Number a(3), b(5);
    Number sum = a + b;
    cout << "Operator+: " << sum.getValue() << endl;
    Number minus = a - b;
    cout << "Operator-: " << minus.getValue() << endl;
    Number multiplication = a * b;
    cout << "Operator*: " << multiplication.getValue() << endl;
    Number divide = a / b;
    cout << "Operator/: " << divide.getValue() << endl;
    ++a;
    cout << "Operator++: " << a.getValue() << endl;
    --a;
    cout << "Operator--: " << a.getValue() << endl;
    Number a1(10), b1(10);
    cout << "Operator==: ";
    if (a1 == b1)
        cout << "Ednakvi se" << endl;

    cout << "Operator!=: ";
    if (a != b)
        cout << "Razlichni se" << endl;

    cout << "Operator<: ";
    if (a < b)
        cout << "a e pomalo od b" << endl;

    Number a2(10), b2(9);
    cout << "Operator>: ";
    if (a2 > b2)
        cout << "a e pogolemo od b" << endl;

    cout << "Operator+=: ";
    a += b;
    cout << a.getValue() << endl;

    cout << "Operator-=: ";
    a -= b;
    cout << a.getValue() << endl;

    cout << "Operator*=: ";
    a *= b;
    cout << a.getValue() << endl;

    cout << "Operator/=: ";
    a /= b;
    cout << a.getValue() << endl;

    cout << "Operator<<: ";
    Number a3(42);
    cout << "Brojot e: " << a3 << endl;

    Number number;
    cout << "Vnesi broj: ";
    cin >> number;
    cout << "Vnese: " << number << endl;
    return 0;
}
