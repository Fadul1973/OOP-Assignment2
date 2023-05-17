#pragma once

#include "Game.h"
#include "ListT.h"
#include "Utils.h"

class Store
{
public:
	Store();
	~Store();
	List<Game*> GetGames() const;
	void AddGame(string title, string description, int price, int ageRating);
	List<Game*> SearchByName(string word);
	List<Game*> SearchByPrice(string priceRange);
	int getGameIndex(const Game*& game);

private:
	List<Game*> games;
};