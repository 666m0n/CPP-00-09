#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
    WrongCat();
    WrongCat(const WrongCat& other);
    ~WrongCat();

    WrongCat& operator=(const WrongCat& other);

    // Cette fonction ne sera pas appelée à travers un pointeur WrongAnimal
    void makeSound() const;
};

#endif