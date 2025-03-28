#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {
protected:
	std::string type;

public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal& other);
	~WrongAnimal();  // Notez l'absence du mot-clé "virtual" ici

	WrongAnimal& operator=(const WrongAnimal& other);

	std::string getType() const;

	// fonction PAS virtuelle !!!
	void makeSound() const;
};

#endif