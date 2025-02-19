#include <iostream>

using namespace std;

class Agol {
private:
    int stepeni;
    int minuti;
    int sekundi;
public:
    Agol() {}

    //TODO: make constructor with arguments

    ~Agol() {}

    //TODO: make getter methods for stepeni and minuti

    int getSekundi() {
        return sekundi;
    }

    void setStepeni(int stepeni) {
        this->stepeni = stepeni;
    }

    void setMinuti(int minuti) {
        this->minuti = minuti;
    }

    void setSekundi(int sekundi) {
        this->sekundi = sekundi;
    }

    int pretvoriVoSekundi() {
        int vkupnoSekundi = sekundi + (minuti * 60) + (stepeni * 3600);
        return vkupnoSekundi;
        //return sekundi + (minuti * 60) + (stepeni * 3600);
    }
};

int proveri(int sekundi, int minuti, int stepeni) {
    if (stepeni > 360 || stepeni < 0) {
        return 0;
    }

    if (minuti >= 60 || minuti < 0) {
        return 0;
    }

    if (sekundi >= 60 || sekundi < 0) {
        return 0;
    }

    return 1;
}

bool promenaNaSekundi(Agol agol, int sekundi) {
    if (agol.getSekundi() != sekundi) {
        return true;
    }

    return false;

//    return agol.getSekundi() != sekundi;
}

int main() {
    Agol a;

    int stepeni, minuti, sekundi;
    cin >> stepeni >> minuti >> sekundi;

    if (proveri(sekundi, minuti, stepeni)) {
        a.setStepeni(stepeni);
        a.setSekundi(sekundi);
        a.setMinuti(minuti);
        cout << a.pretvoriVoSekundi();
        if (promenaNaSekundi(a, sekundi))
            cout << "Ne smeete da gi menuvate sekundite vo ramkite na klasata";
    } else {
        cout << "Nevalidni vrednosti za agol";
    }

    return 0;
}
