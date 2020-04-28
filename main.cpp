#include <iostream>
#include <string>
#include <list>
#include <unistd.h>
#include "user.h"
#include "community.h"

using namespace std;
list<User>::iterator LoggedAccount;

int main()
{
	int input1;
	int input2;
	int input3;
	User user = User();
	Community communityObj = Community();
	begin:
	cout << "WELCOME TO NITROX!" << endl;
	cout << "\nType 1 - If you wish to login in to your account.\nType 2 - If you do not currently have a Nitrox account but wish to create one.\nType 3 - To exit the Nitrox application.\n\nInput: ";
	cin >> input1;
	cout << "\n";
	
	while (input1 != 1 && input1 != 2 && input1 != 3) {
		cout << "The inputted value is not in the bounds please select again" << endl;
		cout << "Input: ";
		cin >> input1;
		cout << "\n";
	}

	switch(input1) {
		
		case 1:
			user.Login();
			cout << string(50, '\n');
			break;
		
		case 2:
			cout << string(50, '\n');
			user.CreateAccount();
			cout << string(50, '\n');
			user.Login();
			cout << string(50, '\n');
			break;
		case 3:
			cout << "Exiting..." << endl;
			sleep(2);
			exit(0);
	}

	while (user.LogOn() == true) {
		cout << "\n***Nitrox Home Page***\n";
		cout << "\nType 1 - If you would like to modify your account.\nType 2 - If you would like to create a new community." << endl;
		cout << "Type 3 - If you would like to list all currently available communities.\nType 4 - To join a currently available community." << endl;
		cout << "Type 5 - To logout of your account.\nType 6 - To exit the Nitrox application.\n\nInput: ";
		cin >> input2;
		cout << "\n";

		while (input2 != 1 && input2 != 2 && input2 != 3 && input2 != 4 && input2 != 5 && input2 != 6) {
			cout << "The inputted value is not in the bounds please select again" << endl;
			cout << "Input: ";
			cin >> input2;
			cout << "\n";
		}

		switch(input2) {

			case 1:
				cout << string(50, '\n');
				cout << "***User Info***" << endl;
				cout << "Type 1 - If you wish to change your username.\nType 2 - If you wish to change your password." << endl;
				cout << "Type 3 - If you wish to change your email.\nType 4 - To go back.\n\nInput: ";
				cin >> input3;
				
				while (input3 != 1 && input3 != 2 && input3 != 3 && input3 != 4) {
					cout << "The inputted value is not in the bounds please select again" << endl;
					cout << "Input: ";
					cin >> input3;
					cout << "\n";
				}

				switch(input3) {

					case 1:
						cout << string(50, '\n');
						cout << "Your current username is " << (*LoggedAccount).username << endl;
						user.ChangeUsername();
						break;
				
					case 2:
						cout << string(50, '\n');
						cout << "Your current password is " << (*LoggedAccount).password << endl;
						user.ChangePass();
						break;
				
					case 3:
						cout << string(50, '\n');
						cout << "Your current email is " << (*LoggedAccount).email << endl;
						user.ChangeEmail();
						break;

					case 4:
						cout << string(50, '\n');
						break;
				}

				break;

			case 2:
				cout << string(50, '\n');
				cout << "***Community Creation Page***\n" << endl;
				communityObj.CreateCommunity();
				break;

			case 3:
				cout << string(50, '\n');
				cout << "Community List:" << endl;
				communityObj.ListCommunities();
				sleep(2);
				break;

			case 4:
				cout << string(50, '\n');
				communityObj.JoinCommunity();
				sleep(2);
				break;

			case 5:
				user.LogOff();
				sleep(2);
				cout << string(50, '\n');
				goto begin;
				break;

			case 6:
				cout << "Exiting..." << endl;
				sleep(2);
				exit(0);
		}
	}
}