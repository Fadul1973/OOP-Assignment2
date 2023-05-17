#pragma once

#include <string>

using namespace std;

class Game
{
	public:
		Game(const string&, const string&, int, int);
		~Game();

		const string& GetName() const;
		const string& GetDescription() const;
		int GetCost() const;
		int GetRating()const;
	private:
		string name;
		string description;
		int cost;
		int ageRating;
};