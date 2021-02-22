#include "mylib/stdafx.hpp"
#include "mylib/Item.hpp"

void Item::initVariables()
{

}

Item::Item(unsigned level, unsigned value)
{
	this->initVariables();

	this->level = level;
	this->value = value;
	this->type = ItemTypes::IT_DEFAULT;
}

Item::~Item()
{

}
