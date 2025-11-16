#include "Character.hpp"

Character::Character() : m_name("NPC") {
    for (int i = 0; i < 4; i++)
		m_slots[i] = NULL;
}

Character::Character(const std::string& name) : m_name(name){
    for (int i = 0; i < 4; i++)
		m_slots[i] = NULL;
}

Character::Character(const Character& other) : ICharacter(other), m_name(other.m_name) {
	for (int i = 0; i < 4; i++){
		if (!other.m_slots[i]){
			this->m_slots[i] = NULL;
		}
		else{
			this->m_slots[i] = other.m_slots[i]->clone();
		}
	}
}

Character& Character::operator=(const Character& other){
	if (this == &other)
		return *this;
	for (int i = 0; i < 4; i++){
		if (!other.m_slots[i]){
			if (this->m_slots[i])
				delete this->m_slots[i];
			this->m_slots[i] = NULL;
		}
		else {
			if (this->m_slots[i])
				delete this->m_slots[i];
			this->m_slots[i] = other.m_slots[i]->clone();
		}
	}
	this->m_name = other.m_name;
    return *this;
}

Character::~Character() {
    for (int i = 0; i < 4; i++) {
        if (this->m_slots[i])
            delete this->m_slots[i];
    }
}

std::string const& Character::getName() const{
	return m_name;
}

void Character::equip(AMateria* m){
	for (int i = 0; i < 4; i++)
	{
		if (m_slots[i] == NULL){
			m_slots[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx){
	if (!Character::indexValidation(idx))
		return ;
	if (m_slots[idx])
		m_slots[idx] = NULL;
}

void Character::use(int idx, ICharacter& target){
	if (!Character::indexValidation(idx))
		return ;
	if (!m_slots[idx])
		return ;
	m_slots[idx]->use(target);
}

bool Character::indexValidation(int idx)
{
		return (idx >= 0 && idx <= 3);
}
