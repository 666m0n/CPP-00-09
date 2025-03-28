#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
private:
    Brain* brain;  // Nouveau membre privé

public:
    Cat();
    Cat(const Cat& other);
    virtual ~Cat();

    Cat& operator=(const Cat& other);

    virtual void makeSound() const;

    // Accesseurs pour le cerveau
    Brain* getBrain() const;
};

#endif