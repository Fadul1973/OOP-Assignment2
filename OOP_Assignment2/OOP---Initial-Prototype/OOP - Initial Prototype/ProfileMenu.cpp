#include "ProfileMenu.h"

ProfileMenu::ProfileMenu(const string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void ProfileMenu::OutputOptions()
{
	Line("Credits: " + Utils::FormatCredit(app->GetCurrentUser()->GetCredits()));
	Option('I', "Purchase 1 credit");
	Option('O', "Purchase 10 credits");
	Option('P', "Purchase 100 credits");
	Line();
	Line("GAMES");

	if (app->GetCurrentUser()->GetLibraryItems().size() < 1)
	{
		Line("NONE");
	}
	else
	{
		for (int i = 0; i < app->GetCurrentUser()->GetLibraryItems().size(); i++)
		{
			// adding 1 so the display is nicer for the user
			Option(i + 1, app->GetCurrentUser()->GetLibraryItems()[i]->GetGame()->GetName() + " (" + Utils::FormatPlayTime(app->GetCurrentUser()->GetLibraryItems()[i]->GetTotalPlayed()) + ")");
		}

		Line();
		Option('D', "Sort By Date Purchased");
		Option('N', "Sort By Name");
	}

	if (app->GetCurrentUser()->IsAdmin())
	{
		Line();
		Line("ADMINISTRATOR");
		Option('A', "Add new user");
		Option('R', "Remove user");
		// Option('G', "Guests per-game access"); // TODO: Maybe in future this will be implemented
	}
}

bool ProfileMenu::HandleChoice(char choice)
{
	switch (choice)
	{
	case 'I':
	{
		app->GetCurrentUser()->AddCredits(100);
	} break;
	case 'O':
	{
		app->GetCurrentUser()->AddCredits(1000);
	} break;
	case 'P':
	{
		app->GetCurrentUser()->AddCredits(10000);
	} break;
	case 'A':
	{

		if (app->GetCurrentUser()->IsAdmin())
		{
			std::string userName = Question("Enter username ");
			std::string password = Question("Enter password ");

			Date date;
			Player* user = new Player(userName, password, date);
			app->GetCurrentAccount()->AddUser(user);
		}

	} break;
	case 'R':
	{
		if (app->GetCurrentUser()->IsAdmin())
		{
			RemoveUserMenu removeUserMenu("REMOVE USER", app);
		}
	}

	case 'N':
		app->GetCurrentUser()->sortByName();
			break;
	case 'D':
		app->GetCurrentUser()->sortByDate();
			break;
	}

	// since we are using numbers here we shift the char down by '1'
	// this puts '1' as 0, '2' as 1, '3' as 2, '4' as 3, etc.
	// this reverses the + 1 above and lets us do the range check below

	if (!app->GetCurrentUser()->GetLibraryItems().empty())
	{
		int index = choice - '1';

		if (index >= 0 && index < app->GetCurrentUser()->GetLibraryItems().size())
		{
			app->GetCurrentUser()->GetLibraryItems()[index]->PlayGame(Utils::RandomNumberWithinRange());
		}
	}

	return false;
}