#include "mylib/stdafx.hpp"
#include "mylib/AIComponent.hpp"

AIComponent::AIComponent(Entity& self, Entity& entity)
	: self(self), entity(entity)
{
}

AIComponent::~AIComponent()
{
}

void AIComponent::update(float dt)
{
}
