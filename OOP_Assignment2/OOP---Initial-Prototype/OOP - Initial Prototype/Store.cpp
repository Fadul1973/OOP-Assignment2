#include "Store.h"

Store::Store()
{
}

Store::~Store()
{
	for (int i = 0; i < 9; ++i)
	{
		delete games[i];
	}
}

List<Game*> Store::GetGames() const
{
	return games;
}

void Store::AddGame(string title, string description, int price, int ageRating)
{
	games.addAtEnd(new Game(title, description, price, ageRating));
}

List<Game*> Store::SearchByName(string word)
{
	List<Game*> foundGames;
	for (int i = 0; i < games.length(); i++)
	{
		if (Utils::StartsWith(Utils::ToUpperVersionA(games[i]->GetName()), Utils::ToUpperVersionA(word)))
		{
			foundGames.addAtEnd(games[i]);
		}
	}
	return foundGames;
}

List<Game*> Store::SearchByPrice(string priceRange)
{
	List<Game*> foundGames;
	for (int i = 0; i < games.length(); i++)
	{
		if (Utils::RangeWithin(priceRange, games[i]->GetCost()))
		{
			foundGames.addAtEnd(games[i]);
		}
	}

	return foundGames;
}

int Store::getGameIndex(const Game*& game)
{
	for (int i = 0; i < games.length(); i++)
	{
		if (games[i] == game)
		{
			return i;
		}
	}
}