#include "Community.h"
#include <iostream>
#include <list>
using namespace std;

Community::Community()
{
}

Community::Community(string Name, int MaxMem, User Owner, bool IsPrivate) {
	CommunityName = Name;
	MaxMembers = MaxMem;
	NumberOfMembers = 1;
	Creator = Owner;
	Private = IsPrivate;
	ListOfComUsers;
}

void Community::CreateCommunity() {
	string ComName;
	char PermIn;
	int MaxMem;
	bool Perm = false;
	User Owner = *LoggedAccount;
	cout << "Enter the name of the community ";
	cin >> ComName;
	cout << "Enter the maximum number of community memebers you would like to allow ";
	cin >> MaxMem;
	cout << "Do you wish for you community to be private? Type y/n ";
	cin >> PermIn;
	if (PermIn == 'y') {
		Perm = true;
	}
	ListOfCommunities.push_back(Community(ComName, MaxMem, (Owner), Perm));
}

void Community::ListCommunities() {
	list<Community>::iterator it = ListOfCommunities.begin();
	for (it; it != ListOfCommunities.end(); it++) {
		cout << (*it).CommunityName << endl;
	}
}

void Community::JoinCommunity() {
	string ComName;
	Community Community;
	while (true) {
		cout << "Name the community you wish to join ";
		cin >> ComName;
		if (FindCommunity(ComName) != ListOfCommunities.end()) {
			break;
		}
		cout << "Sorry that community doesn't exist try again" << endl;
	}
	Community = (*FindCommunity(ComName));
	Community.ListOfComUsers.push_back(*LoggedAccount);
}

list<Community>::iterator Community::FindCommunity(string ComName) {
	list<Community>::iterator it = ListOfCommunities.begin();
	for (it; it != ListOfCommunities.end(); it++) {
		if ((*it).CommunityName == ComName) {
			return it;
		}
	}
	return it;
}