#include "mylib/stdafx.hpp"
#include "mylib/VectorMath.hpp"

float vectorDistance(float x1, float y1, float x2, float y2)
{
	const float dx = x2 - x1;
	const float dy = y2 - y1;

	return sqrt(pow(dx, 2) + pow(dy, 2));
}

float vectorDistance(sf::Vector2f vec1, sf::Vector2f vec2)
{
	const sf::Vector2f dVec = vec2 - vec1;

	return sqrt(pow(dVec.x, 2) + pow(dVec.y, 2));
}
