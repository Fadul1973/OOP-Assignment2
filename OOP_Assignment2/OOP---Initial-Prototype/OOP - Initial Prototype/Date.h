#pragma once
#include <string>

class Date
{
public:

	Date(); // Default constructor instantiates with todays date
	Date(const int d, const int m, const int y); // Constructor to create date with params
	~Date();

	int GetDay() const ;
	int GetMonth() const ;
	int GetYear() const ;
	
	std::string getFullDate() const;


private:
	int d = 0, m = 0, y = 0;
	
};

