#pragma once
#include <list>
#include <iostream>
#include "user.h"

using namespace std;

//Creates all of the functions and class variables for the Communtiy class

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
	list<User> ListOfComUsers; //Simulates Database
	list<Community> ListOfCommunities; //Simulates Database

};