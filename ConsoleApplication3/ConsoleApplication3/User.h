#ifndef User_h
#define User_h
#include <bits/stdc++.h>
using namespace std;

class User {
public:
    string Name;
    string Id;
    string Password;
    double Cheltuieli;
    int Conectari;
    bool Vip;
    bool Reducere;
    bool ReducereAplicata;
    bool ReducereEligibi;
    bool Vipfile;

    User(string name, string password, string id) {
        Name = name;
        Id = id;
        Vipfile = false;
        Password = password;
        Cheltuieli = 0;
        ReducereEligibi = true;
        Conectari = 0;
        Vip = false;
        Reducere = false;
        ReducereAplicata = false;
        VipFile = false;
    }

    friend ostream& operator<<(ostream& out, const User& user) {
        out << "User: " << user.Name << ", IDNP: " << user.Id;
        return out;
    }

    bool operator==(const User& other) const {
        return Id == other.Id;
    }
    
    User& operator+(double amount) {
        Cheltuieli += amount;
        return *this;
    }

    User& operator-(double amount) {
        Cheltuieli -= amount;
        return *this;
    }

    User& operator++() {
        ++Conectari;
        return *this;
    }

    bool isEligibil(User& aux) {
        return aux.ReducereEligibi;
    }
    friend void setVipFile(User& user);

private:
    bool VipFile;
};

inline void setVipFile(User& user) {
    user.Vip = true;
}

#endif // User_h
