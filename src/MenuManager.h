#include <iostream>
#include <algorithm>

#include "ftxui/component/component.hpp" // for Components (Menu)
#include "ftxui/component/component_options.hpp"  // for ButtonOption, CheckboxOption & MenuOption
#include "ftxui/component/screen_interactive.hpp"

// Display main menu and return user selection
std::string display_main_menu()
{
	auto screen = ftxui::ScreenInteractive::TerminalOutput();
	screen.Clear();
	// Initialize title renderer
	auto renderer = ftxui::Renderer([] { return ftxui::text("A PEREGRINATOR'S TALE"); });
	
	// Initialize choices for menu
	int selected = 0;
	auto menuChoices = ftxui::Container::Vertical(
		{
		ftxui::MenuEntry("Start Game"),
		ftxui::MenuEntry("Settings"),
		ftxui::MenuEntry("Quit"),
		}, &selected);

	// Handle user input
	menuChoices |= ftxui::CatchEvent([&](ftxui::Event event){
			if (event == ftxui::Event::Special({ 10 }))
			{
				screen.ExitLoopClosure()();
				return true;
			}
			return false;
		});

	// Put all components in one container and loop it
	auto mainMenu = ftxui::Container::Vertical({
		renderer,
		menuChoices,
		});
	screen.Loop(mainMenu);
	switch (selected) {
	case 0:
		return "class_select"; // Start game leads to class select
	case 1:
		return "settings";
	case 2:
		return "quit";
	default:
		return "INVALID_CHOICE";
	}
	
}

// Display player class select menu and return user selection
std::string display_class_select()
{
	auto screen = ftxui::ScreenInteractive::TerminalOutput();
	screen.Clear();
	// Initialize page label renderer
	auto renderer = ftxui::Renderer([] { return ftxui::text("CHOOSE A CLASS"); });

	// Initialize class choices
	int selected = 0;
	auto classChoices = ftxui::Container::Vertical(
		{
		ftxui::MenuEntry("Boatman"),
		ftxui::MenuEntry("Pardoner"),
		ftxui::MenuEntry("Game Warden"),
		ftxui::MenuEntry("Back")
		}, &selected);

	// Handle user input
	classChoices |= ftxui::CatchEvent([&](ftxui::Event event) {
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
		classChoices,
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

// Display difficult select menu and return user selection
int display_difficulty_select() 
{
	return 0; // TODO
}

// Display settings menu and handle user input
// WRITE ME