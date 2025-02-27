#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	_fixedPointValue = value << _fractionalBits;
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	// On multiplie le flottant par 2^_fractionalBits et on arrondit
	_fixedPointValue = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed &Fixed::operator=(const Fixed &rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_fixedPointValue = rhs.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	std::cout << " getRawBits member function called" << std::endl;
	return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
	this->_fixedPointValue = raw;
}

float Fixed::toFloat(void) const {
	return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
	return _fixedPointValue >> _fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}

// Operateurs de comparaison

bool Fixed::operator>(const Fixed &rhs) const {
	return this->_fixedPointValue >= rhs._fixedPointValue;
}

bool Fixed::operator<(const Fixed &rhs) const {
	return this->_fixedPointValue < rhs._fixedPointValue;
}

bool Fixed::operator>=(const Fixed &rhs) const {
	return this->_fixedPointValue >= rhs._fixedPointValue;
}

bool Fixed::operator<=(const Fixed &rhs) const {
	return this->_fixedPointValue <= rhs._fixedPointValue;
}

bool Fixed::operator==(const Fixed &rhs) const {
	return this->_fixedPointValue == rhs._fixedPointValue;
}

bool Fixed::operator!=(const Fixed &rhs) const {
	return this->_fixedPointValue != rhs._fixedPointValue;
}

// Operateurs arithmetiques

Fixed Fixed::operator+(const Fixed &rhs) const {
	Fixed result;
	result.setRawBits(this->_fixedPointValue + rhs._fixedPointValue);
	return result;
}

Fixed Fixed::operator-(const Fixed &rhs) const {
	Fixed result;
	result.setRawBits(this->_fixedPointValue - rhs._fixedPointValue);
	return result;
}

Fixed Fixed::operator*(const Fixed &rhs) const {
	// Pour la multiplication, on multiplie les valeurs puis on divise par 2^_fractionalBits
	// pour ajuster la position du point fixe
	Fixed result;
	long long temp = (long long)this->_fixedPointValue * (long long)rhs._fixedPointValue;
	result.setRawBits((int)(temp >> _fractionalBits));
	return result;
}

Fixed Fixed::operator/(const Fixed &rhs) const {
	if (rhs._fixedPointValue == 0) {
		std::cerr << "Error: Division by zero" << std::endl;
		return Fixed();
	}
	// Pour la division, on multiplie par 2^_fractionalBits puis on divise
	// pour ajuster la position du point fixe
	Fixed result;
	long long temp = ((long long)this->_fixedPointValue << _fractionalBits) / rhs._fixedPointValue;
	result.setRawBits((int)temp);
	return result;
}

// Opérateurs d'incrémentation et décrémentation
Fixed &Fixed::operator++() {
	// Pré-incrémentation : on incrémente puis on retourne la référence
	this->_fixedPointValue += 1; // Incrémentation de la plus petite unité (2^-8)
	return *this;
}

Fixed Fixed::operator++(int) {
	// Post-incrémentation : on retourne l'ancienne valeur puis on incrémente
	Fixed old = *this;
	this->_fixedPointValue += 1;
	return old;
}

Fixed &Fixed::operator--() {
	// Pré-décrémentation : on décrémente puis on retourne la référence
	this->_fixedPointValue -= 1;
	return *this;
}

Fixed Fixed::operator--(int) {
	// Post-décrémentation : on retourne l'ancienne valeur puis on décrémente
	Fixed old = *this;
	this->_fixedPointValue -= 1;
	return old;
}

// Fonctions membres statiques
Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	return (a > b) ? a : b;
}
