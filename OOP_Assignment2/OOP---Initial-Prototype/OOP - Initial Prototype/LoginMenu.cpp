#include "LoginMenu.h"

LoginMenu::LoginMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void LoginMenu::OutputOptions()
{
	if (!app->GetCurrentAccount()->GetUsers().isEmpty())
	{
		for (int i = 0; i < app->GetCurrentAccount()->GetUsers().length(); i++)
		{
			// adding 1 so the display is nicer for the user
			Option(i + 1, app->GetCurrentAccount()->GetUsers()[i]->GetUsername());
		}
	}
	else
	{
		Line("Empty");
		Line();
		Option('C', "Create admin");
	}
}

bool LoginMenu::HandleChoice(char choice)
{
	// since we are using numbers here we shift the char down by '1'
	// this puts '1' as 0, '2' as 1, '3' as 2, '4' as 3, etc.
	// this reverses the + 1 above and lets us do the range check below
	int index = choice - '1';

	if (!app->GetCurrentAccount()->GetUsers().isEmpty())
	{
		if (index >= 0 && index < app->GetCurrentAccount()->GetUsers().length())
		{
			std::string username = app->GetCurrentAccount()->GetUsers()[index]->GetUsername();

			if (app->LoginUser(username, Question(" Enter password for " + username)))
			{
				return true;
			}
			else
			{
				BlockingMessage("Incorrect password - Please try again.");
				return false;
			}
		}
	}
	else {
		switch (choice)
		{
		case 'C':
		{
			std::string userName = Question("Enter username ");
			std::string password = Question("Enter password ");

			Date date;
			Admin* user = new Admin(userName, password, date);
			app->GetCurrentAccount()->AddUser(user);
		}
		}
	}

	return false;
}