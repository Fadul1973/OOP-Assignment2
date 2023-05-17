#pragma once

#include <string>
#include "Date.h"
#include "ListT.h"
#include "LibraryItem.h"
#include <vector>

using namespace std;

class User
{
public:
	User(const string&, const string&, const Date& date);

	virtual ~User();
	const string& GetUsername() const;
	const string& GetUserPassword() const;
	const Date& GetDate() const;
	virtual int GetCredits() const = 0;
	virtual void AddCredits(int cred) = 0;
	virtual vector<LibraryItem*> GetLibraryItems() const = 0;
	virtual void AddLibraryItem(Date& date, Game* game, int minsPlayed) = 0;
	virtual void PurchaseGame(Date& date, Game* game) = 0;
	virtual LibraryItem* GetLibraryItem(Game* game) = 0;
	virtual bool IsAdmin() const = 0;
	virtual bool HasGame(Game* game) const = 0;
	virtual void sortByName()= 0;
	virtual void sortByDate() = 0;


private:
	string username;
	string password;
	Date date;  
};