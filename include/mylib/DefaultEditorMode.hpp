#ifndef DEFAULTEDITORMODE_H
#define DEFAULTEDITORMODE_H

#include "EditorMode.hpp"

class State;
class StateData;
class EditorMode;
class TileMap;
class Tile;

class DefaultEditorMode :
	public EditorMode
{
private:
	sf::Text cursorText;
	sf::RectangleShape sidebar;
	sf::RectangleShape selectorRect;
	gui::TextureSelector* textureSelector;
	sf::IntRect textureRect;
	bool collision;
	short type;
	int layer;
	bool tileAddLock;

	void initVariables();
	void initGui();

public:
	DefaultEditorMode(StateData* state_data, TileMap* tile_map, EditorStateData* editor_state_data);
	virtual ~DefaultEditorMode();

	void updateInput(float dt);
	void updateGui(float dt);
	void update(float dt);

	void renderGui(sf::RenderTarget& target);
	void render(sf::RenderTarget& target);
};

#endif //!DEFAULTEDITORMODE_H