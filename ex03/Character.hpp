#pragma once
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter {
public:
    Character();
    Character(const Character& other);
    Character& operator=(const Character& other);
    ~Character();

	Character(const std::string& name);
	virtual std::string const & getName() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);

private:
	AMateria* m_slots[4];
	bool indexValidation(int idx);
	std::string m_name;
};

