#include <string>
#include <iostream>

using namespace std; 

class User
{
public:
    string username;
    string password;
    string email;
    
    User(string uname, string psswrd, string mail);
    User createUser(string uname, string psswrd, string mail);
};

