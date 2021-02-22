#ifndef STATE_H
#define STATE_H

#include "Player.hpp"
#include "GraphicsSettings.hpp"

class Player;
class GraphicsSettings;
class State;

class StateData
{
public:
	StateData() {};

	//Variables
	float gridSize;
	sf::RenderWindow* window;
	GraphicsSettings* gfxSettings;
	std::map<std::string, int>* supportedKeys;
	std::stack<State*>* states;
};

class State
{
private:

protected:
	StateData* stateData;
	std::stack<State*>* states;
	sf::RenderWindow* window;
	std::map<std::string, int>* supportedKeys;
	std::map<std::string, int> keybinds;
	bool quit;
	bool paused;
	float keytime;
	float keytimeMax;
	float gridSize;

	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
	sf::Vector2i mousePosGrid;

	//Resources
	std::map<std::string, sf::Texture> textures;

	//Functions
	virtual void initKeybinds() = 0;

public:
	State(StateData* state_data);
	virtual ~State();

	//Accessors
	bool getQuit() const;
	bool getKeytime();

	//Functions	
	void endState(); 
	void pauseState();
	void unpauseState();
	
	virtual void updateMousePositions(sf::View* view = NULL);
	virtual void updateKeytime(float dt);
	virtual void updateInput(float dt) = 0;
	virtual void update(float dt) = 0;
	virtual void render(sf::RenderTarget* target = NULL) = 0;
};

#endif