#ifndef REGULARTILE_H
#define REGULARTILE_H

#include "Tile.hpp"

class RegularTile :
	public Tile
{
private:

protected:

public:
	RegularTile(short type, int grid_x, int grid_y, float gridSizeF,
		const sf::Texture& texture, const sf::IntRect& texture_rect,
		bool collision = false);

	virtual ~RegularTile();

	//Functions
	virtual std::string getAsString() const;

	virtual void update();
	virtual void render(sf::RenderTarget& target, sf::Shader* shader = NULL, sf::Vector2f player_position = sf::Vector2f());
};

#endif //!REGULARTILE_H
