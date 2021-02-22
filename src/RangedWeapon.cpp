#include "mylib/stdafx.hpp"
#include "mylib/RangedWeapon.hpp"

RangedWeapon::RangedWeapon(unsigned level, unsigned value, std::string texture_file)
	: Weapon(level, value, texture_file)
{
	this->type = ItemTypes::IT_RANGEDWEAPON;
}

RangedWeapon::~RangedWeapon()
{

}

void RangedWeapon::generate(unsigned levelMin, unsigned levelMax)
{

}
