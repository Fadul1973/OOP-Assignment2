#include "Application.h"
#include "Date.h"
#include <fstream>
#include <iostream>

Application::Application() : currentAccount(nullptr), currentUser(nullptr)
{
}

Application::~Application()
{
	for (int i = 0; i < accounts.length(); ++i)
	{
		delete accounts[i];
	}
}

bool Application::IsUserLoggedIn() const
{
	return currentUser != nullptr;
}

bool Application::IsAccountLoggedIn() const
{
	return currentAccount != nullptr;
}

Account*& Application::GetCurrentAccount()
{
	return currentAccount;
}

User*& Application::GetCurrentUser()
{
	return currentUser;
}

List<Account*> Application::GetAccounts() const
{
	return accounts;
}

Store& Application::GetStore()
{
	return store;
}

bool Application::LoginAccount(const string& email, const string& password)
{
	for (int i = 0; i < accounts.length(); i++)
	{
		if (accounts[i]->GetEmail() == email)
		{
			if (accounts[i]->GetPassword() == password)
			{
				currentAccount = accounts[i];
				return true;
			}
		}
	}

	return false;
}

bool Application::LoginUser(const string& username, const string& password)										
{
	for (int i = 0; i < currentAccount->GetUsers().length(); i++)
	{
		if (currentAccount->GetUsers()[i]->GetUsername() == username)
		{
			if (currentAccount->GetUsers()[i]->GetUserPassword() == password)
			{
				currentUser = currentAccount->GetUsers()[i];
				return true;
			}
		}
	}

	return false;
}

void Application::LogoutAccount()
{
	currentAccount = nullptr;
}

void Application::LogoutUser()
{
	currentUser = nullptr;
}

void Application::Load()
{
	Player* previousPlayer = nullptr; // Holds pointer to player/admin account for library items to be assigned
	std::string text = "";

	ifstream readFile("data.txt");

	if (readFile.is_open())
	{
		while (std::getline(readFile, text))
		{
			if (text == "GAME")
			{
				std::string num = "";
				std::string title = "";
				std::string desc = "";
				std::string price = "";
				std::string ageRating = "";

				std::getline(readFile, num);
				std::getline(readFile, title);
				std::getline(readFile, desc);
				std::getline(readFile, price);
				std::getline(readFile, ageRating);

				int p = stoi(price);
				int a = stoi(ageRating);

				GetStore().AddGame(title, desc, p, a);
			}

			if (text == "ACCOUNT")
			{
				std::string year = "";
				std::string month = "";
				std::string day = "";

				std::string email = "";
				std::string password = "";

				std::getline(readFile, year,'-'); 
				std::getline(readFile, month, '-'); 
				std::getline(readFile, day);
				
				std::getline(readFile, email);
				std::getline(readFile, password);
				int y = stoi(year);
				int m = stoi(month);
				int d = stoi(day);

				Date theDate(d,m,y);
				CreateAccount(email, password, theDate);
			}

			if (text == "ACCOUNT-PLAYER")
			{
				std::string year = "";
				std::string month = "";
				std::string day = "";

				std::string username = "";
				std::string password = "";

				std::string credits = "";

				std::getline(readFile, year, '-');
				std::getline(readFile, month, '-');
				std::getline(readFile, day);

				std::getline(readFile, username);
				std::getline(readFile, password);
				std::getline(readFile, credits);

				int y = stoi(year);
				int m = stoi(month);
				int d = stoi(day);

				int cred = stoi(credits);

				Date theDate(d, m, y);

				Player* p = new Player(username,password,theDate,cred);

				previousPlayer = p;

				accounts[0]->AddUser(p);
				std::getline(readFile, text);

				
			}

			if (text == "ACCOUNT-ADMIN")
			{
				std::string year = "";
				std::string month = "";
				std::string day = "";

				std::string username = "";
				std::string password = "";

				std::string credits = "";

				std::getline(readFile, year, '-');
				std::getline(readFile, month, '-');
				std::getline(readFile, day);

				std::getline(readFile, username);
				std::getline(readFile, password);
				std::getline(readFile, credits);

				int y = stoi(year);
				int m = stoi(month);
				int d = stoi(day);

				int cred = stoi(credits);

				Date theDate(d, m, y);

				Player* p = new Admin(username, password, theDate,cred);
				previousPlayer = p;

				accounts[0]->AddUser(p);
								
			}

			if (text == "LIBRARY-ITEM")
			{
				std::string gameIndex = "";
				std::string year = "";
				std::string month = "";
				std::string day = "";
				std::string minutesPlayed = "";

				std::getline(readFile, gameIndex);

				std::getline(readFile, year, '-');
				std::getline(readFile, month, '-');
				std::getline(readFile, day);

				std::getline(readFile, minutesPlayed);

				int y = stoi(year);
				int m = stoi(month);
				int d = stoi(day);

				int gI = stoi(gameIndex);

				int mPlayed = stoi(minutesPlayed);

				Date theDate(d, m, y);

				previousPlayer->AddLibraryItem(theDate, store.GetGames()[gI], mPlayed);

			}
		
		}

		readFile.close();

	}
	else
	{
		cout << "File Not Found";
	}									

}

void Application::Save()
{
	ofstream saveFile("data.txt");

	if (saveFile.is_open())
	{

	int sizeOfGames = GetStore().GetGames().length();
	int sizeOfAccount = GetAccounts().length();

	for (int i = 0; i < sizeOfGames; i++)
	{
		saveFile << "GAME" << "\n";
		saveFile << i << "\n";
		saveFile << GetStore().GetGames()[i]->GetName() << "\n";
		saveFile << GetStore().GetGames()[i]->GetDescription() << "\n";
		saveFile << GetStore().GetGames()[i]->GetCost() << "\n";
		saveFile << GetStore().GetGames()[i]->GetRating() << "\n";

	}

	for (int i = 0; i < sizeOfAccount; i++)
	{
		saveFile << "ACCOUNT" << "\n";
		saveFile << GetAccounts()[i]->GetDate().getFullDate() <<"\n";
		saveFile << GetAccounts()[i]->GetEmail() << "\n";
		saveFile << GetAccounts()[i]->GetPassword() << "\n";

		int sizeOfUsers = GetAccounts()[i]->GetUsers().length();

		for (int j = 0; j < sizeOfUsers; j++)
		{

			if (GetAccounts()[i]->GetUsers()[j]->IsAdmin())
			{
				saveFile << "ACCOUNT-ADMIN" << "\n";
				saveFile << GetAccounts()[i]->GetUsers()[j]->GetDate().getFullDate() << "\n";
				saveFile << GetAccounts()[i]->GetUsers()[j]->GetUsername() << "\n";
				saveFile << GetAccounts()[i]->GetUsers()[j]->GetUserPassword() << "\n";
				saveFile << GetAccounts()[i]->GetUsers()[j]->GetCredits() << "\n";
			}
			else if (!GetAccounts()[i]->GetUsers()[j]->IsAdmin())
			{
				saveFile << "ACCOUNT-PLAYER" << "\n";
				saveFile << GetAccounts()[i]->GetUsers()[j]->GetDate().getFullDate() << "\n";
				saveFile << GetAccounts()[i]->GetUsers()[j]->GetUsername() << "\n";
				saveFile << GetAccounts()[i]->GetUsers()[j]->GetUserPassword() << "\n";
				saveFile << GetAccounts()[i]->GetUsers()[j]->GetCredits() << "\n";

			}

			size_t sizeOfLibrary = GetAccounts()[i]->GetUsers()[j]->GetLibraryItems().size();

			for (int k = 0; k < sizeOfLibrary; k++)
			{
				saveFile << "LIBRARY-ITEM" << "\n";
				saveFile << GetStore().getGameIndex(GetAccounts()[i]->GetUsers()[j]->GetLibraryItems()[k]->GetGame()) << "\n";
				saveFile << GetAccounts()[i]->GetUsers()[j]->GetLibraryItems()[k]->GetDatePurchased().getFullDate() << "\n";
				saveFile << GetAccounts()[i]->GetUsers()[j]->GetLibraryItems()[k]->GetTotalPlayed() << "\n";

			}
		}
	}

	saveFile.close();

	}
	

}

void Application::CreateAccount(string email, string password, Date& date)			
{
	accounts.addInFront(new Account(email, password, date));
}