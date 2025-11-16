#pragma once
#include "AMateria.hpp"

class Cure : public AMateria{
public:
    Cure();
    Cure(const Cure& other);
    Cure& operator=(const Cure& other);
    ~Cure();

	virtual AMateria* clone(void) const;
	virtual void use(ICharacter& target);

private:
    
};

