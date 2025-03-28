#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream>

// Déclaration anticipée pour éviter l'inclusion circulaire
class ICharacter;

class AMateria {
protected:
	std::string type;

public:
	AMateria();
	AMateria(std::string const & type);
	AMateria(const AMateria& other);
	virtual ~AMateria();

	AMateria& operator=(const AMateria& other);

	std::string const & getType() const; // Retourne le type de la materia

	virtual AMateria* clone() const = 0; // Méthode virtuelle pure
	virtual void use(ICharacter& target);
};

#endif