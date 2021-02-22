#ifndef ENEMYEDITORMODE_H
#define ENEMYEDITORMODE_H

#include "EditorMode.hpp"
#include "EnemySpawnerTile.hpp"

class State;
class StateData;
class EditorMode;
class TileMap;
class Tile;
class EnemySpawner;

class EnemyEditorMode :
	public EditorMode
{
private:
	sf::Text cursorText;
	sf::RectangleShape sidebar;
	sf::RectangleShape selectorRect;
	sf::IntRect textureRect;

	int type;
	int amount;
	int timeToSpawn;
	float maxDistance;

	void initVariables();
	void initGui();

public:
	EnemyEditorMode(StateData* state_data, TileMap* tile_map, EditorStateData* editor_state_data);
	virtual ~EnemyEditorMode();

	//Functions
	void updateInput(float dt);
	void updateGui(float dt);
	void update(float dt);

	void renderGui(sf::RenderTarget& target);
	void render(sf::RenderTarget& target);
};

#endif //!ENEMYEDITORMODE_H
