#pragma once

#include <string>
#include "Player.h"

using namespace std;

class Admin : public Player
{
	public:
		Admin(const string&, const string&, const Date& date);
		Admin(const string&, const string&, const Date& date,const int credits);

		~Admin();

		bool IsAdmin() const override;
};