#pragma once

#include "Account.h"
#include "User.h"
#include "Store.h"
#include "ListT.h"
#include "Admin.h"										
#include "Date.h"											

using namespace std;

class Application
{
public:
	Application();
	~Application();

	bool IsAccountLoggedIn() const;
	bool IsUserLoggedIn() const;
	Account*& GetCurrentAccount();
	User*& GetCurrentUser();
	List<Account*> GetAccounts() const;									

	Store& GetStore();

	bool LoginAccount(const string& email, const string& password);
	bool LoginUser(const string& username, const string& password);
	void LogoutAccount();
	void LogoutUser();
	void Load();													
	void Save();
	void CreateAccount(string email, string password, Date& date);		

private:
	Store store;
	Account* currentAccount;
	User* currentUser;
	List<Account*> accounts;												
};