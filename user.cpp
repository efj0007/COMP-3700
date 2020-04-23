#include <iostream>
#include <list>
#include <string>
#include "user.h"


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

	User User::CreateAccount() {
		
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
			cout << "Enter a email" << endl;
			cin >> mail;
		} while (!IsInputValid("Email", mail));
		return User(uname, pass, mail);
	}

	void User::ChangeUsername() {
		string uname;
		while (true) {
			cout << "Enter the new username" << endl;
			cin >> uname;
				if (IsInputValid("Username", uname)) {
					break;
				}
		}

		User::username = uname;
		cout << "Username successfully changed" << endl;
	}

	void User::ChangePass() {
		string pass;
		cout << "Enter the new password" << endl;
		cin >> pass;
		User::password = pass;
	}

	void User::ChangeEmail() {
		string mail;
		cout << "Enter the new email" << endl;
		cin >> mail;
		User::email = mail;
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
		string uname, pass, mail;
		cout << "Enter your username" << endl;
		cin >> uname;
		cout << "Enter your password" << endl;

	}

	void User::CheckUseAndPass(string uname, string pass) {
		//list<User>::iterator it = ListOfUsers.begin();
	}
