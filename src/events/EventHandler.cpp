#include <vector>
#include "EventHandler.h"

void EventHandler::resolve_next() {
	// WRITE ME
}

void EventHandler::queue_event(GameEvent ev) {
	queue.push_back(ev);
}

void EventHandler::insert_event_at(int pos, GameEvent ev) {
	queue.insert(queue.begin() + pos, ev);
}

void EventHandler::remove_event_at(int pos, GameEvent ev) {
	queue.erase(
		remove(queue.begin(), queue.end(), queue[pos]),
		queue.end()
	);
}



