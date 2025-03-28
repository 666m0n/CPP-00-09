#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
public:
	Cat();
	Cat(const Cat& other);
	virtual ~Cat();

	Cat& operator=(const Cat& other);

	// Surcharge de la fonction makeSound
	virtual void makeSound() const;
};

#endif