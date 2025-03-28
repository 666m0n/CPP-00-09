#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
protected:
    std::string type;

public:
    // Constructeurs et destructeur
    Animal();
    Animal(const Animal& other);
    virtual ~Animal();  // Destructeur virtuel important pour la polymorphisme

    // Opérateur d'affectation
    Animal& operator=(const Animal& other);

    // Getter pour l'attribut type
    std::string getType() const;

    // Fonction pour faire un son - doit être virtuelle pour permettre le polymorphisme
    virtual void makeSound() const;
};

#endif