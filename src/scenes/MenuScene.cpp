#include "MenuScene.h"

void MenuScene::initialize_nav_map() {

}

void MenuScene::initialize_choices() {

}

std::string MenuScene::display_menu() {
	auto screen = ftxui::ScreenInteractive::TerminalOutput();
	
	//Title renderer
	auto renderer = ftxui::Renderer([] {return ftxui::text("A PEREGRINATOR'S TALE"); });

}