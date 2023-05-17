#include <iostream>
#include <string>
#include "Application.h"
#include "Account.h"
#include "User.h"
#include "Player.h"
#include "Admin.h"
#include "Utils.h"
#include "MainMenu.h"
#include "Date.h"

using namespace std;

void main()
{
	
	Application app;

	app.Load();

	MainMenu mainMenu("GAME SYSTEM", &app);

	app.Save();
}