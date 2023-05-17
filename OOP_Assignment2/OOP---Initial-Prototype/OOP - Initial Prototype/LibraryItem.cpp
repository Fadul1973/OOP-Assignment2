#include "LibraryItem.h"

LibraryItem::LibraryItem(const Date& date, Game* game)
	: datePurchased(date), game(game), totalPlayed(0)
{

}

LibraryItem::LibraryItem(const Date& date, Game* game, const int totalPlayed)
	: datePurchased(date), game(game), totalPlayed(totalPlayed)
{

}

LibraryItem::~LibraryItem()
{

}

const Game*& LibraryItem::GetGame()
{
	return game;
}

const Date& LibraryItem::GetDatePurchased() const
{
	return datePurchased;
}

const int& LibraryItem::GetTotalPlayed() const
{
	return totalPlayed;
}

void LibraryItem::PlayGame(int time)
{
	totalPlayed += time;
}
