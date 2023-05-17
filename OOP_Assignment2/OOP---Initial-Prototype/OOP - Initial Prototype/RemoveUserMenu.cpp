#include "RemoveUserMenu.h"

RemoveUserMenu::RemoveUserMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void RemoveUserMenu::OutputOptions()
{
	int number = 1;
	if (app->GetCurrentAccount()->GetUsers().length() > 0)
	{
		for (int i = 0; i < app->GetCurrentAccount()->GetUsers().length(); i++)
		{
			// if (!users[i]->IsAdmin()) // TODO: Maybe Implement this - but how to correct for index value?
			//{
			Option(number, app->GetCurrentAccount()->GetUsers()[i]->GetUsername());
			number++;
			//}
		}
	}
	else
	{
		Line("NO USERS");
	}
}

bool RemoveUserMenu::HandleChoice(char choice)
{
	// since we are using numbers here we shift the char down by '1'
	// this puts '1' as 0, '2' as 1, '3' as 2, '4' as 3, etc.
	// this reverses the + 1 above and lets us do the range check below
	int index = choice - '1';

	if (index >= 0 && index < app->GetCurrentAccount()->GetUsers().length())
	{
		User* user = app->GetCurrentAccount()->GetUsers()[index];
		if (user->GetUsername() == app->GetCurrentUser()->GetUsername())
		{
			BlockingMessage("Can't delete Admin");
		}
		else
		{
			app->GetCurrentAccount()->DeleteUser(index);
		}
	}

	return false;
}