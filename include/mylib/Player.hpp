#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.hpp"
#include "Items.hpp"
#include "Inventory.hpp"

class Entity;

class Player :
	public Entity
{
private:
	//Variables
	Inventory* inventory;

	bool initAttack;
	bool attacking;
	Weapon* weapon;

	sf::Clock damageTimer;
	sf::Int32 damageTimerMax;

	//Initializer functions
	void initVariables();
	void initComponents();
	void initAnimations();
	void initInventory();

public:
	Player(float x, float y, sf::Texture& texture_sheet);
	virtual ~Player();

	//Accessors
	AttributeComponent* getAttributeComponent();
	Weapon* getWeapon() const;

	std::string toStringCharacterTab() const;
	bool getInitAttack() const;

	bool getDamageTimer();

	unsigned getDamage();

	//Modifier
	void setInitAttack(bool initAttack);

	//Functions
	void loseHP(int hp);
	void gainHP(int hp);
	void loseEXP(int exp);
	void gainEXP(int exp);
	bool isDead() const;

	void updateAnimation(float dt);
	void update(float dt, sf::Vector2f& mouse_pos_view, const sf::View& view);

	void render(sf::RenderTarget& target, sf::Shader* shader = NULL, const sf::Vector2f& light_position = sf::Vector2f(), bool show_hitbox = false);
};

#endif