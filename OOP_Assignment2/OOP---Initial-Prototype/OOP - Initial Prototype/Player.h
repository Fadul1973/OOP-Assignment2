#pragma once

#include "LibraryItem.h"
#include "User.h"
#include "ListT.h"
#include <vector>
#include <algorithm>

using namespace std;

class Player : public User
{
public:
	Player(const string&, const string&, const Date&);
	Player(const string&, const string&, const Date&, const int credits);

	~Player();
	vector<LibraryItem*> GetLibraryItems() const override;
	int GetCredits() const override;
	void AddLibraryItem(Date& date, Game* game, int minsPlayed) override;
	void PurchaseGame(Date& date, Game* game) override;
	void AddCredits(int cred) override;
	LibraryItem* GetLibraryItem(Game* game) override;
	bool IsAdmin() const override;
	bool HasGame(Game* game) const override;
	void sortByName();
	void sortByDate();

private:
	int credits = 1500;
	vector<LibraryItem*> library;

};