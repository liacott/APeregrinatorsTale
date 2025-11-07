#pragma once

#include <iostream>
#include "events/GameEvent.h"

// Superclass to handle all interactable NPCs and objects
class Entity {

public:
	std::string name;
	std::string inspect_text; // What the player sees when inspecting
	bool inspect_enabled;
		
	Entity(std::string init_name, std::string init_text = "", bool insp_status = true) {
		name = init_name;
		inspect_text = init_text;
		inspect_enabled = insp_status;
	}

	// Setters and getters
	void set_name(std::string new_name);
	std::string get_name();

	void set_inspect_text(std::string new_text);
	std::string get_inspect_text();

	void enable_inspect();
	void disable_inspect();

	void 
	
};