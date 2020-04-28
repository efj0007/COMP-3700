#pragma once
#include <list>
#include <iostream>
#include "user.h"
using namespace std;
class Community
{
public:
	Community();
	Community(string Name, int MaxMem, User Owner, bool IsPrivate);
	void CreateCommunity();
	void ListCommunities();
	void JoinCommunity();
	list<Community>::iterator FindCommunity(string ComName);
public:
	string CommunityName;
	int NumberOfMembers = 0;
	int MaxMembers;
	User Creator;
	bool Private;
	list<User> ListOfComUsers;
	list<Community> ListOfCommunities;
};