#pragma once
#include <vector>
#include <string>
#include "../Cell.h"

class GameMap {
	std::vector<std::vector<Cell>> map_grid;
	int width;
	int height;

public:
	
	GameMap(int w, int h) {
		width = w;
		height = h;
	}

	Cell& get_cell(int x, int y);
	void initialize_from_JSON(const std::string& filename);
	void print_map() const;
	void update_language_shift();
	void update_political_map();

};

