#include "MainMenu.h"

MainMenu::MainMenu(const string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void MainMenu::OutputOptions()
{
	if (app->IsAccountLoggedIn())
	{
		Option('S', "Browse Store");

		if (app->IsUserLoggedIn())
		{
			Option('P', "View Profile");
			Option('L', "Logout");
		}
		else
		{
			Option('L', "Login");
			Line();
			Option('E', "Exit Account");
		}
	}
	else
	{
		Option('L', "Login");
		Option('C', "Create New Account");
	}
}

bool MainMenu::HandleChoice(char choice)
{
	if (app->IsAccountLoggedIn())
	{
		switch (choice)
		{
		case 'S':
		{
			StoreMenu storeMenu("STORE", app);
		} break;
		case 'L':
		{
			if (app->IsUserLoggedIn())
			{
				string answer = Question("Are you sure?");
				if (answer == "y" || answer == "Y")
				{
					app->LogoutUser();
				}
			}
			else
			{
				LoginMenu loginMenu("LOGIN", app);
			}
		} break;
		case 'P':
		{
			if (app->IsUserLoggedIn())
			{
				ProfileMenu profileMenu(Utils::ToUpperVersionA(app->GetCurrentUser()->GetUsername()) + " PROFILE", app); 
			}
		} break;
		case 'E':
		{
			app->LogoutAccount();
		}
		}
	}
	else
	{
		switch (choice)
		{
		case 'L':
		{
			LoginAccountMenu loginAccountMenu("SELECT ACCOUNT", app);
		} break;
		case 'C':
		{
			std::string emailAddress = Question("Enter email ");
			std::string emailPassword = Question("Enter password ");
			Date date;
			app->CreateAccount(emailAddress, emailPassword, date);
		}
		}
	}

	return false;
}