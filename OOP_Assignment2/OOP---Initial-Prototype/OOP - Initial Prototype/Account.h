#pragma once

#include <string>
#include "Player.h"
#include "Date.h"
#include "ListT.h"

using namespace std;

class Account
{
public:
	Account(const string& email, const string& password, const Date& date);
	~Account();
	const string& GetEmail();						
	const string& GetPassword();					
	const Date GetDate();							
	List<User*>& GetUsers();
	void AddUser(User* user);
	void DeleteUser(int index);

private:
	string email;
	string password;
	Date date; 
	List<User*> users;
};