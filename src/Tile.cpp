#include "mylib/stdafx.hpp"
#include "mylib/Tile.hpp"

Tile::Tile()
{
	this->collision = false;
	this->type = 0;
}

Tile::Tile(short type, int grid_x, int grid_y, float gridSizeF,
	const sf::Texture& texture, const sf::IntRect& texture_rect,
	bool collision)
{
	//this->shape.setOutlineThickness(1.f);
	//this->shape.setOutlineColor(sf::Color::Black);
	this->shape.setPosition(static_cast<float>(grid_x) * gridSizeF, static_cast<float>(grid_y) * gridSizeF);
	this->shape.setTexture(texture);
	this->shape.setTextureRect(texture_rect);

	this->collision = collision;
	this->type = type;
}

Tile::~Tile()
{

}

//Accessors
short Tile::getType() const
{
	return this->type;
}

bool Tile::getCollision() const
{
	return this->collision;
}

const sf::Vector2f& Tile::getPosition() const
{
	return this->shape.getPosition();
}

sf::FloatRect Tile::getGlobalBounds() const
{
	return this->shape.getGlobalBounds();
}

//Functions
bool Tile::intersects(const sf::FloatRect& bounds) const
{
	return this->shape.getGlobalBounds().intersects(bounds);
}
