#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& src);
	ScalarConverter& operator=(const ScalarConverter& src);
	~ScalarConverter();

	enum Type {
		CHAR,
		INT,
		FLOAT,
		DOUBLE,
		LITERAL,  // nan, inf
		ERROR
	};

	static Type detectType(const std::string& literal);
	static bool isChar(const std::string& literal);
	static bool isInt(const std::string& literal);
	static bool isFloat(const std::string& literal);
	static bool isDouble(const std::string& literal);
	static bool isLiteral(const std::string& literal);

	static void convertFromChar(const char c);
	static void convertFromInt(const int i);
	static void convertFromFloat(const float f);
	static void convertFromDouble(const double d);
	static void convertFromLiteral(const std::string& literal);

public:
	static void convert(const std::string& literal);
};

#endif