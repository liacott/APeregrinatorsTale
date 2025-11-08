#pragma once

#include <iostream>
#include <vector>
#include "GameEvent.h"

// Class to resolve a queue of events in a scene
class GameEventHandler {

public:
	
	std::vector<GameEvent> queue;

	// Overload == as member function
	bool operator==(const GameEventHandler& other)
		const {
		return	queue == other.queue;
	}

	void resolve_next();

	void queue_event(GameEvent ev); 
	void insert_event_at(int pos, GameEvent ev);
	void remove_event_at(int pos, GameEvent ev); 
	void clear_queue();
};