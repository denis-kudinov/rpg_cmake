#pragma once
#include"Entity.hpp"

class AIOption
{
protected:

	Entity& self;
	Entity& entity;

public:
	AIOption(Entity& self, Entity& entity)
		: self(self), entity(entity)
	{

	}

	virtual void update(float dt) = 0;
};

