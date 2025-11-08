#include "scenes/Scene.h"
#include <iostream>

class Game {
public:
	std::vector<Scene> game_scenes;

	void change_scene(int target_id);
	void render_scene();
	void initialize_scenes();
	
	void run();
};