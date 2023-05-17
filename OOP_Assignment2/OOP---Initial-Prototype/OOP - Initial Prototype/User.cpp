#include "User.h"

User::User(const string& username, const string& password, const Date& date)
	: username(username), password(password), date(date)
{
}

User::~User()
{
}

const string& User::GetUsername() const
{
	return username;
}

const string& User::GetUserPassword() const
{
	return password;
}

const Date& User::GetDate() const
{
	return date;
}