#include "scenes/SceneManager.h"
#include "scenes/SceneState.h"
#include <ftxui/component/screen_interactive.hpp>
#include <functional>	// for functionn
#include <memory>		// for make_shared & shared_ptr
#include <utility>		// for forward
#include <iostream>

int main()
{
	auto screen = ftxui::ScreenInteractive::Fullscreen();

	auto state = std::make_shared<SceneState>();
	state->current_scene = Scene::MainMenu;
	state->next_scene = Scene::MainMenu;

	SceneManager manager(state);

	// Pointer to active scene component
	ftxui::Component scene_component = manager.build_scene(state->current_scene, state);

	// Wrap active scene
	auto renderer = ftxui::Renderer(scene_component, [&]() mutable {
		// Rebuild scene on change
		if (state->next_scene != state->current_scene) {
			state->current_scene = state->next_scene;
			scene_component = manager.build_scene(state->current_scene, state);
		}
		return scene_component->Render();
	});

	screen.Loop(renderer);
	return 0;

}
