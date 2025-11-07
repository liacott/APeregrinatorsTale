#pragma once

#include "Entity.h"

// Subclass to handle NPCs and other animate entities
class Actor : public Entity {

public:
	int base_mind;
	int base_body;
	int base_soul;
	int player_relationship; // Scale from (-3) to (+3)
	
	// Bools to determine whether certain menus are available
	bool social_enabled;

	void enable_social();
	void disable_social();

};