#include "Scene.h"

int Scene::get_id() {
	return id;
}

void Scene::add_entity(Entity new_entity) {
	scene_entities.push_back(new_entity);
}

// Look for and erase entities matching target ID in scene_entities
void Scene::remove_entity(int target_entity_id) {
	for (Entity ent : scene_entities) 
	{
		if (ent.get_id() == target_entity_id) 
		{
			int target_pos = find(scene_entities.begin(),
					scene_entities.end(), ent) - scene_entities.begin();
			scene_entities.erase(
				remove(scene_entities.begin(), scene_entities.end(), scene_entities[target_pos]),
				scene_entities.end()
			);
		}
	}
}

// Render visibile entities
void Scene::display_entities() {
	// TODO
}

// Render player interface
void Scene::display_interface() {
	// TODO
}