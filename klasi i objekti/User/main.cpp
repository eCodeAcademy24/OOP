#include <iostream>
#include <cstring>

using namespace std;

class User {
private:
    char username[50];
    char password[50];

public:
    User() {
        strcpy(username, "guest");
        strcpy(password, "1234");
    }

    User(char *username, char *password) {
        strcpy(this->username, username);
        strcpy(this->password, password);
    }

    ~User() {}

    //TODO: getter and setter methods for username and password

    bool login(char *username, char *password) {
        if (strcmp(this->username, username) == 0 && strcmp(this->password, password) == 0) {
            cout << "Login successful. Welcome, " << username << "!" << endl;
            return true;
        } else {
            cout << "Invalid username or password. Try again." << endl;
            return false;
        }
    }

    void logout() {
        cout << "User " << username << " is logged out.";
    }
};

int main() {
    User user("john_doe", "securepass");

    while (true) {
        char inputUsername[50], inputPassword[50];
        cout << "Enter username: ";
        cin >> inputUsername;
        cout << "Enter password: ";
        cin >> inputPassword;

        if (user.login(inputUsername, inputPassword)) {
            user.logout();
            break;
        }
    }


    return 0;
}
