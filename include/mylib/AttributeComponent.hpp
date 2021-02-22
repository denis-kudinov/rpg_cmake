#pragma once
class AttributeComponent
{
public:
	//Leveling
	int level;
	int exp;
	int expNext;
	int attributePoints;

	//Attributes
	int vitality;
	int strength;
	int dexterity;
	int agility;
	int intelligence;

	//Stats
	int hp;
	int hpMax;
	int damageMin;
	int damageMax;
	int accuracy;
	int defence;
	int luck;

	AttributeComponent(int level, int vitality = 1);
	virtual ~AttributeComponent();

	//Functions
	std::string debugPrint() const;

	void loseHP(int hp);
	void gainHP(int hp);
	void loseEXP(int exp);
	void gainExp(int exp);

	bool isDead() const;

	void updateStats(bool reset);
	void updateLevel();

	void update();
};

