#ifndef Cos_h
#define Cos_h
#include "Produs.h"
#include "User.h"
#include <bits/stdc++.h>

using namespace std;


class Cos {
public:
    int Ord;
    string Name;
    string Id;
    double Price;
    int Quantity;
    void afisare() const;

    Cos(string name, string id, double price, int quantity, int ord);
};


void Final(vector<Cos> cos, int userId, vector<User>& user);

void vizualizareCos(vector<Cos> cos);

#endif //Cos