#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class	Fixed {
	private:
		int	_fixedPointValue;
		static const int _fractionalBits = 8;
	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &src);
		//pour la surcharge de l'operateur d'affectation
		Fixed &operator=(const Fixed &rhs);
		~Fixed();

		int	getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif