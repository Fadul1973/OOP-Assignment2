#include "SearchResultsMenu.h"

SearchResultsMenu::SearchResultsMenu(const string& title, Application* app, List<Game*> games) : Menu(title, app), games(games), currentPage(1)
{
	noOfPages = Utils::NumberOFPages(games);
	Paint(); // required in constructor
}

void SearchResultsMenu::OutputOptions()
{
	if (!games.isEmpty())
	{
		if (currentPage % 2 == 1)
		{
			for (int i = 0; i < 5; i++)
			{
				// adding 1 so the display is nicer for the user
				Option(i + 1, games[i]->GetName());
				if (games.length() == (i + 1)) { i += 5; }
			}
		}
		else
		{
			int size = currentPage * 5;
			for (int i = size - 5; i < size; i++)
			{
				// adding 1 so the display is nicer for the user
				Option(i + 1, games[i]->GetName());
				if (games.length() == (i + 1)) { i += size; }
			}
		}
	}
	else {
		Line("None");
	}
	Line();
	Line("PAGE " + Utils::GetStringFromInt(currentPage) + " OF " + Utils::GetStringFromInt(noOfPages));
	Option('S', "Search");
	if (currentPage < noOfPages) { Option('N', "Next Page"); }
	else if (currentPage == noOfPages && currentPage > 1) { Option('P', "Previous Page"); }
	if (currentPage < noOfPages && currentPage > 1) { Option('P', "Previous Page"); }
}

bool SearchResultsMenu::HandleChoice(char choice)
{
	switch (choice)
	{
	case 'S':
	{
		return true;
	}break;
	case 'N':
	{
		if (currentPage < noOfPages) { currentPage++; }
	}break;
	case 'P':
	{
		if (currentPage > 1 && noOfPages > 1) { currentPage--; }
	}
	}
	// since we are using numbers here we shift the char down by '1'
	// this puts '1' as 0, '2' as 1, '3' as 2, '4' as 3, etc.
	// this reverses the + 1 above and lets us do the range check below
	if (!games.isEmpty())
	{
		int index = choice - '1';

		int size = currentPage * 5;
		if (index >= size - 5 && index < size)
		{
			if (index < games.length()) { GameMenu gameMenu(Utils::ToUpperVersionB(games[index]->GetName()), app, games[index]); }
		}
	}

	return false;
}