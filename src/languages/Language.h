#pragma once
#include <string>
#include <vector>
#include <unordered_map>

struct Variety {
	std::string var_id;
	std::string name;
	std::string parent_ID;
	double covert_prestige_factor;	// Multiplied by base_prestige of parent for spread
	double overt_prestige_factor;	// Multiplied by base-prestige of parent for spread
};

struct Language {
	std::string lang_id;
	std::string name;
	std::string parent_ID;
	double writing_complexity;
	double base_prestige;
	int total_speakers;	// Total speakers of this language on the entire map
	std::vector<Variety> varieties;	// Varieties of this language
};