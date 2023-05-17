#pragma once

#include "Menu.h"
#include "GameMenu.h"
#include "SearchMenu.h"
#include <string>
#include "ListT.h"

using namespace std;

class StoreMenu : public Menu
{
public:
	StoreMenu(const string& title, Application* app);
	void OutputOptions() final;
	bool HandleChoice(char choice) final;
private:
	List<Game*> games;
	int noOfPages;
	int currentPage;
};