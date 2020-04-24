#include <iostream>
#include <list>
#include <string>
#include "user.h"

using namespace std;

	User::User() {
	//Default Constructor for intiailization
	}
	//Constructor
	User::User(string uname, string psswrd, string mail) {
		User::username = uname;
		User::password = psswrd;
		User::email = mail;
	}

	string User::GetUsername() {
		return User::username;
	}

	string User::GetPassword() {
		return User::password;
	}

	string User::GetEmail() {
		return User::email;
	}

	void User::CreateAccount() {
		
		string uname, pass, vPass, mail;
		do {
			cout << "Enter a Username" << endl;
			cin >> uname;
		} while (!IsInputValid("Username", uname));
		while (true) {
			cout << "Enter a Password" << endl;
			cin >> pass;
			cout << "Verify the password" << endl;
			cin >> vPass;
			//Loop until passwords match
			if (pass == vPass) {
				break;
			}
			cout << "\nPasswords Mismatch, retry" << endl;
		}
		do {
			cout << "Enter an email" << endl;
			cin >> mail;
		} while (!IsInputValid("Email", mail));
		ListOfUsers.push_back(User(uname, pass, mail));
	}

	void User::ChangeUsername() {
		if (!LoggedOn) {
			cout << "Please login first" << endl;
			return;
		}
		string uname;
		while (true) {
			cout << "Enter the new username" << endl;
			cin >> uname;
				if (IsInputValid("Username", uname)) {
					break;
				}
		}

		(*LoggedAccount).username = uname;
		cout << "Username successfully changed" << endl;
	}

	void User::ChangePass() {
		if (!LoggedOn) {
			cout << "Please login first" << endl;
			return;
		}
		string pass;
		cout << "Enter the new password" << endl;
		cin >> pass;
		(*LoggedAccount).password = pass;
	}

	void User::ChangeEmail() {
		if (!LoggedOn) {
			cout << "Please login first" << endl;
			return;
		}
		string mail;
		while (true) {
			cout << "Enter the new email" << endl;
			cin >> mail;
			if (IsInputValid("Email", mail)) {
				break;
			}
		}

		(*LoggedAccount).email = mail;
		cout << "Username successfully changed" << endl;
	}

	//Checks to see if Username/Email is taken
	bool User::IsInputValid(string CheckParam, string UserInfo) {
		if (ListOfUsers.empty()) {
			return true;
		}
		list<User>::iterator it = ListOfUsers.begin();
		do  {
			if (CheckParam == "Username") {
				if (UserInfo == (*it).GetUsername()) {
					cout << "Username already in use" << endl;
					return false;
				}
			}
			if (CheckParam == "Email") {
				if (UserInfo == (*it).GetEmail()) {
					cout << "Email already registered" << endl;
					return false;
				}
			}
			it++;
		} while (it != ListOfUsers.end());
		return true;
	}

	void User::Login() {
		int Attempts = 0, MaxAttempts = 5;

		string uname, pass, mail;
		while (Attempts < MaxAttempts) {
			cout << "Enter your username" << endl;
			cin >> uname;
			cout << "Enter your password" << endl;
			cin >> pass;
			if (IsAccountFound(uname, pass)) {
				cout << "Login Sucessful!" << endl;
				LoggedOn = true;
				LoggedAccount = FindAccount(uname, pass);
				break;
			}
			cout << "Invalid username or password please try again" << endl << endl;
			Attempts++;
		}
		if (Attempts >= MaxAttempts) {
			cout << "You've exceeded the maximum amount of attempts please try again later" << endl;
		}
	}

	void User::LogOff() {
		LoggedOn = false;
		(*LoggedAccount).username = nullptr;
		(*LoggedAccount).password = nullptr;
	}

	list<User>::iterator User::FindAccount(string uname, string pass) {
		list<User>::iterator it = ListOfUsers.begin();
		do {
			if (uname == (*it).GetUsername()) {
				if (pass == (*it).GetPassword()) {
					return it;
				}
			}
			it++;
		} while (it != ListOfUsers.end());
		//Note this returns the user with null string member variables
		return it;
	}

	bool User::IsAccountFound(string uname, string pass) {
		list<User>::iterator Account = FindAccount(uname, pass);
		if (Account == ListOfUsers.end()) {
			return false;
		}
		if ((*Account).GetUsername() == uname) {
			return true;
		}
		return false;
	}