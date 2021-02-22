#ifndef SKILLCOMPONENT_H
#define SKILLCOMPONENT_H

enum SKILLS { CONSTITUTION = 0, MELEE_COMBAT, RANGED_COMBAT, ENDURANCE };

class SkillComponent
{
private:
	class Skill
	{
	private:
		int type;
		int level;
		int levelCap;
		int exp;
		int expNext;

	public:
		Skill(int type)
		{
			this->type = type;
			this->level = 1;
			this->levelCap = 99;
			this->exp = 0;
			this->expNext = 100;
		}

		~Skill() {}

		//Accessors
		//Accessors
		inline int getType() const { return this->type; }
		inline int getLevel() const { return this->level; }
		inline int getExp() const { return this->exp; }
		inline int getExpNext() const { return this->expNext; }

		//Modifiers
		void setLevel(int level) { this->level = level; }
		void setLevelCap(int level_cap) { this->levelCap = level_cap; }

		//Functions
		void gainExp(int exp)
		{
			this->exp += exp;
			this->updateLevel();
		}

		void loseExp(int exp)
		{
			this->exp -= exp;
		}

		void updateLevel(bool up = true)
		{
			/**
			  * Increases or decreases the level of the skill depending on if there is a deficit in the exp or not.
			  *
			  */

			if (up)
			{
				if (this->level < this->levelCap)
				{
					while (this->exp >= this->expNext)
					{
						if (this->level < this->levelCap)
						{
							this->level++;
							this->expNext = static_cast<int>(std::pow(this->level, 2)) + this->level * 10 + this->level * 2;
						}
					}
				}
			}
			else
			{
				if (this->level > 0)
				{
					while (this->exp < 0)
					{
						if (this->level > 0)
						{
							this->level--;
							this->expNext = static_cast<int>(std::pow(this->level, 2)) + this->level * 10 + this->level * 2;
						}
					}
				}
			}
		}

		void update() {}
	};

	std::vector<Skill> skills;

public:
	SkillComponent();
	virtual ~SkillComponent();

	int getSkill(int skill) const;
	void gainExp(int skill, int exp);
};

#endif //!SKILLCOMPONENT_H
