#pragma once

#include "Utils.h"
#include "Application.h"
#include <iostream>
#include <string>

using namespace std;

class Menu
{
	public:
		Menu(const string& title, Application* app);

		void Paint();

		// Use this function to output all the options specific to your menu
		virtual void OutputOptions() = 0;

		// Use this function to handle the possible choices from your menu
		// Returning true means you are ready to go back to the previous menu
		// Returning false means you will stay on the same menu
		virtual bool HandleChoice(char) = 0;

	protected:
		Application* app;                                   // each menu will store a pointer to the main application
															// this way menus can access all the data required

		void Line();										// output blank line
		void Line(const string& text);					// output a message
		void Option(int id, const string& option);		// output menu option
		void Option(char id, const string& option);	// output menu option
		std::string Question(const string& question);	// output a question and return the user's input
		void BlockingMessage(const string& message);	// output message and wait for the user to press enter

	private:
		string title;

		void Header();
		void Footer();

};

