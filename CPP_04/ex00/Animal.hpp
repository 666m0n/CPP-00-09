#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
protected:
	std::string type;

public:
	Animal();
	Animal(const Animal& other);
	virtual ~Animal();  // Destructeur virtuel important pour la polymorphisme

	Animal& operator=(const Animal& other);

	std::string getType() const;

	// Fonction pour faire un son - doit être virtuelle pour permettre le polymorphisme
	virtual void makeSound() const;
};

#endif