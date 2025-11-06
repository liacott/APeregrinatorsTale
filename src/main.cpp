#include "APeregrinatorsTale.h"
#include "MenuManager.h"

#include <functional>	// for functionn
#include <memory>		// for make_shared & shared_ptr
#include <utility>		// for forward
#include <iostream>

#include "ftxui/component/component.hpp" // for Components (Menu)
#include "ftxui/component/component_options.hpp"  // for ButtonOption, CheckboxOption & MenuOption
#include "ftxui/component/screen_interactive.hpp" // for Element


int main()
{
	using namespace ftxui;

	display_main_menu();

	return 0;

}
