#include "Entity.h"
#include "events/GameEvent.h"
#include "events/GameEventHandler.h"

// Setters and getters
int Entity::get_id() {
	return id;
}

void Entity::set_name(std::string new_name) {
	name = new_name;
}

std::string Entity::get_name() {
	return name;
}

void Entity::set_inspect_status(bool new_status) {
	inspect_enabled = new_status;
}

void Entity::set_inspect_text(std::string new_text) {
	inspect_text = new_text;
}

std::string Entity::get_inspect_text() {
	return inspect_text;
}

void Entity::set_visibility(bool new_visibility) {
	visible = new_visibility;
}

bool Entity::get_visibility() {
	return visible;
}