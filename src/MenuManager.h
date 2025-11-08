#include <iostream>
#include <algorithm>

#include "ftxui/component/component.hpp" // for Components (Menu)
#include "ftxui/component/component_options.hpp"  // for ButtonOption, CheckboxOption & MenuOption
#include "ftxui/component/screen_interactive.hpp"

// Display main menu and return user selection
std::string main_menu()
{
	auto screen = ftxui::ScreenInteractive::TerminalOutput();
	// Initialize title renderer
	auto renderer = ftxui::Renderer([] { return ftxui::text("A PEREGRINATOR'S TALE"); });
	
	// Initialize choices for menu
	int selected = 0;
	auto menu_choices = ftxui::Container::Vertical(
		{
		ftxui::MenuEntry("Start Game"),
		ftxui::MenuEntry("Settings"),
		ftxui::MenuEntry("Quit"),
		}, &selected);

	// Handle user input
	menu_choices |= ftxui::CatchEvent([&](ftxui::Event event){
			if (event == ftxui::Event::Special({ 10 }))
			{
				screen.ExitLoopClosure()();
				return true;
			}
			return false;
		});

	// Put all components in one container and loop it
	auto main_menu = ftxui::Container::Vertical({
		renderer,
		menu_choices,
		});

	screen.Loop(main_menu);
	switch (selected) {
	case 0:
		return "start_game"; // Start game leads to class select
	case 1:
		return "settings";
	case 2:
		return "quit";
	default:
		return "INVALID_CHOICE";
	}
	
}

// Display player class select menu and return user selection
std::string class_select()
{
	auto screen = ftxui::ScreenInteractive::TerminalOutput();
	// Initialize page label renderer
	auto renderer = ftxui::Renderer([] { return ftxui::text("CHOOSE A CLASS"); });

	// Initialize class choices
	int selected = 0;
	auto class_choices = ftxui::Container::Vertical(
		{
		ftxui::MenuEntry("Apothecary")	| ftxui::color(ftxui::Color::Cyan3),
		ftxui::MenuEntry("Laborer")		| ftxui::color(ftxui::Color::Magenta3),
		ftxui::MenuEntry("Pardoner")	| ftxui::color(ftxui::Color::Gold1),
		ftxui::MenuEntry("Back")
		}, &selected);

	// Handle user input
	class_choices |= ftxui::CatchEvent([&](ftxui::Event event) {
		if (event == ftxui::Event::Special({ 10 }))
		{
			screen.ExitLoopClosure()();
			return true;
		}
		return false;
		});

	// Put all components in one container and loop it
	auto classSelect = ftxui::Container::Vertical({
		renderer,
		class_choices,
		});

	screen.Loop(classSelect);
	switch (selected) {
	case 0:
		return "0"; // TODO
	case 1:
		return "0"; // TODO
	case 2:
		return "0"; // TODO
	case 3:
		return "main_menu"; // 'Back' returns to main menu
	default:
		return "INVALID_CHOICE";
	}

}

// Display difficult select menu and return user selection (maybe?)
int difficulty_select() 
{
	return 0; // TODO
}

// Display settings menu and handle user input
// WRITE ME

// Handle the flow between menus
bool startup_menu_flow() {
	std::string menu_choice = main_menu();
	if (menu_choice == "quit") 
	{
		return false;
	}
	else if (menu_choice == "settings")
	{
		return false; // TODO
	}
}