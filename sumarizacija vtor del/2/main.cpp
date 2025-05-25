#include <iostream>

using namespace std;

class ArithmeticException {
public:
    ArithmeticException() {}

    void print() {
        cout << "Division by zero is not allowed" << endl;
    }
};

class NumbersNotDivisibleException {
private:
    int n;
public:
    NumbersNotDivisibleException(int n) {
        this->n = n;
    }

    void print() {
        cout << "Division by " << n << " is not supported" << endl;
    }
};

class ArrayFullException {
public:
    ArrayFullException() {}

    void print() {
        cout << "The array is full. Increase the capacity" << endl;
    }
};

class IndexOutOfBoundsException {
private:
    int index;
public:
    IndexOutOfBoundsException(int index) {
        this->index = index;
    }

    void print() {
        cout << "Index " << index << " is out of bounds" << endl;
    }
};

class NumberIsNotPositiveException {
private:
    int n;
public:
    NumberIsNotPositiveException(int n) {
        this->n = n;
    }

    void print() {
        cout << "Number " << n << " is not positive integer" << endl;
    }
};

class PositiveIntegers {
private:
    int *array;
    int numbers;
    int capacity;
public:
    PositiveIntegers() {
        capacity = 0;
        array = new int[0];
        numbers = 0;
    }

    PositiveIntegers(int capacity) {
        this->capacity = capacity;
        array = new int[0];
        numbers = 0;
    }

    PositiveIntegers(const PositiveIntegers &pi) {
        numbers = pi.numbers;
        array = new int[pi.numbers];
        for (int i = 0; i < pi.numbers; i++) {
            array[i] = pi.array[i];
        }
        capacity = pi.capacity;
    }

    PositiveIntegers operator=(const PositiveIntegers &pi) {
        if (this != &pi) {
            delete[]array;
            numbers = pi.numbers;
            array = new int[pi.numbers];
            for (int i = 0; i < pi.numbers; i++) {
                array[i] = pi.array[i];
            }
            capacity = pi.capacity;
        }
        return *this;
    }

    void increaseCapacity(int c) {
        capacity += c;
    }

    PositiveIntegers &operator+=(int nov) {
        if (numbers == capacity)
            throw ArrayFullException();
        if (nov <= 0)
            throw NumberIsNotPositiveException(nov);
        int i;
        int *tmp = new int[numbers + 1];
        for (i = 0; i < numbers; i++) {
            tmp[i] = array[i];
        }
        tmp[numbers] = nov;
        delete[] array;
        numbers++;
        array = new int[numbers];
        for (i = 0; i < numbers; i++) {
            array[i] = tmp[i];
        }
        return *this;
    }

    PositiveIntegers operator*(int broj) {
        PositiveIntegers nov(*this);
        for (int i = 0; i < numbers; i++)
            nov.array[i] *= broj;
        return nov;
    }

    PositiveIntegers operator/(int broj) {
        PositiveIntegers nov(*this);
        if (broj == 0)
            throw ArithmeticException();
        for (int i = 0; i < nov.numbers; i++) {
            if (nov.array[i] % broj != 0)
                throw NumbersNotDivisibleException(broj);
            nov.array[i] /= broj;
        }
        return nov;
    }

    int &operator[](int i) const {
        if (i >= numbers || i < 0)
            throw IndexOutOfBoundsException(i);
        return array[i];
    }

    void print() {
        cout << "Size: " << numbers << " Capacity: " << capacity << " Numbers: ";
        for (int i = 0; i < numbers; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }

};

int main() {

    int n, capacity;
    cin >> n >> capacity;
    PositiveIntegers pi(capacity);
    for (int i = 0; i < n; i++) {
        int number;
        cin >> number;
        try {
            pi += number;
        }
        catch (ArrayFullException afe) {
            afe.print();
        }
        catch (NumberIsNotPositiveException nnpe) {
            nnpe.print();
        }

    }
    cout << "===FIRST ATTEMPT TO ADD NUMBERS===" << endl;
    pi.print();
    int incCapacity;
    cin >> incCapacity;
    pi.increaseCapacity(incCapacity);
    cout << "===INCREASING CAPACITY===" << endl;
    pi.print();

    int n1;
    cin >> n1;
    for (int i = 0; i < n1; i++) {
        int number;
        cin >> number;
        try {
            pi += number;
        }
        catch (ArrayFullException afe) {
            afe.print();
        }
        catch (NumberIsNotPositiveException nnpe) {
            nnpe.print();
        }
    }
    cout << "===SECOND ATTEMPT TO ADD NUMBERS===" << endl;

    pi.print();
    PositiveIntegers pi1;

    cout << "===TESTING DIVISION===" << endl;

    try {
        pi1 = pi / 0;
        pi1.print();
    }
    catch (ArithmeticException ae) {
        ae.print();
    }
    catch (NumbersNotDivisibleException nnde) {
        nnde.print();
    }

    try {
        pi1 = pi / 1;
        pi1.print();
    }
    catch (ArithmeticException ae) {
        ae.print();
    }
    catch (NumbersNotDivisibleException nnde) {
        nnde.print();
    }


    try {
        pi1 = pi / 2;
        pi1.print();
    }
    catch (ArithmeticException ae) {
        ae.print();
    }
    catch (NumbersNotDivisibleException nnde) {
        nnde.print();
    }


    cout << "===TESTING MULTIPLICATION===" << endl;
    pi1 = pi * 3;
    pi1.print();


    cout << "===TESTING [] ===" << endl;
    try {
        cout << "PositiveIntegers[-1] = " << pi[-1] << endl;
    }
    catch (IndexOutOfBoundsException iobe) {
        iobe.print();
    }
    try {
        cout << "PositiveIntegers[2] = " << pi[2] << endl;
    }
    catch (IndexOutOfBoundsException iobe) {
        iobe.print();
    }
    try {
        cout << "PositiveIntegers[3] = " << pi[3] << endl;
    }
    catch (IndexOutOfBoundsException iobe) {
        iobe.print();
    }
    try {
        cout << "PositiveIntegers[12] = " << pi[12] << endl;
    }
    catch (IndexOutOfBoundsException iobe) {
        iobe.print();
    }


    return 0;
}
