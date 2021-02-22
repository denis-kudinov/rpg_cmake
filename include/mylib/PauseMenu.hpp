#ifndef PAUSEMENU_H
#define PAUSEMENU_H

#include"Gui.hpp"

class Gui;

class PauseMenu
{
private:
	sf::Font& font;
	sf::Text menuText;

	sf::RectangleShape background;
	sf::RectangleShape container;

	std::map<std::string, gui::Button*> buttons;

	//Private Functions

public:
	PauseMenu(sf::VideoMode& vm, sf::Font& font);
	virtual ~PauseMenu();

	std::map<std::string, gui::Button*>& getButtons();

	void setMenuText(std::string text);
	bool isButtonPressed(const std::string& key);
	void addButton(const std::string& key,
		float y,
		float width,
		float height,
		unsigned char_size,
		const std::string& text);
	void update(const sf::Vector2i& mousePosWindow);
	void render(sf::RenderTarget& target);
};

#endif