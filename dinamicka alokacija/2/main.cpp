#include<iostream>
#include<cstring>

using namespace std;

enum Extension {
    txt,
    pdf,
    exe
};

class File {
private:
    char *ime;
    Extension ex;
    char *sopstvenik;
    int golemina;
public:
    File() {
        ime = new char[0];
        sopstvenik = new char[0];
    }

    File(char *ime, char *sopstvenik, int golemina, Extension ex) {
        this->ime = new char[strlen(ime) + 1];
        strcpy(this->ime, ime);
        this->sopstvenik = new char[strlen(sopstvenik) + 1];
        strcpy(this->sopstvenik, sopstvenik);
        this->golemina = golemina;
        this->ex = ex;
    }

    File(const File &file) {
        ime = new char[strlen(file.ime) + 1];
        strcpy(ime, file.ime);
        sopstvenik = new char[strlen(file.sopstvenik) + 1];
        strcpy(sopstvenik, file.sopstvenik);
        golemina = file.golemina;
        ex = file.ex;
    }

    File &operator=(const File &file) {
        if (this != &file) {
            delete[] ime;
            delete[] sopstvenik;
            ime = new char[strlen(file.ime) + 1];
            strcpy(ime, file.ime);
            sopstvenik = new char[strlen(file.sopstvenik) + 1];
            strcpy(sopstvenik, file.sopstvenik);
            golemina = file.golemina;
            ex = file.ex;
        }

        return *this;
    }

    ~File() {
        delete[] ime;
        delete[] sopstvenik;
    }

    void print() {
        cout << "File name: " << ime << ".";
        if (ex == pdf) cout << "pdf" << endl;
        else if (ex == exe) cout << "exe" << endl;
        else if (ex == txt) cout << "txt" << endl;

        cout << "File owner: " << sopstvenik << endl;
        cout << "File size: " << golemina << endl;
    }

    bool equals(const File &that) {
//        if (!strcmp(ime, that.ime) && ex == that.ex && !strcmp(sopstvenik, that.sopstvenik)) {
//            return true;
//        }
//
//        return false;
        return !strcmp(ime, that.ime) && ex == that.ex && !strcmp(sopstvenik, that.sopstvenik);
    }

    bool equalsType(const File &that) {
        return !strcmp(ime, that.ime) && ex == that.ex;
    }
};

class Folder {
private:
    char *ime;
    int brFiles;
    File *files;
public:
    Folder() {
        ime = new char[0];
        brFiles = 0;
        files = new File[0];
    }

    Folder(char *ime) {
        this->ime = new char[strlen(ime) + 1];
        strcpy(this->ime, ime);
        brFiles = 0;
        files = new File[0];
    }

    Folder(const Folder &folder) {
        ime = new char[strlen(folder.ime) + 1];
        strcpy(ime, folder.ime);
        brFiles = folder.brFiles;
        files = new File[brFiles];
        for (int i = 0; i < brFiles; i++) {
            files[i] = folder.files[i];
        }
    }

    Folder &operator=(const Folder &folder) {
        if (this != &folder) {
            delete[] ime;
            delete[] files;
            ime = new char[strlen(folder.ime) + 1];
            strcpy(ime, folder.ime);
            brFiles = folder.brFiles;
            files = new File[brFiles];
            for (int i = 0; i < brFiles; i++) {
                files[i] = folder.files[i];
            }
        }

        return *this;
    }

    void add(const File &file) {
        File *tmp = new File[brFiles + 1];
        for (int i = 0; i < brFiles; i++) {
            tmp[i] = files[i];
        }

        tmp[brFiles] = file;
        delete[] files;
        ++brFiles;
        files = new File[brFiles];
        for (int i = 0; i < brFiles; i++) {
            files[i] = tmp[i];
        }
    }

    void remove(const File &file) {
        bool flag = false;
        for (int i = 0; i < brFiles; i++) {
            if (files[i].equals(file)) {
                flag = true;
                break;
            }
        }
        if (!flag) return;

        File *tmp = new File[brFiles - 1];
        int k = 0;
        for (int i = 0; i < brFiles; i++) {
            if (!files[i].equals(file)) {
                tmp[k] = files[i];
                ++k;
            }
        }

        brFiles--;
        delete[] files;
        files = new File[brFiles];
        for (int i = 0; i < brFiles; i++) {
            files[i] = tmp[i];
        }
    }

    void print() {
        cout << "Folder name: " << ime << endl;
        for (int i = 0; i < brFiles; i++) {
            files[i].print();
        }
    }
};

int main() {
    char fileName[20];
    char fileOwner[20];
    int ext;
    int fileSize;

    int testCase;
    cin >> testCase;
    if (testCase == 1) {
        cout << "======= FILE CONSTRUCTORS AND = OPERATOR =======" << endl;
        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File created = File(fileName, fileOwner, fileSize, (Extension) ext);
        File copied = File(created);
        File assigned = created;

        cout << "======= CREATED =======" << endl;
        created.print();
        cout << endl;
        cout << "======= COPIED =======" << endl;
        copied.print();
        cout << endl;
        cout << "======= ASSIGNED =======" << endl;
        assigned.print();
    } else if (testCase == 2) {
        cout << "======= FILE EQUALS AND EQUALS TYPE =======" << endl;
        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File first(fileName, fileOwner, fileSize, (Extension) ext);
        first.print();

        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File second(fileName, fileOwner, fileSize, (Extension) ext);
        second.print();

        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File third(fileName, fileOwner, fileSize, (Extension) ext);
        third.print();

        bool equals = first.equals(second);
        cout << "FIRST EQUALS SECOND: ";
        if (equals)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;

        equals = first.equals(third);
        cout << "FIRST EQUALS THIRD: ";
        if (equals)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;

        bool equalsType = first.equalsType(second);
        cout << "FIRST EQUALS TYPE SECOND: ";
        if (equalsType)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;

        equalsType = second.equals(third);
        cout << "SECOND EQUALS TYPE THIRD: ";
        if (equalsType)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;

    } else if (testCase == 3) {
        cout << "======= FOLDER CONSTRUCTOR =======" << endl;
        cin >> fileName;
        Folder folder(fileName);
        folder.print();

    } else if (testCase == 4) {
        cout << "======= ADD FILE IN FOLDER =======" << endl;
        char name[20];
        cin >> name;
        Folder folder(name);

        int iter;
        cin >> iter;

        while (iter > 0) {
            cin >> fileName;
            cin >> fileOwner;
            cin >> fileSize;
            cin >> ext;

            File file(fileName, fileOwner, fileSize, (Extension) ext);
            folder.add(file);
            iter--;
        }
        folder.print();
    } else {
        cout << "======= REMOVE FILE FROM FOLDER =======" << endl;
        char name[20];
        cin >> name;
        Folder folder(name);

        int iter;
        cin >> iter;

        while (iter > 0) {
            cin >> fileName;
            cin >> fileOwner;
            cin >> fileSize;
            cin >> ext;

            File file(fileName, fileOwner, fileSize, (Extension) ext);
            folder.add(file);
            iter--;
        }
        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File file(fileName, fileOwner, fileSize, (Extension) ext);
        folder.remove(file);
        folder.print();
    }
    return 0;
}
