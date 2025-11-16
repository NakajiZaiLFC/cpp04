#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++) {
        this->m_templates[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource& other) : IMateriaSource(other) {
    *this = other;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    if (this != &other) {
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++)
	{
		if (m_templates[i])
			delete m_templates[i];
	}
}

void MateriaSource::learnMateria(AMateria* m){
	if (!m)
		return ;
	for (int i = 0; i < 4; i++){
		if (!m_templates[i]){
			m_templates[i] = m->clone();
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const& type){
	for (int i = 0; i < 4; i++)
	{
		if (!m_templates[i])
			continue;
		else if (m_templates[i]->getType() == type)
			return (m_templates[i]->clone());
	}
	return NULL;
}
