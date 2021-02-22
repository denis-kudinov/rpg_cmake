#ifndef TILEMAP_H
#define TILEMAP_H

#include "EnemySpawnerTile.hpp"
#include "RegularTile.hpp"
#include "EnemySystem.hpp"

class TileMap
{
private:
	void clear();

	float gridSizeF;
	int gridSizeI;
	sf::Vector2i maxSizeWorldGrid;
	sf::Vector2f maxSizeWorldF;
	int layers;
	std::vector< std::vector< std::vector< std::vector<Tile*> > > > map;
	std::stack<Tile*> deferredRenderStack;
	std::string textureFile;
	sf::Texture tileSheet;
	sf::RectangleShape collisionBox;

	//Culling
	int fromX;
	int toX;
	int fromY;
	int toY;
	int layer;

public:
	TileMap(float gridSize, int width, int height, std::string texture_file);
	TileMap(const std::string& file_name);
	virtual ~TileMap();

	//Accessors
	bool tileEmpty(int x, int y, int z) const;
	const sf::Texture* getTileSheet() const;
	int getLayerSize(int x, int y, int layer) const;
	const sf::Vector2i& getMaxSizeGrid() const;
	const sf::Vector2f& getMaxSizeF() const;

	//Functions
	void addTile(int x, int y, int z, const sf::IntRect& texture_rect, bool collision, short type);
	void addTile(int x, int y, int z, const sf::IntRect& texture_rect,
		int enemy_type, int enemy_amount, int enemy_tts, int enemy_md);
	void removeTile(int x, int y, int z, int type = -1);
	void saveToFile(const std::string& file_name);
	void loadFromFile(const std::string& file_name);
	bool checkType(int x, int y, int z, int type) const;

	void updateWorldBoundsCollision(Entity* entity, float dt);
	void updateTileCollision(Entity* entity, float dt);
	void updateTiles(Entity* entity, float dt, EnemySystem& enemySystem);
	void update(Entity* entity, float dt);

	void render(
		sf::RenderTarget& target,
		const sf::Vector2i& gridPosition,
		sf::Shader* shader = NULL,
		const sf::Vector2f playerPosition = sf::Vector2f(),
		const bool show_collision = false
	);
	void renderDeferred(sf::RenderTarget& target, sf::Shader* shader = NULL, sf::Vector2f playerPosition = sf::Vector2f());
};

#endif