include(FetchContent)

FetchContent_Declare(ftxui
	GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI
	GIT_TAG v6.1.9
)

FetchContent_MakeAvailable(ftxui)

# Add source to this project's executable.
add_executable (main "main.cpp"  "MenuManager.h" "PlayerInterface.h" "Entity.cpp" "Entity.h" "Actor.cpp" "Actor.h" "events/GameEvent.h" "events/GameEvent.cpp"   "events/GameEventHandler.cpp" "events/GameEventHandler.h" "events/QuickTime.h" "scenes/Scene.cpp" "events/QuickTime.cpp" "scenes/Scene.h" "scenes/MenuScene.cpp" "scenes/MenuScene.h"   "Game.cpp" "Game.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET main PROPERTY CXX_STANDARD 20)
endif()

target_link_libraries(main
	PRIVATE ftxui::screen
	PRIVATE ftxui::dom
	PRIVATE ftxui::component
)

# todo- Add tests

