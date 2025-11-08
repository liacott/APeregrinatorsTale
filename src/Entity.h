#pragma once

#include <iostream>
#include "events/GameEvent.h"

// Superclass to handle all interactable NPCs and objects
class Entity {

public:
	int id;	// Entity IDs should be a 6 digit number of the format 2XXXXX
	std::string name;
	std::string inspect_text; // What the player sees when inspecting
	bool inspect_enabled;
	bool visible; // Whether the  entity is visible to the player
	
	Entity(int init_id = 0, std::string init_name = "", std::string init_text = "", 
		bool insp_status = true, bool is_vis = true)
	{
		id = init_id;
		name = init_name;
		inspect_text = init_text;
		inspect_enabled = insp_status;
		visible = is_vis;
	}

	// Overload == as member function
	bool operator==(const Entity& other)
		const {
		return	id == other.id &&
			name == other.name &&
			inspect_text == other.inspect_text &&
			inspect_enabled == other.inspect_enabled;
	}

	// Setters and getters
	int get_id();

	void set_name(std::string new_name);
	std::string get_name();

	void set_inspect_status(bool new_status);
	void set_inspect_text(std::string new_text);
	std::string get_inspect_text();
	
	void set_visibility(bool new_visibility);
	bool get_visibility();
	
};