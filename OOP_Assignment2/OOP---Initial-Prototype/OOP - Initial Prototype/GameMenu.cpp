#include "GameMenu.h"

GameMenu::GameMenu(const string& title, Application* app, Game* game) : Menu(title, app), game(game) {

	Paint(); // required in constructor

}

void GameMenu::OutputOptions()
{
	Line(game->GetDescription());
	string cost = Utils::FormatCredit(game->GetCost());
	Line("Costs: " + cost);
	if (app->IsUserLoggedIn())
	{
		if (app->GetCurrentUser()->HasGame(game))
		{
			Line();
			Line("You own this game");
			Line();
			Line("Purchased: " + app->GetCurrentUser()->GetLibraryItem(game)->GetDatePurchased().getFullDate());
			Line("Playtime:" + Utils::FormatPlayTime(app->GetCurrentUser()->GetLibraryItem(game)->GetTotalPlayed()));
		}
		else
		{
			Line("Credits: " + Utils::FormatCredit(app->GetCurrentUser()->GetCredits()));
			Line();
			Option('P', "Purchase for " + cost);
		}
	}
}

bool GameMenu::HandleChoice(char choice)
{
	if (app->IsUserLoggedIn()) {
		switch (choice)
		{
		case 'P':
		{
			if (app->GetCurrentUser()->GetCredits() > game->GetCost())
			{
				Date date;
				app->GetCurrentUser()->PurchaseGame(date, game);
			}
			else
			{
				BlockingMessage("You don't have enough credit");
			}

		} break;
		}
	}

	return false;

}