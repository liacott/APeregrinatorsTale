#pragma once
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <functional>
#include "SceneState.h"

class SceneManager {

	std::shared_ptr<SceneState> state;

	// Scenes as components
	ftxui::Component main_menu;
	ftxui::Component spirit_select;
	ftxui::Component load_menu;
	ftxui::Component settings_menu;
	ftxui::Component game_view;

	// Build individual scenes
	ftxui::Component build_main_menu(std::shared_ptr<SceneState> state);
	//ftxui::Component build_spirit_select(std::shared_ptr<SceneState> state);
	//ftxui::Component build_load_menu(std::shared_ptr<SceneState> state);
	ftxui::Component build_settings_menu(std::shared_ptr<SceneState> state);
	//ftxui::Component build_game_view(bool hardmode);
	
	// Toggles for settings menu
	ftxui::Component make_hardmode_toggle(bool* enabled);

public:
	SceneManager(std::shared_ptr<SceneState> state);

	ftxui::Component build_scene(Scene scene, std::shared_ptr<SceneState> state);
};