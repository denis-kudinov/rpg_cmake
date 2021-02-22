#pragma once
#include "AIOption.hpp"
class AIFollow :
    public AIOption
{
private:

public:
    AIFollow(Entity& self, Entity& entity);
    ~AIFollow();

    void update(float dt);
};

