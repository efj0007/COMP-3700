// Nitrox.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Test.h"
#include "user.h"
#include <list>
#include "Community.h"
using namespace std;
list<User>::iterator LoggedAccount;
int main()
{
	User user = User();
	Community ComObj = Community();
	user.CreateAccount();
	user.CreateAccount();
	//user.ListOfUsers.push_back(user.CreateAccount());
	user.Login();
	ComObj.CreateCommunity();
	ComObj.CreateCommunity();
	ComObj.CreateCommunity();
	ComObj.ListCommunities();
	ComObj.JoinCommunity();
	user.Login();
	ComObj.JoinCommunity();
	//cout << endl << ComObj.ListOfCommunities.front().CommunityName) << endl;
	cout << ComObj.ListOfCommunities.front().Creator.username << endl;
	cout << ComObj.ListOfCommunities.front().ListOfComUsers.front().username << endl;
	//user.ChangeUsername();
	//cout << endl << user.ListOfUsers.front().GetUsername() << endl;
}
