#include "Community.h"
#include <iostream>
#include <list>
using namespace std;

Community::Community()
{
    //Default Constructor
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
	cout << "Enter the name of the community: ";
	cin >> ComName;
	cout << "Enter the maximum number of community memebers you would like to allow: ";
	cin >> MaxMem;
	cout << "Do you wish for you community to be private? Type y/n: ";
	cin >> PermIn;
	if (PermIn == 'y') {
		Perm = true;
	}
	ListOfCommunities.push_back(Community(ComName, MaxMem, (Owner), Perm));
}

void Community::ListCommunities() {
	int i = 1;
	if (ListOfCommunities.empty()) {
		cout << "There are currently no available communities" << endl;
	}
	else {
		list<Community>::iterator it = ListOfCommunities.begin();
		for (it; it != ListOfCommunities.end(); it++) {
			cout << i << ". " << (*it).CommunityName << endl;
		}
	}
}

void Community::JoinCommunity() {
	string ComName;
	list<Community>::iterator Comm;
	if (ListOfCommunities.empty()) {
		cout << "There are currently no available communites" << endl;
	}
	else {
		while (true) {
			cout << "Name the community you wish to join: ";
			cin >> ComName;
			if (FindCommunity(ComName) != ListOfCommunities.end()) {
				break;
			}
			cout << "Sorry that community doesn't exist" << endl;
			return;
		}
		Comm = FindCommunity(ComName);
		(*Comm).ListOfComUsers.push_back(*LoggedAccount);
		cout << "You have successfully joined " << ComName << endl;
	}
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