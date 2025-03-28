#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
public:
	Dog();
	Dog(const Dog& other);
	virtual ~Dog();

	Dog& operator=(const Dog& other);

	// Surcharge de la fonction makeSound
	virtual void makeSound() const;
};

#endif