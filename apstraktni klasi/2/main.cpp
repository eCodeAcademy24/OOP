#include <iostream>

using namespace std;

class Number {
public:
    virtual double doubleValue() = 0;

    virtual int intValue() = 0;

    virtual void print() = 0;
};

bool operator==(Number &n1, Number &n2) {
    return n1.doubleValue() == n2.doubleValue() && n1.intValue() == n2.intValue();
}

class Integer : public Number {
private:
    int number;
public:
    Integer() : Number() {}

    Integer(int number) {
        this->number = number;
    }

    double doubleValue() {
        return (double) number;
    }

    int intValue() {
        return number;
    }

    void print() {
        cout << "Integer: " << number << endl;
    }
};

class Double : public Number {
private:
    double number;
public:
    Double() : Number() {}

    Double(double number) {
        this->number = number;
    }

    double doubleValue() {
        return number;
    }

    int intValue() {
        return (int) number;
    }

    void print() {
        cout << "Double: " << number << endl;
    }
};

class Numbers {
private:
    Number **broevi;
    int nums;
public:
    Numbers() {
        broevi = new Number *[0];
        nums = 0;
    }

    Numbers(const Numbers &numbers) {
        nums = numbers.nums;
        broevi = new Number *[nums];
        for (int i = 0; i < nums; i++) {
            broevi[i] = numbers.broevi[i];
        }
    }

    Numbers &operator=(const Numbers &numbers) {
        if (this != &numbers) {
            delete[] broevi;
            nums = numbers.nums;
            broevi = new Number *[nums];
            for (int i = 0; i < nums; i++) {
                broevi[i] = numbers.broevi[i];
            }
        }

        return *this;
    }

    ~Numbers() {
        delete[] broevi;
    }

    Numbers &operator+=(Number *nov) {
        Number **tmp = new Number *[nums + 1];
        for (int i = 0; i < nums; i++) {
            if (*broevi[i] == *nov) {
                delete[] tmp;
                return *this;
            }

            tmp[i] = broevi[i];
        }

        tmp[nums] = nov;
        delete[] broevi;
        nums++;
        broevi = new Number *[nums];
        for (int i = 0; i < nums; i++) {
            broevi[i] = tmp[i];
        }

        return *this;
    }

    void statistics() {
        double sumOfAllDouble = 0.0;
        int countIntegers = 0, countDoubles = 0, sumOfAllInteger = 0;

        for (int i = 0; i < nums; i++) {
            Integer *integerValue = dynamic_cast<Integer *>(broevi[i]);
            Double *doubleValue = dynamic_cast<Double *>(broevi[i]);

            if (integerValue) {
                sumOfAllInteger += integerValue->intValue();
                countIntegers++;
            } else {
                sumOfAllDouble += doubleValue->doubleValue();
                countDoubles++;
            }
        }

        int countOfAllNumbers = countIntegers + countDoubles;
        double sumOfAllNumbers = sumOfAllDouble + sumOfAllInteger;

        cout << "Count of numbers: " << countOfAllNumbers << endl;
        cout << "Sum of all numbers: " << sumOfAllNumbers << endl;
        cout << "Count of integer numbers: " << countIntegers << endl;
        cout << "Sum of integer numbers: " << sumOfAllInteger << endl;
        cout << "Count of double numbers: " << countDoubles << endl;
        cout << "Sum of double numbers: " << sumOfAllDouble << endl;
    }

    void integersLessThan(Integer n) {
        int flag = 1;
        for (int i = 0; i < nums; i++) {
            Integer *intValue = dynamic_cast<Integer *>(broevi[i]);
            if (intValue) {
                if (broevi[i]->intValue() < n.intValue()) {
                    broevi[i]->print();
                    flag = 0;
                }
            }
        }

        if (flag) {
            cout << "None" << endl;
        }
    }

    void doublesBiggerThan(Double n) {
        int flag = 1;
        for (int i = 0; i < nums; i++) {
            Double *doubleValue = dynamic_cast<Double *>(broevi[i]);
            if (doubleValue) {
                if (broevi[i]->doubleValue() > n.doubleValue()) {
                    broevi[i]->print();
                    flag = 0;
                }
            }
        }

        if (flag) {
            cout << "None" << endl;
        }
    }
};

int main() {

    int n;
    cin >> n;
    Numbers numbers;
    for (int i = 0; i < n; i++) {
        int type;
        double number;
        cin >> type >> number;
        if (type == 0) {
            Integer *integer = new Integer((int) number);
            numbers += integer;
        } else {
            Double *doublee = new Double(number);
            numbers += doublee;
        }
    }

    int lessThan;
    double biggerThan;

    cin >> lessThan;
    cin >> biggerThan;

    cout << "STATISTICS FOR THE NUMBERS\n";
    numbers.statistics();
    cout << "INTEGER NUMBERS LESS THAN " << lessThan << endl;
    numbers.integersLessThan(Integer(lessThan));
    cout << "DOUBLE NUMBERS BIGGER THAN " << biggerThan << endl;
    numbers.doublesBiggerThan(Double(biggerThan));

    return 0;
}
