#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <limits>
#include <cctype>
#include <cmath>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& src) { (void)src; }
ScalarConverter::~ScalarConverter() {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& src) {
	(void)src;
	return *this;
}

void ScalarConverter::convert(const std::string& literal) {
	if (literal.empty()) {
		std::cout << "Error: Empty input" << std::endl;
		return;
	}

	Type type = detectType(literal);

	switch (type) {
		case CHAR:
			convertFromChar(literal[1]); // "x"
			break;
		case INT:
			convertFromInt(std::atoi(literal.c_str()));
			break;
		case FLOAT:
			convertFromFloat(std::atof(literal.c_str()));
			break;
		case DOUBLE:
			convertFromDouble(std::atof(literal.c_str()));
			break;
		case LITERAL:
			convertFromLiteral(literal);
			break;
		case ERROR:
			std::cout << "Error: Invalid input" << std::endl;
			break;
	}
}

ScalarConverter::Type ScalarConverter::detectType(const std::string& literal) {
	if (isChar(literal))
		return CHAR;
	else if (isLiteral(literal))
		return LITERAL;
	else if (isInt(literal))
		return INT;
	else if (isFloat(literal))
		return FLOAT;
	else if (isDouble(literal))
		return DOUBLE;
	return ERROR;
}

bool ScalarConverter::isChar(const std::string& literal) {
	return (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'');
}

bool ScalarConverter::isInt(const std::string& literal) {
	size_t i = 0;

	if (literal[i] == '+' || literal[i] == '-')
		i++;

	while (i < literal.length()) {
		if (!std::isdigit(literal[i]))
			return false;
		i++;
	}

	return !literal.empty();
}

bool ScalarConverter::isFloat(const std::string& literal) {
	if (literal.length() < 2)
		return false;

	if (literal[literal.length() - 1] != 'f')
		return false;

	size_t i = 0;
	bool hasDecimal = false;

	if (literal[i] == '+' || literal[i] == '-')
		i++;

	while (i < literal.length() - 1) {
		if (literal[i] == '.') {
			if (hasDecimal)
				return false;
			hasDecimal = true;
		} else if (!std::isdigit(literal[i])) {
			return false;
		}
		i++;
	}

	return hasDecimal;
}

bool ScalarConverter::isDouble(const std::string& literal) {
	size_t i = 0;
	bool hasDecimal = false;

	if (literal[i] == '+' || literal[i] == '-')
		i++;

	while (i < literal.length()) {
		if (literal[i] == '.') {
			if (hasDecimal)
				return false;
			hasDecimal = true;
		} else if (!std::isdigit(literal[i])) {
			return false;
		}
		i++;
	}

	return hasDecimal;
}

bool ScalarConverter::isLiteral(const std::string& literal) {
	return (literal == "nan" || literal == "+inf" || literal == "-inf" ||
			literal == "nanf" || literal == "+inff" || literal == "-inff");
}

void ScalarConverter::convertFromChar(const char c) {
	std::cout << "char: ";
	if (std::isprint(c))
		std::cout << "'" << c << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;

	std::cout << "int: " << static_cast<int>(c) << std::endl;

	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;

	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::convertFromInt(const int i) {
	std::cout << "char: ";
	if (i >= 0 && i <= 127) {
		if (std::isprint(i))
			std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	} else {
		std::cout << "impossible" << std::endl;
	}

	std::cout << "int: " << i << std::endl;

	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;

	std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void ScalarConverter::convertFromFloat(const float f) {
	std::cout << "char: ";
	if (std::isnan(f) || std::isinf(f) || f < 0 || f > 127) {
		std::cout << "impossible" << std::endl;
	} else if (std::isprint(static_cast<int>(f))) {
		std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
	} else {
		std::cout << "Non displayable" << std::endl;
	}

	std::cout << "int: ";
	if (std::isnan(f) || std::isinf(f) ||
		f > static_cast<float>(std::numeric_limits<int>::max()) ||
		f < static_cast<float>(std::numeric_limits<int>::min())) {
		std::cout << "impossible" << std::endl;
	} else {
		std::cout << static_cast<int>(f) << std::endl;
	}

	std::cout << "float: " << f;
	if (f - static_cast<int>(f) == 0)
		std::cout << ".0";
	std::cout << "f" << std::endl;

	std::cout << "double: " << static_cast<double>(f);
	if (f - static_cast<int>(f) == 0)
		std::cout << ".0";
	std::cout << std::endl;
}

void ScalarConverter::convertFromDouble(const double d) {
	std::cout << "char: ";
	if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127) {
		std::cout << "impossible" << std::endl;
	} else if (std::isprint(static_cast<int>(d))) {
		std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
	} else {
		std::cout << "Non displayable" << std::endl;
	}

	std::cout << "int: ";
	if (std::isnan(d) || std::isinf(d) ||
		d > static_cast<double>(std::numeric_limits<int>::max()) ||
		d < static_cast<double>(std::numeric_limits<int>::min())) {
		std::cout << "impossible" << std::endl;
	} else {
		std::cout << static_cast<int>(d) << std::endl;
	}

	std::cout << "float: ";
	if (std::isnan(d) || std::isinf(d) ||
		d > static_cast<double>(std::numeric_limits<float>::max()) ||
		d < -static_cast<double>(std::numeric_limits<float>::max())) {
		if (std::isnan(d))
			std::cout << "nanf" << std::endl;
		else if (d > 0)
			std::cout << "+inff" << std::endl;
		else
			std::cout << "-inff" << std::endl;
	} else {
		std::cout << static_cast<float>(d);
		if (d - static_cast<int>(d) == 0)
			std::cout << ".0";
		std::cout << "f" << std::endl;
	}

	std::cout << "double: " << d;
	if (d - static_cast<int>(d) == 0)
		std::cout << ".0";
	std::cout << std::endl;
}

void ScalarConverter::convertFromLiteral(const std::string& literal) {
	std::cout << "char: impossible" << std::endl;

	std::cout << "int: impossible" << std::endl;

	std::cout << "float: ";
	if (literal == "nan" || literal == "nanf")
		std::cout << "nanf" << std::endl;
	else if (literal == "+inf" || literal == "+inff")
		std::cout << "+inff" << std::endl;
	else if (literal == "-inf" || literal == "-inff")
		std::cout << "-inff" << std::endl;

	std::cout << "double: ";
	if (literal == "nan" || literal == "nanf")
		std::cout << "nan" << std::endl;
	else if (literal == "+inf" || literal == "+inff")
		std::cout << "+inf" << std::endl;
	else if (literal == "-inf" || literal == "-inff")
		std::cout << "-inf" << std::endl;
}