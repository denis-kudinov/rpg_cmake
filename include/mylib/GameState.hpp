#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.hpp"
#include "PauseMenu.hpp"
#include "TileMap.hpp"
#include "PlayerGUI.hpp"
#include "Sword.hpp"
#include "TextTagSystem.hpp"

class GameState :
	public State
{
private:
	sf::View view;
	sf::Vector2i viewGridPosition;
	sf::RenderTexture renderTexture;
	sf::Sprite renderSprite;

	sf::Font font;
	PauseMenu* pmenu;

	sf::Shader core_shader;

	sf::Clock keyTimer;
	float keyTimeMax;

	sf::Text debugText;

	Player* player;
	PlayerGUI* playerGUI;
	sf::Texture texture;

	std::vector<Enemy*> activeEnemies;
	EnemySystem* enemySystem;

	TileMap* tileMap;

	//Systems
	TextTagSystem* tts;

	//Functions
	void initDeferredRender();
	void initView();
	void initKeybinds();
	void initFonts();
	void initTextures();
	void initPauseMenu();
	void initShaders();
	void initKeyTime();
	void initDebugText();

	void initPlayers();
	void initPlayerGUI();
	void initEnemySystem();
	void initTileMap();
	void initSystems();

public:
	GameState(StateData* state_data);
	virtual ~GameState();

	//Accessors
	bool getKeyTime();

	//Functions
	void updateView(float dt);
	void updateInput(float dt);
	void updatePlayerInput(float dt);
	void updatePlayerGUI(float dt);
	void updatePauseMenuButtons();
	void updateTileMap(float dt);
	void updatePlayer(float dt);
	void updateCombatAndEnemies(float dt);
	void updateCombat(Enemy* enemy, int index, float dt);
	void updateDebugText(float dt);
	void update(float dt);

	void render(sf::RenderTarget* target = NULL);
};

#endif