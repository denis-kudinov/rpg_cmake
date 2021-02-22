#ifndef RAT_H
#define RAT_H

#include "Enemy.hpp"

class Rat :
	public Enemy
{
private:
	void initVariables();
	void initAnimations();
	void initAI();
	void initGUI();

	sf::RectangleShape hpBar;

	AIFollow* follow;

public:
	Rat(float x, float y, sf::Texture& texture_sheet, EnemySpawnerTile& enemy_spawner_tile, Entity& player);
	virtual ~Rat();

	//Functions
	void updateAnimation(float dt);
	void update(float dt, sf::Vector2f& mouse_pos_view, const sf::View& view);

	void render(sf::RenderTarget& target, sf::Shader* shader, const sf::Vector2f& light_position, bool show_hitbox);
};

#endif //!RAT_H