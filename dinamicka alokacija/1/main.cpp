#include <iostream>

using namespace std;

class List {
private:
    int *numbers;
    int numElements;
public:
    List() {
        numElements = 0;
        this->numbers = new int[0];
    }

    List(int *numbers, int numElements) {
        this->numElements = numElements;
        this->numbers = new int[numElements];
        for (int i = 0; i < numElements; i++) {
            this->numbers[i] = numbers[i];
        }
    }

    List(const List &list) {
        numElements = list.numElements;
        numbers = new int[numElements];
        for (int i = 0; i < numElements; i++) {
            numbers[i] = list.numbers[i];
        }
    }

    List &operator=(const List &list) {
        if (this != &list) {
            delete[] numbers;

            numElements = list.numElements;
            numbers = new int[numElements];
            for (int i = 0; i < numElements; i++) {
                numbers[i] = list.numbers[i];
            }
        }

        return *this;
    }

    ~List() {
        delete[] numbers;
    }

    int getNumElements() {
        return numElements;
    }

    int sum() {
        int sum = 0;
        for (int i = 0; i < numElements; i++) {
            sum += numbers[i];
        }

        return sum;
    }

    double average() {
        return sum() / (double) numElements;
    }

    // 5: 1 2 3 4 5 sum: 15 average: 3
    void pecati() {
        cout << numElements << ": ";
        for (int i = 0; i < numElements; i++) {
            cout << numbers[i] << " ";
        }

        cout << "sum: " << sum() << " average: " << average() << endl;
    }
};

class ListContainer {
private:
    List *list;
    int numList;
    int tries;
public:
    ListContainer() {
        tries = 0;
        numList = 0;
        list = new List[0];
    }

    ListContainer(List *list, int numList, int tries) {
        this->numList = numList;
        this->list = new List[numList];
        for (int i = 0; i < numList; i++) {
            this->list[i] = list[i];
        }
        this->tries = tries;
    }

    ListContainer(const ListContainer &other) {
        numList = other.numList;
        list = new List[numList];
        for (int i = 0; i < numList; i++) {
            list[i] = other.list[i];
        }
        tries = other.tries;
    }

    ListContainer &operator=(const ListContainer &other) {
        if (this != &other) {
            delete[] list;
            numList = other.numList;
            list = new List[numList];
            for (int i = 0; i < numList; i++) {
                list[i] = other.list[i];
            }
            tries = other.tries;
        }

        return *this;
    }

    ~ListContainer() {
        delete[] list;
    }

    int sumOfNumElements() {
        int sumNumElements = 0;
        for (int i = 0; i < numList; i++) {
            sumNumElements += list[i].getNumElements();
        }

        return sumNumElements;
    }

    int sum() {
        int sum = 0;
        for (int i = 0; i < numList; i++) {
            sum += list[i].sum();
        }

        return sum;
    }

    double average() {
        return sum() / (double) sumOfNumElements();
    }

    void addNewList(List l) {
        ++tries;
        for (int i = 0; i < numList; i++) {
            if (list[i].sum() == l.sum()) {
                return;
            }
        }

        List *tmp = new List[numList + 1];
        for (int i = 0; i < numList; i++) {
            tmp[i] = list[i];
        }

        tmp[numList] = l;
        delete[] list;
        numList++;

        list = new List[numList];
        for (int i = 0; i < numList; i++) {
            list[i] = tmp[i];
        }
    }

    void print() {
        if (numList == 0) {
            cout << "The list is empty" << endl;
            return;
        }

        for (int i = 0; i < numList; i++) {
            cout << "List number: " << i + 1 << " List info: ";
            list[i].pecati();
        }

        cout << "Sum: " << sum() << " Average: " << average() << endl;
        cout << "Successful attempts: " << numList << " Failed attempts: " << tries - numList << endl;
    }
};

int main() {

    ListContainer lc;
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int n;
        int niza[100];

        cin >> n;

        for (int j = 0; j < n; j++) {
            cin >> niza[j];

        }

        List l = List(niza, n);

        lc.addNewList(l);
    }


    int testCase;
    cin >> testCase;

    if (testCase == 1) {
        cout << "Test case for operator =" << endl;
        ListContainer lc1;
        lc1.print();
        cout << lc1.sum() << " " << lc.sum() << endl;
        lc1 = lc;
        lc1.print();
        cout << lc1.sum() << " " << lc.sum() << endl;
        lc1.sum();
        lc1.average();

    } else {
        lc.print();
    }

    return 0;
}
