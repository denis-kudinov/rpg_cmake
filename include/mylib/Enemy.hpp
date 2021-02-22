#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.hpp"
#include "EnemySpawnerTile.hpp"
#include "AIFollow.hpp"

class Enemy :
	public Entity
{
protected:
	//Variables
	EnemySpawnerTile& enemySpawnerTile;
	unsigned gainExp;
	sf::Clock damageTimer;
	sf::Int32 damageTimerMax;
	sf::Clock despawnTimer;
	sf::Int32 despawnTimerMax;

	//Initializer functions
	virtual void initVariables() = 0;
	virtual void initAnimations() = 0;

public:
	Enemy(EnemySpawnerTile& enemy_spawner_tile);
	virtual ~Enemy();

	//Accessors
	unsigned getGainExp() const;
	EnemySpawnerTile& getEnemySpawnerTile();
	bool getDamageTimerDone() const;
	bool getDespawnTimerDone() const;

	//Modifiers
	void resetDamageTimer();

	//Functions
	virtual void generateAttributes(unsigned level);

	virtual void loseHP(int hp);
	virtual bool isDead() const;

	virtual const AttributeComponent* getAttributeComp() const;

	virtual void updateAnimation(float dt) = 0;

	virtual void update(float dt, sf::Vector2f& mouse_pos_view, const sf::View& view) = 0;
	virtual void render(sf::RenderTarget& target, sf::Shader* shader = NULL, const sf::Vector2f& light_position = sf::Vector2f(), bool show_hitbox = false) = 0;
};

#endif //!ENEMY_H
