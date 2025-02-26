#ifndef FIXED_HPP
#define FIXED_HPP

class	Fixed {
	private:
		int	_fixedPointValue;
		static const int _fractionalBits = 8;
	public:
		Fixed();
		Fixed(const Fixed &src);
		//pour la surcharge de l'operateur d'affectation
		Fixed &operator=(const Fixed &rhs);
		~Fixed();
		int	getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif