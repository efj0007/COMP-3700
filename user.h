#include <string>
#include <iostream>

using namespace std; 

class User
{

public:
	User();
	User(string uname, string psswrd, string mail);
	string GetUsername();
	string GetPassword();
	string GetEmail();
	User CreateAccount();
	void ChangePass();
	void ChangeUsername();
	void ChangeEmail();
	bool IsInputValid(string CheckParam, string UserInfo);
	void Login();
	void CheckUseAndPass(string uname, string pass);
public:
	string username;
	string password;
	string email;
	list<User> ListOfUsers;
};
