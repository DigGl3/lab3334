#ifndef BUY_H
#define BUY_H
#include <bits/stdc++.h>
#include "Produs.h"
#include "Cos.h"
using namespace std;

void drawCumpara(int selected, vector<Produse>& p, vector<Cos>& cos);

void drawCantitatea(int cantitatea, int sizeOptions);

void addToCos(int cantitatea, int selected, vector<Produse>& p, vector<Cos>& cos);

void addCos(int selected, vector<Produse>& p, vector<Cos>& cos);

void cumpara(vector<Produse>& p, vector<Cos>& cos);

#endif // !Buy
