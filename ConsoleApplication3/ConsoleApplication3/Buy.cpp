#include <bits/stdc++.h>
#include "Buy.h"
#include "Produs.h"
#include "Cos.h"
#include <Windows.h>
#include <conio.h>
using namespace std;

void drawCumpara(int selected,vector<Produse>& p, vector<Cos>& cos) {
    //Afisez toata produsele si aleg din ele
    system("cls");
    cout << "Produse:" << "\n";
    for (int i = 0; i < p.size(); i++) {
        if (i == selected)
            cout << " > ";
        p[i].afisare();
    }
    if (selected == p.size())
        cout << " > Iesire < "; else
            cout << "Iesire";


}


void drawCantitatea(int cantitatea,int sizeOptions) {
    // Aleg cata cantitatea vreau sa cumpar
    system("cls");
    cout << "Alege cantitatea:" << "\n";
    for (int i = 0; i < sizeOptions; i++) {
        if (i == cantitatea)
            cout << " > " << i << " <" << "\n"; else
            cout << i << "\n";
    }
}

void addToCos(int cantitatea, int selected, vector<Produse>& p, vector<Cos>& cos) {
    // Am cantitatea si la produs[selecte] aduag in cos
    p[selected].Quantity -= cantitatea;

    for (int i = 0; i < cos.size(); i++) {
        if (cos[i].Name == p[selected].Name && cos[i].Price == p[selected].Price) {
            cos[i].Quantity += cantitatea;
            if (p[selected].Quantity == 0) {
                p.erase(p.begin() + selected);
            }
            return;
        }
    }
    Cos aux = Cos(p[selected].Name, p[selected].Id, p[selected].Price, cantitatea,p[selected].Ord);
    cos.push_back(aux);

    if (p[selected].Quantity == 0) {
        p.erase(p.begin() + selected);
    }
}

void addCos(int selected, vector<Produse>& p, vector<Cos>& cos) {
    //Aici am looop pentru a alege cantitatea
    int cantitatea = 0;
    char key = 32;
    while ((int)key != 13) {
        int sizeOptions = p[selected].Quantity + 1;
        drawCantitatea(cantitatea,sizeOptions);
        key = _getch();
        if (key == 72) {
            cantitatea = (cantitatea - 1 + sizeOptions) % sizeOptions;
        }
        else if (key == 80) {
            cantitatea = (cantitatea + 1) % sizeOptions;
        }
        else if (key == 13) {
            if (cantitatea == 0) {
                break;
            }
            else {
                addToCos(cantitatea, selected, p, cos);
            }
        }
    }
}

void cumpara(vector<Produse>& p, vector<Cos>& cos) {
    // Loop pentru a alege produs
    int selected = 0;
    char key;
    while (true) {
        int sizeOptions = p.size() + 1;
        selected = selected % sizeOptions;
        drawCumpara(selected,p,cos);
        key = _getch();
        if (key == 72) {
            selected = (selected - 1 + sizeOptions) % sizeOptions;
        }
        else if (key == 80) {
            selected = (selected + 1) % sizeOptions;
        }
        else if (key == 13) {
            if (selected != sizeOptions - 1) {
                addCos(selected, p, cos);
            }
            else {
                break;
            }
        }

    }
}
