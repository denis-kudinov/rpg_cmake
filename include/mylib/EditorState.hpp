#ifndef EDITORSTATE_H
#define EDITORSTATE_H

#include "State.hpp"
#include "Gui.hpp"
#include "PauseMenu.hpp"
#include "TileMap.hpp"
#include "EditorModes.hpp"

class State;
class StateData;
class Gui;
class PauseMenu;
class TileMap;
class Tile;
class EditorMode;
class DefaultEditorMode;
class EnemyEditorMode;
class EditorStateData;

enum EditorModes { DEFAULT_EDITOR_MODE = 0, ENEMY_EDITOR_MODE };

class EditorState :
	public State
{
private:
	//Variables
	EditorStateData editorStateData;

	sf::View view;
	float cameraSpeed;

	sf::Font font;
	PauseMenu* pmenu;

	std::map<std::string, gui::Button*> buttons;

	TileMap* tileMap;

	std::vector<EditorMode*> modes;
	unsigned activeMode;

	//Functions
	void initVariables();
	void initEditorStateData();
	void initView();
	void initFonts();
	void initKeybinds();
	void initPauseMenu();
	void initButtons();
	void initGui();
	void initTileMap();
	void initModes();

public:
	EditorState(StateData* state_data);
	virtual ~EditorState();

	//Functions
	void updateInput(float dt);
	void updateEditorInput(float dt);
	void updateButtons();
	void updateGui(float dt);
	void updatePauseMenuButtons();
	void updateModes(float dt);
	void update(float dt);
	void renderButtons(sf::RenderTarget& target);
	void renderGui(sf::RenderTarget& target);
	void renderModes(sf::RenderTarget& target);
	void render(sf::RenderTarget* target = NULL);
};

#endif

