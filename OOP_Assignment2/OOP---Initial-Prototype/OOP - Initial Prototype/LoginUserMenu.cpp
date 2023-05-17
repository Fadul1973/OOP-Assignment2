#include "LoginUserMenu.h"

LoginUserMenu::LoginUserMenu(const string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void LoginUserMenu :: OutputOptions() 
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
	}
}
bool LoginUserMenu :: HandleChoice(char choice)
{
	switch (choice)
	{
	case 'S':
	{
		StoreMenu("STORE", app);
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
			// this would need to go to a LoginMenu - similar to StoreMenu
			// instead we just set logged in to true on the main app object
			// app->LogIn();																// I COMMENT THIS OUT FOR NOW JUST TO SEE IF IT WORKS
		}
	} break;
	case 'P':
	{
		if (app->IsUserLoggedIn())
		{
			BlockingMessage("Not implemented, press return to continue");
			// this needs to go to a profile page - similar to StoreMenu
			// notice the if - this only works if somebody is logged in
		}
	} break;
	}

	return false;
}