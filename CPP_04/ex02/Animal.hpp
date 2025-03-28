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
    virtual ~Animal();

    Animal& operator=(const Animal& other);

    std::string getType() const;

    // Fonction virtuelle pure (= 0) - rend la classe abstraite
    virtual void makeSound() const = 0;
};

#endif