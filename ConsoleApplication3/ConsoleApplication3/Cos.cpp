#include "Cos.h"
#include "User.h"
#include <fstream>
#include <bits/stdc++.h>
using namespace std;
ofstream out("VipPerson.out");

void Cos::afisare() const {
    cout << "Name: " << Name << " <<<< ";
    cout << "Id: " << Id << " <<<< ";
    cout << "Price: " << Price << " <<<< ";
    cout << "Quantity: " << Quantity;
    cout << endl;
}

Cos::Cos(string name, string id, double price, int quantity, int ord) {
    Name = name;
    Id = id;
    Price = price;
    Quantity = quantity;
    Ord = ord;
}

void Final(vector<Cos> cos, int userId, vector<User>& user) {
    cout << "Cosul dvs:\n";
    double sum = 0;
    for (int i = 0; i < cos.size(); i++) {
        cos[i].afisare();
        sum += (cos[i].Price * cos[i].Quantity);
    }
    if (user[userId].Cheltuieli >= 50000) {
        user[userId].Vip = true;
    }
    if (user[userId].Vip == true) {
        cout << "Felicitari sunteti VIP si aveti reducere 5%" << endl;
        sum *= 0.95;
    }

    if (user[userId].Reducere == true && user[userId].ReducereAplicata == false) {
        cout << "Aveti un cupon de 10% doriti sal aplicati Tasteaza y/n: ";
        string s1;
        getline(cin, s1);
        if (s1 == "y") {
            sum *= 0.90;
            cout << "Felicitari ati folosit cuponul!!!" << endl;
            user[userId].ReducereAplicata = true;
        }
    }
    cout << user[userId] << endl;
    user[userId].Conectari += 1;

    if (sum < 500) {
        user[userId].ReducereEligibi = false;
    }

    if (user[userId].Conectari >= 5 && user[userId].Cheltuieli >= 4000 && user[userId].ReducereEligibi == true) {
        user[userId].Reducere = true;
    }
    cout << "Total: " << sum << "\n";
    user[userId] + sum;
    if (user[userId].Cheltuieli >= 50000) {
        user[userId].Vip = true;
        if (user[userId].Vipfile == false) {
            setVipFile(user[userId]);
            user[userId].Vipfile = true;
            out<<user[userId]<<endl;
        }
    }
}

void vizualizareCos(vector<Cos> cos) {
    if (cos.size() == 0)
        cout << "Cos gol" << endl;
    for (int i = 0; i < cos.size(); i++) {
        cos[i].afisare();

    }
}