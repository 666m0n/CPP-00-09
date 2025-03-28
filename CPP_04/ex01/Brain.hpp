#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>
#include <iostream>

class Brain {
private:
    std::string ideas[100];

public:
    Brain();
    Brain(const Brain& other);
    ~Brain();

    Brain& operator=(const Brain& other);

    // Accesseurs pour les idées
    std::string getIdea(int index) const;
    void setIdea(int index, const std::string& idea);
};

#endif