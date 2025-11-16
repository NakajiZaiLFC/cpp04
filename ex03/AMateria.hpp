#pragma once
#include <string>
#include "ICharacter.hpp"


class AMateria {
public:
    AMateria();
    AMateria(const AMateria& other);
    AMateria& operator=(const AMateria& other);
    virtual ~AMateria();
	virtual AMateria* clone(void) const = 0;
	std::string const & getType() const;
	virtual void use(ICharacter& target) = 0;


protected:
	std::string type;
    
};

