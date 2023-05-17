#pragma once

#include "Game.h"
#include "Date.h"

using namespace std;

class LibraryItem
{
public:
	LibraryItem(const Date&, Game*);
	LibraryItem(const Date&, Game*, const int totalPlayed);

	~LibraryItem();
	const Game*& GetGame();
	const Date& GetDatePurchased() const;
	const int& GetTotalPlayed() const;
	void PlayGame(int time);

private:
	const Game* game;
	const Date datePurchased;
	int totalPlayed; // in minutes
};