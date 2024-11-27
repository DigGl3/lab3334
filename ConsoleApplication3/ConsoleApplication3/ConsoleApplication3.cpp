#include <bits/stdc++.h>
#include <Windows.h>
#include <conio.h>
#include "Cos.h"
#include "Produs.h"
#include "Buy.h"
#include "Meniu.h"
#include "Reduceri.h"
#include "addUser.h"
#include "User.h"

using namespace std;

int main() {
    vector<Produse> produs;
    addProduse(produs);
    vector<string> Voucher;
    Voucher.push_back("Cristi");
    Voucher.push_back("Jmecher");
    Voucher.push_back("Hello");
    Voucher.push_back("World");
    vector<string> options = {
        "Store",
        "Cosul",
        "Reduceri",
        "Iesire"
    };
    int selected = 0;
    char key;
    vector<User> user;
    user.push_back(User("Christian", "12345678","12345678"));
    while (true) {
        int i = addUserFunctions(user);
        vector<Cos> Cosul;
        while (true) {
            drawMenu(selected, options);
            int sizeOptions = (int)options.size();
            selected = selected % sizeOptions;
            key = _getch();
            if (key == 72) {
                selected = (selected - 1 + sizeOptions) % sizeOptions;
            }
            else if (key == 80) {
                selected = (selected + 1) % sizeOptions;
            }
            else if (key == 13) {
                if (selected == 3) {
                    Final(Cosul,i,user);
                    Cosul.clear();
                    cin.get();
                    break;
                }
                else {
                    if (selected == 0) {
                        cumpara(produs, Cosul);
                    }
                    else if (selected == 1) {
                        vizualizareCos(Cosul);
                        cin.get();
                    }
                    else if (selected == 2) {
                        vizualReduceri(produs, Cosul, Voucher);
                    }
                }
            }
        }
    }
    return 0;
}