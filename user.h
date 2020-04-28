  
#pragma once
#include <string>
#include <list>

using namespace std;

class User
{

public:
	User();
	User(string uname, string psswrd, string mail);
	string GetUsername();
	string GetPassword();
	string GetEmail();
	void CreateAccount();
	void ChangePass();
	void ChangeUsername();
	void ChangeEmail();
	bool IsInputValid(string CheckParam, string UserInfo);
	void Login();
	list<User>::iterator FindAccount(string uname, string pass);
	bool IsAccountFound(string uname, string pass);
	void LogOff();
	bool LogOn();
public:
	string username;
	string password;
	string email;
	bool LoggedOn = false;
	list<User> ListOfUsers; //Simulates Nitrox Database that stores all users/userinfo
};
extern list<User>::iterator LoggedAccount; 