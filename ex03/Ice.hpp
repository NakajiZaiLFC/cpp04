#pragma once
#include "AMateria.hpp"

class Ice : public AMateria{
public:
    Ice();
    Ice(const Ice& other);
    Ice& operator=(const Ice& other);
    ~Ice();

	virtual AMateria* clone(void) const;
	virtual void use(ICharacter& target);

private:
    
};

