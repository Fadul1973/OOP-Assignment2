#pragma once

#include "Menu.h"
#include "StoreMenu.h"

class LoginUserMenu : public Menu
{
public:
	LoginUserMenu(const string& title, Application* app);
	void OutputOptions() final;
	bool HandleChoice(char choice);


private:

};

