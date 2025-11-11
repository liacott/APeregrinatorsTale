#pragma once

enum class Scene {
	MainMenu,
	SpiritSelect,
	LoadMenu,
	Settings,
	GameView,
	Exit
};

struct SceneState {
	Scene current_scene;
	Scene next_scene;
};
