#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	std::cout << "MateriaSource constructor called" << std::endl;
	// Initialiser les templates à NULL
	for (int i = 0; i < 4; i++) {
		this->templates[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	std::cout << "MateriaSource copy constructor called" << std::endl;
	// Copie profonde des templates
	for (int i = 0; i < 4; i++) {
		if (other.templates[i])
			this->templates[i] = other.templates[i]->clone();
		else
			this->templates[i] = NULL;
	}
}

MateriaSource::~MateriaSource() {
	std::cout << "MateriaSource destructor called" << std::endl;
	// Nettoyer les templates
	for (int i = 0; i < 4; i++) {
		if (this->templates[i]) {
			delete this->templates[i];
			this->templates[i] = NULL;
		}
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	std::cout << "MateriaSource assignment operator called" << std::endl;
	if (this != &other) {
		// Nettoyer les templates actuels
		for (int i = 0; i < 4; i++) {
			if (this->templates[i]) {
				delete this->templates[i];
				this->templates[i] = NULL;
			}
		}

		// Copie profonde des templates
		for (int i = 0; i < 4; i++) {
			if (other.templates[i])
				this->templates[i] = other.templates[i]->clone();
			else
				this->templates[i] = NULL;
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
	if (!m) {
        std::cout << "Cannot learn NULL materia" << std::endl;
        return;
    }

    // Trouver le premier emplacement vide
    for (int i = 0; i < 4; i++) {
        if (!this->templates[i]) {
            this->templates[i] = m;
            std::cout << "MateriaSource learned " << m->getType() << std::endl;
            return;
        }
    }

    // Si on arrive ici, tous les emplacements sont occupés
    std::cout << "MateriaSource cannot learn more materias, memory is full" << std::endl;
    delete m;  // On supprime la materia car on ne peut pas l'apprendre
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    // Chercher un template du même type
    for (int i = 0; i < 4; i++) {
        if (this->templates[i] && this->templates[i]->getType() == type) {
            std::cout << "MateriaSource created " << type << " materia" << std::endl;
            return this->templates[i]->clone();  // Créer une copie du template
        }
    }

    // Si on arrive ici, le type n'a pas été trouvé
    std::cout << "MateriaSource does not know materia type: " << type << std::endl;
    return NULL;
}