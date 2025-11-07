#pragma once

// Super class to handle all in game events and entity interactions
class GameEvent {
public:
	int id;
	std::string name;

	GameEvent(int x, std::string n) {
		id = x;
		name = n;
	}

	// Overload == as member function
	bool operator==(const GameEvent& other)
	const {
		return	id == other.id &&
				name == other.name;
	}

	// Getters
	
	//

};