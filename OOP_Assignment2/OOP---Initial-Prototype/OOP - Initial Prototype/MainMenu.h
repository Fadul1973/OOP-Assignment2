#pragma once

#include "Menu.h"
#include "StoreMenu.h"
#include "LoginMenu.h"
#include "ProfileMenu.h"
#include "LoginAccountMenu.h"

using namespace std;

class MainMenu : public Menu
{
public:
	MainMenu(const string& title, Application* app);
	void OutputOptions() final;
	bool HandleChoice(char choice) final;
};