#include "SearchMenu.h"

SearchMenu::SearchMenu(const string& title, Application* app) : Menu(title, app)
{

	Paint(); // required in constructor
}

void SearchMenu::OutputOptions()
{
	Line("SEARCHING 9 GAMES");
	Option('N', "Search by name");
	Option('P', "Search by price");
}

bool SearchMenu::HandleChoice(char choice)
{
	switch (choice)
	{
	case 'N':
	{
		List<Game*>foundGames = app->GetStore().SearchByName(Question("Enter name to search for "));
		SearchResultsMenu searchResultsMenu("SEARCH RESULTS", app, foundGames);
	}break;
	case 'P':
	{
		List<Game*>foundGames = app->GetStore().SearchByPrice(Question("Enter price range (e.g. 5-10)"));
		SearchResultsMenu searchResultsMenu("SEARCH RESULTS", app, foundGames);
	}
	}
	return false;
}