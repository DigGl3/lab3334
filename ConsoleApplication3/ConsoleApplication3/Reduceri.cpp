#include <bits/stdc++.h>
#include "Reduceri.h"
#include "Produs.h"
#include "Cos.h"
#include <Windows.h>
#include <conio.h>
using namespace std;


void promoCode(vector<Produse>& produse, vector<Cos>& cos,vector<string>& Voucher) {
    string s;
    cout << "Introdu promocode: ";
    getline(cin, s);
    bool aplicarePromocode = false;
    
    for (int j = 0; j < Voucher.size(); j++) {
        if (s == Voucher[j]) {
            cout << "Felicitari ai reducere 5% la primele 5 produse" << endl;
            Voucher.erase(Voucher.begin() + j);
            aplicarePromocode = true;
            for (int i = 0; i < produse.size(); i++) {
                if (produse[i].Ord >= 0 && produse[i].Ord <= 4)
                    produse[i].Price *= 0.95,cout<<produse[i].Name<<endl;
            }
            for (int i = 0; i < cos.size(); i++) {
                if (cos[i].Ord >= 0 && cos[i].Ord <= 4)
                    cos[i].Price *= 0.95;
            }
        }
    }
    if (aplicarePromocode == false) {
        cout << "Maybe next time" << endl;
    }
    cin.get();
}


void drawReduceri(int select,vector<string> red) {
    system("cls");
    cout << "Reduceri:" << endl;
    for (int i = 0; i < red.size(); i++) {
        if (i == select)
            cout << " > ";
        cout << red[i]<<endl;
    }
}

void livrareGratuita(vector<Cos> cos) {
    double sum = 0;
    for (int i = 0; i < cos.size(); i++) {
        sum += (cos[i].Quantity * cos[i].Price);
    }
    if (sum >= 100)
        cout << "Felicitari aveti Livrare Gratuita"; else
        cout << "Nu dispuneti de livrare Gratuita";
    cin.get();
}

void addReview(vector<Produse>& produse,vector<Cos>& cos) {
    string reviewMessage;
    cout << "Scrie recenzia ta: ";
    cin.ignore();
    getline(cin, reviewMessage);

    for (int i = 0; i < produse.size(); i++) {
        if (produse[i].Ord >= 5 && produse[i].Ord <= 9)
            produse[i].Price *= 0.9;
    }
    for (int i = 0; i < cos.size(); i++) {
        if (cos[i].Ord >= 5 && cos[i].Ord <= 9)
            cos[i].Price *= 0.9;
    }
    cout << "Felicitari! Ai lasat o recenzie." << endl;
}

void followSocialMedia(vector<Produse>& produse,vector<Cos>& cos) {
    cout << "Felicitari! Ai dat follow pe retelele sociale." << endl;
    for (int i = 0; i < produse.size(); i++) {
        if (produse[i].Ord >= 5 && produse[i].Ord <= 9)
            produse[i].Price *= 0.9;
    }
    for (int i = 0; i < cos.size(); i++) {
        if (cos[i].Ord >= 5 && cos[i].Ord <= 9)
            cos[i].Price *= 0.9;
    }
}

void drawReteleSociale(int select) {
    system("cls");
    cout << "Alege o actiune dorita:" << "\n";

    if (select == 0) cout << " > Lasa recenzie\n";
    else cout << "   Lasa recenzie\n";

    if (select == 1) cout << " > Follow pe Instagram\n";
    else cout << "   Follow pe Instagram\n";
}

void reteleSociale(vector<Produse>& produse, vector<Cos>& cos) {
    int select = 0;
    char key;

    while (true) {
        drawReteleSociale(select);
        key = _getch();

        if (key == 72) {
            select = (select - 1 + 2) % 2; 
        }
        else if (key == 80) { 
            select = (select + 1) % 2; 
        }
        else if (key == 13) { 
            if (select == 0) {
                addReview(produse,cos);
                cin.get();
            }
            else if (select == 1) {
                followSocialMedia(produse,cos);
                cin.get();
            }
            break; 
        }
    }
}


void drawUnuPlusUnu(int select, vector<Produse>& produse, vector<int> availableProducts) {
    cout << "Produse disponibile pentru oferta 1+1:" << endl;
    for (int i = 0; i < availableProducts.size(); ++i) {
        if (i == select) cout << " > ";
        cout << produse[availableProducts[i]].Name << " (Cantitate: " << produse[availableProducts[i]].Quantity / 2 << ")" << endl;
    }
    if (select == availableProducts.size())
        cout << " > ";
    cout << "Iesire";
}

void drawCantitateFor(int selected, int n) {
    for (int i = 0; i <= n; i++) {
        if (i == selected)
            cout << " > ";
        cout << i << endl;
    }
}


void drawCantitate(int selected, vector<Produse>& produse,vector<Cos>& cos,vector<int> avaibleProduct) {
    char key;
    int sl = 0;
    while (true) {
        system("cls");
        int cantitate = produse[avaibleProduct[selected]].Quantity / 2;
        drawCantitateFor(sl, cantitate);

        key = _getch();
        if (key == 72) {
            sl = (sl - 1 + cantitate+1) % (cantitate+1);
        }
        else if (key == 80) {
            sl = (sl + 1) % (cantitate+1);
        }
        else if (key == 13) {
            if (sl != 0){
                bool ok = false;
                Cos aux = Cos(produse[avaibleProduct[selected]].Name, produse[avaibleProduct[selected]].Id, produse[avaibleProduct[selected]].Price, sl, produse[avaibleProduct[selected]].Ord);
                for (int i = 0; i < cos.size(); i++) {
                    if (cos[i].Name == aux.Name && cos[i].Price == aux.Price) {
                        cos[i].Quantity += sl;
                        ok = true;
                        break;
                    }
                }
                if (ok == false) {
                    cos.push_back(aux);
                }
                ok = false;
                aux.Price = 0;
                for (int i = 0; i < cos.size(); i++) {
                    if (cos[i].Name == aux.Name && cos[i].Price == aux.Price) {
                        cos[i].Quantity += sl;
                        ok = true;
                        break;
                    }
                }
                if (ok == false) {
                    cos.push_back(aux);
                }
                produse[avaibleProduct[selected]].Quantity -= sl * 2;
                if (produse[avaibleProduct[selected]].Quantity == 0)
                    produse.erase(produse.begin() + avaibleProduct[selected]);
                break;
            }
            else {
                break;
            }
        }
    }

    
}

void unuPlusUnu(vector<Produse>& produse, vector<Cos>& cos) {
    vector<int> availableProducts;
    for (int i = 0; i < produse.size(); i++) {
        if (produse[i].Quantity > 1 && produse[i].Ord >= 10 && produse[i].Ord <= 14) {
            availableProducts.push_back(i);
        }
    }
    //cin.get();

    if (availableProducts.empty()) {
        cout << "Nu sunt produse disponibile pentru oferta 1+1." << endl;
        cin.get();
        return;
    }

    int select = 0;
    char key;

    while (true) {
        system("cls");
        drawUnuPlusUnu(select, produse, availableProducts);
        

        key = _getch();
        if (key == 72) {
            select = (select - 1 + availableProducts.size()+1) % (availableProducts.size()+1);
        }
        else if (key == 80) {
            select = (select + 1) % (availableProducts.size() + 1);
        }
        else if (key == 13) {
            if (select != availableProducts.size()) {
                drawCantitate(select, produse, cos, availableProducts);
                return;
            }
            else {
                return;
            }
        }
    }
}

void drawCombouri(vector<Produse>& produs, vector<Cos>& cos,int select,vector<string> comb) {
    system("cls");
    for (int i = 0; i < comb.size(); i++) {
        if (i == select)
            cout << " > ";
        cout << comb[i];
        cout << endl;
    }
}


void addCos(Produse aux, vector<Cos>& cos) {
    for (int i = 0; i < cos.size(); i++) {
        if (cos[i].Name == aux.Name && cos[i].Price == aux.Price) {
            cos[i].Quantity += 1;
            return;
        }
    }
    Cos aux1 = Cos(aux.Name, aux.Id, aux.Price, 1, aux.Ord);
    cos.push_back(aux1);

}

void addRosii_Om(vector<Produse>& produse, vector<Cos>& cos) {
    bool okRosii = false;
    bool okOm = false;
    int mini = 9999;

    for (int i = 0; i < produse.size(); i++) {
        if (produse[i].Ord == 19)
            okRosii = true;
        if (produse[i].Ord == 18)
            okOm = true;
    }
    if (okRosii == false || okOm == false) {
        cout << "Promotia nu mai este valabila";
        return;
    }
    else {
        cout << "Felicitari ai cumparat un produs";
    }
    // ADD rosii 
    for (int i = 0; i < produse.size(); i++) {
        if (produse[i].Ord == 19) {
            addCos(produse[i],cos);
            produse[i].Quantity -= 1;
            if (produse[i].Quantity == 0)
                produse.erase(produse.begin() + i);
            break;
        }
    }
    // ADD om
    for (int i = 0; i < produse.size(); i++) {
        if (produse[i].Ord == 18) {
            addCos(produse[i],cos);
            produse[i].Quantity -= 1;
            if (produse[i].Quantity == 0)
                produse.erase(produse.begin() + i);
            break;
        }
    }

} 

void addMazare_Coca(vector<Produse>& produse, vector<Cos>& cos) {
    bool okRosii = false;
    bool okOm = false;
    int mini = 9999;

    for (int i = 0; i < produse.size(); i++) {
        if (produse[i].Ord == 17)
            okRosii = true;
        if (produse[i].Ord == 16)
            okOm = true;
    }
    if (okRosii == false || okOm == false) {
        cout << "Promotia nu mai este valabila";
        return;
    }
    else {
        cout << "Felicitari ai cumparat un produs";
    }
    // ADD rosii 
    for (int i = 0; i < produse.size(); i++) {
        if (produse[i].Ord == 17) {
            addCos(produse[i], cos);
            produse[i].Quantity -= 1;
            if (produse[i].Quantity == 0)
                produse.erase(produse.begin() + i);
            break;
        }
    }
    // ADD om
    for (int i = 0; i < produse.size(); i++) {
        if (produse[i].Ord == 16) {
            addCos(produse[i], cos);
            produse[i].Quantity -= 1;
            if (produse[i].Quantity == 0)
                produse.erase(produse.begin() + i);
            break;
        }
    }
}

void addMiere_Avocado(vector<Produse>& produse, vector<Cos>& cos) {
    bool okRosii = false;
    bool okOm = false;
    int mini = 9999;

    for (int i = 0; i < produse.size(); i++) {
        if (produse[i].Ord == 15)
            okRosii = true;
        if (produse[i].Ord == 14)
            okOm = true;
    }
    if (okRosii == false || okOm == false) {
        cout << "Promotia nu mai este valabila";
        return;
    }
    else {
        cout << "Felicitari ai cumparat un produs";
    }
    // ADD rosii 
    for (int i = 0; i < produse.size(); i++) {
        if (produse[i].Ord == 15) {
            addCos(produse[i], cos);
            produse[i].Quantity -= 1;
            if (produse[i].Quantity == 0)
                produse.erase(produse.begin() + i);
            break;
        }
    }
    // ADD om
    for (int i = 0; i < produse.size(); i++) {
        if (produse[i].Ord == 14) {
            addCos(produse[i], cos);
            produse[i].Quantity -= 1;
            if (produse[i].Quantity == 0)
                produse.erase(produse.begin() + i);
            break;
        }
    }
}

void addPeste_Ulei(vector<Produse>& produse, vector<Cos>& cos) {
    bool okRosii = false;
    bool okOm = false;
    int mini = 9999;

    for (int i = 0; i < produse.size(); i++) {
        if (produse[i].Ord == 13)
            okRosii = true;
        if (produse[i].Ord == 12)
            okOm = true;
    }
    if (okRosii == false || okOm == false) {
        cout << "Promotia nu mai este valabila";
        return;
    }
    else {
        cout << "Felicitari ai cumparat un produs";
    }
    // ADD rosii 
    for (int i = 0; i < produse.size(); i++) {
        if (produse[i].Ord == 13) {
            addCos(produse[i], cos);
            produse[i].Quantity -= 1;
            if (produse[i].Quantity == 0)
                produse.erase(produse.begin() + i);
            break;
        }
    }
    // ADD om
    for (int i = 0; i < produse.size(); i++) {
        if (produse[i].Ord == 12) {
            addCos(produse[i], cos);
            produse[i].Quantity -= 1;
            if (produse[i].Quantity == 0)
                produse.erase(produse.begin() + i);
            break;
        }
    }
}

void addOrez_fasole(vector<Produse>& produse, vector<Cos>& cos) {
    bool okRosii = false;
    bool okOm = false;
    int mini = 9999;

    for (int i = 0; i < produse.size(); i++) {
        if (produse[i].Ord == 11)
            okRosii = true;
        if (produse[i].Ord == 10)
            okOm = true;
    }
    if (okRosii == false || okOm == false) {
        cout << "Promotia nu mai este valabila";
        return;
    }
    else {
        cout << "Felicitari ai cumparat un produs";
    }
    // ADD rosii 
    for (int i = 0; i < produse.size(); i++) {
        if (produse[i].Ord == 11) {
            addCos(produse[i], cos);
            produse[i].Quantity -= 1;
            if (produse[i].Quantity == 0)
                produse.erase(produse.begin() + i);
            break;
        }
    }
    // ADD om
    for (int i = 0; i < produse.size(); i++) {
        if (produse[i].Ord == 10) {
            addCos(produse[i], cos);
            produse[i].Quantity -= 1;
            if (produse[i].Quantity == 0)
                produse.erase(produse.begin() + i);
            break;
        }
    }
}


void Combouri(vector<Produse>& produs, vector<Cos>& cos) {
    vector<string> comb{
        "Rosii + Om",
        "Mazare + Coca Cola",
        "Miere + Avocado",
        "Peste + Ulei",
        "Orez brun + fasole",
        "Iesire"
    };
    int select = 0;
    int size = comb.size();
    char key;
    while (true) {
        drawCombouri(produs, cos, select, comb);
        key = _getch();
        if (key == 72) {
            select = (select - 1 + size) % size;
        }
        else if (key == 80) {
            select = (select + 1) % size;
        }
        else if (key == 13) {
            if (select == 0) {
                // Rosii om
                addRosii_Om(produs, cos);
            }
            else if (select == 1) {
                addMazare_Coca(produs, cos);
                // Mazare cocoa
            }
            else if (select == 2) {
                addMiere_Avocado(produs, cos);
                // Miere + avocado
            }
            else if (select == 3) {
                addPeste_Ulei(produs, cos);
                // peste ulei
            }
            else if (select == 4) {
                addOrez_fasole(produs, cos);
                // Orez brun fasole
            }
            else {
                return;
            }
            cin.get();
        }
    }
}


void vizualReduceri(vector<Produse>& produse, vector<Cos>& cos, vector<string>& Voucher) {
    vector<string> redu = {
        "Promocode",
        "Retele Sociale",
        "Livrare Gratuita",
        "1+1",
        "Combo-uri",
        "Iesire"
    };

    char key;
    int select = 0;
    while (true) {
        drawReduceri(select, redu);
        key = _getch();
        if (key == 72) {
            select = (select - 1 + redu.size()) % redu.size();
        }
        else if (key == 80) {
            select = (select + 1) % redu.size();
        }
        else if (key == 13) {

            if (select == 0) {
                // Promocode
                promoCode(produse, cos, Voucher);
                cin.get();
                return;
            }
            else if (select == 1) {
                //Retele sociale
                reteleSociale(produse, cos);
                return;
            }
            else if (select == 2) {
                //Livrare Gratuita
                livrareGratuita(cos);
                cin.get();
                return;
            }
            else if (select == 3) {
                //1+1
                unuPlusUnu(produse, cos);
                return;
            }
            else if (select == 4) {
                //Combo-uri
                Combouri(produse, cos);
                return;
            }
            else if (select = redu.size() - 1) {
                return;
            }
        }
    }
}