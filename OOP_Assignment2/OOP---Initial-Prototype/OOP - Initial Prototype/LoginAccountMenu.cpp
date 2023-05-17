#include "LoginAccountMenu.h"

LoginAccountMenu::LoginAccountMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void LoginAccountMenu::OutputOptions()
{
	if (!app->GetAccounts().isEmpty())
	{
		for (int i = 0; i < app->GetAccounts().length(); i++)
		{
			// adding 1 so the display is nicer for the user
			Option(i + 1, app->GetAccounts()[i]->GetEmail());
		}
	}
	else
	{
		Line("No Accounts Available");
	}
}

bool LoginAccountMenu::HandleChoice(char choice)
{
	// since we are using numbers here we shift the char down by '1'
	// this puts '1' as 0, '2' as 1, '3' as 2, '4' as 3, etc.
	// this reverses the + 1 above and lets us do the range check below
	int index = choice - '1';

	if (index >= 0 && index < app->GetAccounts().length())
	{
		std::string email = app->GetAccounts()[index]->GetEmail();

		if (app->LoginAccount(email, Question(" Enter password for " + email)))
		{
			return true;
		}
		else
		{
			BlockingMessage("Incorrect password - Please try again.");
			return false;
		}
	}

	return false;
}