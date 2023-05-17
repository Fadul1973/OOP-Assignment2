#include "Player.h"

Player::Player(const string& username, const string& password, const Date& date)
	: User(username, password, date)
{
}
Player::Player(const string& username, const string& password, const Date& date, const int credits)
	: User(username, password, date), credits(credits)
{
}

Player::~Player()
{
	if (!library.empty())
	{
		for (int i = 0; i < library.size(); ++i)
		{
			delete library[i];
		}
	}
}

vector<LibraryItem*> Player::GetLibraryItems() const
{
	return library;
}

void Player::AddLibraryItem(Date& date, Game* game,int minsPlayed)
{
	library.push_back(new LibraryItem(date, game, minsPlayed));
}

void Player::PurchaseGame(Date& date, Game* game)
{
	credits -= game->GetCost();
	library.push_back(new LibraryItem(date, game));
}

void Player::AddCredits(int cred)
{
	credits += cred;
}

int Player::GetCredits() const
{
	return credits;
}

LibraryItem* Player::GetLibraryItem(Game* game)
{
	for (int i = 0; i < library.size(); i++)
	{
		if (game->GetName() == library[i]->GetGame()->GetName())
		{
			return library[i];
		}
	}

	return 0;
}

bool Player::IsAdmin() const
{
	return false;
}

bool Player::HasGame(Game* game) const
{
	if (!library.empty())
	{
		for (int i = 0; i < library.size(); i++)
		{
			if (GetLibraryItems()[i]->GetGame()->GetName() == game->GetName()) { return true; }
		}
	}

	return false;
}

void Player::sortByName()
{

	std::sort(library.begin(), library.end(), [](LibraryItem* lhs, LibraryItem* rhs)
		{
			return lhs->GetGame()->GetName() < rhs->GetGame()->GetName();
		});
		

}

void Player::sortByDate()
{
	std::sort(library.begin(), library.end(), [](LibraryItem* lhs, LibraryItem* rhs) -> bool
		{

			if (lhs->GetDatePurchased().GetYear() == rhs->GetDatePurchased().GetYear())
			{
				if (lhs->GetDatePurchased().GetMonth() == rhs->GetDatePurchased().GetMonth())
				{
					return lhs->GetDatePurchased().GetDay() > rhs->GetDatePurchased().GetDay();
				}
				else
				{
					return lhs->GetDatePurchased().GetMonth() > rhs->GetDatePurchased().GetMonth();
				}
			}
			else {
				return lhs->GetDatePurchased().GetYear() > rhs->GetDatePurchased().GetYear();
			}


		});

}
