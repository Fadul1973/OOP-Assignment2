#pragma once

#include "Menu.h"
#include <string>
#include "ListT.h"
#include "RemoveUserMenu.h"

class ProfileMenu : public Menu
{
public:
	ProfileMenu(const string& title, Application* app);
	void OutputOptions() final;
	bool HandleChoice(char choice) final;

};