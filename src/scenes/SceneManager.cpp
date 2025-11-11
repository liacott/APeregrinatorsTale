#include "SceneManager.h"
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/dom/elements.hpp>
#include <iostream>

SceneManager::SceneManager(std::shared_ptr<SceneState> state) : state(state) 
{
} 

ftxui::Component SceneManager::build_main_menu(std::shared_ptr<SceneState> state) {

	auto selected = std::make_shared<int>(0);
	std::vector<std::string> menu_options = { "New Game", "Load Game", "Settings", "Quit" };

	auto event_grabber = ftxui::Renderer(nullptr, [selected, menu_options]() {
		std::vector<ftxui::Element> entries;
		for (size_t i = 0; i < menu_options.size(); ++i) {
			auto ev = ftxui::text(menu_options[i]);
			if (*selected == i) {
				ev = ev | ftxui::bold | ftxui::inverted;
			}
		}
		return vbox(entries.begin(), entries.end());
	});

	// Handle user input and selection
	auto menu_component = ftxui::CatchEvent(event_grabber, [selected, &menu_options, state] (ftxui::Event event) {

		if (event == ftxui::Event::ArrowDown) {
			*selected = (*selected + 1) % menu_options.size();
			return true;
		}
		if (event == ftxui::Event::ArrowUp) {
			*selected = (*selected + menu_options.size() - 1) % menu_options.size();
			return true;
		}
		if (event == ftxui::Event::Return) {
			switch (*selected) {
				case 0: state->next_scene = Scene::SpiritSelect; break;
				case 1: state->next_scene = Scene::LoadMenu; break;
				case 2: state->next_scene = Scene::Settings; break;
				case 3: state->next_scene = Scene::Exit; break;
			}
			return true;
		}
		return false;
	});

	// Renderer for the menu
	return ftxui::Renderer(menu_component, [menu_component]() {
		return ftxui::vbox({
			ftxui::text("PNEUMALANG") | ftxui::bold | ftxui::center,
			ftxui::separator(),
			menu_component->Render(),
			ftxui::separator(),
			ftxui::text("Up/down to navigate, Enter to select") | ftxui::dim | ftxui::center
	}) 
	// Border and centering for whole menu
	| ftxui::border
	| ftxui::center;
	});
}

//ftxui::Component SceneManager::build_spirit_select() {
	// TODO
//}

//ftxui::Component SceneManager::build_load_menu() {
	// TODO
//}

// Make toggles for settings menu
ftxui::Component SceneManager::make_hardmode_toggle(bool* enabled) {
	
	return ftxui::CatchEvent(ftxui::Renderer([enabled] {
		std::string label = *enabled ? "HARDMODE: ENABLED" : "HARDMODE: DISABLED";
		ftxui::Decorator color_deco = (*enabled)
			? ftxui::color(ftxui::Color::RedLight)
			: ftxui::color(ftxui::Color::GrayLight);

		// Decorating toggle text
		return ftxui::text(label) | ftxui::bold | color_deco | ftxui::center; 

	}), [enabled](ftxui::Event event) {
		if (event == ftxui::Event::Return) {
			*enabled = !*enabled;
			return true;
		}
		return false;
	});
}

ftxui::Component SceneManager::build_settings_menu(std::shared_ptr<SceneState> state) {

	bool hardmode_enabled = false;

	auto hardmode_toggle = make_hardmode_toggle(&hardmode_enabled);

	std::vector<std::string> menu_entries = {
		"Toggle Hardmode",
		"Back"
	};
	int selected = 0;

	auto menu = ftxui::Menu(&menu_entries, &selected);

	// Combine menu and toggle together
	auto layout = ftxui::Renderer(menu, [&] {
		ftxui::Elements lines;
		lines.push_back(ftxui::text("#### SETTINGS ####") | ftxui::bold | ftxui::center);
		lines.push_back(ftxui::separator());

		if (selected == 0) {
			// Show hardmode state when hovered over
			lines.push_back(make_hardmode_toggle(&hardmode_enabled)->Render());
		}
		else {
			// Show static label otherwise
			lines.push_back(ftxui::text("Hardmode Enabled: ") |
				(hardmode_enabled ? ftxui::color(ftxui::Color::RedLight)
					: ftxui::color(ftxui::Color::GrayLight)) |
				ftxui::center);
		}

		lines.push_back(ftxui::separator());
		lines.push_back(ftxui::text("Back") |
			(selected == 1 ? ftxui::inverted : ftxui::nothing) |
			ftxui::center);

		return vbox(lines) | ftxui::border | ftxui::center;

		});
	
	// Handle enter key press
	auto component = ftxui::CatchEvent(layout, [&](ftxui::Event event) {
		if (event == ftxui::Event::Return) {
			if (selected == 0) {
				hardmode_enabled = !hardmode_enabled; // Flip hardmode status on press
			}
			else if (selected == 1) {
				//screen.Exit();
				state->next_scene = Scene::MainMenu;
			}
			return true;
		}
		return false;
	});

	return component;
}

//ftxui::Component SceneManager::build_game_view(bool hardmode) {
	// TODO
//}

ftxui::Component SceneManager::build_scene(Scene scene, std::shared_ptr<SceneState> state) {
	switch (scene) {
	case Scene::MainMenu:
		return build_main_menu(state);
	//case Scene::Settings:
		return ftxui::Renderer([] { return ftxui::text("Settings placeholder"); });
	//case Scene::LoadMenu:
		return ftxui::Renderer([] { return ftxui::text("Load Menu placeholder"); });
	case Scene::SpiritSelect:
		return ftxui::Renderer([] { return ftxui::text("Spirit Select placeholder"); });
	case Scene::Exit:
		std::exit(0); // exit immediately
	default:
		return ftxui::Renderer([] { return ftxui::text("ERROR: UNKNOWN SCENE"); });
	}
}