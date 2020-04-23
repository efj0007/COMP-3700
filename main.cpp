#include <iostream>
#include <string>
#include <list>
#include "user.h"

using namespace std;

int main()
{
	User user = User();
	user.ListOfUsers.push_back(user.CreateAccount());
	user.ListOfUsers.push_back(user.CreateAccount());
	cout << endl << user.ListOfUsers.front().GetUsername() << endl;
	user.ChangeUsername();
}