#include <iostream>
#include <list>
#include <string>
#include "user.h"

using namespace std;

	User::User() 
	{
	//Default Constructor for intiailization
	}

	//Constructor
	User::User(string uname, string psswrd, string mail) 
	{
		username = uname;
		password = psswrd;
		email = mail;
	}

	//Get logged in user's username
	string User::GetUsername() 
	{
		return username;
	}

	//Get logged in user's password
	string User::GetPassword() 
	{
		return password;
	}

	//Get logged in user's email
	string User::GetEmail() 
	{
		return email;
	}

	//Used for creating account
	void User::CreateAccount() 
	{
		string uname, pass, vPass, mail;
		do 
		{
			cout << "***Account Creation Page***\n" << endl;
			cout << "Enter a Username: ";
			cin >> uname;
		} while (!IsInputValid("Username", uname));
		while (true) {
			cout << "Enter a Password: ";
			cin >> pass;
			cout << "Verify the password: ";
			cin >> vPass;
			//Loop until passwords match
			if (pass == vPass) 
			{
				break;
			}
			cout << "\nThe passwords do not match, try again." << endl;
		}
		do 
		{
			cout << "Enter an email: ";
			cin >> mail;
		} while (!IsInputValid("Email", mail));
		ListOfUsers.push_back(User(uname, pass, mail));
	}

	//Change currently logged in user's username
	void User::ChangeUsername() 
	{
		if (!LoggedOn) 
		{
			cout << "Please login first." << endl;
			return;
		}
		string uname;
		while (true) 
		{
			cout << "Enter the new username: ";
			cin >> uname;
				if (IsInputValid("Username", uname)) 
				{
					break;
				}
		}

		(*LoggedAccount).username = uname;
		cout << "Username successfully changed to " << uname << endl;
	}

	//Change currently logged in user's password
	void User::ChangePass() 
	{
		if (!LoggedOn) 
		{
			cout << "Please login first." << endl;
			return;
		}
		string pass;
		cout << "Enter the new password: ";
		cin >> pass;
		(*LoggedAccount).password = pass;
	}

	//Change currently logged in user's email
	void User::ChangeEmail() 
	{
		if (!LoggedOn) 
		{
			cout << "Please login first." << endl;
			return;
		}
		string mail;
		while (true) 
		{
			cout << "Enter the new email: ";
			cin >> mail;
			if (IsInputValid("Email", mail)) 
			{
				break;
			}
		}
		(*LoggedAccount).email = mail;
		cout << "Email successfully changed to " << mail << endl;
	}

	//Checks to see if Username/Email is taken
	bool User::IsInputValid(string CheckParam, string UserInfo) 
	{
		if (ListOfUsers.empty()) 
		{
			return true;
		}
		list<User>::iterator it = ListOfUsers.begin();
		do  
		{
			if (CheckParam == "Username") {
				if (UserInfo == (*it).GetUsername()) 
				{
					cout << "Username " << UserInfo << " already in use." << endl;
					return false;
				}
			}
			if (CheckParam == "Email") 
			{
				if (UserInfo == (*it).GetEmail()) 
				{
					cout << "Email " << UserInfo << " is already registered" << endl;
					return false;
				}
			}
			it++;
		} while (it != ListOfUsers.end());
		return true;
	}

	//Login based off user's input of credentials
	void User::Login() 
	{
		int Attempts = 0, MaxAttempts = 5;
		string uname, pass, mail;
		while (Attempts < MaxAttempts) 
		{
			cout << "\n***Login Page***\n" << endl;
			cout << "Enter your username: ";
			cin >> uname;
			cout << "Enter your password: ";
			cin >> pass;
			if (IsAccountFound(uname, pass)) 
			{
				cout << "\nLogin Sucessful!" << endl;
				LoggedOn = true;
				LoggedAccount = FindAccount(uname, pass);
				break;
			}
			cout << "Invalid username or password please try again." << endl << endl;
			Attempts++;
		}
		if (Attempts >= MaxAttempts) 
		{
			cout << "You've exceeded the maximum number of attempts please try again later." << endl;
		}
	}

	//Log off the currently logged in user
	void User::LogOff() 
	{
		cout << "Logging out...\n" << endl;
		LoggedOn = false;
	}

	//Check to see if someone is currently logged in
	bool User::LogOn() 
	{
		return LoggedOn;
	}

	//Search the ListOfUsers for a specific account and return the user
	list<User>::iterator User::FindAccount(string uname, string pass) 
	{
		list<User>::iterator it = ListOfUsers.begin();
		do 
		{
			if (uname == (*it).GetUsername()) 
			{
				if (pass == (*it).GetPassword()) 
				{
					return it;
				}
			}
			it++;
		} while (it != ListOfUsers.end());
		//Note this returns the user with null string member variables
		return it;
	}

	//Search the ListOfUsers to see if the username already exists
	bool User::IsAccountFound(string uname, string pass) 
	{
		list<User>::iterator Account = FindAccount(uname, pass);
		if (Account == ListOfUsers.end()) 
		{
			return false;
		}
		if ((*Account).GetUsername() == uname) 
		{
			return true;
		}
		return false;
	}
