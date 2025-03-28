#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

int main() {
    // On ne peut plus créer d'Animal directement
    // const Animal* meta = new Animal(); // Cela ne compile plus!

    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << "J type: " << j->getType() << std::endl;
    std::cout << "I type: " << i->getType() << std::endl;

    i->makeSound();  // Son du chat
    j->makeSound();  // Son du chien

    // Nettoyage mémoire
    delete j;
    delete i;

    std::cout << "\n--- Testing array of animals ---\n" << std::endl;

    // Création d'un tableau d'animaux
    const int arraySize = 4;
    Animal* animals[arraySize];

    // Remplir le tableau avec des chiens et des chats
    for (int i = 0; i < arraySize; i++) {
        if (i < arraySize / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    // Utilisation des animaux
    for (int i = 0; i < arraySize; i++) {
        std::cout << "Animal " << i << " is a " << animals[i]->getType() << " and makes sound: ";
        animals[i]->makeSound();
    }

    // Libération de la mémoire
    for (int i = 0; i < arraySize; i++) {
        delete animals[i];
    }

    std::cout << "\n--- Testing deep copy ---\n" << std::endl;

    // Test de la copie profonde (comme dans l'exercice 01)
    Dog* originalDog = new Dog();

    originalDog->getBrain()->setIdea(0, "I love bones");
    originalDog->getBrain()->setIdea(1, "I want to chase cats");

    Dog* copyDog = new Dog(*originalDog);

    std::cout << "Original dog idea 0: " << originalDog->getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy dog idea 0: " << copyDog->getBrain()->getIdea(0) << std::endl;

    copyDog->getBrain()->setIdea(0, "I prefer toys over bones");

    std::cout << "After modification:" << std::endl;
    std::cout << "Original dog idea 0: " << originalDog->getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy dog idea 0: " << copyDog->getBrain()->getIdea(0) << std::endl;

    delete originalDog;
    delete copyDog;

    return 0;
}