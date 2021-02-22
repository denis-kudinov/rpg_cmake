#pragma once

#include "CharacterTab.hpp"

enum PLAYER_TABS { CHARACTER_TAB = 0, INVENTORY_TAB };

class PlayerGUITabs
{
private:

	std::vector<Tab*> tabs;

	//Core
	sf::VideoMode& vm;
	sf::Font& font;
	Player& player;

	sf::Clock keyTimer;
	float keyTimeMax;

	//Tabs

	//Character Tab

	//Private functions
	void initTabs();
	void initKeyTime();

public:
	PlayerGUITabs(sf::VideoMode& vm, sf::Font& font, Player& player);
	virtual ~PlayerGUITabs();

	bool getKeyTime();
	bool tabsOpen();

	void toggleTab(int tab_index);

	void update();
	void render(sf::RenderTarget& target);
};

