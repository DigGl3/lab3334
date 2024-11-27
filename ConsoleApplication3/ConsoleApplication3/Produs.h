#ifndef Produs
#define Produs

#include <bits/stdc++.h>
using namespace std;

class Produse {
public:
    string Name;
    string Id;
    double Price;
    int Quantity;
    int Ord;
    Produse() {
        Name = "No name";
        Id = "678923";
        Price = 0;
        Quantity = 0;
        Ord = 0;
    }
    Produse(string name, string id, double price, int quantity,int ord) {
        Name = name;
        Id = id;
        Price = price;
        Quantity = quantity;
        Ord = ord;
    }
    void afisare() {
        cout << "Name: " << Name << " <<<< ";
        cout << "Id: " << Id << " <<<< ";
        cout << "Price: " << Price << " <<<< ";
        cout << "Quantity: " << Quantity;
        cout << endl;
    }
    Produse(const Produse& other) {
        Name = other.Name;
        Id = other.Id;
        Price = other.Price;
        Quantity = other.Quantity;
        Ord = other.Ord;
    }
};


void addProduse(vector<Produse>& produs);
#endif // !Produs