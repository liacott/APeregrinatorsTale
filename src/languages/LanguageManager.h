#pragma once
#include <string>
#include <unordered_map>
#include "Language.h"

class LanguageManager {

	std::unordered_map<std::string, Language> language_registry; // <lang_id, lang>
	std::unordered_map<std::string, Variety> variety_registry; // <var_id, var>
	int lang_counter = 0; // Counter for number of unique language IDs

public:
	// Access and modify language data
	Language& get_language(const std::string& id);
	bool exists(const std::string& id) const;
	
	// Add a new language to the registry and return its ID
	std::string create_language(std::string lang_name, const std::string& parent_ID);

};