#include "Account.h"
#include "Date.h"

Account::Account(const string& email, const string& password, const Date& date)
	: email(email), password(password), date(date)
{
}

Account::~Account()
{
	for (int i = 0; i < users.length(); ++i)
	{
		delete users[i];
	}
}
const string& Account::GetEmail()
{
	return email;
}
const string& Account::GetPassword()
{
	return password;
}

const Date Account::GetDate()
{
	return date;
}

List<User*>& Account::GetUsers()
{
	return users;
}

void Account::AddUser(User* user)
{
	users.addAtEnd(user);
}

void Account::DeleteUser(int index)
{
	users.deleteOne(users[index]);
}