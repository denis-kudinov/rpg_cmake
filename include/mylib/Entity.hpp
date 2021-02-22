#ifndef ENTITY_H
#define ENTITY_H

#include "HitboxComponent.hpp"
#include "MovementComponent.hpp"
#include "AnimationComponent.hpp"
#include "AttributeComponent.hpp"
#include "SkillComponent.hpp"

class HitboxComponent;
class MovementComponent;
class AnimationComponent;
class AttributeComponent;
class SkillComponent;

class Entity
{
private:
	void initVariables();

protected:

	sf::Sprite sprite;
	std::vector<std::pair<sf::SoundBuffer, sf::Sound>> noises;
	HitboxComponent* hitboxComponent;
	MovementComponent* movementComponent;
	AnimationComponent* animationComponent;
	AttributeComponent* attributeComponent;
	SkillComponent* skillComponent;

public:
	Entity();
	virtual ~Entity();

	//Component functions
	void setTexture(sf::Texture& texture);
	void createHitboxComponent(sf::Sprite& sprite,
		float offset_x, float offset_y,
		float width, float height);
	void createMovementComponent(float maxVelocity, float acceleration, float deceleration);
	void createAnimationComponent(sf::Texture& texture_sheet);
	void createAttributeComponent(unsigned level);
	void createAttributeComponent(unsigned level, int vitality);
	void createSkillComponent();
	void createAIComponent();

	//Accessors
	virtual MovementComponent* getMovementComponent();
	virtual AnimationComponent* getAnimationComponent();
	virtual AttributeComponent* getAttributeComponent();
	virtual SkillComponent* getSkillComponent();

	virtual const sf::Vector2f& getPosition() const;
	virtual const sf::Vector2f& getSpritePosition() const;
	virtual sf::Vector2f getCenter() const;
	virtual sf::Vector2f getSpriteCenter() const;
	virtual sf::Vector2i getGridPosition(int gridSizeI) const;
	virtual sf::FloatRect getGlobalBounds() const;
	virtual sf::FloatRect getNextPositionBounds(float dt) const;

	//Modifiers
	virtual void setPosition(float x, float y);

	//Functions
	virtual void move(float x, float y, float dt);
	virtual void stopVelocity();
	virtual void stopVelocityX();
	virtual void stopVelocityY();

	//Calculations
	virtual float getDistance(const Entity& entity) const;
	virtual float getSpriteDistance(const Entity& entity) const;

	virtual void update(float dt, sf::Vector2f& mouse_pos_view, const sf::View& view) = 0;
	virtual void render(sf::RenderTarget& target, sf::Shader* shader, const sf::Vector2f& light_position, bool show_hitbox) = 0;
};

#endif

