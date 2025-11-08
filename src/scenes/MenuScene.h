#pragma once

#include <iostream>
#include <algorithm>
#include <map>

#include "Scene.h"
#include "ftxui/component/component.hpp" // for Components (Menu)
#include "ftxui/component/component_options.hpp"  // for ButtonOption, CheckboxOption & MenuOption
#include "ftxui/component/screen_interactive.hpp"

class MenuScene : public Scene {
public:
	
	std::map<std::string, Scene> nav_map; // Possible inputs and scenes they go to

	// Overload == as member function
	bool operator==(const MenuScene& other)
		const {
		return	id == other.id &&
			local_event_handler == other.local_event_handler &&
			scene_entities == other.scene_entities &&
			nav_map == other.nav_map;
	}

	void initialize_nav_map(); // 
	void initialize_choices(); // Put user choices into a vertical container

	std::string display_menu(); // Display menu and get user input
};