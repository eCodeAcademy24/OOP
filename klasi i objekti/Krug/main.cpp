#include <iostream>
#include <cstring>

using namespace std;

class Krug {
private:
    float radius;
    const float pi = 3.14;
public:
    Krug() {}

    Krug(float radius) {
        this->radius = radius;
    }

    //TODO: make getter and setter methods for radius

    float perimetar() {
        return 2 * pi * radius;
    }

    float plostina() {
        return pi * radius * radius;
    }

    bool ednakvi() {
        return perimetar() == plostina();
    }
};

int main() {
    float radius;
    cin >> radius;

    Krug krug(radius);

//    Krug krug1;
//
//    krug1.setRadius(radius);

    cout << krug.perimetar() << endl;
    cout << krug.plostina() << endl;
    cout << krug.ednakvi();
    return 0;
}