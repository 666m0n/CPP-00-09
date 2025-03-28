#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main() {
	// Test du sujet
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}

	std::cout << "\n--- Additional tests ---\n" << std::endl;

	// Test de création de materia avec un type inconnu
	{
		MateriaSource src;
		src.learnMateria(new Ice());

		AMateria* tmp = src.createMateria("fire");  // Type inconnu
		if (tmp)
			delete tmp;
	}

	// Test d'unequip et d'utilisation de materia après unequip
	{
		Character me("me");
		AMateria* ice = new Ice();

		me.equip(ice);
		me.unequip(0);  // La materia est enlevée mais pas supprimée

		Character target("target");
		me.use(0, target);  // Rien ne devrait se passer car l'emplacement 0 est vide

		delete ice;  // On nettoie la materia désépiquée
	}

	// Test de copie de Character avec inventaire
	{
		Character original("original");
		original.equip(new Ice());
		original.equip(new Cure());

		Character copy = original;  // Utilise l'opérateur d'affectation
		Character deepCopy(original);  // Utilise le constructeur de copie

		ICharacter* target = new Character("target");

		std::cout << "Original using materias:" << std::endl;
		original.use(0, *target);
		original.use(1, *target);

		std::cout << "Copy using materias:" << std::endl;
		copy.use(0, *target);
		copy.use(1, *target);

		std::cout << "Deep copy using materias:" << std::endl;
		deepCopy.use(0, *target);
		deepCopy.use(1, *target);

		delete target;
		// Les destructeurs de original, copy et deepCopy vont nettoyer leur inventaire
	}

	return 0;
}