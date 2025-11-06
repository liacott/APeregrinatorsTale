#include <iostream>
#include <algorithm>

#include "ftxui/component/component.hpp" // for Components (Menu)
#include "ftxui/component/component_options.hpp"  // for ButtonOption, CheckboxOption & MenuOption
#include "ftxui/component/screen_interactive.hpp"

// Display main menu and handle input
int display_main_menu()
{
	auto screen = ftxui::ScreenInteractive::TerminalOutput();

	int selected = 0;
	auto mainMenu = ftxui::Container::Vertical({
		ftxui::MenuEntry(""),
		ftxui::MenuEntry("Settings"),
		ftxui::MenuEntry("Quit"),
		}, &selected);
	
	screen.Loop(mainMenu);
	return 0;
}

// Display class select menu and handle input
int display_class_select()
{
	return 0;
}

// Display difficult select menu and handle input
int display_difficulty_select() 
{
	return 0;
}
