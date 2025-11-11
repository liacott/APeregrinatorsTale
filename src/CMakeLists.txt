include(FetchContent)

FetchContent_Declare(ftxui
	GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI
	GIT_TAG v6.1.9
)

FetchContent_MakeAvailable(ftxui)

# Add source to this project's executable.
add_executable (main "main.cpp"        "events/GameEvent.h" "events/GameEvent.cpp"   "events/GameEventHandler.cpp" "events/GameEventHandler.h"    "scenes/SceneState.h"       "scenes/GameMap.h" "scenes/GameMap.cpp" "Cell.h" "languages/Language.h" "languages/LanguageManager.cpp" "scenes/SceneManager.cpp" "scenes/GameView.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET main PROPERTY CXX_STANDARD 20)
endif()

target_link_libraries(main
	PRIVATE ftxui::screen
	PRIVATE ftxui::dom
	PRIVATE ftxui::component
)

# todo- Add tests

