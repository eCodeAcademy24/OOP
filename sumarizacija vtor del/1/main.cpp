#include <iostream>
#include <cstring>

using namespace std;

class InvalidPassword {
private:
    char msg[100];
public:
    InvalidPassword(char *msg) {
        strcpy(this->msg, msg);
    }

    void message() {
        cout << msg << endl;
    }
};

class InvalidEmail {
private:
    char msg[100];
public:
    InvalidEmail(char *msg) {
        strcpy(this->msg, msg);
    }

    void message() {
        cout << msg << endl;
    }
};

class MaximumSizeLimit {
private:
    int n;
public:
    MaximumSizeLimit(int n) {
        this->n = n;
    }

    void message() {
        cout << "You can't add more than " << n << " users." << endl;
    }
};

class User {
protected:
    char username[50];
    char password[50];
    char email[50];

private:
    void isPasswordValid(char *password) {
        int upper = 0, lower = 0, digit = 0;

        for (int i = 0; i < strlen(password); i++) {
            if (isupper(password[i])) {
                ++upper;
            } else if (islower(password[i])) {
                ++lower;
            } else if (isdigit(password[i])) {
                ++digit;
            }
        }

        if (upper == 0 || lower == 0 || digit == 0) {
            throw InvalidPassword("Password is too weak.");
        }
    }

    void isEmailValid(char *email) {
        int counter = 0;
        for (int i = 0; i < strlen(email); i++) {
            if (email[i] == '@') {
                ++counter;
            }
        }

        if (counter != 1) {
            throw InvalidEmail("Mail is not valid.");
        }
    }

public:
    User() {}

    User(char *username, char *password, char *email) {
        isPasswordValid(password);
        isEmailValid(email);

        strcpy(this->username, username);
        strcpy(this->password, password);
        strcpy(this->email, email);
    }

    User(const User &user) {
        strcpy(username, user.username);
        strcpy(password, user.password);
        strcpy(email, user.email);
    }

    ~User() {}

    virtual double popularity() = 0;
};

class FacebookUser : public User {
private:
    int friends;
    int likes;
    int comments;
public:
    FacebookUser() : User() {}

    FacebookUser(char *username, char *password, char *email, int friends, int likes, int comments) : User(username,
                                                                                                           password,
                                                                                                           email) {
        this->friends = friends;
        this->likes = likes;
        this->comments = comments;
    }

    FacebookUser(const FacebookUser &fu) : User(fu) {
        friends = fu.friends;
        likes = fu.likes;
        comments = fu.comments;
    }

    ~FacebookUser() {}

    double popularity() {
        return friends + (likes * 0.1) + (comments * 0.5);
    }
};

class TwitterUser : public User {
private:
    int followers;
    int tweets;
public:
    TwitterUser() : User() {}

    TwitterUser(char *username, char *password, char *email, int followers, int tweets) : User(username, password,
                                                                                               email) {
        this->followers = followers;
        this->tweets = tweets;
    }

    TwitterUser(const TwitterUser &tu) : User(tu) {
        followers = tu.followers;
        tweets = tu.tweets;
    }

    ~TwitterUser() {}

    double popularity() {
        return followers + (tweets * 0.5);
    }
};

class SocialNetwork {
private:
    User **users;
    int numUsers;
    int maxUsers;
public:
    SocialNetwork() {
        users = new User *[0];
        numUsers = 0;
        maxUsers = 5;
    }

    SocialNetwork(const SocialNetwork &sn) {
        numUsers = sn.numUsers;
        users = new User *[numUsers];
        for (int i = 0; i < numUsers; i++) {
            users[i] = sn.users[i];
        }
        maxUsers = sn.maxUsers;
    }

    SocialNetwork &operator=(const SocialNetwork &sn) {
        if (this != &sn) {
            delete[] users;
            numUsers = sn.numUsers;
            users = new User *[numUsers];
            for (int i = 0; i < numUsers; i++) {
                users[i] = sn.users[i];
            }
            maxUsers = sn.maxUsers;
        }
        return *this;
    }

    ~SocialNetwork() {
        delete[] users;
    }

    SocialNetwork &operator+=(User *other) {
        if (maxUsers == numUsers) {
            throw MaximumSizeLimit(maxUsers);
        }

        User **tmp = new User *[numUsers + 1];
        for (int i = 0; i < numUsers; i++) {
            tmp[i] = users[i];
        }

        tmp[numUsers] = other;
        delete[] users;
        numUsers++;

        users = new User *[numUsers];
        for (int i = 0; i < numUsers; i++) {
            users[i] = tmp[i];
        }

        return *this;
    }

    double sum() {
        double sum = 0;
        for (int i = 0; i < numUsers; i++) {
            sum += users[i]->popularity();
        }

        return sum;
    }

    double avgPopularity() {
        return sum() / numUsers;
    }

    void changeMaximumSize(int number) {
        maxUsers = number;
    }
};

int main() {
    SocialNetwork network = SocialNetwork();
    int n;
    cin >> n;
    char username[50];
    char password[50];
    char email[50];
    int userType;
    for (int i = 0; i < n; ++i) {
        cin >> username;
        cin >> password;
        cin >> email;
        cin >> userType;
        if (userType == 1) {
            int friends;
            int likes;
            int comments;
            cin >> friends >> likes >> comments;

            try {
                User *u = new FacebookUser(username, password, email, friends, likes, comments);
                network += u;
            } catch (InvalidPassword &ip) {
                ip.message();
            } catch (InvalidEmail &ie) {
                ie.message();
            } catch (MaximumSizeLimit &msl) {
                msl.message();
            }
        } else {
            int followers;
            int tweets;
            cin >> followers >> tweets;

            try {
                User *u = new TwitterUser(username, password, email, followers, tweets);
                network += u;
            } catch (InvalidPassword &ip) {
                ip.message();
            } catch (InvalidEmail &ie) {
                ie.message();
            } catch (MaximumSizeLimit &msl) {
                msl.message();
            }
        }
    }
    network.changeMaximumSize(6);
    cin >> username;
    cin >> password;
    cin >> email;
    int followers;
    int tweets;
    cin >> followers >> tweets;

    try {
        User *u = new TwitterUser(username, password, email, followers, tweets);
        network += u;
    } catch (InvalidPassword &ip) {
        ip.message();
    } catch (InvalidEmail &ie) {
        ie.message();
    } catch (MaximumSizeLimit &msl) {
        msl.message();
    }


    cout << network.avgPopularity();
}
