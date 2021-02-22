#include "mylib/stdafx.hpp"
#include "mylib/SkillComponent.hpp"

SkillComponent::SkillComponent()
{
	this->skills.push_back(Skill(SKILLS::CONSTITUTION));
	this->skills.push_back(Skill(SKILLS::MELEE_COMBAT));
	this->skills.push_back(Skill(SKILLS::RANGED_COMBAT));
	this->skills.push_back(Skill(SKILLS::ENDURANCE));
}

SkillComponent::~SkillComponent() {}

int SkillComponent::getSkill(int skill) const
{
	if (skills.empty() || skill < 0 || skill >= this->skills.size())
		throw("ERROR::SKILLCOMPONENT::GETSKILL::SKILL DOES NOT EXIST: " + skill);
	else
		return this->skills[skill].getLevel();
}

void SkillComponent::gainExp(int skill, int exp)
{
	if (skills.empty() || skill < 0 || skill >= this->skills.size())
		throw("ERROR::SKILLCOMPONENT::GAINEXP::SKILL DOES NOT EXIST: " + skill);
	else
	{
		this->skills[skill].gainExp(exp);
	}
}
