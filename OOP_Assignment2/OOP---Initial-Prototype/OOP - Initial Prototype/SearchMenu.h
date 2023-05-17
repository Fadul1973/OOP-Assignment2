#pragma once

#include "Menu.h"
#include "SearchResultsMenu.h"

class SearchMenu : public Menu
{
public:
	SearchMenu(const string& title, Application* app);
	void OutputOptions() final;
	bool HandleChoice(char choice) final;
};