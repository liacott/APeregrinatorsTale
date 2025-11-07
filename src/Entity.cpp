#include "Entity.h"
#include "events/GameEvent.h"
#include "events/EventHandler.h"

// Setters and getters
void Entity::set_name(std::string new_name) {
	name = new_name;
}

std::string Entity::get_name() {
	return name;
}

void Entity::set_inspect_text(std::string new_text) {
	inspect_text = new_text;
}

std::string Entity::get_inspect_text() {
	return inspect_text;
}

void Entity::enable_inspect() {
	inspect_enabled = true;
}

void Entity::disable_inspect() {
	inspect_enabled = false;
}