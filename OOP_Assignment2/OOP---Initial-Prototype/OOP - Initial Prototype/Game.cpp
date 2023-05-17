#include "Game.h"

Game::Game(const string& name, const string& desc, int cost, int rating)
	: name(name), description(desc), cost(cost), ageRating(rating)
{
}

Game::~Game()
{
}

const string& Game::GetName() const
{
	return name;
}

const string& Game::GetDescription() const
{
	return description;
}

int Game::GetCost() const
{
	return cost;
}

int Game::GetRating() const
{
	return ageRating;
}
