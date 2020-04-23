#include <iostream>
#include <list>
#include <string>
#include "user.h"


//Constructor
User::User(string uname, string psswrd, string mail) {
    username = uname;
    password = psswrd;
    email = mail;
}

User User::createUser(string uname, string psswrd, string mail) {
    User randomUser = User(uname, psswrd, mail);
    return randomUser;
}

