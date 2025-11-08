#pragma once

#include "../events/GameEventHandler.h"
#include "../Entity.h"
#include <iostream>

class Scene {

public:
	int id; // Scene IDs should be a 6 digit number of the format 1XXXXX
	GameEventHandler local_event_handler;
	std::vector<Entity> scene_entities;

	// Overload == as member function
	bool operator==(const Scene& other)
		const {
		return	id == other.id &&
			local_event_handler == other.local_event_handler &&
			scene_entities == other.scene_entities;
	}

	int get_id();

	void add_entity(Entity new_entity);
	void remove_entity(int target_entity_id); // Erase entities matching target ID

	void display_entities(); // Render all visible entities in scene_entities
	void display_interface(); // Render relevant in-game player interface
};