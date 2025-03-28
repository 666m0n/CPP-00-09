#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
	Brain* brain;  // Nouveau membre privé

public:
	Dog();
	Dog(const Dog& other);
	virtual ~Dog();

	Dog& operator=(const Dog& other);

	virtual void makeSound() const;

	// Accesseurs pour le cerveau
	Brain* getBrain() const;
};

#endif