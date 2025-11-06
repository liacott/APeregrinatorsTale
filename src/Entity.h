// Superclass to handle all interactable NPCs and objects
class Entity {

public:
	std::string name;
	std::string inspect_text; // What the player sees when inspecting
		
	Entity(std::string x, std::string i = "") {
		name = x;
		inspect_text = i;
	}


	void set_name(std::string new_name) {
		name = new_name;
	}

	// TODO FINISH SETTERS AND GETTERS

	// TODO INIT OTHER FUNCTIONS

	// TODO MAKE SUBCLASS FOR NPCS AND MISC ACTIVE
	//	-ActorEntity

};