#include "User.h"
#include <bits/stdc++.h>
#include "Cos.h"
#include <Windows.h>
#include <conio.h>
using namespace std;

void drawMenuUser(int& chosen, vector<string> Meniu) {
	system("cls");
	for (int i = 0; i < Meniu.size(); i++) {
		if (i == chosen) {
			cout << " > ";
		}
		cout << Meniu[i] << endl;
	}
}

int logare(vector<User> user) {
	system("cls");
	cout << "Introdu Username: ";
	string s1;
	getline(cin, s1);
	for (int i = 0; i < user.size(); i++) {
		if (s1 == user[i].Name) {
			bool ok = false;
			while (ok == false) {
				cout << "Introdu Parola: ";
				string s2;
				getline(cin, s2);
				if (s2 == user[i].Password)
					return i;
				else {
					system("cls");
					cout << "Parola gresita" << endl;
				}
			}
		}
	}

	return -1;
}

void creazaCont(vector<User>& user) {
	system("cls");
	bool ok = true;
	string s1;
	while (ok) {
		cout << "Introdu Username: ";
		ok = false;
		getline(cin, s1);
		for (int i = 0; i < user.size(); i++) {
			if (s1 == user[i].Name) {
				system("cls");
				cout << "Exista deja acest username Scrieti altul" << endl;
				ok = true;
			}
		}
	}
	string Id;
	cout << "Introdu idnp: ";
	getline(cin, Id);
		while (true) {
			string s2;
			cout << "Introdu parola: ";
			getline(cin, s2);
			string s2copy;
			cout << "Introdu inca odata parola: ";
			getline(cin, s2copy);
			if (s2 == s2copy) {
				user.push_back(User(s1, s2,Id));
				return;
			}
			system("cls");
			cout << "Parolele nu coincid" << endl;
		}
}

int addUserFunctions(vector<User> &user) {
	vector <string> Options = {
		"Login",
		"Create account"
	};
	char key;
	int chosenUser = 0;
	int sizeOptions = Options.size();
	while (true) {
		drawMenuUser(chosenUser, Options);
		key = _getch();
		if (key == 72) {
			chosenUser = (chosenUser - 1 + sizeOptions) % sizeOptions;
		}
		else if (key == 80) {
			chosenUser = (chosenUser + 1) % sizeOptions;
		}
		else if (key == 13) {
			if (chosenUser == 0) {
				// Logare
				int i = logare(user);
				if (i == -1) {
					cout << "Nu merge" << endl;
				} else 
					return i;
			}
			else if (chosenUser == 1) {
				// creare cont
				creazaCont(user);
			}
		}
	}

}
