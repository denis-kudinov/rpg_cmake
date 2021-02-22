#ifndef ENEMYSYSTEM_H
#define ENEMYSYSTEM_H

#include "EnemySpawnerTile.hpp"
#include "Rat.hpp"
#include "Bird1.hpp"

enum EnemyTypes { RAT = 0, BIRD1 };

class EnemySystem
{
private:
	std::map<std::string, sf::Texture>& textures;
	std::vector<Enemy*>& activeEnemies;
	Entity& player;

public:
	EnemySystem(std::vector<Enemy*>& activeEnemies,
		std::map<std::string, sf::Texture>& textures, Entity& player);
	virtual ~EnemySystem();

	//Accessors

	//Modifiers

	//Functions
	void createEnemy(short type, float xPos, float yPos, EnemySpawnerTile& enemy_spawner_tile);
	void removeEnemy(int index);

	void update(float dt);
	void render(sf::RenderTarget* target);
};

#endif //!ENEMYSYSTEM_H