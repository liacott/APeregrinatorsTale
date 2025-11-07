#pragma once

#include <iostream>
#include <vector>
#include "GameEvent.h"

// Class to resolve a queue of events in a scene
class EventHandler {

	std::vector<GameEvent> queue;

public:
	
	void resolve_next(); // Resolve next event in queue

	void queue_event(GameEvent ev); // Add event to end of queue
	void insert_event_at(int pos, GameEvent ev); // Add event at a specific index in queue
	void remove_event_at(int pos, GameEvent ev); // Remove event at a specific index in queue
};