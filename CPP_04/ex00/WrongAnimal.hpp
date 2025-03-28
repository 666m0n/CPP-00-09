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

    // Cette fonction n'est PAS virtuelle - c'est la différence clé
    void makeSound() const;
};

#endif