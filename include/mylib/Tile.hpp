#ifndef TILE_H
#define TILE_H

enum TileTypes { DEFAULT = 0, DAMAGING, DOODAD, ENEMYSPAWNER };

class Tile
{
private:

protected:
	sf::Sprite shape;
	bool collision;
	short type;

public:
	Tile();
	Tile(short type, int grid_x, int grid_y, float gridSizeF,
		const sf::Texture& texture, const sf::IntRect& texture_rect,
		bool collision);
	virtual ~Tile();

	//Accessors
	short getType() const;
	virtual bool getCollision() const;

	//Functions
	virtual const sf::Vector2f& getPosition() const;
	virtual sf::FloatRect getGlobalBounds() const;
	virtual bool intersects(const sf::FloatRect& bounds) const;
	virtual std::string getAsString() const = 0;

	virtual void update() = 0;
	virtual void render(sf::RenderTarget& target, sf::Shader* shader = NULL, sf::Vector2f player_position = sf::Vector2f()) = 0;
};

#endif