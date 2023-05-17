#pragma once

#include "Menu.h"

class GameMenu : public Menu
{
public:
	GameMenu(const string& title, Application* app, Game* game);
	void OutputOptions() final;
	bool HandleChoice(char choice) final;
private:
	Game* game;
};
