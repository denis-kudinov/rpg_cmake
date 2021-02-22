#include "mylib/stdafx.hpp"

#include "mylib/Player.hpp"

//Initializer functions
void Player::initVariables()
{
	this->initAttack = false;
	this->attacking = false;
	this->weapon = new Sword(1, 2, 5, 100, 20, "Resources/Images/Sprites/Player/sword.png");
	this->weapon->generate(1, 3);
	this->damageTimerMax = 500;
}

void Player::initComponents()
{

}

void Player::initAnimations()
{
	this->animationComponent->addAnimation("IDLE", 15.f, 0, 0, 0, 0, 32, 32);
	this->animationComponent->addAnimation("WALK_DOWN", 11.f, 0, 0, 2, 0, 32, 32);
	this->animationComponent->addAnimation("WALK_LEFT", 11.f, 0, 1, 2, 1, 32, 32);
	this->animationComponent->addAnimation("WALK_RIGHT",11.f, 0, 2, 2, 2, 32, 32);
	this->animationComponent->addAnimation("WALK_UP",   11.f, 0, 3, 2, 3, 32, 32);
}

void Player::initInventory()
{
	this->inventory = new Inventory(100);
}

//Constructors / Destructors
Player::Player(float x, float y, sf::Texture& texture_sheet)
{
	this->initVariables();

	this->createHitboxComponent(this->sprite, 0.f, 0.f, 32.f, 38.f);
	this->createMovementComponent(140.f, 1400.f, 1000.f);
	this->createAnimationComponent(texture_sheet);
	this->createAttributeComponent(1, 10);
	this->createSkillComponent();

	this->setPosition(x, y);
	this->initAnimations();

	this->initInventory();

	this->noises.resize(3);
	if (!noises[0].first.loadFromFile("Resources/Music/Player/hissing1.ogg"))
		std::cout << "ERROR Player::Player: could not load soud\n";
	noises[0].second.setBuffer(noises[0].first);

	if (!noises[1].first.loadFromFile("Resources/Music/Player/angry_or_scared.ogg"))
		std::cout << "ERROR Player::Player: could not load soud\n";
	noises[1].second.setBuffer(noises[1].first);

	if (!noises[2].first.loadFromFile("Resources/Music/Player/just_fine.ogg"))
		std::cout << "ERROR Player::Player: could not load soud\n";
	noises[2].second.setBuffer(noises[2].first);

}

Player::~Player()
{
	delete this->inventory;
	delete this->weapon;
}

//Accessors
AttributeComponent* Player::getAttributeComponent()
{
	return this->attributeComponent;
}

Weapon* Player::getWeapon() const
{
	return this->weapon;
}

std::string Player::toStringCharacterTab() const
{
	std::stringstream ss;
	const AttributeComponent* ac = this->attributeComponent;
	const Weapon* w = this->weapon;

	ss << "Level: " << ac->level << "\n"
		<< "Exp: " << ac->exp << "\n"
		<< "Exp next: " << ac->expNext << "\n"

		<< "Weapon Level: " << w->getLevel() << "\n"
		<< "Weapon Type: " << w->getType() << "\n"
		<< "Weapon Value: " << w->getValue() << "\n"
		<< "Weapon Range: " << w->getRange() << "\n"
		<< "Weapon Damage Min: " << w->getDamageMin() + this->attributeComponent->damageMin << " (" << this->attributeComponent->damageMin << ")" << "\n"
		<< "Weapon Damage Max: " << w->getDamageMax() + this->attributeComponent->damageMax << " (" << this->attributeComponent->damageMax << ")" << "\n";

	return ss.str();
}

bool Player::getInitAttack() const
{

	return this->initAttack;
}

bool Player::getDamageTimer()
{
	if (this->damageTimer.getElapsedTime().asMilliseconds() >= this->damageTimerMax)
	{
		this->damageTimer.restart();
		return true;
	}

	return false;
}

unsigned Player::getDamage()
{
	return rand() % (
		(this->attributeComponent->damageMax + this->weapon->getDamageMax())
		- (this->attributeComponent->damageMin + this->weapon->getDamageMin()) + 1)
		+ (this->attributeComponent->damageMin + this->weapon->getDamageMin());
}

void Player::setInitAttack(bool initAttack)
{
	this->initAttack = initAttack;
}

//Functions
void Player::loseHP(int hp)
{
	auto probability = rand() % 4 + 0; // with probabilty 2/4, the sound will be played

	if (probability <= 2)
		this->noises[probability].second.play();

	this->attributeComponent->loseHP(hp);
}

void Player::gainHP(int hp)
{
	//this->sound.play();
	this->attributeComponent->gainHP(hp);
}

void Player::loseEXP(int exp)
{
	auto probability = rand() % 4 + 0; // with probabilty 2/4, the sound will be played

	if (probability <= 2)
		this->noises[probability].second.play();

	this->attributeComponent->loseEXP(exp);
}

void Player::gainEXP(int exp)
{
	//this->sound.play();
	this->attributeComponent->gainExp(exp);
}

bool Player::isDead() const
{
	if (this->attributeComponent->isDead())
	{
		return true;
	}

	return false;
}

void Player::updateAnimation(float dt)
{
	if (this->attacking)
	{

	}
	if (this->movementComponent->getState(IDLE))
	{
		this->animationComponent->play("IDLE", dt);
	}
	else if (this->movementComponent->getState(MOVING_LEFT))
	{
		this->animationComponent->play("WALK_LEFT", dt, this->movementComponent->getVelocity().x, this->movementComponent->getMaxVelocity());
	}
	else if (this->movementComponent->getState(MOVING_RIGHT))
	{
		this->animationComponent->play("WALK_RIGHT", dt, this->movementComponent->getVelocity().x, this->movementComponent->getMaxVelocity());
	}
	else if (this->movementComponent->getState(MOVING_UP))
	{
		this->animationComponent->play("WALK_UP", dt, this->movementComponent->getVelocity().y, this->movementComponent->getMaxVelocity());
	}
	else if (this->movementComponent->getState(MOVING_DOWN))
	{
		this->animationComponent->play("WALK_DOWN", dt, this->movementComponent->getVelocity().y, this->movementComponent->getMaxVelocity());
	}
}

void Player::update(float dt, sf::Vector2f& mouse_pos_view, const sf::View& view)
{
	//auto probability = rand() % 100 + 0; 

	//if (probability <= 50)
	this->noises[2].second.play();

	this->movementComponent->update(dt);

	this->updateAnimation(dt);

	this->hitboxComponent->update();

	this->weapon->update(mouse_pos_view, sf::Vector2f(this->getSpriteCenter().x, this->getSpriteCenter().y + 5.f));
}

void Player::render(sf::RenderTarget& target, sf::Shader* shader, const sf::Vector2f& light_position, bool show_hitbox)
{
	if (shader)
	{
		shader->setUniform("hasTexture", true);
		shader->setUniform("lightPos", light_position);
		target.draw(this->sprite, shader);

		shader->setUniform("hasTexture", true);
		shader->setUniform("lightPos", light_position);
		this->weapon->render(target, shader);
	}
	else
	{
		target.draw(this->sprite);
		this->weapon->render(target);
	}

	if (show_hitbox)
		this->hitboxComponent->render(target);
}
