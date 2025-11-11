#include "LanguageManager.h"

Language& LanguageManager::get_language(const std::string& id) {
	return language_registry.at(id);
}

bool LanguageManager::exists(const std::string& id) const {
	return language_registry.find(id) != language_registry.end();
}

std::string LanguageManager::create_language(std::string lang_name, const std::string& parent_ID) {
	std::string id = "lang_" + std::to_string(++lang_counter);
	std::vector<Variety> lang_varieties;
	Language lang{ id, lang_name, parent_ID, 1.0, 1.0, 0, lang_varieties };
	language_registry[id] = lang;
	return id;
}