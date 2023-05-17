#include "Admin.h"

Admin::Admin(const string& username, const string& password, const Date& date)
	: Player(username, password, date)
{
}

Admin::Admin(const string& username, const string& password, const Date& date, const int credits)
	: Player(username, password, date,credits)
{
}


Admin::~Admin()
{
}

bool Admin::IsAdmin() const
{
	return true;
}