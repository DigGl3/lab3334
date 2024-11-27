#include <bits/stdc++.h>
#include "Meniu.h"
using namespace std;

void drawMenu(int selected, vector<string> options) {
    system("cls");
    cout << "Meniu:" << endl;

    for (int i = 0; i < options.size(); i++) {
        if (i == selected) {
            cout << "> " << options[i] << " <\n";
        }
        else {
            cout << " " << options[i] << "\n";
        }
    }
}