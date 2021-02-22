#ifndef WEAPON_H
#define WEAPON_H

#include "Item.hpp"

class Weapon :
	public Item
{
private:
	void initVariables();

protected:
	sf::Texture weapon_texture;
	sf::Sprite weapon_sprite;

	unsigned damageMin;
	unsigned damageMax;
	unsigned range;

	sf::Clock attackTimer;
	sf::Int32 attackTimerMax;

public:
	Weapon(unsigned level, unsigned value, std::string texture_file);
	Weapon(unsigned level, unsigned damageMin, unsigned damageMax, unsigned range,
		unsigned value,
		std::string texture_file);
	virtual ~Weapon();

	//Accessors
	unsigned getDamageMin() const;
	unsigned getDamageMax() const;
	unsigned getDamage() const;
	unsigned getRange() const;
	bool getAttackTimer();

	//Function
	virtual Item* clone() = 0;
	virtual void generate(unsigned levelMin, unsigned levelMax) = 0;

	virtual void update(const sf::Vector2f& mouse_pos_view, const sf::Vector2f& center) = 0;
	virtual void render(sf::RenderTarget& target, sf::Shader* shader = nullptr) = 0;
};

#endif
